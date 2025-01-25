#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class GamePlay
{
public:
	GamePlay();

	void loadTextures();

	void update(double t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event& t_event);
	void processKeys(sf::Event& t_event);

private:

	Player player;

	std::vector<Enemy> enemies;
	sf::Texture enemyTexture;

	// Enemy spawn timer
	const int TIME_BETWEEN_SPAWNS = 2 * 60;
	int spawnTimer = 0;
};

