#include "Oxygen.h"
#include <iostream>

Oxygen::Oxygen()
{
	init();
}

void Oxygen::Render(sf::RenderTexture& t_renderTexture)
{
	m_plant.Render(t_renderTexture);
	t_renderTexture.draw(m_platform);
	t_renderTexture.draw(m_oxygenBar);
	t_renderTexture.draw(m_fillOxygen);
}

void Oxygen::Update(float t_dt, sf::CircleShape t_player)
{
	m_timeBetweenUpdate += t_dt;
	sf::Vector2f size = m_fillOxygen.getSize();
	m_platform.setPosition(m_plant.GetPlant().getPosition()+ sf::Vector2f{-100,100});
	if (m_timeBetweenUpdate > 50)
	{
		if (size.x > 0)
		{
			size.x--;
		}
		m_timeBetweenUpdate = 0;
	}
	if (m_collision.CircleSpriteCollision(t_player, m_plant.GetPlant()))
	{
		if(size.x < maxHP)
			size.x++;
	}

	m_fillOxygen.setSize(size);
}

void Oxygen::MoveOxygenUI(sf::Vector2f t_viewCenter)
{
	m_fillOxygen.setPosition(t_viewCenter + m_barPositionOffset);
	m_oxygenBar.setPosition(t_viewCenter + (m_barPositionOffset+ sf::Vector2f{-50,-78}));
}

void Oxygen::TakeDMG(int t_damage)
{
	sf::Vector2f size = m_fillOxygen.getSize();
	size.x = size.x - t_damage;
	m_fillOxygen.setSize(size);
}

void Oxygen::ChangePosition(sf::Vector2f t_playerPosition, sf::View t_viewPort)
{
	if (t_playerPosition.y < m_plant.GetPlant().getPosition().y - 1000)
	{
		std::cout << "random" << std::endl;
		// Get the world coordinates of the top of the viewport
		sf::FloatRect viewBounds = t_viewPort.getViewport();
		float viewTop = t_viewPort.getCenter().y - (t_viewPort.getSize().y / 2.0f);

		// Get the width of the viewport
		float viewLeft = t_viewPort.getCenter().x - (t_viewPort.getSize().x / 2.0f);
		float viewRight = viewLeft + t_viewPort.getSize().x;

		// Generate a random x position within the viewport bounds
		float randomX = viewLeft + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (viewRight - viewLeft));

		// Set the plant's position with the random x position and fixed y position
		m_plant.GetPlant().setPosition(randomX, viewTop - 50);
	}
}

bool Oxygen::isDead()
{
	if (m_fillOxygen.getSize().x <= 0)
	{
		return true;
	}
	return false;
}

void Oxygen::init()
{
	if (!m_oxygenBarTexture.loadFromFile("Assets/Art/OxygenBackground.png")) 
		std::cout << "issue loading texture" << std::endl;

	m_oxygenBar.setTexture(m_oxygenBarTexture);
	m_oxygenBar.setPosition(m_oxygenPos);
	m_oxygenBar.setScale(0.2, 0.2);

	m_fillOxygen.setFillColor(sf::Color::Blue);
	m_fillOxygen.setSize(sf::Vector2f{ maxHP,35 });
	m_fillOxygen.setPosition(m_oxygenPos);

	if (!m_oxygenPlantTexture.loadFromFile("Assets/Art/OxygenPlant.png"))
	{
		std::cout << "issue loading plant" << std::endl;
	}

	if (!m_platformTexture.loadFromFile("Assets/Art/platform.png"))
	{
		std::cout << "platform issue loading" << std::endl;
	}
	m_platform.setTexture(m_platformTexture);

}
