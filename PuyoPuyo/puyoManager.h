#pragma once

#include <vector>
#include "puyo.h"
#include "red.h"
#include "blue.h"
#include "green.h"
#include "yellow.h"
#include "purple.h"
#include "gameNode.h"

class puyoManager : public gameNode
{
private:
	typedef vector<puyo*> vPuyo;
	typedef vector<puyo*>::iterator viPuyo;
private:
	vPuyo _vPuyo;
	viPuyo _viPuyo;

public:
	puyoManager();
	~puyoManager();


	//�����ѿ� �����
	void makeRed();

	//�Ķ��ѿ� �����
	void makeBlue();

	//����ѿ� �����
	void makeYellow();

	//�ʷϻѿ� �����
	void makeGreen();

	//����ѿ� �����
	void makePurple();

	//�ѿ������
	void removePuyo(int index);

	vPuyo getVPuyo(){ return _vPuyo; }
	viPuyo getVIPuyo(){ return _viPuyo; }
};

