struct D2GraphicsInterfaceStrc
{
    char unk0x00[40];
    int (__fastcall* pfGetBackBuffer)(unsigned char* pBuffer);
    char unk0x2C[148];
    void (__fastcall* pfDrawLine)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha);
};

extern int gnResolutionMode;                                                                                // 0x007C8CB8
extern D2GraphicsInterfaceStrc* gpGraphicsInterface;                                                        // 0x007C8CC0

// 0x004F5160
int __stdcall D2GFX_GetResolutionMode()
{
    return gnResolutionMode;
}

// 0x004F6250
int __stdcall D2GFX_GetBackBuffer(unsigned char* pBuffer)
{
    return gpGraphicsInterface->pfGetBackBuffer(pBuffer);
}

// 0x004F6380
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    gpGraphicsInterface->pfDrawLine(nXStart, nYStart, nXEnd, nYEnd, dwColor, nAlpha);
}
