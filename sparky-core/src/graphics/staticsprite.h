#ifndef STATICSPRITE_H
#define STATICSPRITE_H

#include "renderable2d.h"

namespace Sparky { namespace Graphics {

	class StaticSprite : public Renderable2D
	{
	private:
		VertexArray* m_vertexArray;
		IndexBuffer* m_indexBuffer;
		Shader& m_shader;

	public:
		StaticSprite(float x, float y, float width, float height, const Math::vec4& color, Shader& shader);
		~StaticSprite();

		const VertexArray* vertexArray() const;
		const IndexBuffer* indexBuffer() const;
		Shader& shader() const;
	};

}}

#endif
