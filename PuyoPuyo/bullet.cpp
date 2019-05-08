#include "stdafx.h"
#include "bullet.h"


bullet::bullet()
{
}


bullet::~bullet()
{
}

HRESULT bullet::init(){
	return S_OK;
}
void bullet::update(){
	move();
}
void bullet::render(bool isFrame){
	if (isFrame){
		//�������� ���
		_img->frameRender(getMemDC(),
			_currentX - (_img->getFrameWidth()) / 2,		//_x,_y�� ��ǥ�� �̹��� �߽����� ����
			_currentY - (_img->getFrameHeight()) / 2,
			_img->getFrameX(),
			_img->getFrameY());
	}
	else{
		//�Ϲ� �̹����� ���
		_img->render(getMemDC(), _currentX - _img->getWidth() / 2, _currentY - _img->getHeight() / 2);
	}
}
void bullet::release(){}
void bullet::move(){
}
