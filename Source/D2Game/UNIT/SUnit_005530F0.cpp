#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define PLRMODE_SEQUENCE 0x12
#define MONMODE_SEQUENCE 0xE
#define ITEMQUAL_UNIQUE 7
#define SKILLSFLAGINDEX_TARGETALLY 26
struct D2MonsterDataStrc;
struct D2AnimDataRecordStrc;
struct D2StaticPathStrc;
struct D2PlayerDataStrc;
struct D2UnitInfoStrc;
struct D2SkillsTxt;
struct D2DrlgCoordsStrc;
struct D2PresetUnitStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};


struct D2GameStrc
{
    char unk0x00[0x7C];
    unsigned int dwInitSeed;
    unsigned char unk_80[0x28];
    unsigned int dwGameFrame;
    unsigned char unk_AC[0x1074];
    D2UnitStrc* pUnitList[5][128];
    D2UnitStrc* pTileList;
    unsigned int dwUniqueFlags[128];
    unsigned char unk_1D24[0xC0];
    unsigned int dwUberSandsCounter;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall MONSTERAI_RemoveInteractInfoFor(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterInteractStrc* pMonInteract); // 0x00572E00
void __fastcall SUNITPROXY_FreeVendorChain(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536B50
void __fastcall sub_6FC79C00(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00585550
void __stdcall D2Common_10228(D2UnitStrc* pUnit); // 0x00649F50
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

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
    unsigned char unk_10[0x90];
    unsigned char unk0xA0;
    char unk0xA1[3];
    unsigned int unk0xA4;
    int unk0xA8[40];
    int unk0x148;
    int unk0x14C;
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

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern unsigned int gdwBitMasks[]; // 0x006CE268
void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit); // 0x00621260
void __stdcall sub_00620F00(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nAnimMode); // 0x00620F00
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
};

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType); // 0x0058F090
unsigned short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

typedef int (__fastcall* EventTimerCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4, int a5);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
D2ActiveRoomStrc* __fastcall D2GAME_GetRoom_6FC52070(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50
void __fastcall sub_00541800(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, EventTimerCallback pfCallBack, int nSkillId, int nSkillLevel); // 0x00541800
D2ClientStrc* __fastcall SUNIT_GetClientFromPlayer(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0
int __fastcall sub_6FCBDF90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3, int a4, int a5); // 0x00554570
void __fastcall sub_6FCBB190(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0
int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0

enum D2C_M108SUnitConstants
{
    LEVEL_PANDEMONIUMRUN1 = 133,
    LEVEL_PANDEMONIUMRUN2 = 134,
    LEVEL_PANDEMONIUMRUN3 = 135,
    LEVEL_PANDEMONIUMFINALE = 136,
    OBJECT_GOLD_PLACEHOLDER = 26,
    OBJECT_WIRTSBODY = 268,
    OBJECT_CAINGIBBET = 269,
    OBJECT_SPARKLY_CHEST = 397,
    OBJECT_VALLEY_WAYPOINT = 402,
};

D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* pRoom); // 0x00619FD0
void __fastcall SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit); // 0x00555910

inline D2UnitStrc** SUNIT_GetUnitList(int nUnitType, D2GameStrc* pGame, int nUnitGUID)
{
    if (nUnitType >= 0 && nUnitType <= 4)
    {
        return (D2UnitStrc**)((char*)pGame + s_anUnitListOffset_006E10E0[nUnitType]) + (nUnitGUID & UNIT_LIST_MASK);
    }

    return 0;
}

// 0x005530F0
static void sub_005530F0_RemoveFromUnitList(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc** ppUnitList;
    if (pUnit->dwUnitType == UNIT_TILE)
    {
        ppUnitList = &pGame->pTileList;
    }
    else
    {
        ppUnitList = SUNIT_GetUnitList(pUnit->dwUnitType, pGame, pUnit->dwUnitId);
    }

    D2UnitStrc* pPrevious = 0;
    D2UnitStrc* i;
    for (i = *ppUnitList; i; i = i->pListNext)
    {
        if (i == pUnit)
        {
            break;
        }
        pPrevious = i;
    }

    if (i)
    {
        if (!pPrevious)
        {
            *ppUnitList = i->pListNext;
        }
        else
        {
            pPrevious->pListNext = i->pListNext;
        }
    }
}

