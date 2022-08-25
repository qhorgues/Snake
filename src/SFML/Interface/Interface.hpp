#ifndef INTERFACE_SFML_HPP
#define INTERFACE_SFML_HPP

#include <unordered_map>
#include <string>
#include <array>
#include <SFML/Graphics.hpp>
#include "../../Interface.hpp"
#include "../Menu/Menu.hpp"

namespace SFML
{
    enum class Theme;

    class Interface final : public ::Interface
    {
    public:
        Interface();
        ~Interface() noexcept override = default;
        
        Interface(Interface const &) = delete; // On supprime le constructeur par copie
        Interface& operator=(Interface const &) = delete; // On supprime l'afféctation par copie
        
        Interface(Interface &&) = delete; // On supprime le constructeur par déplacement
        Interface& operator=(Interface &&) = delete; // On supprime l'afféctation par déplacement

        void getEvent(Game::Statut & statut, Game::Mode & mode) noexcept override;
        void update(Game::Statut const statut, Game::Mode const mode, Game::Event const event) override;
        bool isRunning() const noexcept override;

        std::size_t getSizeSnake() const noexcept override;
        std::size_t getSizeApple() const noexcept override;

    private:
        void setIcon(std::string const & path, unsigned int const size);
        void updateBackground();

        sf::RenderWindow m_window;

        std::unordered_map<sf::Keyboard::Key, bool> m_touch_press;

        std::unique_ptr<SFML::Menu> m_menu;

        std::array<sf::Texture, 2> m_texture_background;
        sf::Sprite m_background;

        std::size_t m_sizeSnake;
        std::size_t m_sizeApple;
        SFML::Theme m_theme;
    };

}



#endif