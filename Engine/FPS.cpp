#include "FPS.h"

FPS::FPS(Font& font)
	:
	font(font)
{}

void FPS::Update(float dt)
{
	nCurTime += dt;
	nCurFrames++;
	if (nCurTime >= nHoldTime)
	{
		nCurTime -= 1.0f;
		nLastFrames = nCurFrames;
		nCurFrames = 0;
	}
}

void FPS::Draw(Vei2& pos, const Color& subColor, Graphics& gfx) const
{
	font.Draw(pos, std::to_string(nLastFrames), subColor, gfx);
}
