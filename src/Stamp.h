#pragma once
#include "ObjectClass.h"
#include <SFML/System/Vector2.hpp>

class Stamp : public ObjectClass 
{
public:

    void init(sf::RenderWindow& window);
    void update(float dt, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void handleEvent();

    void setPassRef(sf::Vector2f pos);
    void deleteStamp();

    bool hasClicked(sf::Vector2f pos);

    int returnType();

    bool clicked = false;

    sf::Vector2f pass_pos_ref;
    sf::Vector2f drag_offset;

protected:
   
    sf::Sprite* stamp_inc = nullptr;
    sf::Texture* stamp_inc_texture = nullptr;
};