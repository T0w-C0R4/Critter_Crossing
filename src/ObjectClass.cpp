#include "ObjectClass.h"

ObjectClass::ObjectClass()
{
}

ObjectClass::~ObjectClass()
{
	delete vector;
}


bool ObjectClass::initialiseSprite(std::string filename)
{
	sprite = new sf::Sprite;
	texture = new sf::Texture;

	// load from file texture ectt.
	if (!texture->loadFromFile(filename))
	{
		std::cout << filename << " didnt load?!?!?!?\n";
		return false;
	}

	sprite->setTexture(*texture);

	return true;
}

bool ObjectClass::colisionChecker(ObjectClass* other_object)
{
    if ( // sprite collisions
        other_object != nullptr &&
        sprite->getGlobalBounds().getPosition().x <
        (other_object->getSprite()->getGlobalBounds().getPosition().x +
            other_object->getSprite()->getGlobalBounds().width) &&

        (sprite->getGlobalBounds().getPosition().x +
            sprite->getGlobalBounds().width) >
        other_object->getSprite()->getGlobalBounds().getPosition().x &&

        sprite->getGlobalBounds().getPosition().y <
        (other_object->getSprite()->getGlobalBounds().getPosition().y +
            other_object->getSprite()->getGlobalBounds().height) &&

        (sprite->getGlobalBounds().getPosition().y +
            sprite->getGlobalBounds().height) >
        other_object->getSprite()->getGlobalBounds().getPosition().y)

    {
        return true;
    }
    return false;
}


sf::Sprite* ObjectClass::getSprite()
{
    return sprite;
}
