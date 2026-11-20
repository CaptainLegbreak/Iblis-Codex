#include "D2Game.h"
#include "D2Constants.h"
#include "D2Txt.h"
#include "D2DataTbls.h"

#define STAT_UNIT_DOOVERLAY 178
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define NPC_LEVEL_COUNT 5

struct D2NpcRecordStrc;
struct D2InteractInfoStrc;
struct D2UnitPacketListStrc;
struct D2UnitPacketLifeStrc;
struct D2UnitPacketSkillStrc;
struct D2UnitPacketPrecacheStrc;
struct D2PetInfoStrc;
struct D2PetDataStrc;
struct D2PetListStrc;
struct D2PlayerPetStrc;
struct D2PlayerDataStrc;
struct D2MonsterDataStrc;
struct D2NpcIndexMapStrc;
struct D2UnitPacketSkillEventStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2BitBufferStrc;
struct D2PlrIntroStrc;
struct D2MonsterInteractStrc;
struct D2GameStrc;
struct D2CoordStrc;
struct D2ObjectsTxt;
struct D2ObjectDataStrc;
struct D2MonStatsTxt;

struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
};

struct D2UnitPacketLifeStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nUnitType;
    char unk0x09[0x03];
    int nUnitGUID;
    unsigned char nLife;
    char unk0x11[0x03];
};

struct D2UnitPacketSkillStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nUnitType;
    char unk0x09[0x03];
    int nUnitGUID;
    short nSkillId;
    char unk0x12[0x02];
};

struct D2UnitPacketPrecacheStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    short nMonsterClassId;
    char unk0x0A[0x02];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    union
    {
        D2MonsterDataStrc* pMonsterData;
        char* szName;
        D2ObjectDataStrc* pObjectData;
    };
    char unk0x18[0x14];
    D2DynamicPathStrc* pDynamicPath;
    char unk_30[0x30];
    D2InventoryStrc* pInventory;
    char unk_64[0x60];
    unsigned int dwFlags;
    unsigned char unk_C8[0x24];
    D2UnitPacketListStrc* pMsgFirst;
    D2UnitPacketListStrc* pMsgLast;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc* pUnit); // 0x004DC0B0
void __fastcall sub_0053BDA0_SendUnitRemoval(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0
void __fastcall D2GAME_PACKETS_SendPacket0x11_6FC3F4A0(D2ClientStrc* pClient, int nUnitType, int nUnitGUID, int nOverlay); // 0x0053D850
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760
int __stdcall STATLIST_GetTotalStatValue_Layer0(D2StatListStrc* pStatListEx, int nStatId); // 0x00625A50
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
};

struct D2PlrIntroStrc
{
    D2BitBufferStrc* pQuestIntroFlags;
    D2BitBufferStrc* pNpcIntroFlags;
};

struct D2PetInfoStrc
{
    unsigned int nSeed;
    unsigned short wName;
    short unk0x06;
    int nHirelingId;
};

struct D2PetDataStrc
{
    unsigned int nFlags;
    int nUnitGUID;
    D2PetInfoStrc petInfo;
    D2PetDataStrc* pNext;
};

struct D2PetListStrc
{
    D2PetDataStrc* pPetData;
    int nCurrent;
    int nMax;
};

struct D2PlayerPetStrc
{
    D2PetListStrc* pPetList;
};

struct D2PlayerDataStrc
{
    char unk0x00[0x44];
    D2PlayerPetStrc* pPlayerPets;
    char unk0x48[0x18];
    D2PlrIntroStrc* pPlayerIntro[3];
};

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
};

struct D2MonsterDataStrc
{
    char unk0x00[0x30];
    D2MonsterInteractStrc* pMonInteract;
};

struct D2InteractInfoStrc
{
    D2UnitStrc* pUnit;
    int nInteract;
    D2InteractInfoStrc* pNext;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
    char unk0x20[0x4D];
    unsigned char nDifficulty;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x22];
    unsigned char nAct;
    char unk0x23[0x11];
    int* pPermStoreItems;
    int nPermStoreItems;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern D2NpcIndexMapStrc gaPlrIntroNpcIndexMap[]; // 0x00732738
