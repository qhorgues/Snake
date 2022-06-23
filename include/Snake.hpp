#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <list>
#include <tuple>
#include "Point2.hpp"

class Snake final // Non héritable
{
	
public:
	using Point = int;
	using direction = signed char;
	
	Snake() = delete;
	Snake(Snake::Point posX, Snake::Point posY, int speed = 1, int life = 1);
	~Snake() = default;
	
	Snake(Snake const &) = delete;
	Snake& operator=(Snake const &) = delete;
	
	Snake(Snake &&) = delete;
	Snake& operator=(Snake &&) = delete;
	
	void move();
	void reset(int speed = 1, int life = 1) noexcept;
	void addOnMove();
	void addOnMoveElement(unsigned int numberElement);
	void setDirection(Snake::direction x, Snake::direction y);
	std::tuple<Snake::direction, Snake::direction> getDirection() const noexcept;
	std::size_t size() const noexcept;
	
	// Const iterator
	using const_iterator = std::list<Point2>::const_iterator;
	Snake::const_iterator cbegin() const noexcept;
	Snake::const_iterator cend() const noexcept;
	
	// Iterator
	using iterator = std::list<Point2>::iterator ;
	Snake::iterator begin() noexcept;
	Snake::iterator end() noexcept;

private:
	std::list<Point2> m_snake;
	Snake::direction m_directionX;
	Snake::direction m_directionY;
	int m_speed;
	int m_life;
	unsigned int m_reserveMember;
};


#endif