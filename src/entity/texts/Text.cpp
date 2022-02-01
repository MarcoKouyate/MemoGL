#include "Text.h"

#include "Line.h"
#include "graphics/text/FontLoader.h"

#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>


namespace MemoGL {
    Text::Text(const std::string& content) 
        : Text(content,0)
    {}

    //TODO make width, font and spacing customizable
    //TODO make width pixel dependant

    Text::Text(const std::string& content, float cwidth)
        : positionX(0), positionY(0), scale(0.01), spaceX(0), spaceY(0.6), width(cwidth)
    {
        FontFace face = loadFont("res/fonts/OpenSans/OpenSans-Regular.ttf");
        
        unsigned char space_delimiter = ' ';
        std::vector<std::string> segments{};

        std::string text = content;
        size_t pos = 0;
        
        Glyph delimiter_glyph = face[space_delimiter];
        delimiter_width = (delimiter_glyph.advance >> 6) * scale;
        
        while ((pos = text.find(space_delimiter)) != std::string::npos) {
            segments.push_back(text.substr(0, pos));
            text.erase(0, pos + 1);
        }

        std::vector<std::shared_ptr<Word>> words;
        
        for (const auto &str : segments) {
            std::shared_ptr<Word> word = std::make_shared<Word>(str, face);
            
            positionX += spaceX + word->getWidth() + delimiter_width;
            
            if (width > 0 && positionX + word->getWidth() > width){
                positionX = 0;
                addNewLine(words, LineAlignment::Justify);
                words.clear();
                positionY -= spaceY;
            }

            words.push_back(word);
        }
        addNewLine(words, LineAlignment::Left);
    }

    void Text::addNewLine(std::vector<std::shared_ptr<Word>> words,  LineAlignment alignment) {
        std::shared_ptr<Line> line = std::make_shared<Line>(words, width, spaceX + delimiter_width, scale, alignment);
        line->getTransform()->setPosition(0, positionY);
        this->addChild(line);
    }
}
