#include "Bird.h"

Bird::Bird()
{
	m_birdPoints = {
		{200,100}, {250,50}, {300,100}, {350,150},
		{400,100}, {350,50}, {300,100}, {250,150}
	};
}

void Bird::update(float dt)
{
	sf::Vector2f to_target;
	if (m_wormPointer)		// is the pointer NOT a nullptr?
	{
		// THERE'S A TASTY WORM, GET IT, 
		sf::Vector2f worm_loc = m_wormPointer->getPosition() + (m_wormPointer->getSize() * 0.5f);
		to_target = worm_loc - getPosition();
	}
	else
	{
		// No worm, guess I'll just fly about
		to_target = m_birdPoints[m_pointIndex] - getPosition();

		// have I reached my next point yet?
		if (to_target.length() < CLOSE_ENOUGH)
		{
			m_pointIndex += 1;
			if (m_pointIndex >= m_birdPoints.size())
				m_pointIndex = 0;
		}
	}
	
	m_velocity += to_target.normalized() * dt * ACCELERATION;
	m_velocity *= 0.95f;	// damp
	move(m_velocity * dt);

}

void Bird::collisionResponse(GameObject& collider)
{
	// worm eaten
	clearWormPointer();
	// yummy worm!
	setSize(getSize() * 1.1f);	
}
