#include "D2Client.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_INVALID 6
#define offsetof(s, m) ((unsigned int)&(((s*)0)->m))

struct D2MonsterDataStrc;
struct D2GfxEntryStrc;
struct D2GfxListNodeStrc;
struct D2MotionVectorStrc;
struct D2CellBlockStrc;
struct D2OffsetTableStrc;
struct D2OffsetTableRefStrc;
struct D2RequestStrc;
struct T004DA110;
struct D2CltUnitEventStrc;
struct D2RosterInfoStrc;
struct D2DrawBoundsArgStrc;
struct D2DrawBoundsStrc;
struct T00481920;
struct D2SoundEnvironStrc;
struct D2SkillsTxt;
struct D2MonStatsTxt;
struct D2OverlayTxt;
struct D2MonStats2Txt;
struct D2MissilesTxt;
struct D2MonGfxCacheStrc;
struct PartialSparseClear;
struct PartialTableRecord;
struct PartialTableView;
struct PartialLookupRecord;
struct PartialLookupHeader;
struct D2CofLayerStrc;
struct D2CofDataStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2GfxDataStrc;
struct D2GfxMotionStrc;
struct D2LevelsTxt;
struct D2DataTablesStrc;
struct D2TokRecord;
struct D2ObjectsTxt;
struct D2ItemsTxt;

struct D2MonsterDataStrc
{
    void* pMonstatsTxt;
    unsigned char nComponent[16];
    unsigned short wNameSeed;
    unsigned short nTypeFlag;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    D2MonsterDataStrc* pMonsterData;
    unsigned char unk_18[0x14];
    D2DynamicPathStrc* pDynamicPath;
    unsigned char unk_30[0xC];
    unsigned int dwSeqSpeed;
    char unk0x40[0xE];
    unsigned char nActionFrame;
    unsigned char unk0x4F;
    unsigned char unk_50[0x10];
    D2InventoryStrc* pInventory;
    unsigned char unk_64[0x2C];
    D2CltUnitEventStrc* pCltTimerList;
    unsigned char unk_94[0x34];
    unsigned int dwFlagEx;
    unsigned char unk_CC[0x1C];
    D2UnitStrc* pRoomNext;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2GfxListNodeStrc
{
    int nMode;
    int nId;
    char unk0x08[0x8];
    D2GfxListNodeStrc* pNext;
};

struct D2GfxDataStrc
{
    D2GfxEntryStrc tEntries[20];
    D2GfxListNodeStrc* pNodeList;
};

struct D2GfxMotionStrc
{
    unsigned int dwFlags;
    D2MotionVectorStrc tA;
    D2MotionVectorStrc tB;
    D2MotionVectorStrc tD;
    D2MotionVectorStrc tC;
    char unk0x34[0xC];
    int nParam0;
    int nParam1;
};

struct D2CellBlockStrc
{
    unsigned char nCount;
    unsigned char nWidth;
    char unk0x02[0x1A];
    unsigned char pData[1];
};

struct D2OffsetTableStrc
{
    char unk0x00[0x10];
    int nOffsetsOffset;
    unsigned int nCount;
    int nFirstId;
};

struct D2OffsetTableRefStrc
{
    D2OffsetTableStrc* f_0;

    void* sub_004E0700_GetEntry(int nId);
};

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    int unk0x08[2];
    int nArg0;
    int nArg1;
    int nArg2;
    int unk0x1C[4];
    int nArg3;
    int nArg4;
    int unk0x34[10];
};

typedef int (__fastcall* UNITCALLBACKFN)(D2UnitStrc* pUnit, D2UnitStrc* pOther, void* pArg1, void* pArg2);

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10
D2GfxMotionStrc* __fastcall sub_0046F060_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060
int __fastcall sub_00464820_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall sub_006416D0_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0
int __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540

struct T004DA110
{
    int nValue;
    int nKeyA;
    int nKeyB;
    T004DA110* pNext;
};

struct D2RosterInfoStrc
{
    int dwUnitId;
    unsigned int dwPartyFlags;
    D2RosterInfoStrc* pNext;
};

struct D2LevelsTxt
{
    char unk0x00[0x09];
    unsigned char nDrawEdges;
};

struct D2DrawBoundsArgStrc
{
    char unk0x00[0x14];
    unsigned int dwFlags;
};

struct D2DrawBoundsStrc
{
    char unk0x00[0x28];
    int bActive;
    int nMinX;
    int nMaxX;
    int nMinY;
    int nMaxY;

    void sub_004DDE80_ExtendBounds(D2DrawBoundsArgStrc* pArg, int nX, int nY);
};

