#pragma once
#include "graphics/context/IContext.h"
#include <memory>


#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

namespace MemoGL {
	class OpenGLImGui {
		public:
			void begin();
			void end();

			OpenGLImGui(std::shared_ptr<IContext> context, const char* glslVersion, bool darkMode);
			~OpenGLImGui();

			std::shared_ptr<IContext> context;
	};
}