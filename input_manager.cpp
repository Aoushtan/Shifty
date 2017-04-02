#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	//Making a ton of garbo
    HANDLE hIn;
    HANDLE hOut;
    bool Continue = TRUE;
    INPUT_RECORD InRec;
    DWORD NumRead;
	POINT p;

    hIn = GetStdHandle(STD_INPUT_HANDLE);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    while (Continue)
    {
        ReadConsoleInput(hIn, &InRec, 1, &NumRead);
        switch (InRec.EventType)
        {
        case KEY_EVENT:
            cout << InRec.Event.KeyEvent.wVirtualKeyCode << endl;
			if(InRec.Event.KeyEvent.wVirtualKeyCode == "VK_ESCAPE")
			{
				cout << "Exiting";
				Continue = FALSE;
			}
			break;
        case MOUSE_EVENT:
            cout << InRec.Event.MouseEvent.dwMousePosition.X << endl;
            break;
        }
    }
    return 0;
}