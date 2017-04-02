#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    HANDLE hIn;
    HANDLE hOut;
    INPUT_RECORD InRec;
    DWORD NumRead;
	POINT p;
	string mouseX = "";
	string mouseY = "";
	string keyCode = "";

    hIn = GetStdHandle(STD_INPUT_HANDLE);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    while (1)
    {
        ReadConsoleInput(hIn, &InRec, 1, &NumRead);
        switch (InRec.EventType)
        {
			case KEY_EVENT:
			{
				if(InRec.Event.KeyEvent.bKeyDown)
				{
					keyCode = InRec.Event.KeyEvent.wVirtualKeyCode;
					cout << "You hit key with value " + keyCode << endl;
				}
				break;
			}
			case MOUSE_EVENT:
			{
				mouseX = InRec.Event.MouseEvent.dwMousePosition.X;
				mouseY = InRec.Event.MouseEvent.dwMousePosition.Y;
				if(InRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				{
					cout << "You clicked LMB on " + mouseX + " " + mouseY << endl;
				}
				else if(InRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
				{
					cout << "You clicked RMB on " + mouseX + " " + mouseY << endl;
				}
				break;
			}
		}
    }
    return 0;
}