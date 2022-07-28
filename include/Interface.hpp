#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "GameMode.hpp"
#include "GameStatut.hpp"

#include <string>

// Vituel pure class modèle

class Interface
{
public:
    Interface() = default;
    virtual ~Interface() = default; // On autorise le polymorphisme

    Interface(Interface const &) = delete;
    Interface& operator=(Interface const &) = delete;
    Interface(Interface &&) = delete;
    Interface& operator=(Interface &&) = delete;

    virtual void getEvent(Game::Statut & statut, Game::Mode & mode) noexcept = 0;
    virtual void update(Game::Statut const statut, Game::Mode const mode) = 0;
    virtual bool isRunning() const = 0;
    virtual std::size_t getSizeSnake() const noexcept = 0;
    virtual std::size_t getSizeApple() const noexcept = 0;
};



#endif