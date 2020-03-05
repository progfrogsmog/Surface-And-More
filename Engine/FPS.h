#include "Graphics.h"
#include "Font.h"

class FPS
{
public:
	FPS(Font& font);
	void Update(float dt);
	void Draw(Vei2& pos, const Color& subColor, Graphics& gfx) const;
private:
	Font& font;
	int nCurFrames = 0;
	int nLastFrames = 0;
	float nCurTime = 0.0f;
	float nHoldTime = 1.0f;
};