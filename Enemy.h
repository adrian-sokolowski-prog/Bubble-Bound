#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
public:
	Enemy();

	sf::Sprite getSprite() { return sprite; }
	sf::Vector2f getPos() { return position; }

	void move();

	void activate(sf::Vector2f t_targetPos);


	bool active = false;

private:

	sf::Sprite sprite;
	sf::Texture texture;

	const int RADIUS = 30;

	sf::Vector2f position;
	sf::Vector2f velocity;
	int speed = 5;
};

