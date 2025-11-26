#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window): window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	SFM->init(window);
  return true;
}

void Game::update(float dt)
{
	SFM->update(dt,window);
}

void Game::render()
{
	SFM->render(window);
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  sf::Vector2f clickf;
  clickf.x = click.x;
  clickf.y = click.y;
  SFM->mouseInput(clickf);

}

void Game::mouseReleased(sf::Event event)
{
	sf::Vector2f release;
	release.x = 0;
	release.y = 0;
	SFM->mouseInput(release);
}

void Game::keyPressed(sf::Event event)
{

}


