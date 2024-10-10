#include <iostream>
#include <Windows.h>

bool enable_autoclicker{ false };
bool key_was_pressed{ false };  // Track if the key was pressed before
INPUT input{ 0 };

void auto_clicker();
void click_mouse();

int main()
{

	std::cout << "Autoclicker initialized...\n";
	std::cout << "189.18.252.154 :) \n";

	auto_clicker();
}

void auto_clicker()
{
	while (true)
	{
		// Check if the ] key is pressed
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

		click_mouse();
		
	}
}

void click_mouse()
{

	int time{ rand() % 50 + 10 };
	// Simulate mouse click
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));

	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));

	// Delay between clicks
	Sleep((DWORD)time);
}
