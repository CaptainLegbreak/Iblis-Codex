#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2Records.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

#define TEXT(y, id) sub_004AAAA0_DrawSkillTreeText(D2LANG_GetStringFromTblIndex(id), y)
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

struct Unicode;
struct D2SkillsTxt;
struct D2SkillDescTxt;

extern int gaChargedSkillIds[60]; // 0x007C04E0
extern int gaHotkeySkills[16]; // 0x007C06C8
extern int gaHotkeyLeft[16]; // 0x007C07B8
extern int gaHotkeyOwners[16]; // 0x007C0768
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
unsigned short __fastcall sub_004E6CE0_GetStringId(int nId, int nIndex); // 0x004E6CE0
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern unsigned char gnCharClass; // 0x007A0522
extern int gnScreenWidth; // 0x0071146C
extern unsigned char gbColor; // 0x007C0C50
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern "C" const char gszFormatD[]; // 0x006D57BC
extern int gnSkillPage; // 0x00724BEC
extern int gnTabSelection; // 0x00724CE0
extern int gbSkillTabPressed; // 0x007C0C38
extern "C" int gbSkillPointsHighlight; // 0x007C0C3C
extern int gbInSkillPanelDraw; // 0x007C0C44
extern int gbSkillPanelDrawn; // 0x007C0C4C
extern int gaSkillButtonFrame[]; // 0x007C0838
extern int gaSkillButtonState[]; // 0x007C0A38
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __stdcall ROSTERPETS_HandleButtonDown(SMSGHANDLER_PARAMS* pMsg); // 0x00467F20
void __stdcall ROSTERPETS_HandleButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0
void* __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt); // 0x004A8C80
int __fastcall sub_004AA8B0_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __cdecl sub_004AA900_IsStateOrValue(); // 0x004AA900
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall SKILLDESC_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY); // 0x004EEF00
void __fastcall SKILLDESC_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY); // 0x004EF410
void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_GetBonusSkillLevelFromSkillId(D2UnitStrc* pUnit, int nSkillId); // 0x00644300
int __stdcall sub_00639DF0_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition); // 0x006460F0
int __stdcall SKILLS_GetPlayerSkillCount(int nClassId); // 0x00646140
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
static int sub_004AA9C0_GetSkillRowY(unsigned char nRow); // 0x004AA9C0
void __stdcall sub_004ABF60_DrawSkillIcon(int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nState, int nMode);

static void __stdcall sub_004AAAA0_DrawSkillTreeText(const Unicode* wszText, int nY);


static inline int IsMouseInSquare(int nX, int nY)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    return nMouseX >= nX && nMouseX <= nX + 0x30 && nMouseY >= nY - 0x30 && nMouseY <= nY;
}

// 0x004AA1F0
void __fastcall sub_004AA1F0_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY)
{
    if (IsMouseInSquare(nX, nY))
    {
        if (nState != 1)
        {
            nState = 0;
        }
    }
    else
    {
        nState = 1;
    }

    if (!IsMouseInSquare(nX, nY))
    {
        return;
    }

    const Unicode* wszNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    Unicode wszText[0x100];
    const unsigned short nNameId = sub_004E6CE0_GetStringId(*pId, 0);
    const int nTextId = sub_004E6CE0_GetStringId(*pId, 1);
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nTextId));
    sub_00526700(wszText, wszNewline);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x105C));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    Unicode wszNumber[10];
    char szNumber[12];
// build: symbol ?gszFormatI@* 0x006D6454
    wsprintfA(szNumber, gszFormatI, nQuantity);
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszNewline);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nNameId));
    D2Win_10129_DrawFramedText(wszText, nX, nY - 0x32, nState, 1);
}

int gnAutomapWidth; // 0x007A5220

// 0x004AAAA0
static void __stdcall sub_004AAAA0_DrawSkillTreeText(const Unicode* wszText, int nY)
{
    const int nTextY = gnScreenHeight + gnPanelOffsetY + nY - 0x1E0;
    TEXT_DrawCenteredText(gnAutomapWidth - gnPanelOffsetX - 0x5A, nTextY, gnAutomapWidth - gnPanelOffsetX, wszText, 0);
}

