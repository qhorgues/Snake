#ifndef APPLE_HPP
#define APPLE_HPP

#include "Point2.hpp"

class Apple final
{
public:
    Apple() = delete;
    Apple(Point const width_map, Point const height_map);
    ~Apple() = default;

    Apple(Apple const &) = delete;
    Apple& operator=(Apple const &) = delete;

    Apple(Apple &&) = delete;
    Apple& operator=(Apple &&) = delete;

    void spawnApple(Point const width_map, Point const height_map);
    Point2 const & getPosition() const noexcept;

private:
    Point2 m_position;
};

#endif