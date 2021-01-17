#include "ClearColorDemo.h"
#include "graphics/renderer/OpenGL/OpenGLError.h"
#include "imgui.h"
#include "MenuDemo.h"
#include "GameEngine.h"

namespace MemoGL {
	ClearColorDemo::ClearColorDemo() :
		clearColor { 0.5f, 0.2f, 0.3f, 1.0f }
	{

	}

	ClearColorDemo::~ClearColorDemo() {

	}

	void ClearColorDemo::update(float deltatime) {

	}

	void ClearColorDemo::render() {
		std::shared_ptr<IRenderer> renderer = GameEngine::get()->getGraphicsEngine()->getRenderer();
		renderer->clearColor({ clearColor[0], clearColor[1], clearColor[2], clearColor[3] });
	}

	void ClearColorDemo::imgui() {
		ImGui::ColorEdit4("Clear Color", clearColor);

		if (ImGui::Button("< home")) {
			SceneManager::getInstance()->load(std::make_shared<MenuDemo>());
		}
	}
}