#include "simple2drenderer.h"

namespace Sparky { namespace Graphics {

	void Simple2DRenderer::submit(const Renderable2D* renderable)
	{
		m_renderQueue.push_back((StaticSprite*)renderable);
	}
	
	
	void Simple2DRenderer::flush()
	{
		while(!m_renderQueue.empty())
		{
			const StaticSprite* sprite = m_renderQueue.front();
			sprite->vertexArray()->bind();
			sprite->indexBuffer()->bind();
			sprite->shader().setUniformMat4("ml_matrix", Math::mat4::translation(sprite->position()));
			glDrawElements(GL_TRIANGLES, sprite->indexBuffer()->count(), GL_UNSIGNED_SHORT, nullptr);
			sprite->indexBuffer()->unbind();
			sprite->vertexArray()->unbind();
			m_renderQueue.pop_front();
		}
	}

}}
