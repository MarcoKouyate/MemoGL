#include "GameEngine.h"
#include "tools/Log.h"

namespace MemoGL{

    int main(int argc, char** argv) {
        //setting up modules
        try {
            GameEngine::get()->run();
        }

        catch (std::runtime_error& error) {
            MEMOGL_LOG_ERROR("Exception : {0}", error.what());
        }

        catch (std::bad_alloc& error) {
            MEMOGL_LOG_ERROR("Exception : {0}", error.what());
        }
        
        catch (...) {
            MEMOGL_LOG_ERROR("Something went wrong!");
            return -1;
        }

        return 0;
    }
    
}