// 0x004AACE0
void __cdecl sub_004AACE0_DrawSkillTreeTexts()
{
    TEXT(0x19, 0x1083);
    TEXT(0x25, 0x1084);
    TEXT(0x31, 0x1085);

    if (gnCharClass == 0)
    {
        TEXT(0x96, 0x1088);
        TEXT(0xA2, 0x1089);
        TEXT(0xAE, 0x1086);
        TEXT(0x102, 0x108A);
        TEXT(0x10E, 0x108B);
        TEXT(0x11A, 0x1086);
        TEXT(0x167, 0x108C);
        TEXT(0x173, 0x108D);
        TEXT(0x17F, 0x1086);
    }
    else if (gnCharClass == 3)
    {
        TEXT(0x9C, 0x108E);
        TEXT(0xA8, 0x108F);
        TEXT(0x108, 0x1090);
        TEXT(0x114, 0x108F);
        TEXT(0x172, 0x1091);
        TEXT(0x17E, 0x1086);
    }
    else if (gnCharClass == 2)
    {
        TEXT(0x9C, 0x1092);
        TEXT(0xA8, 0x1087);
        TEXT(0x102, 0x1093);
        TEXT(0x10E, 0x1094);
        TEXT(0x11A, 0x1087);
        TEXT(0x178, 0x1095);
    }
    else if (gnCharClass == 4)
    {
        TEXT(0xA2, 0x1096);
        TEXT(0x108, 0x1097);
        TEXT(0x114, 0x1098);
        TEXT(0x172, 0x1097);
        TEXT(0x17E, 0x1086);
    }
    else if (gnCharClass == 1)
    {
        TEXT(0x9C, 0x1099);
        TEXT(0xA8, 0x1087);
        TEXT(0x108, 0x109A);
        TEXT(0x114, 0x1087);
        TEXT(0x172, 0x109B);
        TEXT(0x17E, 0x1087);
    }
    else if (gnCharClass == 6)
    {
        TEXT(0x96, 0x57F4);
        TEXT(0xA2, 0x57F5);
        TEXT(0x108, 0x57F2);
        TEXT(0x114, 0x57F3);
        TEXT(0x172, 0x57F1);
    }
    else if (gnCharClass == 5)
    {
        TEXT(0xA2, 0x57F0);
        TEXT(0x108, 0x57EE);
        TEXT(0x114, 0x57EF);
        TEXT(0x172, 0x57ED);
    }
}

// 0x004AB310
void __stdcall sub_004AB310_DrawTabHoverText(int nMode)
{
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    int bHover = 0;
    int bShow1082 = 0;
    int bShow1081 = 0;
    int bShow1080 = 0;
    int nBoxY = 0;

LOOP:
    gbColor = D2Win_10034_MixRGB(0, 0, 0);
    if (nX >= gnScreenWidth - gnPanelOffsetX - 0x59 && nX <= gnScreenWidth - gnPanelOffsetX + 1)
    {
        if (nMode == 1)
        {
            if (nY <= gnScreenHeight + gnPanelOffsetY - 0x9C && nY >= gnScreenHeight + gnPanelOffsetY - 0x108)
            {
                bShow1081 = 1;
                if (nMode != 1) goto LOOP;
                goto Box1081;
            }
            else if (nY <= gnScreenHeight + gnPanelOffsetY - 0x108 && nY >= gnScreenHeight + gnPanelOffsetY - 0x174)
            {
            Show1080:
                bShow1080 = 1;
                nBoxY = gnScreenHeight + gnPanelOffsetY - 0x174;
                bHover = 1;
                goto Done;
            }
            if (nMode != 1) goto LOOP;
            goto Done;
        }
        else if (nMode == 2)
        {
            if (nY <= gnScreenHeight + gnPanelOffsetY - 0x108 && nY >= gnScreenHeight + gnPanelOffsetY - 0x174)
            {
                goto Show1080;
            }
            else if (nY <= gnScreenHeight + gnPanelOffsetY - 0x30 && nY >= gnScreenHeight + gnPanelOffsetY - 0x9C)
            {
                bShow1082 = 1;
                if (nMode != 2) goto LOOP;
                goto Box1082;
            }
        }
        else if (nMode == 3)
        {
            if (nY <= gnScreenHeight + gnPanelOffsetY - 0x9C && nY >= gnScreenHeight + gnPanelOffsetY - 0x108)
            {
                bShow1081 = 1;
            Box1081:
                nBoxY = gnScreenHeight + gnPanelOffsetY - 0x108;
                bHover = 1;
                goto Done;
            }
            else if (nY <= gnScreenHeight + gnPanelOffsetY - 0x30 && nY >= gnScreenHeight + gnPanelOffsetY - 0x9C)
            {
                bShow1082 = 1;
            Box1082:
                nBoxY = gnScreenHeight + gnPanelOffsetY - 0x9C;
                bHover = 1;
                goto Done;
            }
        }
    }
Done:
    D2Win_10127_SetFont(1);
    if (!bHover)
    {
        return;
    }

    AUTOMAP_DrawFramedBox(gnScreenWidth - gnPanelOffsetX - 0x59, nBoxY + 5, 0x5A, 0x14, gbColor, 6);
    if (bShow1082)
    {
        TEXT_DrawCenteredText(gnScreenWidth - gnPanelOffsetX - 0x59, nBoxY + 0x14, 0x5A, D2LANG_GetStringFromTblIndex(0x1082), 0);
    }
    if (bShow1081)
    {
        TEXT_DrawCenteredText(gnScreenWidth - gnPanelOffsetX - 0x59, nBoxY + 0x14, 0x5A, D2LANG_GetStringFromTblIndex(0x1081), 0);
    }
    if (bShow1080)
    {
        TEXT_DrawCenteredText(gnScreenWidth - gnPanelOffsetX - 0x59, nBoxY + 0x14, 0x5A, D2LANG_GetStringFromTblIndex(0x1080), 0);
    }
}

