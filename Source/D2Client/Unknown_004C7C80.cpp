#include "D2Client.h"
#include "D2DataTbls.h"

struct D2SkillsTxt;


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_INTOWN = 8,
};

struct D2SkillsTxt
{
    char unk0x00[4];
    unsigned char nFlags[8];
    char unk0x0C[0x23C - 0x0C];
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
void __stdcall sub_Z12_EmitUse(int nValue);

// 0x004C7C80
int __cdecl sub_004C7C80_GetMissilesTxtRecordCount()
{
    return sgptDataTables->nMissilesTxtRecordCount;
}

// 0x004C8350
static int __stdcall sub_004C8350_CanTargetRoom(int nSkillId, D2UnitStrc* pUnit, int nX, int nY)
{
    D2SkillsTxt* pSkillsTxt = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxt)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    D2ActiveRoomStrc* pTarget = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
    if (!pTarget)
        return 0;
    if (!(pSkillsTxt->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]) && DUNGEON_IsRoomInTown(pTarget))
        return 0;
    return 1;
}

void __fastcall sub_Z12_EmitCanTargetRoom(D2UnitStrc* pUnit, int nSkillId)
{
    sub_Z12_EmitUse(sub_004C8350_CanTargetRoom(nSkillId, pUnit, 0x2D, 0x2F));
}
