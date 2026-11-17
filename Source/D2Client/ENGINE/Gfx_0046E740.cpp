#include "D2Client.h"

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GfxLayerStrc;
struct D2HashedFileEntryStrc;
struct D2HashedFileStrc;
struct D2GfxListNodeStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2MonCofInfoStrc;
struct D2CofModeEntryStrc;
struct D2GfxNodeTargetStrc;
struct D2MonGfxCacheStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x60 - 0x08];
    D2InventoryStrc* pInventory;
    char unk0x64[0xC8 - 0x64];
    unsigned int dwFlagEx;
    int unk0xCC[7];
    D2UnitStrc* pRoomNext;
};

struct D2HashedFileEntryStrc
{
    D2HashedFileEntryStrc* pNext;
    unsigned int nFlags;
    int nSize;
    union
    {
        char szName[8];
        unsigned int dwName[2];
    };
    unsigned char* pData;
    int nUnk0x18;
};

struct D2HashedFileStrc
{
    int f_0;
    unsigned char* pData;
    unsigned int nSize;
    D2HashedFileEntryStrc* f_C[0x200];
};

struct D2GfxListNodeStrc
{
    int nMode;
    int nId;
    union
    {
        D2HashedFileEntryStrc* f_8;
        D2GfxNodeTargetStrc* pTarget;
    };
    int f_C;
    D2GfxListNodeStrc* pNext;
};

struct D2GfxDataStrc
{
    char unk0x00[0x28];
    D2GfxListNodeStrc* pList;
};

struct D2ObjectsTxt
{
    char unk0x000[0x13F];
    unsigned char nModeEnabled[16];
};

struct D2MonStatsTxt
{
    char unk0x00[0x10];
    unsigned int dwCode;
    char unk0x14[0x18 - 0x14];
    union
    {
        short nMonStatsEx;
        short wMonStatsEx;
    };
    char unk0x1A[0x1A8 - 0x1A];
};

struct D2MonStats2Txt
{
    char unk0x00[0x04];
    unsigned char nFlags[4];
    char unk0x08[0x10 - 0x08];
    unsigned int dwBaseW;
    char unk0x14[0xF0 - 0x14];
    union
    {
        unsigned char aModeFlags[0x44];
        unsigned char nModeFlags[4];
    };
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    void* pMonStatsLinker;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xC];
    D2MonStats2Txt* pMonStats2Txt;
    void* pMonStats2Linker;
    int nMonStats2TxtRecordCount;
};

struct D2GfxLayerHeaderStrc
{
    union
    {
        unsigned char nLayers;
        unsigned char nCount;
    };
    unsigned char unk0x01;
    unsigned char nArg;
};

struct D2CelContextStrc
{
    char unk0x00[0x34];
    union
    {
        int nUnk0x34;
        int nArg34;
    };
    int unk0x38[3];
    int nFlags44;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330
extern "C" char* __cdecl _strlwr(char* szString); // 0x006864E1
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
D2GfxDataStrc* __fastcall sub_00463E10_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
int __fastcall sub_0046D9F0_GetConvertedUnitType(D2UnitStrc* pUnit); // 0x0046D9F0
int __fastcall sub_0046E570_GetNodeValue(D2UnitStrc* pUnit, int nMode); // 0x0046E570
D2GfxListNodeStrc* __fastcall sub_0046E5A0_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void __fastcall sub_0046EC80_FreeGfxNodes(D2UnitStrc* pUnit); // 0x0046EC80
void __fastcall sub_0046F020_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue); // 0x0046F020
int __fastcall sub_004DB180_IsGfxUnitType(D2UnitStrc* pUnit); // 0x004DB180
unsigned char __fastcall sub_004DB1A0(D2UnitStrc* pUnit, int nIndex); // 0x004DB1A0
void __fastcall sub_004DB1C0_SetGfxEntryByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue); // 0x004DB1C0
extern "C" D2GfxLayerHeaderStrc* __fastcall sub_004DB040_identity(void* pGfx); // 0x004DB040
int __fastcall sub_004DBCF0_FillMonsterCelContextEx(D2CelContextStrc* pContext, int nA, int nB, int nLayer, int nMode, unsigned int dwCode, D2HashedFileEntryStrc* pEntry, D2MonCofInfoStrc* pInfo, D2MonStatsTxt* pMonStats, int nIndex); // 0x004DBCF0
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __stdcall D2Common_10885_COMPOSIT_unk(D2UnitStrc* pUnit, char* szPath, int* pWeaponClassCode, int bAddPathPrefix, int a5, D2InventoryStrc* pInventory, int nAnimMode); // 0x0064FA00
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2CofModeEntryStrc gaCofModeCodes_00712B04[]; // 0x00712B04
extern int gdwGlobal_007A8918; // 0x007A8918
extern D2HashedFileStrc gtHashedFile_007A78F0; // 0x007A78F0
extern D2HashedFileStrc gtHashedFile_007A8100; // 0x007A8100
static int __stdcall sub_0046E740_LoadGfxNode(int* pValue, int nIndex, D2UnitStrc* pUnit);
static int sub_0046EA50_LoadGfxNodeSetByte(D2UnitStrc* pUnit, int nIndex);

