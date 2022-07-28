#ifndef GAME_MODE_HPP
#define GAME_MODE_HPP

#include <cinttypes>

namespace Game
{
	enum Mode : std::uint8_t
	{
		SOLO,
		MULTI,
		NONE
	};
};

#endif