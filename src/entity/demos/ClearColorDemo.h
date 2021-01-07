#pragma once
#include "../Scene.h"


namespace MemoGL {
	class ClearColorDemo : public Scene{
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