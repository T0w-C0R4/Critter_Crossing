#include "ActiveGame.h"

bool ActiveGame::initScene(sf::RenderWindow& window)
{

	state_obj.emplace_back(std::make_shared<Character>());
	state_obj[0].get()->init(window);
	score = 0;


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


	if (!initString(window, "current score: " + std::to_string(score), 2, 1.1))
	{
		std::cout << "string failed to initialise" << std::endl;
	}


	stamp[0] = new Stamp;
	stamp[0]->type = ObjectClass::Type::accept;
	stamp[0]->init(window);

	stamp[1] = new Stamp;
	stamp[1]->type = ObjectClass::Type::reject;
	stamp[1]->init(window);

	return true;
}

void ActiveGame::update(float dt, sf::RenderWindow& window)
{
	initString(window, "current score: " + std::to_string(score), 2, 1.1);

		


	if (click)
	{
		state_obj[0].get()->getPassport()->clickCheck(MouseInput);

		click = false;
	}
	//update everything within the Vector
	for (int i = 0; state_obj.size() > i; i++)
	{
		state_obj[i].get()->update(dt, window);
	}
	//valid passport check
	if (!click && state_obj[0].get()->getPassport()->stamped && state_obj[0].get()->getPassport()->getSprite()->getGlobalBounds().contains(state_obj[0].get()->getSprite()->getGlobalBounds().getPosition().x, state_obj[0].get()->getSprite()->getGlobalBounds().getPosition().y) && state_obj[0].get()->valid)
	{
		if (!state_obj[0].get()->getPassport()->correct_stamp)
		{
			state_obj[0].get()->init(window);
			Life_counter[next_life - 1]->visible = false;
			next_life--;
		}
		else if (state_obj[0].get()->getPassport()->correct_stamp)
		{
			score++;
			state_obj[0].get()->init(window);
		}

	}

	//invalid passport check
	else if (!click && state_obj[0].get()->getPassport()->stamped && state_obj[0].get()->getPassport()->getSprite()->getGlobalBounds().contains(state_obj[0].get()->getSprite()->getGlobalBounds().getPosition().x, state_obj[0].get()->getSprite()->getGlobalBounds().getPosition().y) && !state_obj[0].get()->valid)
	{
		if (state_obj[0].get()->getPassport()->correct_stamp)
		{
			state_obj[0].get()->init(window);
			Life_counter[next_life - 1]->visible = false;
			next_life--;
		}
		else if (!state_obj[0].get()->getPassport()->correct_stamp)
		{
			score++;
			state_obj[0].get()->init(window);
		}

	}

	for (int i = 0; i <= 1; i++)
	{
		if (stamp[i]->hasClicked(MouseInput) && !state_obj[0].get()->getPassport()->stamped)
		{
			stamp[i]->clicked = true;
			stamp[i]->setPassRef(state_obj[0].get()->getPassport()->getSprite()->getGlobalBounds().getPosition());
			state_obj[0].get()->getPassport()->stamped = true;
			state_obj[0].get()->getPassport()->correct_stamp = stamp[i]->returnType();
		}

		stamp[i]->update(dt, window);
	}

	if (next_life <= 0) //lose
	{
		changeScene = true;
		next_scene = 4;
	}
	else if (score == 10) //win
	{
		changeScene = true;
		next_scene = 3;
	}
}

void ActiveGame::render(sf::RenderWindow& window)
{
	window.draw(*scene_text);

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
	stamp[1]->render(window);
	stamp[0]->render(window);
}

bool ActiveGame::clearState()
{
	//delete everything within the Vector

	return true;
}