#include "D2Client.h"
#include "D2Primitives.h"
#include "D2CelContext.h"
#include "D2Unicode.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

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

struct D2QuestTableStrc
{
    unsigned char bEnabled;
    unsigned char nCelId;
    unsigned char nCelId2;
    unsigned char nPage;
    D2QuestTextsStrc* pTexts;
    int nCondition;
    int nQuestId;
};

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

// build: context TEXT_BuildQuestText
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


struct T0044CB60
{
    unsigned short* pText;
    T0044CB60* pNext;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __cdecl CUNIT_IsPlayerDeadOrMissing();                                                                                 // 0x00463DF0
int __cdecl sub_00468730();                                                                                 // 0x00468730
int __cdecl sub_00468740();                                                                                 // 0x00468740
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg);                          // 0x004785B0
void __cdecl TEXT_LoadQuestPanelCels();                                                                  // 0x004A23D0
int __stdcall TEXT_OpenQuestPanel(int nArg);                                                             // 0x004A26B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                   // 0x004B9A00
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const unsigned short* wszText);                                      // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall D2Win_10117_DrawText(const unsigned short* wszText, int nX, int nY, int nColor, int bCentered);   // 0x00502320
T0044CB60* __fastcall sub_00502970_SplitText(unsigned short* pText, unsigned int* pLineCount, int nWidth); // 0x00502970
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

// 0x004A34F0
void __cdecl sub_004A34F0_DrawQuestPage()
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
        TEXT_OpenQuestPanel(0);
        return;
    }

    if (sub_00483350())
    {
        TEXT_OpenQuestPanel(0);
        return;
    }

    if (!gtQuestLog_007BF298.pCelD5)
    {
        TEXT_LoadQuestPanelCels();
        TEXT_LoadQuestPage(0, 1);
    }

    if (gtQuestLog_007BF298.pCelD5)
    {
        tDraw.pCellFile = gtQuestLog_007BF298.pCelD5;
        tDraw.nFrame = 0;
        sub_004F6480(&tDraw, gnPanelOffsetX, gnScreenHeight_00711470 + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tDraw.nFrame = 1;
        sub_004F6480(&tDraw, gnPanelOffsetX + 0x100, gnScreenHeight_00711470 + gnPanelOffsetY - 0xE0, -1, 5, 0);
        tDraw.nFrame = 2;
        sub_004F6480(&tDraw, gnPanelOffsetX, gnScreenHeight_00711470 + gnPanelOffsetY - 0x30, -1, 5, 0);
        tDraw.nFrame = 3;
        sub_004F6480(&tDraw, gnPanelOffsetX + 0x100, gnScreenHeight_00711470 + gnPanelOffsetY - 0x30, -1, 5, 0);
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
                sub_004F6480(&tDraw, aX[i] + gnPanelOffsetX, gnScreenHeight_00711470 + gnPanelOffsetY + bExpansion - 0x1C0, -1, 5, 0);
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
            sub_004F6480(&tDraw, aX[i] + gnPanelOffsetX, gnScreenHeight_00711470 + gnPanelOffsetY + bExpansion - 0x1C0, -1, 5, 0);
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
                        sub_004785B0_SendPacket3(0x58, (unsigned short)pEntry->nQuestId);
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
            sub_004F6480(&tDraw, gnPanelOffsetX + 0x6E, gnScreenHeight_00711470 + gnPanelOffsetY - 0x6E, -1, 3, 0);
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
                T0044CB60* pLine = sub_00502970_SplitText(gtQuestLog_007BF298.aMsgs[nFound].wszText, &nLines, 0x10E);
                if (pLine)
                {
                    int nLine = 0;
                    do
                    {
// build: symbol ?gnQuestTextTop@* 0x00724210
// build: symbol ?gnQuestTextLeft@* 0x00724214
                        D2Win_10117_DrawText(pLine->pText, gnPanelOffsetX + gnQuestTextLeft, nLine * 0x14 - gnPanelOffsetY + gnQuestTextTop, 0, 0);
                        T0044CB60* pNext = pLine->pNext;
                        FOG_Free(pLine->pText, ".\\UI\\QuestLog.cpp", 0x8D1, 0);
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
    sub_004F6480(&tDraw, gnPanelOffsetX + 0x116, gnScreenHeight_00711470 + gnPanelOffsetY - 0x3A, -1, 5, 0);

    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    nMouseX -= gnPanelOffsetX;
    nMouseY += gnPanelOffsetY;
    if (nMouseX >= 0x116 && nMouseX <= 0x139 && nMouseY >= 0x188 && nMouseY <= 0x1A9)
    {
        D2Win_10127_SetFont(9);
        const unsigned short* pHelp = D2LANG_GetStringFromTblIndex(0x1030);
        sub_00502280_SetPopUpText(pHelp, gnPanelOffsetX + 0x128, gnScreenHeight_00711470 + gnPanelOffsetY - 0x5F, 0, 1);
    }

    tDraw.pCellFile = gtQuestLog_007BF298.pCel34D;
    tDraw.nFrame = gtQuestLog_007BF298.bB4 != 0;
    sub_004F6480(&tDraw, gnPanelOffsetX + 0xE2, gnPanelOffsetY + gnScreenHeight_00711470 - 0x3A, -1, 5, 0);
    if (nMouseX >= 0xE6 && nMouseX <= 0x103 && nMouseY >= 0x187 && nMouseY <= 0x1A7)
    {
        const unsigned short* pText = D2LANG_GetStringFromTblIndex(0xE88);
        D2Win_10127_SetFont(9);
        sub_00502280_SetPopUpText(pText, gnPanelOffsetX + 0xF1, gnScreenHeight_00711470 + gnPanelOffsetY - 0x5F, 0, 1);
    }
}

#include "gen/data/Source/D2Client/UI/QuestLog.inc"
struct D2CelFileStrc;
