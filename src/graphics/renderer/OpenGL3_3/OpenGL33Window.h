#pragma once
#include "graphics/renderer/IWindow.h"

namespace MemoGL {
    class OpenGL33Window : public IWindow {
        public:
            bool isRunning() override;
            void close() override;
            
            OpenGL33Window(const WindowProperties& properties);
            ~OpenGL33Window();
        
        private:
            void createContext(const WindowProperties& properties);
    };
}