#include "GamePlay.h"

GamePlay::GamePlay()
{
	circle.setRadius(50);
	circle.setFillColor(sf::Color::Blue);
}

void GamePlay::update(double t_deltaTime)
{
}

void GamePlay::render(sf::RenderWindow& t_window) const
{
	t_window.draw(circle);
}

void GamePlay::processEvents(sf::Event& t_event)
{
}

void GamePlay::processKeys(sf::Event& t_event)
{
}
