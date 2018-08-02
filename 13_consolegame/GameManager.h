#pragma once
#include "defines.h"
#include "SceneManager.h"
#include "WndManager.h"

class GameManager {
public:
	GameManager();
	~GameManager();


	// Variable
private:
	SceneManager		_SceneManager;
	WndManager		_WndManager;
public:
	bool					m_GameRunning = true;

	// Method
private:
	// 종료 버튼이 눌렸는지 프레임마다 확인할 메소드
	void					CheckExitKey();
public:
	void					Loop();
	void					Init();
	
	SceneManager*		GetSceneManager();
	WndManager*		GetWndManager();
	// 싱글톤으로 GameManager에 접근
	static GameManager*		GetGameManager();
	
};

