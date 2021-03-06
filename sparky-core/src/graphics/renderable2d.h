#ifndef RENDERABLE2D_H
#define RENDERABLE2D_H

#include "../math/math.h"
#include "buffers/buffer.h"
#include "buffers/indexBuffer.h"
#include "buffers/vertexArray.h"
#include "shader.h"
#include "renderer2d.h"

namespace Sparky { namespace Graphics {

	struct VertexData
	{
		Math::vec3 vertex;
		//Math::vec4 color;
		unsigned int color;
	};

	class Renderable2D
	{
	protected:
		Math::vec3 m_position;
		Math::vec2 m_size;
		Math::vec4 m_color;

	protected:
		Renderable2D() {}

	public:
		Renderable2D(Math::vec3 position, Math::vec2 size, Math::vec4 color);
		virtual ~Renderable2D();
		virtual void submit(Renderer2D* renderer) const
		{
			renderer->submit(this);
		}
		const Math::vec3& position() const;
		const Math::vec2& size() const;
		const Math::vec4& color() const;
	};

}}

#endif
