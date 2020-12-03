#pragma once
#include "graphics/renderer/IWindow.h"

namespace MemoGL {
    class OpenGL4Window : public IWindow {
        public:
            bool isRunning() override;
            void close() override;
            
            OpenGL4Window(const WindowProperties& properties);
            ~OpenGL4Window();
        
        private:
            void createContext(const WindowProperties& properties);
    };
}