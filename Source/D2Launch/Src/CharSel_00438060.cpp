extern "C" unsigned int __cdecl strlen(const char* sz);
#pragma intrinsic(strlen)

struct D2CellFileStrc;

struct D2LaunchCharEntryStrc
{
    char szName[0x324];
    int nFlags;
    char unk0x328[0x0C];
    int bShared;
    D2CellFileStrc* pCellFile;
    char unk0x33C[0x10];
    D2LaunchCharEntryStrc* pNext;
};

void __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0);                       // 0x0040B3C0
int __stdcall sub_005041B0_Destroy(D2CellFileStrc* pCellFile, int nFlag);                                   // 0x005041B0
extern D2LaunchCharEntryStrc* gpCharEntry_00779DC0;                                                         // 0x00779DC0

// 0x00438060
void __cdecl sub_00438060_FreeCharEntry()
{
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->bShared)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
}

// 0x00438F40
int __fastcall sub_00438F40_IsValidCharName(const char* szName)
{
    const int nLen = strlen(szName);
    if (nLen < 2 || nLen > 15 || szName[nLen - 1] == '-' || szName[0] == '_')
        return 0;
    return 1;
}
