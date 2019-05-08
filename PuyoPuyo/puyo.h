#pragma once
#include "gameNode.h"
enum COLOR { RED=1, BLUE, GREEN, YELLOW, PURPLE };
class puyo : public gameNode
{
protected:
	//»Ñ¿ä Á¦¾î±Ç
	bool _control;
	//»Ñ¿ä ÇöÀç ÁÂÇ¥
	float _x, _y;
	//»Ñ¿ä »ö±ò
	COLOR _color;
	//»Ñ¿ä ÀÌ¹ÌÁö
	image* _img;
	//»Ñ¿ä zero Ä«¿îÆ®
	int _zeroCount;
	//»Ñ¿ä yÃà ¹«ºê
	int _yMove;
public:
	puyo();
	~puyo();

	void render();
	
	//»Ñ¿ä »ö±ò
	COLOR getColor() { return _color; }

	//»Ñ¿ä ÁÂÇ¥
	void setX(float x) { _x = x;}
	float getX() { return _x; }
	void setY(float y) { _y = y; }
	float getY() { return _y; }

	//»Ñ¿ä Á¦¾î¿¡ °üÇÏ¿©
	bool getControl(){ return _control; }
	void setControl(bool control){ _control = control; }

	//»Ñ¿ä zero
	int getZeroCount() { return _zeroCount; }
	void setZeroCount(int zeroCount) { _zeroCount = zeroCount; }

	//»Ñ¿ä yÃà ¹«ºê
	int getYMove() { return _yMove; }
	void setYMove(int yMove) { _yMove = yMove; }
};

