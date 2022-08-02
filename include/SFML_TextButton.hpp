#ifndef TEXT_BUTTON_HPP
#define TEXT_BUTTON_HPP

#include <SFML/Graphics.hpp>

namespace SFML
{

    class TextButton final
    {
    public:
        TextButton() = default;
        TextButton(std::string const & text, 
                            sf::Vector2i const & position,
                            sf::Vector2i const & size,
                            sf::Color const & textColor,
                            sf::Color const & backColor,
                            sf::Font const & font, 
                            unsigned int const sizePolice = 30U) ;

        TextButton(TextButton const &) = delete;
        TextButton& operator=(TextButton const &) = delete;

        TextButton(TextButton &&) = delete;
        TextButton& operator=(TextButton &&) = delete;
        
        ~TextButton() = default;

        bool isClick(sf::Vector2i const & point) const noexcept;
        void draw(sf::RenderWindow & window) const noexcept;
        void draw(sf::RenderWindow & window, sf::Vector2i const & position) noexcept;
        void setPosition(sf::Vector2i const & position) noexcept;

    private:
        float textHeight() const noexcept; 
        float textWidth() const noexcept; 
        void allignText() noexcept;

        sf::Text m_textButton;
        sf::IntRect m_rectText;
        sf::Color m_textColor;
        sf::Color m_backColor;
        sf::Vector2i m_pos;
    };

};


#endif