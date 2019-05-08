#include "stdafx.h"
#include "yellow.h"


yellow::yellow()
{
}


yellow::~yellow()
{
}

HRESULT yellow::init() {
	//»Ñ¿ä ÀÌ¹ÌÁö
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("³ë¶û", "yellow.bmp", 960, 60, 16, 1, true, RGB(255, 0, 255));
	

	//»Ñ¿ä»ö±ò
	_color = YELLOW;

	//³ë¶û»Ñ¿ä Á¦¾î ÃÊ±âÈ­
	_control = false;
	return S_OK;
}

