#include "Flag.h"

Flag::Flag()
{
	m_flap.addFrame({ {11 * 19, 5 * 19}, {18,18} });
	m_flap.addFrame({ {12 * 19, 5 * 19}, {18,18} });
	m_flap.setFrameSpeed(0.4f);
	m_currentAnimation = &m_flap;
}

void Flag::update(float dt)
{
	m_currentAnimation->animate(dt);
	setTextureRect(m_currentAnimation->getCurrentFrame());
}

void Flag::setup()
{
	setTextureRect(m_currentAnimation->getCurrentFrame());
}