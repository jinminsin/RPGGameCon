#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define MAXCOL 50
#define MAXROW 20

void initConsole();
void gotoxy(int, int);

int main(void)
{
	initConsole();

	int character[2] = { MAXCOL / 2, MAXROW / 2};


	while (1) {
		gotoxy(character[0] - 1, character[1] - 1);
		printf(" ");

		if (GetAsyncKeyState(0x41) != 0 && character[0] > 1)
			character[0]--;
		if (GetAsyncKeyState(0x44) != 0 && character[0] < MAXCOL) 
			character[0]++;
		if (GetAsyncKeyState(0x57) != 0 && character[1] > 1)
			character[1]--;
		if (GetAsyncKeyState(0x53) != 0 && character[1] < MAXROW)
			character[1]++;

		gotoxy(character[0] - 1, character[1] - 1);
		printf("@");

		Sleep(120);
	}

	return 0;
}

void gotoxy(int x, int y) { //gotoxyÇÔ¼ö 
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void initConsole() {
	system("RPG Game");
	system("mode con:cols=50 lines=20");

	CONSOLE_CURSOR_INFO c;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	c.bVisible = 0;
	c.dwSize = 1;

	SetConsoleCursorInfo(h, &c);
	SetConsoleCursorPosition(h, {0, 0});
}