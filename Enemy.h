#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
public:
	Enemy(sf::Texture& t_texture, sf::Vector2f t_targetPos);

	sf::Sprite getSprite() { return sprite; }

	void move();

private:

	sf::Sprite sprite;
	sf::Texture& texture;

	const int RADIUS = 30;

	sf::Vector2f position;
	sf::Vector2f velocity;
	int speed = 5;

	sf::Vector2f targetPos;

	bool active = true;

	float degreesToRadians(int t_degrees) { return t_degrees * (3.14f / 180); }
};

