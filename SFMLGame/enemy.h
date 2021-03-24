#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Enemy{

private:
	//Variables
	float attackDamage;
	float health;
	float size;
	sf::Vector2f position;
	float speed;
	sf::Vector2f targetObjective;
	sf::Vector2f directionToObjective;
	sf::Vector2f normalizedDirectionToObjective;


	//functions
	float invSqrt(float number);


public:

	//Constructor / Destructor

	Enemy();
	Enemy(float _attackDamage, float _health, float _size, sf::Vector2f _position, float _speed);



	//Functions
	void SetAttackDamage(float _attackDamage);
	void SetHealth(float _health);
	void SetSize(float _size);
	void SetPosition(sf::Vector2f _position);
	void SetSpeed(float _speed);

	float GetAttackDamage();
	float GetHealth();
	float GetSize();
	sf::Vector2f GetPosition();
	float GetSpeed();

	void SetTargetObjective(sf::Vector2f _targetObjective);

	void MoveToTargetObjective();
	



};

