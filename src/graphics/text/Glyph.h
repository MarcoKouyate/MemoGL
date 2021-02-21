#pragma once
#include "glm/glm.hpp"

namespace MemoGL {
   struct Glyph {
        unsigned char* buffer;
        unsigned int textureId;  // ID handle of the glyph texture
        glm::ivec2   size;       // Size of glyph
        glm::ivec2   bearing;    // Offset from baseline to left/top of glyph
        unsigned int advance;    // Offset to advance to next glyph
    };
}