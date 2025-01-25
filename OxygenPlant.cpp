#include "OxygenPlant.h"
#include <iostream>

OxygenPlant::OxygenPlant()
{
	if (!m_plantTexture.loadFromFile("Assets/Art/OxygenPlant.png"))
	{
		std::cout << "issue loading plant" << std::endl;
	}
	m_oxygenPlant.setTexture(m_plantTexture);
}

void OxygenPlant::Render(sf::RenderWindow& t_window)
{
	t_window.draw(m_oxygenPlant);
}

void OxygenPlant::Update(float t_dt)
{
}

sf::Sprite& OxygenPlant::GetPlant()
{
	return m_oxygenPlant;
}
