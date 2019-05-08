#pragma once
#include "gameNode.h"
#include "witch.h"
#include "progressBar.h"

class board;

class witch : public gameNode
{
private:
	int _alpha;

	//적 체력
	float _hp;
	progressBar* _hpBar;

	//적 이미지
	image* _img;

	//보드 상호참조
	board* _board;

	int _damage;

	bool _isWin;
public:
	witch();
	~witch();

	HRESULT init();
	void update();
	void render();
	void release();

	void setBoardMemoryAddressLink(board* board) { _board = board; }

	//hp
	void setHp(float hp) { _hp = hp; }
	float getHp() { return _hp; }

	bool getWin() { return _isWin; }
};

