#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "GamePlay.h"
#include "MainMenu.h"

enum class Scene
{
	None,
	MainMenu,
	GamePlay
};


class Game
{
public:
	Game();

	void run();

private:

	void update(double t_deltaTime);
	void render();
	void processEvents();

	// Scenes
	GamePlay gameplay;
	MainMenu mainMenu;

	// main window
	sf::RenderWindow m_window;

	static Scene currentScene;
};
