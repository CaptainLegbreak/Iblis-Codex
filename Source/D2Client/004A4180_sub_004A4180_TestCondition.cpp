extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2BitBufferStrc;

struct Unicode
{
    unsigned short wChar;
    Unicode();                                                                                              // 0x0042F530
};

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

struct D2QuestTextsStrc
{
    unsigned short awIds[64];
};

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

struct D2QuestPageRangeStrc
{
    int nFirst;
    int nLast;
};

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD
int __cdecl sub_00408F20_HasExpansionMpq();                                                                 // 0x00408F20
int __cdecl sub_0044DCC0();                                                                                 // 0x0044DCC0
void* __fastcall sub_004788B0_LoadCellFile(const char* szPath, int nFlags);                                 // 0x004788B0
D2BitBufferStrc* __cdecl sub_004B32D0();                                                           // 0x004B32D0
D2BitBufferStrc* __cdecl sub_004B32E0_GetQuestHistory();                                                    // 0x004B32E0
int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex);                                           // 0x004B92E0
const unsigned short* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                       // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
unsigned short* __fastcall sub_00526700(unsigned short* pDest, const Unicode* pSource);                   // 0x00526700
unsigned short* __fastcall sub_00526790(unsigned short* pDest, const unsigned short* pSource, int nCount); // 0x00526790
unsigned short* __fastcall sub_005267E0(unsigned short* pDest, const unsigned short* pSource);            // 0x005267E0
int __fastcall sub_00526800(const unsigned short* pString);                                               // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, unsigned short* pBuffer, const unsigned short* pFormat, ...);  // 0x005269D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

extern const char gszFormatD_006D57BC[];                                                                    // 0x006D57BC
extern const char gszDataGlobal_006D4118[];                                                                 // 0x006D4118
extern const char* gaszQuestCelNames_006DA2C8[];                                                            // 0x006DA2C8
extern D2QuestTextsStrc gtQuestTexts_00723A64;                                                              // 0x00723A64
extern D2QuestTextsStrc gtQuestTexts_00723C64;                                                              // 0x00723C64
extern D2QuestTextsStrc gtQuestTexts_00723D24;                                                              // 0x00723D24
extern D2QuestPageRangeStrc gaQuestPageRanges_00723F08[];                                                   // 0x00723F08
extern D2QuestTableStrc gaQuestTable_00723F30[];                                                            // 0x00723F30
extern int gdwGlobal_007A0610;                                                                              // 0x007A0610
extern int ganPageSelection_007BF280[5];                                                                    // 0x007BF280
extern int gnGlobal_007BF2A4;                                                                               // 0x007BF2A4
extern int gnGlobal_007BF2AC;                                                                               // 0x007BF2AC
extern int gnIndex_007BF2B9;                                                                                // 0x007BF2B9
extern int ganPageSelection_007BF2BD[];                                                                     // 0x007BF2BD
extern void* gapCelFiles_007BF2E1[];                                                                        // 0x007BF2E1
extern unsigned char gabQuestFlagsA_007BF356[];                                                             // 0x007BF356
extern unsigned char gabQuestFlagsB_007BF380[];                                                             // 0x007BF380

