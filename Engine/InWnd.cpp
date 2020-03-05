#include "InWnd.h"

InWnd::InWnd(const Vei2& pos, int width, Font& font)
	:
	pos(pos),
	width(width),
	font(font)
{
	height = font.GetGlyphHeight();
}

void InWnd::Draw(Graphics& gfx)
{
	gfx.DrawRect(pos.x, pos.y, width, height, backgroundColor);  //background
	font.Draw(pos, text, Colors::White, gfx);  //text
	if (showCursor)
	{
		gfx.DrawRect(pos.x + cursorX, pos.y, 1, font.GetGlyphHeight(), fontColor);  //cursor
	}
}

void InWnd::Update(float dt)  //cursor blinking and Highlight
{
	if (isSelected)
	{
		//Update Cursor
		cursorTime += dt;
		if (cursorTime >= cursorHoldTime)
		{
			cursorTime -= cursorHoldTime;
			showCursor = !showCursor;
		}
		//? Highlight as active ?

		//
	}
}

void InWnd::UpdateText(const char c)
{
	if (isSelected)  //if active
	{
		if (c == '\r' || c == 27)  //unselect
		{
			isSelected = false;
			showCursor = false;
			return;
		}
		else if (c > 31 && c < 127)  //add char
		{
			text.push_back(c);
		}
		else if (c == 8 && text.length() > 0)  //remove last
		{
			text.pop_back();
		}
		cursorX = text.length() * font.GetGlyphWidth();
	}
}

void InWnd::SetBackgroundColor(const Color& c)
{
	backgroundColor = c;
}

void InWnd::OnClick(const Vei2& clickPos)  //onClick select = true; assign cursorX;
{
	if (GetRect().Contains(clickPos))  //click Wnd
	{
		isSelected = true;  //select

		//calculate cursorPos
		int xPos = clickPos.x - pos.x;  //pos in wnd
		int xGlyph = xPos / font.GetGlyphWidth();  //place cursor to char

		if (xGlyph > text.length())
		{
			xGlyph = text.length();  //cursor to last char (in pos)
		}
		cursorX = xGlyph * font.GetGlyphWidth();  //multiply to (in pxl)
	}
	else  //if not on Wnd
	{
		isSelected = false;
		showCursor = false;
	}
}

RectI InWnd::GetRect() const
{
	return RectI(pos, width, height);
}
