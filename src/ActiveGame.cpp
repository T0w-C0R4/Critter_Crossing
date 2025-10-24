#include "ActiveGame.h"

bool ActiveGame::initScene(sf::RenderWindow& window) 
{
	//add every new pointer to the vector
	character->init(window);
	state_obj.push_back(character);
	return true;
}

void ActiveGame::update(float dt, sf::RenderWindow& window) 
{
	//update everything within the Vector
}

void ActiveGame::render(sf::RenderWindow& window) 
{
	//render everything within the Vector
	for (int i = 0; state_obj.max_size() >= i; i++) 
	{
		state_obj[i].render(window);
	}
}

bool ActiveGame::clearState() 
{
	//delete everything within the Vector

	return true;
}