#include "stdafx.h"
#include "green.h"


green::green()
{
}


green::~green()
{
}

HRESULT green::init() {
	//�ѿ� �̹���
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("�ʷ�", "green.bmp", 960, 60, 16, 1, true, RGB(255, 0, 255));
	

	//�ѿ����
	_color = GREEN;

	//�ʷϻѿ� ���� �ʱ�ȭ
	_control = false;

	//
	_x = 0;
	_y = 0;
	return S_OK;
}

