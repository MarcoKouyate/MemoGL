#include "Text.h"

#include "Word.h"
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

    Text::Text(const std::string& content, float _width)
        : positionX(0), positionY(0), scale(0.01), spaceX(0), spaceY(0.6), width(10)
    {
        FontFace face = loadFont("res/fonts/OpenSans/OpenSans-Regular.ttf");
        
        unsigned char space_delimiter = ' ';
        std::vector<std::string> words{};
        std::string text = content;
        size_t pos = 0;
        
        Glyph delimiter_glyph = face[space_delimiter];
        float delimiter_width = (delimiter_glyph.advance >> 6) * scale;
        
        while ((pos = text.find(space_delimiter)) != std::string::npos) {
            words.push_back(text.substr(0, pos));
            text.erase(0, pos + 1);
        }
        
        for (const auto &str : words) {
            std::shared_ptr<Word> word = std::make_shared<Word>(str, face);
            word->getTransform()->setPosition(positionX, positionY);
            this->addChild(word);
            
            positionX += spaceX + word->getWidth() + delimiter_width;
            
            if (width > 0 && positionX > width){
                positionX = 0;
                positionY -= spaceY;
            }
        }
    }
}
