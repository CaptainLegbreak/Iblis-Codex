extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ArchiveHandleStrc;

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332
void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pMPQHandle);                                     // 0x005173AC

extern "C" const char gszExpansionMpq_006CD3A0[];                                                           // 0x006CD3A0
extern "C" const char szPatchD2Mpq_006DC728[];                                                              // 0x006DC728
extern "C" const char szD2DataMpq_006DC770[];                                                               // 0x006DC770
void* ghArchive_008829DC;                                                                                   // 0x008829DC
void* ghArchive_008829E0;                                                                                   // 0x008829E0
void* ghArchive_008829E4;                                                                                   // 0x008829E4

// 0x00524810
int __cdecl sub_00524810_OpenArchives()
{
    D2_ASSERT(!ghArchive_008829DC, 0x8A);
    ghArchive_008829DC = sub_00517332_LoadMpqFile(szD2DataMpq_006DC770, 0, 0, 1000);
    if (!ghArchive_008829DC)
        return 0;
    ghArchive_008829E0 = sub_00517332_LoadMpqFile(szPatchD2Mpq_006DC728, 0, 0, 1000);
    if (!ghArchive_008829E0)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghArchive_008829DC);
        ghArchive_008829DC = 0;
        return 0;
    }
    ghArchive_008829E4 = sub_00517332_LoadMpqFile(gszExpansionMpq_006CD3A0, 0, 0, 1000);
    if (!ghArchive_008829E4)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghArchive_008829DC);
        ghArchive_008829DC = 0;
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghArchive_008829E0);
        ghArchive_008829E0 = 0;
        return 0;
    }
    return 1;
}

// 0x005248E0
void __cdecl sub_005248E0_CloseArchives()
{
    if (ghArchive_008829DC)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghArchive_008829DC);
        ghArchive_008829DC = 0;
    }
    if (ghArchive_008829E0)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghArchive_008829E0);
        ghArchive_008829E0 = 0;
    }
    if (ghArchive_008829E4)
    {
        ARCHIVE_UnloadMPQFile((D2ArchiveHandleStrc*)ghArchive_008829E4);
        ghArchive_008829E4 = 0;
    }
}

// 0x005249C0
static __forceinline void sub_005249C0_FreeTable(void* pTable)
{
    FOG_Free(pTable, ".\\StrTable\\strtable.cpp", 0x121, 0);
}

void __fastcall sub_M129_Emit_005249C0(void* pTable1, void* pTable2)
{
    sub_005249C0_FreeTable(pTable1);
    sub_005249C0_FreeTable(pTable2);
}
