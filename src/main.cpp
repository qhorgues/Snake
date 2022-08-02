#include <memory>
#include "../include/SFML_Interface.hpp"
#include "../include/SFML_TextButton.hpp"

int main()
{
    std::unique_ptr<Interface> interface { std::make_unique<SFML::Interface>() };
    Game::Mode mode {Game::Mode::NONE};
    Game::Statut statut {Game::Statut::MAIN_MENU};
    while (interface->isRunning())
    {
        interface->update(statut, mode);
        interface->getEvent(statut, mode);
    }

    return 0;
}