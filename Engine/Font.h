#pragma once
#include "Surface.h"
#include <vector>
#include "Graphics.h"


class Font
{
public:
	Font(const std::string& str, const std::string filename, int charWidth, int charHeight, Color chroma);
	void Draw(Vei2& pos, const Color& subColor, Graphics& gfx) const;
private:
	RectI CalcCharRect(const Vei2& topLeft) const;
private:
	const Color chroma;
	const Surface sprite;
	std::vector<RectI> text;
	const int GlyphWidth;
	const int GlyphHeight;
	const char firstChar = ' ';
	const char lastChar = '~';
};