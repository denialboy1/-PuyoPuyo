#pragma once
#include "singletonBase.h"
#include <bitset>

//눌러질 수 있는 키 전부 등록
#define KEYMAX 256

using namespace std;

class keyManager : public singletonBase<keyManager>
{
private:
	bitset<KEYMAX> _keyUp;
	bitset<KEYMAX> _keyDown;

public:
	HRESULT init(void);
	void release(void);

	//키를 한번 누르면
	bool isOnceKeyDown(int key);
	//눌렀다 때면
	bool isOnceKeyUp(int key);
	//키를 누르고 있으면
	bool isStayKeyDown(int key);
	//한번 누르면 계속 켜져있으면
	bool isToggleKey(int key);

	bitset<KEYMAX> getKeyUp() { return _keyUp; }
	bitset<KEYMAX> getKeyDown() { return _keyDown; }

	void setKeyDown(int key, bool state) { _keyDown.set(key, state); }
	void setKeyUp(int key, bool state) { _keyUp.set(key, state); }

	keyManager();
	~keyManager();
};

