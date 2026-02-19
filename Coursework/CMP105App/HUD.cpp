#include "HUD.h"

HUD::HUD()
{
	if (!m_spriteTexture.loadFromFile(m_spritePath))
		std::cerr << "Failed to load ps glyph sprite\n";

	readInSpriteData();

	float posX = 50.f;
	float offsetX = 35.0f;
	std::vector interestedIn = { "Circle", "Square", "Triangle", "Cross" };
	for (std::pair<std::string, sf::IntRect> pair : m_spriteMap)
		// for each pair of string <file_name> to IntRect <position & size>
	{
		if (std::find(interestedIn.begin(), interestedIn.end(), pair.first) == interestedIn.end())
			continue;		// not X/square/triangle/O
		GameObject hudElement;
		hudElement.setTexture(&m_spriteTexture);
		hudElement.setTextureRect(pair.second);
		hudElement.setSize({ 30.f, 30.f });
		hudElement.setPosition({ posX, 450.f });
		posX += offsetX;
		m_HUD_Elements.push_back(hudElement);
	}
}

void HUD::readInSpriteData()
{
	std::ifstream inData(m_spriteDataPath);

	if (!inData.is_open()) std::cerr << "Failed to open ps glyph data";

	std::string name;
	int x, y, w, h;
	while (inData >> name >> x >> y >> w >> h)
	{
		m_spriteMap[name] = sf::IntRect({ {x, y}, {w, h} });
	}
	inData.close();
}


void HUD::render(sf::RenderWindow& window)
{
	for (GameObject& element : m_HUD_Elements)
	{
		window.draw(element);
	}
}
