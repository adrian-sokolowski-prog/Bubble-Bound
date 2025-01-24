#pragma once

#include <SFML/Graphics.hpp>
#include <string>


class Game
{
public:
	Game();

	void run();

private:

	void update(double dt);
	void render();
	void processEvents();
	void processGameEvents(sf::Event&);

	// main window
	sf::RenderWindow m_window;
};
