#pragma once
#include "Scene.h"

enum class Menu { START, EXIT };

struct CursorPos {
	int	x;
	int	y;
};

class MainScene final:
	public Scene {
public:
	MainScene();
	virtual ~MainScene();


	// Variable
private:
	Menu						_Menu		= Menu::START;
	CursorPos				_CursorPos	= { 45, 15 };
public:
	
	// Method
private:
public:
	virtual void				Init()							override;
	virtual void				Update()						override;
	virtual void				Render(HANDLE hnd)		override;
};

