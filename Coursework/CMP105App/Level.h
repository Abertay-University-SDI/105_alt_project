#pragma once

#include "Framework/BaseLevel.h"

class Level : BaseLevel {
public:
	Level(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.

	// Default variables for level class.
	
};