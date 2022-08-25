#include <array>
#include <stdexcept>
#include "Menu.hpp"

namespace SFML
{

    static sf::Color const blue_menu{63, 72, 204};

    Menu::Menu(sf::RenderWindow const &window) : m_button()
    {
        sf::Font font;
        font.loadFromFile("assets/arial.ttf");
        m_button = createMap(window, font, {});
    }

    Menu::Menu(sf::RenderWindow const & window, std::initializer_list<std::string> const & list_button) : m_button()
    {
        sf::Font font;
        font.loadFromFile("assets/arial.ttf");
        m_button = createMap(window, font, list_button);
    }

    Menu::mapButton Menu::createMap(sf::RenderWindow const &window, sf::Font const &font, std::initializer_list<std::string> const &list_button)
    {
        mapButton button;
        sf::Vector2u const windowSize{window.getSize()};
        sf::Vector2i const buttonSize{static_cast<int>(windowSize.x) / 3, static_cast<int>(windowSize.y) / 3};

        int index = 0;
        for (std::string const &key : list_button)
        {
            if (button.find(key) == button.end())
            {
                sf::Vector2i const positionButton{static_cast<int>(windowSize.x) / 3 - buttonSize.x / 3, (static_cast<int>(windowSize.y) / 3) * (index + 1) - buttonSize.y / 3};
                button.insert_or_assign(key, SFML::TextButton{key, positionButton, buttonSize, sf::Color::White, blue_menu, font, windowSize.x / 40});
                index++;
            }
        }
        return button;
    }

    void Menu::drawButton(sf::RenderWindow &window, std::string const &name_button) const
    {
        if (m_button.find(name_button) == m_button.end())
        {
            throw std::invalid_argument("This name of buutton not exist");
        }
        else
        {
            m_button.at(name_button).draw(window);
        }
    }

    bool Menu::pointCollideWithButton(std::string const &name_button, sf::Vector2i const &point) const
    {
        if (m_button.find(name_button) == m_button.end())
        {
            throw std::invalid_argument("This name of buutton not exist");
        }
        else
        {
            return m_button.at(name_button).isClick(point);
        }
    }

}