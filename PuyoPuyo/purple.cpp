#include "stdafx.h"
#include "purple.h"


purple::purple()
{
}


purple::~purple()
{
}

HRESULT purple::init() {
	//�ѿ� �̹���
	_img = new image;
	_img = IMAGEMANAGER->addFrameImage("����", "purple.bmp", 960, 60, 16, 1, true, RGB(255, 0, 255));
	

	//�ѿ����
	_color = PURPLE;

	//����ѿ� ���� �ʱ�ȭ
	_control = false;
	return S_OK;
}

