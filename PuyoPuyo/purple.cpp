#include "stdafx.h"
#include "purple.h"


purple::purple()
{
}


purple::~purple()
{
}

HRESULT purple::init() {
	//뿌요 이미지
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("보라", "purple.bmp", 960, 60, 16, 1, true, RGB(255, 0, 255));
	

	//뿌요색깔
	_color = PURPLE;

	//보라뿌요 제어 초기화
	_control = false;
	return S_OK;
}

