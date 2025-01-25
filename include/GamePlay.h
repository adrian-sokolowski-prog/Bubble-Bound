#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class GamePlay
{
public:
	GamePlay();

	void update(double t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event& t_event);
	void processKeys(sf::Event& t_event);

private:

	Player player;

};

