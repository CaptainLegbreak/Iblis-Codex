#include "D2Client.h"
#include "D2Primitives.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2ClientQuestLog.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#pragma pack(push, 1)
struct D2QuestTextMsgStrc
{
    unsigned char unk0x000[1];
    int nQuestId;
    unsigned short wTitle;
    unsigned short wszText[300];
    unsigned short wDesc;
    unsigned char nCelId;
    unsigned char nCelId2;
    unsigned char f_263;
    unsigned char bValid;
    unsigned char nStep;
    int nState;
};
#pragma pack(pop)


extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags();                                                           // 0x004B32D0
int __stdcall INV_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0
const unsigned short* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                       // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
unsigned short* __fastcall sub_00526700(unsigned short* pDest, const Unicode* pSource);                   // 0x00526700
unsigned short* __fastcall sub_00526790(unsigned short* pDest, const unsigned short* pSource, int nCount); // 0x00526790
unsigned short* __fastcall sub_005267E0(unsigned short* pDest, const unsigned short* pSource);            // 0x005267E0
int __fastcall sub_00526800(const unsigned short* pString);                                               // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, unsigned short* pBuffer, const unsigned short* pFormat, ...);  // 0x005269D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

extern const char gszFormatD[];                                                                    // 0x006D57BC
extern D2QuestTextsStrc gtQuestTextsSevenTombs;                                                              // 0x00723A64
extern D2QuestTextsStrc gtQuestTextsFallenAngel;                                                              // 0x00723C64
extern D2QuestTextsStrc gtQuestTextsSiege;                                                              // 0x00723D24
extern D2QuestPageRangeStrc gaQuestPageRanges[];                                                   // 0x00723F08
extern D2QuestTableStrc gaQuestTable[];                                                            // 0x00723F30
extern int gaQuestPageDefault[5];                                                                    // 0x007BF280
extern int gnQuestAct;                                                                               // 0x007BF2A4
extern int gnQuestParam;                                                                               // 0x007BF2AC
extern void* gapQuestIconCels[];                                                                        // 0x007BF2E1
extern unsigned char gabQuestFlagsA[];                                                             // 0x007BF356
extern unsigned char gabQuestFlagsB[];                                                             // 0x007BF380

