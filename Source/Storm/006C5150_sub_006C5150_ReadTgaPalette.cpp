struct D2TargaHeaderStrc { unsigned char bytes[18]; };
struct T004F51E0 { unsigned char red, green, blue, alpha; };
void __stdcall SMemZero(void* destination, unsigned int size); // 0x0041D300

static __declspec(noinline)
// 0x006C5150
int __stdcall sub_006C5150_ReadTgaPalette(const D2TargaHeaderStrc* header, const unsigned char* source, int size, T004F51E0* palette)
{
    int bytesPerColor = (header->bytes[7] + 7) / 8;
    int index = *(const unsigned short*)&header->bytes[3];
    int end = index + *(const unsigned short*)&header->bytes[5];
    if ((end - index) * bytesPerColor != size)
        return 0;
    SMemZero(palette, index * sizeof(T004F51E0));
    for (; index < end; ++index)
    {
        palette[index].red = source[2];
        palette[index].green = source[1];
        palette[index].blue = source[0];
        palette[index].alpha = bytesPerColor > 3 ? source[3] : 0;
        source += bytesPerColor;
    }
    SMemZero(palette + index, (256 - index) * sizeof(T004F51E0));
    return 1;
}

int __fastcall EmitReadTgaPalette(const D2TargaHeaderStrc* header, const unsigned char* source, int size, T004F51E0* palette)
{
    return sub_006C5150_ReadTgaPalette(header + 1, source, size, palette);
}
