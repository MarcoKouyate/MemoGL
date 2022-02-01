#pragma once
#include "entity/Entity.h"
#include "Word.h"


namespace MemoGL {
    enum class LineAlignment {
        Left,
        Center,
        Justify
    };

    class Line : public Entity {
    public:
        Line(std::vector<std::shared_ptr<Word>> words, float width, float spacing, float scale, LineAlignment alignment);
    };
}