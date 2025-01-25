#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button
{
public:

	Button();

	// setup
	void setupButton(sf::Vector2f t_pos, sf::Sprite t_sprite);

	// "Get" functions
	sf::Sprite getBody() { return sprite; }

	// Mouse check
	bool checkForMouse(sf::Vector2f t_mousePos);

	// Animate
	void hovering();
	void notHovering();

	// Collision
	bool colliding = false;

private:
	sf::RectangleShape body;

	sf::Sprite sprite;

	sf::Vector2f position;
	float size = 250.0f;
	float scale = 0.3f;
	const int MIN_SIZE = 250;
	const float MIN_SCALE = 0.3f;
	const int MAX_SIZE = 325;
	const float MAX_SCALE = 0.1f;
	const int CHANGE_PER_FRAME = 5;
};

