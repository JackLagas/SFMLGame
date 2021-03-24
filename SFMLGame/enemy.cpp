#include "enemy.h"



float Enemy::invSqrt(float number){
	union {
		float f;
		uint32_t i;
	} conv;

	float x2;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	conv.f = number;
	conv.i = 0x5f3759df - (conv.i >> 1);
	conv.f = conv.f * (threehalfs - (x2 * conv.f * conv.f));
	return conv.f;
}

Enemy::Enemy(){
}


void Enemy::SetAttackDamage(float _attackDamage){
	this->attackDamage = _attackDamage;
}

void Enemy::SetHealth(float _health){
	this->health = _health;
}

void Enemy::SetSize(float _size){
	this->size = _size;
}

void Enemy::SetPosition(sf::Vector2f _position){
	this->position = _position;
}

void Enemy::SetSpeed(float _speed){
	this->speed = _speed;
}


float Enemy::GetAttackDamage() {
	return this->attackDamage;
}
float Enemy::GetHealth() {
	return this->health;
}
float Enemy::GetSize() {
	return this->size;
}
sf::Vector2f Enemy::GetPosition() {
	return this->position;
}

float Enemy::GetSpeed(){
	return this->speed;
}

void Enemy::SetTargetObjective(sf::Vector2f _targetObjective){

	this->targetObjective = _targetObjective;
}

void Enemy::MoveToTargetObjective(){

	this->directionToObjective = this->targetObjective - this->position ;

	this->normalizedDirectionToObjective.x = invSqrt(this->directionToObjective.x * this->directionToObjective.x + this->directionToObjective.y * this->directionToObjective.y) * this->directionToObjective.x;
	this->normalizedDirectionToObjective.y = invSqrt(this->directionToObjective.x * this->directionToObjective.x + this->directionToObjective.y * this->directionToObjective.y) * this->directionToObjective.y;

	this->position = this->position + sf::Vector2f(this->normalizedDirectionToObjective.x * speed, this->normalizedDirectionToObjective.y * speed);

}
