#pragma once
#include <string>
#include <map>
#include "entity/Entity.h"




namespace MemoGL {

    class Text : public Entity {
    public: 
        Text(const std::string& content);
        Text(const std::string& content, float width);

    private:
        float width;

        float positionX;
        float positionY;
        
        float spaceX;
        float spaceY;
        
        float scale;
        
    };
}