struct T00481920
{
    char unk0x00[0x24];
    int nEAXEnviron;
    int nEAXEnvSize;
    int nEAXEnvDiff;
    int nEAXRoomVol;
    int nEAXRoomHF;
    int nEAXDecayTime;
    int nEAXDecayHF;
    int nEAXReflect;
    int nEAXReflectDelay;
    int nEAXReverb;
    int nEAXRevDelay;
    int nEAXRoomRoll;
    int nEAXAirAbsorb;
};

struct D2SoundEnvironStrc
{
    int nEnviron;
    float f_4;
    float fEnvDiff;
    int nRoomVol;
    int f_10;
    float f_14;
    float fDecayHF;
    int nReflect;
    float fReflectDelay;
    int f_24;
    float fRevDelay;
    float fRoomRoll;
    float fAirAbsorb;
};

struct D2SkillsTxt
{
    char unk0x000[0x04];
    unsigned char nFlags[8];
    char unk0x00C[0x2C];
    unsigned int dwPrgCalc[3];
    char unk0x044[0x10];
    short wAuraStat[6];
    char unk0x060[0x20];
    short nAuraState;
    char unk0x082[0x68];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    char unk0x0F0[0x48];
    unsigned int dwCalc[4];
    char unk0x148[0xF4];
};

struct D2DataTablesStrc
{
    char unk0x000[0xC4];
    int nStatesTxtRecordCount;
    unsigned char unk_C8[0x9B0];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
    unsigned char unk_A84[0xE8];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    void* pSkillsLinker;
    int nSkillsTxtRecordCount;
    unsigned char unk_BA4[0x18];
    D2OverlayTxt* pOverlayTxt;
    int nOverlayTxtRecordCount;
};
extern "C" double __cdecl sqrt(double x); // 0x006879C0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnSoundEnvironId_0072ADE4; // 0x0072ADE4
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom(); // 0x004646A0
int __fastcall sub_004648F0_GetPathValue(D2UnitStrc* pUnit); // 0x004648F0
D2RosterInfoStrc** __fastcall sub_0047A310_GetRosterInfoList(int nUnitId); // 0x0047A310
T00481920* __fastcall sub_00481920_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920
void __fastcall sub_004C5420_CreateClientMissile(D2UnitStrc* pUnit, int nMissileId, int nSkillId, int nSkillLevel); // 0x004C5420
int __fastcall sub_004E31C0_CltDo(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004E31C0
int __fastcall D2GFX_GetResolutionMode(); // 0x004F5160
void __fastcall sub_00513C50_SetSoundEnviron(D2SoundEnvironStrc* pEnviron); // 0x00513C50
int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
int __stdcall sub_006018F0(D2CelStrc* pCel); // 0x006018F0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

struct D2MonStatsTxt
{
    char unk0x000[0x10];
    unsigned int dwCode;
    char unk0x014[0x1A8 - 0x14];
};

struct D2OverlayTxt
{
    char unk0x00[0x80];
    unsigned char nNumDirections;
    unsigned char nLocalBlood;
    unsigned short pad0x82;
};

struct D2MonStats2Txt
{
    char unk0x00[0xE8];
    unsigned char nModeFlags[4];
    unsigned char unk_EC[0x8];
    unsigned char nModeDirections[16];
};

struct D2MissilesTxt
{
    char unk0x00[0x1A0];
    unsigned char nNumDirections;
};

struct D2MonGfxCacheStrc
{
    int nModeFlags[16];
    char unk0x40[0x60];
};

extern int gdwGlobal_007A8928; // 0x007A8928
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
D2MonGfxCacheStrc* __fastcall sub_0046F9D0_GetMonGfxCache(int nMonsterId); // 0x0046F9D0
D2MissilesTxt* __fastcall DATATBLS_GetMissilesTxtRecord(int nMissileId); // 0x0046ACE0
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

struct D2ObjectsTxt
{
    char unk0x000[0x151];
    unsigned char nModeEnabled[16];
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

struct PartialSparseClear
{
    char unknown_00[0x38];
    unsigned int first;
    char unknown_3C[0xEA9C - 0x3C];
    unsigned int second;
    char unknown_EAA0[8];
    unsigned int third;
    char unknown_EAAC[4];
    unsigned int fourth;
};

struct PartialTableRecord
{
    char opaque[12];
};

struct PartialTableView
{
    char unknown_00[0xC34];
    int count;
    char unknown_C38[4];
    PartialTableRecord* records;
};

extern "C" PartialTableView* gTableView_00744304;

struct PartialLookupRecord
{
    unsigned char key;
    unsigned char first;
    unsigned char second;
    char unknown_03[6];
};

struct PartialLookupHeader
{
    unsigned char count;
    char unknown_01[0x1B];
    PartialLookupRecord records[1];
};

typedef char check_PartialSparseClear_size[sizeof(PartialSparseClear) == 0xEAB4 ? 1 : -1];

typedef char check_PartialSparseClear_first[offsetof(PartialSparseClear, first) == 0x38 ? 1 : -1];

typedef char check_PartialSparseClear_second[offsetof(PartialSparseClear, second) == 0xEA9C ? 1 : -1];

typedef char check_PartialSparseClear_third[offsetof(PartialSparseClear, third) == 0xEAA8 ? 1 : -1];

typedef char check_PartialSparseClear_fourth[offsetof(PartialSparseClear, fourth) == 0xEAB0 ? 1 : -1];

typedef char check_PartialTableRecord_size[sizeof(PartialTableRecord) == 12 ? 1 : -1];

typedef char check_PartialTableView_size[sizeof(PartialTableView) == 0xC40 ? 1 : -1];

typedef char check_PartialTableView_count[offsetof(PartialTableView, count) == 0xC34 ? 1 : -1];

typedef char check_PartialTableView_records[offsetof(PartialTableView, records) == 0xC3C ? 1 : -1];

typedef char check_PartialLookupRecord_size[sizeof(PartialLookupRecord) == 9 ? 1 : -1];

typedef char check_PartialLookupRecord_key[offsetof(PartialLookupRecord, key) == 0 ? 1 : -1];

typedef char check_PartialLookupRecord_first[offsetof(PartialLookupRecord, first) == 1 ? 1 : -1];

typedef char check_PartialLookupRecord_second[offsetof(PartialLookupRecord, second) == 2 ? 1 : -1];

typedef char check_PartialLookupHeader_records[offsetof(PartialLookupHeader, records) == 0x1C ? 1 : -1];

struct D2CofLayerStrc
{
    unsigned char nComponent;
    unsigned char bShadow;
    unsigned char bSelectable;
    unsigned char nOverrideTransLvl;
    unsigned char nNewTransLvl;
    char szWeaponClass[4];
};

struct D2CofDataStrc
{
    unsigned char nLayers;
    unsigned char unk0x01[0x1B];
    D2CofLayerStrc pLayers[1];
};

struct D2ItemsTxt
{
    char unk0x00[0x12C];
    unsigned char nTransparent;
    unsigned char nTransTbl;
};

D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit);
int __fastcall sub_0046D9F0_GetConvertedUnitType(D2UnitStrc* pUnit);
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480
extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
D2UnitStrc* __stdcall sub_0063C050_GetBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc);

