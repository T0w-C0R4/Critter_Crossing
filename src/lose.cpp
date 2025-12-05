#include "lose.h"

bool Lose::initScene(sf::RenderWindow& window)
{
	if (!initString(window))
	{
		std::cout << "string failed to initialise" << std::endl;
	}
	return true;
}
void Lose::update(float dt, sf::RenderWindow& window)
{

}
void Lose::render(sf::RenderWindow& window)
{
	window.draw(score_text);
}
bool Lose::clearState()
{
	return true;
}

bool Lose::initString(sf::RenderWindow& window)
{
	//load font & set
	if (!score_font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font didnt load" << std::endl;
		return true;
	}
	score_text.setFont(score_font);
	//set String
	score_text.setString("your final score: " + std::to_string(score));

	//set colour
	score_text.setColor(sf::Color::White);

	//set scale
	score_text.setCharacterSize(60);

	//set position
	score_text.setPosition((window.getSize().x/2)- score_text.getGlobalBounds().width/2, window.getSize().y / 4);

	//check if string is valid
	if (score_text.getString().getSize() == 0)
	{
		return false;
	}

}
