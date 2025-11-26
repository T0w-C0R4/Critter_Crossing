#pragma once
#include "ObjectClass.h"
#include <vector>
class Scene {

public:
	Scene();
	~Scene();

	int scene;

	int number_of_objects = 0;
	int next_scene = 0;

	bool changeScene = false;



	virtual bool initScene(sf::RenderWindow& window) = 0;
	virtual void update(float dt, sf::RenderWindow& window) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual bool clearState() = 0;

	sf::Vector2f MouseInput;

		//stores a unique pointer to the objects within the vector
	std::vector<std::shared_ptr<ObjectClass>> state_obj;
};