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
		// Check if the M key is pressed
		if (GetAsyncKeyState('M') & 0x1)
		{

			enable_autoclicker = !enable_autoclicker;
		}

		if (!enable_autoclicker)
			continue;

		click_mouse();
		
	}
}

void click_mouse()
{
	
	srand(static_cast<unsigned>(time(0)));
	int time{ rand() % 100 + 20 };
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
