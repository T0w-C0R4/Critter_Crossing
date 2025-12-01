#include "life.h"

void life::init(sf::RenderWindow& window) 
{
	initialiseSprite("../Data/Images/kenney_physicspack/PNG/Aliens/alienGreen_round.png");
}
void life::update(float dt, sf::RenderWindow& window) 
{

}
void life::render(sf::RenderWindow& window) 
{
	if (visible)
	{
		window.draw(*sprite);
	} 

	
}
void life::handleEvent()
{
	
}