// build: context SKILLTREE_GetSkillsTxtRecord
static inline D2SkillsTxt* SKILLTREE_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// build: context SKILLTREE_GetSkillDescTxtRecord
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
        return gnScreenHeight + gnPanelOffsetY - 0x1A2;
    if (nRow == 2)
        return gnScreenHeight + gnPanelOffsetY - 0x15E;
    if (nRow == 3)
        return gnScreenHeight + gnPanelOffsetY - 0x11A;
    if (nRow == 4)
        return gnScreenHeight + gnPanelOffsetY - 0xD6;
    if (nRow == 5)
        return gnScreenHeight + gnPanelOffsetY - 0x91;
    if (nRow == 6)
        return gnScreenHeight + gnPanelOffsetY - 0x4D;
    return 0;
}

// 0x004AAA50
static int sub_004AAA50_GetSkillColumnX(unsigned char nColumn)
{
    if (nColumn == 1)
        return gnScreenWidth - gnPanelOffsetX - 0x131;
    if (nColumn == 2)
        return gnScreenWidth - gnPanelOffsetX - 0xEC;
    if (nColumn == 3)
        return gnScreenWidth - gnPanelOffsetX - 0xA7;
    return 0;
}

// 0x004ABF60
static void __stdcall sub_004ABF60_DrawSkillIcon(int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nState, int nMode)
{
    D2SkillDescTxt* pDesc;
    int nY;
    int nFrame;
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

    if (!(gdwBitMasks[10 & 7] & pSkillsTxt->nFlags[10 >> 3]))
        nMode = 1;

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nBaseLevel = SKILLS_GetSkillLevel(pPlayer, SKILLS_GetSkillById(pPlayer, nSkillId, -1), 0);
    const int nBonus = SKILLS_GetBonusSkillLevelFromSkillId(pPlayer, nSkillId);
    if (!nBaseLevel && nBonus && nState != -1)
        nMode = 3;

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = pCellFile;
    tCel.nDirection = 0;
    tCel.nFrame = nFrame;
    TEXTURE_CelDrawColor(&tCel, nX, nY, -1, 5, nMode);

    if (nMouseX > nX && nMouseX < nX + 0x30 && nMouseY > nY - 0x30 && nMouseY < nY)
    {
        if (nState != -1)
            SKILLDESC_ShowSkillPopup(sub_00463DD0_GetPlayerUnit(), nSkillId, nSkillLevel, 0, nX, nY);
        else
            SKILLDESC_ShowSkillPopupB(sub_00463DD0_GetPlayerUnit(), nSkillId, nSkillLevel, 0, nX, nY);
    }

    if (nBaseLevel || nSkillLevel)
    {
        unsigned int adwText[5];
        unsigned short* const pwText = (unsigned short*)adwText;
        pwText[0] = 0;
        pwText[1] = 0;
        pwText[2] = 0;
        pwText[3] = 0;
        pwText[4] = 0;
        pwText[5] = 0;
        pwText[6] = 0;
        pwText[7] = 0;
        pwText[8] = 0;
        pwText[9] = 0;
        unsigned int adwLevel[3];
        wsprintfA((char*)adwLevel, gszFormatD, nSkillLevel);
        sub_00526320_ToUnicode((Unicode*)adwText, (const char*)adwLevel, 9);
        if (nSkillLevel > 9)
        {
            D2Win_10127_SetFont(4);
            nX -= 4;
        }
        else
        {
            D2Win_10127_SetFont(1);
        }

        int nColor = 0;
        D2UnitStrc* const pPlayerUnit = sub_00463DD0_GetPlayerUnit();
        const int nBonusLevel = SKILLS_GetBonusSkillLevelFromSkillId(pPlayerUnit, nSkillId);
        if (nBonusLevel > 0)
            nColor = 3;
        else if (nBonusLevel < 0)
            nColor = 1;

        D2Win_10117_DrawText((const Unicode*)adwText, nX + 0x30, nY + 0xC, nColor, 0);
    }
}

