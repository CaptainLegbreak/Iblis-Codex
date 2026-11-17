#include "D2Game.h"

struct D2CoordStrc { int nX; int nY; };
struct D2ObjectsTxt { char unk_00[0x167]; unsigned char nFlags; };
struct D2ObjectDataStrc { D2ObjectsTxt* pObjectsTxt; unsigned char nInteractType; };
struct D2UnitStrc {
    unsigned int dwUnitType; int dwClassId; void* pPool; int dwUnitId; int dwAnimMode;
    union { char* szName; D2ObjectDataStrc* pObjectData; };
    char unk_18[0x14]; D2DynamicPathStrc* pDynamicPath;
    char unk_30[0x30]; D2InventoryStrc* pInventory;
    char unk_64[0x60]; unsigned int dwFlags;
};
struct D2MonStatsTxt { char unk_00[0x16C]; unsigned char nSendSkill[4]; short nSkill[8]; };
struct D2DataTablesStrc { char unk_00[0xBA0]; int nSkillsTxtRecordCount; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
#define D2_ASSERT(x, line) if (!(x)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc*, int); // 0x00451F30
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int); // 0x00451F80
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc*, unsigned int); // 0x00463720
void __fastcall PLAYER_SynchronizeItemsToClient(D2UnitStrc*, D2ClientStrc*); // 0x00534F80
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc*, int); // 0x00537860
void __fastcall D2GAME_PACKETS_SendPacket0x09_6FC3D1A0(D2ClientStrc*, unsigned char, unsigned char, unsigned int, unsigned char, unsigned short, unsigned short); // 0x0053BCD0
void __fastcall D2GAME_PACKETS_SendPacket0x51_6FC3D300(D2ClientStrc*, unsigned char, unsigned char, int, unsigned short, unsigned short, unsigned short, unsigned char, unsigned char); // 0x0053BD10
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc*, D2UnitStrc*, unsigned short, int, int); // 0x0053C4A0
void __fastcall sub_6FC3F550(D2ClientStrc*, D2UnitStrc*); // 0x0053D900
void __fastcall D2GAME_PACKETS_SendPacket0x74_6FC3F640(D2ClientStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x0053DA40
void __fastcall D2GAME_PACKETS_SendPacket0x82_6FC3F790(D2GameStrc*, D2ClientStrc*, int, int); // 0x0053DB90
void __fastcall sub_6FC3FAF0(D2ClientStrc*, unsigned int, unsigned short); // 0x0053E0A0
void __fastcall sub_0053E2E0_SendMonster(D2ClientStrc*, D2UnitStrc*); // 0x0053E2E0
void __fastcall sub_6FC3D1F0(D2ClientStrc*, int, unsigned char, const char*, short, short); // 0x0053E8F0
void __fastcall D2GAME_SendP0x9C_ItemAction_AddToGround_6FC3E850(D2ClientStrc*, D2UnitStrc*, unsigned int); // 0x0053EC00
void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(D2ClientStrc*, D2UnitStrc*, D2UnitStrc*, int); // 0x0053EC90
void __fastcall sub_6FC82270(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x005484B0
void __fastcall sub_6FC82830(D2UnitStrc*, D2ClientStrc*); // 0x005489F0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60
D2UnitStrc* __fastcall sub_00553720_GetPortalOwner(D2GameStrc*, D2UnitStrc*); // 0x00553720
int __fastcall SUNIT_IsDead(D2UnitStrc*); // 0x005541B0
void __fastcall sub_6FC42050(D2UnitStrc*, D2ClientStrc*); // 0x0055BED0
void __fastcall D2GAME_STATES_SendUnitStates_6FCC58E0(D2UnitStrc*, D2ClientStrc*); // 0x00570E30
void __fastcall sub_00571620(D2UnitStrc*, D2ClientStrc*); // 0x00571620
void __fastcall sub_6FCC6540(D2UnitStrc*, D2ClientStrc*); // 0x00571CD0
int __fastcall sub_0058F710(D2UnitStrc*); // 0x0058F710
void __fastcall MONSTERMSG_SendMonsterModeUpdate(D2GameStrc*, D2UnitStrc*, D2ClientStrc*); // 0x00597E20
void __fastcall sub_0059FEE0_SendMissile(D2ClientStrc*, D2GameStrc*, D2UnitStrc*, int); // 0x0059FEE0
void __stdcall UNITS_GetCoords(D2UnitStrc*, D2CoordStrc*); // 0x00620870
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0
int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc*); // 0x0063A320
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc*); // 0x0063D450
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0
int __stdcall sub_006486C0(D2DynamicPathStrc*); // 0x006486C0
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
        if (pUnit->pObjectData->pObjectsTxt->nFlags & 4)
        {
            sub_6FC3F550(pClient, pUnit);
            if ((short)nClassId == 59)
            {
                D2UnitStrc* pOwner = sub_00553720_GetPortalOwner(pGame, pUnit);
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
            sub_0053E2E0_SendMonster(pClient, pUnit);
            STATLIST_SetUnitStat(pUnit, 328, (unsigned short)(tCoords.nX + tCoords.nY), 0);
            if (pUnit->dwClassId == 528)
                sub_6FC3FAF0(pClient, pUnit->dwUnitId, sub_0058F710(pUnit));
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
        sub_0059FEE0_SendMissile(pClient, pGame, pUnit, sub_006486C0(UnitPath(pUnit)));
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
