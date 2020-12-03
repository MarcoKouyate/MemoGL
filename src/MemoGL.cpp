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

        
        try {
            std::shared_ptr<IWindow> window = std::make_shared<OpenGL4Window>(windowProperties);
            std::shared_ptr<IRenderer> renderer = std::make_shared<OpenGL4Renderer>(window);
            std::shared_ptr<IGraphicsEngine> graphicsEngine = std::make_shared<RasterizationEngine>(renderer);

            GameEngine gameEngine(graphicsEngine);

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