typedef unsigned long DWORD;

struct D2ActiveRoomStrc
{
    int unk0x00[29];
    D2UnitStrc* pUnitFirst;
};

struct D2GfxNodeTargetStrc
{
    int unk0x00[5];
    D2GfxLayerStrc* pLayer;
};

struct D2MonGfxCacheStrc
{
    int f_0[20];
    int aPending[20];
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80
D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx); // 0x004DB040
void __fastcall sub_004DB2E0_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pContext, D2UnitStrc* pItem, int nArg3, int nArg4, int nArg5, int* pOut, unsigned char nArg7, int nArg8); // 0x004DBB50
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790
extern D2MonGfxCacheStrc* gpPoolBlock_007A80FC; // 0x007A80FC
extern int gbPreloadForce_007A8920; // 0x007A8920
extern int gdwGlobal_007A8928; // 0x007A8928
extern int gdwGlobal_007A8910; // 0x007A8910

static int __stdcall sub_0046E690_FindGfxNode(int nId, D2GfxListNodeStrc** ppNode, int* pValue, D2UnitStrc* pUnit, int nMode);
static void sub_0046F9E0_LoadMonsterModeGfx(D2UnitStrc* pUnit, int nIndex);

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    return (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
}

inline D2MonStats2Txt* DATATBLS_GetMonStats2TxtRecordInl(int nRecordId)
{
    if (nRecordId >= 0 && nRecordId < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nRecordId];
    }
    return 0;
}

static __declspec(noinline) unsigned int sub_0046DB90_HashName(const char* szName)
{
    D2_ASSERT(strlen(szName) < 8, 0x79);
    const unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nBucket = (nHash >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    return nBucket & 0x1FF;
}

static __declspec(noinline) void __fastcall sub_0046DBF0_GetBaseName(char* szDest, const char* szPath)
{
    const int nPathLength = strlen(szPath);
    if (szPath[nPathLength - 4] == 0x2E)
    {
        const char* pExt = szPath + nPathLength - 4;
        int nLength = 0;
        while (*pExt != 0x5C)
        {
            --pExt;
            ++nLength;
        }
        --nLength;
        strncpy(szDest, pExt + 1, nLength);
        szDest[nLength] = 0;
    }
}

D2HashedFileEntryStrc* __stdcall sub_0046DC40_FindHashedEntry(D2HashedFileStrc* pTable, const char* szPath)
{
    char szName[0x104] = { 0 };
    sub_0046DBF0_GetBaseName(szName, szPath);
    _strlwr(szName);
    for (D2HashedFileEntryStrc* pEntry = pTable->f_C[sub_0046DB90_HashName(szName)]; pEntry; pEntry = pEntry->pNext)
    {
        if (*(unsigned int*)&szName[0] == pEntry->dwName[0] && *(unsigned int*)&szName[4] == pEntry->dwName[1])
        {
            return pEntry;
        }
    }
    return 0;
}

static D2HashedFileEntryStrc* __stdcall sub_0046DCC0_LoadHashedEntry(D2HashedFileStrc* pTable, const char* szPath)
{
    char szName[0x104] = { 0 };
    char* pName = szName;
    sub_0046DBF0_GetBaseName(pName, szPath);
    _strlwr(pName);
    if (!sub_0046DC40_FindHashedEntry(pTable, pName))
    {
        D2HashedFileEntryStrc* pEntry = (D2HashedFileEntryStrc*)FOG_Alloc(sizeof(D2HashedFileEntryStrc), ".\\ENGINE\\Gfx.cpp", 0xDC, 0);
        memset(pEntry, 0, sizeof(D2HashedFileEntryStrc));
        pEntry->nFlags |= 1;
        strcpy(pEntry->szName, szName);
        pEntry->pData = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szPath, (unsigned int*)&pEntry->nSize, ".\\ENGINE\\Gfx.cpp", 0xE0);
        if (!pEntry->pData)
        {
            return 0;
        }

        D2_ASSERT(pEntry->pData[2] <= 0x40, 0xEC);
        const unsigned int nBucket = sub_0046DB90_HashName(szName);
        pEntry->pNext = pTable->f_C[nBucket];
        pTable->f_C[nBucket] = pEntry;
        gdwGlobal_007A8918 += pEntry->nSize + sizeof(D2HashedFileEntryStrc);
        return pEntry;
    }
    return 0;
}

