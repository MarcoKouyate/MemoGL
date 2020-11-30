#pragma once
#include "graphics/renderer/IWindow.h"

namespace MemoGL {
    class OpenGLLegacyWindow : public IWindow {
    public:
        bool isRunning() override;
        void close() override;

        OpenGLLegacyWindow(const WindowProperties& properties);
        ~OpenGLLegacyWindow();
    private:
        void createContext(const WindowProperties& properties);
    };
}