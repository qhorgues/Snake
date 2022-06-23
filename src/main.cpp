#include <iostream>
#include "../include/Apple.hpp"

int main()
{
    Apple apple(250, 200);
    for (int i = 0; i < 1000; i++)
    {
        std::cout << apple.getPosition().x << '/' << apple.getPosition().y << std::endl;
        apple.spawnApple(250, 200);
    }
    return 0;
}