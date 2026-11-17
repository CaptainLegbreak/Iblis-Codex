struct D2ArenaTxt
{
    int dwSuicide;
    int dwPlayerKill;
    int dwPlayerKillPercent;
    int dwMonsterKill;
    int dwPlayerDeath;
    int dwPlayerDeathPercent;
    int dwMonsterDeath;
};

struct D2CharTemplateTxt
{
    char szName[30];
    unsigned char nClass;
    char unk0x1F[0xD1];
};

D2ArenaTxt* gpArenaTxtTable;                                                                                      // 0x0096D608
D2CharTemplateTxt* gpCharTemplateTxtTable;                                                                        // 0x0096D600
int gnCharTemplateTxtTableRecordCount;                                                                                 // 0x0096D604
int gnCharTemplateStartIds[64];                                                                                       // 0x0096D500
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                               // 0x006125C0
extern "C" const char gszEmptyAssertText;                                                                         // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09

#define ARENA_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00664AB0
D2ArenaTxt* __fastcall DATATBLS_GetArenaTxtRecord(int nArenaType)
{
    ARENA_ASSERT(nArenaType < 1, 65);

    return &gpArenaTxtTable[nArenaType];
}

// 0x00664AF0
void __fastcall DATATBLS_UnloadArenaTxt()
{
    DATATBLS_UnloadBin(gpArenaTxtTable);
    gpArenaTxtTable = 0;
}

// 0x00665740
void __fastcall DATATBLS_UnloadCharTemplateTxt()
{
    DATATBLS_UnloadBin(gpCharTemplateTxtTable);
    gpCharTemplateTxtTable = 0;
}

// 0x00665760
int __fastcall DATATBLS_GetCharTemplateTxtRecordCount()
{
    return gnCharTemplateTxtTableRecordCount;
}

// 0x00665770
D2CharTemplateTxt* __fastcall DATATBLS_GetCharTemplateTxtRecord(int nTemplate, int nLevel)
{
    ARENA_ASSERT(nTemplate > 0, 245);
    const int nIndex = gnCharTemplateStartIds[nLevel] + nTemplate - 1;
    ARENA_ASSERT(nIndex < gnCharTemplateTxtTableRecordCount, 248);

    return &gpCharTemplateTxtTable[nIndex];
}

// 0x006657C0
int __fastcall DATATBLS_GetClassFromCharTemplateTxtRecord(int nTemplate, int nLevel)
{
    return DATATBLS_GetCharTemplateTxtRecord(nTemplate, nLevel)->nClass;
}
