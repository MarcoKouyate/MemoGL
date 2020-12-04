#include "OpenGL3.h" 

namespace MemoGL {
	void OpenGL3::changeSettings(ContextSettings& settings) {
		settings.debugMode = false;
		settings.version.major = 3;
		settings.version.minor = 3;
	}

	void OpenGL3::initErrorCalls() {
		//OpenGL does not have any error callback to setup
	}
}