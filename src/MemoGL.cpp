#include "GameEngine.h"
#include "layers/ExampleLayer.h"
#include "tools/Log.h"
#include "events/KeyBoardEvents.h"

namespace MemoGL{

    int main(int argc, char** argv) {
        //setting up modules
        try {
            KeyReleasedEvent e(24);
            GameEngine gameEngine;
            //gameEngine.pushLayer(new ExampleLayer);
            gameEngine.run();
        }

        catch (std::runtime_error& error) {
            MEMOGL_LOG_ERROR("Exception : {0}", error.what());
        }

        catch (std::bad_alloc& error) {
            MEMOGL_LOG_ERROR("Exception : {0}", error.what());
        }

        return 0;
    }
    
}
