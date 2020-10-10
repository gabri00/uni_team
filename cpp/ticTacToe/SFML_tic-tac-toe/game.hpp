#include "draw.hpp"

namespace game
{
    inline void setGrid(char(&t)[3][3], const int nTiles)
    {
        for (int i = 0; i < nTiles; i++)
        {
            for (int j = 0; j < nTiles; j++)
                t[i][j] = 'E';
        }
    }

    inline void clearWindow(sf::RenderWindow& window)
    {
        window.clear(options::bg_color);
    }

    void reset(sf::RenderWindow& window, const int nTiles, char(&grid)[3][3])
    {
        clearWindow(window);

        setGrid(grid, nTiles);
    }

    const bool checkBound(const sf::Vector2i lp, const int tileSize, const int x1, const int x2, const int y1, const int y2)
    {
        if (lp.x > tileSize * x1 && lp.x < tileSize * x2 && lp.y > tileSize * y1 && lp.y < tileSize * y2)
            return true;
        else
            return false;
    }

    void showCircle(sf::RenderWindow& window, const float r, const int tileSize, char (&grid)[3][3])
    {
        sf::Vector2i lp = sf::Mouse::getPosition(window);

        if (checkBound(lp, tileSize, 0, 1, 0, 1))
        {
            if (grid[0][0] != 'X')
            {
                draw::circle(window, r, 50.f, 50.f);
                grid[0][0] = 'O';
            }
        }

        else if (checkBound(lp, tileSize, 1, 2, 0, 1))
        {
            if (grid[0][1] != 'X')
            {
                draw::circle(window, r, 150.f, 50.f);
                grid[0][1] = 'O';
            }
        }

        else if (checkBound(lp, tileSize, 2, 3, 0, 1))
        {
            if (grid[0][2] != 'X')
            {
                draw::circle(window, r, 250.f, 50.f);
                grid[0][2] = 'O';
            }
        }

        else if (checkBound(lp, tileSize, 0, 1, 1, 2))
        {
            if (grid[1][0] != 'X')
            {
                draw::circle(window, r, 50.f, 150.f);
                grid[1][0] = 'O';
            }
        }

        else if (checkBound(lp, tileSize, 1, 2, 1, 2))
        {
            if (grid[1][1] != 'X')
            {
                draw::circle(window, r, 150.f, 150.f);
                grid[1][1] = 'O';
            }
        }

        else if (checkBound(lp, tileSize, 2, 3, 1, 2))
        {
            if (grid[1][2] != 'X')
            {
                draw::circle(window, r, 250.f, 150.f);
                grid[1][2] = 'O';
            }
        }

        else if (checkBound(lp, tileSize, 0, 1, 2, 3))
        {
            if (grid[2][0] != 'X')
            {
                draw::circle(window, r, 50.f, 250.f);
                grid[2][0] = 'O';
            }
        }

        else if (checkBound(lp, tileSize, 1, 2, 2, 3))
        {
            if (grid[2][1] != 'X')
            {
                draw::circle(window, r, 150.f, 250.f);
                grid[2][1] = 'O';
            }
        }

        else if (checkBound(lp, tileSize, 2, 3, 2, 3))
        {
            if (grid[2][2] != 'X')
            {
                draw::circle(window, r, 250.f, 250.f);
                grid[2][2] = 'O';
            }
        }
    }

    void showCross(sf::RenderWindow& window, const int tileSize, char (&grid)[3][3])
    {
        sf::Vector2i lp = sf::Mouse::getPosition(window);

        if (checkBound(lp, tileSize, 0, 1, 0, 1))
        {
            if (grid[0][0] != 'O')
            {
                draw::cross(window, 50.f, 50.f);
                grid[0][0] = 'X';
            }
        }

        else if (checkBound(lp, tileSize, 1, 2, 0, 1))
        {
            if (grid[0][1] != 'O')
            {
                draw::cross(window, 150.f, 50.f);
                grid[0][1] = 'X';
            }
        }

        else if (checkBound(lp, tileSize, 2, 3, 0, 1))
        {
            if (grid[0][2] != 'O')
            {
                draw::cross(window, 250.f, 50.f);
                grid[0][2] = 'X';
            }
        }

        else if (checkBound(lp, tileSize, 0, 1, 1, 2))
        {
            if (grid[1][0] != 'O')
            {
                draw::cross(window, 50.f, 150.f);
                grid[1][0] = 'X';
            }
        }

        else if (checkBound(lp, tileSize, 1, 2, 1, 2))
        {
            if (grid[1][1] != 'O')
            {
                draw::cross(window, 150.f, 150.f);
                grid[1][1] = 'X';
            }
        }

        else if (checkBound(lp, tileSize, 2, 3, 1, 2))
        {
            if (grid[1][2] != 'O')
            {
                draw::cross(window, 250.f, 150.f);
                grid[1][2] = 'X';
            }
        }

        else if (checkBound(lp, tileSize, 0, 1, 2, 3))
        {
            if (grid[2][0] != 'O')
            {
                draw::cross(window, 50.f, 250.f);
                grid[2][0] = 'X';
            }
        }

        else if (checkBound(lp, tileSize, 1, 2, 2, 3))
        {
            if (grid[2][1] != 'O')
            {
                draw::cross(window, 150.f, 250.f);
                grid[2][1] = 'X';
            }
        }

        else if (checkBound(lp, tileSize, 2, 3, 2, 3))
        {
            if (grid[2][2] != 'O')
            {
                draw::cross(window, 250.f, 250.f);
                grid[2][2] = 'X';
            }
        }
    }

    const char checkWin(char table[][3])
    {
        for (short x = 0; x < 3; x++)
        {
            if (table[x][0] == 'X' && table[x][1] == 'X' && table[x][2] == 'X')
                return 'X';
        }

        for (short y = 0; y < 3; y++)
        {
            if (table[0][y] == 'X' && table[1][y] == 'X' && table[2][y] == 'X')
                return 'X';
        }

        if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X')
            return 'X';
        else if (table[2][0] == 'X' && table[1][1] == 'X' && table[0][2] == 'X')
            return 'X';

        for (short x = 0; x < 3; x++)
        {
            if (table[x][0] == 'O' && table[x][1] == 'O' && table[x][2] == 'O')
                return 'O';
        }

        for (short y = 0; y < 3; y++)
        {
            if (table[0][y] == 'O' && table[1][y] == 'O' && table[2][y] == 'O')
                return 'O';
        }

        if (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O')
            return 'O';
        else if (table[2][0] == 'O' && table[1][1] == 'O' && table[0][2] == 'O')
            return 'O';

        return 'D';
    }
}