#include "Player.h"
#include "Globals.h"

Player::Player()
{
	body.setFillColor(sf::Color::Blue);
	body.setRadius(RADIUS);
	body.setOrigin(RADIUS, RADIUS);
	position = { SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT * 0.8f };
	body.setPosition(position);
}

void Player::move()
{
	checkDirection();
	applyFriction();

	position += velocity;
	body.setPosition(position);
}

void Player::checkDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}
}

void Player::applyFriction()
{
	velocity.x *= FRICTION;
	velocity.y *= FRICTION;

	velocity.y -= 0.05f;
}
