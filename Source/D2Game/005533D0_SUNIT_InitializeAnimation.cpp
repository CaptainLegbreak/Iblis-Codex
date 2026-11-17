extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define PLRMODE_SEQUENCE 0x12
#define MONMODE_SEQUENCE 0xE
#define ITEMQUAL_UNIQUE 7

struct D2AnimSeqTxt;
struct D2DynamicPathStrc;
struct D2InventoryStrc;

struct D2AnimDataRecordStrc
{
    char unk0x00[0x08];
    int dwFrames;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2PlayerDataStrc
{
    char szName[16];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    D2AnimSeqTxt* pAnimSeq;
    char unk0x34[0x10];
    int nSeqCurrentFramePrecise;
    int dwFrameCountPrecise;
    short wAnimSpeed;
    unsigned char nActionFrame;
    unsigned char unk0x4F;
    const D2AnimDataRecordStrc* pAnimData;
    char unk0x54[0x40];
    int dwOwnerType;
    int dwOwnerGUID;
};

struct D2UnitInfoStrc
{
    int nUnitType;
    int nClassId;
    int nUnitGUID;
    int nAnimMode;
    int nX;
    int nY;
    int nOwnerType;
    int nOwnerGUID;
    int unk0x20;
    char szDescription[16];
};

struct D2GameStrc
{
    char unk0x0000[0x1B24];
    unsigned int dwUniqueFlags[128];
};

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                            // 0x006633B0
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit);                                                 // 0x00621260
void __stdcall UNITS_UpdateAnimRateAndVelocity(D2UnitStrc* pUnit, const char* szFile, int nLine);          // 0x00623F50
void __stdcall sub_00620F00(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nAnimMode);    // 0x00620F00
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

static int SUNIT_GetUnitX_Inlined(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static int SUNIT_GetUnitY_Inlined(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static unsigned int ITEMS_HasUniqueBeenDroppedAlready_Inlined(D2GameStrc* pGame, int nUniqueItemId)
{
    if (!pGame)
    {
        return 0;
    }

    if (nUniqueItemId < 0 || nUniqueItemId > 4096)
    {
        return 1;
    }

    return pGame->dwUniqueFlags[nUniqueItemId >> 5] & gdwBitMasks[nUniqueItemId & 0x1F];
}

// 0x005533D0
void __fastcall SUNIT_InitializeAnimation(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x561);

    pUnit->nActionFrame = 0;

    int bPlayerSequence = 0;
    if (pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == PLRMODE_SEQUENCE)
    {
        bPlayerSequence = 1;
    }

    if ((pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_SEQUENCE || bPlayerSequence) && DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit))
    {
        UNITS_InitializeSequence(pUnit);
        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNIT\\SUnit.cpp", 0x570);
        return;
    }

    pUnit->pAnimSeq = 0;
    pUnit->nSeqCurrentFramePrecise = 0;
    if (pUnit->pDynamicPath)
    {
        UNITS_UpdateAnimRateAndVelocity(pUnit, ".\\UNIT\\SUnit.cpp", 0x578);
    }
    else
    {
        sub_00620F00(pUnit, pUnit->dwUnitType, pUnit->dwClassId, pUnit->dwAnimMode);
    }

    pUnit->dwFrameCountPrecise = pUnit->pAnimData->dwFrames << 8;
}

// 0x00553F30
void __fastcall SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pInfo)
{
    D2_ASSERT(pInfo, 0x9AA);
    D2_ASSERT(pUnit, 0x9AB);

    D2PlayerDataStrc* pPlayerData;
    if (pUnit->dwUnitType == UNIT_PLAYER && (pPlayerData = UNITS_GetPlayerData(pUnit)) != 0)
    {
        strcpy(pInfo->szDescription, pPlayerData->szName);
    }
    else
    {
        pInfo->szDescription[0] = 0;
    }

    pInfo->nUnitType = pUnit->dwUnitType;
    pInfo->nClassId = pUnit->dwClassId;
    pInfo->nUnitGUID = pUnit->dwUnitId;
    pInfo->nAnimMode = pUnit->dwAnimMode;
    pInfo->nX = SUNIT_GetUnitX_Inlined(pUnit);
    pInfo->nY = SUNIT_GetUnitY_Inlined(pUnit);
    pInfo->nOwnerType = pUnit->dwOwnerType;
    pInfo->nOwnerGUID = pUnit->dwOwnerGUID;
}

// 0x005564D0
int __fastcall sub_005564D0_IsDroppedUnique(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_UNIQUE)
    {
        return 0;
    }

    return ITEMS_HasUniqueBeenDroppedAlready_Inlined(pGame, ITEMS_GetFileIndex(pItem));
}
