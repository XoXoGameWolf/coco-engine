#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

FT_Library text_lib;

typedef struct {
    FT_Face face;
} Font;

Font* loadFont(char* path) {
    Font* font = malloc(sizeof(Font));
    FT_New_Face(text_lib, path, 0, &font->face);
    FT_Set_Char_Size(font->face, 0, 64 * 64, 200, 200);
    return font;
}

Texture* getChar(Font* font, char character) {
    FT_UInt index = FT_Get_Char_Index(font->face, character);

    FT_Load_Char(font->face, character, FT_LOAD_RENDER);

    unsigned char* buf = font->face->glyph->bitmap.buffer;
    int width = font->face->glyph->bitmap.width;
    int height = font->face->glyph->bitmap.rows;

    Texture* texture = createTextureMemory(buf, width, height, 1, false);
    flipTexture(texture, true, false);
    return texture;
}