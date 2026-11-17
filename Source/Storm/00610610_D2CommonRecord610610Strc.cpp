extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pnFrequency);             // 0x006CC254
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pnCount);                   // 0x006CC25C

struct D2DrlgRoomStrc;
struct D2DrlgActStrc;
struct D2DrlgDeleteStrc;

struct D2CommonRecord610610Strc
{
    int unk0x00;
    int f_4;
    int f_8;
    int nFieldC;
    int nField10;
    int nField14;
    int nField18;

    D2CommonRecord610610Strc(int nValue);
};

struct D2ProfileCounterStrc
{
    char szName[0x68];
    __int64 nTotal;
    int nCount;
    int f_74;
};

struct D2CompCodeTxt
{
    unsigned int dwCode;
};

struct D2ExperienceTxt
{
    unsigned int dwClass[7];
    unsigned int dwExpRatio;
};

struct D2ExperienceDataTbl
{
    D2ExperienceTxt tMax;
    D2ExperienceTxt aLevels[1];
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x10];
    D2DrlgRoomStrc* pDrlgRoom;
    char unk0x14[0x4];
    D2DrlgDeleteStrc* pDrlgDelete;
    char unk0x1C[0xC];
    int nAllies;
    D2DrlgActStrc* pAct;
    char unk0x30[0x1C];
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    char unk0x6C[0x10];
    D2ActiveRoomStrc* pRoomNext;
};

struct D2DrlgActStrc
{
    char unk0x00[0x10];
    D2ActiveRoomStrc* pRoom;
    char unk0x14[0x44];
    int bHasPendingRoomDeletions;
    void* pMemPool;
};

struct D2DrlgDeleteStrc
{
    int nUnitType;
    int nUnitGUID;
    D2DrlgDeleteStrc* pNext;
};

struct D2RectStrc
{
    int left;
    int top;
    int right;
    int bottom;
};

typedef void(__stdcall* PROFHOOKFN)(int nA, char* pBuffer, int nC);

PROFHOOKFN gpfnProfHook;                                                                                    // 0x0096BC28
extern D2ProfileCounterStrc gaProfEntries[23];                                                                   // 0x00743800
int gnCompCodeTxtRecordCount;                                                                               // 0x0096BCB4
extern D2CompCodeTxt* gpCompCodeTxt;                                                                        // 0x0096BCAC
D2ExperienceDataTbl* gpExperienceTxt;                                                                       // 0x0096C8A8
extern int gbCompileTxt;                                                                                    // 0x0096C8B4
extern int DATATBLS_LoadFromBin;                                                                            // 0x00744308

void __cdecl sub_006248E0_Log(int nA, int nB, int nC, int nFlags, const char* szFile, int nLine, const char* szFormat, ...); // 0x006248E0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
int __fastcall DRLGROOM_GetWarpDestinationLevel(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel);               // 0x0066BAC0

// 0x00610610
D2CommonRecord610610Strc::D2CommonRecord610610Strc(int nValue)
    : f_4(0), f_8(0), nFieldC(0), nField10(0), nField14(0), nField18(nValue)
{
}

// 0x00611620
void __fastcall sub_00611620_ClearAndCallHook(int nA, char* pBuffer, int nC)
{
    PROFHOOKFN pfnHook = gpfnProfHook;
    *pBuffer = 0;
    if (pfnHook)
        pfnHook(nA, pBuffer, nC);
}

// 0x00611660
void __fastcall sub_00611660_AddSample(int nIndex, __int64 nStart)
{
    __int64 nNow;
    QueryPerformanceCounter(&nNow);
    gaProfEntries[nIndex].nTotal += nNow - nStart;
    gaProfEntries[nIndex].nCount++;
}

// 0x006116B0
void __cdecl sub_006116B0_WriteProfileCounters()
{
    __int64 nFrequency;
    QueryPerformanceFrequency(&nFrequency);
    sub_006248E0_Log(1, 2, 1, 0x80000, ".\\Logging\\ProfCore.cpp", 0x4E, "PROFILING DUMP FREQUENCY %d:\n", nFrequency);
    for (int i = 0; i < 23; i++)
        sub_006248E0_Log(1, 2, 1, 0x80000, ".\\Logging\\ProfCore.cpp", 0x54, "FUNCTION: %30s, TIME %12d, COUNT %5d", gaProfEntries[i].szName,
            (int)gaProfEntries[i].nTotal, gaProfEntries[i].nCount);
}

