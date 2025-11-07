#include"MainMenu.h"


bool MainMenu::initScene(sf::RenderWindow& window) 
{
	
	for (int i = 0; i < 2; i++) 
	{
		buttonslist[i] = new Buttons();
		if (i == 0)
		{
			buttonslist [i] ->type = ObjectClass::Type::start;
			buttonslist[i]->init(window);
		}
		else if (i == 1)
		{
			buttonslist[i]->type = ObjectClass::Type::quit;
			buttonslist[i]->init(window);
		}
	}
	scene = 0;
	if (scene != 0)
	{
		return false;
	}
	return true;
}

void MainMenu::update(float dt, sf::RenderWindow& window) 
{
	for (int i = 0; i < 2; i++) 
	{
		if (buttonslist[i]->hasClicked(MouseInput)) 
		{
			changeScene = true;
			if (buttonslist[i]->type == ObjectClass::start) 
			{
				next_scene = 1;

			}
			
		}
		buttonslist[i]->update(dt,window);
	}
}

void MainMenu::render(sf::RenderWindow& window) 
{
	for (int i = 0; i < 2; i++)
	{
		buttonslist[i]->render(window);
	}
}

bool MainMenu::clearState()
{
	for (int i = 0; i < 2; i++)
	{
		 buttonslist[i];
	}
	return false;
}
