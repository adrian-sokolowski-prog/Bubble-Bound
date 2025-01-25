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
		if(size.x < 200)
			size.x++;
	}

	m_fillOxygen.setSize(size);
}

void Oxygen::MoveOxygenUI(sf::Vector2f t_viewCenter)
{
	m_fillOxygen.setPosition(t_viewCenter + m_barPositionOffset);
	m_transparentOxygen.setPosition(t_viewCenter + m_barPositionOffset);
}

void Oxygen::TakeDMG(int t_damage)
{
	sf::Vector2f size = m_fillOxygen.getSize();
	size.x = size.x - t_damage;
	m_fillOxygen.setSize(size);
}

void Oxygen::ChangePosition(sf::Vector2f t_playerPosition, sf::View t_viewPort)
{
	if (t_playerPosition.y < m_plant.GetPlant().getPosition().y - 2000)
	{
		// Get the world coordinates of the top of the viewport
		sf::FloatRect viewBounds = t_viewPort.getViewport();
		float viewTop = t_viewPort.getCenter().y - (t_viewPort.getSize().y / 2.0f);

		// Get the width of the viewport
		float viewLeft = t_viewPort.getCenter().x - (t_viewPort.getSize().x / 2.0f);
		float viewRight = viewLeft + t_viewPort.getSize().x;

		// Seed the random number generator (this only needs to be done once, ideally)
		std::srand(static_cast<unsigned int>(std::time(0)));

		// Generate a random x position within the viewport bounds
		float randomX = viewLeft + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (viewRight - viewLeft));

		// Set the plant's position with the random x position and fixed y position
		m_plant.GetPlant().setPosition(randomX, viewTop - 50);
	}
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
