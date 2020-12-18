#pragma once
#include "graphics/renderer/IRenderer.h"

namespace MemoGL {
	class Entity
	{
	public:
		virtual ~Entity() = default;
		virtual void render(IRenderer& renderer) = 0;
	};


}