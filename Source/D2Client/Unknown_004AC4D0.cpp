#include "D2Client.h"

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short wValue = 0) : wChar(wValue) {}
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
};

struct D2SkillsTxt
{
    short nSkillId;
    unsigned short unk0x02;
    unsigned char nFlags[8];
    char unk0x0C[0x164];
    unsigned int dwSkPoints;
    char unk0x174[0x20];
    short wSkillDesc;
    char unk0x196[0xA6];
};

struct D2SkillDescTxt
{
    unsigned short wSkillDesc;
    char nSkillPage;
    unsigned char nSkillRow;
    unsigned char nSkillColumn;
    unsigned char nListRow;
    unsigned char nListPool;
    unsigned char nIconCel;
    char unk0x08[0x118];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB8C];
    D2SkillDescTxt* pSkillDescTxt;
    char unk0xB90[0x4];
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[0x4];
    int nSkillsTxtRecordCount;
};

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_00724BEC;                                                                               // 0x00724BEC
extern int gnGlobal_007C0C44;                                                                               // 0x007C0C44
extern int ganSkillMode_007C0838[];                                                                         // 0x007C0838
extern int ganSkillState_007C0A38[];                                                                        // 0x007C0A38

int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit);                                                 // 0x00451F60
D2UnitStrc* __cdecl sub_00463DD0();                                                               // 0x00463DD0
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
void __stdcall sub_004ABF60_DrawSkillIcon(int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nState, int nMode); // 0x004ABF60
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                 // 0x00526320
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140

static inline D2SkillsTxt* SKILLTREE_GetSkillsTxtRecord(int nSkillId)
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

static inline D2SkillDescTxt* SKILLTREE_GetSkillDescRec(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = SKILLTREE_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        return SKILLTREE_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    }
    return 0;
}

// 0x004AC4D0
void __cdecl sub_004AC4D0_DrawSkillTree()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;

    if (!gnGlobal_007C0C44)
    {
        Unicode wszText[10];
        char szText[12];
        wsprintfA(szText, "%d", gnGlobal_007C0C44);
        sub_00526320_ToUnicode(wszText, szText, 9);
        const int nX = gnGlobal_0071146C - gnGlobal_007A2858;
        sub_004A7080(nX - 0x41, gnGlobal_00711470 + gnGlobal_007A285C - 0x190, nX - 0x19, wszText, 0);
    }

    for (int i = 0; i < SKILLS_GetPlayerSkillCount(sub_00451F60_UnitClassId(pPlayer)); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(sub_00451F60_UnitClassId(pPlayer), i);
        D2SkillsTxt* pSkillsTxt = SKILLTREE_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxt)
        {
            continue;
        }

        D2SkillDescTxt* pDesc = SKILLTREE_GetSkillDescRec(nSkillId);
        if (!pDesc || gnGlobal_00724BEC != pDesc->nSkillPage)
        {
            continue;
        }

        ganSkillState_007C0A38[i] = -1;
        ganSkillMode_007C0838[i] = 5;
        int nSkillLevel = 0;
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, nSkillId, -1);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
            if (nSkillLevel > 0)
            {
                ganSkillState_007C0A38[i] = 0;
                ganSkillMode_007C0838[i] = 0;
            }
        }
        sub_004ABF60_DrawSkillIcon(nSkillId, pSkillsTxt, nSkillLevel, ganSkillState_007C0A38[i], ganSkillMode_007C0838[i]);
    }
}
