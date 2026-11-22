#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2TxtTables.h"

#define UNIT_MONSTER 1
struct D2MissilesTxt;
struct D2GSPacketSrv73;
struct D2MonUModTxt;
struct D2MonsterDataStrc;
struct D2MonStatsTxt;
struct Data005A0120;
struct Unit005A0120;
struct Data005A0180;
struct Unit005A0180;
struct Data004AC780;
struct Unit004AC780;
struct Data005A01E0;
struct Unit005A01E0;
struct Data005A0200;
struct Unit005A0200;
union D2SeedStrc;

struct D2MissilesTxt { int unk00; unsigned int dwMissileFlags; char unk08[0x19C]; };

#pragma pack(push, 1)
struct D2GSPacketSrv73 { unsigned char nHeader; int unk01; unsigned short nMissileId; int nX; int nY; int nFirstX; int nFirstY; unsigned short nCurrentFrame; unsigned char nUnitType; int nUnitGUID; unsigned char nLevel; unsigned char nPierce; };

#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned char gnMissileFlag_006CE27C; // 0x006CE27C

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0
int __stdcall sub_0064A3E0_GetMissileId(D2UnitStrc*); // 0x0064A3E0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10
int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc*); // 0x0064A380
int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
void __fastcall D2GAME_PACKETS_SendPacket0x73(D2ClientStrc*, D2GSPacketSrv73*); // 0x0053DA10

struct D2MonStatsTxt
{
    char unk0x00[0x1C];
    short wMonType;
    char unk0x1E[0x18A];
};

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

struct Data005A0120 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwField1C;
};

struct Unit005A0120 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0120* pData;
};

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010
int __fastcall sub_005A00F0_GetMonUModConstant(int nIndex); // 0x005A00F0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

struct Data005A0180 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned short wUnknown14;
    unsigned short wFlags16;
};

struct Unit005A0180 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0180* pData;
};

#pragma pack(push, 1)
struct Data004AC780 { unsigned char bUnknown00[0x14]; unsigned short wValue14; };

#pragma pack(pop)
struct Unit004AC780 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data004AC780* pData;
};

struct Data005A01E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned short wUnknown24;
    short sValue26;
};

struct Unit005A01E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A01E0* pData;
};

#pragma pack(push, 1)
struct Data005A0200 { unsigned char bUnknown00[0x26]; unsigned short wValue26; };

#pragma pack(pop)
struct Unit005A0200 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A0200* pData;
};
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

__forceinline D2MissilesTxt* GetMissilesTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nId];
    return 0;
}

// 0x0059FEE0
void __fastcall MISSILES_SyncToClient(D2ClientStrc* pClient, D2GameStrc* pGame, D2UnitStrc* pMissile, int bSendPath)
{
    if (!pMissile || pMissile->dwUnitType != UNIT_MISSILE)
        return;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
        return;
    D2MissilesTxt* pMissilesTxt = GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxt || !(pMissilesTxt->dwMissileFlags & gnMissileFlag_006CE27C))
        return;
    D2GSPacketSrv73 packet = {};
    packet.nHeader = 0x73;
    packet.nMissileId = sub_0064A3E0_GetMissileId(pMissile);
    packet.nX = CLIENTS_GetUnitX(pMissile);
    packet.nY = CLIENTS_GetUnitY(pMissile);
    if (bSendPath)
    {
        packet.nFirstX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath);
        packet.nFirstY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath);
    }
    packet.nCurrentFrame = sub_0064A380_GetRemainingFrames(pMissile);
    const int nOwnerType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    packet.nUnitType = nOwnerType;
    packet.nUnitGUID = pOwner->dwUnitId;
    packet.nLevel = MISSILE_GetLevel(pMissile);
    packet.nPierce = STATLIST_UnitGetStatValue(pMissile, STAT_PIERCE_IDX, 0);
    D2GAME_PACKETS_SendPacket0x73(pClient, &packet);
}
