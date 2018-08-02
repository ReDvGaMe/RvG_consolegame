#include "GameManager.h"



GameManager::GameManager() {
	Init();
}


GameManager::~GameManager() {
}

void GameManager::CheckExitKey() {
	if (GetAsyncKeyState(VK_ESCAPE))
		GetGameManager()->m_GameRunning = false;
}

void GameManager::Loop() {
	while (m_GameRunning) {
		CheckExitKey();
		_WndManager.ScreenClear();
		_SceneManager.Update();
		_SceneManager.Render(_WndManager.GetHandle());
		_WndManager.ScreenFlipping();
	}
}

void GameManager::Init() {
}

SceneManager * GameManager::GetSceneManager() {
	return &_SceneManager;
}

WndManager * GameManager::GetWndManager() {
	return &_WndManager;
}

GameManager * GameManager::GetGameManager() {
	static GameManager	_GameManager;
	return &_GameManager;
}
