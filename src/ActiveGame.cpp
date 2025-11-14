#include "ActiveGame.h"

bool ActiveGame::initScene(sf::RenderWindow& window) 
{
	state_obj.reserve(10);
	//add every new pointer to the vector
	character = std::make_shared<Character>();
	character->init(window);
	
	state_obj.push_back(std::move(character));
	
	return true;
}

void ActiveGame::update(float dt, sf::RenderWindow& window) 
{

	//update everything within the Vector
}

void ActiveGame::render(sf::RenderWindow& window) 
{
	
	//render everything within the Vector
	for (int i = 0; state_obj.size() > i; i++) 
	{
		
		if (state_obj[i].get()->getSprite() != NULL)
		{
			state_obj[i].get()->render(window);
		}
		
	}
}

bool ActiveGame::clearState() 
{
	//delete everything within the Vector

	return true;
}