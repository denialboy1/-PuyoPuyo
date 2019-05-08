#include "stdafx.h"
#include "blue.h"


blue::blue()
{
}


blue::~blue()
{
}

HRESULT blue::init() {
	//»Ñ¿ä ÀÌ¹ÌÁö
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("ÆÄ¶û", "blue.bmp", 960, 60, 16, 1, true, RGB(255, 0, 255));
	//»Ñ¿ä»ö±ò
	_color = BLUE;

	//ÆÄ¶û»Ñ¿ä Á¦¾î ÃÊ±âÈ­
	_control = false;
	return S_OK;
}

