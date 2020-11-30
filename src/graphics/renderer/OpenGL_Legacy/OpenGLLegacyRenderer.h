#pragma once
#include "graphics/renderer/IRenderer.h"
#include "OpenGLLegacyWindow.h"

namespace MemoGL {
    class OpenGLLegacy : public IRenderer {
    public:
        void render() override;

        OpenGLLegacy(std::shared_ptr<IWindow> pWindow);
        ~OpenGLLegacy();
    };
}