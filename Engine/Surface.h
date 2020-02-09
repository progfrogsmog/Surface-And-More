#pragma once
#include "Colors.h"
#include <string>
#include "RectI.h"

class Surface
{
public:
	Surface(const Surface& src);
	Surface(int width, int height);
	Surface(const std::string filename);
	Surface& operator=(const Surface& src);
	~Surface();
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
private:
	int width;
	int height;
	Color* pPixels;
};