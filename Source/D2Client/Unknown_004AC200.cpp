#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"



struct D2SkillDescTxt
{
    char unk0x00[0x02];
    char nSkillPage;
    char unk0x03[0x11D];
};


extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId);                                                 // 0x004AA8B0
void __stdcall sub_004ABF60_DrawSkillButton(int nSkillId, D2SkillsTxt* pSkillsTxt, int nLevel, int nState, int nFrame); // 0x004ABF60
void __fastcall sub_00502320_DrawText(const wchar_t* wszText, int nX, int nY, int nColor, int bCentered);   // 0x00502320
void __fastcall sub_00526320_ToUnicode(wchar_t* wszDest, const char* szSource, int nLength);               // 0x00526320
int __stdcall sub_006253B0(D2UnitStrc* pUnit, int nStatId, int nLayer);                    // 0x006253B0
int __stdcall sub_00639DF0_CheckState(D2UnitStrc* pUnit, int nState);                                       // 0x00639DF0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);              // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                    // 0x006442A0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern int gnSkillPage_00724BEC;                                                                            // 0x00724BEC
extern int gnPanelOffsetX_007A2858;                                                                         // 0x007A2858
extern int gnPanelOffsetY_007A285C;                                                                         // 0x007A285C
extern int gaSkillButtonFrame_007C0838[];                                                                   // 0x007C0838
extern int gaSkillButtonState_007C0A38[];                                                                   // 0x007C0A38
extern int gbSkillPointsHighlight_007C0C3C;                                                                 // 0x007C0C3C

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2SkillDescTxt* DATATBLS_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
    {
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    }

    return 0;
}

// build: context sub_004AC200_GetSkillDescFromSkillId
inline D2SkillDescTxt* sub_004AC200_GetSkillDescFromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return DATATBLS_GetSkillDescTxtRecord(pSkillsTxtRecord->wSkillDesc);
}

// 0x004AC200
void __cdecl sub_004AC200_RefreshSkillTree()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }

    const int nClass = pPlayer->dwClassId;
    char szText[12];
    wchar_t wszText[10];
    wszText[0] = 0;
    wszText[1] = 0;
    wszText[2] = 0;
    wszText[3] = 0;
    wszText[4] = 0;
    wszText[5] = 0;
    wszText[6] = 0;
    wszText[7] = 0;
    wszText[8] = 0;
    wszText[9] = 0;
    wsprintfA(szText, "%i", sub_006253B0(pPlayer, 5, 0));
    sub_00526320_ToUnicode(wszText, szText, 9);

    D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
    if ((pUnit && sub_00639DF0_CheckState(pUnit, 0x36)) || gbSkillPointsHighlight_007C0C3C)
    {
        sub_00502320_DrawText(wszText, gnScreenWidth_0071146C - gnPanelOffsetX_007A2858 - 0x34, gnScreenHeight_00711470 + gnPanelOffsetY_007A285C - 0x190, 1, 0);
    }
    else
    {
        sub_00502320_DrawText(wszText, gnScreenWidth_0071146C - gnPanelOffsetX_007A2858 - 0x34, gnPanelOffsetY_007A285C + gnScreenHeight_00711470 - 0x190, 0, 0);
    }

    int bCanLearn;
    int nLevel;
    const int nPoints = sub_006253B0(pPlayer, 5, 0);
    for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClass); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClass, i);
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        D2SkillDescTxt* pSkillDescTxtRecord = sub_004AC200_GetSkillDescFromSkillId(nSkillId);
        if (!pSkillDescTxtRecord || gnSkillPage_00724BEC != pSkillDescTxtRecord->nSkillPage)
        {
            continue;
        }

        if (SKILLS_CheckRequiredSkills(pPlayer, nSkillId))
        {
            bCanLearn = 1;
            nLevel = 0;
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, nSkillId, -1);
            if (pSkill)
            {
                nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);
            }

            if (nLevel >= sub_004AA8B0_GetSkillMaxLevel(pSkillsTxtRecord->nSkillId))
            {
                bCanLearn = 0;
            }

            if (!SKILLS_CheckRequiredAttributes(pPlayer, nSkillId))
            {
                bCanLearn = 0;
            }

            int nRequired = 1;
            if (pSkillsTxtRecord->dwSkPoints != -1)
            {
                nRequired = SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxtRecord->dwSkPoints, nSkillId, nLevel);
            }

            if (nPoints >= nRequired && bCanLearn)
            {
                if (gaSkillButtonState_007C0A38[i] != 1)
                {
                    gaSkillButtonState_007C0A38[i] = 0;
                    gaSkillButtonFrame_007C0838[i] = 0;
                }
            }
            else
            {
                gaSkillButtonState_007C0A38[i] = -1;
                gaSkillButtonFrame_007C0838[i] = 5;
            }

            int nBaseLevel = 0;
            if (pSkill)
            {
                nBaseLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
            }
            sub_004ABF60_DrawSkillButton(nSkillId, pSkillsTxtRecord, nBaseLevel, gaSkillButtonState_007C0A38[i], gaSkillButtonFrame_007C0838[i]);
        }
        else
        {
            gaSkillButtonState_007C0A38[i] = -1;
            gaSkillButtonFrame_007C0838[i] = 5;
            int nBaseLevel;
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, pSkillsTxtRecord->nSkillId, -1);
            if (pSkill && (nBaseLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1)))
            {
                sub_004ABF60_DrawSkillButton(nSkillId, pSkillsTxtRecord, nBaseLevel, gaSkillButtonState_007C0A38[i], gaSkillButtonFrame_007C0838[i]);
            }
            else
            {
                sub_004ABF60_DrawSkillButton(nSkillId, pSkillsTxtRecord, 0, gaSkillButtonState_007C0A38[i], gaSkillButtonFrame_007C0838[i]);
            }
        }
    }
}
