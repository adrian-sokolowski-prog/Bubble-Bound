// Ian Perez Bunuel
// C00294680

#include "Button.h"
#include <iostream>

Button::Button()
{
}

void Button::setupButton(sf::Vector2f t_pos, sf::Sprite t_sprite)
{
	sprite = t_sprite;

	body.setSize({ size, size });
	body.setFillColor(sf::Color::Blue);

	body.setOutlineThickness(10);
	body.setOutlineColor({ 0, 175, 255, 255 });

	body.setOrigin({ size / 2, size / 2 });

	sprite.setOrigin(800, 1000);

	position = t_pos;
	body.setPosition(position);
}

bool Button::checkForMouse(sf::Vector2f t_mousePos)
{
	// Check if the mouse is within the button on the x-axis
	if (t_mousePos.x >= position.x - ((size + 20) / 2) && t_mousePos.x <= position.x + ((size + 20) / 2))
	{
		// Check if the mouse is within the button on the y-axis
		if (t_mousePos.y <= position.y + ((size + 20) / 2) && t_mousePos.y >= position.y - ((size + 20) / 2))
		{
			// Change the size when hovering
			hovering();


			colliding = true;
			return true; // if colliding
		}
	}


	colliding = false;
	notHovering();

	return colliding; // if not colliding
}

void Button::hovering()
{
	// Change fill colour
	body.setFillColor({ 0, 100, 255, 255 });

	if (size <= MAX_SIZE) // if the size isnt max
	{
		// Change size
		size += CHANGE_PER_FRAME;
		body.setSize({ size, size });
		body.setOrigin(size / 2, size / 2);

		scale += 0.01f;
		sprite.setScale(scale, scale);
	}
}

void Button::notHovering()
{
	// Change fill colour back
	body.setFillColor(sf::Color::Blue);

	if (size >= MIN_SIZE)
	{
		// Change size
		size -= CHANGE_PER_FRAME;
		body.setSize({ size, size });
		body.setOrigin(size / 2, size / 2);

		scale -= 0.01f;
		sprite.setScale(scale, scale);
	}
}