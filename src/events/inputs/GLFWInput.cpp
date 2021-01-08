#include "GLFWInput.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GameEngine.h"

// No need to map keycodes because MEMOGL keycodes and GLFW keycodes are the same
// However it would be necessary to map codes if we use other API (ex: windows API)

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