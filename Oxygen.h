#pragma once
#include "SFML/Graphics.hpp"
#include <OxygenPlant.h>
#include <Collisions.h>

class Oxygen
{

public:
	Oxygen();
	void Render(sf::RenderTexture& t_renderTexture);
	void Update(float t_dt, sf::CircleShape t_player);


private:

	sf::RectangleShape m_transparentOxygen;
	sf::RectangleShape m_fillOxygen;

	void init();
	
	float m_timeBetweenUpdate = 0;
	sf::Vector2f m_oxygenPos{ 100,200 };

	sf::Texture m_oxygenPlantTexture;

	OxygenPlant m_plant;
	Collisions m_collision;
};