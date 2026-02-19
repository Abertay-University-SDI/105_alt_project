#include "LevelTwoWithTiles.h"

LevelTwoWithTiles::LevelTwoWithTiles(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio)
	: Scene(window, input, gameState, audio), m_alertText(m_font)
{
	GameObject tile;
	std::vector<GameObject> tileSet;

	int flag_index = 111;	// position in tiles png of the flag
	int num_columns = 20;
	int num_rows = 9;
	int tile_size = 18;      // Visual size of the tile
	int sheet_spacing = 1;   // Gap between tiles

	// Set GameObject size (Scaling up 4x for visibility)
	// 4 * 18 = 3 * 24 = 72 (dino size is 24).
	tile.setSize(sf::Vector2f(tile_size * 4, tile_size * 4));
	tile.setCollisionBox({ { 0,0 }, tile.getSize() });

	for (int i = 0; i < num_columns * num_rows; i++)
	{
		int row = i / num_columns;
		int col = i % num_columns;

		tile.setTextureRect({
			{(tile_size + sheet_spacing) * col, (tile_size + sheet_spacing) * row},
			{tile_size, tile_size} });
		if (col <= 4 || col >= 12) tile.setCollider(true);
		else tile.setCollider(false);
		tileSet.push_back(tile);
		if (i == flag_index)
		{
			m_flagDown = tile.getTextureRect();
		}
		if (i - 1 == flag_index)
		{
			m_flagUp = tile.getTextureRect();
		}
	}

	// Add Blank
	tile.setTextureRect({ {0, 0}, {-24, -24} }); // Empty rect for blank
	int b = tileSet.size();
	tile.setCollider(false);
	tileSet.push_back(tile);

	sf::Vector2u mapDimensions{ 40, 8 };
	std::vector<int> tileMap = {

		b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,
		b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,

		b,   131, b,   b,   b,   131, b,   b,   131, b,   21,  22,  23,  b,   b,   b,   21,  22,  22,  22,
		22,  23,  b,   b,   b,   21,  22,  22,  23,  b,   b,   b,   b,   b,   b,   b,   b,   b,   b,   b,

		b,   131, b,   b,   b,	 131, b,   21,  22,  22,  121, 122, 123, b,   b,   b,   121, 122, 122, 122,
		122, 123, b,   b,   b,   121, 122, 122, 123, 22,  22,  23,  b,   b,   b,   b,   b,   b,   66, b,

		b,   131, b,   b,   21,  22,  22,  121, 122, 122, 121, 122, 123, b,   b,   b,   121, 122, 122, 122,
		122, 123, b,   b,   b,   121, 122, 122, 123, 122, 122, 123, 22,  22,  22,  22,  22,  22,  22,  23,

		21,  22,  22,  22,  121, 122, 122, 121, 122, 122, 121, 122, 123, b,   b,   b,   121, 122, 122, 122,
		122, 123, b,   b,   b,   121, 122, 122, 123, 122, 122, 123, 122, 122, 122, 122, 122, 122, 122, 123,

		121, 122, 122, 122, 121, 122, 122, 121, 122, 122, 121, 122, 123, b,   b,   b,   121, 122, 122, 122,
		122, 123, b,   b,   b,   121, 122, 122, 123, 122, 122, 123, 122, 122, 122, 122, 122, 122, 122, 123,

		121, 122, 122, 122, 121, 122, 122, 121, 122, 122, 121, 122, 123, b,   b,   b,   121, 122, 122, 122,
		122, 123, b,   b,   b,   121, 122, 122, 123, 122, 122, 123, 122, 122, 122, 122, 122, 122, 122, 123,

		141, 142, 142, 142, 141, 142, 142, 141, 142, 142, 141, 142, 143, b,   b,   b,   141, 142, 142, 142,
		142, 143, b,   b,   b,   141, 142, 142, 143, 142, 142, 143, 142, 142, 142, 142, 142, 142, 142, 143
	};
	for (int i = 0; i < tileMap.size(); i++)
	{
		if (tileMap[i] == flag_index) m_flagIndices.push_back(i);

	}

	m_tilemap.loadTexture("gfx/tilemap.png");
	m_tilemap.setTileSet(tileSet);
	m_tilemap.setTileMap(tileMap, mapDimensions);
	m_tilemap.setPosition({ 0, 100 });
	m_tilemap.buildLevel();

	tileSet.clear();

	// setup background
	tile_size = 24;
	num_columns = 8;
	num_rows = 3;
	// 24 * 9 = 216, a multiple of 72, the LCM of the player and tile size.
	tile.setSize(sf::Vector2f(tile_size * 9, tile_size * 9));

	for (int i = 0; i < num_columns * num_rows; i++)
	{
		int row = i / num_columns;
		int col = i % num_columns;

		tile.setTextureRect({
			{(tile_size + sheet_spacing) * col, (tile_size + sheet_spacing) * row},
			{tile_size, tile_size} });
		tile.setCollider(false);		// don't collide with background
		tileSet.push_back(tile);
	}

	mapDimensions = { 14,3 };
	tileMap = {
		6,6,6,6,6,6,6,6,6,6,6,6,6,6,
		14,14,14,14,14,14,14,14,14,14,14,14,14,14,
		22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22
	};

	m_bgtilemap.loadTexture("gfx/tilemap-backgrounds.png");
	m_bgtilemap.setTileSet(tileSet);
	m_bgtilemap.setTileMap(tileMap, mapDimensions);
	m_bgtilemap.setPosition({ 0, 0 });
	m_bgtilemap.buildLevel();

	// setup player 
	m_player.setInput(&m_input);
	m_player.setEdges(0, WORLD_SIZE.x);

	if (!m_font.openFromFile("font/bitcount.ttf")) std::cerr << "no font found";
	
}

void LevelTwoWithTiles::onBegin()
{

}

void LevelTwoWithTiles::onEnd()
{

}

void LevelTwoWithTiles::handleInput(float dt)
{

}

void LevelTwoWithTiles::update(float dt)
{

}

void LevelTwoWithTiles::render()
{
	beginDraw();
	m_tilemap.render(m_window);
	endDraw();
}