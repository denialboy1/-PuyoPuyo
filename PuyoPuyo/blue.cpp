#include "stdafx.h"
#include "blue.h"


blue::blue()
{
}


blue::~blue()
{
}

HRESULT blue::init() {
	//�ѿ� �̹���
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("�Ķ�", "blue.bmp", 960, 60, 16, 1, true, RGB(255, 0, 255));
	//�ѿ����
	_color = BLUE;

	//�Ķ��ѿ� ���� �ʱ�ȭ
	_control = false;
	return S_OK;
}

