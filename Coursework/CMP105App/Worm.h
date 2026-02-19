#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Worm :
    public GameObject
{
public:
    Worm();
    void handleInput(float dt) override;
    void update(float dt) override;
    void collisionResponse(GameObject& collider) override;

private:
    Animation* m_currentAnimation;
    Animation m_crawl;

    float m_crawlSpeed;
};