static void sub_004A1950_BuildQuestText(D2QuestTextMsgStrc* pMsg)
{
    pMsg->wTitle = 0xE8C;
    pMsg->wDesc = 0xE8C;
    pMsg->wszText[0] = 0;
    pMsg->f_263 = 0;
    pMsg->bValid = 0;

    int nIndex = -1;
    for (int i = 0; i < 41; ++i)
    {
        if (gaQuestTable_00723F30[i].nQuestId == pMsg->nQuestId)
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

    pMsg->nCelId = gaQuestTable_00723F30[nIndex].nCelId2;
    pMsg->nCelId2 = gaQuestTable_00723F30[nIndex].nCelId;
    D2BitBufferStrc* pQuestInfo = sub_004B32D0();
    D2BitBufferStrc* pQuestHistory = sub_004B32E0_GetQuestHistory();
    unsigned char nStep = gabQuestFlagsA_007BF356[nIndex];
    pMsg->nStep = nStep;
    if (!gaQuestTable_00723F30[nIndex].pTexts)
    {
        pMsg->nState = 2;
        return;
    }

    const int bState0 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 0);
    const int bState13 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 0xD);
    const int bState1 = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 1);
    D2QuestTextsStrc* pTexts = gaQuestTable_00723F30[nIndex].pTexts;

    if (pTexts == &gtQuestTexts_00723D24 && bState1)
    {
        if (!nStep)
        {
            nStep = 4;
        }
    }
    else if (pTexts == &gtQuestTexts_00723A64 && !bState0 && !bState13
        && (QUESTRECORD_GetQuestState(pQuestInfo, 0xC, 0) || QUESTRECORD_GetQuestState(pQuestInfo, 0xC, 0xD)) && nStep == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[7 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 7;
        gabQuestFlagsB_007BF380[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[7 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (pTexts == &gtQuestTexts_00723A64 && !bState0 && !bState13 && QUESTRECORD_GetQuestState(pQuestInfo, 0xE, 3) == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[5 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 5;
        gabQuestFlagsB_007BF380[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[5 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (pTexts == &gtQuestTexts_00723A64 && !bState0 && !bState13 && QUESTRECORD_GetQuestState(pQuestInfo, 0xE, 4) == 1)
    {
        pMsg->wTitle = pTexts->awIds[0];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pTexts->awIds[6 * 2 + 1]), 300);
        pMsg->wszText[300 - 1] = 0;
        nStep = 6;
        gabQuestFlagsB_007BF380[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[6 * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
        return;
    }
    else if (bState13 && !bState0 && pTexts->awIds[2] != 0xFFFF && bState1 && pTexts != &gtQuestTexts_00723C64)
    {
        nStep = (unsigned char)pTexts->awIds[2] + 1;
        pMsg->wTitle = pTexts->awIds[0];
        const unsigned short* pIds = &pTexts->awIds[nStep * 2];
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(pIds[1]), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->f_263 = nStep != gabQuestFlagsB_007BF380[nIndex];
        const unsigned short wDesc = pIds[2];
        gabQuestFlagsB_007BF380[nIndex] = nStep;
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
        gabQuestFlagsB_007BF380[nIndex] = nStep;
        pMsg->bValid = 1;
        pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 0xC) != 0;
        return;
    }
    else if (bState1 && QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 0xF))
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
        gabQuestFlagsB_007BF380[nIndex] = nNewStep;
        pMsg->bValid = 1;
        pMsg->nState = (pMsg->nQuestId != 0x1B) ? 3 : 1;
        return;
    }

    if (nStep)
    {
        if (!gaQuestTable_00723F30[nIndex].pTexts)
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
                if (pTexts->awIds[0] == 0xE82 && gnGlobal_007BF2A4 > 1)
                {
                    Unicode wszNumber[10];
                    char szNumber[10];
                    sprintf(szNumber, gszFormatD_006D57BC, pTexts->awIds[0] == 0xE82 ? gnGlobal_007BF2A4 : 0);
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
            if (nStep != gabQuestFlagsB_007BF380[nIndex])
            {
                pMsg->f_263 = 1;
            }
            gabQuestFlagsB_007BF380[nIndex] = nStep;
            pMsg->wDesc = pTexts->awIds[nStepIndex * 2 + 2];
            pMsg->nState = 3;
            pMsg->bValid = 1;
            pMsg->nStep = nStep;
            if (nStep == 0xD)
            {
                pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 0xC) != 0;
            }
            return;
        }

        pMsg->wTitle = pTexts->awIds[0];
        int nString;
        if ((!bState0 && !bState13 && !QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 1)
            && pQuestHistory && QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable_00723F30[nIndex].nQuestId, 0xD) && pMsg->nQuestId != 0x13)
            || QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 0xE))
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
            if (!gnGlobal_007BF2AC)
            {
                sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(0xE91), 300);
            }
            else
            {
                sub_005269D0(300, pMsg->wszText, D2LANG_GetStringFromTblIndex(0x5860), gnGlobal_007BF2AC);
            }
        }

        pMsg->wszText[300 - 1] = 0;
        pMsg->f_263 = 0;
        if (nStep != gabQuestFlagsB_007BF380[nIndex] && gaQuestTable_00723F30[nIndex].pTexts)
        {
            pMsg->f_263 = 1;
        }
        gabQuestFlagsB_007BF380[nIndex] = nStep;
        pMsg->wDesc = pTexts->awIds[nStep * 2 + 2];
        pMsg->nState = 3;
        pMsg->bValid = 1;
        if (nStep == 0xD)
        {
            pMsg->nState = QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 0xC) != 0;
        }
        return;
    }

    unsigned short nString;
    if (QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable_00723F30[nIndex].nQuestId, 0xD))
    {
        if (pMsg->nQuestId == 0x15 && !QUESTRECORD_GetQuestState(pQuestInfo, 0x15, 0) && QUESTRECORD_GetQuestState(pQuestInfo, 0x15, 4) == 1)
        {
            nString = 0x3DD;
        }
        else
        {
            if (bState13 || QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 1))
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
        if (!QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable_00723F30[nIndex].nQuestId, 0xF) || bState13
            || QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 1))
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

