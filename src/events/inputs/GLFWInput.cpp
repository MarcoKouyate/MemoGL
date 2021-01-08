#include "GLFWInput.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GameEngine.h"

namespace MemoGL {
    bool GLFWInput::isKeyPressed(int keyCode) const {
        auto window = static_cast<GLFWwindow*>(GameEngine::get()->getContext().getNativeWindow());
        auto state = glfwGetKey(window, keyCode);
        return state == GLFW_PRESS ||state == GLFW_REPEAT;
    }

    bool GLFWInput::isMouseButtonPressed(int button) const {
        auto window = static_cast<GLFWwindow*>(GameEngine::get()->getContext().getNativeWindow());
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    glm::vec2 GLFWInput::getMousePosition() const {
        auto window = static_cast<GLFWwindow*>(GameEngine::get()->getContext().getNativeWindow());
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return { (float) x, (float) y };
    }
}