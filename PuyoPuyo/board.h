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
	//���� �̹���
	image* _img;

	//������
	tagBoard _board[16][8];

	//�ѿ� �̱�
	puyoManager* _puyoManager;

	//�ѿ�1��,2��
	puyo* _puyo1;
	puyo* _puyo2;

	//����
	GAMESTATE _gameState;
	PUYOSTATE _puyoState;
	UPSTATE _upState;
	//�ѿ� ���ǵ�,����, �Ѱ谢��,�Ÿ�
	int _speed;
	float _angle;
	float _angleEnd;
	float _distance;

	//�ѿ� ���� �ε���
	int _index;

	//�޺�
	int _combo;

	//����ī��Ʈ�� ���������
	bool _isZeroCount;

	//���ΰ� �ƴѰ� �����
	int _zeroNum;

	//���� ��ȣ
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

