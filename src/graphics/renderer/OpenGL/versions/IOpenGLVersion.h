#pragma once
#include "graphics/context/IWindow.h"

namespace MemoGL {
	class IOpenGLVersion {
		public:
			virtual void initErrorCalls() = 0;
	};
}