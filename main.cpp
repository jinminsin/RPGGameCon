#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define MAXCOL 90
#define MAXROW 20

#define LEFT 10000
#define RIGHT 10001

typedef struct hero {
	int maxHP = 100;
	int currentHP = 100;
	int maxMP = 50;
	int currentMP = 50;
	int weapon = 0;

	int maxEXP = 100;
	int currentEXP = 0;

	int locationX = 1;
	int locationY = 18;

	int direction = RIGHT;
};

void initConsole();
void gotoxy(int, int);
char user[3][3] = { {' ','O',' '},
	{'o','l', 'o'},
	{'_','^','_',} };



int main(void)
{
	initConsole();
	hero character;

	gotoxy(0, MAXROW);
	for (int i = 0; i < MAXCOL; i++)
		printf("=");
	

	while (1) {
		gotoxy(character.locationX - 1, character.locationY - 1);
		printf("    ");
		gotoxy(character.locationX - 1, character.locationY);
		printf("    ");
		gotoxy(character.locationX - 1, character.locationY + 1);
		printf("    ");

		if (GetAsyncKeyState(0x41) != 0 && character.locationX > 1) {
			if (character.direction == RIGHT)
				character.direction = LEFT;

			character.locationX--;
		}
		if (GetAsyncKeyState(0x44) != 0 && character.locationX + 3 < MAXCOL) {
			if (character.direction == LEFT)
				character.direction = RIGHT;

			character.locationX++;
		}


		gotoxy(character.locationX - 1, character.locationY - 1);
		printf("%.*s", 3, user[0]);
		gotoxy(character.locationX - 1, character.locationY);
		printf("%.*s", 3, user[1]);
		gotoxy(character.locationX - 1, character.locationY + 1);
		printf("%.*s", 3, user[2]);

		Sleep(20);
	}

	return 0;
}

void gotoxy(int x, int y) { //gotoxyÇÔ¼ö 
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void initConsole() {
	system("RPG Game");
	system("mode con:cols=90 lines=30");

	CONSOLE_CURSOR_INFO c;
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	c.bVisible = 0;
	c.dwSize = 1;

	SetConsoleCursorInfo(h, &c);
	SetConsoleCursorPosition(h, {0, 0});
}