static int sub_0046E610_RemoveGfxNode(D2UnitStrc* pUnit, D2HashedFileEntryStrc* pEntry)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x3C8);

    D2GfxListNodeStrc* pPrev = 0;
    for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
    {
        if (pNode->f_8 == pEntry)
        {
            D2GfxListNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x3D0, 0);
            if (!pPrev)
            {
                pGfxData->pList = pNext;
            }
            else
            {
                pPrev->pNext = pNext;
            }
            return 1;
        }
        pPrev = pNode;
    }
    return 0;
}

// 0x0046E740
static int __stdcall sub_0046E740_LoadGfxNode(int* pValue, int nIndex, D2UnitStrc* pUnit)
{
    int nId = 0;
    char szPath[0x104] = { 0 };
    if (!sub_004DB180_IsGfxUnitType(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pOwner;
    D2InventoryStrc* pInventory;
    if (STATES_IsUnitShapeShiftedInl(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    D2Common_10885_COMPOSIT_unk(pUnit, szPath, &nId, 1, 1, pInventory, nIndex);
    if (!szPath[0])
    {
        return 0;
    }

    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return 0;
    }

    if (sub_0046E690_FindGfxNode(nId, (D2GfxListNodeStrc**)&pValue, pValue, pUnit, nIndex))
    {
        D2GfxListNodeStrc* pNewNode = (D2GfxListNodeStrc*)FOG_Alloc(sizeof(D2GfxListNodeStrc), ".\\ENGINE\\Gfx.cpp", 0x434, 0);
        D2_ASSERT(pNewNode, 0x435);
        memset(pNewNode, 0, sizeof(D2GfxListNodeStrc));

        D2HashedFileStrc* pTable = !sub_0046D9F0_GetConvertedUnitType(pUnit) ? &gtHashedFile_007A8100 : &gtHashedFile_007A78F0;
        D2HashedFileEntryStrc* pEntry = sub_0046DC40_FindHashedEntry(pTable, szPath);
        if (!pEntry)
        {
            pEntry = sub_0046DCC0_LoadHashedEntry(pTable, szPath);
            if (!pEntry)
            {
                return 0;
            }
        }

        pNewNode->nMode = nIndex;
        int& nNodeId = pNewNode->nId;
        nNodeId = nId;
        pNewNode->f_8 = pEntry;
        pNewNode->pNext = pGfxData->pList;
        pGfxData->pList = pNewNode;
    }

    return sub_0046E570_GetNodeValue(pUnit, nIndex);
}

static int sub_0046E8D0_LoadMonsterGfx(D2UnitStrc* pUnit, int nIndex)
{
    int nUnitType;
    int nMode;
    int nClassId;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0x464);
    if (sub_0046C140_TestMonModeFlag(nClassId, nIndex))
    {
        if (sub_004DB1A0(pUnit, nIndex))
        {
            return 0;
        }
        return sub_0046EA50_LoadGfxNodeSetByte(pUnit, nIndex);
    }
    D2_ASSERT(0, 0x486);
    return 0;
}

static int sub_0046E980_LoadObjectGfx(D2UnitStrc* pUnit, int nIndex)
{
    int nValue;
    int nUnitType;
    int nMode;
    int nClassId;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0x4BE);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
    D2_ASSERT(pObjectsTxtRecord, 0x4C2);
    if (pObjectsTxtRecord->nModeEnabled[nIndex] == 1)
    {
        if (sub_004DB1A0(pUnit, nIndex))
        {
            return 0;
        }
        D2_ASSERT(sub_0046E740_LoadGfxNode(&nValue, nIndex, pUnit), 0x4D4);
        sub_004DB1C0_SetGfxEntryByte(pUnit, nIndex, 1);
        return 1;
    }
    D2_ASSERT(0, 0x4DC);
    return 0;
}

static int sub_0046EA50_LoadGfxNodeSetByte(D2UnitStrc* pUnit, int nIndex)
{
    int nValue;
    if (!sub_0046E740_LoadGfxNode(&nValue, nIndex, pUnit))
    {
        return 0;
    }
    sub_004DB1C0_SetGfxEntryByte(pUnit, nIndex, 1);
    return 1;
}

static void __stdcall sub_0046F490_BuildMonsterCofPath(int nMode, char* szPath, unsigned int* pCode, int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = DATATBLS_GetMonStats2TxtRecordInl(pMonStatsTxtRecord->nMonStatsEx);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    unsigned int dwMonCode = pMonStatsTxtRecord->dwCode;
    D2MonModeTxt* pModeTxtRecord = sub_0065B500_GetModeTxtRecord(nMode, 1);
    D2_ASSERT(pModeTxtRecord, 0xE86);

    unsigned int dwToken = pModeTxtRecord->dwToken;
    if (nMode && nMode != 0xC)
    {
        *pCode = pMonStats2TxtRecord->dwBaseW;
    }
    else if (pMonStats2TxtRecord->nFlags[2] & gdwBitMasks[0])
    {
        *pCode = pMonStats2TxtRecord->dwBaseW;
    }
    else
    {
        *pCode = 0x20687468;
    }

    for (unsigned int i = 0; i < gnCofModeCodeCount_00712B0C; ++i)
    {
        if (nMode == gaCofModeCodes_00712B04[i].nMode)
        {
            dwToken = gaCofModeCodes_00712B04[i].dwCode;
        }
    }

    char szToken[4];
    char szWeapon[4];
    char szMonster[4];
    const unsigned char* pCodeBytes = (const unsigned char*)pCode;
    const unsigned char* pMonBytes = (const unsigned char*)&dwMonCode;
    szWeapon[0] = pCodeBytes[0] == 0x20 ? 0 : pCodeBytes[0];
    szWeapon[1] = pCodeBytes[1] == 0x20 ? 0 : pCodeBytes[1];
    szWeapon[2] = pCodeBytes[2] == 0x20 ? 0 : pCodeBytes[2];
    szWeapon[3] = 0;
    szMonster[0] = pMonBytes[0] == 0x20 ? 0 : pMonBytes[0];
    szMonster[1] = pMonBytes[1] == 0x20 ? 0 : pMonBytes[1];
    szMonster[2] = pMonBytes[2] == 0x20 ? 0 : pMonBytes[2];
    szMonster[3] = 0;
    szToken[0] = (unsigned char)dwToken == 0x20 ? 0 : (unsigned char)dwToken;
    szToken[1] = (unsigned char)(dwToken >> 8) == 0x20 ? 0 : (unsigned char)(dwToken >> 8);
    szToken[2] = (unsigned char)(dwToken >> 16) == 0x20 ? 0 : (unsigned char)(dwToken >> 16);
    szToken[3] = 0;
    wsprintfA(szPath, "%s\\%s\\COF\\%s%s%s.COF", "DATA\\GLOBAL\\MONSTERS", szMonster, szMonster, szToken, szWeapon);
}

static void __stdcall sub_0046F650_LoadMonsterCof(D2MonStatsTxt* pMonStatsTxtRecord, int nMode, int bLoadNow, D2MonCofInfoStrc* pInfo)
{
    char szPath[0x104] = { 0 };
    unsigned int dwCode;
    sub_0046F490_BuildMonsterCofPath(nMode, szPath, &dwCode, pInfo->nMonsterId);

    D2HashedFileEntryStrc* pEntry = sub_0046DC40_FindHashedEntry(&gtHashedFile_007A78F0, szPath);
    if (!pEntry)
    {
        pEntry = sub_0046DCC0_LoadHashedEntry(&gtHashedFile_007A78F0, szPath);
        D2_ASSERT(pEntry, 0xEC3);
    }

    unsigned char* pData = pEntry->pData;
    D2_ASSERT(pData, 0xEC9);
    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_identity(pData);
    D2_ASSERT(pHeader, 0xECB);
    unsigned char* pOrder = sub_004DB110_GetLayerOrder(pData, 0, 0);
    D2_ASSERT(pOrder, 0xED0);

    for (int i = 0; i < pHeader->nLayers; ++i)
    {
        const int nLayer = pOrder[i];
        D2_ASSERT(nLayer < 0x10, 0xED7);
        if (pInfo->nCount)
        {
            for (unsigned int j = 0; j < pInfo->nCount; ++j)
            {
                D2CelContextStrc tContext;
                memset(&tContext, 0, sizeof(tContext));
                if (sub_004DBCF0_FillMonsterCelContextEx(&tContext, 0, 0, nLayer, nMode, dwCode, pEntry, pInfo, pMonStatsTxtRecord, j))
                {
                    if (bLoadNow)
                    {
                        if (!sub_006001F0(&tContext, 1, 1))
                        {
                            tContext.nUnk0x34 = 0;
                            sub_006004E0_LoadSprite(&tContext);
                        }
                    }
                    else
                    {
                        sub_006001F0(&tContext, 0, 0);
                    }
                }
            }
        }
        else
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            if (sub_004DBCF0_FillMonsterCelContextEx(&tContext, 0, 0, nLayer, nMode, dwCode, pEntry, pInfo, pMonStatsTxtRecord, 0))
            {
                if (bLoadNow)
                {
                    if (!sub_006001F0(&tContext, 1, 1))
                    {
                        tContext.nUnk0x34 = 0;
                        sub_006004E0_LoadSprite(&tContext);
                    }
                }
                else
                {
                    sub_006001F0(&tContext, 0, 0);
                }
            }
        }
    }
}

