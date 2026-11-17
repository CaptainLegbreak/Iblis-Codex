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

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    int wParam;
    unsigned short nXpos;
    unsigned short nYpos;
    unsigned int nNotifyCode;
    void* pExtra;
    int bUseResult;
    int lResult;
};

struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);

extern D2DataTablesStrc* sgptDataTables;
extern unsigned int gdwBitMasks[];
extern "C" const char gszFormatD_006D57BC[];
extern int gnGlobal_0071146C;
extern int gnGlobal_00711470;
extern int gnGlobal_007A2858;
extern int gnGlobal_007A285C;
extern int gnGlobal_00724BEC;
extern int gnTabSelection_00724CE0;
extern int gbGlobal_007C0C38;
extern "C" int gnValue_007C0C3C;
extern int gnGlobal_007C0C44;
extern int gnGlobal_007C0C4C;
extern int ganSkillMode_007C0838[];
extern int ganSkillState_007C0A38[];

int __cdecl sub_00468730();
int __cdecl sub_00468740();
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg);
void __cdecl sub_0044DA70();
int __fastcall sub_00451F60_UnitClassId(D2UnitStrc* pUnit);
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);
D2UnitStrc* __cdecl sub_00463DD0();
void __stdcall sub_00467F20_MsgHandler(SMSGHANDLER_PARAMS* pMsg);
void __stdcall sub_00467FA0_MsgHandler(SMSGHANDLER_PARAMS* pMsg);
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);
void __fastcall sub_004786A0_SendIntInt(char nHeader, int nArg1, int nArg2);
int __fastcall sub_00498DC0_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor);
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);
void* __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt);
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId);
int __cdecl sub_004AA900_IsStateOrValue();
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);
void __fastcall sub_004EEF00_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY);
void __fastcall sub_004EF410_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY);
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift);
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);
int __fastcall sub_00502EF0(int nArg);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId);
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel);

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

// build: context sub_004AAA50_GetSkillColumnX
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

// 0x0045FB80
static int __stdcall sub_004AB5F0_IsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + nWidth && nMouseY >= nY - nHeight && nMouseY <= nY)
        return 1;
    return 0;
}

void __cdecl sub_004AB630_DrawTabHint()
{
    if (gnTabSelection_00724CE0 == 1)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0x95, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
            sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_0071146C - gnGlobal_007A2858 - 0x86, gnGlobal_00711470 + gnGlobal_007A285C - 0x62, 0, 1);
    }
    else if (gnTabSelection_00724CE0 == 2)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0xDC, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
            sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_0071146C - gnGlobal_007A2858 - 0xCD, gnGlobal_00711470 + gnGlobal_007A285C - 0x62, 0, 1);
    }
    else if (gnTabSelection_00724CE0 == 3)
    {
        if (sub_004AB5F0_IsMouseInRect(gnGlobal_0071146C - gnGlobal_007A2858 - 0x131, gnGlobal_00711470 + gnGlobal_007A285C - 0x3F, 0x22, 0x22))
            sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_0071146C - gnGlobal_007A2858 - 0x122, gnGlobal_00711470 + gnGlobal_007A285C - 0x62, 0, 1);
    }
}

void __stdcall sub_004AB7E0_SkillTreeLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    int nMouseY = pMsg->nYpos;
    if (sub_00498DC0_MouseMoveMsg(pMsg))
        return;

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;

    const int nClassId = pPlayer->dwClassId;
    if (nMouseY > gnGlobal_00711470 - 0x30)
        return;

    if (!gnGlobal_007C0C4C)
    {
        sub_0044DA70();
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    if (nMouseX > gnGlobal_0071146C - gnGlobal_007A2858 - 0x140 && nMouseX < gnGlobal_0071146C - gnGlobal_007A2858 - 0x58)
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, 5, 0) <= 0)
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
                            sub_004786A0_SendIntInt(0x3C, pSkillsTxt->nSkillId, -1);
                            sub_00455F20(4, 1, 0);
                            continue;
                        }
                    }
                }

                pMsg->bUseResult = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
            }

            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
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

        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
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
        if (STATLIST_GetUnitBaseStat(pPlayer, 5, 0) > 0)
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
                pMsg->bUseResult = 1;
                pMsg->lResult = 0;
                sub_004B9A00(5, 0, 0, 0, 0);
                sub_00420290_HandleMsg(pMsg);
                return;
            }

            pMsg->bUseResult = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
            return;
        }

        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    pMsg->bUseResult = 0;
}

