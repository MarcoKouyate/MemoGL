#include <iostream>
#include "graphics/renderer/OpenGL3_3/OpenGL33Window.h"


namespace MemoGL{

    int main(int argc, char** argv) {
      
        OpenGL33Window window;

        try {
            window.initialize(1280, 720, "MemoGL");
        }

        catch (std::runtime_error& error) {
            std::cerr << "Exception : " << error.what() << std::endl;
        }

        while (!glfwWindowShouldClose(window.get()) && glfwGetKey(window.get(), GLFW_KEY_ESCAPE) != GLFW_PRESS) {
            glfwSwapBuffers(window.get());
            glfwPollEvents();
        }

        glfwTerminate();

        return 0;
    }
}
