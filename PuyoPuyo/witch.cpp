#include "stdafx.h"
#include "witch.h"

#include "board.h"

witch::witch()
{
}


witch::~witch()
{
}

HRESULT witch::init(){
	_img = IMAGEMANAGER->addFrameImage("¸¶³à", "Witch.bmp", 1000, 400, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("¸¶³à¾ËÆÄ", "¸¶³à¾ËÆÄ.bmp", 250, 400, true, RGB(255, 0, 255));
	_hpBar = new progressBar;
	_hpBar->init(450,150,350,40);//ÁÂÇ¥¼³Á¤ÇØÁÖ±â!
	_hp = 100;
	_hpBar->gauge(_hp, 100);
	_alpha = 255;
	_isWin = false;
	return S_OK;
}
void witch::update(){
	_hpBar->gauge(_hp, 100);
	
	if (_alpha < 50) { _alpha = 255; }
	_alpha -= 5;

	if (_hp > 70) {
		_img->setFrameX(0);
	}
	else if (_hp > 50) {
		_img->setFrameX(1);
	}
	else if (_hp > 20) {
		_img->setFrameX(2);
	}
	else if (_hp > 0) {
		_img->setFrameX(3);
		SOUNDMANAGER->stop("»Ñ¿ä»Ñ¿ä");
		if(!SOUNDMANAGER->isPlaySound("ÆÐ¹è"))
			SOUNDMANAGER->play("ÆÐ¹è",1);
	}
	if (_hp <= 0) {
		_isWin = true;
	}
}
void witch::render() {
	if (_hp > 20) {
		_img->frameRender(getMemDC(), 680, 250, _img->getFrameX(), _img->getFrameY());
	}
	else {
		_img->alphaFrameRender(getMemDC(), 680, 250,3, 0, 255);
		IMAGEMANAGER->findImage("¸¶³à¾ËÆÄ")->alphaRender(getMemDC(), 680, 250, _alpha);
	}
	_hpBar->render();
}
void witch::release(){}