#include "OpenGL3.h" 

namespace MemoGL {
	void OpenGL3::changeSettings(ContextSettings& settings) {
		settings.debugMode = false;
		settings.version.majorId = 3;
		settings.version.minorId = 3;
	}

	void OpenGL3::initErrorCalls() {
		//OpenGL does not have any error callback to setup
	}
}