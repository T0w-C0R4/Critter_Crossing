#include "Passport.h"

void Passport::init(sf::RenderWindow& window) {
	initialiseSprite("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/default passport.png");
	sprite->setPosition(350, 500);
	
}

void Passport::update(float dt, sf::RenderWindow& window) {
	passport_photo.setPosition(sprite->getGlobalBounds().getPosition().x + 50,sprite->getGlobalBounds().getPosition().y + 450);

	if (drag) {
		dragCharacter(window);
	}
}

void Passport::render(sf::RenderWindow& window){

	window.draw(*sprite);
	window.draw(passport_photo);
}

void Passport::handleEvent()
{
	
}

void Passport::getPassPhotoNSet(int rand)
{


		switch (rand)
		{
		case 0:
			if (!pass_texture.loadFromFile("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/penguin.png"))
			{
				std::cout << " pass photo didnt load?!?!?!?\n";

			}
			break;
		case 1:
			if (!pass_texture.loadFromFile("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/giraffe.png"))
			{
				std::cout << " pass photo didnt load?!?!?!?\n";

			}
			break;
		case 2:
			if (!pass_texture.loadFromFile("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/gorilla.png"))
			{
				std::cout << " pass photo didnt load?!?!?!?\n";

			}
			break;
		
		}
 		passport_photo.setTexture(pass_texture);
		passport_photo.setScale(0.75,0.75);
		passport_photo.setPosition(sprite->getGlobalBounds().getPosition().x+50.f,sprite->getGlobalBounds().getPosition().y+450.f);
		


}

void Passport::clickCheck(sf::Vector2f click)
{
	if (click.x < sprite->getGlobalBounds().getPosition().x +
		sprite->getGlobalBounds().width &&
		click.x > sprite->getGlobalBounds().getPosition().x &&
		click.y < sprite->getGlobalBounds().getPosition().y +
		sprite->getGlobalBounds().height &&
		click.y > sprite->getGlobalBounds().getPosition().y) 
	{
		drag = true;
		//set drag position
		drag_position = click;
		std::cout << "clicked" << std::endl;

		//make offset
		drag_offset.x = click.x - sprite->getGlobalBounds().getPosition().x;
		drag_offset.y = click.y - sprite->getGlobalBounds().getPosition().y;
	}
	else
	{
		drag = false;
	}
	
}

void Passport::dragCharacter(sf::RenderWindow& window)
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	drag_position = static_cast<sf::Vector2f>(mouse_position);
	sprite->setPosition(drag_position - drag_offset);
}


