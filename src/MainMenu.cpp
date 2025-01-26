#include "MainMenu.h"
#include "Game.h"
#include "Globals.h"

MainMenu::MainMenu()
{
	if (!backgroundTexture.loadFromFile("Assets/Art/background.png"))
	{
		std::cout << "couldnt load background";
	}
	backgroundTexture.setRepeated(true);
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setTextureRect(sf::IntRect(0, 3150, SCREEN_WIDTH, SCREEN_HEIGHT));

	if (!quitTexture.loadFromFile("Assets/Art/QuitButton.png"))
	{
		std::cout << "Error loading quit texture \n";
	}
	quitSprite.setTexture(quitTexture);
	quitSprite.setOrigin(800, 1000);
	quitSprite.setScale(0.25, 0.25);

	if (!playTexture.loadFromFile("Assets/Art/PlayButton.png"))
	{
		std::cout << "Error loading play texture \n";
	}
	playSprite.setTexture(playTexture);
	playSprite.setOrigin(800, 1000);
	playSprite.setScale(0.35, 0.35);

	playButton.setupButton({ 200, 200 }, playSprite);
	quitButton.setupButton({ SCREEN_WIDTH - 205, SCREEN_HEIGHT - 175 }, quitSprite);


}

void MainMenu::update(double t_deltaTime)
{
	playButton.checkForMouse(mousePos);
	quitButton.checkForMouse(mousePos);
}

void MainMenu::render(sf::RenderWindow& t_window)
{
	t_window.draw(backgroundSprite);

	t_window.draw(playButton.getBody());
	t_window.draw(quitButton.getBody());
}

void MainMenu::processEvents(sf::Event& t_event, sf::RenderWindow& t_window)
{
	if (sf::Event::MouseButtonPressed == t_event.type)
	{
		processMouseDown(t_event, t_window);
	}

	if (sf::Event::MouseMoved == t_event.type)
	{
		getMousePos(t_event);
	}
}

void MainMenu::processKeys(sf::Event& t_event)
{
}

void MainMenu::processMouseDown(sf::Event& t_event, sf::RenderWindow& t_window)
{
	if (playButton.colliding)
	{
		std::cout << "SWAP \n";
		Game::menuMusic.pause();
		Game::gameMusic.play();
		Game::currentScene = Scene::GamePlay;
	}
	else if (quitButton.colliding)
	{
		t_window.close();
	}
}

void MainMenu::getMousePos(sf::Event& t_event)
{
	mousePos.x = static_cast<float>(t_event.mouseMove.x);
	mousePos.y = static_cast<float>(t_event.mouseMove.y);
}
