#include <SFML/Graphics.hpp>
#include <string>
#include <cassert>
#include "../TextButton/TextButton.hpp"
#include "../RoundedRect/RoundedRect.hpp"

#define RADIUS 45


SFML::TextButton::TextButton(std::string const & text, 
                        sf::Vector2i const & position,
                        sf::Vector2i const & size,
                        sf::Color const & textColor,
                        sf::Color const & backColor,
                        sf::Font const & font, 
                        unsigned int const sizePolice) 
: m_textButton(text, font, sizePolice), m_rectText(position, size), m_textColor(textColor), m_backColor(backColor)
{
    float const width = textWidth();
    float const height = textHeight();
    m_textButton.setFillColor(textColor);
    assert(static_cast<int>(width) <= size.x && "The width of the button must be greater than or equal to the width taken by the text");
    assert(static_cast<int>(height) <= size.y && "The height of the button must be greater than or equal to the height taken by the text");

    m_textButton.setPosition(sf::Vector2f(static_cast<float>(m_rectText.left) / 2.f - width/2.f , static_cast<float>(m_rectText.top) / 2.f - height/2.f));
    allignText();
}

bool SFML::TextButton::isClick(sf::Vector2i const & point) const noexcept
{
    return m_rectText.contains(point);
}

void SFML::TextButton::draw(sf::RenderWindow & window, sf::Vector2i const & position) noexcept
{
	m_rectText.left = position.x;
	m_rectText.top = position.y;
    allignText();
    renderFillRoundedRect(window, m_rectText, m_backColor, RADIUS);
    window.draw(m_textButton);
}

void SFML::TextButton::draw(sf::RenderWindow & window) const noexcept
{
    renderFillRoundedRect(window, m_rectText, m_backColor, RADIUS);
    window.draw(m_textButton);
}

void SFML::TextButton::setPosition(sf::Vector2i const & position) noexcept
{
    
    m_rectText.left = position.x;
    m_rectText.top = position.y;
    
}

float SFML::TextButton::textWidth() const noexcept
{
    return m_textButton.getGlobalBounds().width;
}

float SFML::TextButton::textHeight() const noexcept
{
    return m_textButton.getGlobalBounds().height;
}

void SFML::TextButton::allignText() noexcept
{
    float const width { textWidth() };
    float const height { textHeight() };
    float const posX = static_cast<float>(m_rectText.left) + static_cast<float>(m_rectText.width) / 2.f - static_cast<float>(width)/2.f;
    float const posY =  static_cast<float>(m_rectText.top) + static_cast<float>(m_rectText.height) / 2.f - static_cast<float>(height)/1.2f;
    m_textButton.setPosition(sf::Vector2f(posX , posY));
}