#pragma once
#include "gameNode.h"

class bullet :public gameNode
{
protected:
	float _currentX, _currentY;				//x,y���� ��ǥ
	float _startX, _startY;					//x,y���� ��ǥ
	float _speed;							//���ǵ�
	float _speedRate;						//���ӵ�
	float _angle;							//����
	float _angleRate;						//���ӵ�
	RECT _rc;								//rect

	image* _img;							//�̹���
	bool _isFrame;							//�����������ƴ���
	int _frameCount;						//������ī��Ʈ
	float _width;							//�̹��� ����ũ��
	float _height;							//�̹��� ����ũ��
public:
	bullet();
	~bullet();

	HRESULT init();
	void update();
	void render(bool isFrame);
	void release();
	void move();
};

