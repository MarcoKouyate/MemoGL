#pragma once

namespace MemoGL {
	class IDemo {
	public:
		virtual ~IDemo() = default;

		virtual void update(float deltatime) = 0; 
		virtual void render() = 0;
		virtual void imgui() = 0;
	};
}