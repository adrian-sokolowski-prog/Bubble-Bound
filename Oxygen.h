#pragma once
#include "SFML/Graphics.hpp"
#include <OxygenPlant.h>

class Oxygen
{

public:
	Oxygen();
	void Render(sf::RenderWindow& t_window);
	void Update(float t_dt, sf::CircleShape t_player);


private:

	sf::RectangleShape m_transparentOxygen;
	sf::RectangleShape m_fillOxygen;

	void init();
	
	float m_timeBetweenUpdate = 0;
	sf::Vector2f m_oxygenPos{ 100,200 };

	sf::Texture m_oxygenPlantTexture;

	OxygenPlant m_plant;
};