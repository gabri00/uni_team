#include "options.hpp"

namespace draw
{
    void table(sf::RenderWindow& window, const int nTiles, const int tileSize)
    {
        const float max_y = float(nTiles * tileSize),
            min_y = 0.f,
            max_x = float(nTiles * tileSize),
            min_x = 0.f;

        for (int i = 1; i < nTiles; i++)
        {
            sf::Vertex vertLine[] =
            {
                sf::Vertex(sf::Vector2f((float)tileSize * i, min_y)),
                sf::Vertex(sf::Vector2f((float)tileSize * i, max_y))
            };

            sf::Vertex orizLine[] =
            {
                sf::Vertex(sf::Vector2f(min_x, (float)tileSize * i)),
                sf::Vertex(sf::Vector2f(max_x, (float)tileSize * i))
            };

            window.draw(vertLine, 2, sf::Lines);
            window.draw(orizLine, 2, sf::Lines);
        }

        sf::Vertex bottomLine[] =
        {
            sf::Vertex(sf::Vector2f(min_x, (float)tileSize * nTiles)),
            sf::Vertex(sf::Vector2f(max_x, (float)tileSize * nTiles))
        };

        window.draw(bottomLine, 2, sf::Lines);
    }

    void cross(sf::RenderWindow& window, const float lp_x, const float lp_y)
    {
        const float offset = 25.f;

        sf::Vertex line1[] =
        {
            sf::Vertex(sf::Vector2f(lp_x - offset, lp_y - offset), options::cross_color),
            sf::Vertex(sf::Vector2f(lp_x + offset, lp_y + offset), options::cross_color)
        };

        sf::Vertex line2[] =
        {
            sf::Vertex(sf::Vector2f(lp_x - offset, lp_y + offset), options::cross_color),
            sf::Vertex(sf::Vector2f(lp_x + offset, lp_y - offset), options::cross_color)
        };

        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
    }

    void circle(sf::RenderWindow& window, const float r, const float lp_x, const float lp_y)
    {
        sf::CircleShape circle(r);
        circle.setPointCount(100);

        circle.setFillColor(sf::Color::Transparent);

        circle.setOutlineThickness(1.f);
        circle.setOutlineColor(options::circle_color);

        circle.setOrigin(r, r);
        circle.move(lp_x, lp_y);

        window.draw(circle);
    }

    sf::RectangleShape clearRect(sf::RenderWindow& window, const int nTiles, const int tileSize)
    {
        const int pixel = 1;

        sf::RectangleShape rect(sf::Vector2f((float)(nTiles * tileSize), (float)(options::winBox - pixel)));

        rect.setFillColor(options::bg_color);

        rect.move(0.f, (float)(nTiles * tileSize + pixel));

        return rect;
    }

    void winText(sf::RenderWindow& window, const char winner, const int nTiles, const int tileSize)
    {
        sf::Text text;
        sf::Font font;

        font.loadFromFile("arial.ttf");

        text.setFont(font);

        if (winner == 'X')      text.setString("X wins!");
        else if (winner == 'O') text.setString("O wins!");
        else if (winner == 'D') text.setString("draw");

        text.setCharacterSize(options::textSize);

        text.setFillColor(options::text_color);

        text.setStyle(options::text_style);

        text.move(tileSize / 4, nTiles * tileSize + 5);

        window.draw(clearRect(window, nTiles, tileSize));
        window.draw(text);
    }
}