void __stdcall sub_00410B10(unsigned char* pBits, int nBit); // 0x00410B10
int __stdcall sub_00410B30(unsigned char* pBits, int nBit); // 0x00410B30
void __stdcall sub_00410B50(unsigned char* pBits, int nBit); // 0x00410B50
D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190
void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

struct D2UnitPacketSkillEventStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nSkillParam;
    char unk0x09;
    short nSkillId;
    short nSkillLevel;
    char unk0x0E[0x02];
    int nUnitType;
    int nUnitGUID;
    int nTargetType;
    int nTargetGUID;
    int nX;
    int nY;
};

struct D2CoordStrc { int nX; int nY; };

struct D2ObjectDataStrc { D2ObjectsTxt* pObjectsTxt; unsigned char nInteractType; };

extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc*, int); // 0x00451F30
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int); // 0x00451F80
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc*, unsigned int); // 0x00463720
void __fastcall PLAYER_SynchronizeItemsToClient(D2UnitStrc*, D2ClientStrc*); // 0x00534F80
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc*, int); // 0x00537860
void __fastcall D2GAME_PACKETS_SendPacket0x09_6FC3D1A0(D2ClientStrc*, unsigned char, unsigned char, unsigned int, unsigned char, unsigned short, unsigned short); // 0x0053BCD0
void __fastcall D2GAME_PACKETS_SendPacket0x51_6FC3D300(D2ClientStrc*, unsigned char, unsigned char, int, unsigned short, unsigned short, unsigned short, unsigned char, unsigned char); // 0x0053BD10
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove); // 0x0053C4A0
void __fastcall sub_6FC3F550(D2ClientStrc*, D2UnitStrc*); // 0x0053D900
void __fastcall D2GAME_PACKETS_SendPacket0x74_6FC3F640(D2ClientStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x0053DA40
void __fastcall D2GAME_PACKETS_SendPacket0x82_6FC3F790(D2GameStrc*, D2ClientStrc*, int, int); // 0x0053DB90
void __fastcall sub_6FC3FAF0(D2ClientStrc*, unsigned int, unsigned short); // 0x0053E0A0
void __fastcall sub_6FC3FC80(D2ClientStrc*, D2UnitStrc*); // 0x0053E2E0
void __fastcall sub_6FC3D1F0(D2ClientStrc*, int, unsigned char, const char*, short, short); // 0x0053E8F0
void __fastcall D2GAME_SendP0x9C_ItemAction_AddToGround_6FC3E850(D2ClientStrc*, D2UnitStrc*, unsigned int); // 0x0053EC00
void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(D2ClientStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x0053EC90
void __fastcall sub_6FC82270(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x005484B0
void __fastcall sub_6FC82830(D2UnitStrc*, D2ClientStrc*); // 0x005489F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
D2UnitStrc* __fastcall sub_00553720_ResolveObjectOwner(D2GameStrc*, D2UnitStrc*); // 0x00553720
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
void __fastcall sub_6FC42050(D2UnitStrc*, D2ClientStrc*); // 0x0055BED0
void __fastcall D2GAME_STATES_SendUnitStates_6FCC58E0(D2UnitStrc*, D2ClientStrc*); // 0x00570E30
void __fastcall sub_00571620(D2UnitStrc*, D2ClientStrc*); // 0x00571620
void __fastcall sub_6FCC6540(D2UnitStrc*, D2ClientStrc*); // 0x00571CD0
int __fastcall AIGENERAL_GetMinionSpawnClassId(D2UnitStrc*); // 0x0058F710
void __fastcall MONSTERMSG_SendMonsterModeUpdate(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x00597E20
void __fastcall sub_0059FEE0_SendMissilePacket(D2ClientStrc*, D2GameStrc*, D2UnitStrc*, int); // 0x0059FEE0
void __stdcall UNITS_GetCoords(D2UnitStrc*, D2CoordStrc*); // 0x00620870
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc*); // 0x0063A320
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc*); // 0x0063D450
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
int __stdcall PATH_GetVelocity(D2DynamicPathStrc*); // 0x006486C0

// 0x005715A0
void __fastcall sub_6FCC5F20(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x80);
    if (pStatList)
    {
        const int nOverlay = STATLIST_GetTotalStatValue_Layer0(pStatList, STAT_UNIT_DOOVERLAY);
        if (nOverlay >= 0 && nOverlay <= sgptDataTables->nOverlayTxtRecordCount)
        {
            D2GAME_PACKETS_SendPacket0x11_6FC3F4A0(pClient, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId, nOverlay);
        }
    }
}

// 0x00571600
void __fastcall sub_00571600(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    sub_0053BDA0_SendUnitRemoval(pClient, 0x0A, pUnit->dwUnitType, pUnit->dwUnitId);
}

// 0x005717C0
void __fastcall sub_6FCC60D0(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, unsigned char nUnitType, int nUnitGUID, unsigned char a6)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 644, 0);
    *((unsigned char*)pMsg + 10) = nSkillLevel;
    *((unsigned char*)pMsg + 11) = nUnitType;
    pMsg->nHeader = 0x99;
    pMsg->pNext = 0;
    *((short*)pMsg + 4) = nSkillId;
    *((int*)pMsg + 3) = nUnitGUID;
    *((unsigned char*)pMsg + 16) = a6;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571840
