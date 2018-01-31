#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <vector>
#include <GL/glew.h>

#include "../math/math.h"
#include "../utils/fileutils.h"

namespace Sparky { namespace Graphics {
	
	using namespace Math;

	class Shader
	{
		private:
			GLuint m_shaderID;
			const char* m_vertPath;
			const char* m_fragPath;

		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, const vec2& vector);
			void setUniform3f(const GLchar* name, const vec3& vector);
			void setUniform4f(const GLchar* name, const vec4& vector);
			void setUniformMat4(const GLchar* name, const mat4& matrix);
			void enable() const;
			void disable() const;

		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
	};

}}

#endif
