#pragma once
#include "gameNode.h"

class bullet :public gameNode
{
protected:
	float _currentX, _currentY;				//x,y현재 좌표
	float _startX, _startY;					//x,y시작 좌표
	float _speed;							//스피드
	float _speedRate;						//가속도
	float _angle;							//각도
	float _angleRate;						//각속도
	RECT _rc;								//rect

	image* _img;							//이미지
	bool _isFrame;							//프레임인지아닌지
	int _frameCount;						//프레임카운트
	float _width;							//이미지 가로크기
	float _height;							//이미지 세로크기
public:
	bullet();
	~bullet();

	HRESULT init();
	void update();
	void render(bool isFrame);
	void release();
	void move();
};

