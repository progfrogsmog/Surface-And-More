#include "Simulation.h"
#include <math.h>

void Simulation::Update(const float dt)
{
	nCurRad -= dt * speed;
	if (nCurRad <= -2*PI)
	{
		nCurRad += 2*PI;
	}
	circlePos.x = offset.x + 98*cos(nCurRad);  //98 from circle center
	circlePos.y = offset.y + 98*sin(nCurRad);

	for (Vec2& pix : arrLine)
	{
		pix.x -= 50 * dt;
	}
	for (Vec2& pix : arrLine)
	{
		if (pix.x <= 0)
		{
			pix.x = 500;
			pix.y = circlePos.y;
			break;
		}
	}
}

void Simulation::Draw(Graphics& gfx)
{
	gfx.DrawCircle(offset, 100, Colors::Blue);
	gfx.DrawCircle(offset,  98, Colors::Black);
	gfx.DrawLine(offset, Vei2(circlePos), Colors::White);//line from circle center to cur Pos
	for (Vec2& pix : arrLine)
	{
		if (pix.x >= 0)
		{
			gfx.PutPixel(pix.x + offset.x, pix.y, Colors::Green);
		}
	}
	gfx.DrawLine(circlePos, Vei2(offset.x + 500, circlePos.y), Colors::Red);
}
