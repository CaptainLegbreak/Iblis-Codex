struct D2TxtLinkStrc;

struct D2BinFieldStrc
{
    const char* szFieldName;
    int nFieldType;
    int nFieldLength;
    int nFieldOffset;
    void* pLinker;
};

struct D2StatesTxt
{
    unsigned short wState;
    char unk0x02[0xE];
    unsigned char nStateFlags[8];
    char unk0x18[0x24];
};

struct D2DataTablesStrc
{
    char unk0x000[0x070];
    D2TxtLinkStrc* pSkillsLinker;
    char unk0x074[0x004];
    D2TxtLinkStrc* pEventsLinker;
    char unk0x07C[0x040];
    D2StatesTxt* pStatesTxt;
    D2TxtLinkStrc* pStatesLinker;
    int nStatesTxtRecordCount;
    unsigned int* pStateMasks;
    unsigned int* fStateMasks[40];
    short* pProgressiveStates;
    short nProgressiveStates;
    char unk0x172[0x002];
    short* pCurseStates;
    short nCurseStates;
    char unk0x17A[0x002];
    short* pTransformStates;
    short nTransformStates;
    char unk0x182[0x002];
    short* pActionStates;
    short nActionStates;
    char unk0x18A[0x002];
    short* pColourStates;
    short nColourStates;
    char unk0x192[0x002];
    char unk0x194[0x004];
    D2TxtLinkStrc* pSoundsLinker;
    char unk0x19C[0x818];
    D2TxtLinkStrc* pColorsLinker;
    char unk0x9B8[0x1B0];
    D2TxtLinkStrc* pMissilesLinker;
    char unk0xB6C[0x04C];
    D2TxtLinkStrc* pOverlayLinker;
    char unk0xBBC[0x014];
    D2TxtLinkStrc* pItemStatCostLinker;
    char unk0xBD4[0x020];
    D2TxtLinkStrc* pItemTypesLinker;
};

enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_CODETOWORD = 15,
    TXTFIELD_NAMETOINDEX = 17,
    TXTFIELD_NAMETOWORD = 20,
    TXTFIELD_BIT = 26,
};