void __fastcall sub_6FCC6150(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, short nX, short nY, unsigned char a6)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 667, 0);
    *((unsigned char*)pMsg + 10) = nSkillLevel;
    *((short*)pMsg + 6) = nX;
    pMsg->nHeader = 0x9A;
    pMsg->pNext = 0;
    *((short*)pMsg + 4) = nSkillId;
    *((short*)pMsg + 7) = nY;
    *((unsigned char*)pMsg + 16) = a6;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x005718C0
void __fastcall D2GAME_MERCS_SendStat_6FCC61D0(D2UnitStrc* pUnit, unsigned short wStat, int nValue)
{
    D2_ASSERT(wStat < ((unsigned char)-1), 685);

    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 687, 0);
    pMsg->nHeader = 0x9E;
    pMsg->pNext = 0;
    *((int*)pMsg + 2) = !pUnit ? -1 : pUnit->dwUnitId;
    *((unsigned char*)pMsg + 12) = (unsigned char)wStat;
    *((int*)pMsg + 4) = nValue;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571A10
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent)
{
    D2UnitPacketLifeStrc* pMsg = (D2UnitPacketLifeStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketLifeStrc), ".\\UNIT\\SUnitMsg.cpp", 729, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketLifeStrc));
    pMsg->nHeader = 0xAB;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nLife = nLifePercent;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

#include "gen/data/Source/D2Game/UNIT/SUnitMsg.inc"
struct D2ClientStrc;

// 0x00571AA0
void __fastcall sub_6FCC6300(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7)
{
    D2UnitPacketSkillEventStrc* pMsg = (D2UnitPacketSkillEventStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketSkillEventStrc), ".\\UNIT\\SUnitMsg.cpp", 746, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketSkillEventStrc));
    pMsg->pNext = 0;
    pMsg->nHeader = 0xA3;
    pMsg->nSkillParam = a7;
    pMsg->nSkillId = nSkillId;
    pMsg->nSkillLevel = nSkillLevel;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nX = nX;
    pMsg->nY = nY;

    if (pTargetUnit)
    {
        const int nTargetType = (pTargetUnit ? pTargetUnit->dwUnitType : 6);
        pMsg->nTargetType = nTargetType;
        const int nTargetGUID = (pTargetUnit ? pTargetUnit->dwUnitId : -1);
        pMsg->nTargetGUID = nTargetGUID;
    }
    else
    {
        pMsg->nTargetGUID = -1;
    }

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571B70
void __fastcall sub_00571B70_SkillUpdate(D2UnitStrc* pUnit, int nSkillId)
{
    STATES_ToggleState(pUnit, STATE_SKILL_MOVE, 0);

    D2UnitPacketSkillStrc* pMsg = (D2UnitPacketSkillStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketSkillStrc), ".\\UNIT\\SUnitMsg.cpp", 783, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketSkillStrc));
    pMsg->pNext = 0;
    pMsg->nHeader = 0xA5;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nSkillId = nSkillId;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571C00
