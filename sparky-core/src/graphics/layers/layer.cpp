#include "layer.h"

namespace Sparky { namespace Graphics {

	Layer::Layer(Renderer2D* renderer, Shader* shader, Math::mat4 projectionMatrix)
	: m_renderer(renderer), m_shader(shader), m_projectionMatrix(projectionMatrix)
	{
		m_shader->enable();
		m_shader->setUniformMat4("pr_matrix", m_projectionMatrix);
		m_shader->disable();
	}

	Layer::~Layer()
	{
		delete m_shader;
		delete m_renderer;
		for(unsigned int i = 0; i < m_renderables.size(); ++i)
			delete m_renderables[i];
	}

	void Layer::add(Renderable2D* renderable)
	{
		m_renderables.push_back(renderable);
	}

	void Layer::render()
	{
		m_shader->enable();

		m_renderer->begin();
		for(const Renderable2D* renderable : m_renderables)
			m_renderer->submit(renderable);
		m_renderer->end();

		m_renderer->flush();
	}
}}
