#pragma once

#include "SFML/Graphics.hpp"

class Collisions
{
public:
	bool CircleSpriteCollision(sf::CircleShape t_circle, sf::Sprite t_sprite);
	bool RectangleCollision(sf::Sprite t_player, sf::Sprite t_otherSprite);
private:
};