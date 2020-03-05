#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Font.h"

class InWnd
{
public:
	InWnd(const Vei2& pos, int width, Font& font);
	void Draw(Graphics& gfx);
	void Update(float dt);  //only if selected >> isSelected and cursorPos have to be assigned in game.cpp when mouseClick on Rect
	void UpdateText(const char c);
	void SetBackgroundColor(const Color& c);
	RectI GetRect() const;  // InWnd Rect NON-border
	void OnClick(const Vei2& clickPos);  //

public:
	Vei2 pos;
	int width;
	int height;


private:
	Font& font;
	std::string text = "";
	float cursorTime = 0.0f;  //cursor lifetime
	float cursorHoldTime = 0.5f;  //if reaches max toggle showCursor
	bool showCursor = true;
	bool isSelected = false;
	int cursorX = 0;

	/*EXTRA*/
	Color backgroundColor = Colors::Gray;
	Color borderColor = Colors::White;
	Color fontColor = Colors::White;
	int borderExtension = 0;
	/*EXTRA*/
};