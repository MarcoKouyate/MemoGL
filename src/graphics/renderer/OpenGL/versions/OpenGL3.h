#pragma once
#include "IOpenGLVersion.h"

namespace MemoGL {
	class OpenGL3 : public IOpenGLVersion {
		public:
			virtual void initErrorCalls() override;
	};
}