#include "GamePlay.h"
#include "Globals.h"

GamePlay::GamePlay()
{
	loadShader();

	circle.setRadius(50);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(100, 100);

	if (!renderTexture.create(SCREEN_WIDTH, SCREEN_HEIGHT))
	{	
		std::cout << "Couldnt create texture\n";
	}
}

void GamePlay::update(double t_deltaTime)
{
	underWaterShader.setUniform("time", clock.getElapsedTime().asSeconds());
}

void GamePlay::render(sf::RenderWindow& t_window) 
{
	renderTexture.clear();

	renderTexture.draw(tileSprite);
	renderTexture.draw(circle);

	renderTexture.display();

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


	if (!tiles.loadFromFile("Assets/Shaders/tiles.jpg"))
	{
		std::cout << "Couldnt load tiles texture\n";
	}
	tiles.setRepeated(true);
	tileSprite.setTexture(tiles);
	tileSprite.setTextureRect(sf::IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

}
