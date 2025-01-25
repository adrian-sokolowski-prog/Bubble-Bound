#include "GamePlay.h"

GamePlay::GamePlay()
{
}

void GamePlay::update(double t_deltaTime)
{
	player.move();
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(player.getBody());
}

void GamePlay::processEvents(sf::Event& t_event)
{
}

void GamePlay::processKeys(sf::Event& t_event)
{
}
