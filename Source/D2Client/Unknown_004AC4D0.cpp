#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2Unicode.h"

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern int gnScreenWidth;                                                                               // 0x0071146C
extern int gnPanelOffsetX;                                                                               // 0x007A2858
extern int gnPanelOffsetY;                                                                               // 0x007A285C
extern int gnSkillPage;                                                                               // 0x00724BEC
extern int gbInSkillPanelDraw;                                                                               // 0x007C0C44
extern int gaSkillButtonFrame[];                                                                         // 0x007C0838
extern int gaSkillButtonState[];                                                                        // 0x007C0A38

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit);                                                 // 0x00451F60
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
void __stdcall sub_004ABF60_DrawSkillIcon(int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nState, int nMode); // 0x004ABF60
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
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
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    if (!gbInSkillPanelDraw)
    {
        Unicode wszText[10];
        char szText[12];
        wsprintfA(szText, "%d", gbInSkillPanelDraw);
        sub_00526320_ToUnicode(wszText, szText, 9);
        const int nX = gnScreenWidth - gnPanelOffsetX;
        TEXT_DrawCenteredText(nX - 0x41, gnScreenHeight + gnPanelOffsetY - 0x190, nX - 0x19, wszText, 0);
    }

    for (int i = 0; i < SKILLS_GetPlayerSkillCount(GAME_GetUnitClassId(pPlayer)); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(GAME_GetUnitClassId(pPlayer), i);
        D2SkillsTxt* pSkillsTxt = SKILLTREE_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxt)
        {
            continue;
        }

        D2SkillDescTxt* pDesc = SKILLTREE_GetSkillDescRec(nSkillId);
        if (!pDesc || gnSkillPage != pDesc->nSkillPage)
        {
            continue;
        }

        gaSkillButtonState[i] = -1;
        gaSkillButtonFrame[i] = 5;
        int nSkillLevel = 0;
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, nSkillId, -1);
        if (pSkill)
        {
            nSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
            if (nSkillLevel > 0)
            {
                gaSkillButtonState[i] = 0;
                gaSkillButtonFrame[i] = 0;
            }
        }
        sub_004ABF60_DrawSkillIcon(nSkillId, pSkillsTxt, nSkillLevel, gaSkillButtonState[i], gaSkillButtonFrame[i]);
    }
}
