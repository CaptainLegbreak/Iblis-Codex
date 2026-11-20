#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PacketRecord11Strc;
struct D2UnitStatPacketStrc;
struct D2PlayerStatPacketStrc;
struct D2UnitStatPacket2Strc;
struct D2SkillPacketStrc;
struct D2SkillsTxt;
struct D2GSPacketSrv26;
struct D2EnvironmentPacketStrc;
struct D2GSPacketSrv9C;
struct D2GSPacketSrv9D;
struct D2PacketSpawnStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2ItemStatCostTxt;
struct D2UnitSpawnExtraStrc;
struct D2UnitSpawnStrc;
struct D2Packet18RecordStrc;
struct D2Packet95RecordStrc;
struct D2Packet96RecordStrc;
struct D2GSPacketSrv0DStrc;
struct D2PacketBufferStrc;
struct D2PacketTableEntryStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C"
__declspec(noreturn)
void __cdecl exit(int nCode); // 0x00681E09

#pragma pack(push, 1)
struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    union
    {
        int nUnitId;
        unsigned long dwUnitId;
    };
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
};

struct D2UnitStatPacketStrc
{
    unsigned char nHeader;
    unsigned char nStat;
    int nUnitId;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
    };
};

struct D2PlayerStatPacketStrc
{
    unsigned char nHeader;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
        struct
        {
            unsigned char nStat;
            union
            {
                unsigned char nByte2;
                unsigned short nWord2;
                unsigned int nDword2;
            };
        };
    };
};

struct D2UnitStatPacket2Strc
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char nStat;
    int nValue;
};

#pragma pack(pop)

void __fastcall sub_004C1BC0(D2PacketRecord11Strc* pPacket, int nArg); // 0x004C1BC0
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
void __fastcall sub_00480E70_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70
void __fastcall sub_004C1C10(D2UnitStrc* pUnit); // 0x004C1C10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

#pragma pack(push, 1)
struct D2SkillPacketStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short nSkillId;
};

#pragma pack(pop)


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall sub_004CA000_EndSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004CA000
void __fastcall sub_004C8B80_EndSkill(D2UnitStrc* pUnit); // 0x004C8B80
void __fastcall sub_004C9420_EndSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004C9420
void __stdcall sub_00639DB0_ToggleState(D2UnitStrc* pUnit, int nState, int nEnable); // 0x00639DB0

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nLang;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nColor;
    unsigned char nSubType;
    char szName[0x10];
};

struct D2ChatMessageStrc
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char f_2;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nColor;
    unsigned char nSubType;
    char szName[0x10];
    char szText[0x100];
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
int __stdcall SStrLen(const char* szString); // 0x00413750

#pragma pack(push, 1)
struct D2EnvironmentPacketStrc
{
    unsigned char nHeader;
    int nIndex;
    int nTicks;
    unsigned char bEclipse;
};

#pragma pack(pop)

extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634
D2ActiveRoomStrc* __fastcall sub_004646A0_GetPlayerRoom(); // 0x004646A0
void __cdecl sub_004646C0_UpdateObjectsForPeriod(); // 0x004646C0

struct D2GSPacketSrv9C
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char pBitstream[244];
};

struct D2GSPacketSrv9D
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    unsigned char pItemId[4];
    unsigned char nOwnerType;
    unsigned char nUnitId[4];
    unsigned char pBitstream[0xF4];
};