static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg)
{
    pMsg->wTitle = 0xE8C;
    pMsg->wDesc = 0xE8C;
    pMsg->wszText[0] = 0;
    pMsg->f_263 = 0;
    pMsg->bValid = 0;

    int nIndex = -1;
    for (int i = 0; i < 41; ++i)
    {
        if (gaQuestTable[i].nQuestId == pMsg->nQuestId)
        {
            nIndex = i;
            break;
        }
    }

    if (nIndex == -1)
    {
        pMsg->nState = 2;
        return;
    }

    pMsg->nCelId = gaQuestTable[nIndex].nCelId2;
    pMsg->nCelId2 = gaQuestTable[nIndex].nCelId;
    D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
    D2BitBufferStrc* pQuestHistory = sub_004B32E0_GetQuestHistory();
    unsigned char nStep = gabQuestFlagsA[nIndex];
    pMsg->nStep = nStep;
    if (!gaQuestTable[nIndex].pTexts)
    {
        pMsg->nState = 2;
        return;
    }

    const int bState0 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0);
    const int bState13 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xD);
    const int bState1 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 1);
    D2QuestTextsStrc* pTexts = gaQuestTable[nIndex].pTexts;

    if (pTexts == &gtQuestTextsSiege && bState1)
    {
        if (!nStep)
        {
            nStep = 4;
        }
    }
    else if (pTexts == &gtQuestTextsSevenTombs && !bState0 && !bState13
        && (QUESTRECORD_GetQuestState(pQuestInfo, 0xC, 0) || QUESTRECORD_GetQuestState(pQuestInfo, 0xC, 0xD)) && nStep == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[7 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 7;
        gabQuestFlagsB[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[7 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (pTexts == &gtQuestTextsSevenTombs && !bState0 && !bState13 && QUESTRECORD_GetQuestState(pQuestInfo, 0xE, 3) == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[5 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 5;
        gabQuestFlagsB[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[5 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (pTexts == &gtQuestTextsSevenTombs && !bState0 && !bState13 && QUESTRECORD_GetQuestState(pQuestInfo, 0xE, 4) == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[6 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 6;
        gabQuestFlagsB[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[6 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (bState13 && !bState0 && pTexts->awIds[2] != 0xFFFF && bState1 && pTexts != &gtQuestTextsFallenAngel)
    {
        nStep = (unsigned char)pTexts->awIds[2] + 1;
        pMsg->wTitle = pTexts->awIds[0];
        const unsigned short* pIds = &pTexts->awIds[nStep * 2];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pIds[1]), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->f_263 = nStep != gabQuestFlagsB[nIndex];
        const unsigned short wDesc = pIds[2];
        gabQuestFlagsB[nIndex] = nStep;
        pMsg->nStep = nStep;
        pMsg->wDesc = wDesc;
        pMsg->nState = 3;
        pMsg->bValid = 1;
        return;
    }
    else if (bState0)
    {
        unsigned short nString;
        if (bState13)
        {
            nString = 0xE8E;
            nStep = 0xD;
        }
        else
        {
            nString = 0xE90;
            nStep = 0xB;
        }

        pMsg->nStep = nStep;
        if (!pTexts)
        {
            pMsg->nState = 2;
            return;
        }

        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->wDesc = pTexts->awIds[1];
        gabQuestFlagsB[nIndex] = nStep;
        pMsg->bValid = 1;
        pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xC) != 0;
        return;
    }
    else if (bState1 && QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xF))
    {
        unsigned char nNewStep = 0xA;
        if (pMsg->nQuestId == 0x25)
        {
            if (QUESTRECORD_GetQuestState(pQuestInfo, 0x25, 8) && !QUESTRECORD_GetQuestState(pQuestInfo, 0x25, 9))
            {
                nNewStep = 6;
            }
            else if (!QUESTRECORD_GetQuestState(pQuestInfo, 0x25, 8))
            {
                nNewStep = 5;
            }
        }

        if (pMsg->nQuestId == 0x26)
        {
            nNewStep = (QUESTRECORD_GetQuestState(pQuestInfo, 0x26, 4) != 0) + 4;
        }

        pMsg->nStep = nNewStep;
        if (!pTexts || pTexts->awIds[nNewStep * 2 + 1] == 0xE8D)
        {
            pMsg->nState = 2;
            return;
        }

        const unsigned short* pIds = &pTexts->awIds[nNewStep * 2];
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pIds[1]), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->wDesc = pIds[2];
        gabQuestFlagsB[nIndex] = nNewStep;
        pMsg->bValid = 1;
        pMsg->nState = (pMsg->nQuestId != 0x1B) ? 3 : 1;
        return;
    }

    if (nStep)
    {
        if (!gaQuestTable[nIndex].pTexts)
        {
            pMsg->nState = 2;
            return;
        }

        if (pTexts->awIds[0] == 0xE82)
        {
            const int nStepIndex = nStep;
            const unsigned short* pString = D2LANG_GetStringFromTblIndex(pTexts->awIds[nStepIndex * 2 + 1]);
            switch (nStepIndex - 1)
            {
            case 3 - 1:
            case 4 - 1:
                if (pTexts->awIds[0] == 0xE82 && gnQuestAct > 1)
                {
                    Unicode wszNumber[10];
                    char szNumber[10];
                    sprintf(szNumber, gszFormatD, pTexts->awIds[0] == 0xE82 ? gnQuestAct : 0);
                    sub_00526320_ToUnicode(wszNumber, szNumber, 9);
                    sub_005267E0(pMsg->wszText, pString);
                    D2_ASSERT(sub_00526800(pString) < 0x118, 0x4FA);
                    sub_00526700(pMsg->wszText, wszNumber);
                }
                else
                {
                    sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(0xE9B), 300);
                    pMsg->wszText[300 - 1] = 0;
                }
                break;

            default:
                sub_00526790(pMsg->wszText, pString, 300);
                pMsg->wszText[300 - 1] = 0;
                break;
            }

            pMsg->wTitle = pTexts->awIds[0];
            pMsg->f_263 = 0;
            if (nStep != gabQuestFlagsB[nIndex])
            {
                pMsg->f_263 = 1;
            }
            gabQuestFlagsB[nIndex] = nStep;
            pMsg->wDesc = pTexts->awIds[nStepIndex * 2 + 2];
            pMsg->nState = 3;
            pMsg->bValid = 1;
            pMsg->nStep = nStep;
            if (nStep == 0xD)
            {
                pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xC) != 0;
            }
            return;
        }

        pMsg->wTitle = pTexts->awIds[0];
        int nString;
        if ((!bState0 && !bState13 && !QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 1)
            && pQuestHistory && QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable[nIndex].nQuestId, 0xD) && pMsg->nQuestId != 0x13)
            || QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xE))
        {
            nString = gdwGlobal_007A0610 ? 0xE92 : 0xE91;
        }
        else
        {
            nString = pTexts->awIds[nStep * 2 + 1];
            if (nString == 0xE8F && !gdwGlobal_007A0610)
            {
                nString = 0xE91;
            }
        }

        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
        if (pTexts->awIds[0] == 0x585E && nString == 0x5860)
        {
            if (!gnQuestParam)
            {
                sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(0xE91), 300);
            }
            else
            {
                sub_005269D0(300, pMsg->wszText, D2LANG_GetStringFromTblIndex(0x5860), gnQuestParam);
            }
        }

        pMsg->wszText[300 - 1] = 0;
        pMsg->f_263 = 0;
        if (nStep != gabQuestFlagsB[nIndex] && gaQuestTable[nIndex].pTexts)
        {
            pMsg->f_263 = 1;
        }
        gabQuestFlagsB[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[nStep * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        if (nStep == 0xD)
        {
            pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 0xC) != 0;
        }
        return;
    }

    unsigned short nString;
    if (QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable[nIndex].nQuestId, 0xD))
    {
        if (pMsg->nQuestId == 0x15 && !QUESTRECORD_GetQuestState(pQuestInfo, 0x15, 0) && QUESTRECORD_GetQuestState(pQuestInfo, 0x15, 4) == 1)
        {
            nString = 0x3DD;
        }
        else
        {
            if (bState13 || QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 1))
            {
                pMsg->nState = 2;
                return;
            }

            nString = 0xE92;
            if (!gdwGlobal_007A0610)
            {
                nString = 0xE91;
            }
            sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
            pMsg->wszText[300 - 1] = 0;
            pMsg->wDesc = 0xE8D;
            pMsg->bValid = 1;
            pMsg->nState = 3;
            return;
        }
    }
    else
    {
        if (!QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable[nIndex].nQuestId, 0xF) || bState13
            || QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable[nIndex].nQuestId, 1))
        {
            pMsg->nState = 2;
            return;
        }

        nString = 0xE92;
        if (!gdwGlobal_007A0610)
        {
            nString = 0xE91;
        }
    }

    sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
    pMsg->wszText[300 - 1] = 0;
    pMsg->wDesc = 0xE8D;
    pMsg->bValid = 1;
    pMsg->nState = 3;
}

