#ifndef GAME_EVENT_HPP
#define GAME_EVENT_HPP

namespace Game
{
    enum class Event
    {
        NO_EVENT,
        PLAYER_1_WIN,
        PLAYER_2_WIN,
        LOSE,
        EQUALITY
    };
}

#endif