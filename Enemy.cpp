#include "Enemy.h"
#include "Globals.h"

Enemy::Enemy()
{
	if (!texture.loadFromFile("Assets/Art/Shark.png"))
	{
		std::cout << "Couldnt load enemy texture \n";
	}
	// Sprite
	sprite.setTexture(texture);
	position = { 200, 200 };
	sprite.setPosition(position);
	sprite.setOrigin(731, 721);
	sprite.setScale(0.1, 0.1);
}

void Enemy::move()
{
	if (active)
	{
		position += velocity;
		sprite.setPosition(position);

		if (position.y > SCREEN_HEIGHT + RADIUS)
		{
			position = { -1000, 0 };
			active = false;
		}
	}
}

void Enemy::activate(sf::Vector2f t_targetPos, float t_viewCenter)
{
	// Set position
	int randChange = (rand() % 400) - 200;
	position.x = t_targetPos.x  + randChange;
	position.y = (t_viewCenter - SCREEN_HEIGHT / 2.0f) - 150;

	// Movement Calc
	float lenght = 0.0f;
	sf::Vector2f heading(0.0f, 0.0f);

	heading.x = (t_targetPos.x) - position.x;
	heading.y = (t_targetPos.y) - position.y;
	lenght = sqrtf((heading.x * heading.x) + (heading.y * heading.y)); // find the distance

	heading = heading / lenght;
	heading.x *= speed; // change speed to the actual speed
	heading.y *= speed; // change speed to the actual speed
	velocity = heading;

	// Activate
	active = true;
}
