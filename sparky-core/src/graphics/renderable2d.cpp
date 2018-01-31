#include "renderable2d.h"

namespace Sparky { namespace Graphics {

	Renderable2D::Renderable2D(Math::vec3 position, Math::vec2 size, Math::vec4 color)
		: m_position(position), m_size(size), m_color(color)
	{
	}


	Renderable2D::~Renderable2D()
	{
	}


	const Math::vec3& Renderable2D::position() const
	{
		return m_position;
	}


	const Math::vec2& Renderable2D::size() const
	{
		return m_size;
	}


	const Math::vec4& Renderable2D::color() const
	{
		return m_color;
	}

}}
