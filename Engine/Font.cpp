#include "Font.h"
#include <assert.h>
#include "SpriteEffect.h"

Font::Font(const std::string filename, int charColumns, int charRows, Color chroma)
	:
	sprite(filename),
	chroma(chroma),
	GlyphWidth(sprite.GetWidth()/charColumns),
	GlyphHeight(sprite.GetHeight()/charRows),
	charColumns(charColumns),
	charRows(charRows)
{
	assert(sprite.GetWidth() == GlyphWidth * charColumns);
	assert(sprite.GetHeight() == GlyphHeight * charRows);
}

void Font::Draw(Vei2& pos, const std::string& text, const Color& subColor, Graphics& gfx) const
{
	Vei2 curPos = pos;
	for (char c : text)
	{
		if (c == '\n')
		{
			curPos.x = pos.x;
			curPos.y += GlyphHeight;
			continue;
		}
		if (c >= firstChar + 1 && c <= lastChar)
		{
			gfx.DrawSprite(curPos, CalcCharRect(c), sprite, SpriteEffect::Substitute(chroma,subColor));
		}
		curPos.x += GlyphWidth;
	}
}

int Font::GetGlyphWidth()
{
	return GlyphWidth;
}

int Font::GetGlyphHeight()
{
	return GlyphHeight;
}

RectI Font::CalcCharRect(const char& c) const
{
	int charIndex = c - firstChar;
	int top = charIndex / charColumns;
	int left = charIndex % charColumns;
	return RectI(Vei2(left*GlyphWidth,top*GlyphHeight),GlyphWidth,GlyphHeight);
}
