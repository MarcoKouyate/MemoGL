#pragma once
#include "graphics/context/IContext.h"
#include <memory>

namespace MemoGL {
    class IRenderer {
        public:
            virtual void render() = 0;

            std::shared_ptr<IContext> getContext() {
                return context;
            }

        protected:
            std::shared_ptr<IContext> context = nullptr;
    };


}