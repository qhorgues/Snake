#ifndef SFML_MAIN_MENU_HPP
#define SFML_MAIN_MENU_HPP

#include "SFML_Menu.hpp"
#include "SFML_theme.hpp"

namespace SFML
{
    class MainMenu : public SFML::Menu
    {
    public:
        MainMenu() = delete;
        MainMenu(sf::RenderWindow const & window);
        ~MainMenu() noexcept override = default;

        MainMenu(MainMenu const &) = delete;
        MainMenu & operator=(MainMenu const &) = delete;

        MainMenu(MainMenu &&) = delete;
        MainMenu & operator=(MainMenu &&) = delete;

        void update(sf::RenderWindow & window, Game::Event const) const override;
        void getEvent(Game::Statut & statut, Game::Mode & mode) const override;
    private:
        sf::Text m_mainText;
        sf::Texture m_icone;
    };
    
} // namespace SFML


#endif