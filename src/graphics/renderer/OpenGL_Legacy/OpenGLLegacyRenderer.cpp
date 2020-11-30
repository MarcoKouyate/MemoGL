#pragma once
#include <iostream>

#include "OpenGLLegacyRenderer.h"

namespace MemoGL {
    void OpenGLLegacy::render() {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0, 0.5f);
        glVertex2f(0.5, -0.5f);
        glEnd();

        glfwSwapBuffers(window->get());
    }

    OpenGLLegacy::OpenGLLegacy(std::shared_ptr<IWindow> pWindow) {
        window = pWindow;
        std::cout << "OpenGL Legacy renderer initialized." << std::endl;
    }

    OpenGLLegacy::~OpenGLLegacy() {
        std::cout << "OpenGL Legacy renderer has been released." << std::endl;
    }
}