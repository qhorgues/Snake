#include "../include/Apple.hpp"
#include <random>
#include <tuple>

Apple::Apple(Point const width_map, Point const height_map)
{
    spawnApple(width_map, height_map);
}

void Apple::spawnApple(Point const width_map, Point const height_map)
{
    std::tuple<Point const, Point const> const width {width_map/20,  width_map - width_map/20};
    std::tuple<Point const, Point const> const height {height_map/20,  height_map - height_map/20};


    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> distrib_width(std::get<0>(width), std::get<1>(width));
    std::uniform_int_distribution<> distrib_height(std::get<0>(height), std::get<1>(height));

    m_position.x = distrib_width(gen);
    m_position.y = distrib_height(gen);
}

Point2 const & Apple::getPosition() const noexcept
{
    return m_position;
}