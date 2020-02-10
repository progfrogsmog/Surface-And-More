#pragma once
#include "Animation.h"
#include "Vec2.h"

class Character
{
private:
	enum Sequence
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};
public:
	Character(Vec2 pos);
	void Update(float dt, const Vec2 vel);
	void Draw(Graphics& gfx) const;
private:
	Surface sprite{"link90x90.bmp"};
	std::vector<Animation> animations;
	Vec2 pos;
	Vec2 vel = { 0,0 };
	float speed = 150.0f;
	Sequence doing = StandingDown;
};