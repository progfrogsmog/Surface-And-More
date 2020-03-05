#pragma once
#include "Surface.h"
#include <vector>
#include "Graphics.h"


class Font
{
public:
	Font(const std::string filename, int charColumns, int charRows, Color chroma);
	void Draw(Vei2& pos, const std::string& text, const Color& subColor, Graphics& gfx) const;
	int GetGlyphWidth();
	int GetGlyphHeight();
private:
	RectI CalcCharRect(const char& c) const;
private:
	const Color chroma;
	const Surface sprite;
	const int GlyphWidth;
	const int GlyphHeight;
	const int charColumns;
	const int charRows;
	const char firstChar = ' ';
	const char lastChar = '~';
};