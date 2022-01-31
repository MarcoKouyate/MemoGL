#pragma once
#include <string>
#include <map>
#include "entity/Object.h"



namespace MemoGL {

    class Text : public Entity {
    public: 
        Text(const std::string& content);

    private:
        void CreateGlyphSprite(Glyph glyph);

        float positionX;
        float scale;
        float space;
    };
}
