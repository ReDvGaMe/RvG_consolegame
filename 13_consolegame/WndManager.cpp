#include "WndManager.h"



WndManager::WndManager() {
	Init();
}


WndManager::~WndManager() {
	CloseHandle(_hScreen[0]);
	CloseHandle(_hScreen[1]);
}

void WndManager::SetWndSize(int width, int height) {
	char size[200] = "mode con: cols=";

	string sWidth = to_string(width);
	strcat(size, sWidth.c_str());

	strcat(size, " lines=");
	string sHeight = to_string(height);
	strcat(size, sHeight.c_str());

	system(size);
}

void WndManager::HideCursor() {
	CONSOLE_CURSOR_INFO cci;

	cci.dwSize = 1;
	cci.bVisible = FALSE;

	SetConsoleCursorInfo(_hScreen[0], &cci);
	SetConsoleCursorInfo(_hScreen[1], &cci);
}

void WndManager::Init() {
	setlocale(LC_ALL, "korean");
	system(TITLE);
	SetWndSize(WND_WIDTH, WND_HEIGHT);

	_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	HideCursor();
}

HANDLE WndManager::GetHandle() {
	return _hScreen[_ScreenIndex];
}

void WndManager::ScreenClear() {
	COORD coor = { 0, 0 };
	DWORD dw;

	for (int i = 0; i < WND_HEIGHT; i++) {
		for (int j = 0; j < WND_WIDTH; j++) {
			SetConsoleTextAttribute(
				GetHandle(),
				FORE_BASIC);
			WriteFile(GetHandle(), " ", strlen(" "), &dw, NULL);
		}
	}
}

void WndManager::ScreenFlipping() {
	if (GetTickCount() - _CheckDelayTime > SCREEN_DELAY) {
		_CheckDelayTime = GetTickCount();

		SetConsoleActiveScreenBuffer(_hScreen[_ScreenIndex]);

		_ScreenIndex = !_ScreenIndex;
	}
}
