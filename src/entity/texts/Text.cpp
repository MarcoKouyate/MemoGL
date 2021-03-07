#include "Text.h"
#include "graphics/text/FontLoader.h"
#include "tools/Log.h"
#include "entity/sprite/Sprite.h"

namespace MemoGL {
    Text::Text(const std::string& content) {
        FontFace face = loadFont("res/fonts/OpenSans/OpenSans-Regular.ttf");
        MEMOGL_LOG_TRACE("Face has been loaded");

        float positionX = 0;
        float space = 1;

        for(auto& letter : content) {
            std::shared_ptr<Sprite> glyph = std::make_shared<Sprite>(face[letter]);
            addChild(glyph);
            glyph->setPosition(positionX, 0);
            positionX += space;
        }
    }
}