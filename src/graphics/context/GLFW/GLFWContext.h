#pragma once
#include "../IContext.h"

namespace MemoGL {
    class GLFWContext : public IContext {
        public:
            void init(ContextSettings* properties) override;
            void swapBuffers() override;
            void pollEvents() override;
            double getTime() override;
            bool isRunning() override;
            void close() override;
            
            GLFWContext();
            ~GLFWContext();

        private:
            int getProfile(APIProfile profile);
    };
}