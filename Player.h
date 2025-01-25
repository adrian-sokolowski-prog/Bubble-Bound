#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	Player();

	sf::CircleShape getBody() { return body; }

	void move();

private:

	void checkDirection();
	void applyFriction();

	sf::CircleShape body;
	const float RADIUS = 30;

	const float FRICTION = 0.98f;

	sf::Vector2f position;
	sf::Vector2f velocity;
	float speed = 0.3f;

};