// 0x00555500
static void sub_00555500_ClearPlayerInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nInteractGUID = pUnit->dwInteractGUID;
    const int nInteractType = pUnit->dwInteractType;
    if (pUnit->nInteract)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nInteractType, nInteractGUID);
        if (pInteractUnit)
        {
            switch (pInteractUnit->dwUnitType)
            {
            case UNIT_MONSTER:
                MONSTERAI_RemoveInteractInfoFor(pGame, pUnit, !pInteractUnit->pMonsterData ? 0 : pInteractUnit->pMonsterData->pMonInteract);
                SUNITPROXY_FreeVendorChain(pGame, pUnit, pInteractUnit);
                break;
            case UNIT_OBJECT:
                sub_6FC79C00(pGame, pInteractUnit);
                break;
            }

            pUnit->dwInteractGUID = -1;
            pUnit->dwInteractType = UNIT_INVALID;
            pUnit->nInteract = 0;
        }
    }
}

// 0x00555580
void __fastcall sub_00555580_DetachUnit(D2UnitStrc* pUnit, D2GameStrc* pGame, int bKeepInRoom)
{
    D2_ASSERT(pUnit, 940);
    D2_ASSERT(pUnit->dwUnitType < 6, 941);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        sub_00555500_ClearPlayerInteraction(pGame, pUnit);
        D2Common_10228(pUnit);
        break;
    case UNIT_MONSTER:
        D2Common_10228(pUnit);
        break;
    case UNIT_OBJECT:
        D2Common_10228(pUnit);
        break;
    case UNIT_MISSILE:
        D2Common_10228(pUnit);
        break;
    }

    if (!bKeepInRoom)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }

    sub_005530F0_RemoveFromUnitList(pGame, pUnit);
}

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

// 0x00554D20
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId)
{
    if (!pOwner || !pPet)
    {
        return 0;
    }

    const int nOwnerUnitType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    const int nPetType = pPet->dwUnitType;
    int nUnitType = nPetType;
    if (nPetType != UNIT_PLAYER && nPetType != UNIT_MONSTER)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETALLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETALLY & 7]))
    {
        return 0;
    }

    int nUnitGUID = pPet->dwUnitId;
    if (nPetType == UNIT_MONSTER)
    {
        AIGENERAL_GetOwnerData(pPet, &nUnitGUID, &nUnitType);
        if (nUnitGUID == -1 || nUnitType != UNIT_PLAYER)
        {
            return 0;
        }
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pOwner);
    if (nPartyId == 0xFFFF)
    {
        return 0;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (!pOtherPlayer)
    {
        return 0;
    }

    return nPartyId == SUNIT_GetPartyId(pOtherPlayer);
}