static void sub_004DB290_ConvertDirection(unsigned int* pDirection, int nDirCount, int nSrcDirCount);

static int __stdcall sub_004DAF70_GetUnitModeDirections(D2UnitStrc* pUnit, int nMode, int nClassId, int nUnitType);
static void __stdcall sub_004DB1E0_SetDeathDirection(unsigned int nDirection, int bSet, D2UnitStrc* pUnit, int nDirCount, int nSrcDirCount);

// 0x0046C570
int __fastcall sub_0046C570_ForEachUnitInAdjacentRooms(D2UnitStrc* pUnit, void* pArg1, void* pArg2, UNITCALLBACKFN pfnCallback)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pOther = ppRoomList[i]->pUnitFirst; pOther; pOther = pOther->pRoomNext)
        {
            int nResult = pfnCallback(pUnit, pOther, pArg1, pArg2);
            if (nResult)
            {
                return nResult;
            }
        }
    }

    return 0;
}

// 0x0046C600
int __fastcall sub_0046C600_NearestUnitCallback(D2UnitStrc* pUnit, D2UnitStrc* pOther, D2UnitStrc** ppNearest, int* pnDistance)
{
    if (pUnit != pOther && pOther)
    {
        if (pOther->dwUnitType == 0
            || pOther->dwUnitType == 1 && pOther->dwClassId != 149 && pOther->dwClassId != 556)
        {
            if (!sub_00464820_IsDeadOrDying(pUnit))
            {
                int nDistance = sub_006416D0_UnitEdgeDistance(pUnit, pOther);
                if (nDistance < *pnDistance)
                {
                    *ppNearest = pOther;
                    *pnDistance = nDistance;
                }
            }
        }
    }

    return 0;
}

// 0x0046E5A0
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 940);

    if (nMode == -1)
    {
        nMode = sub_0046DA60_GetUnitMode(pUnit);
    }

    for (D2GfxListNodeStrc* pNode = pGfxData->pNodeList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nId == nId)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x00483360
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x004AC810
void __fastcall sub_004AC810_ToggleMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            if (bSet)
            {
                pMonsterData->nTypeFlag |= nFlag;
            }
            else
            {
                pMonsterData->nTypeFlag &= ~nFlag;
            }
        }
    }
}

