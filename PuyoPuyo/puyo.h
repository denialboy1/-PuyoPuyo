#pragma once
#include "gameNode.h"
enum COLOR { RED=1, BLUE, GREEN, YELLOW, PURPLE };
class puyo : public gameNode
{
protected:
	//�ѿ� �����
	bool _control;
	//�ѿ� ���� ��ǥ
	float _x, _y;
	//�ѿ� ����
	COLOR _color;
	//�ѿ� �̹���
	image* _img;
	//�ѿ� zero ī��Ʈ
	int _zeroCount;
	//�ѿ� y�� ����
	int _yMove;
public:
	puyo();
	~puyo();

	void render();
	
	//�ѿ� ����
	COLOR getColor() { return _color; }

	//�ѿ� ��ǥ
	void setX(float x) { _x = x;}
	float getX() { return _x; }
	void setY(float y) { _y = y; }
	float getY() { return _y; }

	//�ѿ� ��� ���Ͽ�
	bool getControl(){ return _control; }
	void setControl(bool control){ _control = control; }

	//�ѿ� zero
	int getZeroCount() { return _zeroCount; }
	void setZeroCount(int zeroCount) { _zeroCount = zeroCount; }

	//�ѿ� y�� ����
	int getYMove() { return _yMove; }
	void setYMove(int yMove) { _yMove = yMove; }
};

