#ifndef SPRITE_H
#define SPRITE_H

#include "renderable2d.h"

namespace Sparky { namespace Graphics {

	class Sprite : public Renderable2D
	{
	private:

	public:
		Sprite(float x, float y, float width, float height, const Math::vec4& color);
		~Sprite();
	};

}}

#endif
