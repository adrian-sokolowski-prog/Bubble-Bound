#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GamePlay
{
public:
	GamePlay();

	void update(double t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void processEvents(sf::Event& t_event);
	void processKeys(sf::Event& t_event);

private:

	// Shader
	sf::Clock clock;
	sf::Texture noiseTexture;
	void loadShader();
	sf::Shader underWaterShader;
	sf::RenderTexture renderTexture;

	// TEMP TEXTURE
	sf::Texture tiles;
	sf::Sprite tileSprite;

	sf::CircleShape circle;

};

