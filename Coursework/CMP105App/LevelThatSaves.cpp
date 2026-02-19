#include "LevelThatSaves.h"

LevelThatSaves::LevelThatSaves(sf::RenderWindow& hwnd, Input& in, GameState& gs, AudioManager& aud) :
	BaseLevel(hwnd, in, gs, aud), m_clickTracker(m_font)
{
	if (!m_font.openFromFile("font/bitcount.ttf"))
		std::cerr << "Oh no, my cool new font :'(";
	m_clickTracker.setCharacterSize(24);
	
	m_growyBox.setFillColor(sf::Color::Red);
	m_growyBox.setPosition({ 100,100 });
	m_growyBox.setSize({ 100,100 });

	m_spinnyBox.setFillColor(sf::Color::Yellow);
	m_spinnyBox.setPosition({ 300,100 });
	m_spinnyBox.setSize({ 50,50 });
}

LevelThatSaves::~LevelThatSaves()
{
}

void LevelThatSaves::handleInput(float dt)
{
	if (m_input.isLeftMouseDown())
	{
		m_clickTime += dt;
	}

	if (m_input.isPressed(sf::Keyboard::Scancode::Space))
	{
		saveGame();

		m_clickTracker.setCharacterSize(0);
		m_growyBox.setSize({ 0,0 });
		m_spinnyBox.setSize({ 0,0 });
	}

	if (m_input.isPressed(sf::Keyboard::Scancode::Enter))
	{
		loadGame();
	}
}

void LevelThatSaves::update(float dt)
{
	std::stringstream ss;
	ss << "Clicked for: " << std::fixed << std::setprecision(2) << m_clickTime;
	m_clickTracker.setString(ss.str());

	if (m_boxGrowing)
	{
		m_growyBox.setSize(m_growyBox.getSize() * 1.01f);
		if (m_growyBox.getSize().x > MAX_BOX_WIDTH)
			m_boxGrowing = false;
	}
	else
	{
		m_growyBox.setSize(m_growyBox.getSize() * 0.99f);
		if (m_growyBox.getSize().x < MIN_BOX_WIDTH)
			m_boxGrowing = true;
	}

	m_spinnyBox.rotate(sf::degrees(100.0f * dt));

}

void LevelThatSaves::render()
{
	beginDraw();
	m_window.draw(m_spinnyBox);
	m_window.draw(m_growyBox);
	m_window.draw(m_clickTracker);
	endDraw();
}

void LevelThatSaves::saveGame()
{
	std::ofstream write_to(m_savePath);
	if (!write_to.is_open()) {
		std::cerr << "Can't write to file";
		return;
	}
	write_to << "spinnyBoi " << m_spinnyBox.getRotation().asDegrees();
	write_to << "\ngrowyLad " << m_growyBox.getSize().x << " " << m_growyBox.getSize().y;
	write_to << " " << m_boxGrowing;
	write_to << "\nclickyTime " << m_clickTime << "\n";	// safer to end on a newline
	write_to.close();
	std::cout << "save file serialised.\n";
}

void LevelThatSaves::loadGame()
{
	std::ifstream read_from(m_savePath);
	if (!read_from.is_open()) {
		std::cerr << "Can't read from file";
		return;
	}
	std::string element;
	while (read_from >> element)
	{
		if (element == "spinnyBoi")
		{
			float angle;
			read_from >> angle;
			m_spinnyBox.setRotation(sf::degrees(angle));
		}
		else if (element == "growyLad")
		{
			float width, height;
			bool isGrowing;
			read_from >> width >> height >> isGrowing;
			m_growyBox.setSize({ width, height });
			m_boxGrowing = isGrowing;
		}
		else if (element == "clickyTime")
		{
			float timeClicked;
			read_from >> timeClicked;
			m_clickTime = timeClicked;
		}
		else
		{
			std::cout << "What on earth is: " << element;
		}
	}
	
	m_spinnyBox.setSize({ 50,50 });
	m_clickTracker.setCharacterSize(24);
	std::cout << "file deserialised\n";
}