void __fastcall sub_0046F870_LoadMonsterCofs(int nMonsterId, int bLoadNow)
{
    D2MonCofInfoStrc tInfo;
    int i;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = DATATBLS_GetMonStats2TxtRecordInl(pMonStatsTxtRecord->nMonStatsEx);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    for (i = 0; i < gnCofModeCount_00712B00; ++i)
    {
        const int nMode = gaCofModes_00712AC4[i];
        if (pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
        {
            memset(&tInfo, 0, sizeof(tInfo));
            tInfo.nMonsterId = nMonsterId;
            sub_0046F650_LoadMonsterCof(pMonStatsTxtRecord, nMode, bLoadNow, &tInfo);
        }
    }
}

void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nIndex)
{
    int nClassId;
    int nUnitType;
    int nMode;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0x502);
    if (nIndex == -1)
    {
        nIndex = nMode;
    }

    if (nUnitType == 1)
    {
        sub_0046F9E0_LoadMonsterModeGfx(pUnit, nIndex);
        return sub_0046E5A0_FindGfxListNode(pUnit, nWeaponClassId, nIndex);
    }

    if (nUnitType == UNIT_PLAYER)
    {
        sub_0046EA50_LoadGfxNodeSetByte(pUnit, nIndex);
        return sub_0046E5A0_FindGfxListNode(pUnit, nWeaponClassId, -1);
    }

    if (nUnitType == 2)
    {
        sub_0046E980_LoadObjectGfx(pUnit, nIndex);
        return sub_0046E5A0_FindGfxListNode(pUnit, nWeaponClassId, -1);
    }

    return 0;
}

