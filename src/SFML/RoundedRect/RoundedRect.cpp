#include <SFML/Graphics.hpp>
#include "RoundedRect.hpp"

void SFML::renderFillRoundedRect(sf::RenderWindow & window, sf::IntRect const & rect, sf::Color const & color, int const radius)
{

    if (radius > 0)
    {
        sf::CircleShape angleRect {static_cast<float>(radius)};
		angleRect.setFillColor(color);
        if (radius >= rect.width/2 && radius <= rect.height/2)
        {
			angleRect.setRadius(static_cast<float>(rect.width/2));
            angleRect.setPosition(static_cast<float>(rect.left), static_cast<float>(rect.top));
            window.draw(angleRect);

            angleRect.setPosition(static_cast<float>(rect.left) + static_cast<float>(rect.width) - 2*angleRect.getRadius()-1, static_cast<float>(rect.top));
            window.draw(angleRect);

			sf::RectangleShape rectPart {sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height - rect.width))};
			rectPart.setPosition(sf::Vector2f(static_cast<float>(rect.left), static_cast<float>(rect.top) + angleRect.getRadius()));
			rectPart.setFillColor(color);
            window.draw(rectPart);
        }
        else if (radius >= rect.height/2 && radius <= rect.width/2)
        {
            angleRect.setRadius(static_cast<float>(rect.height/2));
            angleRect.setPosition(static_cast<float>(rect.left), static_cast<float>(rect.top));
            window.draw(angleRect);
            
            angleRect.setPosition(static_cast<float>(rect.left) + static_cast<float>(rect.width) - 2*angleRect.getRadius()-1, static_cast<float>(rect.top));
            window.draw(angleRect);

			sf::RectangleShape rectPart {sf::Vector2f(static_cast<float>(rect.width - rect.height), static_cast<float>(rect.height))};
			rectPart.setPosition(sf::Vector2f(static_cast<float>(rect.left) + angleRect.getRadius(), static_cast<float>(rect.top)));
			rectPart.setFillColor(color);
            window.draw(rectPart);
        }
        else if (radius >= rect.width/2 && radius >= rect.height/2)
        {
			angleRect.setRadius(static_cast<float>((rect.width > rect.height) ? rect.height/2 : rect.width/2));
            angleRect.setPosition(static_cast<float>(rect.left), static_cast<float>(rect.top));
            window.draw(angleRect);
        }
        else
        {
            angleRect.setPosition(static_cast<float>(rect.left), static_cast<float>(rect.top));
            window.draw(angleRect);
            
            angleRect.setPosition(static_cast<float>(rect.left + rect.width - 2*radius-1), static_cast<float>(rect.top));
            window.draw(angleRect);
            
            angleRect.setPosition(static_cast<float>(rect.left), static_cast<float>(rect.top + rect.height - 2*radius-1));
            window.draw(angleRect);
            
            angleRect.setPosition(static_cast<float>(rect.left + rect.width - 2*radius-1), static_cast<float>(rect.top + rect.height - 2*radius-1));
            window.draw(angleRect);

            sf::RectangleShape rectPart1 {sf::Vector2f(static_cast<float>(rect.width - 2*radius), static_cast<float>(rect.height))};
			rectPart1.setPosition(sf::Vector2f(static_cast<float>(rect.left + radius), static_cast<float>(rect.top)));
			rectPart1.setFillColor(color);
            window.draw(rectPart1);
			
			sf::RectangleShape rectPart2 {sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height - 2*radius))};
            rectPart2.setPosition(sf::Vector2f(static_cast<float>(rect.left), static_cast<float>(rect.top+radius)));
			rectPart2.setFillColor(color);
            window.draw(rectPart2);
        }
    }
    else
    {
		sf::RectangleShape rectShape {sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height))};
        rectShape.setPosition(sf::Vector2f(static_cast<float>(rect.left), static_cast<float>(rect.top)));
		rectShape.setFillColor(color);
        window.draw(rectShape);
    }
}