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
	// ȭ�� �����̸� Ȯ���� ����
	DWORD					_CheckDelayTime	= 0;
public:
	
	// Method
private:
	// ȭ�� ũ�� ����
	void						SetWndSize(int width, int height);
	// ȭ�� Ŀ�� ����
	void						HideCursor();
	void						Init();
public:
	// �ڵ��� ������
	HANDLE					GetHandle();
	// ȭ���� ����
	void						ScreenClear();
	// ȭ�� ��ü
	void						ScreenFlipping();
};

