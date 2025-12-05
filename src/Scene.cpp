#include "Scene.h"

Scene::Scene()
{
	
}

Scene::~Scene()
{

}

bool Scene::initString(sf::RenderWindow& window, std::string string_text, float div_x, float div_y)
{
	if (scene_text != nullptr) 
	{
		delete scene_text;
		delete scene_text_font;
	}
	scene_text = new sf::Text;
	scene_text_font = new sf::Font;
	//load font & set
	if (!scene_text_font->loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font didnt load" << std::endl;
		return true;
	}
	scene_text->setFont(*scene_text_font);
	//set String
	scene_text->setString(string_text);

	//set colour
	scene_text->setColor(sf::Color::White);

	//set scale
	scene_text->setCharacterSize(60);

	//set position
	scene_text->setPosition((window.getSize().x / div_x) - scene_text->getGlobalBounds().width / 2, window.getSize().y / div_y);

	//check if string is valid
	if (scene_text->getString().getSize() == 0)
	{
		std::cout << "string: " << string_text << "didnt load" << std::endl;
		return false;
	}
	return false;
}

bool Scene::setBackground(sf::RenderWindow& window, std::string file_path)
{
	if (background != nullptr) 
	{
		delete background;
		delete background_texture;
	}
	background = new sf::Sprite;
	background_texture = new sf::Texture;

	background_texture->loadFromFile("../Data/Images/" +file_path);

	//background->setTexture(background_texture);




	return false;
}



