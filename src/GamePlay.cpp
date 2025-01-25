#include "GamePlay.h"

GamePlay::GamePlay()
{
	srand(time(nullptr));
}

void GamePlay::update(double t_deltaTime)
{
	player.move();
	m_oxygen.Update(t_deltaTime);
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(player.getSprite());
	m_oxygen.Render(t_window);
}

void GamePlay::processEvents(sf::Event& t_event)
{
}

void GamePlay::processKeys(sf::Event& t_event)
{
}
