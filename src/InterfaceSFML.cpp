#include <stdexcept>
#include "../include/InterfaceSFML.hpp"
#include <iostream>

SFML::Interface::Interface()
: ::Interface(),
m_window(sf::VideoMode(1200, 675), "Snake"), 
m_touch_press(),
m_texture_background(),
m_background(),
m_theme(SFML::Theme::BLACK)
{
	m_texture_background[0].loadFromFile("./assets/forest.png");
	m_texture_background[1].loadFromFile("./assets/sand.png");
	updateBackground();
	setIcon("./assets/Snake.png", 256);
}

bool SFML::Interface::isRunning() const noexcept
{
	return m_window.isOpen();
}

void SFML::Interface::getEvent(Game::Statut & statut, [[maybe_unused]]Game::Mode & mode) noexcept
{
	sf::Event event;
	if (statut == Game::Statut::IN_GAME)
	{
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
			else if (event.type == sf::Event::KeyPressed)
				m_touch_press.insert_or_assign(event.key.code, true);
			else if (event.type == sf::Event::KeyReleased)
				m_touch_press.insert_or_assign(event.key.code, false);
		}
	}
	else
	{
		if (m_window.waitEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}
	}
}

void SFML::Interface::update(Game::Statut const statut, [[maybe_unused]]Game::Mode const mode)
{
	m_window.clear();
	if (statut == Game::Statut::IN_GAME)
	{
		
	}

	m_window.draw(m_background);
	m_window.display();
}

void SFML::Interface::setIcon(std::string const & path, unsigned int const size)
{
	sf::Image icon {};
	if (icon.loadFromFile(path))
	{
		m_window.setIcon(size, size, icon.getPixelsPtr());
	}
}

std::size_t SFML::Interface::getSizeSnake() const noexcept
{
	return static_cast<std::size_t>(m_window.getSize().x / 40);
}

std::size_t SFML::Interface::getSizeApple() const noexcept
{
	return static_cast<std::size_t>(m_window.getSize().x / 60);
}

void SFML::Interface::updateBackground()
{
	int const widthWindow { static_cast<int>(m_window.getSize().x) };
	int const heightWindow { static_cast<int>(m_window.getSize().y) };

	sf::Vector2i const sizeWindow {widthWindow, heightWindow};

	sf::Vector2i const origin {0, 0};

	sf::IntRect const rectWindow { origin, sizeWindow };

	m_background.setTexture( m_texture_background[m_theme] );
	sf::FloatRect const rectSprite { m_background.getGlobalBounds() };

	float const factorX { static_cast<float>(widthWindow) / rectSprite.width };
	float const factorY { static_cast<float>(heightWindow) / rectSprite.height };

	m_background.scale(sf::Vector2f(factorX, factorY));
}