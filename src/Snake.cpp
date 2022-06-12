#include <Snake.hpp>
#include <cassert>

Snake::Snake(Snake::Point posX, Snake::Point posY, unsigned int speed, unsigned int life)
 : m_snake(), m_directionX(0), m_directionY(0), m_speed(speed), m_life(life), m_reserveMember(0)
{
	m_snake.push_back(Point2(posX, posY));
}

Snake::const_iterator Snake::cbegin() const noexcept
{
	return std::cbegin(m_snake);
}

Snake::const_iterator Snake::cend() const noexcept
{
	return std::cend(m_snake);
}

Snake::iterator Snake::begin() noexcept
{
	return std::begin(m_snake);
}

Snake::iterator Snake::end() noexcept
{
	return std::end(m_snake);
}

void Snake::reset(unsigned int speed, unsigned int life) noexcept
{
	m_snake.clear();
	m_directionX = 0;
	m_directionY = 0;
	m_reserveMember = 0;
	m_speed = speed;
	m_life = life;
}

void Snake::move()
{
	addOnMove();
	if (m_reserveMember == 0)
		m_snake.pop_back();
}

void Snake::addOnMove()
{
	m_snake.push_back(Point2(m_directionX*m_speed + m_snake.back().x, 
							m_directionY*m_speed + m_snake.back().y));
}

void Snake::addOnMoveElement(unsigned int numberElement)
{
	addOnMove();
	m_reserveMember += numberElement-1;
}

void Snake::setDirection(Snake::direction x, Snake::direction y)
{
    assert((x == 1 or x == -1 or x == 0) && "x necessary 1, -1 or 0");
    assert((y == 1 or y == -1 or y == 0) && "y necessary 1, -1 or 0");
	
	if (x != y)
	{
		m_directionX = x;
		m_directionY = y;
	}
}

std::tuple<Snake::direction, Snake::direction> Snake::getDirection() const noexcept
{
	return std::make_tuple(m_directionX, m_directionY);
}

std::size_t Snake::size() const noexcept
{
	return std::size(m_snake);
}