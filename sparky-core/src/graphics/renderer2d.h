#ifndef RENDERER2D_H
#define RENDERER2D_H

#include <GL/glew.h>
#include "../math/math.h"
#include "renderable2d.h"

namespace Sparky { namespace Graphics {

	class Renderer2D
	{
	protected:
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void flush() = 0;
	};

}}

#endif
