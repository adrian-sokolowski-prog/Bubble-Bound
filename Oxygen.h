#pragma once
#include "SFML/Graphics.hpp"

class Oxygen
{

public:
	Oxygen();
	void Render(sf::RenderWindow& t_window);
	void Update(float t_dt);


private:

	sf::RectangleShape m_transparentOxygen;
	sf::RectangleShape m_fillOxygen;

	void init();
	
	float m_timeBetweenUpdate = 0;
	sf::Vector2f m_oxygenPos{ 100,200 };
};