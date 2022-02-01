#include "Word.h"
#include "graphics/text/FontLoader.h"
#include "tools/Log.h"
#include "entity/sprite/Sprite.h"


namespace MemoGL {
    Word::Word(const std::string& content, FontFace& face)
        : positionX(0), scale(0.01), space(0)
    {
        for(auto& letter : content) {
            CreateGlyphSprite(face[letter]);
        }
    }

    void Word::CreateGlyphSprite(Glyph glyph) {
        std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>(glyph, scale);
        sprite->getTransform()->setPosition(positionX, 0);
        positionX += (glyph.advance >> 6) * scale + space;
        addChild(sprite);
    }
}
