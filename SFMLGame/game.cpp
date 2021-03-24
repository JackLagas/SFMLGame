#include "game.h"


/*
Private
*/
void Game::InitVariables(){


	this->window = nullptr;


}

void Game::InitWindow(){

	this->videoMode.height = 600;
	this->videoMode.width = 800;
	

	this->window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setMouseCursorVisible(false);

}

void Game::InitPlayer(){

	float size = 25.f;
	
	this->player.setRadius(2 * size);
	this->player.setOrigin(sf::Vector2f(size, size));
	this->player.setFillColor(sf::Color::Cyan);
	this->player.setOutlineColor(sf::Color::White);
	this->player.setOutlineThickness(1.0f);

	

}

void Game::InitEnemy(){

	float size = 15.f;


	this->enemy.SetPosition(sf::Vector2f(0, 0));
	this->enemy.SetSize(size);
	this->enemy.SetSpeed(100.f * FRAMETIME);


	this->enemyCircle.setRadius(2 * this->enemy.GetSize());
	this->enemyCircle.setOrigin(sf::Vector2f(size, size));
	this->enemyCircle .setFillColor(sf::Color::Red);
	this->enemyCircle.setOutlineColor(sf::Color::White);
	this->enemyCircle.setOutlineThickness(1.0f);

	

	

}

void Game::InitText(){

	
	if (!this->font.loadFromFile("coolvetica.ttf")){
		throw "Font not Found";
	}
	else {
		this->text.setFont(this->font);
		this->text.setString("you lose");
		this->text.setCharacterSize(24);
		this->text.setFillColor(sf::Color::Red);
		this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	}
}

void Game::GameLost(){
	this->gameStatus = "lost";
	this->window->setMouseCursorVisible(true);
}

bool Game::DetectCollision(sf::Shape* objectOne, sf::Shape* objectTwo){
	if (objectOne->getGlobalBounds().intersects(objectTwo->getGlobalBounds())) 
		return true;
	else return false;
}

Game::Game(){
	
	this->InitVariables();
	this->InitWindow();
	this->InitPlayer();
	this->InitEnemy();
	this->InitText();
	this->gameStatus = "play";

}

/*
Public
*/

//Constructor / Destructor 
Game::~Game() {
	delete this->window;
}


//Accessors
const bool Game::Running() const{
	return this->window->isOpen();
}



//Functions
void Game::GetFramerate(){


	frametime = frameCounter.getElapsedTime();

	FRAMETIME = frametime.asSeconds();

	FRAMERATE = 1.f / FRAMETIME;

	frameCounter.restart();


	//Adds FPS to window Title
	//this->window->setTitle("Game FPS: " + std::to_string(FRAMERATE));
}

void Game::PollEvents(){

	while (this->window->pollEvent(this->ev)) {

		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->GameLost();
			break;

		}
	}
}


void Game::Update(){

	this->PollEvents();

	if (!this->gameStatus.compare("play")) {

		this->player.setPosition(sf::Vector2f(sf::Mouse::getPosition(*this->window).x, sf::Mouse::getPosition(*this->window).y));
		this->enemy.SetSpeed(100 * FRAMETIME);

		this->enemy.SetTargetObjective(player.getPosition());

		this->enemy.MoveToTargetObjective();
		this->enemyCircle.setPosition(this->enemy.GetPosition());

		if (this->DetectCollision(&enemyCircle, &player)) {
			this->GameLost();
		}
	}

}

void Game::Render(){
	this->window->clear(sf::Color::Black);

	if (!this->gameStatus.compare("play")) {
		this->window->draw(this->player);
		this->window->draw(this->enemyCircle);

	}
	else {
		this->window->draw(this->text);
	}

	this->window->display();

}
