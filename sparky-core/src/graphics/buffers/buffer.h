#ifndef BUFFER_H
#define BUFFER_H

#include <GL/glew.h>
#include <iostream>

namespace Sparky { namespace Graphics {

	class Buffer
	{
	private:
		GLuint m_bufferID;
		GLuint m_componentCount;

	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componenetCount);
		~Buffer();

		void bind() const;
		void unbind() const;
		GLuint componentCount() const;
	};

}}

#endif
