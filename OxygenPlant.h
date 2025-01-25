#pragma once

#include "SFML/Graphics.hpp"
class OxygenPlant
{
public:
	OxygenPlant();

	void Render(sf::RenderWindow& t_window);
	void Update(float t_dt);
	sf::Vector2f GetPlantPos();
private:
	sf::Sprite m_oxygenPlant;
	sf::Texture m_plantTexture;

};
