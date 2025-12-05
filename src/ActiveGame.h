#pragma once
#include "Scene.h"
#include "Character.h"
#include "life.h"
#include "ObjectClass.h"
#include "Stamp.h"


class ActiveGame :public Scene
{
public:
	bool initScene(sf::RenderWindow& window);
	void update(float dt, sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	bool clearState();

	int next_life = 0;
	int next_stamp = 0;
	int score = 0;
	bool click;


protected:

	std::shared_ptr<Character> character;
	std::shared_ptr<Passport> char_passport;
	ObjectClass* Life_counter[3];
	Stamp* stamp[2];

};
