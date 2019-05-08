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


	//»¡°­»Ñ¿ä ¸¸µé±â
	void makeRed();

	//ÆÄ¶û»Ñ¿ä ¸¸µé±â
	void makeBlue();

	//³ë¶û»Ñ¿ä ¸¸µé±â
	void makeYellow();

	//ÃÊ·Ï»Ñ¿ä ¸¸µé±â
	void makeGreen();

	//º¸¶ó»Ñ¿ä ¸¸µé±â
	void makePurple();

	//»Ñ¿äÁö¿ì±â
	void removePuyo(int index);

	vPuyo getVPuyo(){ return _vPuyo; }
	viPuyo getVIPuyo(){ return _viPuyo; }
};

