#include "Surface.h"
#include <cassert>
#include "ChiliWin.h"
#include <fstream>

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

Surface::Surface(const std::string filename)
{
	std::ifstream file(filename, std::ios::binary);
	assert(file);

	BITMAPFILEHEADER bmFileHeader;
	file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));
	assert(bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
	assert(bmInfoHeader.biCompression == BI_RGB);

	width = bmInfoHeader.biWidth;
	int yStart;
	int yEnd;
	int dy;
	if (bmInfoHeader.biHeight < 0)
	{
		height = -bmInfoHeader.biHeight;
		yStart = 0;
		yEnd = height;
		dy = 1;
	}
	else
	{
		height = bmInfoHeader.biHeight;
		yStart = height - 1;
		yEnd = -1;
		dy = -1;
	}
	pPixels = new Color[width * height];


	file.seekg(bmFileHeader.bfOffBits);
	const int padding = (4 - (3 * width) % 4) % 4;

	for (; yStart != yEnd; yStart += dy)
	{
		for (int x = 0; x < width; x++)
		{
			pPixels[yStart*width + x] = Color( file.get(),file.get(),file.get() );
			if (bmInfoHeader.biBitCount == 32)
			{
				file.seekg(1,std::ios::cur);
			}
		}
		if (!(bmInfoHeader.biBitCount == 32))
		{
			file.seekg(padding, std::ios::cur);
		}
	}
}

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

RectI Surface::GetRect() const
{
	return {0,width,0,height};
}

void Surface::PutPixel(int x, int y, Color c)
{
	pPixels[y * width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	return pPixels[y * width + x];
}
