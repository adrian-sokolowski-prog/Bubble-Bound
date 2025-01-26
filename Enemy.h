#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
public:
	Enemy();
	bool m_collied = false;
	sf::Sprite& getSprite() { return sprite; }
	sf::Vector2f getPos() { return position; }
	void move();

	void activate(sf::Vector2f t_targetPos, float t_viewCenter);


	bool active = false;

private:

	sf::Sprite sprite;
	sf::Texture sharkTexture;
	sf::Texture piranhaTexture;

	const int RADIUS = 30;

	sf::Vector2f position;
	sf::Vector2f velocity;
	int speed = 7;
};

