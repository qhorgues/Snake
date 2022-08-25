#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include "../Menu/Menu.hpp"

namespace SFML
{
    MainMenu::MainMenu(sf::RenderWindow const & window) : Menu(window, {"Solo", "Multiplayer", "Quit"}), m_mainText(), m_icone()
    {
        // sf::Font imprisha;
        // imprisha.loadFromFile("assets/imprisha.ttf");
        // sf::Text("The Snake", imprisha, window.getSize().x/14);
        m_icone.loadFromFile("assets/Snake.png");
    }

    void MainMenu::update(sf::RenderWindow & window, Game::Event const) const
    {
        drawButton(window, "Solo");
        drawButton(window, "Multiplayer");
        drawButton(window, "Quit");

        sf::Sprite icone {m_icone};
        window.draw(icone);
    }

    void MainMenu::getEvent([[maybe_unused]]Game::Statut & statut, [[maybe_unused]]Game::Mode & mode) const
    {

    }
}