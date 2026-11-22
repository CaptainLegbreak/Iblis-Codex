#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2Records.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
struct D2SkillStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                              // 0x00681EF0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);           // 0x006CC468

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern "C" const char gszFormatD_006D57BC[];                                                                // 0x006D57BC
extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470
extern int gnGlobal_007A2858;                                                                               // 0x007A2858
extern int gnGlobal_007A285C;                                                                               // 0x007A285C
extern int gnGlobal_00724BEC;                                                                               // 0x00724BEC
extern int gnTabSelection_00724CE0;                                                                         // 0x00724CE0
extern int gbGlobal_007C0C38;                                                                               // 0x007C0C38
extern "C" int gnValue_007C0C3C;                                                                            // 0x007C0C3C
extern int gnGlobal_007C0C44;                                                                               // 0x007C0C44
extern int gnGlobal_007C0C4C;                                                                               // 0x007C0C4C
int ganSkillMode_007C0838[128];                                                                             // 0x007C0838
extern int ganSkillState_007C0A38[];                                                                        // 0x007C0A38

int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __cdecl sub_0044DA70();                                                                                // 0x0044DA70
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit);                                                 // 0x00451F60
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS* pMsg);                                           // 0x00467F20
void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg);                                           // 0x00467FA0
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0
void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                         // 0x004A89D0
void* __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt);                                       // 0x004A8C80
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId);                                                 // 0x004AA8B0
int __cdecl sub_004AA900_IsStateOrValue();                                                                  // 0x004AA900
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
void __fastcall SKILLDESC_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY); // 0x004EEF00
void __fastcall SKILLDESC_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY); // 0x004EF410
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);         // 0x00502320
int __fastcall sub_00502EF0(int nArg);                                                                      // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId);                        // 0x00644300
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

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

// build: context SKILLTREE_GetSkillDescRec
static inline D2SkillDescTxt* SKILLTREE_GetSkillDescRec(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = SKILLTREE_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        return SKILLTREE_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    }
    return 0;
}

// 0x004AA9C0
static int sub_004AA9C0_GetSkillRowY(unsigned char nRow)
{
    if (nRow == 1)
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x1A2;
    if (nRow == 2)
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x15E;
    if (nRow == 3)
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x11A;
    if (nRow == 4)
        return gnGlobal_00711470 + gnGlobal_007A285C - 0xD6;
    if (nRow == 5)
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x91;
    if (nRow == 6)
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x4D;
    return 0;
}

// 0x004AAA50
static int sub_004AAA50_GetSkillColumnX(unsigned char nColumn)
{
    if (nColumn == 1)
        return gnGlobal_0071146C - gnGlobal_007A2858 - 0x131;
    if (nColumn == 2)
        return gnGlobal_0071146C - gnGlobal_007A2858 - 0xEC;
    if (nColumn == 3)
        return gnGlobal_0071146C - gnGlobal_007A2858 - 0xA7;
    return 0;
}

// 0x004AB5F0
static int __stdcall sub_004AB5F0_IsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + nWidth && nMouseY >= nY - nHeight && nMouseY <= nY)
        return 1;
    return 0;
}

// 0x004AB630
void __cdecl sub_004AB630_DrawTabHint()
{
    if (gnTabSelection_00724CE0 == 1)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0x95, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_0071146C - gnGlobal_007A2858 - 0x86, gnGlobal_00711470 + gnGlobal_007A285C - 0x62, 0, 1);
    }
    else if (gnTabSelection_00724CE0 == 2)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0xDC, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_0071146C - gnGlobal_007A2858 - 0xCD, gnGlobal_00711470 + gnGlobal_007A285C - 0x62, 0, 1);
    }
    else if (gnTabSelection_00724CE0 == 3)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0x131, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_0071146C - gnGlobal_007A2858 - 0x122, gnGlobal_00711470 + gnGlobal_007A285C - 0x62, 0, 1);
    }
}

