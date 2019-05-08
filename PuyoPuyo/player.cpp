#include "stdafx.h"
#include "player.h"
#include "animation.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init() {
	_player = IMAGEMANAGER->addImage("주인공애니", "주인공애니.bmp", 392, 67, true, RGB(255, 0, 255));

	_ani = new animation;
	_ani->init(_player->getWidth(), _player->getHeight(), 56, 67);
	_ani->setPlayFrame(0, 5, false, true);
	_ani->setFPS(1);

	_ani->start();

	return S_OK;
}

void player::update() {
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 6);
}
void player::render() {
	_player->aniRender(getMemDC(), 490, 50, _ani);
}