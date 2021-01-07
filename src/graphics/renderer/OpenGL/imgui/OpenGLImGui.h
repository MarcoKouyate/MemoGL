#pragma once
#include "graphics/context/IContext.h"

#define IMGUI_IMPL_API
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

namespace MemoGL {
	class OpenGLImGui {
		public:
			void begin();
			void end();

			OpenGLImGui(const IContext& context, const char* glslVersion, bool darkMode);
			~OpenGLImGui();

		private:
			const IContext& context;
			ImGuiIO* io;
	};
}