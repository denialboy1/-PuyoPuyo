#include "stdafx.h"
#include "board.h"

#include "witch.h"

board::board()
{
}


board::~board()
{
}

HRESULT board::init() {
	//보드 초기화
	_img = IMAGEMANAGER->addImage("보드", "보드.bmp", 561, 840, true, RGB(255, 0, 255));
	boardClear();
	boardZeroCountClear();

	//뿌요 만들기 초기화
	_puyoManager = new puyoManager;
	randomPuyo();
	makePuyo();
	

	//벽 초기화
	memset(_board, 0, sizeof(_board));
	for (int i = 0; i < 8; i++) {
		_board[15][i].color = 10;
	}
	for (int i = 0; i < 16; i++) {
		_board[i][0].color = 10;
		_board[i][7].color = 10;
	}


	//뿌요상태
	_gameState = CONTROL;
	_puyoState = NOTCOLLISION;
	_upState = NOTUP;

	//뿌요 초기화
	_speed = 1;
	_angle = 0;
	_angleEnd = PI / 2;
	_distance = 0;

	//뿌요 벡터 인덱스
	_index = 1;

	//콤보
	_combo = 0;

	//제로카운트가 실행됬는지
	_isZeroCount = false;
	//제로가 아닌게 몇개인지
	_zeroNum;
	//
	_isLose = false;
	return S_OK;
}
void board::update() {
	switch (_gameState) {
	case CONTROL:
		//왼쪽 이동
		if (_puyoState == NOTCOLLISION) {
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) {
				if (_puyo1->getX() < _puyo2->getX()) {		//첫번째 뿌요가 두번째 뿌요보다 왼쪽에 있을때
					if (_board[puyoYToboardY(_puyo1->getY()+40)][puyoXToboardX(_puyo1->getX() - 60)].color == 0) {
						_puyo1->setX(_puyo1->getX() - 60);
						_puyo2->setX(_puyo2->getX() - 60);
					}
				}
				else if (_puyo1->getX() > _puyo2->getX()) {  //두번째 뿌요가 첫번째 뿌요보다 왼쪽에 있을떄
					if (_board[puyoYToboardY(_puyo2->getY()+40)][puyoXToboardX(_puyo2->getX() - 60)].color == 0) {
						_puyo2->setX(_puyo2->getX() - 60);
						_puyo1->setX(_puyo1->getX() - 60);
					}
				}
				else if (_puyo1->getX() == _puyo2->getX()) {
					if (_puyo1->getY() > _puyo2->getY()) {
						if (_board[puyoYToboardY(_puyo1->getY()) + 1][puyoXToboardX(_puyo1->getX() - 60)].color == 0) {
							_puyo1->setX(_puyo1->getX() - 60);
						}
						if (_board[puyoYToboardY(_puyo2->getY()) + 2][puyoXToboardX(_puyo2->getX() - 60)].color == 0) {
							_puyo2->setX(_puyo2->getX() - 60);
						}
					}
					if (_puyo1->getY() < _puyo2->getY()) {
						if (_board[puyoYToboardY(_puyo1->getY()) + 2][puyoXToboardX(_puyo1->getX() - 60)].color == 0) {
							_puyo1->setX(_puyo1->getX() - 60);
						}
						if (_board[puyoYToboardY(_puyo2->getY()) + 1][puyoXToboardX(_puyo2->getX() - 60)].color == 0) {
							_puyo2->setX(_puyo2->getX() - 60);
						}
					}
				}
			}
			//오른쪽 이동
			else 	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
				if (_puyo1->getX() < _puyo2->getX()) {		//첫번째 뿌요가 두번째 뿌요보다 왼쪽에 있을때
					if (_board[puyoYToboardY(_puyo2->getY()+40)][puyoXToboardX(_puyo2->getX() + 60)].color == 0) {
						_puyo2->setX(_puyo2->getX() + 60);
						_puyo1->setX(_puyo1->getX() + 60);
					}
				}
				else if (_puyo1->getX() > _puyo2->getX()) { //두번째 뿌요가 첫번째 뿌요보다 왼쪽에 있을떄
					if (_board[puyoYToboardY(_puyo1->getY()+40)][puyoXToboardX(_puyo1->getX() + 60)].color == 0) {
						_puyo1->setX(_puyo1->getX() + 60);
						_puyo2->setX(_puyo2->getX() + 60);
					}
				}
				else if (_puyo1->getX() == _puyo2->getX()) {
					if (_puyo1->getY() > _puyo2->getY()) {
						if (_board[puyoYToboardY(_puyo1->getY()) + 1][puyoXToboardX(_puyo1->getX() + 60)].color == 0) {
							_puyo1->setX(_puyo1->getX() + 60);
						}
						if (_board[puyoYToboardY(_puyo2->getY()) + 2][puyoXToboardX(_puyo2->getX() + 60)].color == 0) {
							_puyo2->setX(_puyo2->getX() + 60);
						}
					}
					if (_puyo1->getY() < _puyo2->getY()) {
						if (_board[puyoYToboardY(_puyo1->getY()) + 2][puyoXToboardX(_puyo1->getX() + 60)].color == 0) {
							_puyo1->setX(_puyo1->getX() + 60);
						}
						if (_board[puyoYToboardY(_puyo2->getY()) + 1][puyoXToboardX(_puyo2->getX() + 60)].color == 0) {
							_puyo2->setX(_puyo2->getX() + 60);
						}
					}
				}
			}
			else if (KEYMANAGER->isOnceKeyDown(VK_UP)) {
				_angleEnd += PI / 2;
				_angle = getAngle(_puyo1->getX(), _puyo1->getY(), _puyo2->getX(), _puyo2->getY());
				_distance = getDistance(_puyo1->getX(), _puyo1->getY(), _puyo2->getX(), _puyo2->getY());
				_upState = UP;
				if (_angleEnd >= PI * 2) _angleEnd = 0;
			}

			if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
				_puyo2->setY(_puyo2->getY() + 4);
				_puyo1->setY(_puyo1->getY() + 4);
			}


			if (_upState == UP) {
				_angle += 0.9f;
				if (_angle > _angleEnd) {
					_upState = NOTUP;
					_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));
					_angle = _angleEnd;
				}
				//왼쪽 벽 충돌
				if (_board[puyoYToboardY(_puyo2->getY())+1][puyoXToboardX(_puyo2->getX()) - 1].color != 0 &&
					_board[puyoYToboardY(_puyo2->getY())+1][puyoXToboardX(_puyo2->getX()) + 1].color == 0 &&
					_puyo1->getX() == _puyo2->getX() && _puyo1->getY() > _puyo2->getY()) {

					if (_angle - 0.3 < PI / 2) {
						_angle = PI / 2;
						_puyo2->setX(cosf(_angle)*_distance + _puyo1->getX() + 10);
						_puyo2->setY(-sinf(_angle)*_distance + _puyo1->getY());
						_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));
						_upState = NOTUP;
					}
					else if (_board[puyoYToboardY(_puyo2->getY()) + 1][puyoXToboardX(_puyo2->getX()) + 1].color != 0 &&
						_board[puyoYToboardY(_puyo2->getY()) + 1][puyoXToboardX(_puyo2->getX()) - 1].color != 0) {
						_upState = NOTUP;
					}
					else {
						_angle = PI;
						_puyo1->setX(_puyo1->getX() + 60);
						_puyo2->setX(_puyo2->getX() + 60);
						_puyo2->setX(cosf(_angle)*_distance + _puyo1->getX());
						_puyo2->setY(-sinf(_angle)*_distance + _puyo1->getY());
						_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));
						_upState = NOTUP;
					}
				}
				//오른쪽 벽 충돌
				else if (_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX()) + 1].color != 0 &&
					_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX()) - 1].color == 0 &&
					_puyo1->getX() == _puyo2->getX() && _puyo1->getY() < _puyo2->getY()) {
					_puyo1->setX(_puyo1->getX() - 60);
					_puyo2->setX(_puyo2->getX() - 60);
					_angle = 0;
					_puyo2->setX(cosf(_angle)*_distance + _puyo1->getX());
					_puyo2->setY(-sinf(_angle)*_distance + _puyo1->getY());
					_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));
					_upState = NOTUP;
				}
				else if (_board[puyoYToboardY(_puyo2->getY()) + 1][puyoXToboardX(_puyo2->getX()) + 1].color != 0 &&
					_board[puyoYToboardY(_puyo2->getY()) + 1][puyoXToboardX(_puyo2->getX()) - 1].color != 0
					) {
					_upState = NOTUP;
				}
				else if (_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX()) + 1].color != 0 &&
					_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].color != 0) {
					_puyo2->setX(cosf(_angle)*_distance + _puyo1->getX() - 1);
					_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));
					_upState = NOTUP;
				}
			
				
				//벽이 없을경우
				else {					_puyo2->setX(cosf(_angle)*_distance + _puyo1->getX());
					_puyo2->setY(-sinf(_angle)*_distance + _puyo1->getY());
				}

			}

		}
		//만약 회전 중이라면 땅바닥에서 잠시 위로 튕겨줌
		if (_upState == UP && _board[puyoYToboardY(_puyo2->getY()) + 1][puyoXToboardX(_puyo2->getX())].color == 10) {
			_puyo1->setY(_puyo1->getY() - 70);
			_puyo2->setY(_puyo2->getY() - 70);
			_angle = PI + PI / 2;
			_puyo2->setX(cosf(_angle)*_distance + _puyo1->getX());
			_puyo2->setY(-sinf(_angle)*_distance + _puyo1->getY());
			_puyo1->setY(boardYTopuyoY(puyoYToboardY(_puyo1->getY())));
			_puyo2->setY(boardYTopuyoY(puyoYToboardY(_puyo2->getY())));
			_upState = NOTUP;
		}
		//뿌요가 y축으로 이동
		if (_puyoState == ONECOLLISION) _speed = 5;
		else { _speed = 1; }
		if (_puyo1->getY() > _puyo2->getY() && _puyo1->getX() == _puyo2->getX()) {									//뿌요2이 뿌요1보다 아래에 있는상태
			_puyo1->setY(_puyo1->getY() + _speed);																	//				ㅁ2
			_puyo2->setY(_puyo2->getY() + _speed);																	//			    ㅁ1
			if (_board[puyoYToboardY(_puyo1->getY() + 60)][puyoXToboardX(_puyo1->getX())].color != 0) {				//이런거 처리해줌
				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].color = _puyo1->getColor();
				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].color = _puyo2->getColor();

				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].color1 = _puyo1->getColor();
				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].color1 = _puyo2->getColor();

				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].index = _puyoManager->getVPuyo().size() - 2;
				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].index = _puyoManager->getVPuyo().size() - 1;
				_puyo1->setY(boardYTopuyoY(puyoYToboardY(_puyo1->getY())));
				_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));
				_puyo2->setY(boardYTopuyoY(puyoYToboardY(_puyo2->getY())));
			}
		}



		if (_puyo1->getY() < _puyo2->getY() && _puyo1->getX() == _puyo2->getX()) {									//뿌요2이 뿌요1보다 아래에 있는상태
			_puyo2->setY(_puyo2->getY() + _speed);																//				ㅁ1
			_puyo1->setY(_puyo1->getY() + _speed);																//			    ㅁ2
			if (_board[puyoYToboardY(_puyo2->getY() + 60)][puyoXToboardX(_puyo2->getX())].color != 0) {				//이런거 처리해줌
				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].color = _puyo2->getColor();
				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].color = _puyo1->getColor();

				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].color1 = _puyo2->getColor();
				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].color1 = _puyo1->getColor();

				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].index = _puyoManager->getVPuyo().size() - 2;
				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].index = _puyoManager->getVPuyo().size() - 1;
				_puyo1->setY(boardYTopuyoY(puyoYToboardY(_puyo1->getY())));
				_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));
				_puyo2->setY(boardYTopuyoY(puyoYToboardY(_puyo2->getY())));
			}
		}

		if ((_puyo1->getX() < _puyo2->getX() || _puyo1->getX() > _puyo2->getX())) {									//뿌요가 아래와 같이 여러종류로 있는상태
			_puyo1->setY(_puyo1->getY() + _speed); 																	//				ㅁ1
			if (_board[puyoYToboardY(_puyo1->getY() + 60)][puyoXToboardX(_puyo1->getX())].color != 0) {				//					ㅁ2
				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].color = _puyo1->getColor();	//이런거 처리해줌
				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].color1 = _puyo1->getColor();
				_board[puyoYToboardY(_puyo1->getY())][puyoXToboardX(_puyo1->getX())].index = _puyoManager->getVPuyo().size() - 2;
				_puyo1->setY(boardYTopuyoY(puyoYToboardY(_puyo1->getY())));
				_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));

			}
			_puyo2->setY(_puyo2->getY() + _speed);
			if (_board[puyoYToboardY(_puyo2->getY() + 60)][puyoXToboardX(_puyo2->getX())].color != 0) {
				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].color = _puyo2->getColor();
				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].color1 = _puyo2->getColor();
				_board[puyoYToboardY(_puyo2->getY())][puyoXToboardX(_puyo2->getX())].index = _puyoManager->getVPuyo().size() - 1;
				_puyo2->setY(boardYTopuyoY(puyoYToboardY(_puyo2->getY())));
				_puyo2->setX(boardXTopuyoX(puyoXToboardX(_puyo2->getX())));
			}
		}



		//뿌요가 하나라도 땅에 닿거나 다른 뿌요에가 닿을경우 컨트롤 못하게함
		if (_board[puyoYToboardY(_puyo1->getY() + 60)][puyoXToboardX(_puyo1->getX())].color != 0 ||
			_board[puyoYToboardY(_puyo2->getY() + 60)][puyoXToboardX(_puyo2->getX())].color != 0) {
			_puyoState = ONECOLLISION;
		}

		//뿌요 두개가 땅에 닿거나 다른 뿌요에 닿을경우 4개이상 모였는지 판단하게 함
		if (_board[puyoYToboardY(_puyo1->getY() + 60)][puyoXToboardX(_puyo1->getX())].color != 0 &&
			_board[puyoYToboardY(_puyo2->getY() + 60)][puyoXToboardX(_puyo2->getX())].color != 0) {
			_gameState = JUDGEMENT;
			_puyo1 = NULL;
			_puyo2 = NULL;
		}

		for (int i = 2; i < 4; i++) {
			if (_board[i][3].color == 0) 
				break;
			_isLose = true;
		}
		break;
	case JUDGEMENT:
		for (int i = 1; i < 15; i++) {
			for (int j = 1; j < 7; j++) {
				same(j, i);
				if (countCollision() > 3) {
					makePang();
					_gameState = PANG;
				}
				boardClear();
			}
		}

		if (_gameState == JUDGEMENT) {
			//마녀에게 데미지
			_witch->setHp(_witch->getHp() - _combo);
			//뿌요 초기화
			_gameState = CONTROL;
			_puyoState = NOTCOLLISION;
			makePuyo();
			_angle = 0;
			_angleEnd = PI / 2;
			_combo = 0;
			
		}
		break;
	case PANG:
		//보드의 컬러가 9이면 팡이기 떄문에 여기서 터트려줌
		for (int i = 1; i < 15; i++) {
			for (int j = 1; j < 7; j++) {
				if (_board[i][j].color == 9) {
					switch (_board[i][j].color1) {
					case 1:
						EFFECTMANAGER->play("레드팡", _puyoManager->getVPuyo()[_board[i][j].index]->getX()+30, _puyoManager->getVPuyo()[_board[i][j].index]->getY()+30);
						break;
					case 2:
						EFFECTMANAGER->play("블루팡", _puyoManager->getVPuyo()[_board[i][j].index]->getX() + 30, _puyoManager->getVPuyo()[_board[i][j].index]->getY()+30);
						break;
					case 3:
						EFFECTMANAGER->play("그린팡", _puyoManager->getVPuyo()[_board[i][j].index]->getX() + 30, _puyoManager->getVPuyo()[_board[i][j].index]->getY() + 30);
						break;
					case 4:
						EFFECTMANAGER->play("옐로우팡", _puyoManager->getVPuyo()[_board[i][j].index]->getX() + 30, _puyoManager->getVPuyo()[_board[i][j].index]->getY() + 30);
						break;
					case 5:
						EFFECTMANAGER->play("퍼플팡", _puyoManager->getVPuyo()[_board[i][j].index]->getX() + 30, _puyoManager->getVPuyo()[_board[i][j].index]->getY() + 30);
						break;
					}
					_puyoManager->removePuyo(_board[i][j].index);
					indexDecrease(_board[i][j].index);
					_board[i][j].index = 0;
					_board[i][j].color = 0;
					_board[i][j].color1 = 0;
					_index--;
				}
			}
		}
		


		//터지고 나서 공백부분 카운트
		if (!_isZeroCount) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 16; j++) {
					_board[j][i].zero = false;
				}
			}

			for (int i = 1; i < 7; i++) {
				for (int j = 1; j < 15; j++) {
					zeroCount(i, j);
				}
			}
			for (int i = 1; i < 7; i++) {
				for (int j = 1; j < 15; j++) {
					if (_board[j][i].zero) {
						_board[j][i].zeroCountY = _puyoManager->getVPuyo()[_board[j][i].index]->getY() + _board[j][i].zeroCount * 60;
					}
				}
			}
			_isZeroCount = true;
		}


		//공백부분 채워줌
		for (int i = 1; i < 7; i++) {
			for (int j = 15; j > 0; j--) {
				if (_board[j][i].zero) {
					_puyoManager->getVPuyo()[_board[j][i].index]->setY(_puyoManager->getVPuyo()[_board[j][i].index]->getY() + 5);
					if (_board[j][i].zeroCountY < _puyoManager->getVPuyo()[_board[j][i].index]->getY()) {
						_board[j][i].zero = false;
						_puyoManager->getVPuyo()[_board[j][i].index]->setY((boardYTopuyoY(puyoYToboardY(_puyoManager->getVPuyo()[_board[j][i].index]->getY()))));
					}
				}
			}
		}

		//zero개수가 0이면
		_zeroNum = 0;
		for (int i = 1; i < 7; i++) {
			for (int j = 15; j > 0; j--) {
				if (_board[j][i].zero)
					_zeroNum++;
			}
		}

		//zero
		if (_zeroNum == 0) {
			for (int i = 1; i < 7; i++) {
				for (int j = 14; j > 0; j--) {
					if (_board[j][i].zeroCount != 0) {
						_board[j + _board[j][i].zeroCount][i].index = _board[j][i].index;
						_board[j + _board[j][i].zeroCount][i].color = _board[j][i].color;
						_board[j + _board[j][i].zeroCount][i].color1 = _board[j][i].color1;
						_board[j][i].zeroCount = 0;
						_board[j][i].color = 0;
						_board[j][i].color1 = 0;
						_board[j][i].index = 0;

					}
				}
			}

		}

		
		if (_zeroNum == 0) {
			//한번더 팡이 될수있는지 판단
			_gameState = JUDGEMENT;
			//콤보 카운트
			_combo+=3;
			//제로카운트실행 off
			_isZeroCount = false;
		}
		break;
	}
}