void __stdcall sub_004ABC30_SkillTreeLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer)
        return;

    const int nClassId = pPlayer->dwClassId;
    sub_00467FA0_MsgHandler(pMsg);
    if (sub_00498DC0_MouseMoveMsg(pMsg))
        return;

    if (!gnGlobal_007C0C4C)
    {
LNotHandled:
        sub_0044DA70();
        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
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

        pMsg->bUseResult = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        return;
    }

    if (nMouseX > gnGlobal_0071146C / 2)
    {
        const int nNewSkills = STATLIST_GetUnitBaseStat(pPlayer, 5, 0);
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
                            pMsg->bUseResult = 1;
                            pMsg->lResult = 0;
                            sub_00420290_HandleMsg(pMsg);
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

        goto LNotHandled;
    }

    pMsg->bUseResult = 0;
}

void __stdcall sub_004ABF60_DrawSkillIcon(int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nState, int nMode)
{
    D2SkillDescTxt* pDesc;
    int nFrame;
    int nY;
    int nX;
    int nMouseX;
    int nMouseY;
    void* pCellFile;

    pDesc = SKILLTREE_GetSkillDescRec(nSkillId);
    if (!pDesc)
        return;

    nY = sub_004AA9C0_GetSkillRowY(pDesc->nSkillRow);
    nX = sub_004AAA50_GetSkillColumnX(pDesc->nSkillColumn);
    nMouseX = sub_00468730();
    nMouseY = sub_00468740();
    pCellFile = sub_004A8C80_GetSkillValue(0);
    nFrame = pDesc->nIconCel;
    if (nState == 1)
        ++nFrame;

    if (nMouseX > nX && nMouseX < nX + 0x30 && nMouseY > nY - 0x30 && nMouseY < nY)
        nMode = 3;

    if (!BITARRAY_CHECK(pSkillsTxt->nFlags, 10))
        nMode = 1;

    D2UnitStrc* pPlayer = sub_00463DD0();
    const int nBaseLevel = SKILLS_GetSkillLevel(pPlayer, SKILLS_GetSkillById(pPlayer, nSkillId, -1), 0);
    if (!nBaseLevel && SKILLS_GetBonusSkillLevelFromSkillId(pPlayer, nSkillId) && nState != -1)
        nMode = 3;

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = pCellFile;
    tCel.unk0x40 = 0;
    tCel.nFrame = nFrame;
    TEXTURE_CelDrawColor(&tCel, nX, nY, -1, 5, nMode);

    if (nMouseX > nX && nMouseX < nX + 0x30 && nMouseY > nY - 0x30 && nMouseY < nY)
    {
        if (nState != -1)
            sub_004EEF00_ShowSkillPopup(sub_00463DD0(), nSkillId, nSkillLevel, 0, nX, nY);
        else
            sub_004EF410_ShowSkillPopupB(sub_00463DD0(), nSkillId, nSkillLevel, 0, nX, nY);
    }

    if (nBaseLevel || nSkillLevel)
    {
        Unicode wszLevel[10];
        char szLevel[12];
        wsprintfA(szLevel, gszFormatD_006D57BC, nSkillLevel);
        sub_00526320_ToUnicode(wszLevel, szLevel, 9);
        if (nSkillLevel > 9)
        {
            sub_00502EF0(4);
            nX -= 4;
        }
        else
        {
            sub_00502EF0(1);
        }

        const int nBonusLevel = SKILLS_GetBonusSkillLevelFromSkillId(sub_00463DD0(), nSkillId);
        int nColor = 0;
        if (nBonusLevel > 0)
            nColor = 3;
        else if (nBonusLevel < 0)
            nColor = 1;

        sub_00502320(wszLevel, nX + 0x30, nY + 0xC, nColor, 0);
    }
}
