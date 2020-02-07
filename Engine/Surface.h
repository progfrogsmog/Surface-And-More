#pragma once
#include "Colors.h"

class Surface
{
public:
	Surface(const Surface& src);
	Surface(int width, int height);
	Surface& operator=(const Surface& src);
	~Surface();
	int GetWidth() const;
	int GetHeight() const;
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
private:
	int width;
	int height;
	Color* pPixels;
};