void __stdcall TEXT_LoadQuestPage(int nPage, int bReset)
{
    int nCount = 0;
    int nFound = 0;
    int nFirst = -1;
    char szPath[260];

// build: symbol ?gnQuestSelectedSlot@* 0x007BF2B9
    gnQuestSelectedSlot = -1;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if ((!FOG_IsExpansion() || !GAME_IsExpansion()) && nPage == 4)
    {
        return;
    }

    for (int i = gaQuestPageRanges[nPage].nFirst; i <= gaQuestPageRanges[nPage].nLast; ++i)
    {
        if (!gapQuestIconCels[i])
        {
// build: symbol ?gaszQuestCelNames@* 0x006DA2C8
            sprintf(szPath, "%s\\ui\\menu\\%s", gszDataGlobal_006D4118, gaszQuestCelNames[i]);
            gapQuestIconCels[i] = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
    }

    if (gaQuestPageDefault[nPage] != -1)
    {
        gnQuestSelectedSlot = gaQuestPageDefault[nPage];
        if (bReset)
        {
            gaQuestPageDefault[4] = -1;
            gaQuestPageDefault[3] = -1;
            gaQuestPageDefault[2] = -1;
            gaQuestPageDefault[1] = -1;
            gaQuestPageDefault[0] = -1;
        }
        return;
    }

    for (; nCount < 41; ++nCount)
    {
        if (gaQuestTable[nCount].nPage == nPage && gaQuestTable[nCount].bEnabled
            && gaQuestTable[nCount].nCelId < 0x1B && gapQuestIconCels[gaQuestTable[nCount].nCelId])
        {
            D2QuestTextMsgStrc tMsg;
            for (int k = 0; k < 300; ++k)
            {
                tMsg.wszText[k] = 0;
            }
            tMsg.nQuestId = gaQuestTable[nCount].nQuestId;
            TEXT_BuildQuestText(&tMsg);
            if (tMsg.f_263 || !tMsg.nState)
            {
                nCount = 41;
                gnQuestSelectedSlot = tMsg.nCelId;
            }

            if (tMsg.nState == 1 || tMsg.nState == 2 || tMsg.nState == 3)
            {
                if (tMsg.nState != 2 && tMsg.nState != 1 && nFirst == -1)
                {
                    nFirst = tMsg.nCelId;
                }
                ++nFound;
            }
        }
    }

    if (nFound && gnQuestSelectedSlot == -1)
    {
// build: symbol ?gaQuestPageSelection@* 0x007BF2BD
        int nSelection = gaQuestPageSelection[nPage];
        if (nSelection != -1 || (nSelection = nFirst) != -1)
        {
            gnQuestSelectedSlot = nSelection;
        }
    }

    if (bReset)
    {
        gaQuestPageDefault[4] = -1;
        gaQuestPageDefault[3] = -1;
        gaQuestPageDefault[2] = -1;
        gaQuestPageDefault[1] = -1;
        gaQuestPageDefault[0] = -1;
    }
}

int __fastcall TEXT_TestQuestCondition(int nCondition)
{
    if (!INV_GetTableByte(0, nCondition))
    {
        return 0;
    }

    for (unsigned int i = 0; i < 41; ++i)
    {
        if (gaQuestTable[i].nCondition == nCondition)
        {
            const int nQuestId = gaQuestTable[i].nQuestId;
            if (nQuestId == 0x2A)
            {
                break;
            }

            if (!sub_004B32E0_GetQuestHistory() || QUESTRECORD_GetQuestState(sub_004B32E0_GetQuestHistory(), nQuestId, 0xD))
            {
                break;
            }

            if (!MONSTER_GetQuestFlags() || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), nQuestId, 1)
                || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), nQuestId, 0)
                || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), nQuestId, 0xE))
            {
                break;
            }

            if (nCondition == 1)
            {
                D2QuestTextMsgStrc tMsg;
                for (int k = 0; k < 300; ++k)
                {
                    tMsg.wszText[k] = 0;
                }
                tMsg.nQuestId = nQuestId;
                TEXT_BuildQuestText(&tMsg);
                if (tMsg.nStep >= 5)
                {
                    break;
                }
            }

            return 1;
        }
    }

    return 0;
}

void __stdcall TEXT_LoadQuestPage(int nPage, int bReset);                                           // 0x004A3220
static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg);                                          // 0x004A1950


struct D2SplittedTextStrc
{
    unsigned short* wszLine;
    D2SplittedTextStrc* pNextLine;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __cdecl CUNIT_IsPlayerDeadOrMissing();                                                                                 // 0x00463DF0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0
void __cdecl QUESTLOG_LoadQuestPanelCels();                                                                  // 0x004A23D0
int __stdcall QUESTLOG_OpenQuestPanel(int nArg);                                                             // 0x004A26B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const unsigned short* wszText);                                      // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall D2Win_10117_DrawText(const unsigned short* wszText, int nX, int nY, int nColor, int bCentered);   // 0x00502320
D2SplittedTextStrc* __fastcall sub_00502970_SplitText(unsigned short* pText, unsigned int* pLineCount, int nWidth); // 0x00502970
int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360
extern D2QuestPosStrc gaQuestPos[];                                                                // 0x00723EA8
extern int gnPanelOffsetX;                                                                               // 0x007A2858
extern int gnPanelOffsetY;                                                                               // 0x007A285C

#pragma pack(push, 1)
struct D2QuestLogStateStrc
{
    int nState;
    char unk0x004[4];
    int f_8;
    char unk0x00C[4];
    int nA8;
    char unk0x014[4];
    char bB0;
    char bB1;
    char bB2;
    char bB3;
    char bB4;
    int nIndexB5;
    int nIndexB9;
    char unk0x025[0x14];
    void* pCelD1;
    void* pCelD5;
    void* pCelD9;
    void* pCelDD;
    void* apCel[27];
    void* pCel34D;
    void* pCel351;
    char unk0x0BD[0x54];
    D2QuestTextMsgStrc aMsgs[6];
    int anAnim[6];
    unsigned int anTick[6];
    int nPage;
    char unk0xFC1[0x13];
    int n26C;
    int n270;
};
#pragma pack(pop)

extern D2QuestLogStateStrc gtQuestLog_007BF298;                                                             // 0x007BF298

struct D2TextNodeStrc;

#pragma pack(push, 2)
struct D2ClientListEntryStrc
{
    unsigned char nId[4];
    unsigned char unk0x04[6];
};
#pragma pack(pop)

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    void* pOwned[6];
    unsigned char unk0x18[10];
    unsigned char pNext[4];
};
#pragma pack(pop)

// 0x004A18F0
void __cdecl sub_004A3050()
{
    gaQuestPageDefault[0] = -1;
    gaQuestPageDefault[1] = -1;
    gaQuestPageDefault[2] = -1;
    gaQuestPageDefault[3] = -1;
    gaQuestPageDefault[4] = -1;
}

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

// build: symbol ?TEXT_SetQuestPage@* 0x004A2220
static void TEXT_SetQuestPage(int nPage)
{
    if (nPage >= 5)
    {
        nPage = 0;
    }
    switch (nPage)
    {
    case 4:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x1A, 0)) nPage = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x17, 0)) nPage = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0xF, 0)) nPage = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 7, 0)) nPage = 0;
    }
// build: symbol ?gnPage@* 0x007C0255
    gnPage = nPage;
    for (int i = 0; i < 6; ++i)
    {
        ganGlobal_007C0225[i] = 0;
        ganGlobal_007C023D[i] = 0;
    }
    gnQuestSelectedSlot = -1;
// build: symbol ?gnQuestPressedSlot@* 0x007BF2B5
    gnQuestPressedSlot = -1;
}

// 0x004A2300
void __cdecl QUESTLOG_UpdateQuestPage()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
        {
            int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (nLevelId)
            {
                TEXT_SetQuestPage(DRLG_GetActNoFromLevelId(nLevelId));
                return;
            }
        }
    }
    TEXT_SetQuestPage(0);
}