// 0x00554EA0
int __fastcall sub_6FCBDFE0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pInputRoom, int nX, int nY, int a6, int a7)
{
    D2_ASSERT(pUnit, 0xC21);
    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2_ASSERT(pPath, 0xC25);

    D2ActiveRoomStrc* pRoom = pInputRoom;
    D2CoordStrc tCoords;
    tCoords.nX = nX;
    tCoords.nY = nY;
    if (!pRoom)
    {
        pRoom = D2GAME_GetRoom_6FC52070(0, tCoords.nX, tCoords.nY);
        if (!pRoom)
        {
            pRoom = D2GAME_GetRoom_6FC52070(pUnitRoom, tCoords.nX, tCoords.nY);
        }
    }

    if (!pRoom)
    {
        return 0;
    }

    if (!a6)
    {
        pRoom = COLLISION_GetFreeCoordinates(pRoom, &tCoords, UNITS_GetUnitSizeX(pUnit), 0x1C09, 0);
    }

    if (!pRoom)
    {
        return 0;
    }

    if (!sub_00650BE0_PlaceUnit(pPath, pUnit, pRoom, tCoords.nX, tCoords.nY))
    {
        return 0;
    }

    if (pUnit->dwUnitType == 0)
    {
        D2ClientStrc* pClient = SUNIT_GetClientFromPlayer(pUnit, ".\\UNIT\\SUnit.cpp", 0xC3C);
        D2DrlgCoordsStrc tDrlgCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &tDrlgCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(pClient, DUNGEON_GetLevelIdFromRoom(pRoom), (unsigned short)tDrlgCoords.nTileXPos, (unsigned short)tDrlgCoords.nTileYPos);

        UNITROOM_RefreshUnit(pUnit);
        if (a7)
        {
            pUnit->dwFlagEx |= 0x800;
        }
        else
        {
            pUnit->dwFlagEx |= 0x10000;
        }

        sub_6FCBB190(pGame, pUnit, 0);

        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        const unsigned char nIndex = pPlayerData->unk0xA0;
        pPlayerData->unk0x148 = tCoords.nX;
        pPlayerData->unk0x14C = tCoords.nY;
        pPlayerData->unk0xA4 = GetTickCount();
        pPlayerData->unk0xA8[2 * nIndex] = tCoords.nX;
        pPlayerData->unk0xA8[2 * nIndex + 1] = tCoords.nY;
        pPlayerData->unk0xA0 += 1;
        if (pPlayerData->unk0xA0 >= 20)
        {
            pPlayerData->unk0xA0 = 0;
        }

        sub_00541800(pGame, pUnit, 14, pGame->dwGameFrame + 50, sub_6FCBDF90, 0, 0);
        sub_6FC7E310(pGame, pUnit, tCoords.nX, tCoords.nY);
    }
    else
    {
        UNITROOM_RefreshUnit(pUnit);
        if (a7)
        {
            pUnit->dwFlagEx |= 0x800;
        }
        else
        {
            pUnit->dwFlagEx |= 0x10000;
        }

        sub_6FCBB190(pGame, pUnit, 0);
    }

    return 1;
}

// 0x005559A0
void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    if (!pGame)
        return;

    D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom);
    int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);

    for (D2PresetUnitStrc* i = pPresetUnit; i; i = i->pNext)
    {
        if (i->nUnitType != UNIT_MONSTER && !(i->bSpawned & 1))
        {
            if (nLevelId == LEVEL_PANDEMONIUMFINALE)
            {
                if (i->nUnitType != UNIT_OBJECT || (i->nIndex != OBJECT_WIRTSBODY && i->nIndex != OBJECT_GOLD_PLACEHOLDER && i->nIndex != OBJECT_CAINGIBBET))
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);

                if (i->nIndex == OBJECT_GOLD_PLACEHOLDER)
                    DUNGEON_GetLevelIdFromRoom(pRoom);
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN1)
            {
                if (i->nUnitType != UNIT_OBJECT || i->nIndex != OBJECT_SPARKLY_CHEST)
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN2)
            {
                if (i->nUnitType != UNIT_OBJECT)
                {
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
                }
                else if (i->nIndex != OBJECT_VALLEY_WAYPOINT)
                {
                    pGame->dwUberSandsCounter++;
                    if (pGame->dwUberSandsCounter != (pGame->dwInitSeed % 3) + 3)
                        SUNIT_SpawnPresetUnit(pGame, pRoom, i);
                }
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN3)
            {
                if (i->nUnitType != UNIT_OBJECT || i->nIndex != OBJECT_SPARKLY_CHEST)
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
            else
            {
                SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
        }
    }

    D2PresetUnitStrc* pMonster = pPresetUnit;
    if (nLevelId == LEVEL_PANDEMONIUMFINALE)
        return;

    for (; pMonster; pMonster = pMonster->pNext)
    {
        if (pMonster->nUnitType == UNIT_MONSTER && !(pMonster->bSpawned & 1))
            SUNIT_SpawnPresetUnit(pGame, pRoom, pMonster);
    }
}
