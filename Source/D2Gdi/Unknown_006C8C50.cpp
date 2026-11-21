extern int gnWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
extern unsigned char* gpBuffer_007C9154; // 0x007C9154

// 0x006C8C50
void __fastcall sub_006C8C50_SetPixel(int nX, int nY, unsigned char nValue)
{
    if (nX >= 0 && nX < gnWidth_007C9138 && nY >= 0 && nY < gnHeight_007C913C)
        gpBuffer_007C9154[gnWidth_007C9138 * nY + nX] = nValue;
}
