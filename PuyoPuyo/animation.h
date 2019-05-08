#pragma once
#include <vector>

//=================================
// ## animation ## 2015.08.12
//=================================

class animation
{
public:
	//������ ������ ���� ������ �����ؾ��ϹǷ� public����~
	typedef vector<POINT> _vFrameList;
	//������ �÷��� ����Ʈ
	typedef vector<int> _vPlayList;

private:
	int _frameNum;

	_vFrameList _frameList;
	_vPlayList _playList;

	int _frameWidth;
	int _frameHeight;

	BOOL _loop;

	float _frameUpdateSec;
	float _elapsedSec;

	DWORD _nowPlayIdx;
	BOOL _play;


public:
	animation();
	~animation();

	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	void release(void);

	//�׳� �Ϲ� ������ ���
	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);

	//�迭�� ��Ƽ� ������ ���
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);

	//������ ���۰� ���� ������ ������ ���
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);

	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start(void);
	void stop(void);
	void pause(void);
	void resume(void);


	//�÷��� ���� Ȯ��
	inline BOOL isPlay(void) { return _play; }

	//������ ��ġ ��������
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIdx]]; }

	//������ ����ũ�� ������
	inline int getFrameWidth(void) { return _frameWidth; }

	//������ ����ũ�� ������
	inline int getFrameHeight(void) { return _frameHeight; }
};

