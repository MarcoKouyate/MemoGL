#include "Text.h"
#include "graphics/text/FontLoader.h"
#include "tools/Log.h"
#include "entity/sprite/Sprite.h"

namespace MemoGL {
    Text::Text(const std::string& content) {
        FontFace face = loadFont("res/fonts/OpenSans/OpenSans-Regular.ttf");
        MEMOGL_LOG_TRACE("Face has been loaded");
        addChild(std::make_shared<Sprite>(face['R']));
    }
}