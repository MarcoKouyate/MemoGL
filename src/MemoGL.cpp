#include <iostream>
#include "GameEngine.h"


namespace MemoGL{

    int main(int argc, char** argv) {
      
        GameEngine gameEngine;
        WindowProperties windowProperties;
        windowProperties.name = "MemoGL";
        windowProperties.width = 1280;
        windowProperties.height = 720;

        try {
            gameEngine.initialize(GraphicsEngineType::Rasterization, RendererType::OpenGL33, windowProperties);
            gameEngine.run();
        }

        catch (std::runtime_error& error) {
            std::cerr << "Exception : " << error.what() << std::endl;
        }

        catch (std::bad_alloc& error) {
            std::cerr << "Exception : " << error.what() << std::endl;
        }

        return 0;
    }
    
}
