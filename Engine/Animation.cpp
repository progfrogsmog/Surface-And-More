#include "Animation.h"
#include "SpriteEffect.h"

Animation::Animation(int x, int y, int width, int height, int count, float holdTime, const Surface& surf, const Color chroma)
	:
	sprite(surf),
	holdTime(holdTime),
	chroma(chroma)
{
	frames.reserve(count);
	for (int i = 0; i < count; i++)
	{
		frames.emplace_back(x + i * width, x + (i + 1) * width, y, y + height);
	}
}

void Animation::Update(float dt)
{
	currentTime += dt;
	while (currentTime >= holdTime)
	{
		Advance();
		currentTime -= holdTime;
	}
}

void Animation::Draw(Vei2& pos, Graphics& gfx) const
{
	gfx.DrawSprite(pos, frames[nCurFrame], sprite, SpriteEffect::Chroma(chroma));
}

void Animation::DrawGhost(Vei2& pos, Graphics& gfx) const
{
	gfx.DrawSprite(pos, frames[nCurFrame], sprite, SpriteEffect::Ghost(chroma));
}

void Animation::Draw(Vei2& pos, const RectI& clip, Graphics& gfx) const
{
	gfx.DrawSprite(pos, clip, frames[nCurFrame], sprite, SpriteEffect::Chroma(chroma));
}

void Animation::Advance()
{
	if (++nCurFrame >= frames.size())
	{
		nCurFrame = 0;
	}
}
