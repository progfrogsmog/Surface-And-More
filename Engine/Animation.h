#pragma once
#include "Surface.h"
#include "Graphics.h"
#include <vector>

class Animation
{
public:
	Animation(int x, int y, int width, int height, int count, float holdTime, const Surface& surf, const Color chroma = Colors::Magenta);
	void Update(float dt);
	void Draw(Vei2& pos, Graphics& gfx) const;
	void DrawGhost(Vei2& pos, Graphics& gfx) const;
	void Draw(Vei2& pos, const RectI& clip, Graphics& gfx) const;
private:
	void Advance();
private:
	const Color chroma;
	const Surface& sprite;
	std::vector<RectI> frames;
	int nCurFrame = 0;
	float holdTime;
	float currentTime = 0.0f;
};