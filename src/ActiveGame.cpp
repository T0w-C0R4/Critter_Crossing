#include "ActiveGame.h"

bool ActiveGame::initScene(sf::RenderWindow& window) 
{
	//char_passport = std::make_shared<Passport>();
	state_obj.emplace_back(std::make_shared<Character>());
	state_obj[0].get()->init(window);
	// state_obj.push_back(std::move(char_passport));
	
	for (int i = 0; i <= 2; i++)
	{

		Life_counter[next_life] = new life;
		Life_counter[next_life]->init(window);
		Life_counter[next_life]->type = ObjectClass::Type::life;
		Life_counter[next_life]->getSprite()->setPosition(
			(i + 100.0) * i,
			0);
		next_life++;

	}
	return true;
}

void ActiveGame::update(float dt, sf::RenderWindow& window) 
{

	if (click) 
	{
		state_obj[0].get()->getPassport()->clickCheck(MouseInput);
		click = false;
	}
	//update everything within the Vector
	for (int i = 0; state_obj.size() > i; i++)
	{
		state_obj[i].get()->update(dt,window);
	}
	state_obj[0].get()->getPassport();
	
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
	for (int i = 0; i <= 2; i++)
	{
		Life_counter[i]->render(window);
	}
}

bool ActiveGame::clearState() 
{
	//delete everything within the Vector

	return true;
}