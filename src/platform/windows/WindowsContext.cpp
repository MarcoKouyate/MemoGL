#include "graphics/context/GLFW/GLFWContext.h"

namespace MemoGL {
    IContext* IContext::create(const WindowSettings& windowSettings) {
        RenderingAPISettings renderingSettings;
        renderingSettings.forward_compatibility = true;
        renderingSettings.version_major = 4;
        renderingSettings.version_minor = 4;
        renderingSettings.profile = APIProfile::Core;

        return new GLFWContext(windowSettings, renderingSettings);
    }
}
