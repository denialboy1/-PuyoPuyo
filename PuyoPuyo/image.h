#pragma once
#include "animation.h"
//====================================================
// 2015.05.08 ## image Class ## - Thursday Of Blood -
//====================================================

class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,	//리소스로부터 생성
		LOAD_FILE,			//파일로부터 생성
		LOAD_EMPTY,			//걍 생성
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD resID;
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		int x;
		int y;
		int width;
		int height;

		int currentFrameX;		//현재 프레임X
		int currentFrameY;		//현재 프레임Y
		int maxFrameX;			//최대 프레임X
		int maxFrameY;			//최대 프레임Y
		int frameWidth;			//프레임 가로크기
		int frameHeight;		//프레임 세로크기

		BYTE loadType;
		RECT boundingBox;		//이미지에 바로 렉트씌우려면 쓸것

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = LOAD_RESOURCE;
			boundingBox = RectMake(0, 0, 0, 0);
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	//생성과 동시에 멤버이니셜 라이즈로 바로 초기화 해주는 변쑤
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;
	BOOL			_trans;
	COLORREF		_transColor;

	BLENDFUNCTION	_blendFunc;		//알파블렌드를 위한 정보
	LPIMAGE_INFO	_blendImage;	//알파블렌드를 사용하기 위한 이미지 정보

public:
	image();
	~image();

	//빈 비트맵 이미지 만든다
	HRESULT init(int width, int height);

	//리소스로부터 읽어본다
	HRESULT init(const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	//이미지 설정(파일로부터 읽어옴)
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	//이미지 + 프레임 파일 초기화
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY,
		BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));


	//삭제
	void release(void);

	//투명 키값(RGB값) 셋팅 == 특정색상을 정해서 날려줌
	void setTransColor(BOOL trans, COLORREF transColor);

	//렌더
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int sourX, int sourY,
		int sourWidth, int sourHeight);

	//프레임 렌더
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//뤂렌더
	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	//알파렌더
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//알파프레임렌더
	void alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);

	//애니렌더
	void aniRender(HDC hdc, int destX, int destY, animation* ani);


	//DC 얻어온다
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }

	//좌표 X
	inline void setX(float x) { _imageInfo->x = x; }
	inline float getX(void) { return _imageInfo->x; }

	//좌표 Y
	inline void setY(float y) { _imageInfo->y = y; }
	inline float getY(void) { return _imageInfo->y; }

	//좌표 x y
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	//중점 x
	inline float getCenterX(void)
	{
		return _imageInfo->maxFrameX <= 0 ? _imageInfo->x + (_imageInfo->width / 2) :
			_imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	//중점 y
	inline float getCenterY(void)
	{
		return _imageInfo->maxFrameY <= 0 ? _imageInfo->y + (_imageInfo->height / 2) :
			_imageInfo->y + (_imageInfo->frameHeight / 2);
	}

	//가로 해상도
	inline int getWidth(void) { return _imageInfo->width; }

	//세로 해상도
	inline int getHeight(void) { return _imageInfo->height; }

	//바운딩 박스
	inline RECT boundingBox(void)
	{
		RECT rc = { int(_imageInfo->x - (_imageInfo->width / 2)),
			int(_imageInfo->y - (_imageInfo->height / 2)),
			int(_imageInfo->x + (_imageInfo->frameWidth / 2)),
			int(_imageInfo->y + (_imageInfo->frameHeight / 2)) };

		return rc;
	}


	//프레임
	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX) _imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}

	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY) _imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }

	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

};