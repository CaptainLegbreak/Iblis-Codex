typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
#pragma pack(push, 2)
struct D2BitmapFileHeader { WORD type; DWORD size; WORD reserved1; WORD reserved2; DWORD offset; };
#pragma pack(pop)
struct D2BitmapInfoHeader {
    DWORD size; int width; int height; WORD planes; WORD bits;
    DWORD compression; DWORD imageSize; int xppm; int yppm; DWORD colorsUsed; DWORD colorsImportant;
};
struct D2PaletteEntry { BYTE red, green, blue, flags; };
struct D2BitmapColor { BYTE blue, green, red, reserved; };
void __stdcall SMemZero(void*, unsigned int); // 0x0041D300
void* __stdcall sub_00413020_Alloc(unsigned int, const char*, int, unsigned int); // 0x00413020
void __stdcall SMemFree(void*, const char*, int, unsigned int); // 0x00412650
extern "C" __declspec(dllimport) int __stdcall WriteFile(void*, const void*, unsigned int, unsigned int*, void*); // 0x006CC1A8

struct D2CopyStackArg { unsigned int value; };

// calling-convention shim (not game code)
static __declspec(noinline) unsigned int __stdcall sub_006C59C0_CopyPixels(BYTE* out, D2CopyStackArg src, D2CopyStackArg size, D2CopyStackArg pitch, D2CopyStackArg width, unsigned int rows); // 0x006C59C0
// build: context sub_006C59C0_CopyPixels
static unsigned int __stdcall sub_006C59C0_CopyPixels(BYTE* out, D2CopyStackArg src, D2CopyStackArg size, D2CopyStackArg pitch, D2CopyStackArg width, unsigned int rows)
{
    rows += src.value + size.value + pitch.value + width.value;
    out[0] = (BYTE)rows;
    out[1] = (BYTE)(rows >> 8);
    return rows;
}

static __declspec(noinline) int __stdcall sub_006C61C0_WriteBmp(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height);
// 0x006C61C0
static int __stdcall sub_006C61C0_WriteBmp(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height)
{
    D2BitmapFileHeader header;
    D2BitmapInfoHeader info;
    D2BitmapColor colors[256];
    unsigned int pixelWritten;
    {
        unsigned int written;
        SMemZero(&header, sizeof(header));
        int imageSize = width * height;
        header.size = imageSize + 1078;
        header.type = 0x4D42;
        header.offset = 1078;
        WriteFile(file, &header, sizeof(header), &written, 0);
        SMemZero(&info, sizeof(info));
        info.size = 40;
        info.width = width;
        info.height = height;
        info.planes = 1;
        info.bits = 8;
        info.compression = 0;
        info.imageSize = imageSize;
        info.colorsUsed = 256;
        info.colorsImportant = 256;
        WriteFile(file, &info, sizeof(info), &written, 0);
        for (int i = 0; i < 256; ++i)
        {
            colors[i].red = palette[i].red;
            colors[i].green = palette[i].green;
            colors[i].blue = palette[i].blue;
            colors[i].reserved = 0;
        }
        WriteFile(file, colors, sizeof(colors), &written, 0);
    }
    unsigned int nPitch = width;
    if ((width & 3))
        nPitch = width - (width & 3) + 4;
    int bufferSize = nPitch * height;
    BYTE* buffer = (BYTE*)sub_00413020_Alloc(bufferSize, ".\\SOURCE\\SBMP.CPP", 660, 0);
    D2CopyStackArg copySource = { (unsigned int)pixels };
    D2CopyStackArg copySize = { (unsigned int)bufferSize };
    D2CopyStackArg copyPitch = { nPitch };
    D2CopyStackArg copyWidth = { (unsigned int)width };
    sub_006C59C0_CopyPixels(buffer, copySource, copySize, copyPitch, copyWidth, height);
    WriteFile(file, buffer, bufferSize, &pixelWritten, 0);
    SMemFree(buffer, ".\\SOURCE\\SBMP.CPP", 668, 0);
    return 1;
}

// build: context sub_006C61C0_Shim
// calling-convention shim (not game code)
int __stdcall sub_006C61C0_Shim(void* file, const D2PaletteEntry* palette, const BYTE* pixels, int width, int height)
{
    return sub_006C61C0_WriteBmp(file, palette, pixels, width, height);
}
