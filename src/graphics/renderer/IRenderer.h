#pragma once
#include "graphics/context/IContext.h"
#include <memory>

namespace MemoGL {
    class IRenderer {
        public:
            virtual void render() = 0;

            IContext* getContext() {
                return context;
            }

        protected:
            IContext* context = nullptr;
    };


}