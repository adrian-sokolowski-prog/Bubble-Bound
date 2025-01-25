#include "Game.h"
#include <iostream>

#include "Globals.h"

// Our target FPS
static double const FPS{ 60.0f };

Scene Game::currentScene = Scene::GamePlay;

////////////////////////////////////////////////////////////
Game::Game()
	: m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "SFML Playground", sf::Style::Default)
{
	// Really only necessary is our target FPS is greater than 60.
	m_window.setVerticalSyncEnabled(true);
}


////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	sf::Time timePerFrame = sf::seconds(1.0f / FPS); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame.asMilliseconds()); //60 fps
		}
		render(); // as many as possible
	}
}

////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (newEvent.type == sf::Event::Closed)
		{
			m_window.close();
		}
		
		switch (Game::currentScene)
		{
		case Scene::None:
			break;
		case Scene::GamePlay:
			gameplay.processEvents(newEvent);
			break;
		case Scene::MainMenu:
			mainMenu.processEvents(newEvent);
			break;
		}
	}
}


// What happens every frame
void Game::update(double t_deltaTime)
{
	switch (Game::currentScene)
	{
	case Scene::None:
		break;
	case Scene::GamePlay:
		gameplay.update(t_deltaTime);
		break;
	case Scene::MainMenu:
		mainMenu.update(t_deltaTime);
		break;
	}
}

// Render to the window
void Game::render()
{
	m_window.clear(sf::Color::White);

	switch (Game::currentScene)
	{
	case Scene::None:
		break;
	case Scene::GamePlay:
		gameplay.render(m_window);
		break;
	case Scene::MainMenu:
		mainMenu.render(m_window);
		break;
	}

	m_window.display();
}





