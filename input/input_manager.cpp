#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	//Making a ton of garbo
    HANDLE hIn;
    HANDLE hOut;
    INPUT_RECORD InRec;
    DWORD NumRead;
	POINT p;
	string mouseX = "";
	string mouseY = "";

    hIn = GetStdHandle(STD_INPUT_HANDLE);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    while (1)
    {
        ReadConsoleInput(hIn, &InRec, 1, &NumRead);
        switch (InRec.EventType)
        {
			case KEY_EVENT:
			{
				cout << InRec.Event.KeyEvent.wVirtualKeyCode << endl;
			}
			case MOUSE_EVENT:
			{
				if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					cout << "You clicked lmb LOL" << endl;
				}
				else {
					mouseX = InRec.Event.MouseEvent.dwMousePosition.X;
					mouseY = InRec.Event.MouseEvent.dwMousePosition.Y;
					cout << mouseX + " " + mouseY;
				}
				break;
			}
		}
    }
    return 0;
}