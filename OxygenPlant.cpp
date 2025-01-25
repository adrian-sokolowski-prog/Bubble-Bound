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

void OxygenPlant::Render(sf::RenderTexture& t_renderTexture)
{
	t_renderTexture.draw(m_oxygenPlant);
}

void OxygenPlant::Update(float t_dt)
{
}

sf::Sprite& OxygenPlant::GetPlant()
{
	return m_oxygenPlant;
}