// 0x004CDB40
int __fastcall sub_004CDB40_SubmitRequest(D2UnitStrc* pUnit, int nArg0, int nArg1, int nArg2, int nArg3, int nArg4)
{
    if (!pUnit)
    {
        return 0;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 1;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = nArg1;
    tRequest.nArg2 = nArg2;
    tRequest.nArg3 = nArg3;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nArg0;
    return sub_004CD540_HandleRequest(&tRequest);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004DA110
int __stdcall sub_004DA110_GetMotionAX(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nX >> 11;
    }

    return 0;
}

// 0x004DA130
int __stdcall sub_004DA130_GetMotionAY(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nY >> 11;
    }

    return 0;
}

// 0x004DA150
int __stdcall sub_004DA150_GetMotionAZ(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nZ >> 11;
    }

    return 0;
}

// 0x004DA170
int __stdcall sub_004DA170_GetMotionRawAX(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nX;
    }

    return 0;
}

// 0x004DA190
int __stdcall sub_004DA190_GetMotionRawAY(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nY;
    }

    return 0;
}

// 0x004DA1B0
int __stdcall sub_004DA1B0_GetMotionRawAZ(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nZ;
    }

    return 0;
}

// 0x004DA1D0
void __stdcall sub_004DA1D0_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->tA.nX = nX << 11;
        pMotion->tA.nY = nY << 11;
        pMotion->tA.nZ = nZ << 11;
    }
}

// 0x004DA200
void __stdcall sub_004DA200_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tB.nX = nX << 11;
            pMotion->tB.nY = nY << 11;
            pMotion->tB.nZ = nZ << 11;
        }
        else
        {
            pMotion->tB.nX = nX;
            pMotion->tB.nY = nY;
            pMotion->tB.nZ = nZ;
        }
    }
}

// 0x004DA250
void __stdcall sub_004DA250_SetMotionVectorD(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tD.nX = nX << 11;
            pMotion->tD.nY = nY << 11;
            pMotion->tD.nZ = nZ << 11;
        }
        else
        {
            pMotion->tD.nX = nX;
            pMotion->tD.nY = nY;
            pMotion->tD.nZ = nZ;
        }
    }
}

// 0x004DA2A0
void __stdcall sub_004DA2A0_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tC.nX = nX << 11;
            pMotion->tC.nY = nY << 11;
            pMotion->tC.nZ = nZ << 11;
        }
        else
        {
            pMotion->tC.nX = nX;
            pMotion->tC.nY = nY;
            pMotion->tC.nZ = nZ;
        }
    }
}

// 0x004DA2F0
void __stdcall sub_004DA2F0_SetMotionParams(D2UnitStrc* pUnit, int nParam0, int nParam1)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags |= 4;
        pMotion->nParam0 = nParam0;
        pMotion->nParam1 = nParam1;
    }
}

// 0x004DA320
int __stdcall sub_004DA320_GetMotionParam0(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nParam0;
    }

    return 0;
}

// 0x004DA640
void __stdcall sub_004DA640_SetMotionFlag1(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags |= 1;
    }
}

// 0x004DA660
int __stdcall sub_004DA660_TestMotionFlag1(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion && (pMotion->dwFlags & 1))
    {
        return 1;
    }

    return 0;
}

// 0x004DA690
void __stdcall sub_004DA690_ReplaceMotionFlag1With8(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags = pMotion->dwFlags & ~1 | 8;
    }
}

// 0x004DA6B0
int __stdcall sub_004DA6B0_TestMotionFlags(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = sub_0046F060_GetGfxMotion(pUnit);
    if (pMotion && (pMotion->dwFlags & 1) && !(pMotion->dwFlags & 8))
    {
        return 0;
    }

    return 1;
}

// 0x004DA920
void __fastcall sub_004DA920_AddGfxUtilNode(T004DA110** ppList, int nValue, int nKeyA, int nKeyB, int* pnCount, int* pnBytes)
{
    T004DA110* pNode = (T004DA110*)FOG_Alloc(sizeof(T004DA110), ".\\ENGINE\\GfxUtil.cpp", 128, 0);
    D2_ASSERT(pNode, 129);

    *pnBytes += sizeof(T004DA110);
    memset(pNode, 0, sizeof(T004DA110));
    pNode->nValue = nValue;
    pNode->nKeyA = nKeyA;
    pNode->nKeyB = nKeyB;
    pNode->pNext = *ppList;
    *ppList = pNode;
    ++*pnCount;
}

// 0x004DA990
T004DA110* __fastcall sub_004DA990_FindGfxUtilNode(T004DA110* pList, int nKeyA, int nKeyB)
{
    for (T004DA110* pNode = pList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKeyB == nKeyB && pNode->nKeyA == nKeyA)
        {
            return pNode;
        }
    }

    return 0;
}

#include "gen/data/Source/D2Client/ENGINE/GfxUtil.inc"

