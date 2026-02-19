#include "Level.h"
#include <cmath>
#include <sstream>
#include <iomanip>

Level::Level(sf::RenderWindow& hwnd, Input& in, GameState& gs, AudioManager& aud) :
	BaseLevel(hwnd, in, gs, aud), m_text(m_font)
{
	m_floor.setSize({ static_cast<float>(hwnd.getSize().x), 200.f });
	m_floor.setPosition({ 0.f, 400 });
	m_floor.setFillColor(sf::Color::Black);
	m_floor.setCollisionBox({ {0,0}, m_floor.getSize() });

	if (!m_font.openFromFile("font/arial.ttf")) std::cerr << "missed font\n";

	if (!m_birdTexture.loadFromFile("gfx/bird.png")) std::cerr << "no bird";
	m_bird.setTexture(&m_birdTexture);
	m_bird.setSize({ 100,100 });
	m_bird.setCollisionBox({ {13,7},{74,58} });

	if (!m_wormTexture.loadFromFile("gfx/worm_sheet.png")) std::cerr << "no worm";
	m_worm.setTexture(&m_wormTexture);
	m_worm.setInput(&m_input);
	m_worm.setSize({ 32, 32 });
	m_text.setString({ "click on the bird to win" });
	m_text.setPosition({ 50,250 });
	m_text.setCharacterSize(24);

}


// handle user input
void Level::handleInput(float dt)
{
	m_worm.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	m_bird.update(dt);
	m_worm.update(dt);
	if (m_worm.isAlive())
	{
		m_bird.setWormPointer(&m_worm);

		m_spawnTimer += dt;
		if (m_spawnTimer > 0.2f) // Spawn every 0.2 seconds
		{
			m_spawnTimer = 0.f;

			HypeText newMessage(m_font);
			newMessage.text.setFont(m_font); // Use existing font

			// random phrase, random position in top 150px of screen, random tilt
			int phraseIndex = rand() % m_phrases.size();
			newMessage.text.setString(m_phrases[phraseIndex]);
			float randX = static_cast<float>(rand() % m_window.getSize().x);
			float randY = static_cast<float>(rand() % 150);
			newMessage.text.setPosition({ randX, randY });
			float randRot = static_cast<float>((rand() % 60) - 30);
			newMessage.text.setRotation(sf::degrees(randRot));
			newMessage.text.setCharacterSize(32);
			newMessage.text.setFillColor(sf::Color::Yellow);
			newMessage.text.setOutlineColor(sf::Color::Black);
			newMessage.text.setOutlineThickness(1.f);

			m_messages.push_back(newMessage);
		}
	}
	else
	{
		m_bird.clearWormPointer();

		m_messages.clear();
	}

	for (int i = m_messages.size() - 1; i >= 0; i--)
	{
		m_messages[i].lifeTime += dt;

		m_messages[i].text.move({ 0.f, -50.f * dt });

		if (m_messages[i].lifeTime > 1.0f)
		{
			m_messages.erase(m_messages.begin() + i);
		}
	}

	if (Collision::checkBoundingCircle(m_bird, m_worm))
	{
		m_bird.collisionResponse(m_worm);
		m_worm.collisionResponse(m_bird);
	}

	sf::Vector2i mousePos{ m_input.getMouseX(), m_input.getMouseY() };
	if (m_input.isLeftMousePressed() &&
		Collision::checkBoundingBox(m_bird, mousePos))
	{
		m_gameState.setCurrentState(State::MENU);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_floor);
	if(m_worm.isAlive()) m_window.draw(m_worm);
	m_window.draw(m_bird);
	for (const auto& msg : m_messages)
	{
		m_window.draw(msg.text);
	}	
	m_window.draw(m_text);
	m_hud.render(m_window);
	endDraw();
}

