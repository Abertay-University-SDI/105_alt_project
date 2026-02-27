#include "Coin.h"

Coin::Coin()
{
	m_spin.addFrame({ {11 * 19, 7 * 19}, {18,18} });
	m_spin.addFrame({ {12 * 19, 7 * 19}, {18,18} });
	m_spin.setFrameSpeed(0.2f);
	m_currentAnimation = &m_spin;
}

void Coin::update(float dt) 
{
	m_currentAnimation->animate(dt);
	setTextureRect(m_currentAnimation->getCurrentFrame());
}