void __fastcall sub_00470610_Refresh(D2UnitStrc* pUnit, int nArg)
{
    int nClassId;
    int nUnitType;
    int nMode;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0xD17);
    switch (nUnitType)
    {
    case UNIT_PLAYER:
        sub_0046EA50_LoadGfxNodeSetByte(pUnit, nMode);
        return;

    case UNIT_MONSTER:
        sub_0046F9E0_LoadMonsterModeGfx(pUnit, nMode);
        return;

    case UNIT_OBJECT:
        sub_0046E980_LoadObjectGfx(pUnit, nMode);
        return;

    default:
        D2_ASSERT(0, 0xD26);
        return;
    }
}

// build: context CLIENT_GetMonStats2TxtRecord
static __forceinline D2MonStats2Txt* CLIENT_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].nMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

// build: context sub_0046C140_TestMonModeFlag
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode)
{
    D2MonStats2Txt* pMonStats2TxtRecord = CLIENT_GetMonStats2TxtRecord(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }
    return pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7];
}

// 0x0046E690
static int __stdcall sub_0046E690_FindGfxNode(int nId, D2GfxListNodeStrc** ppNode, int* pValue, D2UnitStrc* pUnit, int nMode)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x3F0);

    if (nMode == -1)
    {
        nMode = sub_0046DA60_GetUnitMode(pUnit);
    }

    for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode)
        {
            if (pNode->nId == nId)
            {
                *ppNode = pNode;
                return 0;
            }

            *ppNode = 0;
            *pValue = sub_0046E570_GetNodeValue(pUnit, nMode);
            D2_ASSERT(sub_0046E610_RemoveGfxNode(pUnit, pNode->f_8), 0x406);
            return 1;
        }
    }
    return 1;
}

