#include "GamePlay.h"
#include "Globals.h"

#include "Game.h"

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

	if (!skyTexture.loadFromFile("Assets/Art/sky.png"))
	{
		std::cout << "couldnt load sky";
	}
	skySprite.setTexture(skyTexture);
	skySprite.setPosition(0.0f, -40000 + SCREEN_HEIGHT);

	if (!endTexture.loadFromFile("Assets/Art/endBubble.png"))
	{
		std::cout << "couldnt load end bubble";
	}
	endSprite.setTexture(endTexture);
	endSprite.setOrigin(1024, 1024);
	endSprite.setPosition(SCREEN_WIDTH / 2.0f, -39300 + SCREEN_HEIGHT);
	endSprite.setScale(0.3, 0.3);
}

void GamePlay::update(double t_deltaTime)
{
	if (!endScreen && view.getCenter().y < -38500)
	{
		endScreen = true;
	}

	if (m_oxygen.isDead())
	{
		Game::gameMusic.pause();
		Game::menuMusic.play();
		Game::currentScene = Scene::MainMenu;
		m_oxygen.reset();
		player.reset();
	}
	moveView();
	brightnessShader.setUniform("height", std::abs(player.getPos().y));

	if (m_collision.CircleSpriteCollision(player.getBody(), m_mine.GetSprite()) && m_mine.isActive)
	{
		m_oxygen.TakeDMG(50);
		m_mine.isActive = false;
	}
	player.move();

	sf::CircleShape shape;
	m_oxygen.Update(t_deltaTime, player.getBody());
	m_oxygen.ChangePosition(player.getPos(), view);
	if (spawnTimer < TIME_BETWEEN_SPAWNS)
	{
		spawnTimer++;
	}
	else
	{
		spawnTimer = 0;

		if (!endScreen)
		{
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				if (!enemies[i].active)
				{
					enemies[i].activate(player.getPos(), view.getCenter().y);
					break;
				}
			}
		}
	}
	
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

	if (!endScreen)
	{
		m_mine.ChangePosition(player.getPos(), view);
		m_mine.Update(t_deltaTime, view);
	}
}

void GamePlay::render(sf::RenderWindow& t_window)
{

	renderTexture.clear();

	renderTexture.draw(backgroundSprite, &brightnessShader);
	renderTexture.draw(skySprite);
	renderTexture.draw(endSprite);
	renderTexture.draw(player.getPlayerSprite());
	//renderTexture.draw(player.getBody());
	if (!endScreen)
	{
		m_oxygen.Render(renderTexture);
	}
	
	renderTexture.setView(view);

	renderTexture.draw(player.getSprite());
	
	if(m_mine.isActive)
		m_mine.Render(renderTexture);
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


	m_mine.Render(renderTexture);
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
	if (view.getCenter().y > -38500)
	{
		view.setCenter(SCREEN_WIDTH / 2.0f, player.getPos().y - 200);
		m_oxygen.MoveOxygenUI(view.getCenter());
	}
}
