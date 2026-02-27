#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Flag :
    public GameObject
{
public:
    Flag();

    void update(float dt) override;
    void setup();
private:

    Animation* m_currentAnimation;
    Animation m_flap;

};

