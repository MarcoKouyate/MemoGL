#include <iostream>
#include "GameEngine.h"
#include <memory>

namespace MemoGL{

    int main(int argc, char** argv) {
      
        //setting up modules


        
        try {
            std::shared_ptr<IRenderer> renderer = std::make_shared<OpenGLRenderer>();
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
