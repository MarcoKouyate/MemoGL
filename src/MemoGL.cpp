#include <iostream>
#include "GameEngine.h"
#include <memory>


namespace MemoGL{

    int main(int argc, char** argv) {
      
        //setting up modules
        WindowProperties windowProperties;
        windowProperties.name = "MemoGL";
        windowProperties.width = 1280;
        windowProperties.height = 720;

        GameEngine gameEngine;

        std::shared_ptr<IWindow> window = std::make_shared<OpenGL33Window>();
        std::shared_ptr<IRenderer> renderer = std::make_shared<OpenGL33Renderer>();
        std::shared_ptr<IGraphicsEngine> graphicsEngine = std::make_shared<RasterizationEngine>();

        try {
            window->initialize(windowProperties);
            renderer->initialize(window);
            graphicsEngine->initialize(renderer);
            gameEngine.initialize(graphicsEngine);

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
