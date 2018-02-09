#ifndef GROUP_H
#define GROUP_H

#include <vector>
#include "../renderable2d.h"

namespace Sparky { namespace Graphics {

	class Group : public Renderable2D
	{
	private:
		std::vector<Renderable2D*> m_renderables;
		Math::mat4 m_transformationMatrix;

	public:
		Group(const Math::mat4& transform);
		void add(Renderable2D* renderable);
		void submit(Renderer2D* renderer) const override;
	};

}}

#endif
