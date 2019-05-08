#include "stdafx.h"
#include "destroyPixelManager.h"


destroyPixelManager::destroyPixelManager()
{
}


destroyPixelManager::~destroyPixelManager()
{
}

void destroyPixelManager::destroyPixel(int x, int y, COLORREF rgb, image* img) {
	SetPixel(img->getMemDC(), x, y, rgb);
}

void destroyPixelManager::destroyEllipse(int x, int y, int width, int height, COLORREF rgb, image* img) {
	HBRUSH hBrush, hOldBrush;
	HPEN hPen, hOldPen;
	hBrush = CreateSolidBrush(rgb);
	hPen = CreatePen(PS_SOLID, 1, rgb);
	hOldBrush = (HBRUSH)SelectObject(img->getMemDC(), hBrush);
	hOldPen = (HPEN)SelectObject(img->getMemDC(), hPen);
	Ellipse(img->getMemDC(), x - width / 2, y - height / 2, x + width / 2, y + height / 2);
	SelectObject(img->getMemDC(),hOldBrush);
	SelectObject(img->getMemDC(), hOldPen);
	DeleteObject(hBrush);
	DeleteObject(hPen);
}

void destroyPixelManager::destroyRect(int x, int y,int width,int height, COLORREF rgb, image* img) {
	HBRUSH hBrush, hOldBrush;
	HPEN hPen, hOldPen;
	hBrush = CreateSolidBrush(rgb);
	hPen = CreatePen(PS_SOLID, 1, rgb);
	hOldBrush = (HBRUSH)SelectObject(img->getMemDC(), hBrush);
	hOldPen = (HPEN)SelectObject(img->getMemDC(), hPen);
	Rectangle(img->getMemDC(), x - width/2, y - height/2, x + width/2, y + height/2);
	SelectObject(img->getMemDC(), hOldBrush);
	SelectObject(img->getMemDC(), hOldPen);
	DeleteObject(hBrush);
	DeleteObject(hPen);
}