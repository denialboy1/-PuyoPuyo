#pragma once
#include "gameNode.h"

class progressBar : public gameNode
{
private:
	RECT _rcProgress;
	int _x, _y;
	float _width;

	image* _progressBarForward;
	image* _progressBarBack;

public:
	HRESULT init(int x, int y, int width, int height);
	void release(void);
	void update(void);
	void render(void);

	//ü�¹� ������
	void gauge(float currentGauge, float maxGauge);

	//��ǥ
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }


	progressBar();
	~progressBar();
};