D2SkillDescTxt* sub_004AC200_GetSkillDescFromSkillId(int nSkillId); // 0x004AC200

// build: context sub_004AC200_RefreshSkillTree
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
    wsprintfA(szText, "%i", STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0));
    sub_00526320_ToUnicode((Unicode*)wszText, szText, 9);

    D2UnitStrc* pUnit = sub_00463DD0_GetPlayerUnit();
    if ((pUnit && sub_00639DF0_CheckState(pUnit, 0x36)) || gbSkillPointsHighlight)
    {
        D2Win_10117_DrawText((const Unicode*)wszText, gnScreenWidth - gnPanelOffsetX - 0x34, gnScreenHeight + gnPanelOffsetY - 0x190, 1, 0);
    }
    else
    {
        D2Win_10117_DrawText((const Unicode*)wszText, gnScreenWidth - gnPanelOffsetX - 0x34, gnPanelOffsetY + gnScreenHeight - 0x190, 0, 0);
    }

    int bCanLearn;
    int nLevel;
    const int nPoints = STATLIST_GetUnitBaseStat(pPlayer, STAT_SKILLPTS, 0);
    for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClass); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClass, i);
        D2SkillsTxt* pSkillsTxtRecord = SKILLTREE_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        D2SkillDescTxt* pSkillDescTxtRecord = sub_004AC200_GetSkillDescFromSkillId(nSkillId);
        if (!pSkillDescTxtRecord || gnSkillPage != pSkillDescTxtRecord->nSkillPage)
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
            if ((int)pSkillsTxtRecord->dwSkPoints != -1)
            {
                nRequired = SKILLS_EvaluateSkillFormula(pPlayer, pSkillsTxtRecord->dwSkPoints, nSkillId, nLevel);
            }

            if (nPoints >= nRequired && bCanLearn)
            {
                if (gaSkillButtonState[i] != 1)
                {
                    gaSkillButtonState[i] = 0;
                    gaSkillButtonFrame[i] = 0;
                }
            }
            else
            {
                gaSkillButtonState[i] = -1;
                gaSkillButtonFrame[i] = 5;
            }

            int nBaseLevel = 0;
            if (pSkill)
            {
                nBaseLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
            }
            sub_004ABF60_DrawSkillIcon(nSkillId, pSkillsTxtRecord, nBaseLevel, gaSkillButtonState[i], gaSkillButtonFrame[i]);
        }
        else
        {
            gaSkillButtonState[i] = -1;
            gaSkillButtonFrame[i] = 5;
            int nBaseLevel;
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, pSkillsTxtRecord->nSkillId, -1);
            if (pSkill && (nBaseLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1)))
            {
                sub_004ABF60_DrawSkillIcon(nSkillId, pSkillsTxtRecord, nBaseLevel, gaSkillButtonState[i], gaSkillButtonFrame[i]);
            }
            else
            {
                sub_004ABF60_DrawSkillIcon(nSkillId, pSkillsTxtRecord, 0, gaSkillButtonState[i], gaSkillButtonFrame[i]);
            }
        }
    }
}

void __cdecl sub_004AC4D0_DrawSkillTree(); // 0x004AC4D0