static __forceinline D2MonStatsTxt* GFXUTIL_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x004DAA00
int __fastcall sub_004DAA00_GetModeArg(D2UnitStrc* pUnit, int nType, int nClass)
{
    switch (nType)
    {
    case 2:
    {
        D2TokRecord* pRecord = DATATBLS_GetObjModeTypeTxtRecord(nClass, 0);
        if (!pRecord)
        {
            return 0;
        }
        return pRecord->dwCode;
    }
    case 1:
    {
        D2MonStatsTxt* pMonStatsTxtRecord = GFXUTIL_GetMonStatsTxtRecord(nClass);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }
        return pMonStatsTxtRecord->dwCode;
    }
    case 0:
    {
        D2TokRecord* pRecord = DATATBLS_GetPlrModeTypeTxtRecord(nClass, 0);
        if (!pRecord)
        {
            return 0;
        }
        return pRecord->dwCode;
    }
    default:
        return 0;
    }
}

// 0x004DAA70
void __fastcall sub_004DAA70_GetItemMode(D2UnitStrc* pUnit, int* pMode)
{
    switch (*pMode)
    {
    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
        *pMode = 4;
        break;

    case 3:
    case 5:
        *pMode = 3;
        break;
    }
}

// 0x004DAB40
int __fastcall sub_004DAB40_IsCelOnScreen(D2CelStrc* pCel, int nX, int nY, int bFlag)
{
    int nHeight = sub_006018F0(pCel);
    int nBottom = sub_00601950(pCel) + nY;
    int nLeft = sub_00601920(pCel) + nX;
    int nWidth = sub_006018C0(pCel);
    if (bFlag)
    {
        nLeft -= nHeight;
        nWidth += nHeight;
    }

    if (nLeft > gnGlobal_0071146C)
    {
        return 0;
    }

    if (nLeft + nWidth < 0)
    {
        return 0;
    }

    if (nBottom - nHeight > gnGlobal_00711470)
    {
        return 0;
    }

    return nBottom + nHeight >= 0;
}

static D2OverlayTxt* DATATBLS_GetOverlayTxtRecordInline(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }

    return 0;
}

// 0x004DAD50
static int sub_004DAD50_GetOverlayDirections(int nOverlay)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecordInline(nOverlay);
    if (!pOverlayTxt)
    {
        return 1;
    }

    return pOverlayTxt->nNumDirections;
}

void __fastcall sub_004DB2E0_GetUnitDirection(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nMode, unsigned int* pDirection, int* pIndex, int* pDirCount, int nSrcDirCount, int bSet)
{
    if (*pDirection >= 64)
    {
        *pDirCount = 1;
        *pIndex = 0;
        return;
    }

    *pDirCount = sub_004DAF70_GetUnitModeDirections(pUnit, nMode, nClassId, nUnitType);
    if (bSet)
    {
        sub_004DB290_ConvertDirection(pDirection, *pDirCount, nSrcDirCount);
        sub_004DB1E0_SetDeathDirection(*pDirection, bSet, pUnit, *pDirCount, nSrcDirCount);
    }

    *pIndex = sub_00600E20_GetDirectionIndex64B(*pDirection, nSrcDirCount);
}

// 0x004DAE60
int __fastcall sub_004DAE60_UnitSupportsMode(D2UnitStrc* pUnit, int nMode)
{
    if (nMode >= 16)
    {
        return 0;
    }

    int nCurrentMode;
    int nUnitType;
    int nClassId;

    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nCurrentMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nCurrentMode, ".\\ENGINE\\GfxUtil.cpp", 603);

    switch (nUnitType)
    {
    case UNIT_PLAYER:
        switch (nMode)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 8:
        case 9:
            return 1;
        }
        break;

    case UNIT_MONSTER:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (pMonStats2TxtRecord && (pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7]))
        {
            return 1;
        }
        break;
    }

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        if (pObjectsTxtRecord && pObjectsTxtRecord->nModeEnabled[nMode] == 1)
        {
            return 1;
        }
        break;
    }

    case UNIT_ITEM:
        if (nMode == 1)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// 0x004DAF70
static int __stdcall sub_004DAF70_GetUnitModeDirections(D2UnitStrc* pUnit, int nMode, int nClassId, int nUnitType)
{
    if (nMode < 0)
    {
        return 1;
    }

    int nDirections = 1;
    switch (nUnitType)
    {
    case 0:
        if (!gdwGlobal_007A8928 && pUnit == sub_00463DD0())
        {
            nDirections = 16;
        }
        else
        {
            nDirections = 8;
        }
        break;

    case 1:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (pMonStats2TxtRecord)
        {
            nDirections = pMonStats2TxtRecord->nModeDirections[nMode];
            if (nDirections == 8)
            {
                D2MonGfxCacheStrc* pCache = sub_0046F9D0_GetMonGfxCache(nClassId);
                if (pCache && !pCache->nModeFlags[nMode])
                {
                    nDirections = 4;
                }
            }
        }
        break;
    }

    case 3:
    {
        D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(nClassId);
        if (pMissilesTxtRecord)
        {
            nDirections = pMissilesTxtRecord->nNumDirections;
        }
        break;
    }

    case 6:
        nDirections = sub_004DAD50_GetOverlayDirections(nClassId);
        break;
    }

    return nDirections;
}

