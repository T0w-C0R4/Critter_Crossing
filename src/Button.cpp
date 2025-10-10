#include "Button.h"
void Buttons::init(sf::RenderWindow& window)
{
    if (type == quit)
    {
        initialiseSprite("../Data/Images/QuitButton.png");
    }
    else if (type == start)
    {
        initialiseSprite("../Data/Images/StartButton.png");
    }
}

void Buttons::update(float dt, sf::RenderWindow& window)
{
    if (type == quit)
    {
        if (
            (sprite->getGlobalBounds().getPosition().x) +
            (sprite->getGlobalBounds().getSize().x / 2) !=
            (window.getSize().x / 2) &&
            sprite->getGlobalBounds().getPosition().y !=
            (window.getSize().y / 2) + sprite->getScale().y + 10)
        {
            sprite->setPosition(
                window.getSize().x / 2 - (sprite->getGlobalBounds().getSize().x / 2),
                (window.getSize().y / 2) + sprite->getGlobalBounds().height + 10);
        }
    }
    else if (type == play)
    {
        texture->loadFromFile("../Data/Images/PlayButton.png");
        sprite->setTexture(*texture);
    }
    else if (type == restart)
    {
        texture->loadFromFile("../Data/Images/RestartButton.png");
        sprite->setTexture(*texture);
    }
    else
    {
        if (
            sprite->getGlobalBounds().getPosition().x !=
            window.getSize().x / 2 - (sprite->getGlobalBounds().getSize().x / 2) &&
            sprite->getGlobalBounds().getPosition().y != (window.getSize().y / 2))
        {
            sprite->setPosition(
                window.getSize().x / 2 - (sprite->getGlobalBounds().getSize().x / 2),
                (window.getSize().y / 2));
        }
    }
}

void Buttons::render(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

void Buttons::handleEvent() {}

bool Buttons::hasClicked(sf::Vector2i click)
{
    if (
        click.x < sprite->getGlobalBounds().getPosition().x +
        sprite->getGlobalBounds().width &&
        click.x > sprite->getGlobalBounds().getPosition().x &&
        click.y < sprite->getGlobalBounds().getPosition().y +
        sprite->getGlobalBounds().height &&
        click.y > sprite->getGlobalBounds().getPosition().y)
    {
        return true;
    }
    return false;
}