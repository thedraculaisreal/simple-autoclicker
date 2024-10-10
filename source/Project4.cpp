#include <iostream>
#include <Windows.h>

bool enable_autoclicker{ true };
bool key_was_pressed{ false };  // Track if the key was pressed before
INPUT input{ 0 };

void click();

int main()
{
	click();
}

void click()
{
	while (true)
	{
		// Check if the M key is pressed
		if (GetAsyncKeyState('M') & 0x8000)
		{
			// If the key was not previously pressed, toggle autoclicker
			if (!key_was_pressed)
			{
				enable_autoclicker = !enable_autoclicker;
				key_was_pressed = true; // Mark the key as pressed
			}
		}
		else
		{
			// Reset the key pressed flag once the key is released
			key_was_pressed = false;
		}

		// If autoclicker is disabled, skip clicking
		if (!enable_autoclicker)
		{
			Sleep(10);
			continue;
		}

		// Simulate mouse click
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput(1, &input, sizeof(INPUT));

		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &input, sizeof(INPUT));

		// Delay between clicks
		Sleep(5);
	}
}
