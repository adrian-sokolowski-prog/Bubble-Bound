#include "GamePlay.h"

GamePlay::GamePlay()
{
	srand(time(nullptr));

	loadTextures();
}

void GamePlay::loadTextures()
{
	if (!enemyTexture.loadFromFile("Assets/Art/enemy.png"))
	{
		std::cout << "Couldnt load enemy texture \n";
	}
}

void GamePlay::update(double t_deltaTime)
{
	player.move();

	if (spawnTimer < TIME_BETWEEN_SPAWNS)
	{
		spawnTimer++;
	}
	else
	{
		spawnTimer = 0;

		enemies.push_back(Enemy(enemyTexture, player.getPos()));
	}

	for (Enemy& e : enemies)
	{
		e.move();
	}
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(player.getSprite());

	for (Enemy& e : enemies)
	{
		t_window.draw(e.getSprite());
	}
}

void GamePlay::processEvents(sf::Event& t_event)
{
}

void GamePlay::processKeys(sf::Event& t_event)
{
}
