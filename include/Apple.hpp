#ifndef APPLE_HPP
#define APPLE_HPP

class Apple final
{
public:
    Apple() = default;
    ~Apple() = default;

    Apple(Apple const &) = delete;
    Apple& operator=(Apple const &) = delete;

    Apple(Apple &&) = delete;
    Apple& operator=(Apple &&) = delete;

private:
    

}

#endif