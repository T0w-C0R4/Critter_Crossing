#include "ObjectClass.h"

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
        sprite->getGlobalBounds().intersects(other_object->sprite->getGlobalBounds()));

    {
        return true;
    }
    return false;
}


sf::Sprite* ObjectClass::getSprite()
{
    return sprite;
}
