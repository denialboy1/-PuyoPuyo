#include "stdafx.h"
#include "red.h"


red::red()
{
}


red::~red()
{
}

HRESULT red::init() {
	//�ѿ� �̹���
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("����", "red.bmp", 960,60, 16, 1, true, RGB(255, 0, 255));
	

	//�ѿ����
	_color = RED;

	//�����ѿ� ���� �ʱ�ȭ
	_control = false;

	return S_OK;
}

