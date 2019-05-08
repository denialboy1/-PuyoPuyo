#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}



//�ʱ�ȭ�� ����!
HRESULT mainGame::init(void)
{
	gameNode::init(true);
	_board = new board;
	_board->init();

	//���� ��ȯ
	_witch = new witch;
	_witch->init();

	//��ȣ����
	_witch->setBoardMemoryAddressLink(_board);
	_board->setWitchMemoryAddressLink(_witch);

	EFFECTMANAGER->addEffect("�����", "�����.bmp", 66, 30, 33, 30, 1, 0.2, 10);
	EFFECTMANAGER->addEffect("�׸���", "�׸���.bmp", 66, 30, 33, 30, 1, 0.2, 10);
	EFFECTMANAGER->addEffect("������", "������.bmp", 66, 30, 33, 30, 1, 0.2, 10);
	EFFECTMANAGER->addEffect("������", "������.bmp", 66, 30, 33, 30, 1, 0.2, 10);
	EFFECTMANAGER->addEffect("���ο���", "���ο���.bmp", 66, 30, 33, 30, 1, 0.2, 10);

	_debug = STOP;
	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY,true,RGB(255,0,255));

	SOUNDMANAGER->addSound("�ѿ�ѿ�", "�ѿ�ѿ�.mp3", true, true);
	SOUNDMANAGER->addSound("�й�", "�й�.mp3", true, true);
	SOUNDMANAGER->play("�ѿ�ѿ�", 1);

	//�÷��̾�
	_player = new player;
	_player->init();

	
	IMAGEMANAGER->addImage("�¸�", "�¸�.bmp",400,600,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("�й�", "�й�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "����.bmp", WINSIZEX, 300, true, RGB(255, 0, 255));
	_gameState = PLAY;
	_result = NORMAL;
	return S_OK;

	
}

//�޸� ���� ����!
void mainGame::release(void)
{
	gameNode::release();
}

//���� ����!
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
		EFFECTMANAGER->play("�����", _ptMouse.x, _ptMouse.y);
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

// �׷��ִ� �͵� ����!
void mainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	IMAGEMANAGER->alphaRender("���", getMemDC(), 0, 0, 125);
	_board->render();
	_witch->render();
	EFFECTMANAGER->render();
	_player->render();
	if (_result == LOSE) {
		SOUNDMANAGER->stop("�й�");
		SOUNDMANAGER->stop("�ѿ�ѿ�");
		IMAGEMANAGER->findImage("�й�")->render(getMemDC(), 0, 0);
	}
	if (_result == WIN) {
		SOUNDMANAGER->stop("�й�");
		SOUNDMANAGER->stop("�ѿ�ѿ�");
		IMAGEMANAGER->findImage("���")->render(getMemDC(), 0, 0);
		IMAGEMANAGER->findImage("�¸�")->render(getMemDC(), 350, 250);
		IMAGEMANAGER->findImage("����")->render(getMemDC(), 0, 0);
	}
	//����� ������ ȭ�鿡 �׷��ش� ## ������ �� �� ##
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

