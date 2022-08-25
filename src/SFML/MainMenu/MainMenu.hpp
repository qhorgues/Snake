#ifndef SFML_MAIN_MENU_HPP
#define SFML_MAIN_MENU_HPP

#include "../Menu/Menu.hpp"
#include "../Theme/Theme.hpp"
#include "../../Game/Mode/Mode.hpp"
#include "../../Game/Statut/Statut.hpp"
#include "../../Game/Event/Event.hpp"


namespace SFML
{
    enum class Theme;

    class MainMenu final : public Menu
    {
    public:
        MainMenu() = delete;
        MainMenu(sf::RenderWindow const & window);
        ~MainMenu() noexcept = default;

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