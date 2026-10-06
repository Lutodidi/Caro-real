#include <stdio.h>
#include <windows.h>
#include <cctype>
#include<conio.h>
#include "Board.cpp"
void main() {
	FixConsoleWindow();
	StartGame();
	bool validEnter = true;
	while (1)
	{
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27)
		{
			ExitGame();
			return;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 13) {
				switch (CheckBoard(_X, _Y)) {
				case -1:
					printf_s("X"); break;
				case 1:
					printf_s("O"); break;
				case 0: validEnter = false;
				}
				if (validEnter == true) {
					switch (ProcessFinish(TestBoard())) {
					case -1: case 1: case 0:
						if (AskContinue() != 'Y') {
							ExitGame(); return;
						}
						else StartGame();

					}
				}
				validEnter = true;
			}
		}
	}
}
			