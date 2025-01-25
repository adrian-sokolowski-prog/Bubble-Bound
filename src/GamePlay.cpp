#include "GamePlay.h"

GamePlay::GamePlay()
{
	srand(time(nullptr));
}

void GamePlay::update(double t_deltaTime)
{
	player.move();
	sf::CircleShape shape;
	m_oxygen.Update(t_deltaTime, player.getBody());
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	m_oxygen.Render(t_window);
	t_window.draw(player.getSprite());
}

void GamePlay::processEvents(sf::Event& t_event)
{
}

void GamePlay::processKeys(sf::Event& t_event)
{
}
