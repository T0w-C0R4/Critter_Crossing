#pragma once
#include "Scene.h"

class ActiveGame :public Scene 
{

		bool initScene(sf::RenderWindow& window);
		void update(float dt, sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		bool clearState();

		/*person
		passport
		2stamps that stamp the passport
		*/

};
