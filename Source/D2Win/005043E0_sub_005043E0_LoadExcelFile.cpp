struct D2CelFileStrc;

struct D2CompositeUnitStrc
{
    char pad0x00[0xBC];
    D2CelFileStrc* pEmblemCellFile;
    unsigned char f_C0;
    unsigned char unk0xC1;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern "C" const char szDataGlobal_006D4118[];                                                              // 0x006D4118
extern "C" const char gszExcelDirectory_006D8ED4[];                                                         // 0x006D8ED4
unsigned char gabEmblemColor1_0087D810[12];                                                                 // 0x0087D810
unsigned char gabEmblemColor2_0087E82C[12];                                                                 // 0x0087E82C
extern void* ghPentagramCellFile;                                                                           // 0x0087E96C

D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType);                              // 0x004FA9B0
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

// 0x005043E0
void* __stdcall sub_005043E0_LoadExcelFile(void* hArchive, const char* szName, const char* szExtension, unsigned int* pnFileSize)
{
    char szFilename[260];
    wsprintfA(szFilename, "%s\\%s%s", gszExcelDirectory_006D8ED4, szName, szExtension);
    return sub_00517079_LoadFile(hArchive, szFilename, pnFileSize, ".\\Src\\D2Comp.cpp", 0x958);
}

// 0x005053A0
void __stdcall D2Win_10158(D2CompositeUnitStrc* pCompositeUnit, unsigned char a2, unsigned char a3, unsigned char a4)
{
    D2_ASSERT(pCompositeUnit, 0xDB0);

    if (a2 < 1u || a2 > 32u)
    {
        return;
    }

    char szFile[512];
    wsprintfA(szFile, "%s\\ui\\emblems\\icon%02dc", szDataGlobal_006D4118, a2 - 1);
    pCompositeUnit->pEmblemCellFile = ARCHIVE_LoadCellFile(szFile, 0);

    if (a3 >= 1u && a3 <= 10u)
    {
        pCompositeUnit->f_C0 = gabEmblemColor1_0087D810[a3 - 1];
    }
    else
    {
        pCompositeUnit->f_C0 = 0;
    }

    if (a4 >= 1u && a4 <= 10u)
    {
        pCompositeUnit->unk0xC1 = gabEmblemColor2_0087E82C[a4 - 1];
    }
    else
    {
        pCompositeUnit->unk0xC1 = 0;
    }
}

// 0x005070D0
void __stdcall LIST_LoadPentspinCellfile()
{
    D2_ASSERT(ghPentagramCellFile == 0, 0x103);

    char szFile[260];
    wsprintfA(szFile, "%s\\UI\\CURSOR\\Pentspin", szDataGlobal_006D4118);
    ghPentagramCellFile = ARCHIVE_LoadCellFile(szFile, 0);
}
