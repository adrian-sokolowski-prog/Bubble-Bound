#include "MainMenu.h"

MainMenu::MainMenu()
{
	circle.setRadius(50);
	circle.setFillColor(sf::Color::Red);
}

void MainMenu::update(double t_deltaTime)
{
}

void MainMenu::render(sf::RenderWindow& t_window) const
{
	t_window.draw(circle);
}

void MainMenu::processEvents(sf::Event& t_event)
{
}

void MainMenu::processKeys(sf::Event& t_event)
{
}
