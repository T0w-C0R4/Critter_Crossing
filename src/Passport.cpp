#include "Passport.h"

void Passport::init(sf::RenderWindow& window) {
	initialiseSprite("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/default passport.png");
	sprite->setPosition(100,200);
	
}

void Passport::update(float dt, sf::RenderWindow& window) {
	passport_photo.setPosition(sprite->getGlobalBounds().getPosition().x,sprite->getGlobalBounds().getPosition().y );
}

void Passport::render(sf::RenderWindow& window){

	window.draw(*sprite);
	window.draw(passport_photo);
}

void Passport::handleEvent(){

}

void Passport::getPassPhotoNSet(int rand)
{

		switch (rand)
		{
		case 1:
			if (pass_texture.loadFromFile("..Data/Images/Critter Crossing Customs/Critter Crossing Customs/giraffe.png"))
			{
				std::cout << " pass photo didnt load?!?!?!?\n";

			}
			break;
		case 2:
			if (pass_texture.loadFromFile("..Data/Images/Critter Crossing Customs/Critter Crossing Customs/gorilla.png"))
			{
				std::cout << " pass photo didnt load?!?!?!?\n";

			}
			break;
		case 3:
			if (pass_texture.loadFromFile("..Data/Images/Critter Crossing Customs/Critter Crossing Customs/moose.png"))
			{
				std::cout<<" pass photo didnt load?!?!?!?\n";
				
			}
			
			break;
		
		}
		passport_photo.setTexture(pass_texture);
		passport_photo.setScale(0.1,0.1);
		


}


