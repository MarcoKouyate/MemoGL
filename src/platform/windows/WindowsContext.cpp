#include "graphics/context/GLFW/WindowGLFW.h"


namespace MemoGL {
    IWindow* IWindow::create(const WindowSettings& windowSettings) {
        RenderingAPISettings renderingSettings;
        renderingSettings.forward_compatibility = true;
        renderingSettings.version_major = 4;
        renderingSettings.version_minor = 4;
        renderingSettings.profile = APIProfile::Core;

        return new WindowGLFW(windowSettings, renderingSettings);
    }
}
