#include <SFML/Graphics.hpp>
#include "../../include/SFML/roundedRect.hpp"

void SFML::renderFillRoundedRect(sf::RenderWindow & window, sf::IntRect const & rect, sf::Color const & color, int const radius)
{

    if (radius > 0)
    {
        sf::CircleShape angleRect {static_cast<float>(radius)};
		angleRect.setFillColor(color);
        if (radius >= rect.width/2 && radius <= rect.height/2)
        {
			angleRect.setRadius(rect.width/2);
            angleRect.setPosition(rect.left, rect.top);
            window.draw(angleRect);

            angleRect.setPosition(rect.left + rect.width - 2*angleRect.getRadius()-1, rect.top);
            window.draw(angleRect);

			sf::RectangleShape rectPart {sf::Vector2f(rect.width, rect.height - rect.width)};
			rectPart.setPosition(sf::Vector2f(rect.left, rect.top + angleRect.getRadius()));
			rectPart.setFillColor(color);
            window.draw(rectPart);
        }
        else if (radius >= rect.height/2 && radius <= rect.width/2)
        {
            angleRect.setRadius(rect.height/2);
            angleRect.setPosition(rect.left, rect.top);
            window.draw(angleRect);
            
            angleRect.setPosition(rect.left + rect.width - 2*angleRect.getRadius()-1, rect.top);
            window.draw(angleRect);

			sf::RectangleShape rectPart {sf::Vector2f(rect.width - rect.height, rect.height)};
			rectPart.setPosition(sf::Vector2f(rect.left + angleRect.getRadius(), rect.top));
			rectPart.setFillColor(color);
            window.draw(rectPart);
        }
        else if (radius >= rect.width/2 && radius >= rect.height/2)
        {
			angleRect.setRadius((rect.width > rect.height) ? rect.height/2 : rect.width/2);
            angleRect.setPosition(rect.left, rect.top);
            window.draw(angleRect);
        }
        else
        {
            angleRect.setPosition(rect.left, rect.top);
            window.draw(angleRect);
            
            angleRect.setPosition(rect.left + rect.width - 2*radius-1, rect.top);
            window.draw(angleRect);
            
            angleRect.setPosition(rect.left, rect.top + rect.height - 2*radius-1);
            window.draw(angleRect);
            
            angleRect.setPosition(rect.left + rect.width - 2*radius-1, rect.top + rect.height - 2*radius-1);
            window.draw(angleRect);

            sf::RectangleShape rectPart1 {sf::Vector2f(rect.width - 2*radius, rect.height)};
			rectPart1.setPosition(sf::Vector2f(rect.left + radius, rect.top));
			rectPart1.setFillColor(color);
            window.draw(rectPart1);
			
			sf::RectangleShape rectPart2 {sf::Vector2f(rect.width, rect.height - 2*radius)};
            rectPart2.setPosition(sf::Vector2f(rect.left, rect.top+radius));
			rectPart2.setFillColor(color);
            window.draw(rectPart2);
        }
    }
    else
    {
		sf::RectangleShape rectShape {sf::Vector2f(rect.width, rect.height)};
        rectShape.setPosition(sf::Vector2f(rect.left, rect.top));
		rectShape.setFillColor(color);
        window.draw(rectShape);
    }
}