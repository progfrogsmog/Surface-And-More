#include "Graphics.h"

namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma(const Color c)
			:
			chroma(c)
		{}
		void operator()(const Vei2& pos, const Color& cSrc, Graphics& gfx) const
		{
			if (chroma != cSrc)
			{
				gfx.PutPixel(pos.x, pos.y, cSrc);
			}
		}
	private:
		Color chroma;
	};

	class Substitute
	{
	public:
		Substitute(const Color& c, const Color& s)
			:
			chroma(c),
			sub(s)
		{}
		void operator()(const Vei2& pos, const Color& cSrc, Graphics& gfx)
		{
			if (chroma != cSrc)
			{
				gfx.PutPixel(pos.x, pos.y, sub);
			}
		}
	private:
		Color chroma;
		Color sub;
	};

	class Ghost
	{
	public:
		Ghost(const Color& c):
			chroma(c)
		{}

		void operator()(const Vei2& pos, const Color& cSrc, Graphics& gfx)
		{
			Color background = gfx.GetPixel(pos.x, pos.y);
			background.Mix(cSrc);
			if (chroma != cSrc)
			{
				gfx.PutPixel(pos.x, pos.y, background);
			}
		}
	private:
		Color chroma;
	};

	class Copy
	{
	public:
		void operator()(const Vei2& pos, const Color& cSrc, Graphics& gfx)
		{
			gfx.PutPixel(pos.x, pos.y, cSrc);
		}
	private:
	};
}