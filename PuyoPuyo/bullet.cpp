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
		//프레임일 경우
		_img->frameRender(getMemDC(),
			_currentX - (_img->getFrameWidth()) / 2,		//_x,_y의 좌표가 이미지 중심으로 만듬
			_currentY - (_img->getFrameHeight()) / 2,
			_img->getFrameX(),
			_img->getFrameY());
	}
	else{
		//일반 이미지일 경우
		_img->render(getMemDC(), _currentX - _img->getWidth() / 2, _currentY - _img->getHeight() / 2);
	}
}
void bullet::release(){}
void bullet::move(){
}
