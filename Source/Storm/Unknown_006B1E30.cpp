struct D2Device006B2030Strc;
struct D2DeviceVtbl006B2030Strc;

extern unsigned int gdwColors_009702C0[256]; // 0x009702C0

struct D2DeviceVtbl006B2030Strc
{
    void* unk_00[40];
    long (__stdcall* SetTextureStageState)(D2Device006B2030Strc* pDevice, unsigned long nStage, unsigned long nType, unsigned long nValue);
};

struct D2Device006B2030Strc
{
    D2DeviceVtbl006B2030Strc* lpVtbl;
};


extern D2Device006B2030Strc* gpDevice_00970E78; // 0x00970E78

// 0x006B1E30
void __fastcall sub_006B1E30_Blit8To32(const unsigned char* pSource, unsigned int* pDest, int nWidth, int nHeight, int nPitch, int nUnused)
{
    unsigned int* pDRow = pDest;
    const unsigned char* pRow = pSource;
    if (nHeight > 0)
    {
        nPitch *= 4;
        int y = nHeight;
        do
        {
            unsigned int* pDst = (unsigned int*)pDRow;
            const unsigned char* pSrc = pRow;
            if (nWidth > 0)
            {
                int x = nWidth;
                do
                {
                    *pDst++ = gdwColors_009702C0[*pSrc++];
                    --x;
                } while (x);
            }
            pRow += nWidth;
            pDRow = (unsigned int*)((char*)pDRow + nPitch);
            --y;
        } while (y);
    }
}

int gnFilterMode_00970E5C; // 0x00970E5C

// 0x006B2030
void __fastcall sub_006B2030_SetFilterMode(int nMode)
{
    if (gnFilterMode_00970E5C && nMode == gnFilterMode_00970E5C)
    {
        return;
    }
    switch (nMode)
    {
    case 1:
        gpDevice_00970E78->lpVtbl->SetTextureStageState(gpDevice_00970E78, 0, 16, 1);
        gpDevice_00970E78->lpVtbl->SetTextureStageState(gpDevice_00970E78, 0, 17, 1);
        break;
    case 2:
        gpDevice_00970E78->lpVtbl->SetTextureStageState(gpDevice_00970E78, 0, 16, 2);
        gpDevice_00970E78->lpVtbl->SetTextureStageState(gpDevice_00970E78, 0, 17, 2);
        break;
    }
    gnFilterMode_00970E5C = nMode;
}
