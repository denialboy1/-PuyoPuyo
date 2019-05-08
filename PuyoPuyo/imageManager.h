#pragma once
#include "singletonBase.h"
#include "image.h"
#include <map>

class imageManager : public singletonBase<imageManager>
{
public:
	typedef map<string, image*> mapImageList;			//�̹��� ����Ʈ ��
	typedef map<string, image*>::iterator mapImageIter;	//�̹��� ����Ʈ ���ͷ�����

private:
	mapImageList _mImageList;	//������ ������ �̹��� ����Ʈ

public:
	HRESULT init();

	void release();

	image* addImage(string strKey, int width, int height);

	image* addImage(string strKey, const DWORD resID,
		int width, int height, bool trans, COLORREF transColor);

	image* addImage(string strKey, const char* fileName,
		int width, int height, bool trans, COLORREF transColor);

	image* addImage(string strKey, const char* fileName, 
		float x, float y, int width, int height, bool trans, COLORREF transColor);

	//������ �̹���
	image* addFrameImage(string strKey, const char* fileName, float x, float y,
		int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);

	image* addFrameImage(string strKey, const char* fileName, int width, int height,
		int frameX, int frameY, bool trans, COLORREF transColor);


	//�̹��� ã�� �Լ�
	image* findImage(string strKey);

	//�̹��� �����
	BOOL deleteImage(string strKey);

	BOOL deleteAll(void);

	//�����Լ�
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY,
		int sourX, int sourY, int sourWidth, int sourHeight);

	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);


	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);
	
	void alphaFrameRender(string strKey, HDC hdc, int destX, int destY);
	void alphaFrameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	imageManager();
	~imageManager();
};
