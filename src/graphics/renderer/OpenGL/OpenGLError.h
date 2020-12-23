#pragma once
#include "GL/glew.h"
#include <stdio.h>
#include <stdlib.h>

//Macros for glGetError()

#ifdef _MSC_VER
#define ASSERT(x) if(!(x)) __debugbreak();
#else 
#include <signal.h>
#define ASSERT(x) if (!(x)) raise(SIGINT);
#endif


#ifdef _DEBUG
#define GLCall( x ) do {\
     glClearErrors(); \
     x; \
     ASSERT( glLogErrors( #x, __FILE__, __LINE__) )} while(0)
#define GLCallR( x )  [&]() { \
     glClearErrors(); \
     auto retVal = x; \
     ASSERT( glLogErrors( #x, __FILE__, __LINE__) ); \
     return retVal; \
   }()
#else
#define GLCallR( x ) x
#define GLCall( x ) x
#endif



namespace MemoGL {


    //Error handling
    void glClearErrors();
    bool glLogErrors(const char* functionName, const char* file, int line);
}



