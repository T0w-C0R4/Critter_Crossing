#pragma once
#include "Scene.h"
class SceneHandler2
{

	public:
		SceneHandler2();
		~SceneHandler2();

		void ChangeScene(int next_scene);
		void init();
		void update(float dt, sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		

		enum CurrentScene {
			MainMenu,
			Game,
			Pause,
			Win,
			Lose
		};
		//clean Scene
		

	private:


		CurrentScene currentscene;
		
};