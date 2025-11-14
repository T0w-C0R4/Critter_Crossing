#pragma once
#include "ObjectClass.h"
class Passport : public ObjectClass 
{
public:
    void init(sf::RenderWindow& window);
    void update(float dt, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void handleEvent();
    void getPassPhotoNSet(int rand);
    sf::Sprite passport_photo;
    sf::Texture pass_texture;
};