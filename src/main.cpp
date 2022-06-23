#include <iostream>
#include <Snake.hpp>

int main()
{
    Snake snake {100, 100};
    snake.setDirection(-1, 0);
    snake.addOnMoveElement(5);
    snake.move();
    snake.move();
    snake.move();
    snake.move();
    snake.move();
    for (Point2 const & e : snake)
    {
        std::cout << e.x << '/' << e.y << std::endl;
    }
    return 0;
}