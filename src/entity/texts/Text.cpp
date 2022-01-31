#include "Text.h"
#include "graphics/text/FontLoader.h"
#include "tools/Log.h"
#include "entity/sprite/Sprite.h"

namespace MemoGL {
    Text::Text(const std::string& content) 
        : positionX(0), scale(0.01), space(0)
    {
        FontFace face = loadFont("res/fonts/OpenSans/OpenSans-Regular.ttf");
        MEMOGL_LOG_TRACE("Face has been loaded");

        for(auto& letter : content) {
            CreateGlyphSprite(face[letter]);
        }
    }

    void Text::CreateGlyphSprite(Glyph glyph) {
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(glyph, scale);
        sprite->getTransform()->setPosition(positionX, 0);
        positionX += (glyph.advance >> 6) * scale + space;
        addChild(sprite);
    }
}