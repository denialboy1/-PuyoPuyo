#include "stdafx.h"
#include "puyo.h"


puyo::puyo()
{
}


puyo::~puyo()
{
}

void puyo::render() {
	_img->frameRender(getMemDC(), _x, _y);
	EFFECTMANAGER->render();
}