#include "stdafx.h"
#include "puyoManager.h"


puyoManager::puyoManager()
{
}


puyoManager::~puyoManager()
{
}


//»¡°­»Ñ¿ä ¸¸µé±â
void puyoManager::makeRed() {
	red* temp;
	temp = new red;
	temp->init();
	
	_vPuyo.push_back(temp);
}


//ÆÄ¶û»Ñ¿ä ¸¸µé±â
void puyoManager::makeBlue(){
	blue* temp;
	temp = new blue;
	temp->init();

	_vPuyo.push_back(temp);
}

//³ë¶û»Ñ¿ä ¸¸µé±â
void puyoManager::makeYellow() {
	yellow* temp;
	temp = new yellow;
	temp->init();

	_vPuyo.push_back(temp);
}

//ÃÊ·Ï»Ñ¿ä ¸¸µé±â
void puyoManager::makeGreen() {
	green* temp;
	temp = new green;
	temp->init();

	_vPuyo.push_back(temp);
}

//º¸¶ó»Ñ¿ä ¸¸µé±â
void puyoManager::makePurple(){
	purple* temp;
	temp = new purple;
	temp->init();

	_vPuyo.push_back(temp);
}

//»Ñ¿ä Áö¿ì±â
void puyoManager::removePuyo(int index){
	SAFE_DELETE(_vPuyo[index]);
	_vPuyo.erase(_vPuyo.begin()+index);
}