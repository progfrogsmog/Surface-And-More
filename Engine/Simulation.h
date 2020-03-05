#pragma once
#include "Vec2.h"
#include "Graphics.h"

constexpr auto PI = 3.1415926535;
class Simulation
{
public:
	void Update(const float dt);
	void Draw(Graphics& gfx);
private:
	Vei2 offset = Vei2(200, 300);  //circle center for draw
	const float speed = PI/2;
	float nCurRad = 0.0f;
	Vec2 circlePos = Vec2(0,0);
	Vec2 arrLine[600] = {Vec2(400.0f,0.0f)};
};