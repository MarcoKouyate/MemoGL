#include "Line.h"


namespace MemoGL {
    Line::Line(std::vector<std::shared_ptr<Word>> words, float width, float spacing, float scale, LineAlignment alignment) {

        float wordfill = 0;
        float advance = 0;

        for (const auto& word : words) {
            wordfill += word->getWidth();
        }

        if (words.size() > 1 && alignment == LineAlignment::Justify) {
            spacing = (width - wordfill) / (words.size() - 1);
        }

        for (const auto& word : words) {
            this->addChild(word);
            word->getTransform()->setPosition(advance, 0);
            advance += word->getWidth() + spacing;
        }
    }
}