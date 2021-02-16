#pragma once
#include <map>
#include <string>
#include "Character.h"

#include <ft2build.h>
#include FT_FREETYPE_H

namespace MemoGL {
    class Font {
        public:
            Font(const std::string& fontpath);
    };
}