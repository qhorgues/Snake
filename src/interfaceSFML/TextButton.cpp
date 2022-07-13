#include <SFML/Graphics.hpp>
#include <string>
#include <cassert>
#include "../../include/interfaceSFML/TextButton.hpp"
#include "../../include/interfaceSFML/roundedRect.hpp"

#define RADIUS 45


TextButton::TextButton(std::string const & text, 
                        sf::Vector2i const & position,
                        sf::Vector2i const & size,
                        sf::Color const & textColor,
                        sf::Color const & backColor,
                        sf::Font const & font, 
                        unsigned int const sizePolice) 
: m_textButton(text, font, sizePolice), m_rectText(position, size), m_textColor(textColor), m_backColor(backColor)
{
    double const width = textWidth();
    double const height = textHeight();
    m_textButton.setFillColor(textColor);
    assert(width <= size.x && "The width of the button must be greater than or equal to the width taken by the text");
    assert(height <= size.y && "The height of the button must be greater than or equal to the height taken by the text");

    m_textButton.setPosition(sf::Vector2f(m_rectText.left / 2. - width/2. , m_rectText.top / 2. - height/2.));
    allignText();
}

bool TextButton::isClick(sf::Vector2i const & point) const noexcept
{
    return m_rectText.contains(point);
}

void TextButton::draw(sf::RenderWindow & window, sf::Vector2i const & position) noexcept
{
	m_rectText.left = position.x;
	m_rectText.top = position.y;
    allignText();
    renderFillRoundedRect(window, m_rectText, m_backColor, RADIUS);
    window.draw(m_textButton);
}

void TextButton::draw(sf::RenderWindow & window) const noexcept
{
    renderFillRoundedRect(window, m_rectText, m_backColor, RADIUS);
    window.draw(m_textButton);
}

void TextButton::setPosition(sf::Vector2i const & position) noexcept
{
    
    m_rectText.left = position.x;
    m_rectText.top = position.y;
    
}

double TextButton::textWidth() const noexcept
{
    return m_textButton.getGlobalBounds().width/*  * m_textButton.getString().getSize() */;
}

double TextButton::textHeight() const noexcept
{
    return m_textButton.getGlobalBounds().height;
}

void TextButton::allignText() noexcept
{
    double const width { textWidth() };
    double const height { textHeight() };
    double const posX = m_rectText.left + m_rectText.width / 2. - width/2.;
    double const posY =  m_rectText.top + m_rectText.height / 2. - height/1.2;
    m_textButton.setPosition(sf::Vector2f(posX , posY));
}