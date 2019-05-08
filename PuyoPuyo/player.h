#pragma once
#include "gameNode.h"
#include "animation.h"
class player : public gameNode
{
private:
	image* _player;
	animation* _ani;
public:
	HRESULT init();
	void update();
	void render();
	player();
	~player();
};

