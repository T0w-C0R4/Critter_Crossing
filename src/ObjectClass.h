#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class ObjectClass
{
public:
    ObjectClass();
    ~ObjectClass();

    virtual void init(sf::RenderWindow& window) = 0;
    virtual void update(float dt, sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleEvent() = 0;

    bool initialiseSprite(std::string filename);
    bool colisionChecker(ObjectClass* other_object);

    sf::Sprite* getSprite();

    Vector2* vector = new Vector2(0, 0);

    bool visible;
    float speed;


    enum Type
    {
        button,
        item,
        character,
        background
    };

    Type type;

protected:
    sf::Sprite* sprite = nullptr;
    sf::Texture* texture = nullptr;
};