#include "Collision.h"

// Check AABB for collision. Returns true if collision occurs.
bool Collision::checkBoundingBox(GameObject* s1, GameObject* s2)
{
	if (s1->getCollisionBox().position.x + s1->getCollisionBox().size.x < s2->getCollisionBox().position.x)
		return false;
	if (s1->getCollisionBox().position.x > s2->getCollisionBox().position.x + s2->getCollisionBox().size.x)
		return false;
	if (s1->getCollisionBox().position.y + s1->getCollisionBox().size.y < s2->getCollisionBox().position.y)
		return false;
	if (s1->getCollisionBox().position.y > s2->getCollisionBox().position.y + s2->getCollisionBox().size.y)
		return false;

	return true;
}

// Check for bounding box collision with a point/vector2 rather than two boxes.
bool Collision::checkBoundingBox(GameObject* s1, sf::Vector2i s2)
{
	if (s1->getCollisionBox().position.x + s1->getCollisionBox().size.x < s2.x)
		return false;
	if (s1->getCollisionBox().position.x > s2.x)
		return false;
	if (s1->getCollisionBox().position.y + s1->getCollisionBox().size.y < s2.y)
		return false;
	if (s1->getCollisionBox().position.y > s2.y)
		return false;

	return true;
}

// Check bounding circle collision. Returns true if collision occurs.
bool Collision::checkBoundingCircle(GameObject* s1, GameObject* s2)
{
	// Get radius and centre of sprites.
	float radius1 = s1->getSize().x / 2;
	float radius2 = s2->getSize().x / 2;
	float xpos1 = s1->getPosition().x + radius1;
	float xpos2 = s2->getPosition().x + radius2;
	float ypos1 = s1->getPosition().y + radius1;
	float ypos2 = s2->getPosition().y + radius2;

	if (pow(xpos2 - xpos1, 2) + pow(ypos2 - ypos1, 2) < pow(radius1 + radius2, 2))
	{
		return true;
	}
	return false;
}