extern "C" { unsigned char gByte_007BF2B1; } // 0x007BF2B1

extern "C" unsigned char gByte_007BF2B2; // 0x007BF2B2

extern "C" unsigned char gByte_007BF2B0; // 0x007BF2B0

extern "C" int gSentinel_007BF2B5; // 0x007BF2B5

extern "C" unsigned char gByte_007BF2B4; // 0x007BF2B4

extern "C" unsigned char gByte_007C025D; // 0x007C025D

extern "C" unsigned char gByte_007C025E; // 0x007C025E

extern "C" unsigned char gByte_007C025F; // 0x007C025F

extern "C" unsigned char gByte_007C0260; // 0x007C0260

// 0x004A2390
extern "C" void __cdecl QUESTLOG_ResetQuestGlobals(void)
{
    gByte_007BF2B1 = 0;
    gByte_007BF2B2 = 0;
    gByte_007BF2B0 = 0;
    gSentinel_007BF2B5 = -1;
    gByte_007BF2B4 = 0;
    gByte_007C025D = 0;
    gByte_007C025E = 0;
    gByte_007C025F = 0;
    gByte_007C0260 = 0;
}

struct D2ClientServiceStrc
{
    char unk0x00[0xD0];
    int (__fastcall* pfnCall)(int nArg1, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsNameSquelched(const char* szName);
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual int IsTextSquelched(const char* szText);
    virtual void AddName(const char* szName, int nSize);
};

// 0x004A23D0
void __cdecl QUESTLOG_LoadQuestPanelCels()
{
    char szPath[0x104];
    if (sub_00483350())
    {
        return;
    }
// build: symbol ?gpQuestBackgroundCel@* 0x007BF2D5
    if (!gpQuestBackgroundCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questbackground", gszDataGlobal);
        gpQuestBackgroundCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestTabsCel@* 0x007BF2D9
    if (!gpQuestTabsCel)
    {
        if (FOG_IsExpansion() && GAME_IsExpansion())
        {
            sprintf(szPath, "%s\\ui\\menu\\expquesttabs", gszDataGlobal);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\questtabs", gszDataGlobal);
        }
        gpQuestTabsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestSocketsCel@* 0x007BF2D1
    if (!gpQuestSocketsCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questsockets", gszDataGlobal);
        gpQuestSocketsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestDoneCel@* 0x007BF2DD
    if (!gpQuestDoneCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questdone", gszDataGlobal);
        gpQuestDoneCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpInvPsCel@* 0x007BF351
    if (!gpInvPsCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\invps", gszDataGlobal);
        gpInvPsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestLastCel@* 0x007BF34D
    if (!gpQuestLastCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questlast", gszDataGlobal);
        gpQuestLastCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

// 0x004A2550
void __cdecl QUESTLOG_FreeQuestCels()
{
    if (gpQuestBackgroundCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestBackgroundCel);
        gpQuestBackgroundCel = 0;
    }
    if (gpQuestTabsCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestTabsCel);
        gpQuestTabsCel = 0;
    }
    if (gpQuestLastCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestLastCel);
        gpQuestLastCel = 0;
    }
    if (gpQuestSocketsCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestSocketsCel);
        gpQuestSocketsCel = 0;
    }
    if (gpQuestDoneCel)
    {
        ARCHIVE_FreeClientCellFile(gpQuestDoneCel);
        gpQuestDoneCel = 0;
    }
    if (gpInvPsCel)
    {
        ARCHIVE_FreeClientCellFile(gpInvPsCel);
        gpInvPsCel = 0;
    }
    for (int i = 0; i < 27; ++i)
    {
        if (gapQuestIconCels[i])
        {
            ARCHIVE_FreeClientCellFile(gapQuestIconCels[i]);
            gapQuestIconCels[i] = 0;
        }
    }
}

// 0x004A2600
void __cdecl QUESTLOG_FreeQuestPanel()
{
    QUESTLOG_FreeQuestCels();
}

extern int gtQuestLog; // 0x007BF298

char gbGlobal_007BF2B0; // 0x007BF2B0

char gbQuestDescriptionOpen; // 0x007BF2B3

// 0x004A26B0
int __stdcall QUESTLOG_OpenQuestPanel(int nArg)
{
    if (gtQuestLog == 2)
    {
        gtQuestLog = 0;
        gbGlobal_007BF2B0 = 0;
        gbQuestDescriptionOpen = 0;
    }

    sub_004A2550();
    UI_SetUIVar(15, 1, nArg);
    return 1;
}

void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0

struct D2QuestPanelEntryStrc;


int gnQuestCount; // 0x007BF2A0

extern D2QuestPanelEntryStrc gaQuestEntries[]; // 0x007BF3AA

// 0x004A2760
void __cdecl QUESTLOG_SendQuestUpdates()
{
    for (int i = 0; i < gnQuestCount; ++i)
    {
        if (!gaQuestEntries[i].bDone)
        {
            D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
            QUESTRECORD_SetQuestState(pQuestInfo, gaQuestEntries[i].nQuestId, 0xC);
            MSG_SendWord(0x58, (unsigned short)gaQuestEntries[i].nQuestId);
        }
    }
}

// 0x004A27B0
int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue)
{
    gbQuestDescriptionOpen = 0;
    TEXT_SetTextCallback(0, pContext);
    return 0;
}

struct PacketShorts;

#pragma pack(push, 1)
struct PacketShorts
{
    char prefix[1];
    unsigned short kind;
    unsigned short a;
    unsigned short b;
    unsigned short c;
};
#pragma pack(pop)

extern "C" unsigned int gValue_007BF2A4; // 0x007BF2A4

extern "C" unsigned int gValue_007BF2AC; // 0x007BF2AC

extern "C" { unsigned int gValue_007BF2A8; } // 0x007BF2A8

// 0x004A28A0
extern "C" void __fastcall QUESTLOG_AcceptShortPacket(const PacketShorts* packet)
{
    switch (packet->kind)
    {
    case 1:
        gValue_007BF2A4 = packet->a;
        gValue_007BF2A8 = packet->b;
        gValue_007BF2AC = packet->c;
        break;
    }
}

// 0x004A28D0
void __cdecl QUESTLOG_ResetQuestButton()
{
    if (gnPage < 5)
        sub_004A2760(gnPage);
    gbGlobal_007BF2B0 = 0;
    gtQuestLog = 0;
    gbQuestDescriptionOpen = 0;
    sub_004A2550();
}

extern int gnScreenWidth; // 0x0071146C

int __stdcall QUESTLOG_IsMouseOnQuestButton(int nX, int nY); // 0x004A2970

struct D2ButtonLayoutStrc;

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160


int __cdecl sub_0045AE90(); // 0x0045AE90

extern D2ButtonLayoutStrc gaButtonLayouts[]; // 0x007241C0

// build: symbol ?sub_E10_GetButtonLayoutCopy@@YAHH@Z 0x004A2900
static int sub_E10_GetButtonLayoutCopy(int nMode)
{
    if (GAME_GetUIVarState(6) && !GAME_GetUIVarState(2))
    {
        const int nResolution = D2GFX_GetResolutionMode();
        if (nMode == 2)
            return nResolution == 2 ? 1 : 3;
        return nResolution == 2 ? 0 : 2;
    }

    const int nResolution = D2GFX_GetResolutionMode();
    if (nMode == 2)
    {
        if (nResolution == 2 || GAME_GetUIVarState(2))
            return 1;
        return 3;
    }
    return nResolution == 2 ? 0 : 2;
}

// 0x004A2900
static int QUESTLOG_GetButtonLayout(int nMode)
{
    if (GAME_GetUIVarState(6) && !GAME_GetUIVarState(2))
    {
        const int nResolution = D2GFX_GetResolutionMode();
        if (nMode == 2)
            return nResolution == 2 ? 1 : 3;
        return nResolution == 2 ? 0 : 2;
    }

    const int nResolution = D2GFX_GetResolutionMode();
    if (nMode == 2)
    {
        if (nResolution == 2 || GAME_GetUIVarState(2))
            return 1;
        return 3;
    }
    return nResolution == 2 ? 0 : 2;
}

// 0x004A2970
int __stdcall QUESTLOG_IsMouseOnQuestButton(int nX, int nY)
{
    const int nMode = sub_0045AE90();
    const int nIndex = sub_E10_GetButtonLayoutCopy(nMode);
    const int nLeft = gaButtonLayouts[nIndex].nTextX + (nMode == 2 ? (gnScreenWidth - 0x280) / 2 : 0);
    const int nTop = gaButtonLayouts[nIndex].nTop + gnScreenHeight - 0x1E0;
    const int nRight = gaButtonLayouts[nIndex].nRight + (nMode == 2 ? (gnScreenWidth - 0x280) / 2 : 0);
    if (nX > nLeft && nX < nRight && nY > nTop && nY < gaButtonLayouts[nIndex].nBottom + gnScreenHeight - 0x1E0)
        return 1;
    return 0;
}

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

extern void* gpLevelCel; // 0x007C02DC

extern void* gpLevelSocketCel; // 0x007C02E0

// 0x004A2A80
void __cdecl QUESTLOG_DrawQuestButton()
{
    if (CUNIT_IsPlayerDeadOrMissing())
    {
        UI_SetUIVar(0x11, 1, 0);
        if (gtQuestLog == 1)
        {
            gbGlobal_007BF2B0 = 0;
            gtQuestLog = 0;
        }
        return;
    }

    const int nMode = sub_0045AE90();
    if (nMode == 3)
        return;
    if (GAME_GetUIVarState(0x0F))
        return;

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.nDirection = 0;
    tCel.pCellFile = gpLevelSocketCel;
    tCel.nFrame = 0;
    const int nIndex = sub_E10_GetButtonLayoutCopy(nMode);
    const int nCelWidth = CelGetWidth(CelGetHandle(&tCel));
    const int nTextWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF58));
    int nTextX = nCelWidth / 2 - nTextWidth / 2 + gaButtonLayouts[nIndex].nTextX + 1;
    const int nTextY = gaButtonLayouts[nIndex].nTextY + gnScreenHeight - 0x1E0;
    if (sub_0045AE90() == 2)
        nTextX += (gnScreenWidth - 0x280) / 2;
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF58), nTextX, nTextY, 0, 0);

    int nCelX = gaButtonLayouts[nIndex].nTextX;
    const int nCelY = gaButtonLayouts[nIndex].nBottom + gnScreenHeight - 0x1E0;
    if (sub_0045AE90() == 2)
        nCelX += (gnScreenWidth - 0x280) / 2;
    sub_004F6480(&tCel, nCelX, nCelY, -1, 5, 0);

    tCel.pCellFile = gpLevelCel;
    tCel.nFrame = gbGlobal_007BF2B0 && (unsigned char)QUESTLOG_IsMouseOnQuestButton(sub_00468730(), sub_00468740());
    sub_004F6480(&tCel, nCelX + 3, nCelY - 4, -1, 5, 0);
}

