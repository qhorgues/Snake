#include <memory>
#include "SFML/Interface/Interface.hpp"
#include "Game/Event/Event.hpp"
#include "Game/Mode/Mode.hpp"
#include "Game/Statut/Statut.hpp"

int main()
{
    std::unique_ptr<Interface> interface { std::make_unique<SFML::Interface>() };
    Game::Mode mode {Game::Mode::NO_MODE};
    Game::Statut statut {Game::Statut::MAIN_MENU};
    Game::Event event {Game::Event::NO_EVENT};

    while (interface->isRunning())
    {
        interface->update(statut, mode, event);
        interface->getEvent(statut, mode);
    }

    return 0;
}