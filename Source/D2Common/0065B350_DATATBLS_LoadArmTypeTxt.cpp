struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpArmtypeTxt;                                                                                  // 0x0096D4E8

// 0x0065B350
void __fastcall DATATBLS_LoadArmTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpArmtypeTxt = DATATBLS_CompileTxt(hArchive, "armtype", pTbl, 0, 52);
}
