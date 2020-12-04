#pragma once
#include "../IContext.h"

namespace MemoGL {
    class GLFWContext : public IContext {
        public:
            void init(const ContextSettings& properties) override;
            bool isRunning() override;
            void close() override;
            
            GLFWContext();
            ~GLFWContext();
    };
}