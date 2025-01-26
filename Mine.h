#pragma once

#include "SFML/Graphics.hpp"
#include "iostream"

class Mine
{
public:
	Mine();
	void Render(sf::RenderTexture& t_renderTexture);
	void Update(float t_dt, sf::View t_port);
	sf::Sprite& GetSprite();
	void SpawnMine(sf::View t_port);
	void ChangePosition(sf::Vector2f t_playerPosition, sf::View t_viewPort);
	bool isActive = 0;
	float m_spawnTime = 0;
private:

	void init();
	sf::Sprite m_mine;
	sf::Texture m_mineTexture;
};