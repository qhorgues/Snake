#include <array>
#include <stdexcept>
#include <limits>
#include <cassert>
#include "Menu.hpp"

namespace SFML
{

    static sf::Color const blue_menu {63, 72, 204};

    /**
     * @brief Construit le nouvelle objet Menu
     * 
     * @param window l'objet representant la fenetre
     * 
     * @exception runtime_error Dans le cas d'echec de chargement de la police arial
     */
    Menu::Menu(sf::RenderWindow const &window) : m_button(), m_textFont()
    {
        if (!m_textFont.loadFromFile("assets/arial.ttf"))
        {
            throw std::runtime_error("Impossible to load font arial");
        }
        m_button = createMap(window, m_textFont, {});
    }

    Menu::Menu(sf::RenderWindow const & window, std::initializer_list<std::string> const & list_button) : m_button()
    {
        if (!m_textFont.loadFromFile("assets/arial.ttf"))
        {
            throw std::runtime_error("Impossible to load font arial");
        }
        m_button = createMap(window, m_textFont, list_button);
    }

    Menu::mapButton Menu::createMap(sf::RenderWindow const &window, sf::Font const &font, std::initializer_list<std::string> const &list_button)
    {
        mapButton button;
        assert(std::size(list_button) > static_cast<size_t>(std::numeric_limits<int>::max()) && "list button is to large");
        int const numberButton { static_cast<int>(std::size(list_button)) };
        sf::Vector2u const windowSize{window.getSize()};
        sf::Vector2i const buttonSize{static_cast<int>(windowSize.x) / 3, static_cast<int>(static_cast<double>(windowSize.y) / static_cast<double>(std::size(list_button)+1LL)) };

        int index = 0;
        for (std::string const &key : list_button)
        {
            if (button.find(key) == button.end())
            {
                sf::Vector2i const positionButton{static_cast<int>(windowSize.x) / 4 - buttonSize.x / 2, (static_cast<int>(windowSize.y) / static_cast<int>(std::size(list_button))) * (index + 1) - buttonSize.y};
                button.insert_or_assign(key, SFML::TextButton{key, positionButton, buttonSize, sf::Color::White, blue_menu, font, windowSize.x / 20});
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