#pragma once
#include <SFML/Graphics.hpp>

class GamePlay
{
public:
	GamePlay();

	void update(double t_deltaTime);
	void render(sf::RenderWindow& t_window) const;
	void processEvents(sf::Event& t_event);
	void processKeys(sf::Event& t_event);

private:

	sf::CircleShape circle;

};