// 0x004A2C30
void __fastcall QUESTLOG_SelectQuestPage(int nCondition)
{
    int nIndex = -1;
    for (int i = 0; i < 41; ++i)
    {
        if (gaQuestTable[i].nCondition == nCondition)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex != -1)
        gaQuestPageDefault[gaQuestTable[nIndex].nPage] = gaQuestTable[nIndex].nCelId2;
}

// 0x004A2C70
void __fastcall QUESTLOG_ClearCainFlag(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x92)
        pUnit->dwFlags &= ~2u;
}

// 0x004A2C90
void __fastcall QUESTLOG_ClearNihlathakFlag(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x20F)
        pUnit->dwFlags &= ~2u;
}

extern "C" int gB27_007BF298; // 0x007BF298

// 0x004A3000
extern "C" void __cdecl QUESTLOG_ResetQuestButtonState()
{
    if (gB27_007BF298 == 1)
        gB27_007BF298 = 0;
}

char gbGlobal_007C025D; // 0x007C025D

struct D2TimedHintEntryStrc;

struct D2ViewStrc;

struct D2CacheStatsStrc;

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x24];
    int nState;
};

struct D2ViewStrc
{
    unsigned int dwFlags;
    tagRECT tRect;
    unsigned char unk_14[0x10];
    int nPosX;
    int nPosY;
    void* pLerpData;
    void* pLerpTable;
    void* pLerpRows;
    unsigned int dwDrawFlags;
};

struct D2CacheStatsStrc
{
    unsigned int nFloorSize;
    int unk0x04;
    int nFloorMisses;
    unsigned int nSubtileSize;
    int unk0x10;
    int nSubtileMisses;
    unsigned int nSpriteSize[3];
    int unk0x24[3];
    int nSpriteMisses[3];
    int unk0x3C[3];
    int nSpriteAccesses[3];
    int unk0x54[3];
    int unk0x60[3];
};


