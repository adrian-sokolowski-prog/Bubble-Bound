#pragma once

#include "SFML/Graphics.hpp"
class OxygenPlant
{
public:
	OxygenPlant();

	void Render(sf::RenderTexture& t_renderTexture);
	void Update(float t_dt);
	sf::Sprite& GetPlant();
private:
	sf::Sprite m_oxygenPlant;
	sf::Texture m_plantTexture;

};
