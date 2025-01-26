#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	Player();

	sf::CircleShape getBody() { return body; }
	sf::Sprite getSprite() { return sprite; }

	sf::Vector2f getPos() { return position; }

	void move();

private:

	void edgeCollision();
	void checkDirection();
	void applyFriction();
	void movementDrift();
	sf::Vector2f drift;

	sf::CircleShape body;
	const float RADIUS = 30;

	// Sprite / Texture
	sf::Sprite sprite;
	sf::Texture texture;

	const float FRICTION = 0.98f;

	sf::Vector2f position;
	sf::Vector2f velocity;
	float speed = 1.5f; //0.15f;
	int driftAngle = -90;
	const float DRIFT_INTENCITY = 0.07f;

	// Drift change timer
	const int TIME_BETWEEN_DRIFT_CHANGE = 10;
	int driftTimer = 0;


	float degreesToRadians(int t_degrees) { return t_degrees * (3.14f / 180); }
};

