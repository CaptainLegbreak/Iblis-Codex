#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2DataTbls.h"

struct D2GraphicsInterfaceStrc;
struct D2MonStatsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
extern D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0
extern D2GraphicsInterfaceStrc* gapGraphicsInterfaces[]; // 0x0072DA80

static D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline_J03(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int MONSTERS_GetBaseIdInline_J03(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline_J03(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nMonsterId;
}

// 0x004F4EC0
int __fastcall sub_004F4EC0_GetSkillOverlay(D2UnitStrc* pUnit, int nSkillId, int nDefault, int nUnused)
{
    int nResult = nDefault;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERS_GetBaseIdInline_J03(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_BLOODRAVEN && nSkillId == SKILL_NEST)
        {
            GFX_AddUnitOverlay(pUnit, 0x55, 2, 0, 0, 0, 0, 0);
            nResult = 0x54;
        }
    }

    return nResult;
}

// 0x004F4FF0
int __fastcall sub_004F4FF0_SetVideoMode(int nMode)
{
    D2GraphicsInterfaceStrc* pInterface = gapGraphicsInterfaces[nMode];
    if (!pInterface)
    {
        sub_00410610_WriteLogLine("Unsupported video mode - %d", nMode);
        return 0;
    }
    gpGraphicsInterface = pInterface;
    return 1;
}

#include "gen/data/Source/D2Client/Unknown_004F4EC0.inc"
