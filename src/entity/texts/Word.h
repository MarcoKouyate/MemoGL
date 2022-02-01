#pragma once
#include "entity/Object.h"
#include "graphics/text/FontLoader.h"

namespace MemoGL {
    class Word : public Entity {
    public:
        Word(const std::string& content, FontFace& face);
        
        float getWidth () const {
            return positionX;
        }

    private:
        void CreateGlyphSprite(Glyph glyph);

        float positionX;
        float scale;
        float space;
    };
}
