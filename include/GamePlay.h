#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Oxygen.h"
#include "Enemy.h"
#include <iostream>

class GamePlay
{
public:
	GamePlay();


	void update(double t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event& t_event);
	void processKeys(sf::Event& t_event);

private:

	// Shader
	sf::Clock clock;
	sf::Texture noiseTexture;
	void loadShader();
	sf::Shader underWaterShader;
	sf::RenderTexture renderTexture;

	// TEMP TEXTURE
	sf::Texture tiles;
	sf::Sprite tileSprite;

	void moveView();
	sf::View view;

	// Objects
	Player player;
	Oxygen m_oxygen;
	
	static const int MAX_ENEMIES = 10;
	int enemyAmount = 0;
	Enemy enemies[MAX_ENEMIES];

	// Enemy spawn timer
	const int TIME_BETWEEN_SPAWNS = 2 * 60;
	int spawnTimer = 0;
};

