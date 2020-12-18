#pragma once
#include "../Demo.h"


namespace MemoGL {
	class ClearColorDemo : public Demo{
	public:
		ClearColorDemo();
		~ClearColorDemo() override;

		void update(float deltatime) override;
		void render(IRenderer& renderer) override;
		void imgui() override;

	private:
		float clearColor[4];
	};
}