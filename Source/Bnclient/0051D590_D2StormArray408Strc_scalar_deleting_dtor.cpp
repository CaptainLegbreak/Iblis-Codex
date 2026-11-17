int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

extern "C" const char gszTypeNewsTableItem_0072FF8C[];                                                      // 0x0072FF8C

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int f_0;
    unsigned int f_4;
    D2Storm408ElemStrc* f_8;
    unsigned int f_C;

    ~D2StormArray408Strc()
    {
        if (f_8)
            SMemFree(f_8, gszTypeNewsTableItem_0072FF8C, -2, 0);
    }
    static void operator delete(void* pMemory);
};

// build: symbol ??_GD2StormArray408Strc@@QAEPAXI@Z 0x0051D590
inline void D2StormArray408Strc::operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

void sub_W11_EmitDeleteStormArray408(D2StormArray408Strc* pArray)
{
    delete pArray;
}

int __fastcall sub_00522AE0_DecodeCDKey(const char* szKey, void* pArg2, void* pArg3, void* pArg4);         // 0x00522AE0

// 0x0051DF90
int __fastcall sub_0051DF90(const char* szKey, void* pArg2, void* pArg3, void* pArg4)
{
    if (!szKey)
        return 0;
    sub_00522AE0_DecodeCDKey(szKey, pArg3, pArg2, pArg4);
    return 1;
}