void __fastcall sub_004C20B0(D2GSPacketSrv9C* pPacket); // 0x004C20B0
void __fastcall sub_004C2340(D2GSPacketSrv9D* pPacket); // 0x004C2340
void __fastcall sub_004C25B0(D2GSPacketSrv9C* pPacket); // 0x004C25B0
void __fastcall sub_004C2650(D2GSPacketSrv9C* pPacket); // 0x004C2650
void __fastcall sub_004C26F0(D2GSPacketSrv9C* pPacket); // 0x004C26F0
void __fastcall sub_004C2810(D2GSPacketSrv9C* pPacket); // 0x004C2810
void __fastcall sub_004C2AD0(D2GSPacketSrv9C* pPacket); // 0x004C2AD0
void __fastcall sub_004C2C80(D2GSPacketSrv9D* pPacket); // 0x004C2C80
void __fastcall sub_004C2E90(D2GSPacketSrv9D* pPacket); // 0x004C2E90
void __fastcall sub_004C3070(D2GSPacketSrv9D* pPacket); // 0x004C3070
void __fastcall sub_004C3380(D2GSPacketSrv9D* pPacket); // 0x004C3380
void __fastcall sub_004C3920(D2GSPacketSrv9D* pPacket); // 0x004C3920
void __fastcall sub_004C3B00(D2GSPacketSrv9D* pPacket); // 0x004C3B00
void __fastcall sub_004C3B30_UpdateItemFromPacket9C(D2GSPacketSrv9C* pPacket); // 0x004C3B30
void __fastcall sub_004C3C00(D2GSPacketSrv9C* pPacket); // 0x004C3C00
void __fastcall sub_004C40D0(D2GSPacketSrv9C* pPacket); // 0x004C40D0
void __fastcall sub_004C4130(D2GSPacketSrv9C* pPacket); // 0x004C4130
void __fastcall sub_004C42A0(D2GSPacketSrv9C* pPacket); // 0x004C42A0
void __fastcall sub_004C45C0(D2GSPacketSrv9C* pPacket); // 0x004C45C0
void __fastcall sub_004C4740(D2GSPacketSrv9D* pPacket); // 0x004C4740
void __fastcall sub_004C4990(D2GSPacketSrv9D* pPacket); // 0x004C4990
void __fastcall sub_004C4AA0(D2GSPacketSrv9D* pPacket); // 0x004C4AA0
void __fastcall sub_004C4C70(D2GSPacketSrv9D* pPacket); // 0x004C4C70

#pragma pack(push, 1)
struct D2PacketSpawnStrc
{
    unsigned char nHeader; unsigned int nUnitId; short nClassId;
    unsigned short nX, nY; unsigned char nLife, nLength; unsigned char aData[1];
};

#pragma pack(pop)




struct D2UnitSpawnExtraStrc { int nFlags, nUniqueId; };

struct D2UnitSpawnStrc { unsigned int nUnitId; int nClassId, nX, nY; D2UnitSpawnExtraStrc tExtra; int nMode; };

extern "C" void* __cdecl memset(void*, int, unsigned int);
extern unsigned int gdwBitMasks[]; // 0x006CE268
void __stdcall BITMANIP_Initialize(D2BitBufferStrc*, unsigned char*, int); // 0x00410E40
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc*, int); // 0x00411020
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc*, int); // 0x00411030
int __fastcall sub_0044BE50_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50
int __fastcall sub_00451F50_GetUnitGUID(D2UnitStrc*); // 0x00451F50
D2UnitStrc* __fastcall sub_00466360_AddClientMonster(D2UnitSpawnStrc*, unsigned char*, unsigned char*, unsigned short, int, int); // 0x00466360
void __fastcall sub_00470B70_ResetMonsterMode(D2UnitStrc*); // 0x00470B70
void __fastcall sub_00477170_LoadPalShift(int); // 0x00477170
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc*, int, int); // 0x00478F20
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc*, int, int); // 0x00621CC0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, int, int, int, int); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc*); // 0x0063EE90

#pragma pack(push, 1)
struct D2Packet18RecordStrc
{
    unsigned char nHeader;
    unsigned short nLife;
    unsigned short nMana;
    unsigned short nStamina;
    unsigned char nValue07;
    unsigned char nValue08;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};

struct D2Packet95RecordStrc
{
    unsigned char nHeader;
    unsigned short nLife;
    unsigned short nMana;
    unsigned short nStamina;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};

struct D2Packet96RecordStrc
{
    unsigned char nHeader;
    unsigned short nStamina;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};

struct D2GSPacketSrv0DStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
    unsigned char unk0x06;
    unsigned short nX;
    unsigned short nY;
    unsigned char unk0x0B;
    unsigned char nLife;
};

#pragma pack(pop)

typedef void (__fastcall* D2PacketHandlerFn)(unsigned char* pPacket);

struct D2PacketTableEntryStrc
{
    D2PacketHandlerFn pfnHandler;
    int nSize;
    void* pfnAltHandler;
};
void __fastcall sub_004804E0_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit); // 0x004647D0
D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(D2UnitStrc* pUnit); // 0x00464770
void __fastcall sub_004647A0_SetPacketBuffer(D2UnitStrc* pUnit, D2PacketBufferStrc* pBuffer); // 0x004647A0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern int gnGlobal_007A5230; // 0x007A5230
extern D2PacketTableEntryStrc gtPacketTable_007114D0[]; // 0x007114D0

