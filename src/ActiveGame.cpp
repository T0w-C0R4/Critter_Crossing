#include "ActiveGame.h"

bool ActiveGame::initScene(sf::RenderWindow& window) 
{
	//char_passport = std::make_shared<Passport>();
	state_obj.emplace_back(std::make_shared<Character>());
	state_obj[0].get()->init(window);
	// state_obj.push_back(std::move(char_passport));
	
	for (int i = 0; i <= 2; i++)
	{

		Life_counter[i] = new life;
		Life_counter[i]->init(window);
		Life_counter[i]->type = ObjectClass::Type::life;
		Life_counter[i]->getSprite()->setPosition(
			(i + 100.0) * i,
			0);
		next_life++;

	}
	for (int i = 0; i <= 1; i++)
	{

		stamp[i] = new Stamp;
		if (i == 1)
		{
			stamp[i]->type = ObjectClass::Type::accept;
			
		}
		else
		{
			stamp[i]->type = ObjectClass::Type::reject;
		}

		stamp[i]->init(window);
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

	for (int i = 0; i <= 1; i++)
	{
		stamp[i]->update(dt,window);
	}
	
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
	stamp[0]->render(window);
	stamp[1]->render(window);
}

bool ActiveGame::clearState() 
{
	//delete everything within the Vector

	return true;
}