#ifndef INTERFACE_SFML_HPP
#define INTERFACE_SFML_HPP

#include <unordered_map>
#include <string>
#include <array>
#include <SFML/Graphics.hpp>
#include "Interface.hpp"
#include "theme.hpp"
#include "TextButton.hpp"

namespace SFML
{
    class Interface final : public ::Interface
    {
    public:
        Interface();
        ~Interface() = default;
        
        Interface(Interface const &) = delete; // On supprime le constructeur par copie
        Interface& operator=(Interface const &) = delete; // On supprime l'afféctation par copie
        
        Interface(Interface &&) = delete; // On supprime le constructeur par déplacement
        Interface& operator=(Interface &&) = delete; // On supprime l'afféctation par déplacement

        void getEvent(Game::Statut & statut, Game::Mode & mode) noexcept override;
        void update(Game::Statut const statut, Game::Mode const mode) override;
        bool isRunning() const noexcept override;

        std::size_t getSizeSnake() const noexcept override;
        std::size_t getSizeApple() const noexcept override;

    private:
        void updateMainMenu() noexcept;
        void setIcon(std::string const & path, unsigned int const size);
        void updateBackground();

        sf::RenderWindow m_window;

        std::unordered_map<sf::Keyboard::Key, bool> m_touch_press;

        std::unordered_map<std::string, SFML::TextButton> m_button;
        sf::Font m_font;

        std::array<sf::Texture, 2> m_texture_background;
        sf::Sprite m_background;

        std::size_t m_sizeSnake;
        std::size_t m_sizeApple;
        SFML::Theme m_theme;
    };

};



#endif