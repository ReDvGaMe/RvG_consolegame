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
	// ���� ��ư�� ���ȴ��� �����Ӹ��� Ȯ���� �޼ҵ�
	void					CheckExitKey();
public:
	void					Loop();
	void					Init();
	
	SceneManager*		GetSceneManager();
	WndManager*		GetWndManager();
	// �̱������� GameManager�� ����
	static GameManager*		GetGameManager();
	
};

