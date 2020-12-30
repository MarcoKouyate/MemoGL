#pragma once
#include "graphics/context/IContext.h"

#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

namespace MemoGL {
	class OpenGLImGui {
		public:
			void begin();
			void end();

			OpenGLImGui(const IContext& context, const char* glslVersion, bool darkMode);
			~OpenGLImGui();

			const IContext& context;
	};
}