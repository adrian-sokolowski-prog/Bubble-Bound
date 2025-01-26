#include "Mine.h"

Mine::Mine()
{
	init();
}

void Mine::Render(sf::RenderWindow& t_window)
{
	t_window.draw(m_mine);
}

void Mine::Update(float t_dt)
{
	m_mine.move(0, 1);
}

sf::Sprite& Mine::GetSprite()
{
	return m_mine;
}

void Mine::init()
{
	if (!m_mineTexture.loadFromFile("Assets/Art/Mine.png"))
	{
		std::cout << "mine not loaded" << std::endl;
	}
	m_mine.setTexture(m_mineTexture);
	m_mine.setScale(0.05, 0.05);
	m_mine.setPosition(0, 0);
}
