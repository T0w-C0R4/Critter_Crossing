#pragma once
#include "ObjectClass.h"
class Passport : public ObjectClass 
{
public:
    void init(sf::RenderWindow& window);
    void update(float dt, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void handleEvent();
private:

};