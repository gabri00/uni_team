// graphical tic tac toe developed by me    { v1.2 }

#ifdef NOMINMAX
#include <windows.h>
#else
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX
#endif

#include "game.hpp"


inline void checkEvents(sf::RenderWindow& window)
{
    sf::Event e;
    while (window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)    window.close();
    }
}

int main()
{
    sf::ContextSettings ctxSets;
    ctxSets.antialiasingLevel = options::antialias;

    const int tileSize = 100, nTiles = 3;
    const float r = 25.f;
    char grid[nTiles][nTiles];

    ShowWindow(GetConsoleWindow(), SW_HIDE);    // to hide the console on windows

    game::setGrid(grid, nTiles);

    sf::RenderWindow window(sf::VideoMode(tileSize * nTiles, tileSize * nTiles + options::winBox), "Tic tac toe", sf::Style::Default, ctxSets);

    game::clearWindow(window);

    while (window.isOpen())
    {
        checkEvents(window);

        draw::table(window, nTiles, tileSize);

        // game events
        if (sf::Mouse::isButtonPressed(options::circle_btn))
            game::showCircle(window, r, tileSize, grid);

        if (sf::Mouse::isButtonPressed(options::cross_btn))
            game::showCross(window, tileSize, grid);

        if (sf::Keyboard::isKeyPressed(options::reset_key))
            game::reset(window, nTiles, grid);

        // check if a win occures
        draw::winText(window, game::checkWin(grid), nTiles, tileSize);

        //end of the current frame
        window.display();
    }

    return 0;
}