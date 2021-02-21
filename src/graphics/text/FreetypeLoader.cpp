#include "FontLoader.h"
#include "tools/Log.h"
#include "GL/glew.h"

namespace MemoGL {
    int initFreetype(FT_Library& ft, FT_Face& face, const char* filepath);
    FontFace loadAllGlyphs(FT_Face& face);
    int loadGlyph(FT_Face& face, unsigned long character);
    void renderGlyph(Glyph character);
    void clearFreetype(FT_Library& ft, FT_Face& face);


    FontFace loadFont(const std::string& fontpath) {
        FT_Library ft;
        FT_Face face;
        initFreetype(ft, face, fontpath.c_str());
        FontFace characters = loadAllGlyphs(face);
        renderGlyph(characters['w']);
        return characters;
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
        return errorCode;
    }

    FontFace loadAllGlyphs(FT_Face& face) {
        FontFace characters;

        for (unsigned char c = 0; c < 128; c++)
        {
            int errorCode = loadGlyph(face, c);

            if (errorCode) {
                continue;
            }

            Glyph character;

            character.size = glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);

            unsigned int size = character.size.x * character.size.y;
            character.buffer = new unsigned char[size];

            for (int i = 0; i < size; i++) {
                character.buffer[i] = face->glyph->bitmap.buffer[i];
            }

            character.bearing = glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top);
            character.advance = face->glyph->advance.x;

            characters[c] = character;
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

    void clearFreetype(FT_Library& ft, FT_Face& face) {
        FT_Done_FreeType(ft);
        FT_Done_Face(face);
    }

    void renderGlyph(Glyph character) {
        unsigned int textureId;
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            character.size.x,
            character.size.y,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            character.buffer
        );

        // set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
}