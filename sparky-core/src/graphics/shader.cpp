#include "shader.h"

namespace Sparky { namespace Graphics {

	Shader::Shader(const char* vertPath, const char* fragPath)
		: m_vertPath(vertPath), m_fragPath(fragPath)
	{
		m_shaderID = load();
	}


	Shader::~Shader()
	{
		glDeleteProgram(m_shaderID);
	}


	void Shader::setUniform1f(const GLchar* name, float value)
	{
		glUniform1f(getUniformLocation(name), value);
	}


	void Shader::setUniform1i(const GLchar* name, int value)
	{
		glUniform1i(getUniformLocation(name), value);
	}


	void Shader::setUniform2f(const GLchar* name, const vec2& vector)
	{
		glUniform2f(getUniformLocation(name), vector.x, vector.y);
	}


	void Shader::setUniform3f(const GLchar* name, const vec3& vector)
	{
		glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
	}


	void Shader::setUniform4f(const GLchar* name, const vec4& vector)
	{
		glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
	}


	void Shader::setUniformMat4(const GLchar* name, const mat4& matrix)
	{
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
	}


	void Shader::enable() const
	{
		glUseProgram(m_shaderID);
	}


	void Shader::disable() const
	{
		glUseProgram(0);
	}


	GLuint Shader::load()
	{
		GLuint program = glCreateProgram();
		GLint result;

		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		std::string vertexSourceString = Fileutils::read_file(m_vertPath).c_str();
		const char* vertexSource = vertexSourceString.c_str();
		glShaderSource(vertex, 1, &vertexSource, NULL);
		glCompileShader(vertex);
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if(result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "failed to compile vertex shader: " << &error[0] << std::endl;
			glDeleteShader(vertex);
			return 0;
		}

		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
		std::string fragmentSourceString = Fileutils::read_file(m_fragPath).c_str();
		const char* fragmentSource = fragmentSourceString.c_str();
		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if(result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "failed to compile fragment shader: " << &error[0] << std::endl;
			glDeleteShader(fragment);
			return 0;
		}

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);
		glLinkProgram(program);
		glValidateProgram(program);
		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}


	GLint Shader::getUniformLocation(const GLchar* name)
	{
		return glGetUniformLocation(m_shaderID, name);
	}

}}