void __stdcall sub_004A3220_LoadQuestPage(int nPage, int bReset)
{
    int nCount = 0;
    int nFound = 0;
    int nFirst = -1;
    char szPath[260];

    gnIndex_007BF2B9 = -1;
    if ((!sub_00408F20_HasExpansionMpq() || !sub_0044DCC0()) && nPage == 4)
    {
        return;
    }

    for (int i = gaQuestPageRanges_00723F08[nPage].nFirst; i <= gaQuestPageRanges_00723F08[nPage].nLast; ++i)
    {
        if (!gapCelFiles_007BF2E1[i])
        {
            sprintf(szPath, "%s\\ui\\menu\\%s", gszDataGlobal_006D4118, gaszQuestCelNames_006DA2C8[i]);
            gapCelFiles_007BF2E1[i] = sub_004788B0_LoadCellFile(szPath, 0);
        }
    }

    if (ganPageSelection_007BF280[nPage] != -1)
    {
        gnIndex_007BF2B9 = ganPageSelection_007BF280[nPage];
        if (bReset)
        {
            ganPageSelection_007BF280[4] = -1;
            ganPageSelection_007BF280[3] = -1;
            ganPageSelection_007BF280[2] = -1;
            ganPageSelection_007BF280[1] = -1;
            ganPageSelection_007BF280[0] = -1;
        }
        return;
    }

    for (; nCount < 41; ++nCount)
    {
        if (gaQuestTable_00723F30[nCount].nPage == nPage && gaQuestTable_00723F30[nCount].bEnabled
            && gaQuestTable_00723F30[nCount].nCelId < 0x1B && gapCelFiles_007BF2E1[gaQuestTable_00723F30[nCount].nCelId])
        {
            D2QuestTextMsgStrc tMsg;
            for (int k = 0; k < 300; ++k)
            {
                tMsg.wszText[k] = 0;
            }
            tMsg.nQuestId = gaQuestTable_00723F30[nCount].nQuestId;
            sub_004A1950_BuildQuestText(&tMsg);
            if (tMsg.f_263 || !tMsg.nState)
            {
                nCount = 41;
                gnIndex_007BF2B9 = tMsg.nCelId;
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

    if (nFound && gnIndex_007BF2B9 == -1)
    {
        int nSelection = ganPageSelection_007BF2BD[nPage];
        if (nSelection != -1 || (nSelection = nFirst) != -1)
        {
            gnIndex_007BF2B9 = nSelection;
        }
    }

    if (bReset)
    {
        ganPageSelection_007BF280[4] = -1;
        ganPageSelection_007BF280[3] = -1;
        ganPageSelection_007BF280[2] = -1;
        ganPageSelection_007BF280[1] = -1;
        ganPageSelection_007BF280[0] = -1;
    }
}

// 0x004A4180
int __fastcall sub_004A4180_TestCondition(int nCondition)
{
    if (!sub_004B92E0_GetTableByte(0, nCondition))
    {
        return 0;
    }

    for (unsigned int i = 0; i < 41; ++i)
    {
        if (gaQuestTable_00723F30[i].nCondition == nCondition)
        {
            const int nQuestId = gaQuestTable_00723F30[i].nQuestId;
            if (nQuestId == 0x2A)
            {
                break;
            }

            if (!sub_004B32E0_GetQuestHistory() || QUESTRECORD_GetQuestState(sub_004B32E0_GetQuestHistory(), nQuestId, 0xD))
            {
                break;
            }

            if (!sub_004B32D0() || QUESTRECORD_GetQuestState(sub_004B32D0(), nQuestId, 1)
                || QUESTRECORD_GetQuestState(sub_004B32D0(), nQuestId, 0)
                || QUESTRECORD_GetQuestState(sub_004B32D0(), nQuestId, 0xE))
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
                sub_004A1950_BuildQuestText(&tMsg);
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
