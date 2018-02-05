#ifndef RENDERER2D_H
#define RENDERER2D_H

#include <GL/glew.h>
#include "../math/math.h"
#include "renderable2d.h"

namespace Sparky { namespace Graphics {

	class Renderer2D
	{
	public:
		virtual ~Renderer2D() {}
		virtual void begin() {}
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void end() {}
		virtual void flush() = 0;
	};

}}

#endif
