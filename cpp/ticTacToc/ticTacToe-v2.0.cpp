#include <iostream>

using namespace std;

char Tabella[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'X';

void Disegno()
{
    cout << "Tris\n";

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << Tabella[row][col] << ' ';
        }
        cout << '\n';
    }
}

void Input()
{
    int a;
    cout << "E' il turno di " << player <<". Inserire il numero della tabella da sostituire: ";
    cin >> a;

    if (a == 1)
    {
        if (Tabella[0][0] == '1')
            Tabella[0][0] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    else if (a == 2)
    {
        if (Tabella[0][1] == '2')
            Tabella[0][1] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    else if (a == 3)
    {
        if (Tabella[0][2] == '3')
            Tabella[0][2] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    else if (a == 4)
    {
        if (Tabella[1][0] == '4')
            Tabella[1][0] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    else if (a == 5)
    {
        if (Tabella[1][1] == '5')
            Tabella[1][1] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    else if (a == 6)
    {
        if (Tabella[1][2] == '6')
            Tabella[1][2] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    else if (a == 7)
    {
        if (Tabella[2][0] == '7')
            Tabella[2][0] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    else if (a == 8)
    {
        if (Tabella[2][1] == '8')
            Tabella[2][1] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    else if (a == 9)
    {
        if (Tabella[2][2] == '9')
            Tabella[2][2] = player;
        else
        {
            cout << "Casella già occupata, riprova!" << endl;
            Input();
        }
    }
    
}

void SwitchPlayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char WinCheck()
{
    
    if (Tabella[0][0] == 'X' && Tabella[0][1] == 'X' && Tabella[0][2] == 'X')
        return 'X';
    if (Tabella[1][0] == 'X' && Tabella[1][1] == 'X' && Tabella[1][2] == 'X')
        return 'X';
    if (Tabella[2][0] == 'X' && Tabella[2][1] == 'X' && Tabella[2][2] == 'X')
        return 'X';

    if (Tabella[0][0] == 'X' && Tabella[1][0] == 'X' && Tabella[2][0] == 'X')
        return 'X';
    if (Tabella[0][1] == 'X' && Tabella[1][1] == 'X' && Tabella[2][1] == 'X')
        return 'X';
    if (Tabella[0][2] == 'X' && Tabella[1][2] == 'X' && Tabella[2][2] == 'X')
        return 'X';

    if (Tabella[0][0] == 'X' && Tabella[1][1] == 'X' && Tabella[2][2] == 'X')
        return 'X';
    if (Tabella[2][0] == 'X' && Tabella[1][1] == 'X' && Tabella[0][2] == 'X')
        return 'X';

    
    if (Tabella[0][0] == 'O' && Tabella[0][1] == 'O' && Tabella[0][2] == 'O')
        return 'O';
    if (Tabella[1][0] == 'O' && Tabella[1][1] == 'O' && Tabella[1][2] == 'O')
        return 'O';
    if (Tabella[2][0] == 'O' && Tabella[2][1] == 'O' && Tabella[2][2] == 'O')
        return 'O';

    if (Tabella[0][0] == 'O' && Tabella[1][0] == 'O' && Tabella[2][0] == 'O')
        return 'O';
    if (Tabella[0][1] == 'O' && Tabella[1][1] == 'O' && Tabella[2][1] == 'O')
        return 'O';
    if (Tabella[0][2] == 'O' && Tabella[1][2] == 'O' && Tabella[2][2] == 'O')
        return 'O';

    if (Tabella[0][0] == 'O' && Tabella[1][1] == 'O' && Tabella[2][2] == 'O')
        return 'O';
    if (Tabella[2][0] == 'O' && Tabella[1][1] == 'O' && Tabella[0][2] == 'O')
        return 'O';

    return '/';
}

int main()
{
    int n = 0;

    Disegno();

    while (1)
    {
        n++;
        Input();

        Disegno();

        if (WinCheck() == 'X')
        {
            cout << "La X vince!" << endl;
            break;
        }
        else if (WinCheck() == 'O')
        {
            cout << "Il O vince!" << endl;
            break;
        }
        else if (WinCheck() == '/' && n == 9)
        {
            cout << "Pareggio" << endl;
            break;
        }
        SwitchPlayer();
    }
    
    return 0;
}
