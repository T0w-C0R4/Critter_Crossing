#pragma once
#include "Scene.h"
class Lose : public Scene
{
public:
	bool initScene(sf::RenderWindow& window);
	void update(float dt, sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	bool clearState();
	bool initString(sf::RenderWindow& window);

	int score;

private:

	sf::Text score_text;
	sf::Font score_font;

};