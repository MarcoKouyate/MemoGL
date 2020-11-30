#pragma once
#include "graphics/renderer/IWindow.h"

namespace MemoGL {
	class OpenGLLegacyWindow : public IWindow {
	public:
		bool isRunning() override;

		OpenGLLegacyWindow(const WindowProperties& properties);
		~OpenGLLegacyWindow();
	};
}