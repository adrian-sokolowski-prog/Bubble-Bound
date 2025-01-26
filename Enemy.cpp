#include "Enemy.h"
#include "Globals.h"

Enemy::Enemy()
{
	if (!sharkTexture.loadFromFile("Assets/Art/Shark.png"))
	{
		std::cout << "Couldnt load enemy texture \n";
	}
	if (!piranhaTexture.loadFromFile("Assets/Art/piranha.png"))
	{
		std::cout << "Couldnt load enemy texture \n";
	}
	// Sprite
	position = { 200, 200 };
	sprite.setPosition(position);
	sprite.setOrigin(731, 721);
	sprite.setScale(0.25, 0.25);
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
	int randTexture = rand() % 2;
	if (randTexture == 0)
	{
		sprite.setTexture(sharkTexture);
		sprite.setTextureRect(sf::IntRect(0, 0, 820, 340));
	}
	else
	{
		sprite.setTexture(piranhaTexture);
		sprite.setTextureRect(sf::IntRect(0, 0, 388, 320));
	}

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
