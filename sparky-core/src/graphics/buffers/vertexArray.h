#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <vector>
#include <GL/glew.h>
#include "buffer.h"

namespace Sparky { namespace Graphics {

	class VertexArray
	{
	private:
		GLuint m_arrayID;
		std::vector<Buffer*> m_buffers;

	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* buffer, GLuint index);
		void bind() const;
		void unbind() const;
	};

}}

#endif
