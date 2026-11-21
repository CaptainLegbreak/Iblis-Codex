#include "D2Client.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

union D2SeedStrc;
struct D2SkillsTxt;
struct D2MissileStrc;
struct D2SkillDescTxt;





typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2UnitStrc* __fastcall sub_004CD540_CreateMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

struct D2SkillDescTxt
{
    unsigned char beforeStrings[8];
    unsigned short strings[(0x120 - 8) / sizeof(unsigned short)];
};

typedef char B07RealSkillsSize[(sizeof(D2SkillsTxt) == 0x23C) ? 1 : -1];

typedef char B07RealDescriptionSize[(sizeof(D2SkillDescTxt) == 0x120) ? 1 : -1];


// 0x004E3AB0
void __fastcall sub_004E3AB0_CreateStateSkillMissile(D2UnitStrc* pUnit)
{
    if (!pUnit->pDynamicPath || !sub_006505C0_TestPathFlag8(pUnit->pDynamicPath))
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, 13);
    if (!pStatList)
    {
        return;
    }

    const int nSkillId = STATLIST_GetStatValue(pStatList, 350, 0);
    int nSkillLevel = STATLIST_GetStatValue(pStatList, 351, 0);
    if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return;
    }

    if (nSkillLevel < 0)
    {
        nSkillLevel = 1;
    }

    D2SkillsTxt* pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return;
    }

    const int nCltMissile = pSkillsTxt->wCltMissileA;
    if (nCltMissile < 0 || nCltMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x21;
    tMissile.pOwner = pUnit;
    tMissile.nX = nX;
    tMissile.nY = nY;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = pSkillsTxt->wCltMissileA;

    if (pSkillsTxt->wCltMissileB >= 0)
    {
        if (pSkillsTxt->wCltMissileC >= 0)
        {
            switch (SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3))
            {
            case 0:
                tMissile.nMissile = pSkillsTxt->wCltMissileB;
                break;

            case 1:
                tMissile.nMissile = pSkillsTxt->wCltMissileC;
                break;
            }
        }
        else if (!SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2))
        {
            tMissile.nMissile = pSkillsTxt->wCltMissileB;
        }
    }

    sub_004CD540_CreateMissile(&tMissile);
}

static __forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline D2SkillDescTxt* SKILLTREE_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
    {
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    }
    return 0;
}

// 0x004E6CE0
unsigned short __fastcall sub_004E6CE0_GetStringId(int skillId, int stringIndex)
{
    D2SkillsTxt* skill = SKILLS_GetSkillsTxtRecord(skillId);
    D2SkillDescTxt* description = 0;
    if (skill)
    {
        description = SKILLTREE_GetSkillDescTxtRecord(skill->wSkillDesc);
    }
    if (!description)
    {
        return static_cast<unsigned short>(0x1506);
    }
    return description->strings[stringIndex];
}
