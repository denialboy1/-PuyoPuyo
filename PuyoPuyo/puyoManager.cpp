#include "stdafx.h"
#include "puyoManager.h"


puyoManager::puyoManager()
{
}


puyoManager::~puyoManager()
{
}


//�����ѿ� �����
void puyoManager::makeRed() {
	red* temp;
	temp = new red;
	temp->init();
	
	_vPuyo.push_back(temp);
}


//�Ķ��ѿ� �����
void puyoManager::makeBlue(){
	blue* temp;
	temp = new blue;
	temp->init();

	_vPuyo.push_back(temp);
}

//����ѿ� �����
void puyoManager::makeYellow() {
	yellow* temp;
	temp = new yellow;
	temp->init();

	_vPuyo.push_back(temp);
}

//�ʷϻѿ� �����
void puyoManager::makeGreen() {
	green* temp;
	temp = new green;
	temp->init();

	_vPuyo.push_back(temp);
}

//����ѿ� �����
void puyoManager::makePurple(){
	purple* temp;
	temp = new purple;
	temp->init();

	_vPuyo.push_back(temp);
}

//�ѿ� �����
void puyoManager::removePuyo(int index){
	SAFE_DELETE(_vPuyo[index]);
	_vPuyo.erase(_vPuyo.begin()+index);
}