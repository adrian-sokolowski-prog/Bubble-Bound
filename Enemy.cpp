#include "Enemy.h"

Enemy::Enemy(sf::Texture& t_texture, sf::Vector2f t_targetPos) : texture(t_texture)
{
	sprite.setTexture(texture);

	position = { 200, 200 };
	sprite.setPosition(position);
	sprite.setOrigin(731, 721);
	sprite.setScale(0.1, 0.1);
}

void Enemy::move()
{
	// Variables
	float distance = 0.0f;
	float angle = 0.0f;
	sf::Vector2f directionVec = { 0.0f, 0.0f };

	velocity.x = std::cos(degreesToRadians(angle)) * speed;
	velocity.y = std::sin(degreesToRadians(angle)) * speed;

	sprite.setRotation(angle);

	position += velocity;
	sprite.setPosition(position);
}
