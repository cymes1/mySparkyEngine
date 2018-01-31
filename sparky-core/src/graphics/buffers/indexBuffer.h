#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H 

#include <GL/glew.h>

namespace Sparky { namespace Graphics {

	class IndexBuffer
	{
	private:
		GLuint m_bufferID;
		GLsizei m_count;

	public:
		IndexBuffer(GLushort* data, GLsizei count);
		~IndexBuffer();

		void bind() const;
		void unbind() const;
		GLsizei count() const;
	};

}}

#endif
