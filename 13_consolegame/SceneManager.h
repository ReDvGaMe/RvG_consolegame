#pragma once
#include "defines.h"
#include "Scene.h"

// �߰��� ���� �Ʒ��� ����
#include "MainScene.h"

class SceneManager {
public:
	SceneManager();
	~SceneManager();


	// Variable
private:
	// ��� ���� ������ ���� ��
	map<string, Scene*>	_SceneListl;
	// ���� �÷������� ���� ������ ������
	Scene*					_PlayScene;
public:
	
	// Method
private:
public:
	void						Init();
	void						Update();
	void						Render(HANDLE hnd);

	// �� �߰�
	void						RegisterScene(string key, Scene* scene);
	// �� ��ü
	void						ChangeScene(string key);
};

