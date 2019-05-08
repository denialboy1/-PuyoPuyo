#pragma once
#include "gameNode.h"
#include "board.h"
#include "witch.h"
#include "player.h"

enum DEBUG{START,STOP};
enum GAMESTATE1{PLAY,GAMEOVER};
enum RESULT{WIN,LOSE,NORMAL};
class mainGame : public gameNode
{
private:
	DEBUG _debug;
	witch* _witch;
	board* _board;
	RESULT _result;
	player* _player;
	GAMESTATE1 _gameState;
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);


	mainGame();
	~mainGame();
};

