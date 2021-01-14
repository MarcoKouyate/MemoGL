#include "graphics/context/GLFW/GLFWContext.h"

namespace MemoGL {
    IContext* IContext::create(const WindowSettings& properties) {
        return new GLFWContext(properties);
    }
}
