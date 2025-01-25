#include "Collisions.h"

bool Collisions::CircleSpriteCollision(sf::CircleShape t_circle, sf::Sprite t_sprite)
{
    bool collision = false;
    float radius = t_circle.getRadius();
    sf::Vector2f circleCenter = t_circle.getPosition() + sf::Vector2f(radius, radius);
    sf::FloatRect spriteBounds = t_sprite.getGlobalBounds();

    float nearestX = std::max(spriteBounds.left, std::min(circleCenter.x, spriteBounds.left + spriteBounds.width));
    float nearestY = std::max(spriteBounds.top, std::min(circleCenter.y, spriteBounds.top + spriteBounds.height));

    float deltaX = circleCenter.x - nearestX;
    float deltaY = circleCenter.y - nearestY;


    return (deltaX * deltaX + deltaY * deltaY) <= (radius * radius);
}

bool Collisions::RectangleCollision(sf::Sprite t_player, sf::Sprite t_otherSprite)
{
    // Get the global bounds of both sprites
    sf::FloatRect playerBounds = t_player.getGlobalBounds();
    sf::FloatRect otherBounds = t_otherSprite.getGlobalBounds();

    // Check if the two bounding boxes intersect
    return playerBounds.intersects(otherBounds);
}