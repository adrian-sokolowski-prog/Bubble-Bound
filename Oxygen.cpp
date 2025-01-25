#include "Oxygen.h"

Oxygen::Oxygen()
{
	init();
}

void Oxygen::Render(sf::RenderWindow& t_window)
{
	t_window.draw(m_transparentOxygen);
	t_window.draw(m_fillOxygen);
}

void Oxygen::Update(float t_dt)
{
	m_timeBetweenUpdate += t_dt;
	if (m_timeBetweenUpdate > 500)
	{
		sf::Vector2f size = m_fillOxygen.getSize();
		if (size.x > 0)
		{
			size.x--;
			m_fillOxygen.setSize(size);
		}
		m_timeBetweenUpdate = 0;
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
}
