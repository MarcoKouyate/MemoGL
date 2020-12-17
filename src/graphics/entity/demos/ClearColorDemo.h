#pragma once
#include "../Demo.h"

namespace MemoGL {
	class ClearColorDemo : public IDemo{
	public:
		ClearColorDemo();
		~ClearColorDemo() override;

		void update(float deltatime) override;
		void render() override;
		void imgui() override;

	private:
		float clearColor[4];
	};
}