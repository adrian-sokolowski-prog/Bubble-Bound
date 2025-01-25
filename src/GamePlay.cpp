#include "GamePlay.h"
#include "Globals.h"

GamePlay::GamePlay()
{
	srand(time(nullptr));
}

void GamePlay::update(double t_deltaTime)
{
	player.move();
	sf::CircleShape shape;
	m_oxygen.Update(t_deltaTime, player.getBody());

	if (spawnTimer < TIME_BETWEEN_SPAWNS)
	{
		spawnTimer++;
	}
	else
	{
		spawnTimer = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (!enemies[i].active)
			{
				enemies[i].activate(player.getPos());
				break;
			}
		}
	}

	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		enemies[i].move();
	}
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	m_oxygen.Render(t_window);
	t_window.draw(player.getSprite());

	for (Enemy& e : enemies)
	{
		if (e.active)
		{
			t_window.draw(e.getSprite());
		}
	}
}

void GamePlay::processEvents(sf::Event& t_event)
{
}

void GamePlay::processKeys(sf::Event& t_event)
{
}