// 0x0046F9E0
static void sub_0046F9E0_LoadMonsterModeGfx(D2UnitStrc* pUnit, int nIndex)
{
    int nUnitType;
    int nClassId;
    int nMode;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0x498);
    const int nConvertedMode = nMode;
    if (nIndex == 0xE)
    {
        nIndex = nConvertedMode;
    }

    if (!sub_0046C140_TestMonModeFlag(nClassId, nIndex))
    {
        return;
    }

    if (nIndex == 0xC)
    {
        sub_0046EC80_FreeGfxNodes(pUnit);
        sub_0046F020_FillGfxEntries(pUnit, 0);
        sub_0046E8D0_LoadMonsterGfx(pUnit, nIndex);
        return;
    }

    if (nIndex == 0xE)
    {
        nIndex = nConvertedMode;
    }
    sub_0046E8D0_LoadMonsterGfx(pUnit, nIndex);
}

#include "gen/data/Source/D2Client/ENGINE/Gfx_0046E740.inc"

D2MonGfxCacheStrc gaPlayerGfxCache_007A7490[7]; // 0x007A7490

inline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

static __forceinline D2GfxLayerStrc* GetNodeLayer(D2UnitStrc* pUnit, int nMode)
{
    D2GfxDataStrc* pGfxData = sub_00463E10_GetGfxData(pUnit);
    if (pGfxData)
    {
        for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
        {
            if (pNode->nMode == nMode)
            {
                return pNode->pTarget->pLayer;
            }
        }
    }
    return 0;
}

static int __stdcall sub_0046FB60_LoadUnitLayers(int bAsync, int nMode, D2UnitStrc* pUnit)
{
    int nResult = 1;
    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }
    int nWeaponClass;
    const int nToken = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClass, nMode, 0);
    if (!sub_0046E5A0_FindGfxNode(pUnit, nToken, nMode) && !sub_0046FA80_LoadGfxNode(pUnit, nToken, nMode))
    {
        char szBuffer[256];
        const int nClassArg = pUnit ? pUnit->dwClassId : -1;
        const int nTypeArg = pUnit ? pUnit->dwUnitType : 6;
        sprintf(szBuffer, gszAsyncLoadFailed_006D6CC8, bAsync, nTypeArg, nClassArg, nMode, nWeaponClass, nToken);
        return 0;
    }

    D2GfxLayerStrc* pLayer = GetNodeLayer(pUnit, nMode);
    if (!pLayer)
    {
        return 0;
    }

    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pLayer);
    D2_ASSERT(pHeader, 0x6C3);
    struct
    {
        int nA;
        int nIndex;
    } tArg;
    tArg.nIndex = pHeader->nArg;
    tArg.nA = 0;
    int nDirection = UNITS_GetDirection(pUnit);
    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x6CD);
    int nB;
    sub_004DB2E0_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &tArg.nA, &nB, tArg.nIndex, 0);
    unsigned char* pOrder = sub_004DB110_GetLayerOrder(pLayer, tArg.nA, 0);
    D2_ASSERT(pOrder, 0x6D6);
    tArg.nIndex = 0;
    while (tArg.nIndex < pHeader->nCount)
    {
        const int nLayer = pOrder[tArg.nIndex];
        D2_ASSERT(nLayer < 0x10, 0x6DD);
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        int nItemId;
        if (sub_004DBB50_GetItemCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), 0, &nItemId, nLayer, nMode))
        {
            if (!sub_006001F0(&tContext, bAsync, bAsync))
            {
                tContext.nArg34 = 0;
                if (!sub_006004E0_LoadSprite(&tContext))
                {
                    return -1;
                }
                if (!(tContext.nFlags44 & 4))
                {
                    nResult = 0;
                }
            }
        }
        ++tArg.nIndex;
    }
    return nResult;
}

