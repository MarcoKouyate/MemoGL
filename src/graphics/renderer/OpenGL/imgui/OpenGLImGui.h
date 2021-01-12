#pragma once
#include "graphics/context/IWindow.h"

#define IMGUI_IMPL_API
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

namespace MemoGL {
	class OpenGLImGui {
		public:
			void begin();
			void end();

			OpenGLImGui(const IWindow& context, const char* glslVersion, bool darkMode);
			~OpenGLImGui();

		private:
			const IWindow& context;
			ImGuiIO* io;
	};
}