void __fastcall SUNITMSG_QueueMonsterPrecache(D2UnitStrc* pUnit, int nMonsterClassId)
{
    D2UnitPacketPrecacheStrc* pMsg = (D2UnitPacketPrecacheStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketPrecacheStrc), ".\\UNIT\\SUnitMsg.cpp", 802, 0);
    pMsg->nHeader = 0xA4;
    pMsg->pNext = 0;
    pMsg->nMonsterClassId = nMonsterClassId;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571C60
void __fastcall sub_6FCC64D0(D2UnitStrc* pUnit, int bLeftSkill, short nSkillId, int nOwnerGUID)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, 16, ".\\UNIT\\SUnitMsg.cpp", 818, 0);
    pMsg->nHeader = 0x23;
    pMsg->pNext = 0;
    *((unsigned char*)pMsg + 14) = bLeftSkill;
    *((short*)pMsg + 6) = nSkillId;
    *((int*)pMsg + 2) = nOwnerGUID;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571F40
void __fastcall D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(D2UnitStrc* pUnit)
{
    D2UnitPacketListStrc* pMsg = pUnit->pMsgFirst;
    if (pMsg)
    {
        do
        {
            D2UnitPacketListStrc* pFree = pMsg;
            pMsg = pMsg->pNext;
            FOG_FreeServerMemory(sub_004DC0B0_GetUnitMemoryPool(pUnit), pFree, ".\\UNIT\\SUnitMsg.cpp", 974, 0);
        }
        while (pMsg);

        pUnit->pMsgLast = 0;
        pUnit->pMsgFirst = 0;
    }
}

static __forceinline int UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit) return (pUnit->dwFlags & nFlag) != 0;
    return 0;
}

