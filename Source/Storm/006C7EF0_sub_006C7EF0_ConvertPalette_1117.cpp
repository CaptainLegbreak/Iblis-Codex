struct T004F51E0 { unsigned char blue, green, red, reserved; };
extern int gnWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
extern unsigned char* gpPixels_007C9154; // 0x007C9154
extern T004F51E0 gaPalette_00989C40[256]; // 0x00989C40

// 0x006C7EF0
int __fastcall sub_006C7EF0_ConvertPalette(unsigned char* buffer)
{
    unsigned char* row = gpPixels_007C9154;
    for (int y = 0; y < gnHeight_007C913C; ++y) {
        unsigned char* source = row;
        unsigned char* destination = buffer;
        for (int x = 0; x < gnWidth_007C9138; ++x) {
            T004F51E0* color = &gaPalette_00989C40[*source];
            *destination++ = color->red;
            *destination++ = color->green;
            *destination = color->blue;
            ++source;
            ++destination;
        }
        row += gnWidth_007C9138;
        buffer += 3 * gnWidth_007C9138;
    }
    return 1;
}