extern "C" const char gszTxtField_exp[];                                                                    // 0x006E7B3C
extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern D2DataTablesStrc gD2DataTables;                                                                      // 0x0096BC30

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine);                                   // 0x006BD040
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0
void __fastcall sub_00611D60_BuildStateMask(unsigned int* pMask, int nFlag);                                // 0x00611D60
void __fastcall sub_00611DC0_BuildStateListByFlag(short** ppList, short* pnCount, int nFlag);               // 0x00611DC0
void __fastcall sub_00611E60_BuildStateListByField(short** ppList, short* pnCount, int nFieldOffset);       // 0x00611E60
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00618100
void __fastcall DATATBLS_LoadStatesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "state", TXTFIELD_NAMETOINDEX, 0, 0, &gD2DataTables.pStatesLinker },
        { "group", TXTFIELD_WORD, 0, 30, 0 },
        { "nosend", TXTFIELD_BIT, 0, 16, 0 },
        { "hide", TXTFIELD_BIT, 2, 16, 0 },
        { "transform", TXTFIELD_BIT, 3, 16, 0 },
        { "aura", TXTFIELD_BIT, 1, 16, 0 },
        { "pgsv", TXTFIELD_BIT, 4, 16, 0 },
        { "active", TXTFIELD_BIT, 5, 16, 0 },
        { "remhit", TXTFIELD_BIT, 6, 16, 0 },
        { "damblue", TXTFIELD_BIT, 7, 16, 0 },
        { "damred", TXTFIELD_BIT, 8, 16, 0 },
        { "attblue", TXTFIELD_BIT, 9, 16, 0 },
        { "attred", TXTFIELD_BIT, 10, 16, 0 },
        { "curse", TXTFIELD_BIT, 11, 16, 0 },
        { "curable", TXTFIELD_BIT, 12, 16, 0 },
        { "plrstaydeath", TXTFIELD_BIT, 13, 16, 0 },
        { "monstaydeath", TXTFIELD_BIT, 14, 16, 0 },
        { "bossstaydeath", TXTFIELD_BIT, 15, 16, 0 },
        { "disguise", TXTFIELD_BIT, 16, 16, 0 },
        { "bossinv", TXTFIELD_BIT, 37, 16, 0 },
        { "meleeonly", TXTFIELD_BIT, 38, 16, 0 },
        { "restrict", TXTFIELD_BIT, 17, 16, 0 },
        { "blue", TXTFIELD_BIT, 18, 16, 0 },
        { "armblue", TXTFIELD_BIT, 19, 16, 0 },
        { "rfblue", TXTFIELD_BIT, 20, 16, 0 },
        { "rcblue", TXTFIELD_BIT, 21, 16, 0 },
        { "rlblue", TXTFIELD_BIT, 22, 16, 0 },
        { "rpblue", TXTFIELD_BIT, 23, 16, 0 },
        { "stambarblue", TXTFIELD_BIT, 24, 16, 0 },
        { "armred", TXTFIELD_BIT, 25, 16, 0 },
        { "rfred", TXTFIELD_BIT, 26, 16, 0 },
        { "rcred", TXTFIELD_BIT, 27, 16, 0 },
        { "rlred", TXTFIELD_BIT, 28, 16, 0 },
        { "rpred", TXTFIELD_BIT, 29, 16, 0 },
        { gszTxtField_exp, TXTFIELD_BIT, 30, 16, 0 },
        { "shatter", TXTFIELD_BIT, 31, 16, 0 },
        { "life", TXTFIELD_BIT, 32, 16, 0 },
        { "udead", TXTFIELD_BIT, 33, 16, 0 },
        { "green", TXTFIELD_BIT, 34, 16, 0 },
        { "nooverlays", TXTFIELD_BIT, 35, 16, 0 },
        { "notondead", TXTFIELD_BIT, 39, 16, 0 },
        { "noclear", TXTFIELD_BIT, 36, 16, 0 },
        { "overlay1", TXTFIELD_NAMETOWORD, 0, 2, &gD2DataTables.pOverlayLinker },
        { "overlay2", TXTFIELD_NAMETOWORD, 0, 4, &gD2DataTables.pOverlayLinker },
        { "overlay3", TXTFIELD_NAMETOWORD, 0, 6, &gD2DataTables.pOverlayLinker },
        { "overlay4", TXTFIELD_NAMETOWORD, 0, 8, &gD2DataTables.pOverlayLinker },
        { "pgsvoverlay", TXTFIELD_NAMETOWORD, 0, 14, &gD2DataTables.pOverlayLinker },
        { "castoverlay", TXTFIELD_NAMETOWORD, 0, 10, &gD2DataTables.pOverlayLinker },
        { "removerlay", TXTFIELD_NAMETOWORD, 0, 12, &gD2DataTables.pOverlayLinker },
        { "stat", TXTFIELD_NAMETOWORD, 0, 24, &gD2DataTables.pItemStatCostLinker },
        { "setfunc", TXTFIELD_WORD, 0, 26, 0 },
        { "remfunc", TXTFIELD_WORD, 0, 28, 0 },
        { "missile", TXTFIELD_NAMETOWORD, 0, 58, &gD2DataTables.pMissilesLinker },
        { "skill", TXTFIELD_NAMETOWORD, 0, 56, &gD2DataTables.pSkillsLinker },
        { "colorpri", TXTFIELD_BYTE, 0, 32, 0 },
        { "colorshift", TXTFIELD_BYTE, 0, 33, 0 },
        { "light-r", TXTFIELD_BYTE, 0, 34, 0 },
        { "light-g", TXTFIELD_BYTE, 0, 35, 0 },
        { "light-b", TXTFIELD_BYTE, 0, 36, 0 },
        { "onsound", TXTFIELD_NAMETOWORD, 0, 38, &gD2DataTables.pSoundsLinker },
        { "offsound", TXTFIELD_NAMETOWORD, 0, 40, &gD2DataTables.pSoundsLinker },
        { "itemtype", TXTFIELD_CODETOWORD, 0, 42, &gD2DataTables.pItemTypesLinker },
        { "itemtrans", TXTFIELD_CODETOBYTE, 0, 44, &gD2DataTables.pColorsLinker },
        { "gfxtype", TXTFIELD_BYTE, 0, 45, 0 },
        { "gfxclass", TXTFIELD_WORD, 0, 46, 0 },
        { "cltevent", TXTFIELD_NAMETOWORD, 0, 48, &gD2DataTables.pEventsLinker },
        { "clteventfunc", TXTFIELD_WORD, 0, 50, 0 },
        { "cltactivefunc", TXTFIELD_WORD, 0, 52, 0 },
        { "srvactivefunc", TXTFIELD_WORD, 0, 54, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    gD2DataTables.pStatesLinker = sub_006BD040(".\\DATATBLS\\DataTbls.cpp", 1735);
    gD2DataTables.pStatesTxt = (D2StatesTxt*)DATATBLS_CompileTxt(hArchive, "states", pTbl, &gD2DataTables.nStatesTxtRecordCount, sizeof(D2StatesTxt));

    D2_ASSERT(gD2DataTables.nStatesTxtRecordCount < 256, 1737);

    unsigned int nMaskSize = sizeof(unsigned int) * ((gD2DataTables.nStatesTxtRecordCount + 32 - 1) / 32);
    unsigned int nSize = 40 * nMaskSize;
    gD2DataTables.pStateMasks = (unsigned int*)FOG_AllocPool(0, nSize, ".\\DATATBLS\\DataTbls.cpp", 1742, 0);
    memset(gD2DataTables.pStateMasks, 0, nSize);

    for (int i = 0; i < 40; ++i)
    {
        gD2DataTables.fStateMasks[i] = &gD2DataTables.pStateMasks[i * (nMaskSize / sizeof(unsigned int))];
        sub_00611D60_BuildStateMask(gD2DataTables.fStateMasks[i], i);
    }

    sub_00611DC0_BuildStateListByFlag(&gD2DataTables.pProgressiveStates, &gD2DataTables.nProgressiveStates, 4);
    sub_00611DC0_BuildStateListByFlag(&gD2DataTables.pCurseStates, &gD2DataTables.nCurseStates, 11);
    sub_00611DC0_BuildStateListByFlag(&gD2DataTables.pTransformStates, &gD2DataTables.nTransformStates, 16);
    sub_00611DC0_BuildStateListByFlag(&gD2DataTables.pActionStates, &gD2DataTables.nActionStates, 5);
    sub_00611E60_BuildStateListByField(&gD2DataTables.pColourStates, &gD2DataTables.nColourStates, 42);
}
