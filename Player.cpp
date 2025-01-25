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

	movementDrift();

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
}

void Player::movementDrift()
{
	

	if (driftTimer < TIME_BETWEEN_DRIFT_CHANGE)
	{
		driftTimer++;
	}
	else
	{
		int randChange = (rand() % 30) - 10;
		driftAngle += randChange;
		driftTimer = 0;
	}


	drift.x = std::cos(degreesToRadians(driftAngle)) * DRIFT_INTENCITY;
	drift.y = -std::abs(std::sin(degreesToRadians(driftAngle)) * DRIFT_INTENCITY);

	velocity.x += drift.x;
	velocity.y += drift.y;
}
