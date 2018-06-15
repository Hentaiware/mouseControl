//This program is FREEWARE and should NOT be used to make profit. 
//You are free to MODIFY and RESHARE it without making profit.


#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include<winuser.h>

using namespace std;

//Mouse speed variables
int i = 0, *MouseSpeed = &i;
int oldi = 0, *oldMouseSpeed = &oldi;
//Desired mouse speed variables
int desiredSpeedCONTROL = 1;
int desiredSpeedSHIFT = 1;

bool x = false;

int main()
{
	//  Retrieving the mouse speed . 
	x = SystemParametersInfo(SPI_GETMOUSESPEED, 0, MouseSpeed, 0);
	x = SystemParametersInfo(SPI_GETMOUSESPEED, 0, oldMouseSpeed, 0);

	//Getting user input
	cout << "\n\nPrevious Mouse Speed was : " << *MouseSpeed;
	cout << "\nPlease enter desired speed for the RIGHT CONTROL button(1-20)" << endl;
	cin >> desiredSpeedCONTROL;
	cout << "\nPlease enter desired speed for the RIGHT SHIFT button(1-20)" << endl;
	cin >> desiredSpeedSHIFT;

	while (true) {
		if (GetKeyState(VK_RCONTROL) & 0x8000)// if the key is pressed
		{
			i = desiredSpeedCONTROL;
			MouseSpeed = &i;

			//  Changing the mouse speed 
			SystemParametersInfo(SPI_SETMOUSESPEED,
				0,
				(LPVOID)i,
				SPIF_UPDATEINIFILE ||
				SPIF_SENDCHANGE ||
				SPIF_SENDWININICHANGE);

		}
		else if (GetKeyState(VK_RSHIFT) & 0x8000)// if the key is pressed
		{
			i = desiredSpeedSHIFT;
			MouseSpeed = &i;

			//  Changing the mouse speed 
			SystemParametersInfo(SPI_SETMOUSESPEED,
				0,
				(LPVOID)i,
				SPIF_UPDATEINIFILE ||
				SPIF_SENDCHANGE ||
				SPIF_SENDWININICHANGE);

		}
		else { //when the key is not pressed
			SystemParametersInfo(SPI_SETMOUSESPEED,
				0,
				(LPVOID)oldi,
				SPIF_UPDATEINIFILE ||
				SPIF_SENDCHANGE ||
				SPIF_SENDWININICHANGE);

		}

	}
	return 0;
}

