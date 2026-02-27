#pragma once
#include "Framework/GameObject.h"
class Lever :
    public GameObject
{
public:
    Lever();

    void update(float dt) override;

    void setUsed(bool value) { m_used = value; };
    bool isUsed() { return m_used; };
private:
    bool m_used;
    sf::IntRect m_leverRight = { {6 * 19, 3 * 19}, { 18,18 } };
    sf::IntRect m_leverLeft = { {4 * 19, 3 * 19}, { 18,18 } };
};

