#include "stdafx.h"
#include "green.h"


green::green()
{
}


green::~green()
{
}

HRESULT green::init() {
	//뿌요 이미지
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("초록", "green.bmp", 960, 60, 16, 1, true, RGB(255, 0, 255));
	

	//뿌요색깔
	_color = GREEN;

	//초록뿌요 제어 초기화
	_control = false;

	//
	_x = 0;
	_y = 0;
	return S_OK;
}

