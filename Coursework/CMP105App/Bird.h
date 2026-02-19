#pragma once
#include "Framework/GameObject.h"

class Bird : public GameObject
{

public:
	Bird();
	void update(float dt) override;
	void collisionResponse(GameObject& collider) override;
	void setWormPointer(GameObject* worm_pointer) { m_wormPointer = worm_pointer; };
	void clearWormPointer() { m_wormPointer = nullptr; };

private:

	std::vector<sf::Vector2f> m_birdPoints;
	const float ACCELERATION = 350.f;
	const float CLOSE_ENOUGH = 10.0f;
	int m_pointIndex = 0;
	GameObject* m_wormPointer;
};

