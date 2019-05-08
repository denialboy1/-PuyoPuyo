#include "stdafx.h"
#include "utils.h"


namespace DENIALBOY_UTIL	//���ϴ´��
{
	//�Ÿ� �������� ����
	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf(x * x + y * y);
	}

	//���� �������� ����
	float getAngle(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		float distance = sqrtf(x * x + y * y);
		float angle = acosf(x / distance);

		if (y > 0) angle = PI2 - angle;

		return angle;
	}

	//�̴ϸ� �����
	void minimapRender(HDC hdc, int rate, int bgWidth, int bgHeight)
	{
		StretchBlt(hdc, bgWidth - bgWidth / rate, 0, bgWidth / rate, bgHeight / rate, hdc, 0, 0, bgWidth, bgHeight, SRCCOPY);
		LineMake(hdc, bgWidth - bgWidth / rate, 0, bgWidth - bgWidth / rate, bgHeight / rate);
		LineMake(hdc, bgWidth - bgWidth / rate, bgHeight / rate, bgWidth, bgHeight / rate);
	}
}