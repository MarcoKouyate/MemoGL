
#include "GameEngine.h"
#include "tools/Log.h"
#include <memory>
#include "events/KeyBoardEvents.h"

namespace MemoGL{

    int main(int argc, char** argv) {
        //setting up modules
        try {
            KeyReleasedEvent e(24);
            //MEMOGL_LOG_INFO(e);
            GameEngine gameEngine;
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
