#pragma once
#include "graphics/context/IContext.h"

namespace MemoGL {
	class IOpenGLVersion {
		public:
			virtual void initErrorCalls() = 0;
			virtual void changeSettings(ContextSettings& settings) = 0;
	};
}