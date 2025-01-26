#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio/Music.hpp>
#include "Button.h"
#include <SFML/Audio.hpp>

class MainMenu
{
public:
	MainMenu();

	void update(double t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event& t_event, sf::RenderWindow& t_window);
	void processKeys(sf::Event& t_event);

private:

	void processMouseDown(sf::Event& t_event, sf::RenderWindow& t_window);
	void getMousePos(sf::Event& t_event);
	sf::Vector2f mousePos;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	Button playButton;
	Button quitButton;

	sf::Texture playTexture;
	sf::Sprite playSprite;
	sf::Texture quitTexture;
	sf::Sprite quitSprite;
	sf::SoundBuffer bubblesBuffer;
	sf::Sound bubblesSound;
};