// build: context sub_0046FDA0_PreloadMonsterMode
static void __stdcall sub_0046FDA0_PreloadMonsterMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x70A);
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount || gpPoolBlock_007A80FC[nClass].f_0[nMode])
    {
        return;
    }
    if (!gpPoolBlock_007A80FC[nClass].aPending[nMode])
    {
        if (sub_0046FB60_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gpPoolBlock_007A80FC[nClass].aPending[nMode] = 0;
            gpPoolBlock_007A80FC[nClass].f_0[nMode] = 0;
        }
        else
        {
            gpPoolBlock_007A80FC[nClass].aPending[nMode] = 1;
        }
    }
    else if (!sub_005FF300_IsEntryPending(nType, nMode, nClass))
    {
        gpPoolBlock_007A80FC[nClass].f_0[nMode] = 1;
    }
}

// 0x0046FEB0
static void __stdcall sub_0046FEB0_PreloadMonsterModes(int bAsync, D2UnitStrc* pUnit)
{
    const int nId = sub_0046DAC0_GetItemClassId(pUnit);
    if (nId < 0 || nId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }
    const int nIndex = sgptDataTables->pMonStatsTxt[nId].wMonStatsEx;
    if (nIndex < 0 || nIndex >= sgptDataTables->nMonStats2TxtRecordCount)
    {
        return;
    }
    D2MonStats2Txt* pMonStats2 = &sgptDataTables->pMonStats2Txt[nIndex];
    if (!pMonStats2)
    {
        return;
    }
    for (unsigned int i = 0; i < gnCofModeCount_00712B00; ++i)
    {
        const unsigned int nMode = gaCofModes_00712AC4[i];
        if (pMonStats2->aModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
        {
            sub_0046FDA0_PreloadMonsterMode(bAsync, pUnit, nMode);
        }
    }
}

// 0x0046FF50
static void __stdcall sub_0046FF50_PreloadPlayerMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x751);
    if (gaPlayerGfxCache_007A7490[nClass].f_0[nMode])
    {
        return;
    }
    if (!gaPlayerGfxCache_007A7490[nClass].aPending[nMode])
    {
        if (sub_0046FB60_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gaPlayerGfxCache_007A7490[nClass].aPending[nMode] = 0;
            gaPlayerGfxCache_007A7490[nClass].f_0[nMode] = 0;
        }
        else
        {
            gaPlayerGfxCache_007A7490[nClass].aPending[nMode] = 1;
        }
    }
    else if (!sub_005FF300_IsEntryPending(nType, nMode, nClass))
    {
        gaPlayerGfxCache_007A7490[nClass].f_0[nMode] = 1;
    }
}

int __stdcall sub_M389_Emit_0046FEB0(int bAsync, D2UnitStrc* pUnit)
{
    sub_0046FEB0_PreloadMonsterModes(bAsync, pUnit);
    return 0x3B;
}

void sub_M389_Emit_0046FF50(int bAsync, D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < gnPlayerModeCount_00712AC0; ++i)
    {
        sub_0046FF50_PreloadPlayerMode(bAsync, pUnit, gaPlayerModes_00712AA0[i] + 0x13);
    }
}
