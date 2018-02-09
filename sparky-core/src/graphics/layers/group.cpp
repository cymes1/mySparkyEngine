#include "group.h"

namespace Sparky { namespace Graphics {

	Group::Group(const Math::mat4& transform)
		: m_transformationMatrix(transform)
	{}

	void Group::add(Renderable2D* renderable)
	{
		m_renderables.push_back(renderable);
	}

	void Group::submit(Renderer2D* renderer) const
	{
		renderer->push(m_transformationMatrix);

		for(const Renderable2D* renderable : m_renderables)
			renderable->submit(renderer);

		renderer->pop();
	}
}}
