#pragma once
#include "Scene.h"
#include "Framework/Collision.h"
#include "Framework/TileMap.h"
#include "Player.h"
#include <algorithm> // for clamp


class LevelTwoWithTiles :
    public Scene
{
public:
    LevelTwoWithTiles(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio);

    void handleInput(float dt) override;
    void update(float dt) override;
    void render() override;
    void onBegin() override;
    void onEnd() override;

private:
    void updateCameraAndBackground();

    TileMap m_tilemap;
    TileMap m_bgtilemap;
    Player m_player;

    // flag that flaps
    bool m_flagLeverPulled = false;
    bool m_isFlagUp = false;            // state flag 
    sf::IntRect m_flagUp;               // frames for eeach
    sf::IntRect m_flagDown;
    std::vector<int> m_flagIndices;     // index of flags in the level
    float m_flagTimer;                  // animation timer
    float m_promptTimer;

    const float PROMPT_TIME = 2.f;
    const float FLAG_TIME = 0.5f;
    const sf::Vector2i WORLD_SIZE = { 2880, 648 };
    const sf::Vector2i VIEW_SIZE = { 432, 432 };

    sf::Text m_alertText;
    sf::Font m_font;

};

