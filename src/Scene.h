#pragma once
#include "ObjectClass.h"
#include <vector>
#include "Character.h"
#include <string>

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
	
	bool initString(sf::RenderWindow& window,std::string string_text, float div_x, float div_y);
	bool setBackground(sf::RenderWindow& window, std::string file_path);

	sf::Vector2f MouseInput;

		//stores a unique pointer to the objects within the vector
	std::vector<std::shared_ptr<Character>> state_obj;

protected:

	sf::Text* scene_text = nullptr;
	sf::Font* scene_text_font = nullptr;

	sf::Sprite* background = nullptr;
	sf::Texture* background_texture = nullptr;
};