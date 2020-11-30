#pragma once
#include "graphics/renderer/IWindow.h"

namespace MemoGL {
	class OpenGL33Window : public IWindow {
		public:
			bool isRunning() override;
			
			OpenGL33Window(const WindowProperties& properties);
			~OpenGL33Window();
	};
}