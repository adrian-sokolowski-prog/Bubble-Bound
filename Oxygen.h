#pragma once
#include "SFML/Graphics.hpp"
#include <OxygenPlant.h>
#include <Collisions.h>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
class Oxygen
{

public:
	Oxygen();
	void Render(sf::RenderTexture& t_renderTexture);
	void Update(float t_dt, sf::CircleShape t_player);
	void MoveOxygenUI(sf::Vector2f t_viewCenter);
	void TakeDMG(int t_damage);
	void ChangePosition(sf::Vector2f t_playerPosition, sf::View t_viewPort);
	bool isDead();

	void reset() { m_fillOxygen.setSize({ maxHP, 35}); }
private:
	sf::Sprite m_oxygenBar;
	sf::Texture m_oxygenBarTexture;
	sf::RectangleShape m_fillOxygen;
	sf::Sprite m_platform;
	sf::Texture m_platformTexture;
	void init();
	
	float m_timeBetweenUpdate = 0;
	sf::Vector2f m_oxygenPos{ 100,200 };
	sf::Vector2f m_barPositionOffset{ -500,-350 };
	float maxHP = 330;
	sf::Texture m_oxygenPlantTexture;

	OxygenPlant m_plant;
	Collisions m_collision;
};