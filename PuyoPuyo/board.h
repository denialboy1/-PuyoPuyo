#pragma once
#include "gameNode.h"
#include "puyoManager.h"
#include "puyo.h"

enum GAMESTATE{CONTROL,JUDGEMENT,PANG};
enum PUYOSTATE{NOTCOLLISION,ONECOLLISION};
enum UPSTATE{UP,NOTUP};

class witch;

class board : public gameNode
{
private:
	struct tagBoard {
		int color;
		int color1;
		bool collision;
		int index;
		int zeroCount;
		int zeroCountY;
		bool zero;
	};
private:
	//보드 이미지
	image* _img;

	//보드판
	tagBoard _board[16][8];

	//뿌요 뽑기
	puyoManager* _puyoManager;

	//뿌요1번,2번
	puyo* _puyo1;
	puyo* _puyo2;

	//상태
	GAMESTATE _gameState;
	PUYOSTATE _puyoState;
	UPSTATE _upState;
	//뿌요 스피드,각도, 한계각도,거리
	int _speed;
	float _angle;
	float _angleEnd;
	float _distance;

	//뿌요 벡터 인덱스
	int _index;

	//콤보
	int _combo;

	//제로카운트가 실행됬는지
	bool _isZeroCount;

	//제로가 아닌게 몇개인지
	int _zeroNum;

	//마녀 상호
	witch* _witch;

	bool _isLose;
public:
	board();
	~board();

	HRESULT init();
	void update();
	void render();
	void release();

	void randomPuyo();
	void makePuyo();

	int puyoXToboardX(float x);
	int puyoYToboardY(float y);
	int boardXTopuyoX(int x);
	int boardYTopuyoY(int y);

	void same(int x, int y);
	void boardClear();
	void color1Clear();
	int countCollision();
	void makePang();
	void indexDecrease(int index);
	void boardZeroCountClear();
	void zeroCount(int x,int y);

	int getCombo() { return _combo; }

	void setWitchMemoryAddressLink(witch* witch) { _witch = witch; }

	bool getIsLose() { return _isLose; }
};