struct D2QuestLookupEntryStrc;

struct D2QuestPanelValuesStrc;

struct D2QuestLookupEntryStrc
{
    int nKey;
    int nValue;
    int unk0x08;
    int unk0x0C;
};

#pragma pack(push, 1)
struct D2QuestPanelValuesStrc
{
    char unk0x00[0x7];
    int nValues[0x96];
};
#pragma pack(pop)

extern D2QuestLookupEntryStrc gaQuestLookup_00723F38[0x29]; // 0x00723F38

// 0x004A3070
int __fastcall QUESTLOG_LookupQuestValue(int nUnused, int nKey)
{
    for (unsigned int i = 0; i < 0x29; ++i)
    {
        if (gaQuestLookup_00723F38[i].nKey == nKey)
        {
            return gaQuestLookup_00723F38[i].nValue;
        }
    }
    return 0x2A;
}

// 0x004A30A0
void __cdecl QUESTLOG_LoadDurielCofsOnce()
{
    if (!gbGlobal_007C025D)
    {
        gbGlobal_007C025D = 1;
// build: symbol ?GFX_LoadMonsterCofs@* 0x0046F870
        GFX_LoadMonsterCofs(0xD3, 1);
    }
}

char gbGlobal_007C025E; // 0x007C025E

// 0x004A30C0
void __cdecl QUESTLOG_LoadAncientsCofsOnce()
{
    if (!gbGlobal_007C025E)
    {
        gbGlobal_007C025E = 1;
        GFX_LoadMonsterCofs(0x219, 0);
        GFX_LoadMonsterCofs(0x21A, 0);
        GFX_LoadMonsterCofs(0x21B, 0);
    }
}

extern "C" unsigned char gB27_007C025F; // 0x007C025F

extern "C" unsigned int gB27_007C0265; // 0x007C0265

// 0x004A3100
extern "C" void __fastcall QUESTLOG_SetQuestPacketValue(unsigned int value)
{
    gB27_007C025F = 1;
    gB27_007C0265 = value;
}

char gbGlobal_007C025F; // 0x007C025F

// 0x004A3110
char __cdecl QUESTLOG_HasQuestPacketValue()
{
    return gbGlobal_007C025F;
}

char gbGlobal_007C0260; // 0x007C0260

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

extern unsigned int gnQuestUnitId; // 0x007C0261

// 0x004A3120
char __cdecl QUESTLOG_IsQuestUnitPresent()
{
    if (gbGlobal_007C0260 && CUNIT_FindServerSideUnit(gnQuestUnitId, 1))
    {
        return 1;
    }
    return 0;
}

union D2SeedStrc;

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

// 0x004A3150
void __fastcall QUESTLOG_SpawnQuestUnits(int nX, int nY)
{
    if (gbGlobal_007C025F)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nCount = SEED_RollLimitedRandomNumber(&pPlayer->pSeed, 3) + 2;
        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pUnit = CUNIT_SpawnPresetUnit(0x95, nX + i % 2, nY + i % 2, 1, 1);
            gnQuestUnitId = UNITS_GetUnitId(pUnit);
            gbGlobal_007C0260 = 1;
        }
    }
}

// 0x004A3200
D2QuestPanelValuesStrc* __fastcall QUESTLOG_ClearQuestPanelValues(D2QuestPanelValuesStrc* pValues)
{
    for (int i = 0; i < 0x96; ++i)
    {
        pValues->nValues[i] = 0;
    }
    return pValues;
}

