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
    else if (type == restart) {
        initialiseSprite("../Data/images/RestartButton.png");
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

bool Buttons::hasClicked(sf::Vector2f click)
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