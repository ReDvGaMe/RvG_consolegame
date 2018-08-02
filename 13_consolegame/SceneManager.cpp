#include "SceneManager.h"



SceneManager::SceneManager() {
	Init();
}


SceneManager::~SceneManager() {
	for (auto it = _SceneListl.begin(); it != _SceneListl.end(); it++)
		delete it->second;
}

void SceneManager::Init() {
	// ���� ���� �̰��� �߰�
	RegisterScene("MainScene", new MainScene());

	// ó�� ���� ���� ����
	ChangeScene("MainScene");
}

void SceneManager::Update() {
	if (_PlayScene == nullptr)	return;
	_PlayScene->Update();
}

void SceneManager::Render(HANDLE hnd) {
	if (_PlayScene == nullptr)	return;
	_PlayScene->Render(hnd);
}

void SceneManager::RegisterScene(string key, Scene * scene) {
	if (key.compare("") == 0 || scene == nullptr)	return;

	_SceneListl.insert(make_pair(key, scene));
}

void SceneManager::ChangeScene(string key) {
	map<string, Scene*>::iterator it = _SceneListl.find(key);
	if (it == _SceneListl.end())	return;
	else
		_PlayScene = it->second;
}
