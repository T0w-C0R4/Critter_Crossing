#pragma once
#include "ObjectClass.h"

class life : public ObjectClass
{
    void init(sf::RenderWindow& window);
    void update(float dt, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void handleEvent();


};