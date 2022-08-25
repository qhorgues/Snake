#ifndef SFML_MENU_HPP
#define SFML_MENU_HPP

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../../Game/Mode/Mode.hpp"
#include "../../Game/Statut/Statut.hpp"
#include "../../Game/Event/Event.hpp"
#include "../Theme/Theme.hpp"
#include "../TextButton/TextButton.hpp"

namespace SFML
{
    class Menu
    {
    public:
        Menu() = delete;
        Menu(sf::RenderWindow const & window);
        Menu(sf::RenderWindow const & window, std::initializer_list<std::string> const & list_button);
        virtual ~Menu() = default;

        Menu(Menu const &) = default;
        Menu & operator=(Menu const &) = default;

        Menu(Menu &&) = default;
        Menu & operator=(Menu &&) = default;

        virtual void update(sf::RenderWindow & window, Game::Event const event) const = 0;
        virtual void getEvent(Game::Statut & statut, Game::Mode & mode) const = 0;
        void drawButton(sf::RenderWindow & window, std::string const & name_button) const;
        bool pointCollideWithButton(std::string const & name_button, sf::Vector2i const & point) const;

    private:
        using mapButton = std::unordered_map<std::string, SFML::TextButton>;
        static mapButton createMap(sf::RenderWindow const & window, sf::Font const & font, std::initializer_list<std::string> const & list_button);

        mapButton m_button;
    };
}

#endif