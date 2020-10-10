#include <SFML/Graphics.hpp>

// here you can easily customize the game
namespace options
{
    // keys
    sf::Keyboard::Key reset_key = sf::Keyboard::Space;
    sf::Mouse::Button circle_btn = sf::Mouse::Left;
    sf::Mouse::Button cross_btn = sf::Mouse::Right;

    // colors
    sf::Color bg_color = sf::Color::Black;
    sf::Color cross_color = sf::Color::Red;
    sf::Color circle_color = sf::Color::Green;
    sf::Color text_color = sf::Color::Cyan;

    // text style
    sf::Text::Style text_style = sf::Text::Regular;

    const int textSize = 20,
              winBox = 40,
              antialias = 6;
}