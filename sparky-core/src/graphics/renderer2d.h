#ifndef RENDERER2D_H
#define RENDERER2D_H

#include <GL/glew.h>
#include <vector>
#include "../math/math.h"


namespace Sparky { namespace Graphics {

	class Renderable2D;

	class Renderer2D
	{
	protected:
		std::vector<Math::mat4> m_transformationStack;
		const Math::mat4* m_transformationBack;

	protected:
		Renderer2D()
		{
			m_transformationStack.push_back(Math::mat4::identity());
			m_transformationBack = &m_transformationStack.back();
		}

	public:
		void push(const Math::mat4& matrix, bool overwrite = false)
		{
			if(overwrite)
				m_transformationStack.push_back(matrix);
			else
				m_transformationStack.push_back(m_transformationStack.back() * matrix);

			m_transformationBack = &m_transformationStack.back();
		}

		void pop()
		{
			if(m_transformationStack.size() > 1)
				m_transformationStack.pop_back();

			m_transformationBack = &m_transformationStack.back();

			// TODO add to log
		}

		virtual ~Renderer2D() {}
		virtual void begin() {}
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void end() {}
		virtual void flush() = 0;
	};

}}

#endif
