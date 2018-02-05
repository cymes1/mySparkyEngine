#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "../renderable2d.h"
#include "../renderer2d.h"

namespace Sparky { namespace Graphics {

	class Layer
	{
	protected:
		Renderer2D* m_renderer;
		std::vector<Renderable2D*> m_renderables;
		Shader* m_shader;
		Math::mat4 m_projectionMatrix;

	protected:
		Layer(Renderer2D* renderer, Shader* shader, Math::mat4 projectionMatrix);

	public:
		virtual ~Layer();
		virtual void add(Renderable2D* renderable);
		virtual void render();
	};

}}

#endif
