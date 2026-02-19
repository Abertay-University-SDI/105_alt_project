#pragma once
#include "Framework/BaseLevel.h"
#include "Framework/GameObject.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

class LevelThatSaves :
    public BaseLevel
{
public:
    LevelThatSaves(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio);
    ~LevelThatSaves();

    void handleInput(float dt) override;
    void update(float dt) override;
    void render() override;

private:
    void saveGame();
    void loadGame();

    GameObject m_spinnyBox;
    GameObject m_growyBox;
    bool m_boxGrowing = true;
    sf::Font m_font;
    sf::Text m_clickTracker;
    float m_clickTime = 0.f;
    std::string m_savePath = "data/save.txt";

    const int MIN_BOX_WIDTH = 100;
    const int MAX_BOX_WIDTH = 400;
};

