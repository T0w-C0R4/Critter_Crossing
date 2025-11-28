#pragma once
#include "ObjectClass.h"
class Stamp : ObjectClass 
{
public:

    void init(sf::RenderWindow& window);
    void update(float dt, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void handleEvent();






};