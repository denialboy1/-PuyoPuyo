#include "stdafx.h"
#include "yellow.h"


yellow::yellow()
{
}


yellow::~yellow()
{
}

HRESULT yellow::init() {
	//�ѿ� �̹���
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("���", "yellow.bmp", 960, 60, 16, 1, true, RGB(255, 0, 255));
	

	//�ѿ����
	_color = YELLOW;

	//����ѿ� ���� �ʱ�ȭ
	_control = false;
	return S_OK;
}