// 0x004A34F0
void __cdecl QUESTLOG_DrawQuestPage()
{
    int i = 0;
    D2CelContextStrc tDraw;
    memset(&tDraw, 0, sizeof(tDraw));
    tDraw.nDirection = 0;

    if (CUNIT_IsPlayerDeadOrMissing())
    {
        if (gtQuestLog_007BF298.nState == 2)
        {
            gtQuestLog_007BF298.nState = 0;
            gtQuestLog_007BF298.bB0 = 0;
            gtQuestLog_007BF298.bB3 = 0;
        }
        sub_004A2550();
        UI_SetUIVar(0xF, 1, 0);
        return;
    }

    if (GAME_GetUIVarState(0x12))
    {
        QUESTLOG_OpenQuestPanel(0);
        return;
    }

    if (sub_00483350())
    {
        QUESTLOG_OpenQuestPanel(0);
        return;
    }

    if (!gtQuestLog_007BF298.pCelD5)
    {
        QUESTLOG_LoadQuestPanelCels();
        TEXT_LoadQuestPage(0, 1);
    }

    if (gtQuestLog_007BF298.pCelD5)
    {
        tDraw.pCellFile = gtQuestLog_007BF298.pCelD5;
        tDraw.nFrame = 0;
        sub_004F6480(&tDraw, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tDraw.nFrame = 1;
        sub_004F6480(&tDraw, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tDraw.nFrame = 2;
        sub_004F6480(&tDraw, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
        tDraw.nFrame = 3;
        sub_004F6480(&tDraw, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
    }

    if (gtQuestLog_007BF298.pCelD9)
    {
        tDraw.pCellFile = gtQuestLog_007BF298.pCelD9;
        for (; i < 5; ++i)
        {
            int bExpansion = 0;
            int aX[5];
            if (FOG_IsExpansion() && GAME_IsExpansion())
            {
                bExpansion = 1;
                aX[0] = 5;
                aX[1] = 0x43;
                aX[2] = 0x81;
                aX[3] = 0xBF;
                aX[4] = 0xFD;
            }
            else
            {
                aX[0] = 5;
                aX[1] = 0x52;
                aX[2] = 0x9F;
                aX[3] = 0xEC;
                if (i > 3)
                    break;
            }

            if (i == gtQuestLog_007BF298.nPage)
            {
                tDraw.nFrame = 2 * i;
                sub_004F6480(&tDraw, aX[i] + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY + bExpansion - 0x1C0, -1, 5, 0);
                continue;
            }

            unsigned char bShow = 1;
            switch (i)
            {
            case 1:
                if (QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 7, 0))
                    break;
                continue;
            case 2:
                if (QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0xF, 0))
                    break;
                continue;
            case 3:
                if (QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x17, 0))
                    break;
                continue;
            case 4:
                if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x1A, 0))
                    bShow = 0;
                if (!FOG_IsExpansion() || !GAME_IsExpansion() || !bShow)
                    continue;
                break;
            }

            tDraw.nFrame = 2 * i + 1;
            sub_004F6480(&tDraw, aX[i] + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY + bExpansion - 0x1C0, -1, 5, 0);
        }
    }

    for (int k = 0; k < 6; ++k)
        memset(gtQuestLog_007BF298.aMsgs, 0, sizeof(gtQuestLog_007BF298.aMsgs));

    unsigned char bSpecial = 0;
    if (gtQuestLog_007BF298.nPage < 5)
    {
        gtQuestLog_007BF298.f_8 = 0;
        int nRow = 0;
        unsigned char bDone = 0;
        D2QuestTableStrc* pEntry = gaQuestTable;
        do
        {
            int nSlot = -1;
            if (pEntry->nPage == gtQuestLog_007BF298.nPage && pEntry->bEnabled && pEntry->nCelId < 0x1B && gtQuestLog_007BF298.apCel[pEntry->nCelId] && gtQuestLog_007BF298.f_8 < 6)
            {
                gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].nQuestId = pEntry->nQuestId;
                TEXT_BuildQuestText(&gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8]);
                int nFrame;
                switch (gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].nState)
                {
                case 0:
                    gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].unk0x000[0] = 1;
                    nFrame = gtQuestLog_007BF298.anAnim[gtQuestLog_007BF298.f_8];
                    if (nFrame >= 0x19)
                    {
                        nFrame = 0x18;
                        D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
                        QUESTRECORD_SetQuestState(pQuestInfo, pEntry->nQuestId, 0xC);
                        MSG_SendWord(0x58, (unsigned short)pEntry->nQuestId);
                    }
                    tDraw.pCellFile = gtQuestLog_007BF298.apCel[pEntry->nCelId];
                    tDraw.nFrame = nFrame;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    {
                        const unsigned int dwTick = GetTickCount();
                        if (!gtQuestLog_007BF298.anTick[gtQuestLog_007BF298.f_8])
                            gtQuestLog_007BF298.anTick[gtQuestLog_007BF298.f_8] = dwTick;
                        if (dwTick - gtQuestLog_007BF298.anTick[gtQuestLog_007BF298.f_8] > 100)
                        {
                            gtQuestLog_007BF298.anTick[gtQuestLog_007BF298.f_8] = dwTick;
                            gtQuestLog_007BF298.anAnim[gtQuestLog_007BF298.f_8] += 1;
                            if (gtQuestLog_007BF298.anAnim[gtQuestLog_007BF298.f_8] == 1 && FOG_IsExpansion())
                                sub_004B9A00(0xE, 0, 0, 0, 0);
                        }
                    }
                    nSlot = pEntry->nCelId2;
                    gtQuestLog_007BF298.f_8 += 1;
                    break;
                case 1:
                    gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].unk0x000[0] = 1;
                    if (gtQuestLog_007BF298.nIndexB5 == pEntry->nCelId2)
                    {
                        tDraw.pCellFile = gtQuestLog_007BF298.pCelDD;
                        tDraw.nFrame = pEntry->nCelId;
// build: symbol ?gnQuestAnimOffsetY@* 0x00724220
                        sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gtQuestLog_007BF298.n270 + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gnQuestAnimOffsetY, -1, 5, 0);
                    }
                    else
                    {
                        tDraw.nFrame = 0x18;
                        tDraw.pCellFile = gtQuestLog_007BF298.apCel[pEntry->nCelId];
                        sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    }
                    nSlot = pEntry->nCelId2;
                    gtQuestLog_007BF298.f_8 += 1;
                    break;
                case 2:
                    gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].unk0x000[0] = 1;
                    tDraw.nFrame = 0x1A;
                    tDraw.pCellFile = gtQuestLog_007BF298.apCel[pEntry->nCelId];
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    nSlot = pEntry->nCelId2;
                    gtQuestLog_007BF298.f_8 += 1;
                    break;
                case 3:
                    if (gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].wTitle == 0x3A0 && gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].nStep == 7)
                        bSpecial = 1;
                    gtQuestLog_007BF298.aMsgs[gtQuestLog_007BF298.f_8].unk0x000[0] = 1;
                    tDraw.pCellFile = gtQuestLog_007BF298.apCel[pEntry->nCelId];
                    tDraw.nFrame = (gtQuestLog_007BF298.nIndexB5 == pEntry->nCelId2) ? 0x19 : 0;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY, -1, 5, 0);
                    nSlot = pEntry->nCelId2;
                    gtQuestLog_007BF298.f_8 += 1;
                    break;
                }

                tDraw.pCellFile = gtQuestLog_007BF298.pCelD1;
                if (nSlot == gtQuestLog_007BF298.nIndexB9)
                {
                    tDraw.nFrame = 1;
// build: symbol ?gnQuestIconOffsetY@* 0x0072421C
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX - 4, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gnQuestIconOffsetY + 5, -1, 5, 0);
                }
                else
                {
                    tDraw.nFrame = 0;
                    sub_004F6480(&tDraw, gaQuestPos[pEntry->nCelId2].nX + gnPanelOffsetX - 4, gaQuestPos[pEntry->nCelId2].nY - gnPanelOffsetY + gtQuestLog_007BF298.n26C + 5, -1, 5, 0);
                }
            }

            ++nRow;
            if (nRow > 0x29 || gtQuestLog_007BF298.f_8 >= 6)
                bDone = 1;
            ++pEntry;
        }
        while (!bDone);

        if (bSpecial && gtQuestLog_007BF298.nIndexB9 == 5)
        {
            tDraw.pCellFile = gtQuestLog_007BF298.pCel351;
            tDraw.nFrame = gtQuestLog_007BF298.nA8;
            if (tDraw.nFrame < 0 || tDraw.nFrame > 6)
                tDraw.nFrame = 0;
            sub_004F6480(&tDraw, gnPanelOffsetX + 0x6E, gnScreenHeight + gnPanelOffsetY - 0x6E, -1, 3, 0);
        }
    }

    D2Win_10127_SetFont(8);
    const int nSelected = gtQuestLog_007BF298.nIndexB9;
    if (nSelected != -1 && nSelected < 6 && nSelected < gtQuestLog_007BF298.f_8)
    {
        int nFound = -1;
        for (int k = 0; k < gtQuestLog_007BF298.f_8; ++k)
        {
            if (gtQuestLog_007BF298.aMsgs[k].nCelId == nSelected)
            {
                nFound = k;
                break;
            }
        }

        if (nFound != -1 && gtQuestLog_007BF298.aMsgs[nFound].unk0x000[0])
        {
            if (gtQuestLog_007BF298.aMsgs[nFound].wTitle != 0xE8C)
            {
                const unsigned short* pTitle = D2LANG_GetStringFromTblIndex(gtQuestLog_007BF298.aMsgs[nFound].wTitle);
// build: symbol ?gnQuestTitleY@* 0x00724218
                D2Win_10117_DrawText(pTitle, gnPanelOffsetX - D2Win_10121_GetTextWidth(pTitle) / 2 + 0xA0, gnQuestTitleY - gnPanelOffsetY, 0, 0);
            }

            if (!gtQuestLog_007BF298.bB3 && gtQuestLog_007BF298.aMsgs[nFound].wszText[0])
            {
                unsigned int nLines;
                D2SplittedTextStrc* pLine = sub_00502970_SplitText(gtQuestLog_007BF298.aMsgs[nFound].wszText, &nLines, 0x10E);
                if (pLine)
                {
                    int nLine = 0;
                    do
                    {
// build: symbol ?gnQuestTextTop@* 0x00724210
// build: symbol ?gnQuestTextLeft@* 0x00724214
                        D2Win_10117_DrawText(pLine->wszLine, gnPanelOffsetX + gnQuestTextLeft, nLine * 0x14 - gnPanelOffsetY + gnQuestTextTop, 0, 0);
                        D2SplittedTextStrc* pNext = pLine->pNextLine;
                        FOG_Free(pLine->wszLine, ".\\UI\\QuestLog.cpp", 0x8D1, 0);
                        FOG_Free(pLine, ".\\UI\\QuestLog.cpp", 0x8D2, 0);
                        ++nLine;
                        pLine = pNext;
                    }
                    while (pLine);
                }
            }
        }
    }

    tDraw.pCellFile = sub_00454600();
    tDraw.nFrame = (gtQuestLog_007BF298.bB2 != 0) + 0xA;
    sub_004F6480(&tDraw, gnPanelOffsetX + 0x116, gnScreenHeight + gnPanelOffsetY - 0x3A, -1, 5, 0);

    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    nMouseX -= gnPanelOffsetX;
    nMouseY += gnPanelOffsetY;
    if (nMouseX >= 0x116 && nMouseX <= 0x139 && nMouseY >= 0x188 && nMouseY <= 0x1A9)
    {
        D2Win_10127_SetFont(9);
        const unsigned short* pHelp = D2LANG_GetStringFromTblIndex(0x1030);
        sub_00502280_SetPopUpText(pHelp, gnPanelOffsetX + 0x128, gnScreenHeight + gnPanelOffsetY - 0x5F, 0, 1);
    }

    tDraw.pCellFile = gtQuestLog_007BF298.pCel34D;
    tDraw.nFrame = gtQuestLog_007BF298.bB4 != 0;
    sub_004F6480(&tDraw, gnPanelOffsetX + 0xE2, gnPanelOffsetY + gnScreenHeight - 0x3A, -1, 5, 0);
    if (nMouseX >= 0xE6 && nMouseX <= 0x103 && nMouseY >= 0x187 && nMouseY <= 0x1A7)
    {
        const unsigned short* pText = D2LANG_GetStringFromTblIndex(0xE88);
        D2Win_10127_SetFont(9);
        sub_00502280_SetPopUpText(pText, gnPanelOffsetX + 0xF1, gnScreenHeight + gnPanelOffsetY - 0x5F, 0, 1);
    }
}

