#pragma once
#include "defines.h"
#include "Scene.h"

// 추가한 씬을 아래에 포함
#include "MainScene.h"

class SceneManager {
public:
	SceneManager();
	~SceneManager();


	// Variable
private:
	// 모든 씬을 가지고 있을 맵
	map<string, Scene*>	_SceneListl;
	// 현재 플레이중인 씬을 참조할 포인터
	Scene*					_PlayScene;
public:
	
	// Method
private:
public:
	void						Init();
	void						Update();
	void						Render(HANDLE hnd);

	// 씬 추가
	void						RegisterScene(string key, Scene* scene);
	// 씬 교체
	void						ChangeScene(string key);
};

