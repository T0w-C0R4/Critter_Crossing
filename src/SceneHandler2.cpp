#include "SceneHandler2.h"

SceneHandler2::SceneHandler2()
{
}

SceneHandler2::~SceneHandler2()
{
}

void SceneHandler2::ChangeScene(int next_scene, sf::RenderWindow& window)
{
	removeCurrentScene();
	currentscene = static_cast<CurrentScene>(next_scene);
	init(window);
}

void SceneHandler2::init(sf::RenderWindow& window)
{
	switch (currentscene)
	{
	case SceneHandler2::mainMenu:
		main_menu->initScene(window);
		break;
	case SceneHandler2::Game:
		active_game->initScene(window);
		break;
	case SceneHandler2::Pause:
		break;
	case SceneHandler2::Win:
		break;
	case SceneHandler2::Lose:
		break;
	default:
		break;
	}
	

	
}
void SceneHandler2::update(float dt, sf::RenderWindow& window) 
{
	switch (currentscene)
	{
	case SceneHandler2::mainMenu:
		main_menu->update(dt, window);//changes states in update
		if (main_menu->changeScene == true) 
		{
			ChangeScene(main_menu->next_scene,window);//changes to new scene based of new state
		}
		
		break;
	case SceneHandler2::Game:
		active_game->update(dt, window);
		if (active_game->changeScene == true)
		{
			ChangeScene(active_game->next_scene, window);//changes to new scene based of new state
		}
		
		break;
	case SceneHandler2::Pause:
		break;
	case SceneHandler2::Win:
		break;
	case SceneHandler2::Lose:
		break;
	default:
		break;
	}
}
void SceneHandler2::render(sf::RenderWindow& window) 
{
	switch (currentscene)
	{
	case SceneHandler2::mainMenu:
		main_menu->render(window);
		break;
	case SceneHandler2::Game:
		active_game->render(window);
		break;
	case SceneHandler2::Pause:
		break;
	case SceneHandler2::Win:
		break;
	case SceneHandler2::Lose:
		break;
	default:
		break;
	}
}

void SceneHandler2::removeCurrentScene()
{
	switch (currentscene)
	{
	case SceneHandler2::mainMenu:
		delete main_menu;
		break;
	case SceneHandler2::Game:
		delete active_game;
		break;
	case SceneHandler2::Pause:
		break;
	case SceneHandler2::Win:
		break;
	case SceneHandler2::Lose:
		break;
	default:
		break;
	}
}

void SceneHandler2::mouseInput(sf::Vector2f click_pos)
{
	switch (currentscene)
	{
	case SceneHandler2::mainMenu:
		main_menu->MouseInput = click_pos;
		break;
	case SceneHandler2::Game:
		active_game->MouseInput = click_pos;
		if (click_pos.x == 0.f && click_pos.y == 0.f)
		{
			active_game->click = false;
		}
		active_game->click = true;
		break;
	case SceneHandler2::Pause:
		break;
	case SceneHandler2::Win:
		break;
	case SceneHandler2::Lose:
		break;
	default:
		break;
	}
}


