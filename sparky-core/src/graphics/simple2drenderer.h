#ifndef SIMPLE2DRENDERER_H
#define SIMPLE2DRENDERER_H

#include <deque>
#include "renderer2d.h"
#include "staticsprite.h"

namespace Sparky { namespace Graphics {

	class Simple2DRenderer : public Renderer2D
	{
	private:
		std::deque<const StaticSprite*> m_renderQueue;
	
	public:
		void submit(const Renderable2D* renderable) override;
		void flush() override;
	};

}}

#endif
