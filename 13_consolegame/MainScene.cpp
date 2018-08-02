#include "MainScene.h"



MainScene::MainScene() {
}


MainScene::~MainScene() {
}

void MainScene::Init() {
}

void MainScene::Update() {
	if (GetAsyncKeyState(VK_UP) && _Menu == Menu::EXIT) {
		_Menu = Menu::START;
		_CursorPos.y -= 1;
	}
	else if (GetAsyncKeyState(VK_DOWN) && _Menu == Menu::START) {
		_Menu = Menu::EXIT;
		_CursorPos.y += 1;
	}
}

void MainScene::Render(HANDLE hnd) {
	ScreenPrint(hnd, 18, 13, "== 메뉴를 선택해주세요. [선택 Enter] ==", FORE_DARK_YELLOW | BACK_RED);
	ScreenPrint(hnd, 30, 15, ":: 게임 시작");
	ScreenPrint(hnd, 30, 16, ":: 게임 종료");
	ScreenPrint(hnd, (_CursorPos.x), (_CursorPos.y), "☜");
}