// 0x006117D0
unsigned int __stdcall DATATBLS_GetCodeFromCompCodeTxt(int nCompCode)
{
    if (nCompCode >= gnCompCodeTxtRecordCount)
        return 0;
    return gpCompCodeTxt[nCompCode].dwCode;
}

// 0x00611800
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel)
{
    if (nClass < 0 || nClass >= 7)
        nClass = 0;
    return gpExperienceTxt->aLevels[dwLevel].dwClass[nClass];
}

// 0x00611830
int __stdcall DATATBLS_GetMaxLevel(int nClass)
{
    if (nClass < 0 || nClass >= 7)
        nClass = 0;
    return gpExperienceTxt->tMax.dwClass[nClass];
}

// 0x006125A0
void __stdcall DATATBLS_ToggleCompileTxtFlag(int bSilent)
{
    gbCompileTxt = !bSilent;
}

// 0x006125C0
void __stdcall DATATBLS_UnloadBin(void* pBinFile)
{
    if (pBinFile)
    {
        if (DATATBLS_LoadFromBin)
            FOG_FreePool(0, (char*)pBinFile - 4, ".\\DATATBLS\\DataTbls.cpp", 0x924, 0);
        else
            FOG_FreePool(0, pBinFile, ".\\DATATBLS\\DataTbls.cpp", 0x926, 0);
    }
}

// 0x00613E60
unsigned int __stdcall DATATBLS_GetExpRatio(int nLevel)
{
    if (!gpExperienceTxt)
        return 0;
    if (nLevel <= 0)
        return gpExperienceTxt->tMax.dwExpRatio;
    if (nLevel > (int)gpExperienceTxt->tMax.dwClass[0])
        return 0;
    return gpExperienceTxt->aLevels[nLevel].dwExpRatio;
}

// 0x00619B10
D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomByTileCoordinates(D2DrlgActStrc* pAct, int nX, int nY)
{
    for (D2ActiveRoomStrc* pRoom = pAct->pRoom; pRoom; pRoom = pRoom->pRoomNext)
    {
        if (nX >= pRoom->nTileXPos && nX < pRoom->nTileXPos + pRoom->nTileWidth && nY >= pRoom->nTileYPos
            && nY < pRoom->nTileYPos + pRoom->nTileHeight)
            return pRoom;
    }
    return 0;
}

// 0x00619D00
void __stdcall DUNGEON_GetSubtileRect(D2ActiveRoomStrc* pRoom, D2RectStrc* pRect)
{
    D2_ASSERT(pRoom, 0x1E3);
    pRect->top = pRoom->nSubtileY;
    pRect->bottom = pRoom->nSubtileY + pRoom->nSubtileHeight;
    pRect->left = pRoom->nSubtileX;
    pRect->right = pRoom->nSubtileWidth + pRoom->nSubtileX;
    D2_ASSERT(pRect->top <= pRect->bottom, 0x1EB);
    D2_ASSERT(pRect->left <= pRect->right, 0x1EC);
}

// 0x00619F20
void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom)
{
    if (pRoom)
    {
        D2_ASSERT(pRoom->nAllies > 0, 0x27C);
        --pRoom->nAllies;
    }
}

// 0x0061A1D0
int __stdcall DUNGEON_GetWarpDestinationLevel(D2ActiveRoomStrc* pRoom, int nSourceLevel)
{
    if (!pRoom)
        return 0;
    return DRLGROOM_GetWarpDestinationLevel(pRoom->pDrlgRoom, nSourceLevel);
}

// 0x0061A270
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID)
{
    if (pRoom)
    {
        D2DrlgDeleteStrc* pDrlgDelete = (D2DrlgDeleteStrc*)FOG_AllocPool(pRoom->pAct->pMemPool, sizeof(D2DrlgDeleteStrc),
            ".\\DUNGEON\\Dungeon.cpp", 0x384, 0);
        pDrlgDelete->nUnitType = nUnitType;
        pDrlgDelete->nUnitGUID = nUnitGUID;
        pDrlgDelete->pNext = pRoom->pDrlgDelete;
        pRoom->pDrlgDelete = pDrlgDelete;
        pRoom->pAct->bHasPendingRoomDeletions = 1;
    }
}

#include "gen/data/Source/Storm/00610610_D2CommonRecord610610Strc.inc"
