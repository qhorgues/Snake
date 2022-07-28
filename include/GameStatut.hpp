#ifndef GAME_STATUT_HPP
#define GAME_STATUT_HPP

#include <cinttypes>

namespace Game
{
	enum Statut : std::uint8_t
	{
		MAIN_MENU,
		END_MENU,
		IN_GAME
	};
};


#endif