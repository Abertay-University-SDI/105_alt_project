#pragma once

#include "Framework/BaseLevel.h"
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
#include "Bird.h"
#include "Worm.h"
#include <fstream>


struct HypeText
{
	sf::Text text;
	float lifeTime = 0.f;

	HypeText(const sf::Font& font) : text(font)
	{
	}
};

class Level : BaseLevel {
public:
	Level(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.

	GameObject m_floor;
	
	sf::Texture m_wormTexture;
	Worm m_worm;
	sf::Font m_font;
	sf::Text m_text;
	Bird m_bird;
	sf::Texture m_birdTexture;

	float m_spawnTimer = 0.f;
	std::vector<HypeText> m_messages;

	const std::vector<std::string> m_phrases = {
		"WORM!", "Gimme", "Breakfast!",
		"snack", "Get it.", "Come here!",
		"Protein", "worm for me", "my favourite"
	};

};