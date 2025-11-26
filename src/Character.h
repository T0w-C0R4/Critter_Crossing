#pragma once
#include "ObjectClass.h"
#include "Passport.h"
class Character :public ObjectClass
{
public:
    void init(sf::RenderWindow& window);
    void update(float dt, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void handleEvent();
    Passport* getPassport();

    bool valid;
    
    Passport* passport = nullptr;

private:

    int rand_player_sprite;
    int rand_pass_sprite;

    
};