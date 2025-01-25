#pragma once

#include "SFML/Graphics.hpp"
#include "iostream"

class Mine
{
public:
	Mine();
	void Render(sf::RenderWindow& t_window);
	void Update(float t_dt);
	sf::Sprite& GetSprite();
	bool isActive = 0;
private:

	void init();
	sf::Sprite m_mine;
	sf::Texture m_mineTexture;
};