// 0x004DB040
extern "C" void* __fastcall sub_004DB040_identity(void* pointer)
{
    return pointer;
}

extern "C" int __fastcall sub_004DB180_range(const int* record)
{
    if (record && *record >= 0 && *record <= 2)
        return 1;
    return 0;
}

extern "C" PartialTableRecord* __fastcall sub_004E4640_boundedTable(int index)
{
    if (index >= 0 && index < gTableView_00744304->count)
        return &gTableView_00744304->records[index];
    return gTableView_00744304->records;
}

// 0x004DB050
int __fastcall sub_004DB050_GetCofLayerOverrideTransLvl(unsigned char* pData, int nComponent)
{
    int nResult = 0;
    if (pData && nComponent < 0x10)
    {
        const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pData;
        pData += 0x1C;
        for (int i = 0; i < pHeader->nLayers; ++i, pData += sizeof(D2CofLayerStrc))
        {
            if (((D2CofLayerStrc*)pData)->nComponent == nComponent)
            {
                nResult = ((D2CofLayerStrc*)pData)->nOverrideTransLvl;
                break;
            }
        }
    }
    return nResult;
}

// 0x004DB090
int __fastcall sub_004DB090_GetCofLayerShadow(void* pCof, int nComponent)
{
    int nResult = 0;
    if (pCof && nComponent < 0x10)
    {
        const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pCof;
        pCof = ((D2CofDataStrc*)pCof)->pLayers;
        for (int i = 0; i < pHeader->nLayers; ++i)
        {
            D2CofLayerStrc* pLayer = (D2CofLayerStrc*)pCof;
            if (pLayer->nComponent == nComponent)
            {
                nResult = pLayer->bShadow;
                break;
            }
            pCof = pLayer + 1;
        }
    }
    return nResult;
}

// 0x004DB110
unsigned char* __fastcall sub_004DB110_GetCellPtr(D2CellBlockStrc* pBlock, int nX, int nY)
{
    if (!pBlock)
    {
        return 0;
    }

    return &pBlock->pData[(pBlock->nWidth * nX + nY + 9) * pBlock->nCount + pBlock->nWidth];
}

// 0x004DB140
int __fastcall sub_004DB140_GetCofLayerNewTransLvl(unsigned char* pData, int nComponent)
{
    if (!pData)
    {
        return 5;
    }
    if (nComponent >= 0x10)
    {
        return 5;
    }
    const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pData;
    pData += 0x1C;
    for (int i = 0; i < pHeader->nLayers; ++i, pData += sizeof(D2CofLayerStrc))
    {
        if (((D2CofLayerStrc*)pData)->nComponent == nComponent)
        {
            return ((D2CofLayerStrc*)pData)->nNewTransLvl;
        }
    }
    return 5;
}

// 0x004DB180
int __fastcall sub_004DB180_IsGfxUnitType(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType >= 0 && pUnit->dwUnitType <= 2)
    {
        return 1;
    }

    return 0;
}

// 0x004DB1C0
void __fastcall sub_004DB1C0_SetGfxEntryByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
    {
        pGfxData->tEntries[nIndex].nValue = nValue;
    }
}

static int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

static int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x004DB1E0
static void __stdcall sub_004DB1E0_SetDeathDirection(unsigned int nDirection, int bSet, D2UnitStrc* pUnit, int nDirCount, int nSrcDirCount)
{
    if (!bSet)
    {
        return;
    }

    int nUnitType = UNITS_GetUnitTypeInline(pUnit);
    int nClassId = UNITS_GetClassIdInline(pUnit);
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\GfxUtil.cpp", 0x53C);
    switch (nUnitType)
    {
    case 0:
        if ((nMode == 0 || nMode == 17) && nDirCount != nSrcDirCount)
        {
            sub_006488A0_SetDirection(pUnit->pDynamicPath, nDirection);
        }
        break;

    case 1:
        if ((nMode == 0 || nMode == 12) && nDirCount != nSrcDirCount)
        {
            sub_006488A0_SetDirection(pUnit->pDynamicPath, nDirection);
        }
        break;
    }
}

