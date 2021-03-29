#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define MAXCOL 80
#define MAXROW 20
#define MINCOL 10
#define MINROW 3

#define LEFT 10000
#define RIGHT 10001

typedef struct hero {
	int maxHP = 100;
	int currentHP = 100;
	int maxMP = 50;
	int currentMP = 50;
	int power = 20;

	int level = 1;
	int maxEXP = 100;
	int currentEXP = 0;

	int locationX = MINCOL;
	int locationY = MAXROW-2;

	int direction = RIGHT;
};

hero character;
void initConsole();
void gotoxy(int, int);
void initUI();
char user[3][3] = { {' ','@',' '},
	{'@','l', 'o'},
	{'<','/','_'} };



int main(void)
{
	initConsole();
	initUI();
	

	while (1) {
		gotoxy(character.locationX, character.locationY - 1);
		printf("    ");
		gotoxy(character.locationX, character.locationY);
		printf("    ");
		gotoxy(character.locationX, character.locationY + 1);
		printf("    ");

		if (GetAsyncKeyState(0x41) != 0 && character.locationX > MINCOL) {
			if (character.direction == RIGHT)
				character.direction = LEFT;

			character.locationX--;
		}
		if (GetAsyncKeyState(0x44) != 0 && character.locationX + 3 < MAXCOL) {
			if (character.direction == LEFT)
				character.direction = RIGHT;

			character.locationX++;
		}


		gotoxy(character.locationX, character.locationY - 1);
		printf("%.*s", 3, user[0]);
		gotoxy(character.locationX, character.locationY);
		printf("%.*s", 3, user[1]);
		gotoxy(character.locationX, character.locationY + 1);
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

void initUI() {
	char m[30];

	gotoxy(MINCOL, MAXROW);
	for (int i = MINCOL; i < MAXCOL; i++)
		printf("=");

	gotoxy(MINCOL, MINROW);
	printf("o");
	for (int i = 0; i < 30; i++) printf("-");
	printf("o");
	gotoxy(MINCOL, MINROW + 1);
	sprintf_s(m, " HERO Lv.%d (%.2lf%%)", character.level, character.currentEXP / character.maxEXP);
	printf("%s%-30s%s", "l", m, "l");
	gotoxy(MINCOL, MINROW + 2);
	printf("%-31s%s", "l", "l");
	gotoxy(MINCOL, MINROW+3);
	sprintf_s(m, " %-3s : %5d / %5d", "HP", character.currentHP, character.maxHP);
	printf("%s%-30s%s","l",m,"l");
	gotoxy(MINCOL, MINROW+4);
	sprintf_s(m, " %-3s : %5d / %5d", "MP", character.currentMP, character.maxMP);
	printf("%s%-30s%s", "l", m, "l");
	gotoxy(MINCOL, MINROW + 5);
	printf("%-31s%s", "l", "l");
	gotoxy(MINCOL, MINROW+6);
	sprintf_s(m, " POWER : %5d", character.power);
	printf("%s%-30s%s", "l", m, "l");

	gotoxy(MINCOL, MINROW + 7);
	printf("o");
	for (int i = 0; i < 30; i++) printf("-");
	printf("o");
}