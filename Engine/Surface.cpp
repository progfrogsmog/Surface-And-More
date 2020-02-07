#include "Surface.h"

Surface::Surface(const Surface& src)
	:
	Surface(src.width, src.height)
{
	for (int i = 0; i < width * height; i++)
	{
		pPixels[i] = src.pPixels[i];
	}
}

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width*height])
{}

Surface& Surface::operator=(const Surface& src)
{
	width = src.width;
	height = src.height;

	delete[] pPixels;
	pPixels = new Color[width * height];

	for (int i = 0; i < width * height; i++)
	{
		pPixels[i] = src.pPixels[i];
	}

	return *this;
}

Surface::~Surface()
{
	delete[] pPixels;
	pPixels = nullptr;
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

void Surface::PutPixel(int x, int y, Color c)
{
	pPixels[y * width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	return pPixels[y * width + x];
}
