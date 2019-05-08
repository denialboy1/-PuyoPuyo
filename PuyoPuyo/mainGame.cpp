#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}



//ÃÊ±âÈ­´Â ¿©±â!
HRESULT mainGame::init(void)
{
	gameNode::init(true);
	_board = new board;
	_board->init();

	//¸¶³à ¼ÒÈ¯
	_witch = new witch;
	_witch->init();

	//»óÈ£ÂüÁ¶
	_witch->setBoardMemoryAddressLink(_board);
	_board->setWitchMemoryAddressLink(_witch);

	EFFECTMANAGER->addEffect("ºí·çÆÎ", "ºí·çÆÎ.bmp", 66, 30, 33, 30, 1, 0.2, 10);
	EFFECTMANAGER->addEffect("±×¸°ÆÎ", "±×¸°ÆÎ.bmp", 66, 30, 33, 30, 1, 0.2, 10);
	EFFECTMANAGER->addEffect("ÆÛÇÃÆÎ", "ÆÛÇÃÆÎ.bmp", 66, 30, 33, 30, 1, 0.2, 10);
	EFFECTMANAGER->addEffect("·¹µåÆÎ", "·¹µåÆÎ.bmp", 66, 30, 33, 30, 1, 0.2, 10);
	EFFECTMANAGER->addEffect("¿»·Î¿ìÆÎ", "¿»·Î¿ìÆÎ.bmp", 66, 30, 33, 30, 1, 0.2, 10);

	_debug = STOP;
	IMAGEMANAGER->addImage("¹è°æ", "background.bmp", WINSIZEX, WINSIZEY,true,RGB(255,0,255));

	SOUNDMANAGER->addSound("»Ñ¿ä»Ñ¿ä", "»Ñ¿ä»Ñ¿ä.mp3", true, true);
	SOUNDMANAGER->addSound("ÆÐ¹è", "ÆÐ¹è.mp3", true, true);
	SOUNDMANAGER->play("»Ñ¿ä»Ñ¿ä", 1);

	//ÇÃ·¹ÀÌ¾î
	_player = new player;
	_player->init();

	
	IMAGEMANAGER->addImage("½Â¸®", "½Â¸®.bmp",400,600,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("ÆÐ¹è", "ÆÐ¹è.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ÃàÇÏ", "ÃàÇÏ.bmp", WINSIZEX, 300, true, RGB(255, 0, 255));
	_gameState = PLAY;
	_result = NORMAL;
	return S_OK;

	
}

//¸Þ¸ð¸® ÇØÁ¦ ¿©±â!
void mainGame::release(void)
{
	gameNode::release();
}

//¿¬»ê ¿©±â!
void mainGame::update(void)
{
	gameNode::update();
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) {
		_debug = START;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) {
		_debug = STOP;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) {
		EFFECTMANAGER->play("ºí·çÆÎ", _ptMouse.x, _ptMouse.y);
	}
	if (_debug == START) {
		if (_gameState == PLAY) {
			_board->update();
			_witch->update();
			_player->update();
		}
	}

	EFFECTMANAGER->update();
	if (_board->getIsLose()) {
		_result = LOSE;
		_gameState = GAMEOVER;
	}
	if (_witch->getWin()) {
		_result = WIN;
		_gameState = GAMEOVER;
	}

}

// ±×·ÁÁÖ´Â °Íµµ ¿©±â!
void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->alphaRender("¹è°æ", getMemDC(), 0, 0, 125);
	_board->render();
	_witch->render();
	EFFECTMANAGER->render();
	_player->render();
	if (_result == LOSE) {
		SOUNDMANAGER->stop("ÆÐ¹è");
		SOUNDMANAGER->stop("»Ñ¿ä»Ñ¿ä");
		IMAGEMANAGER->findImage("ÆÐ¹è")->render(getMemDC(), 0, 0);
	}
	if (_result == WIN) {
		SOUNDMANAGER->stop("ÆÐ¹è");
		SOUNDMANAGER->stop("»Ñ¿ä»Ñ¿ä");
		IMAGEMANAGER->findImage("¹è°æ")->render(getMemDC(), 0, 0);
		IMAGEMANAGER->findImage("½Â¸®")->render(getMemDC(), 350, 250);
		IMAGEMANAGER->findImage("ÃàÇÏ")->render(getMemDC(), 0, 0);
	}
	//¹é¹öÆÛ ³»¿ëÀ» È­¸é¿¡ ±×·ÁÁØ´Ù ## Áö¿ìÁö ¸» °Í ##
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

