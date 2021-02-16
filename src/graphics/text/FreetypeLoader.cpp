#include "FontLoader.h"
#include "tools/Log.h"
#include "GL/glew.h"

namespace MemoGL {
    int initFreetype(FT_Library& ft, FT_Face& face, const char* filepath);
    FontFace loadAllGlyphs(FT_Face& face);
    int loadGlyph(FT_Face& face, unsigned long character);


    FontFace loadFont(const std::string& fontpath) {
        FT_Library ft;
        FT_Face face;
        initFreetype(ft, face, fontpath.c_str());
        return loadAllGlyphs(face);
    }

    FT_Error initFreetype(FT_Library& ft, FT_Face& face, const char* filepath) {
        FT_Error errorCode = FT_Init_FreeType(&ft);

        if (errorCode)
        {
            MEMOGL_LOG_ERROR("FREETYPE: Could not init FreeType Library (error code: {0})", errorCode);
            return errorCode;
        }

        errorCode = FT_New_Face(ft, filepath, 0, &face);

        if (errorCode)
        {
            MEMOGL_LOG_ERROR("FREETYPE: Could not load FreeType FontFace Face (error code: {0})", errorCode);
            return errorCode;
        }

        FT_Set_Pixel_Sizes(face, 0, 48);

        errorCode = FT_Load_Char(face, 'X', FT_LOAD_RENDER);
        if (errorCode)
        {
            MEMOGL_LOG_ERROR("ERROR::FREETYTPE: Failed to load Glyph");
            return errorCode;
        }

        return errorCode;
    }

    FontFace loadAllGlyphs(FT_Face& face) {
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction
        FontFace characters;
        for (unsigned char c = 0; c < 128; c++)
        {
            int errorCode = loadGlyph(face, c);

            if (errorCode) {
                continue;
            }

            // generate texture
            unsigned int textureId;
            glGenTextures(1, &textureId);
            glBindTexture(GL_TEXTURE_2D, textureId);
            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
            );
            // set texture options
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            // now store character for later use
            Character character = {
                textureId,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                face->glyph->advance.x, 
                face->glyph->bitmap.buffer
            };
            characters.insert(std::pair<char, Character>(c, character));
        }

        return characters;
    }

    int loadGlyph(FT_Face& face, unsigned long character) {
        FT_Error errorCode = FT_Load_Char(face, character, FT_LOAD_RENDER);

        if (errorCode)
        {
            MEMOGL_LOG_ERROR("ERROR::FREETYTPE: Failed to load Glyph");
            return -1;
        }

        return 0;
    }
}