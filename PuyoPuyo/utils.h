#pragma once
#include <cmath>

#define DEG_TO_RAD 0.017453f //1도의 라디안 값
#define PI 3.141592654f
#define PI2 (PI * 2)

#define FLOAT_EPSILON 0.001f //실수의 가장 작은 단위를 그리스어로 엡실론 입실론이라고 함

namespace DENIALBOY_UTIL	//원하는대로
{
	//거리 가져오는 공식
	float getDistance(float startX, float startY, float endX, float endY);

	//각도 가져오는 공식
	float getAngle(float x1, float y1, float x2, float y2);

	//미니맵 만들기
	void minimapRender(HDC hdc, int rate, int bgWidth, int bgHeight);
}