#pragma once
#include "Scene.h"
#include "Button.h"

class Lose : public Scene
{
public:
	bool initScene(sf::RenderWindow& window);
	void update(float dt, sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	bool clearState();
	bool initButtons(sf::RenderWindow& window);
	int score;


	Buttons* buttonslist[2];
};