#include "SceneHandler2.h"

SceneHandler2::SceneHandler2()
{
}

SceneHandler2::~SceneHandler2()
{
}

void SceneHandler2::init()
{
}

void SceneHandler2::update(float dt, sf::RenderWindow& window)
{
}

void SceneHandler2::ChangeScene(int next_scene)
{
	currentscene = static_cast<CurrentScene>(next_scene);
}

void SceneHandler2::render(sf::RenderWindow& window)
{
}
