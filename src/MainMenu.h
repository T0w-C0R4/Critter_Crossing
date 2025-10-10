#pragma once
#include "Scene.h"
#include "Button.h"
class MainMenu :public Scene {
public:

	bool initScene(sf::RenderWindow& window);
	void update(float dt, sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	bool clearState();
	Buttons* buttonslist[2];
};