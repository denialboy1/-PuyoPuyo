#pragma once
#include "singletonBase.h"
#include "image.h"

class destroyPixelManager : public singletonBase<destroyPixelManager>
{
public:
	destroyPixelManager();
	~destroyPixelManager();

	// ÇÈ¼¿Å©±âÆÄ±«(ÆÄ±«ÇÒ ÁÂÇ¥, Ä¥ÇØÁÙ »ö±ò, Ä¥ÇÒ ÀÌ¹ÌÁö)
	void destroyPixel(int x, int y, COLORREF rgb, image* img);
	//¿øÅ©±âÆÄ±«(ÆÄ±«ÇÒ ÁÂÇ¥,Ä¥ÇØÁÙ »ö±ò, Ä¥ÇÒ ÀÌ¹ÌÁö)
	void destroyEllipse(int x, int y, int width, int hiehgt, COLORREF rgb, image* img);
	//»ç°¢ÇüÅ©±âÆÄ±«(ÆÄ±«ÇÒ ÁÂÇ¥,Ä¥ÇØÁÙ »ö±ò, Ä¥ÇÒ ÀÌ¹ÌÁö)
	void destroyRect(int x, int y, int width, int height, COLORREF rgb, image* img);
};

