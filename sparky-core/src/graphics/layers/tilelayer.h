#ifndef TILELAYER_H
#define TILELAYER_H

#include "layer.h"
#include "../batchrenderer2d.h"

namespace Sparky { namespace Graphics {

	class TileLayer : public Layer
	{
	public:
		TileLayer(Shader* shader);
		~TileLayer();
	};

}}

#endif
