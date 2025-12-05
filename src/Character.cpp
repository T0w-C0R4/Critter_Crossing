#include "Character.h"

void Character::init(sf::RenderWindow& window)
{
	rand_player_sprite = rand() % 3;
	rand_pass_sprite = rand() % 3;
	passport = new Passport();
	if (rand_pass_sprite == rand_player_sprite)
	{
		valid = true;
	}
	else { valid = false; }

	switch (rand_player_sprite)
	{
	case 0:
		initialiseSprite("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/penguin.png");
		break;
	case 1:
		initialiseSprite("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/giraffe.png");
		break;
	case 2:
		initialiseSprite("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/gorilla.png");
		break;
	}
	sprite->setScale(1.8, 1.8);
	sprite->setPosition(window.getSize().x / 12.f, window.getSize().y / 12.f);
	//initialise passport
	passport->init(window);
	passport->getPassPhotoNSet(rand_pass_sprite);

}
void Character::update(float dt, sf::RenderWindow& window)
{

	//player location
	//passport location
	passport->update(dt, window);

}
void Character::render(sf::RenderWindow& window) {
	if (visible)
	{
		//render player first
		window.draw(*sprite);
		passport->render(window);
		//when player is in frame propperly render the passport
	}

}
void Character::handleEvent()
{
	//move character in either direction based on accepted or rejected
	passport->drag = false;
}
Passport* Character::getPassport()
{
	return passport;
}


