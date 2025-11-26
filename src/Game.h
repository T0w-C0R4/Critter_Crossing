#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "ObjectClass.h"
#include "SceneHandler2.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void mouseReleased(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  SceneHandler2* SFM = new SceneHandler2;

};

#endif