// 0x0045D3B0
static void sub_0045D3B0_SendUnitStatus(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : 6;
        const int nUnitId = pUnit->dwUnitId;
        D2PacketRecord11Strc tPacket;
        tPacket.nHeader = 0x47;
        tPacket.nUnitType = (unsigned char)nUnitType;
        tPacket.nUnitId = nUnitId;
        sub_004C1BC0(&tPacket, 0);
    }
}

// 0x0045D4B0
static void __stdcall sub_0045D4B0_OnStatChanged(int nValue, int nStat, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    switch (nStat)
    {
    case 6:
        if (nValue && pUnit->dwAnimMode == 0x11)
        {
            sub_00480E70_SetUnitMode(pUnit, 5);
            sub_004647D0(pUnit);
        }
        break;

    case 0xC:
        sub_0045D3B0_SendUnitStatus(sub_00463DD0_GetPlayerUnit());
        if (pUnit != sub_00463DD0_GetPlayerUnit())
            break;
        sub_0045D3E0(pUnit);

    case 0:
    case 2:
        sub_004C1C10(pUnit);
        break;
    }
}

void __fastcall sub_0045D540_HandleUnitStatPacket(D2UnitStatPacketStrc* pPacket)
{
    int bAdd = 0;
    int nValue;
    switch (pPacket->nHeader)
    {
    case 0x9E:
        nValue = pPacket->nByte;
        break;
    case 0xA0:
        nValue = pPacket->nDword;
        break;
    case 0xA1:
        nValue = pPacket->nByte;
        bAdd = 1;
        break;
    case 0xA2:
        bAdd = 1;

    case 0x9F:
        nValue = pPacket->nWord;
        break;
    default:
        return;
    }

    const int nStat = pPacket->nStat;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 1);
    if (!pUnit)
        return;

    if (nStat == 0xC)
        sub_0045D3B0_SendUnitStatus(pUnit);

    if (bAdd)
        STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
    else
        STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

// 0x0045D780
void __fastcall sub_0045D780_HandlePlayerStatPacket(D2PlayerStatPacketStrc* pPacket)
{
    const unsigned char nHeader = pPacket->nHeader;
    int nValue = 0;
    int nStat = -1;
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x9AA);

    switch (nHeader)
    {
    case 0x19:
        nStat = 0xE;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nByte;
        break;
    case 0x1A:
        nStat = 0xD;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nByte;
        break;
    case 0x1B:
        nStat = 0xD;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nWord;
        break;
    case 0x1C:
        nValue = pPacket->nDword;
        nStat = 0xD;
        break;
    case 0x1D:
        nValue = pPacket->nByte2;
        nStat = pPacket->nStat;
        break;
    case 0x1E:
        nValue = pPacket->nWord2;
        nStat = pPacket->nStat;
        break;
    case 0x1F:
        nValue = pPacket->nDword2;
        nStat = pPacket->nStat;
        break;
    }

    STATLIST_SetUnitStat(pPlayer, nStat, nValue, 0);
    sub_0045D4B0_OnStatChanged(nValue, nStat, pPlayer);
}

// 0x0045D880
void __fastcall sub_0045D880_HandleUnitStatPacket2(D2UnitStatPacket2Strc* pPacket)
{
    const int nValue = pPacket->nValue;
    D2UnitStrc* pUnit = sub_00463990(pPacket->nUnitId, 0);
    if (pUnit)
    {
        const int nStat = pPacket->nStat;
        STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
        sub_0045D4B0_OnStatChanged(nValue, nStat, pUnit);
    }
}

static __forceinline D2SkillsTxt* GetSkillRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x0045D6A0
void __fastcall sub_0045D6A0_EndPacketSkill(D2SkillPacketStrc* pPacket)
{
    D2UnitStrc* pUnit;
    const int nUnitType = pPacket->nUnitType;
    const int nUnitId = pPacket->nUnitId;
    const unsigned short nSkillId = pPacket->nSkillId;
    pUnit = sub_00463990(nUnitId, nUnitType);
    if (!pUnit)
        return;
    D2SkillsTxt* pSkill = GetSkillRecord(nSkillId);
    if (!pSkill)
        return;
    switch (pSkill->wSrvDoFunc)
    {
    case 67:
        sub_004CA000_EndSkill(pUnit, nSkillId);
        break;
    case 77:
    case 78:
        sub_004C8B80_EndSkill(pUnit);
        break;
    case 76:
        sub_004C9420_EndSkill(pUnit, nSkillId);
        break;
    }
    sub_00639DB0_ToggleState(pUnit, 18, 0);
}

