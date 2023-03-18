
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y);

int main()
{
    string rotating_string = "Welcome to workmate...";
	int len = rotating_string.length();
	char letter_holder;

	do
	{
		gotoXY(14,13);
		cout << rotating_string;
		Sleep(200);
		letter_holder = rotating_string[len];
		for( int x=len;x>0;x--)
		{
			rotating_string[x] = rotating_string[x-1];
		}
		rotating_string[0] = letter_holder;

	} while(true);


    return 0;
}

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}