void board::render() {
	for (int i = 0; i < _puyoManager->getVPuyo().size(); i++) {
		_puyoManager->getVPuyo()[i]->render();
	}
	_img->render(getMemDC(), 0, 0);
	_img->render(getMemDC(), WINSIZEX/2+40, 0);
	
}
void board::release() {}

void board::randomPuyo() {
	switch (RND->getFromIntTo(1, 5)) {
	case 1:
		_puyoManager->makeRed();
		break;
	case 2:
		_puyoManager->makeBlue();
		break;
	case 3:
		_puyoManager->makeYellow();
		break;
	case 4:
		_puyoManager->makeGreen();
		break;
	case 5:
		_puyoManager->makePurple();
		break;
	}
}

void board::makePuyo() {
	randomPuyo();
	_puyo1 = _puyoManager->getVPuyo()[_puyoManager->getVPuyo().size() - 1];
	_puyo1->setX(180);
	_puyo1->setY(0);
	_index++;

	randomPuyo();
	_puyo2 = _puyoManager->getVPuyo()[_puyoManager->getVPuyo().size() - 1];
	_puyo2->setX(180);
	_puyo2->setY(-60);
	_index++;
}

int board::puyoXToboardX(float x) {
	if (0 <= x&&x < 60) return 0;
	if (60 <= x && x < 120) return 1;
	if (120 <= x && x < 180) return 2;
	if (180 <= x && x < 240) return 3;
	if (240 <= x && x < 300) return 4;
	if (300 <= x && x < 360) return 5;
	if (360 <= x && x < 420) return 6;
	if (420 <= x && x < 480) return 7;
}
int board::puyoYToboardY(float y) {

	if (780 <= y && y < 840)		return 15;
	if (720 <= y && y < 780)		return 14;
	if (660 <= y && y < 720)		return 13;
	if (600 <= y && y < 660)		return 12;
	if (540 <= y && y < 600)		return 11;
	if (480 <= y && y < 540)		return 10;
	if (420 <= y && y < 480)		return 9;
	if (360 <= y && y < 420)		return 8;
	if (300 <= y && y < 360)		return 7;
	if (240 <= y && y < 300)		return 6;
	if (180 <= y && y < 240)		return 5;
	if (120 <= y && y < 180)		return 4;
	if (60 <= y && y < 120)			return 3;
	if (0 <= y && y < 60)			return 2;
	if (-60 <= y && y < 0)			return 1;
	if (-120 <= y && y < -60)		return 0;

}


