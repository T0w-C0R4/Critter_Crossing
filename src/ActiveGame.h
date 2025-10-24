#pragma once
#include "Scene.h"
#include "Character.h"


class ActiveGame :public Scene 
{
public:
		bool initScene(sf::RenderWindow& window);
		void update(float dt, sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		bool clearState();

		
private:
	/*person
		passport
		2stamps that stamp the passport
		*/
	Character *character = new Character;

	//make spart pointer to a Vector of game objects used within this game state
};