// 0x0045DFC0
void __fastcall sub_0045DFC0_Packet26_Chat(const D2GSPacketSrv26* pPacket)
{
    D2ChatMessageStrc tMessage;
    const char* szName = pPacket->szName;
    tMessage.nHeader = pPacket->nHeader;
    tMessage.nType = pPacket->nType;
    tMessage.f_2 = pPacket->nLang;
    tMessage.nUnitType = pPacket->nUnitType;
    tMessage.nUnitId = pPacket->nUnitId;
    tMessage.nColor = pPacket->nColor;
    tMessage.nSubType = pPacket->nSubType;
    SStrCopy(tMessage.szName, szName, 0x10);
    szName += SStrLen(szName) + 1;
    SStrCopy(tMessage.szText, szName, 0x100);
    sub_0049F490_PrintChatMessage(&tMessage);
}

// 0x0045E300
void __fastcall sub_0045E300_InitializeEnvironment(D2EnvironmentPacketStrc* pPacket)
{
    const int nIndex = pPacket->nIndex;
    const int nTicks = pPacket->nTicks;
    if (gpDrlgAct_007A0634 == sub_00463DD0_GetPlayerUnit()->pDrlgAct)
    {
        ENVIRONMENT_InitializeEnvironment(gpDrlgAct_007A0634, sub_004646A0_GetPlayerRoom(), nIndex, nTicks, pPacket->bEclipse);
        sub_004646C0_UpdateObjectsForPeriod();

        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer)
        {
            D2PacketRecord11Strc tPacket;
            const int nUnitType = !pPlayer ? 6 : pPlayer->dwUnitType;
            tPacket.nUnitType = (unsigned char)nUnitType;
            tPacket.dwUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;
            tPacket.nHeader = 0x47;
            sub_004C1BC0(&tPacket, 0);
        }
    }
}

// 0x0045EB10
void __fastcall sub_0045EB10_Packet9C_ItemActionWorld(const D2GSPacketSrv9C* pPacket)
{
    D2GSPacketSrv9C tPacket = *pPacket;
    D2GSPacketSrv9C* pCopy = &tPacket;
    switch (pCopy->nAction)
    {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0x11:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xF6D);
        exit(-1);
    case 0:
        sub_004C25B0(pCopy);
        break;
    case 1:
        sub_004C2650(pCopy);
        break;
    case 2:
        sub_004C26F0(pCopy);
        break;
    case 3:
        sub_004C2810(pCopy);
        break;
    case 4:
        sub_004C2AD0(pCopy);
        break;
    case 0xA:
        sub_004C3B30_UpdateItemFromPacket9C(pCopy);
        break;
    case 0xD:
        sub_004C40D0(pCopy);
        break;
    case 0xE:
        sub_004C4130(pCopy);
        break;
    case 0xF:
        sub_004C42A0(pCopy);
        break;
    case 0x10:
        sub_004C45C0(pCopy);
        break;
    case 0x12:
        sub_004C20B0(pCopy);
        break;
    case 0xB:
    case 0xC:
        sub_004C3C00(pCopy);
        break;
    }
}

// 0x0045EC70
void __fastcall sub_0045EC70_Packet9D_ItemActionOwned(const D2GSPacketSrv9D* pPacket)
{
    D2GSPacketSrv9D tPacket = *pPacket;
    D2GSPacketSrv9D* pCopy = &tPacket;
    switch (pCopy->nAction)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x12:
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xFB7);
        exit(-1);
    case 5:
        sub_004C2C80(pCopy);
        break;
    case 6:
        sub_004C2E90(pCopy);
        break;
    case 7:
        sub_004C3070(pCopy);
        break;
    case 8:
        sub_004C3380(pCopy);
        break;
    case 9:
        sub_004C3920(pCopy);
        break;
    case 0x17:
        sub_004C3B00(pCopy);
        break;
    case 0x11:
        sub_004C4740(pCopy);
        break;
    case 0x13:
        sub_004C4990(pCopy);
        break;
    case 0x14:
        sub_004C4AA0(pCopy);
        break;
    case 0x15:
        sub_004C4C70(pCopy);
        break;
    case 0x16:
        sub_004C2340(pCopy);
        break;
    }
}

