#pragma once
#include "graphics/renderer/IRenderer.h"


namespace MemoGL {
	class IDemo {
	public:
		virtual ~IDemo() = default;

		virtual void update(float deltatime) = 0; 
		virtual void render(IRenderer& renderer) = 0;
		virtual void imgui() = 0;
	};
}