#include "Scene.h"



Scene::Scene() {
}


Scene::~Scene() {
}

void Scene::ScreenPrint(HANDLE hnd, int x, int y, const char * str) {
	DWORD dw;
	COORD coor = { x, y };
	SetConsoleCursorPosition(hnd, coor);
	WriteFile(hnd, str, strlen(str), &dw, NULL);
}

void Scene::ScreenPrint(HANDLE hnd, int x, int y, const char * str, int color) {
	DWORD dw;
	COORD coor = { x, y };
	SetConsoleTextAttribute(hnd, color);
	SetConsoleCursorPosition(hnd, coor);
	WriteFile(hnd, str, strlen(str), &dw, NULL);
	SetConsoleTextAttribute(hnd, FORE_BASIC | BACK_BASIC);
}