unsigned char __cdecl INV_IsCinematicBusy(); // 0x00483350

int __cdecl sub_004A1760_Forward();

void __stdcall sub_004A3220(int nPage, int nArg);

void __fastcall MSG_SendHeaderOnly(char nValue); // 0x00478590

void __fastcall QUESTLOG_ToggleQuestLog(int nMode); // 0x004A3FE0

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A3FE0
void __fastcall QUESTLOG_ToggleQuestLog(int nMode)
{
    if (gtQuestLog == 0)
    {
// build: symbol ?gdwQuestLogToggleTick@* 0x007C0259
        if (GetTickCount() - gdwQuestLogToggleTick < 250)
            return;
        if (CUNIT_IsPlayerDeadOrMissing())
            return;
        if (INV_IsCinematicBusy())
            return;
        if (UI_SetUIVar(15, 0, nMode) != 1)
            return;
        QUESTLOG_LoadQuestPanelCels();
        gtQuestLog = 2;
        QUESTLOG_UpdateQuestPage();
// build: symbol ?gnPage@* 0x007C0255
        sub_004A3220(gnPage, 0);
        MSG_SendHeaderOnly(0x40);
        return;
    }

    if (gtQuestLog == 1)
    {
        gtQuestLog = 0;
        if (INV_IsCinematicBusy())
            return;
        if (UI_SetUIVar(15, 0, nMode) != 1)
            return;
        QUESTLOG_LoadQuestPanelCels();
        gtQuestLog = 2;
        QUESTLOG_UpdateQuestPage();
        sub_004A3220(gnPage, 0);
        MSG_SendHeaderOnly(0x40);
        return;
    }

    QUESTLOG_OpenQuestPanel(nMode);
    gdwQuestLogToggleTick = GetTickCount();
    sub_004A1760_Forward();
}

struct D2Record42Strc;

#pragma pack(push, 2)
struct D2Record42Strc
{
    int aData[10];
    unsigned short wLast;
};
#pragma pack(pop)

extern unsigned char gbFlag_007BF2B0; // 0x007BF2B0

extern D2Record42Strc gtQuestRecord; // 0x007BF355

extern int gnPage_007C0255; // 0x007C0255

// 0x004A40D0
void __fastcall QUESTLOG_SetQuestRecord(const D2Record42Strc* pRecord)
{
    gtQuestRecord = *pRecord;
    gbFlag_007BF2B0 = 0;
    if (!sub_00483350())
    {
        if (gnState_007BF298 == 2)
        {
            QUESTLOG_LoadQuestPanelCels();
        }
        sub_004A3220(gnPage_007C0255, 1);
    }
}

#include "gen/data/Source/D2Client/UI/QuestLog.inc"
struct D2CelFileStrc;
