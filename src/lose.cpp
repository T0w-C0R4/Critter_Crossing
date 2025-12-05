#include "lose.h"

bool Lose::initScene(sf::RenderWindow& window)
{
	if (!initString(window, "your final score: " + std::to_string(score), 2, 4))
	{
		std::cout << "string failed to initialise" << std::endl;
	}

	initButtons(window);

	return true;
}
void Lose::update(float dt, sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		buttonslist[i]->update(dt, window);

		if (buttonslist[i]->hasClicked(MouseInput))
		{
			if (buttonslist[i]->type == ObjectClass::restart)
			{
				changeScene = true;
				next_scene = 1;
			}
			if (buttonslist[i]->type == ObjectClass::quit)
			{
				exit(0);
			}
		}
	}


}
void Lose::render(sf::RenderWindow& window)
{
	window.draw(*scene_text);

	for (int i = 0; i < 2; i++)
	{
		buttonslist[i]->render(window);
	}
}
bool Lose::clearState()
{
	return true;
}



bool Lose::initButtons(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		buttonslist[i] = new Buttons();
		if (i == 0)
		{
			buttonslist[i]->type = ObjectClass::Type::restart;
			buttonslist[i]->init(window);
		}
		else if (i == 1)
		{
			buttonslist[i]->type = ObjectClass::Type::quit;
			buttonslist[i]->init(window);
		}
	}
	return false;
}
