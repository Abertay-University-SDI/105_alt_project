#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in, GameState& gs, AudioManager& aud) :
	BaseLevel(hwnd, in, gs, aud)
{
	// initialise game objects

}

// handle user input
void Level::handleInput(float dt)
{
	if (m_input.isLeftMousePressed())
	{
		std::cout << "left mouse pressed" << std::endl;
	}
}

// Update game objects
void Level::update(float dt)
{
}

// Render level
void Level::render()
{
	beginDraw();

	endDraw();
}

