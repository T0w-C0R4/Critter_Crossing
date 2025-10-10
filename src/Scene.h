#pragma once
#include "ObjectClass.h"
class Scene2 {

public:
	Scene2();
	~Scene2();

	const int scene;

	int number_of_objects = 0;


	virtual bool initScene() = 0;

	

	private:
};