#pragma once
#include "renderer/IWindow.h"

namespace MemoGL {
	class OpenGL33Window : public IWindow {
		public:
			~OpenGL33Window() override;
			void initialize(int width, int height, const char* name) override;
			void release() override;
			bool isRunning() override;
	};
}