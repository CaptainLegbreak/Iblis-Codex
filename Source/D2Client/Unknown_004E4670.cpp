#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"




typedef unsigned short Unicode;
unsigned short __fastcall SKILLDESC_GetSkillDescStringId(int skillId, int stringIndex); // 0x004E6CE0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
extern "C" __declspec(dllexport) unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc); // 0x005267E0
int __stdcall SKILLS_IsPlayerClassSkill(int nSkillId, int* pPlayerClass); // 0x00645080
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static inline D2CharStatsTxt* sub_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x004E4670
void __fastcall sub_004E4670_BuildSkillBonusText(D2UnitStrc* pUnit, Unicode* pBuffer, int a3, int a4, int nStatId)
{
    D2StatStrc tStats[128];
    Unicode wszLine[128];
    Unicode wszValue[128];
    char szNum[10];
    Unicode wszNum[10];

    for (int j = 0; j < 128; ++j)
    {
        wszLine[j] = 0;
    }
    for (int j = 0; j < 128; ++j)
    {
        wszValue[j] = 0;
    }

    const Unicode* wszNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* wszPlus = D2LANG_GetStringFromTblIndex(0xFA2);
    const Unicode* wszTo = D2LANG_GetStringFromTblIndex(0xFA3);
    const Unicode* wszSpace = D2LANG_GetStringFromTblIndex(0xF9B);

    const int nCount = STATLIST_CopyStats(pUnit, nStatId, tStats, 128);
    for (int i = 0; i < nCount; ++i)
    {
        wszLine[0] = 0;
        wszValue[0] = 0;
        const int nSkillId = tStats[i].nLayer;
        const int nValue = tStats[i].nValue;

        const Unicode* wszSkillName = D2LANG_GetStringFromTblIndex(SKILLDESC_GetSkillDescStringId(nSkillId, 0));
        wszNum[0] = 0;
        wszNum[1] = 0;
        wszNum[2] = 0;
        wszNum[3] = 0;
        wszNum[4] = 0;
        wszNum[5] = 0;
        wszNum[6] = 0;
        wszNum[7] = 0;
        wszNum[8] = 0;
        wszNum[9] = 0;
        SStrPrintf(szNum, 10, "%i", nValue);
        sub_00526320_ToUnicode(wszNum, szNum, 9);

        if (nValue > 0)
        {
            sub_005267E0(wszValue, wszPlus);
            sub_00526700(wszValue, wszNum);
        }
        else
        {
            sub_005267E0(wszValue, wszNum);
        }

        sub_005267E0(wszLine, wszValue);
        sub_00526700(wszLine, wszSpace);
        sub_00526700(wszLine, wszTo);
        sub_00526700(wszLine, wszSpace);
        sub_00526700(wszLine, wszSkillName);

        if (nStatId == 0x6B)
        {
            sub_00526700(wszLine, wszSpace);
            int nClass = 7;
            if (SKILLS_IsPlayerClassSkill(nSkillId, &nClass))
            {
                if (nClass < 0 || nClass >= 7)
                {
                    sub_00526700(wszLine, wszNewLine);
                    sub_00526700(pBuffer, wszLine);
                    return;
                }

                D2CharStatsTxt* pCharStatsTxt = sub_GetCharStatsTxtRecord(nClass);
                if (!pCharStatsTxt)
                {
                    sub_00526700(wszLine, wszNewLine);
                    sub_00526700(pBuffer, wszLine);
                    return;
                }

                sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(pCharStatsTxt->wStrClassOnly));
            }
        }

        sub_00526700(wszLine, wszNewLine);
        sub_00526700(pBuffer, wszLine);
    }
}
