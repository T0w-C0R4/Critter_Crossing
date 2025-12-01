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
    void clickCheck(sf::Vector2f click);
    void dragCharacter(sf::RenderWindow& window);

    sf::Sprite passport_photo;
    sf::Texture pass_texture;

    sf::Vector2f drag_position;
    sf::Vector2f drag_offset;

    bool drag = false;

    bool stamped = false;
    bool correct_stamp = false;

};