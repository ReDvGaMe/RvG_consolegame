#pragma once
#include "defines.h"


class Scene abstract {
public:
	Scene();
	virtual ~Scene();

	// Variable
private:
public:
	
	// Method
private:
public:
	virtual void			Init()						PURE;
	virtual void			Update()					PURE;	
	virtual void			Render(HANDLE hnd)	PURE;
protected:
	void					ScreenPrint(HANDLE hnd, int x, int y, const char* str);
	void					ScreenPrint(HANDLE hnd, int x, int y, const char* str, int color);
};

