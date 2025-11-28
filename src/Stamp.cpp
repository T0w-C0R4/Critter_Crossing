#include "Stamp.h"

void Stamp::init(sf::RenderWindow& window)
{
	if (accept)
	{
		initialiseSprite("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/accept button.png");

		if (!stamp_inc_texture.loadFromFile("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/accept.png"))
		{
			std::cout<< "inc no load accept" << std::endl;
		}
		stamp_inc.setTexture(stamp_inc_texture);
		sprite->setPosition(1500 , 250);
	
	}
	if (reject)
	{
		initialiseSprite("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/reject button.png");

		if (!stamp_inc_texture.loadFromFile("../Data/Images/Critter Crossing Customs/Critter Crossing Customs/reject.png"))
		{
			std::cout << "inc no load reject" << std::endl;
		}
		stamp_inc.setTexture(stamp_inc_texture);
		sprite->setPosition(1500, 350);

	}
	sprite->setScale(1.5, 1.5);
}
	

void Stamp::update(float dt, sf::RenderWindow& window)
{
	if (clicked) 
	{
		stamp_inc.setPosition(pass_pos_ref);
	}
	else
	{
		stamp_inc.setPosition(sprite->getGlobalBounds().getPosition().x, sprite->getGlobalBounds().getPosition().y);
	}
}

void Stamp::render(sf::RenderWindow& window)
{
	window.draw(stamp_inc);
	window.draw(*sprite);
	
}

void Stamp::handleEvent()
{

}

void Stamp::setPassRef(sf::Vector2f pos)
{
	drag_offset.x = pos.x - stamp_inc.getGlobalBounds().getPosition().x;
	drag_offset.y = pos.y - stamp_inc.getGlobalBounds().getPosition().y;

	pass_pos_ref = pos - drag_offset;
}

void Stamp::deleteStamp()
{
	if (clicked) 
	{
		clicked = false;
		pass_pos_ref.x = 0;
		pass_pos_ref.y = 0;
		stamp_inc.setPosition(sprite->getGlobalBounds().getPosition().x, sprite->getGlobalBounds().getPosition().y);
	}
	

}
