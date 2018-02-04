#ifndef BATCHRENDERER2D_H
#define BATCHRENDERER2D_H

#include <cstddef>
#include "buffers/vertexArray.h"
#include "renderer2d.h"
#include "renderable2d.h"

namespace Sparky { namespace Graphics {

	class BatchRenderer2D : public Renderer2D
	{
	private:
		const int RENDERER_MAX_SPRITES = 10000;
		const int RENDERER_VERTEX_SIZE = sizeof(VertexData);
		const int RENDERER_SPRITE_SIZE = RENDERER_VERTEX_SIZE * 4;
		const int RENDERER_BUFFER_SIZE = RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES;
		const int RENDERER_INDICES_SIZE = RENDERER_MAX_SPRITES * 6;
		const int SHADER_VERTEX_INDEX = 0;
		const int SHADER_COLOR_INDEX = 1;

		GLuint m_vao;
		IndexBuffer* m_ibo;
		GLuint m_vbo;
		GLsizei m_indexCount;
		VertexData* m_buffer;
		
	public:
		BatchRenderer2D();
		~BatchRenderer2D();
		void begin();
		void submit(const Renderable2D* renderable) override;
		void end();
		void flush() override;

	private:
		void init();
	};

}}

#endif