// 0x004DB290
static void sub_004DB290_ConvertDirection(unsigned int* pDirection, int nDirCount, int nSrcDirCount)
{
    if (nSrcDirCount == 8)
    {
        if (nDirCount == 4)
        {
            const unsigned int nIndex = *(unsigned int*)pDirection * 8 >> 6;
            *pDirection = (unsigned int)sub_00600CB0_ConvertDirection(nIndex, 8, nDirCount, 0) * 64 / 8;
        }
    }
    else if (nSrcDirCount == 16 && nDirCount == 8)
    {
        const unsigned int nIndex = *(unsigned int*)pDirection * 16 >> 6;
        *pDirection = (unsigned int)sub_00600CB0_ConvertDirection(nIndex, 16, nDirCount, 0) * 64 / 16;
    }
}

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

// 0x004DB360
int __fastcall sub_004DB360_GetCompTransparency(D2UnitStrc* pUnit, int nComponent, int* pOut, int nItemId)
{
    const int nType = sub_0046D9F0_GetConvertedUnitType(pUnit);
    switch (nType)
    {
    case 1:
    {
        const int nStat = STATLIST_UnitGetStatValue(pUnit, 0xB5, 0);
        if (nStat <= 0)
            break;
        if (nStat > 0xF)
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!pInventory)
                return 0;
            for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
            {
                D2UnitStrc* pChecked = INVENTORY_UnitIsItem(pItem);
                if (pChecked && sub_006280A0(pChecked, 0x400000, 0x5E6, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
                {
                    *pOut = 1;
                    return 1;
                }
            }
            return 0;
        }
        *pOut = 1;
        return 1;
    }
    case 0:
        if (STATLIST_UnitGetStatValue(pUnit, 0xB5, 0))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }

    if (nItemId != -1)
    {
        D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(nItemId);
        if (pTxt && pTxt->nTransparent)
        {
            *pOut = pTxt->nTransTbl;
            return 1;
        }
    }

    if (nType)
        return 0;

    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (STATES_IsUnitShapeShiftedInline(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    if (!pInventory)
        return 0;

    switch (nComponent)
    {
    case 7:
    {
        D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, 7);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x627, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 2;
            return 1;
        }
        break;
    }
    case 6:
    {
        D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, 6);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x61C, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }
    case 5:
    {
        D2UnitStrc* pItem = sub_0063C050_GetBodyLocItem(pInventory, 5);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x611, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }
    }

    return 0;
}

// 0x004DC110
D2CltUnitEventStrc* __fastcall sub_004DC110_AddCltUnitEvent(D2UnitStrc* pUnit, int nType, int nParam1, int nParam2, int nParam3, int nParam4, int nParam5)
{
    if (!pUnit)
    {
        return 0;
    }

    D2CltUnitEventStrc* pEvent = (D2CltUnitEventStrc*)FOG_AllocPool(pUnit->pMemoryPool, sizeof(D2CltUnitEventStrc), ".\\UNIT\\CUnitEvent.cpp", 72, 0);
    memset(pEvent, 0, sizeof(D2CltUnitEventStrc));
    pEvent->nParam1 = nParam1;
    pEvent->nParam2 = nParam2;
    pEvent->nParam3 = nParam3;
    pEvent->nType = nType;
    pEvent->pNext = pUnit->pCltTimerList;
    pEvent->f_4 = nParam4;
    pEvent->f_8 = nParam5;
    if (pUnit->pCltTimerList)
    {
        pUnit->pCltTimerList->pPrevious = pEvent;
    }
    pUnit->pCltTimerList = pEvent;
    return pEvent;
}

// 0x004DC3E0
void __fastcall sub_004DC3E0_TogglePvpFlag(int nUnitId1, int nUnitId2, unsigned int nFlags, int bSet)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            if (bSet)
            {
                pRosterInfo->dwPartyFlags |= nFlags;
            }
            else
            {
                pRosterInfo->dwPartyFlags &= ~nFlags;
            }
            return;
        }
    }
}

// 0x004DC440
unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo->dwPartyFlags & nFlags;
        }
    }

    return 0;
}

// 0x004DC4C0
void __fastcall sub_004DC4C0_SetPvpFlagsLow(int nUnitId1, int nUnitId2, unsigned int nFlags)
{
    D2RosterInfoStrc** ppRosterInfo = sub_0047A310_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            pRosterInfo->dwPartyFlags &= 0xFFFF0000;
            pRosterInfo->dwPartyFlags |= nFlags;
            return;
        }
    }
}

// 0x004DDE00
int __stdcall sub_004DDE00_TestLevelDrawEdges(int bArg)
{
    D2ActiveRoomStrc* pRoom = sub_004646A0_GetPlayerRoom();
    if (pRoom)
    {
        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
        if (pLevelsTxtRecord->nDrawEdges && !bArg && D2GFX_GetResolutionMode() == 2)
        {
            return 1;
        }
    }

    return 0;
}

