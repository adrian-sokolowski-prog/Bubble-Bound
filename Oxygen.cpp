#include "Oxygen.h"
#include <iostream>

Oxygen::Oxygen()
{
	init();
}

void Oxygen::Render(sf::RenderTexture& t_renderTexture)
{
	t_renderTexture.draw(m_transparentOxygen);
	t_renderTexture.draw(m_fillOxygen);
	m_plant.Render(t_renderTexture);
}

void Oxygen::Update(float t_dt, sf::CircleShape t_player)
{
	m_timeBetweenUpdate += t_dt;
	sf::Vector2f size = m_fillOxygen.getSize();
	if (m_timeBetweenUpdate > 500)
	{
		if (size.x > 0)
		{
			size.x--;
		}
		m_timeBetweenUpdate = 0;
	}
	if (m_collision.CircleSpriteCollision(t_player, m_plant.GetPlant()))
	{
		size.x++;

	}

	m_fillOxygen.setSize(size);
}

void Oxygen::init()
{
	m_transparentOxygen.setOutlineColor(sf::Color::Red);
	m_transparentOxygen.setOutlineThickness(4.0f);
	m_transparentOxygen.setSize(sf::Vector2f{ 200,50 });
	m_transparentOxygen.setPosition(m_oxygenPos);

	m_fillOxygen.setFillColor(sf::Color::Red);
	m_fillOxygen.setSize(sf::Vector2f{ 200,50 });
	m_fillOxygen.setPosition(m_oxygenPos);

	if (!m_oxygenPlantTexture.loadFromFile("Assets/Art/OxygenPlant.png"))
	{
		std::cout << "issue loading plant" << std::endl;
	}
}
