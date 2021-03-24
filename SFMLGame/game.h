#pragma once

#include <iostream>
#include <string>
#include <cmath>

#include "enemy.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game{

private:


	//Variables

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Clock frameCounter;
	sf::Time frametime;
	float FRAMETIME;
	float FRAMERATE;
	Enemy enemy;
	std::string gameStatus;
	sf::Text text;
	sf::Font font;


	//Game Objects
	sf::CircleShape player;
	sf::CircleShape enemyCircle;


	void InitVariables();
	void InitWindow();
	void InitPlayer();
	void InitEnemy();
	void InitText();

	void GameLost();
	bool DetectCollision(sf::CircleShape* objectOne, sf::CircleShape* objectTwo);

public:

	//Constructor / Destructor 
	Game();
	virtual ~Game();


	//Accessors

	const bool Running() const;


	//Functions
	void GetFramerate();
	void PollEvents();
	void Update();
	void Render();
};

