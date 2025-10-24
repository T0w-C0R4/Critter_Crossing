#include "Character.h"

void Character::init(sf::RenderWindow& window) 
{
	rand_player_sprite = rand() % 3;
	rand_pass_sprite = rand() % 3;

	if (rand_pass_sprite == rand_player_sprite) 
	{
		valid = true;
	}
	else {valid = false;}

	switch (rand_player_sprite)
	{
	case 1:
		initialiseSprite("..Data/Images/Critter Crossing Customs/Critter Crossing Customs/giraffe.png");
		break;
	case 2:
		initialiseSprite("..Data/Images/Critter Crossing Customs/Critter Crossing Customs/gorilla.png");
		break;
	case 3:
		initialiseSprite("..Data/Images/Critter Crossing Customs/Critter Crossing Customs/moose.png");
		break;
	}
	sprite->setScale(1.8,1.8);
	sprite->setPosition(window.getSize().x / 12, window.getSize().y / 12);
	//initialise passport
}
void Character::update(float dt, sf::RenderWindow& window) 
{
	//player location
	//passport location

}
void Character::render(sf::RenderWindow& window) {
	//render player first
	window.draw(*sprite);
	//when player is in frame propperly render the passport
}
void Character::handleEvent() 
{
	//move character in either direction based on accepted or rejected
}