#pragma once
#include "IOpenGLVersion.h"

namespace MemoGL {
	class OpenGL3 : public IOpenGLVersion {
		public:
			virtual void initErrorCalls() override;
			virtual void changeSettings(ContextSettings& settings) override;
	};
}