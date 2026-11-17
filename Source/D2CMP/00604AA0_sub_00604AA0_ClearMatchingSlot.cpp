extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0
int __stdcall sub_00600760_GetValue(void* pData);                                                          // 0x00600760
void __fastcall sub_005179A4_VirtualFree(void* pMemory);                                                   // 0x005179A4
void __stdcall sub_006059B0_BuildTable(unsigned char* pData);                                              // 0x006059B0

extern unsigned int gdwSwappedColor_008E9D38;                                                               // 0x008E9D38
extern int gnGlobal_008E9028;                                                                               // 0x008E9028
extern int gnGlobal_008E9D3C;                                                                               // 0x008E9D3C
extern unsigned char gaTable_008E9830[0x100];                                                               // 0x008E9830
extern int gbTableSet_008E9D40;                                                                             // 0x008E9D40

// 0x00604AA0
void __stdcall sub_00604AA0_ClearMatchingSlot(int* pSlots, char* pEntry)
{
    if (pEntry)
    {
        int nValue = sub_00600760_GetValue(pEntry + 8);
        if (nValue)
        {
            for (int i = 0; i < 0x20; i++)
            {
                if (pSlots[i] == nValue)
                {
                    pSlots[i] = 0;
                    return;
                }
            }
        }
    }
}

// 0x00604DD0
double __stdcall sub_00604DD0_MinDouble(double a, double b)
{
    return a < b ? a : b;
}

// 0x00604FE0
double __stdcall sub_00604FE0_HueToRgb(double n1, double n2, double hue)
{
    if (hue > 360.0)
        hue -= 360.0;
    if (hue < 0.0)
        hue += 360.0;
    if (hue < 60.0)
        return n1 + (n2 - n1) * hue / 60.0;
    if (hue < 180.0)
        return n2;
    if (hue < 240.0)
        return n1 + (n2 - n1) * (240.0 - hue) / 60.0;
    return n1;
}

// 0x006051F0
void __stdcall sub_006051F0_FreeIfSet(void* pMemory)
{
    if (pMemory)
        sub_005179A4_VirtualFree(pMemory);
}

// 0x00605320
void __stdcall sub_00605320_SetSwappedColor(unsigned int nColor)
{
    unsigned char nLow = (unsigned char)nColor;
    unsigned char nMid = (unsigned char)(nColor >> 8);
    unsigned char nHigh = (unsigned char)(nColor >> 16);
    gdwSwappedColor_008E9D38 = (((nLow << 8) | nMid) << 8) | nHigh;
}

// 0x006056C0
void __stdcall sub_006056C0_SetGlobal(int nValue)
{
    gnGlobal_008E9028 = nValue;
}

// 0x00605840
void __stdcall sub_00605840_SetGlobal(int nValue)
{
    gnGlobal_008E9D3C = nValue;
}

// 0x00605850
void __stdcall sub_00605850_SetTable(const unsigned char* pTable)
{
    memcpy(gaTable_008E9830, pTable, 0x100);
    gbTableSet_008E9D40 = 1;
}

// 0x00605A90
void __stdcall sub_00605A90_Forward(unsigned char* pData, int nUnused)
{
    sub_006059B0_BuildTable(pData);
}

// 0x00606D40
void __fastcall sub_00606D40_RleCopyRows(const char* pSrc, char* pDst, int nLines, int nPitch)
{
    char* pNextLine = pDst + nPitch;
    while (1)
    {
        char nRun = *pSrc++;
        if (nRun < 0)
        {
            nRun &= 0x7F;
            if (!nRun)
            {
                if (--nLines == 0)
                    return;
                pDst = pNextLine;
                pNextLine += nPitch;
            }
            else
            {
                pDst += nRun;
            }
        }
        else
        {
            memcpy(pDst, pSrc, nRun);
            pSrc += nRun;
            pDst += nRun;
        }
    }
}

// 0x00606DA0
void __fastcall sub_00606DA0_RleCopyRowsClipped(const char* pSrc, char* pDst, int nLines, int nPitch, int nX, int nClipLeft, int nClipRight)
{
    int nLineX = nX;
    char* pNextLine = pDst + nPitch;
    while (1)
    {
        char nRun = *pSrc++;
        if (nRun < 0)
        {
            nRun &= 0x7F;
            if (!nRun)
            {
                if (--nLines == 0)
                    return;
                pDst = pNextLine;
                nX = nLineX;
                pNextLine += nPitch;
            }
            else
            {
                nX += nRun;
                pDst += nRun;
            }
        }
        else
        {
            int nSkip = nClipLeft - nX;
            if (nSkip < 0)
                nSkip = 0;
            int nEnd = nClipRight - nX;
            if (nEnd > nRun)
                nEnd = nRun;
            int nCount = nEnd - nSkip;
            if (nCount > 0)
                memcpy(pDst + nSkip, pSrc + nSkip, nCount);
            pSrc += nRun;
            nX += nRun;
            pDst += nRun;
        }
    }
}