// 0x004DDE80
void D2DrawBoundsStrc::sub_004DDE80_ExtendBounds(D2DrawBoundsArgStrc* pArg, int nX, int nY)
{
    pArg->dwFlags |= 0x20000;
    if (bActive)
    {
        if (nX < nMinX)
        {
            nMinX = nX;
        }
        if (nX > nMaxX)
        {
            nMaxX = nX;
        }
        if (nY < nMinY)
        {
            nMinY = nY;
        }
        if (nY > nMaxY)
        {
            nMaxY = nY;
        }
    }
}

// 0x004DF6C0
void __fastcall sub_004DF6C0_ApplySoundEnviron(int nEnvironId)
{
    if (nEnvironId == gnSoundEnvironId_0072ADE4)
    {
        return;
    }

    T00481920* pTxt = sub_00481920_GetSoundEnvironTxtRecord(nEnvironId);
    if ((sub_00514C90_GetSoundMode() == 2 || !nEnvironId) && sub_00513B70_IsSoundEnvironEnabled())
    {
        D2SoundEnvironStrc tEnviron;
        tEnviron.nEnviron = pTxt->nEAXEnviron;
        tEnviron.f_4 = pTxt->nEAXEnvSize / 1000.0;
        tEnviron.fEnvDiff = pTxt->nEAXEnvDiff / 1000.0;
        tEnviron.nRoomVol = pTxt->nEAXRoomVol;
        tEnviron.f_10 = pTxt->nEAXRoomHF;
        tEnviron.f_14 = pTxt->nEAXDecayTime / 1000.0;
        tEnviron.fDecayHF = pTxt->nEAXDecayHF / 1000.0;
        tEnviron.nReflect = pTxt->nEAXReflect;
        tEnviron.fReflectDelay = pTxt->nEAXReflectDelay / 1000.0;
        tEnviron.f_24 = pTxt->nEAXReverb;
        tEnviron.fRevDelay = pTxt->nEAXRevDelay / 1000.0;
        tEnviron.fRoomRoll = pTxt->nEAXRoomRoll / 1000.0;
        tEnviron.fAirAbsorb = pTxt->nEAXAirAbsorb / 1000.0;
        sub_00513C50_SetSoundEnviron(&tEnviron);
    }

    gnSoundEnvironId_0072ADE4 = nEnvironId;
}

// 0x004E0700
void* D2OffsetTableRefStrc::sub_004E0700_GetEntry(int nId)
{
    D2OffsetTableStrc* pTable = this->f_0;
    if (!pTable)
    {
        return 0;
    }

    unsigned int nIndex = nId - pTable->nFirstId;
    if (nIndex >= pTable->nCount)
    {
        return 0;
    }

    return (char*)pTable + *(int*)((char*)pTable + pTable->nOffsetsOffset + nIndex * 4);
}

// 0x004E0C60
int __fastcall sub_004E0C60_CltDoResetActionFrame(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    pUnit->nActionFrame = 0;
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    return 1;
}

// 0x004E0F40
int __fastcall sub_004E0F40_CltDoSetAnimFrameFromCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel));
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    }

    return 1;
}

// 0x004E12F0
int __fastcall sub_004E12F0_CltDoResetActionFrame2(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    pUnit->nActionFrame = 0;
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    return 1;
}

// 0x004E24D0
int __fastcall sub_004E24D0_CltDoMissileA(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wCltMissileA;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004C5420_CreateClientMissile(pUnit, nMissileId, nSkillId, nSkillLevel);
        return 1;
    }

    return 0;
}

// 0x004E3330
int __fastcall sub_004E3330_CltDoTest(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return sub_004E31C0_CltDo(pUnit, nSkillId, nSkillLevel) != 0;
}

// 0x004E4060
float __stdcall sub_004E4060_SqrtF(float fValue)
{
    return (float)sqrt(fValue);
}

// 0x004E4080
float __cdecl sub_004E4080_SqrtFCdecl(float fValue)
{
    return (float)sqrt(fValue);
}

// 0x004E4130
float __stdcall sub_004E4130_Length2D(float fX, float fY)
{
    float fLengthSquared = fX * fX + fY * fY;
    return (float)sqrt(fLengthSquared);
}

// 0x004E4160
float __stdcall sub_004E4160_LengthSquared2D(float fX, float fY)
{
    return (float)(fX * fX + fY * fY);
}

// 0x004F20C0
int __fastcall sub_004F20C0_CltDoSetParamFromCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nValue = sub_004648F0_GetPathValue(pUnit);
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!nValue)
    {
        SKILLS_SetParam1(pSkill, 0);
    }
    else
    {
        SKILLS_SetParam1(pSkill, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    }

    return 1;
}

// 0x004F34D0
int __fastcall sub_004F34D0_CltDoMissileC(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wCltMissileC;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        sub_004C5420_CreateClientMissile(pUnit, nMissileId, nSkillId, nSkillLevel);
    }

    return 1;
}
