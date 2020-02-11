#include "Font.h"
#include <assert.h>

Font::Font(const std::string& str, const std::string filename, int charWidth, int charHeight, Color chroma)
	:
	sprite(filename),
	chroma(chroma),
	GlyphWidth(sprite.GetWidth()/charWidth),
	GlyphHeight(sprite.GetHeight()/charHeight)
{
	assert(sprite.GetWidth() == GlyphWidth * charWidth);
	assert(sprite.GetHeight() == GlyphHeight * charHeight);
	text.reserve(str.size());

	for (int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (c >= firstChar + 1 && c <= lastChar)
		{
			int charIndex = c - firstChar;
			int top = charIndex / charWidth;
			int left = charIndex % charWidth;
			text.emplace_back(CalcCharRect(Vei2(left * GlyphWidth, top * GlyphHeight)));//SHIT LEFT,TOP
			continue;
		}
		text.emplace_back(CalcCharRect(Vei2(0,0)));
	}
}

void Font::Draw(Vei2& pos, const Color& subColor, Graphics& gfx) const
{
	for (int i = 0; i < text.size(); i++)
	{
		gfx.DrawSpriteSubstitute(pos, text[i], sprite, subColor, chroma);
		pos.x += GlyphWidth;
	}
}

RectI Font::CalcCharRect(const Vei2& topLeft) const
{
	return RectI(topLeft,GlyphWidth,GlyphHeight);
}
