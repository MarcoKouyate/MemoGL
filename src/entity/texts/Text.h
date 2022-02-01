#pragma once
#include <string>
#include <map>
#include "entity/Entity.h"
#include "Line.h"
#include <vector>



namespace MemoGL {

    class Text : public Entity {
    public: 
        Text(const std::string& content);
        Text(const std::string& content, float width);

    private:
        void addNewLine(std::vector<std::shared_ptr<Word>> words, LineAlignment alignment);

        float width;

        float positionX;
        float positionY;
        
        float spaceX;
        float spaceY;
        float delimiter_width;
        
        float scale;
        
    };
}
