#include "stdafx.h"
#include "red.h"


red::red()
{
}


red::~red()
{
}

HRESULT red::init() {
	//»Ñ¿ä ÀÌ¹ÌÁö
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("·¹µå", "red.bmp", 960,60, 16, 1, true, RGB(255, 0, 255));
	

	//»Ñ¿ä»ö±ò
	_color = RED;

	//»¡°­»Ñ¿ä Á¦¾î ÃÊ±âÈ­
	_control = false;

	return S_OK;
}

