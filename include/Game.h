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
	static Scene currentScene;

private:

	void update(double t_deltaTime);
	void render();
	void processEvents();

	bool m_gameLost = false;
	// Scenes
	GamePlay gameplay;
	MainMenu mainMenu;

	// main window
	sf::RenderWindow m_window;


	
};