// 0x00409000
int __fastcall sub_00409000_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

// build: context Log2Ceil
static __forceinline int Log2Ceil(int nValue)
{
    return nValue < 3 ? 1 : sub_00409000_GetBitWidth(nValue - 1);
}

// build: context GetMonStats2TxtRecordFromMonsterId
static __forceinline D2MonStats2Txt* GetMonStats2TxtRecordFromMonsterId(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount) return 0;
    int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    }
    return 0;
}

// build: context GetItemStatCostTxtRecord
static __forceinline D2ItemStatCostTxt* GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0045F190
void __fastcall sub_0045F190_SpawnMonsterPacket(D2PacketSpawnStrc* pPacket)
{
    unsigned int nUnitId = pPacket->nUnitId;
    unsigned short nX = pPacket->nX;
    unsigned short nY = pPacket->nY;
    short nClassId = pPacket->nClassId;
    D2BitBufferStrc tBuffer;
    unsigned char aComponents[16];
    unsigned char aMods[9];
    BITMANIP_Initialize(&tBuffer, pPacket->aData, pPacket->nLength - 13);
    unsigned char nMode = (unsigned char)sub_00411020_ReadBits(&tBuffer, 4);
    unsigned char* pComponents = 0;
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        D2MonStats2Txt* pRecord = GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (!pRecord) return;
        pComponents = aComponents;
        for (int i = 0; i < 16; ++i)
            aComponents[i] = (unsigned char)sub_00411020_ReadBits(&tBuffer, Log2Ceil(pRecord->nComponentChoiceCounts[i]));
    }
    unsigned char* pMods = 0;
    unsigned short nFlags = 0;
    int nUniqueId = -1;
    int nSpecial = 0;
    unsigned short nPalette = 0;
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        nFlags = sub_00411020_ReadBits(&tBuffer, 1) ? 4 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 8 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 2 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 16 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 64 : 0;
        if (nFlags & 2) nSpecial = (unsigned short)BITMANIP_ReadSigned(&tBuffer, 16);
        for (int i = 0; i < 9; ++i) aMods[i] = 0;
        pMods = aMods;
        int nModIndex = 0;
        for (unsigned char nMod = (unsigned char)sub_00411020_ReadBits(&tBuffer, 8); nMod; nMod = (unsigned char)sub_00411020_ReadBits(&tBuffer, 8))
            aMods[nModIndex++] = nMod;
        nPalette = (unsigned char)sub_00411020_ReadBits(&tBuffer, 16);
        if (sub_00411020_ReadBits(&tBuffer, 1)) nUniqueId = sub_00411020_ReadBits(&tBuffer, 32);
    }
    D2UnitSpawnStrc tSpawn;
    memset(&tSpawn, 0, sizeof(tSpawn));
    tSpawn.nUnitId = nUnitId;
    tSpawn.nClassId = nClassId;
    tSpawn.nX = nX;
    tSpawn.nY = nY;
    tSpawn.tExtra.nFlags = nFlags;
    tSpawn.tExtra.nUniqueId = nUniqueId;
    tSpawn.nMode = nMode;
    sub_00477170_LoadPalShift(nClassId);
    D2UnitStrc* pUnit = sub_00466360_AddClientMonster(&tSpawn, pComponents, pMods, nPalette, nSpecial, 0);
    if (!pUnit) return;
    sub_00470B70_ResetMonsterMode(pUnit);
    if (!MONSTERS_GetHirelingTypeId(pUnit) || nUnitId != sub_00478F20_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 1))
    {
        STATLIST_SetUnitStat(pUnit, 7, 0x8000, 0);
        STATLIST_SetUnitStat(pUnit, 6, pPacket->nLife << 8, 0);
    }
    if (MONSTERS_GetHirelingTypeId(pUnit) && nMode == 1) pUnit->dwFlagEx &= ~0x40000;
    STATLIST_SetUnitStat(pUnit, 0x148, (unsigned short)(nX + nY), 0);
    if (sub_00411020_ReadBits(&tBuffer, 1)) UNITS_StoreOwnerTypeAndGUID(pUnit, 0, sub_00411020_ReadBits(&tBuffer, 31));
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        D2StatListStrc* pStatList = 0;
        for (int nStat = sub_00411020_ReadBits(&tBuffer, 9); nStat < 511; nStat = sub_00411020_ReadBits(&tBuffer, 9))
        {
            D2ItemStatCostTxt* pRecord = GetItemStatCostTxtRecord(nStat);
            if (!pRecord || pRecord->nSendBits <= 0) return;
            int nLayer = 0;
            if (pRecord->nSendParamBits > 0) nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pRecord->nSendParamBits);
            int nValue;
            if (pRecord->nSendBits < 32 && (pRecord->nItemStatFlags[0] & (unsigned char)gdwBitMasks[1]))
                nValue = BITMANIP_ReadSigned(&tBuffer, pRecord->nSendBits);
            else
                nValue = sub_00411020_ReadBits(&tBuffer, pRecord->nSendBits);
            if (!pStatList)
            {
                pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40);
                if (!pStatList)
                {
                    pStatList = STATLIST_AllocStatList(0, 0x40, 0, sub_0044BE50_GetUnitTypeOrInvalid(pUnit), sub_00451F50_GetUnitGUID(pUnit));
                    STATLIST_SetState(pStatList, 0);
                    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                }
            }
            if (pStatList) STATLIST_SetStatIfListIsValid(pStatList, nStat, nValue, nLayer);
        }
    }
}

