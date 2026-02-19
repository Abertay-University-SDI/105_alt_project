#include "Worm.h"

Worm::Worm()
{
	for (int i = 0; i < 6; i++) m_crawl.addFrame({ {64 * i, 0}, {64, 64} });
	m_crawl.setFrameSpeed(1 / 6.f);
	m_currentAnimation = &m_crawl;
	m_crawlSpeed = 100.0f;
}

void Worm::handleInput(float dt)
{
	if (!isAlive())
	{
		if (m_input->isKeyDown(sf::Keyboard::Scancode::Space))
		{
			setAlive(true);
		}
	}
}

void Worm::update(float dt)
{
	if (!isAlive())
		setPosition({ 0, 400 });
	else
	{
		m_currentAnimation->animate(dt);
		setTextureRect(m_currentAnimation->getCurrentFrame());
		move(sf::Vector2f({ m_crawlSpeed, 0 }) * dt);
		// unalive if it makes it to the end of the screen.
		if (getPosition().x + getSize().x > 900)
		{
			setAlive(false);
		}
	}
}

void Worm::collisionResponse(GameObject& collider)
{
	// worm got eaten
	setAlive(false);
}