#pragma once
#include "IWindow.h"
#include <memory>

namespace MemoGL {
    class IRenderer {
        public:
            virtual void render() = 0;

            std::shared_ptr<IWindow> getWindow(){
                return window;
            }

        protected:
            std::shared_ptr<IWindow> window = nullptr;
    };
}