static __forceinline int UnitGUID(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static __forceinline D2DynamicPathStrc* UnitPath(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pDynamicPath;
}

static __forceinline D2InventoryStrc* UnitInventory(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pInventory;
}

// 0x00571F90
void __fastcall sub_00571F90(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2CoordStrc tCoords;
    UNITS_GetCoords(pUnit, &tCoords);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    switch (pUnit->dwUnitType)
    {
    case 0:
        sub_6FC3D1F0(pClient, pUnit->dwUnitId, pUnit->dwClassId, pUnit->szName, tCoords.nX, tCoords.nY);
        break;
    case 4:
        if (UnitHasFlag(pUnit, 0x10))
        {
            if (pUnit->dwAnimMode == 3 && sub_00451F30_TestUnitFlag(pUnit, 0x1000))
                D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(pClient, pPlayer, pUnit, 0);
            else D2GAME_SendP0x9C_ItemAction_AddToGround_6FC3E850(pClient, pUnit, 0);
        }
        break;
    case 2:
        D2GAME_PACKETS_SendPacket0x51_6FC3D300(pClient, 0x51, 2, pUnit->dwUnitId, pUnit->dwClassId, tCoords.nX, tCoords.nY, pUnit->dwAnimMode, pUnit->pObjectData->nInteractType);
        if (pUnit->pObjectData->pObjectsTxt->nSubClass & 4)
        {
            sub_6FC3F550(pClient, pUnit);
            if ((short)nClassId == 59)
            {
                D2UnitStrc* pOwner = sub_00553720_ResolveObjectOwner(pGame, pUnit);
                int nOwnerId = -1;
                if (pOwner) nOwnerId = pOwner->dwUnitId;
                const int nPortalId = UnitGUID(pUnit);
                D2GAME_PACKETS_SendPacket0x82_6FC3F790(pGame, pClient, nPortalId, nOwnerId);
            }
        }
        break;
    case 1:
        if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskHideOnUnit(pUnit))
        {
            sub_6FC3FC80(pClient, pUnit);
            STATLIST_SetUnitStat(pUnit, 328, (unsigned short)(tCoords.nX + tCoords.nY), 0);
            if (pUnit->dwClassId == 528)
                sub_6FC3FAF0(pClient, pUnit->dwUnitId, AIGENERAL_GetMinionSpawnClassId(pUnit));
            D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxt)
            {
                int i = 0;
                short* pSkillId = pMonStatsTxt->nSkill;
                for (; i < 8; ++i, ++pSkillId)
                {
                    if (pMonStatsTxt->nSendSkill[i >> 3] & gdwBitMasks[i & 7])
                    {
                        const unsigned short nSkillId = *pSkillId;
                        if ((short)nSkillId >= 0 && (short)nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                        {
                            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, (short)nSkillId);
                            if (pSkill)
                                D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(pClient, pUnit, nSkillId, SKILLS_GetSkillLevel(pUnit, pSkill, 0), 0);
                        }
                    }
                }
            }
            D2GAME_STATES_SendUnitStates_6FCC58E0(pUnit, pClient);
            sub_6FCC6540(pUnit, pClient);
        }
        break;
    case 3:
        sub_0059FEE0_SendMissilePacket(pClient, pGame, pUnit, PATH_GetVelocity(UnitPath(pUnit)));
        break;
    default:
        D2GAME_PACKETS_SendPacket0x09_6FC3D1A0(pClient, 9, pUnit->dwUnitType, pUnit->dwUnitId, pUnit->dwClassId, tCoords.nX, tCoords.nY);
        break;
    }
    switch (pUnit->dwUnitType)
    {
    case 0:
        sub_6FC82830(pUnit, pClient);
        if (SUNIT_IsDead(pUnit) && STATES_CheckState(pUnit, 7))
        {
            D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, 0, INVENTORY_GetOwnerId(UnitInventory(pUnit)));
            D2_ASSERT(pOwner, 184);
            D2GAME_PACKETS_SendPacket0x74_6FC3F640(pClient, pOwner, pUnit, sub_00463720_TestUnitFlagEx(pUnit, 0x1000));
        }
        else PLAYER_SynchronizeItemsToClient(pUnit, pClient);
        D2GAME_STATES_SendUnitStates_6FCC58E0(pUnit, pClient);
        sub_6FC82270(pGame, pUnit, pClient);
        sub_6FCC6540(pUnit, pClient);
        sub_00571620(pUnit, pClient);
        break;
    case 1:
        MONSTERMSG_SendMonsterModeUpdate(pGame, pUnit, pClient);
        if (STATES_CheckState(pUnit, 93) || pUnit->dwClassId == 291 || pUnit->dwClassId == 417 || pUnit->dwClassId == 418)
            PLAYER_SynchronizeItemsToClient(pUnit, pClient);
        break;
    case 4:
        sub_6FC42050(pUnit, pClient);
        break;
    case 2:
    case 3:
    case 5:
        return;
    }
}

static int PLRINTRO_GetNpcIndex(int nNpcId)
{
    for (int i = 0; i < gnPlrIntroNpcIndexMapCount; ++i)
    {
        if (gaPlrIntroNpcIndexMap[i].nNpcClassId == nNpcId)
        {
            return gaPlrIntroNpcIndexMap[i].nIndex;
        }
    }

    return 0;
}

