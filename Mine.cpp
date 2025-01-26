#include "Mine.h"

Mine::Mine()
{
	init();
}

void Mine::Render(sf::RenderTexture& t_renderTexture)
{
	t_renderTexture.draw(m_mine);
}

void Mine::Update(float t_dt, sf::View t_port)
{
	if (isActive)
	{
		std::cout << "active" << std::endl;
		m_mine.move(0, 1);
	}

	if (!isActive)
	{
		m_spawnTime += t_dt;
		std::cout << "waiting on spawn" << std::endl;
		if (m_spawnTime > 5000)
		{
			std::cout << "spawned" << std::endl;
			m_spawnTime = 0;
			isActive = true;
			SpawnMine(t_port);
		}
	}
}

sf::Sprite& Mine::GetSprite()
{
	return m_mine;
}

void Mine::SpawnMine(sf::View t_port)
{
	int randTexture = rand() % 2;
	if (randTexture == 0)
	{
		m_mine.setTexture(m_mineTexture);
	}
	else
	{
		m_mine.setTexture(m_crateTexture);
	}

	float viewTop = t_port.getCenter().y - (t_port.getSize().y / 2.0f);
	float viewLeft = t_port.getCenter().x - (t_port.getSize().x / 2.0f);
	float viewRight = viewLeft + t_port.getSize().x;
	float randomX = viewLeft + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (viewRight - viewLeft));
	m_mine.setPosition(randomX, viewTop - 100);
}

void Mine::ChangePosition(sf::Vector2f t_playerPosition, sf::View t_viewPort)
{
	if (t_playerPosition.y < m_mine.getPosition().y - 1000)
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
		m_mine.setPosition(randomX, viewTop - 100);
	}
}

void Mine::init()
{
	if (!m_mineTexture.loadFromFile("Assets/Art/Mine.png"))
	{
		std::cout << "mine not loaded" << std::endl;
	}
	if (!m_crateTexture.loadFromFile("Assets/Art/crate.png"))
	{
		std::cout << "crate not loaded" << std::endl;
	}

	m_mine.setScale(0.05, 0.05);
}
