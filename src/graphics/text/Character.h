#pragma once
#include "glm/glm.hpp"

namespace MemoGL {
    struct Character {
        unsigned int textureID;  // ID handle of the glyph texture
        glm::ivec2   size;       // Size of glyph
        glm::ivec2   bearing;    // Offset from baseline to left/top of glyph
        unsigned int advance;    // Offset to advance to next glyph
        unsigned char* buffer;
    };
}