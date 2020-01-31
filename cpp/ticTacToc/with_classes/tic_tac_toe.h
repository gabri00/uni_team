#pragma once

#ifndef _TIC_TAC_TOE_H_
#define _TIC_TAC_TOE_H_

#include <string>

using namespace std;

#define HEADER	"\t***\tTRIS GAME\t***\n"
#define GRID	3

class Tris
{
public:

	Tris();
	~Tris();

	char getPlayer() { return player; };
	char& getPlayerRef() { return player; };
	void Draw();
	void Input(char player);
	void checkTable(int x, int y, char a);
	inline void SwitchPlayer(char& player);
	const char WinCheck();

private:
	char table[GRID][GRID] = { {'1', '2', '3'},
						{'4', '5', '6'},
						{'7', '8', '9'} };
	char player = 'X';
};


#endif _TIC_TAC_TOE_