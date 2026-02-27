#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Coin :
    public GameObject
{
public:
    Coin();

    void update(float dt) override;

private:

    Animation* m_currentAnimation;
    Animation m_spin;

};