// 0x00572360
void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    sub_00410B10(pPlayerIntro->pQuestIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x005723C0
int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    return sub_00410B30(pPlayerIntro->pQuestIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x005724C0
void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
    sub_00410B50(pPlayerIntro->pNpcIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x00572E00
void __fastcall MONSTERAI_RemoveInteractInfoFor(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterInteractStrc* pMonInteract)
{
    if (!pMonInteract)
    {
        return;
    }

    D2InteractInfoStrc* pPrevious = 0;
    for (D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo; pInteractInfo; pInteractInfo = pInteractInfo->pNext)
    {
        if (pInteractInfo->pUnit == pMonster)
        {
            if (pInteractInfo == pMonInteract->pInteractInfo)
            {
                pMonInteract->pInteractInfo = pInteractInfo->pNext;
            }
            else
            {
                pPrevious->pNext = pInteractInfo->pNext;
            }
            FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 553, 0);
            return;
        }

        pPrevious = pInteractInfo;
    }
}

// 0x00573750
void __fastcall sub_00573750_ClearTargetIfMatches(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pTarget == SUNIT_GetTargetUnit(pGame, pUnit))
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
        PATH_SetTargetUnit(pUnit->pDynamicPath, 0);
    }
}

// 0x005749B0
void __fastcall PLAYERPETS_UpdatePetInfo(D2UnitStrc* pUnit, int nPetType, int nUnitGUID, D2PetInfoStrc* pPetInfo)
{
    D2PlayerPetStrc* pPlayerPets = UNITS_GetPlayerData(pUnit)->pPlayerPets;
    if (!pPlayerPets || nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        return;
    }

    D2PetListStrc* pPetList = &pPlayerPets->pPetList[nPetType];
    if (!pPetList)
    {
        return;
    }

    for (D2PetDataStrc* pPetData = pPetList->pPetData; pPetData; pPetData = pPetData->pNext)
    {
        if (pPetData->nUnitGUID == nUnitGUID)
        {
            pPetData->petInfo = *pPetInfo;
        }
    }
}

// 0x00576890
int __fastcall sub_00576890(D2GameStrc* pGame, D2UnitStrc* pNpc, int nLevel)
{
    if (pGame->nDifficulty == DIFFMODE_NORMAL)
    {
        int nUnused;
        D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
        if (pNpcRecord)
        {
            const int npcLevels[NPC_LEVEL_COUNT] = { 12, 20, 28, 36, 45 };
            if (pNpcRecord->nAct < NPC_LEVEL_COUNT)
            {
                const int nCap = npcLevels[pNpcRecord->nAct];
                return nCap < nLevel ? nCap : nLevel;
            }
        }
    }

    return nLevel;
}

// 0x00576ED0
bool __fastcall sub_00576ED0(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        return false;
    }

    const int nCode = ITEMS_GetBaseCode(pItem);
    if (pGame->nDifficulty > DIFFMODE_NORMAL)
    {

        if (nCode == 0x20347068 || nCode == 0x20357068 || nCode == 0x2034706D || nCode == 0x2035706D)
        {
            return true;
        }
    }

    for (int i = 0; i < pNpcRecord->nPermStoreItems; ++i)
    {
        if (nCode == pNpcRecord->pPermStoreItems[i])
        {
            return true;
        }
    }

    return false;
}

// 0x00579130
void __fastcall D2GAME_NPC_ResetInteract_6FCCB4D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    SUNIT_ResetInteractInfo(pPlayer);
    MONSTERAI_RemoveInteractInfoFor(pGame, pPlayer, (pNpc && pNpc->dwUnitType == UNIT_MONSTER && pNpc->pMonsterData) ? pNpc->pMonsterData->pMonInteract : 0);
}

// 0x00585160
int __fastcall sub_00585160_StatCallback1(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 1, nValue, 0);
    return 1;
}

// 0x00585180
int __fastcall sub_00585180_StatCallback2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 2, nValue, 0);
    return 1;
}

// 0x005851A0
int __fastcall sub_005851A0_StatCallback3(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 3, nValue, 0);
    return 1;
}

// 0x005851C0
int __fastcall sub_005851C0_StatCallback0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 0, nValue, 0);
    return 1;
}

// 0x00585220
int __fastcall sub_00585220_StatCallback5(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 5, nValue, 0);
    return 1;
}
