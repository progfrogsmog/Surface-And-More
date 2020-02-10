#include "Character.h"

Character::Character(Vec2 pos)
	:
	pos(pos)
{
	int x = 90;
	int y = 0; 
	int width = 90;
	int height = 90;

	for (int i = WalkingLeft; i < StandingLeft; i++)
	{
		animations.emplace_back(x, y+i*height, width, height, 4, 0.16f, sprite);
	}
	for (int i = StandingLeft; i < Count; i++)
	{
		animations.emplace_back(0, y + (i - (int)StandingLeft) * height, width, height, 1, 0.16f, sprite);
	}
}

void Character::Update(float dt, const Vec2 vel)
{
	animations[int(doing)].Update(dt);
	if (this->vel != vel)
	{
		if (vel.x > 0)
		{
			doing = WalkingRight;
		}
		else if (vel.x < 0)
		{
			doing = WalkingLeft;
		}
		else if (vel.y > 0)
		{
			doing = WalkingDown;
		}
		else if (vel.y < 0)
		{
			doing = WalkingUp;
		}
		else
		{
			if (this->vel.x > 0)
			{
				doing = StandingRight;
			}
			else if (this->vel.x < 0)
			{
				doing = StandingLeft;
			}
			else if (this->vel.y > 0)
			{
				doing = StandingDown;
			}
			else if (this->vel.y < 0)
			{
				doing = StandingUp;
			}
		}
		this->vel = vel;
	}
	pos += vel * speed * dt;
}

void Character::Draw(Graphics& gfx) const
{
	animations[int(doing)].Draw((Vei2)pos, gfx);
}
