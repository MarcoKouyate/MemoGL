#include "ClearColorDemo.h"
#include "GL/glew.h"
#include "graphics/renderer/OpenGL/OpenGLError.h"
#include "imgui.h"

namespace MemoGL {
	ClearColorDemo::ClearColorDemo() :
		clearColor { 0.5f, 0.2f, 0.3f, 1.0f }
	{

	}

	ClearColorDemo::~ClearColorDemo() {

	}

	void ClearColorDemo::update(float deltatime) {

	}

	void ClearColorDemo::render(IRenderer& renderer) {
		renderer.clearColor({ clearColor[0], clearColor[1], clearColor[2], clearColor[3]});
	}

	void ClearColorDemo::imgui() {
		ImGui::ColorEdit4("Clear Color", clearColor);
	}
}