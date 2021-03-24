#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define MAXCOL 50
#define MAXROW 20

void initConsole();
char map[MAXCOL * MAXROW];

int main(void)
{
	initConsole();

	int character[2] = { MAXCOL / 2 + 1, MAXROW / 2 + 1 };

	for (int i = 0; i < MAXCOL * MAXROW; i++)
		map[i] = ' ';

	while (1) {
		map[(character[1] - 1) * MAXCOL + character[0] - 1] = ' ';

		if (GetAsyncKeyState(0x41) != 0 && character[0] > 1)
			character[0]--;
		if (GetAsyncKeyState(0x44) != 0 && character[0] < MAXCOL)
			character[0]++;
		if (GetAsyncKeyState(0x57) != 0 && character[1] > 1)
			character[1]--;
		if (GetAsyncKeyState(0x53) != 0 && character[1] < MAXROW)
			character[1]++;

		map[(character[1] - 1) * MAXCOL + character[0] - 1] = '@';

		printf("%s", map);
		Sleep(30);
	}

	return 0;
}

void initConsole() {
	system("RPG Game");
	system("mode con:cols=50 lines=20");

	HANDLE h;
	CONSOLE_CURSOR_INFO c;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	c.bVisible = 0;
	c.dwSize = 1;

	SetConsoleCursorInfo(h, &c);
	SetConsoleCursorPosition(h, {0, 0});
}