typedef unsigned int size_t;

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);                                     // 0x00681EF0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
extern void* gpCellFile_007BC960;                                                                           // 0x007BC960
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gdwGlobal_007BC978;                                                                              // 0x007BC978
void __cdecl sub_K04_EmitUse(int nValue);

// 0x0047E770
static void sub_0047E770_DrawModeCel(int nMode)
{
    if (!nMode)
        return;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BC960;
    switch (nMode)
    {
    case 1:
        sub_004F6480(&tContext, gnGlobal_0071146C / 2 - 0xCD, gnGlobal_00711470 - 0x2F, -1, 5, 0);
        break;
    case 2:
    {
        const int nX = gdwGlobal_007BC978 ? gnGlobal_0071146C / 2 - 0x4A : gnGlobal_0071146C / 2 - 0x54;
        sub_004F6480(&tContext, nX - 3, gnGlobal_00711470 - 0x2F, -1, 5, 0);
        break;
    }
    case 3:
    {
        const int nX = gdwGlobal_007BC978 ? gnGlobal_0071146C / 2 + 0x38 : gnGlobal_0071146C / 2 + 0x23;
        sub_004F6480(&tContext, nX - 2, gnGlobal_00711470 - 0x2F, -1, 5, 0);
        break;
    }
    }
}

void __cdecl sub_K04_EmitDrawModeCel(int nMode)
{
    sub_0047E770_DrawModeCel(nMode);
    sub_K04_EmitUse(nMode);
}
