#pragma once
#include "GL/glew.h"
#include <iostream>

#ifdef _MSC_VER
#define ASSERT(x) if(!(x)) __debugbreak();
#else 
#include <signal.h>
#define ASSERT(x) if (!(x)) raise(SIGINT);
#endif

#ifdef _DEBUG
#define CallGL(x) clearGlErrors();\
    x;\
    ASSERT(logGlCalls(#x, __FILE__, __LINE__))
#else
#define CallGL(x) x
#endif


namespace MemoGL {
    //Error handling
    void clearGlErrors();
    bool logGlCalls(const char* functionName, const char* file, int line);
}



