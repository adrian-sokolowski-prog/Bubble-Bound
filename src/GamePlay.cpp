#include "GamePlay.h"
#include "Globals.h"

GamePlay::GamePlay()
{
	srand(time(nullptr));

	view.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	view.setCenter(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	loadShader();

	if (!renderTexture.create(SCREEN_WIDTH, SCREEN_HEIGHT))
	{	
		std::cout << "Couldnt create texture\n";
	}

	if (!backgroundTexture.loadFromFile("Assets/Art/background.png"))
	{
		std::cout << "couldnt load background";
	}
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0.0f, -40000 + SCREEN_HEIGHT);
	backgroundSprite.setTextureRect(sf::IntRect(0,0, 1200, 40000));
}

void GamePlay::update(double t_deltaTime)
{
	moveView();
	brightnessShader.setUniform("height", std::abs(player.getPos().y));


	player.move();

	sf::CircleShape shape;
	m_oxygen.Update(t_deltaTime, player.getBody());

	if (spawnTimer < TIME_BETWEEN_SPAWNS)
	{
		spawnTimer++;
	}
	else
	{
		spawnTimer = 0;

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			if (!enemies[i].active)
			{

				enemies[i].activate(player.getPos());
				break;
			}
			
		}
	}
	m_oxygen.ChangePosition(player.getPos(), view);
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		enemies[i].move();

		if (m_collision.CircleSpriteCollision(player.getBody(), enemies[i].getSprite()) && !enemies[i].m_collied && enemies[i].active)
		{
			std::cout << "Damage" << std::endl;
			enemies[i].m_collied = true;
			m_oxygen.TakeDMG(20);
		}
	}
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	renderTexture.clear();

	renderTexture.draw(backgroundSprite, &brightnessShader);

	renderTexture.draw(player.getBody());
	m_oxygen.Render(renderTexture);
	
	renderTexture.setView(view);

	renderTexture.draw(player.getSprite());

	for (Enemy& e : enemies)
	{
		if (e.active)
		{
			renderTexture.draw(e.getSprite());
		}
	}

	renderTexture.display();
	underWaterShader.setUniform("time", clock.getElapsedTime().asSeconds());

	sf::Sprite screenSprite(renderTexture.getTexture());
	t_window.draw(screenSprite, &underWaterShader);
}


void GamePlay::processEvents(sf::Event& t_event)
{
}

void GamePlay::processKeys(sf::Event& t_event)
{
}

void GamePlay::loadShader() // shader.setUniform("texture", sf::Shader::CurrentTexture);
{
	if (!underWaterShader.loadFromFile("Assets/Shaders/UnderWater.frag", sf::Shader::Fragment))
	{
		std::cout << "COULDN'T LOAD SHADER \n";
	}
	if (!noiseTexture.loadFromFile("Assets/Shaders/Perlin.png"))
	{
		std::cout << "Couldnt load noise texture\n";
	}
	noiseTexture.setRepeated(true);
	noiseTexture.setSmooth(true);
	underWaterShader.setUniform("noiseTexture", noiseTexture);

	if (!brightnessShader.loadFromFile("Assets/Shaders/DarkToBright.frag", sf::Shader::Fragment))
	{
		std::cout << "COULDN'T LOAD DARK-TO-BRIGHT SHADER \n";
	}
}

void GamePlay::moveView()
{
	view.setCenter(SCREEN_WIDTH / 2.0f, player.getPos().y - 200);
	m_oxygen.MoveOxygenUI(view.getCenter());
}