int board::boardXTopuyoX(int x) {
	if (x == 0) return 0;
	if (x == 1) return 60;
	if (x == 2) return 120;
	if (x == 3) return 180;
	if (x == 4) return 240;
	if (x == 5) return 300;
	if (x == 6) return 360;
	if (x == 7) return 420;
}
int board::boardYTopuyoY(int y) {
	if (y == 0) return -120;
	if (y == 1) return -60;
	if (y == 2) return 0;
	if (y == 3) return 60;
	if (y == 4) return 120;
	if (y == 5) return 180;
	if (y == 6) return 240;
	if (y == 7) return 300;
	if (y == 8) return 360;
	if (y == 9) return 420;
	if (y == 10) return 480;
	if (y == 11) return 540;
	if (y == 12) return 600;
	if (y == 13) return 660;
	if (y == 14) return 720;
	if (y == 15) return 780;
}

void board::same(int x, int y) {
	if ((_board[y][x].color == _board[y - 1][x].color) && !_board[y - 1][x].collision && _board[y][x].color != 0 && _board[y][x].color != 10) {
		_board[y - 1][x].collision = true;
		same(x, y - 1);
	}
	if ((_board[y][x].color == _board[y][x - 1].color) && !_board[y][x - 1].collision&& _board[y][x].color != 0 && _board[y][x].color != 10) {
		_board[y][x - 1].collision = true;
		same(x - 1, y);
	}
	if ((_board[y][x].color == _board[y + 1][x].color) && !_board[y + 1][x].collision&& _board[y][x].color != 0 && _board[y][x].color != 10) {
		_board[y + 1][x].collision = true;
		same(x, y + 1);
	}
	if ((_board[y][x].color == _board[y][x + 1].color) && !_board[y][x + 1].collision&& _board[y][x].color != 0 && _board[y][x].color != 10) {
		_board[y][x + 1].collision = true;
		same(x + 1, y);
	}
}

void board::boardClear() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			_board[i][j].collision = false;
		}
	}
}

int board::countCollision() {
	int count = 0;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			if (_board[i][j].collision) count++;
		}
	}
	return count;
}

void board::makePang() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			if (_board[i][j].collision) _board[i][j].color = 9;
		}
	}
}

void board::indexDecrease(int index) {
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 7; j++) {
			if (_board[i][j].index == index) continue;
			if (_board[i][j].index>index) {
				_board[i][j].index--;
			}
		}
	}
}

void board::boardZeroCountClear()
{
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			_board[i][j].zeroCount = 0;
		}
	}
}

void board::zeroCount(int x,int y) {
	for (int i = 0; i < 16; i++) {
		if (y < i) {
			if (_board[i][x].color == 0 && _board[y][x].color!=0) {
				_board[y][x].zeroCount++;
				_board[y][x].zero = true;
			}
		}
	}
}

void board::color1Clear() {
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 8; j++) {
			_board[i][j].color1 = 0;
		}
	}
}