int gnPacketBytes_007A6AF4; // 0x007A6AF4

int gnPacketBlocks_007A6AFC; // 0x007A6AFC

int gnLargePacketBlocks_007A6B04; // 0x007A6B04

unsigned char gnLastPacketId_007A5234; // 0x007A5234

static void sub_0045D900_ReadPacket18(unsigned char* pData, D2Packet18RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 0xF);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nLife = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nMana = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nValue07 = sub_00411020_ReadBits(&tBuffer, 7);
    pRecord->nValue08 = sub_00411020_ReadBits(&tBuffer, 7);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

void __fastcall sub_0045D9B0_HandlePacket18(unsigned char* pPacket)
{
    D2Packet18RecordStrc tRecord;
    sub_0045D900_ReadPacket18(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    int nLife = tRecord.nLife << 8;
    STATLIST_SetUnitStat(pPlayer, 6, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, 8, tRecord.nMana << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 0x4A, tRecord.nValue07, 0);
    STATLIST_SetUnitStat(pPlayer, 0x1A, tRecord.nValue08, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
    if (nLife && pPlayer->dwAnimMode == 0x11)
    {
        sub_00480E70_SetUnitMode(pPlayer, 5);
        sub_004647D0_UpdateAttackableFlag(pPlayer);
    }
}

static void sub_0045DA90_ReadPacket95(unsigned char* pData, D2Packet95RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 0xD);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nLife = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nMana = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

void __fastcall sub_0045DB20_HandlePacket95(unsigned char* pPacket)
{
    D2Packet95RecordStrc tRecord;
    sub_0045DA90_ReadPacket95(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    int nLife = tRecord.nLife << 8;
    STATLIST_SetUnitStat(pPlayer, 6, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, 8, tRecord.nMana << 8, 0);
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
    if (nLife && pPlayer->dwAnimMode == 0x11)
    {
        sub_00480E70_SetUnitMode(pPlayer, 5);
        sub_004647D0_UpdateAttackableFlag(pPlayer);
    }
}

static void sub_0045DBE0_ReadPacket96(unsigned char* pData, D2Packet96RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 9);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

void __fastcall sub_0045DC50_HandlePacket96(unsigned char* pPacket)
{
    D2Packet96RecordStrc tRecord;
    sub_0045DBE0_ReadPacket96(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    STATLIST_SetUnitStat(pPlayer, 10, tRecord.nStamina << 8, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    sub_004804E0_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
}

static D2PacketBufferStrc* sub_0045F610_GrowPacketBuffer(D2UnitStrc* pUnit)
{
    if (!gnGlobal_007A5230)
    {
        for (int i = 0; i < 0xAF; ++i)
        {
            if (gtPacketTable_007114D0[i].pfnAltHandler && gtPacketTable_007114D0[i].nSize > gnGlobal_007A5230)
            {
                gnGlobal_007A5230 = gtPacketTable_007114D0[i].nSize;
            }
        }
        gnGlobal_007A5230 += 5;
    }
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (!pBuffer)
    {
        pBuffer = (D2PacketBufferStrc*)FOG_Alloc(0x10, ".\\GAME\\SCmd.cpp", 0x1266, 0);
        memset(pBuffer, 0, 0x10);
        sub_004647A0_SetPacketBuffer(pUnit, pBuffer);
    }
    int nNewMax = pBuffer->nMax + 5;
    unsigned char* pData = (unsigned char*)FOG_Alloc(gnGlobal_007A5230 * nNewMax, ".\\GAME\\SCmd.cpp", 0x126B, 0);
    memset(pData, 0, gnGlobal_007A5230 * nNewMax);
    if (pBuffer->pData)
    {
        memcpy(pData, pBuffer->pData, pBuffer->nMax * gnGlobal_007A5230);
        FOG_Free(pBuffer->pData, ".\\GAME\\SCmd.cpp", 0x126F, 0);
    }
    pBuffer->nMax = nNewMax;
    pBuffer->pData = pData;
    return pBuffer;
}

static void __stdcall sub_0045F730_QueuePacket(unsigned char* pPacket, int nLength, D2UnitStrc* pUnit)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (!pBuffer || pBuffer->nCount + 1 == pBuffer->nMax)
    {
        pBuffer = sub_0045F610_GrowPacketBuffer(pUnit);
    }
    D2_ASSERT(nLength <= gnGlobal_007A5230, 0x127F);
    memcpy(pBuffer->pData + pBuffer->nCount * gnGlobal_007A5230, pPacket, nLength);
    ++pBuffer->nCount;
}

static __forceinline void sub_0045F7B0_FindStoppedPlayer(const unsigned char* pPacket)
{
    const int nUnitId = *(const int*)(pPacket + 2);
    __assume((nUnitId | 1) != 0);
    if (pPacket[1] == 1)
    {
        sub_00463990(nUnitId, 1);
    }
}

// 0x0045F7B0
void __fastcall sub_0045F7B0_ProcessPackets(unsigned char* pData, int nSize)
{
    if (nSize == -1)
    {
        return;
    }

    int nRemaining = nSize;
    unsigned char* pPacket = pData;
    GetTickCount();
    if (nSize > 500)
    {
        ++gnLargePacketBlocks_007A6B04;
    }

    while (nRemaining > 0)
    {
        unsigned char nId = *pPacket;
        int nPacketSize;
        int nUnitId;
        int nUnitType;
        if (!sub_0052B920(pPacket, nSize, &nPacketSize))
        {
            return;
        }

        unsigned short nLength = (unsigned short)nPacketSize;
        D2_ASSERT(nId < 0xAF, 0x1449);
        D2PacketTableEntryStrc* pEntry = &gtPacketTable_007114D0[nId];
        if (pEntry->nSize != -1)
        {
            D2_ASSERT(nLength == pEntry->nSize, 0x1450);
        }

        if (pEntry->nSize == -1 || nLength == pEntry->nSize)
        {
            if (pEntry->pfnAltHandler)
            {
                switch (nId)
                {
                case 0x67: case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D:
                    nUnitId = *(int*)(pPacket + 1);
                    nUnitType = 1;
                    break;
                default:
                    nUnitId = *(int*)(pPacket + 2);
                    nUnitType = pPacket[1];
                    break;
                }

                D2UnitStrc* pUnit = sub_00463990(nUnitId, nUnitType);
                if (pUnit)
                {
                    sub_0045F730_QueuePacket(pPacket, nLength, pUnit);
                }
            }

            switch (nId)
            {
            case 0x18:
            {
                D2Packet18RecordStrc tRecord;
                sub_0045D900_ReadPacket18(pPacket, &tRecord);
                break;
            }
            case 0x95:
            {
                D2Packet95RecordStrc tRecord;
                sub_0045DA90_ReadPacket95(pPacket, &tRecord);
                break;
            }
            case 0x96:
            {
                D2Packet96RecordStrc tRecord;
                sub_0045DBE0_ReadPacket96(pPacket, &tRecord);
                break;
            }
            case 0x0D:
                sub_0045F7B0_FindStoppedPlayer(pPacket);
                break;
            }

            if (pEntry->pfnHandler)
            {
                pEntry->pfnHandler(pPacket);
            }
        }

        gnPacketBytes_007A6AF4 += nLength;
        nRemaining -= nLength;
        pPacket += nLength;
        gnLastPacketId_007A5234 = nId;
    }

    ++gnPacketBlocks_007A6AFC;
}
