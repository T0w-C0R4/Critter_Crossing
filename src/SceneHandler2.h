#pragma once
#include "MainMenu.h"
#include "ActiveGame.h"	
#include "lose.h"
#include "Win.h"

class SceneHandler2
{

	public:
		SceneHandler2();
		~SceneHandler2();

		void ChangeScene(int next_scene, sf::RenderWindow& window);
		void init(sf::RenderWindow& window);
		void update(float dt, sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		void removeCurrentScene();

		void mouseInput(sf::Vector2f click_pos);
		

		enum CurrentScene {
			mainMenu,
			Game,
			Pause,
			win,
			lose
		};
		
		int temp_score;

	private:


		CurrentScene currentscene = SceneHandler2::CurrentScene::mainMenu;
		MainMenu* main_menu = new MainMenu;
		ActiveGame* active_game = new ActiveGame;
		Lose* Lose_state = new Lose;
		Win* Win_state = new Win;
};