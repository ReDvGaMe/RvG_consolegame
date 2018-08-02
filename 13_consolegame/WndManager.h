#pragma once
#include "defines.h"

class WndManager {
public:
	WndManager();
	~WndManager();


	// Variable
private:
	HANDLE					_hScreen[2];
	int							_ScreenIndex			= 0;
	// 화면 딜레이를 확인할 변수
	DWORD					_CheckDelayTime	= 0;
public:
	
	// Method
private:
	// 화면 크기 지정
	void						SetWndSize(int width, int height);
	// 화면 커서 제거
	void						HideCursor();
	void						Init();
public:
	// 핸들을 가져옴
	HANDLE					GetHandle();
	// 화면을 지움
	void						ScreenClear();
	// 화면 교체
	void						ScreenFlipping();
};

