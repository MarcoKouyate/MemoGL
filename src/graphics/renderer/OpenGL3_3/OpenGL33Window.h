#pragma once
#include "graphics/renderer/IWindow.h"

namespace MemoGL {
	class OpenGL33Window : public IWindow {
		public:
			~OpenGL33Window() override;
			void initialize(const WindowProperties& properties) override;
			void release() override;
			bool isRunning() override;
	};
}