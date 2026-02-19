#pragma once
#include "Framework/BaseLevel.h"
class Scene :
    public BaseLevel
{
public:
    Scene(sf::RenderWindow& hwnd, Input& in, GameState& gs, AudioManager& aud);
    virtual void onBegin() = 0;
    virtual void onEnd() = 0;
};

