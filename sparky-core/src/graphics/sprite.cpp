#include "sprite.h"

namespace Sparky { namespace Graphics {

	Sprite::Sprite(float x, float y, float width, float height, const Math::vec4& color)
		: Renderable2D(Math::vec3(x, y, 0), Math::vec2(width, height), color)
	{

	}

	Sprite::~Sprite() {}

}}