// 0x004AB7E0
void __stdcall sub_004AB7E0_SkillTreeLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    int nMouseY = pMsg->nYpos;
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
        return;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    const int nClassId = pPlayer->dwClassId;
    if (nMouseY > gnGlobal_00711470 - 0x30)
        return;

    if (!gnGlobal_007C0C4C)
    {
        sub_0044DA70();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    if (nMouseX > gnGlobal_0071146C - gnGlobal_007A2858 - 0x140 && nMouseX < gnGlobal_0071146C - gnGlobal_007A2858 - 0x58)
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0) <= 0)
        {
            for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
            {
                const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
                D2SkillsTxt* pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (!pSkillsTxt)
                    continue;

                D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
                if (!pDesc)
                    continue;

                if (gnGlobal_00724BEC == pDesc->nSkillPage)
                {
                    const int nY = sub_004AA9C0_GetSkillRowY(pDesc->nSkillRow);
                    if (nMouseY > nY - 0x30 && nMouseY < nY)
                    {
                        const int nX = sub_004AAA50_GetSkillColumnX(pDesc->nSkillColumn);
                        if (nMouseX > nX && nMouseX < nX + 0x30 && !ganSkillState_007C0A38[i] && !BITARRAY_CHECK(pSkillsTxt->nFlags, 4))
                        {
                            sub_004786A0_SendDwords2(0x3C, pSkillsTxt->nSkillId, -1);
                            sub_00455F20(4, 1, 0);
                            continue;
                        }
                    }
                }

                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
            }

            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
        }
    }

    if (nMouseX >= gnGlobal_0071146C - gnGlobal_007A2858 - 0x58)
    {
        if (nMouseX <= gnGlobal_0071146C - gnGlobal_007A2858)
        {
            const int nOldPage = gnGlobal_00724BEC;
            if (nMouseY > gnGlobal_00711470 + gnGlobal_007A285C - 0x174 && nMouseY < gnGlobal_00711470 + gnGlobal_007A285C - 0x109)
                gnGlobal_00724BEC = 3;
            if (nMouseY > gnGlobal_00711470 + gnGlobal_007A285C - 0x108 && nMouseY < gnGlobal_00711470 + gnGlobal_007A285C - 0x9D)
                gnGlobal_00724BEC = 2;
            if (nMouseY > gnGlobal_00711470 + gnGlobal_007A285C - 0x9C && nMouseY < gnGlobal_00711470 - 0x31)
                gnGlobal_00724BEC = 1;
            if (gnGlobal_00724BEC != nOldPage)
                sub_004B9A00(6, 0, 0, 0, 0);
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }

    if (gnTabSelection_00724CE0 == 1)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0x95, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
        {
            sub_004B9A00(4, 0, 0, 0, 0);
            gbGlobal_007C0C38 = 1;
        }
    }
    else if (gnTabSelection_00724CE0 == 2)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0xDC, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
        {
            sub_004B9A00(4, 0, 0, 0, 0);
            gbGlobal_007C0C38 = 1;
        }
    }
    else if (gnTabSelection_00724CE0 == 3)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0x131, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
        {
            sub_004B9A00(4, 0, 0, 0, 0);
            gbGlobal_007C0C38 = 1;
        }
    }

    if (nMouseX > gnGlobal_0071146C - gnGlobal_007A2858 - 0x140 && nMouseX < gnGlobal_0071146C - gnGlobal_007A2858 - 0x58)
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0) > 0)
        {
            for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
            {
                const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
                if (!sub_0045C4B0_GetSkillsTxtRecord(nSkillId))
                    continue;

                D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
                if (!pDesc)
                    continue;

                if (gnGlobal_00724BEC != pDesc->nSkillPage)
                    continue;

                const int nY = sub_004AA9C0_GetSkillRowY(pDesc->nSkillRow);
                if (nMouseY <= nY - 0x30 || nMouseY >= nY)
                    continue;

                const int nX = sub_004AAA50_GetSkillColumnX(pDesc->nSkillColumn);
                if (nMouseX <= nX || nMouseX >= nX + 0x30 || ganSkillState_007C0A38[i])
                    continue;

                ganSkillState_007C0A38[i] = 1;
                ganSkillMode_007C0838[i] = 3;
                sub_00467F20_MsgHandler(pMsg);
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_004B9A00(5, 0, 0, 0, 0);
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }

            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 0;
}

// 0x004ABC30
void __stdcall sub_004ABC30_SkillTreeLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;

    const int nClassId = pPlayer->dwClassId;
    sub_00467FA0_MsgHandler(pMsg);
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
        return;

    if (!gnGlobal_007C0C4C)
    {
        sub_0044DA70();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    if (gbGlobal_007C0C38)
    {
        gbGlobal_007C0C38 = 0;
        if (gnTabSelection_00724CE0 == 1)
        {
            if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0x95, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
                sub_00455F20(4, 2, 0);
        }
        else if (gnTabSelection_00724CE0 == 2)
        {
            if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0xDC, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
                sub_00455F20(4, 2, 0);
        }
        else if (gnTabSelection_00724CE0 == 3)
        {
            if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0x131, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
                sub_00455F20(4, 2, 0);
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    if (nMouseX > gnGlobal_0071146C / 2)
    {
        const int nNewSkills = STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0);
        if (nNewSkills > 0)
        {
            for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
            {
                const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
                D2SkillsTxt* pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                if (!pSkillsTxt)
                    continue;

                D2SkillDescTxt* pDesc = sub_004A89D0_SkillDescRec(nSkillId);
                if (!pDesc)
                    continue;

                if (gnGlobal_00724BEC == pDesc->nSkillPage)
                {
                    const int nY = sub_004AA9C0_GetSkillRowY(pDesc->nSkillRow);
                    if (nMouseY > nY - 0x30 && nMouseY < nY)
                    {
                        const int nX = sub_004AAA50_GetSkillColumnX(pDesc->nSkillColumn);
                        if (nMouseX > nX && nMouseX < nX + 0x30 && ganSkillState_007C0A38[i] == 1)
                        {
                            if (pSkillsTxt->dwSkPoints != -1)
                            {
                                int nLevel = 0;
                                D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, nSkillId, -1);
                                if (pSkill)
                                    nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);

                                if (SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxt->dwSkPoints, nSkillId, nLevel) > nNewSkills)
                                    goto LDone;
                            }

                            {
                                int nLevel = 0;
                                D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, nSkillId, -1);
                                if (pSkill)
                                    nLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 0);

                                if (nLevel <= sub_004AA8B0_GetSkillMaxLevel(pSkillsTxt->nSkillId) && !sub_004AA900_IsStateOrValue())
                                {
                                    sub_004785B0_SendPacket3(0x3B, nSkillId);
                                    gnValue_007C0C3C = 0;
                                }
                            }

LDone:
                            ganSkillState_007C0A38[i] = 0;
                            ganSkillMode_007C0838[i] = 0;
                            pMsg->bReturn = 1;
                            pMsg->lResult = 0;
                            sub_00420290_BreakHandlerChain(pMsg);
                            return;
                        }
                    }
                }

                if (ganSkillState_007C0A38[i] != -1)
                {
                    ganSkillState_007C0A38[i] = 0;
                    ganSkillMode_007C0838[i] = 0;
                }
            }
        }

        sub_0044DA70();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 0;
}

void __stdcall sub_004ABF60_DrawSkillIcon(int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nState, int nMode); // 0x004ABF60

#include "gen/data/Source/D2Client/Unknown_004AA9C0.inc"
