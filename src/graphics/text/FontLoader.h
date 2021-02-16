#pragma once
#include <map>
#include <string>
#include "Font.h"

#include <ft2build.h>
#include FT_FREETYPE_H

namespace MemoGL {
    using FontFace = std::map<unsigned char, Character>;
    using FontFamily = std::map<std::string, FontFace>;

    FontFace loadFont(const std::string& fontpath);
}