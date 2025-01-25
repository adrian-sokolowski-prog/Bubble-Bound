#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "GamePlay.h"
#include "MainMenu.h"
#include "Oxygen.h"
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
