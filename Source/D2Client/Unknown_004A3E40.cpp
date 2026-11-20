#include "D2Client.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_PLAYER 0
#define STAT_LEVEL 12
struct D2QuestPanelEntryStrc;
struct D2QuestSlotRectStrc;
struct Unicode;
struct D2QuestTextMsgStrc;
struct D2QuestTextsStrc;
struct D2QuestTableStrc;
struct D2QuestPageRangeStrc;
struct D2CharStatsTxt;
struct D2MonStatsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct SMSGHANDLER_PARAMS
{
    void* hWindow;
    unsigned int nMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int unk0x10;
    unsigned int unk0x14;
    int bUseResult;
    int lResult;
};

#pragma pack(push, 1)
struct D2QuestPanelEntryStrc
{
    int nQuestId;
    char unk0x004[0x25E - 0x004];
    unsigned short wTextId;
    unsigned char nSlot;
    char unk0x261[0x263 - 0x261];
    unsigned char bEnabled;
    char unk0x264[0x265 - 0x264];
    int bDone;
    char unk0x269[0x26A - 0x269];
};

#pragma pack(pop)

D2BitBufferStrc* __cdecl sub_004B32D0(); // 0x004B32D0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310


D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __cdecl D2GFX_GetResolutionMode(); // 0x004F5160
void __stdcall sub_004A3220(int nPage, int nArg); // 0x004A3220
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004A3FE0(int nMode); // 0x004A3FE0
void __cdecl sub_0044DA70(); // 0x0044DA70
int __cdecl sub_0044DCC0(); // 0x0044DCC0
void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound); // 0x004A1320
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0
int __fastcall sub_004A27B0_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2QuestSlotRectStrc gaQuestSlots_00723EB0[]; // 0x00723EB0
extern int gnQuestCount_007BF2A0; // 0x007BF2A0
extern char gbGlobal_007BF2B0; // 0x007BF2B0
extern char gbGlobal_007BF2B2; // 0x007BF2B2
extern char gbGlobal_007BF2B3; // 0x007BF2B3
extern char gbGlobal_007BF2B4; // 0x007BF2B4
extern D2QuestPanelEntryStrc gaQuestEntries_007BF3AA[]; // 0x007BF3AA
extern char gbGlobal_007C025D; // 0x007C025D
extern char gbGlobal_007C025E; // 0x007C025E
extern char gbGlobal_007C025F; // 0x007C025F
extern char gbGlobal_007C0260; // 0x007C0260

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

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
void* __fastcall sub_004788B0_LoadCellFile(const char* szPath, int nFlags); // 0x004788B0
int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex); // 0x004B92E0
const unsigned short* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
unsigned short* __fastcall sub_00526700(unsigned short* pDest, const Unicode* pSource); // 0x00526700
unsigned short* __fastcall sub_00526790(unsigned short* pDest, const unsigned short* pSource, int nCount); // 0x00526790
unsigned short* __fastcall sub_005267E0(unsigned short* pDest, const unsigned short* pSource); // 0x005267E0
int __fastcall sub_00526800(const unsigned short* pString); // 0x00526800
void __cdecl sub_005269D0(int nBufferSize, unsigned short* pBuffer, const unsigned short* pFormat, ...); // 0x005269D0
extern const char gszFormatD_006D57BC[]; // 0x006D57BC
extern D2QuestTextsStrc gtQuestTexts_00723A64; // 0x00723A64
extern D2QuestTextsStrc gtQuestTexts_00723C64; // 0x00723C64
extern D2QuestTextsStrc gtQuestTexts_00723D24; // 0x00723D24
extern D2QuestPageRangeStrc gaQuestPageRanges_00723F08[]; // 0x00723F08
extern D2QuestTableStrc gaQuestTable_00723F30[]; // 0x00723F30
extern int ganPageSelection_007BF280[5]; // 0x007BF280
extern int gnGlobal_007BF2A4; // 0x007BF2A4
extern int gnGlobal_007BF2AC; // 0x007BF2AC
extern void* gapCelFiles_007BF2E1[]; // 0x007BF2E1
extern unsigned char gabQuestFlagsA_007BF356[]; // 0x007BF356
extern unsigned char gabQuestFlagsB_007BF380[]; // 0x007BF380

#pragma pack(push, 2)
struct D2ClientListEntryStrc
{
    int nKey;
    unsigned short nString;
    unsigned char unk0x06[4];
};

#pragma pack(pop)
extern D2ClientListEntryStrc gaEntries_00724268[]; // 0x00724268
extern D2ClientListEntryStrc gaEntries_00724468[]; // 0x00724468
extern int gnAutomapHeight_007A521C; // 0x007A521C

int __stdcall ITEMS_CheckItemTypeId(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
static __declspec(noinline) int sub_004A70C0_GetWieldedTypeStatMax(D2UnitStrc* pUnit);

struct D2CharStatsTxt
{
    char unk0x00[0x3C];
    int dwToHitFactor;
    char unk0x40[0x84];
};

struct D2MonStatsTxt
{
    char unk0x00[0x4C];
    unsigned char nAlign;
    char unk0x4D[0x5D];
    short nLevel[3];
    char unk0xB0[0xF8];
};

struct D2DataTablesStrc
{
    char unk0x00[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    char unk0xA7C[4];
    int nMonStatsTxtRecordCount;
    char unk0xA84[0x140];
    D2CharStatsTxt* pCharStatsTxt;
    int nCharStatsTxtRecordCount;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned char __cdecl sub_0044DCD0_GetDifficulty(); // 0x0044DCD0
int __cdecl sub_00466DC0(); // 0x00466DC0
int __cdecl sub_0044DCA0_GetGameType(); // 0x0044DCA0
static __declspec(noinline) int sub_004A7300_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate);

// 0x004A2220
static void sub_004A2220_SetQuestPage(int nPageArg)
{
    int nPage = nPageArg;
    if (nPage >= 5)
    {
        nPage = 0;
    }
    switch (nPage)
    {
    case 4:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x1A, 0)) nPage = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0x17, 0)) nPage = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 0xF, 0)) nPage = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(sub_004B32D0(), 7, 0)) nPage = 0;
    }
    gnIndex_007BF2B9 = -1;
    gnIndex_007BF2B5 = -1;
    for (int i = 0; i < 6; ++i)
    {
        ganGlobal_007C023D[i] = ganGlobal_007C0225[i] = 0;
    }
    gnGlobal_007C0255 = nPage;
}

// build: context sub_004A2300_UpdateQuestPage
void __cdecl sub_004A2300_UpdateQuestPage()
{
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (pPlayer)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
        if (pRoom)
        {
            int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (nLevelId)
            {
                sub_004A2220_SetQuestPage(DRLG_GetActNoFromLevelId(nLevelId));
                return;
            }
        }
    }
    sub_004A2220_SetQuestPage(0);
}

// build: context sub_004A2390_ResetQuestSelection
static void sub_004A2390_ResetQuestSelection()
{
    gbGlobal_007BF2B1 = 0;
    gbGlobal_007BF2B2 = 0;
    gbGlobal_007BF2B0 = 0;
    gnIndex_007BF2B5 = -1;
    gbGlobal_007BF2B4 = 0;
    gbGlobal_007C025D = 0;
    gbGlobal_007C025E = 0;
    gbGlobal_007C025F = 0;
    gbGlobal_007C0260 = 0;
}

// 0x004A2610
static unsigned char sub_004A2610_HitTestButtonA(int nX, int nY)
{
    if (nX >= 0xE6 && nX <= 0xE6 + 0x1D && nY >= 0x187 && nY <= 0x187 + 0x20)
    {
        return 1;
    }
    return 0;
}

// 0x004A2630
static int sub_004A2630_GetSlotAtPoint(int nX, int nY)
{
    int nCount = gnQuestCount_007BF2A0;
    D2_ASSERT((unsigned int)nCount <= 6, 0x738);
    for (int i = 0; i < nCount; ++i)
    {
        if (nX >= gaQuestSlots_00723EB0[i].nX && nX < gaQuestSlots_00723EB0[i].nX + 0x38 && nY >= gaQuestSlots_00723EB0[i].nY && nY < gaQuestSlots_00723EB0[i].nY + 0x34)
        {
            return i;
        }
    }
    return -1;
}

// 0x004A2690
static unsigned char sub_004A2690_HitTestButtonB(int nX, int nY)
{
    if (nX >= 0x116 && nX <= 0x116 + 0x23 && nY >= 0x188 && nY <= 0x188 + 0x21)
    {
        return 1;
    }
    return 0;
}

// 0x004A26F0
static int __stdcall sub_004A26F0_GetTabAtPoint(int nY, int nX)
{
    if (nY < 0 || nY > 0x1B || nX < 0 || nX > 0x13F)
    {
        return -1;
    }
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        int i = 0;
        for (int n = 0; n < 0x140; n += 0x40, ++i)
        {
            if (nX >= n && nX <= n + 0x40) return i;
        }
        return -1;
    }
    int i = 0;
    for (int n = 0; n < 0x140; n += 0x50, ++i)
    {
        if (nX >= n && nX <= n + 0x50) return i;
    }
    return -1;
}

// 0x004A27D0
static void sub_004A27D0_OpenQuestDescription(int nSlot)
{
    int nIndex = -1;
    for (int i = 0; i < gnQuestCount_007BF2A0; ++i)
    {
        if (gaQuestEntries_007BF3AA[i].nSlot == nSlot)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex == -1)
    {
        return;
    }
    unsigned short wTextId = gaQuestEntries_007BF3AA[nIndex].wTextId;
    if (wTextId == 0xE8C || wTextId == 0xE8D)
    {
        return;
    }
    sub_004A1320_OpenTextPanel(wTextId, 1, 0);
    sub_0049E7E0_SetTextCallback(sub_004A27B0_CloseQuestText, 0);
    gbGlobal_007BF2B3 = 1;
}

// build: context sub_004A3E40_ClickSlot_Inline
static __forceinline void sub_004A3E40_ClickSlot_Inline(int nIndex)
{
    for (int i = 0; i < gnQuestCount_007BF2A0; ++i)
    {
        if (nIndex == gaQuestEntries_007BF3AA[i].nSlot && gaQuestEntries_007BF3AA[i].bEnabled)
        {
            gbGlobal_007BF2B1 = 1;
            gnIndex_007BF2B5 = nIndex;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
    }
}

// 0x004A3E40
void __stdcall sub_004A3E40_OnLeftButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam);
    int nY = D2_HIWORD(pMsg->lParam);
    if (sub_00483350())
    {
        return;
    }
    if (nX > gnGlobal_0071146C / 2)
    {
        return;
    }
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (nY > gnGlobal_00711470 - 0x2F) return;
    }
    else
    {
        if (nY > gnGlobal_00711470 - 0x31) return;
    }
    nX -= gnGlobal_007A2858;
    nY += gnGlobal_007A285C;
    int nIndex;
    if (!gbGlobal_007BF2B3)
    {
        nIndex = sub_004A26F0_GetTabAtPoint(nY, nX);
        if (nIndex != -1)
        {
            if (nIndex < 5 && nIndex != gnGlobal_007C0255 && ((sub_00408F20_HasExpansionMpq() && sub_0044DCC0()) || nIndex != 4))
            {
                sub_004A2760(gnGlobal_007C0255);
                sub_004A2220_SetQuestPage(nIndex);
                sub_004A3220(gnGlobal_007C0255, 1);
                sub_004A2390_ResetQuestSelection();
            }
        }
        else
        {
            nIndex = sub_004A2630_GetSlotAtPoint(nX, nY);
            if (nIndex != -1 && nIndex < gnQuestCount_007BF2A0)
            {
                sub_004A3E40_ClickSlot_Inline(nIndex);
                pMsg->bUseResult = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
            else
            {
                if (sub_004A2690_HitTestButtonB(nX, nY))
                {
                    gbGlobal_007BF2B2 = 1;
                    sub_004B9A00(4, 0, 0, 0, 0);
                }
                else if (sub_004A2610_HitTestButtonA(nX, nY))
                {
                    gbGlobal_007BF2B4 = 1;
                    sub_004B9A00(4, 0, 0, 0, 0);
                }
            }
        }
    }
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x004A42A0
void __stdcall sub_004A42A0_OnLeftButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam) - gnGlobal_007A2858;
    int nY = D2_HIWORD(pMsg->lParam) + gnGlobal_007A285C;
    if (gbGlobal_007BF2B2)
    {
        if (sub_004A2690_HitTestButtonB(nX, nY)) sub_004A3FE0(0);
    }
    else if (!gbGlobal_007BF2B3)
    {
        if (gnIndex_007BF2B5 != -1)
        {
            int nSlot = sub_004A2630_GetSlotAtPoint(nX, nY);
            if (nSlot == gnIndex_007BF2B5)
            {
                ganPageSelection_007BF2BD[gnGlobal_007C0255] = nSlot;
                gnIndex_007BF2B9 = nSlot;
            }
        }
        else if (gbGlobal_007BF2B4 == 1)
        {
            if (sub_004A2610_HitTestButtonA(nX, nY) && gnIndex_007BF2B9 != -1)
            {
                sub_004A27D0_OpenQuestDescription(gnIndex_007BF2B9);
            }
        }
    }
    D2_RESET_QUEST_SELECTION();
    if (D2_LOWORD(pMsg->lParam) > gnGlobal_0071146C / 2) return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        if ((int)(pMsg->lParam >> 16) > gnGlobal_00711470 - 0x2F) return;
    }
    else
    {
        if ((int)(pMsg->lParam >> 16) > gnGlobal_00711470 - 0x31) return;
    }
    sub_0044DA70();
    pMsg->bUseResult = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

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

int gnEntryCount_007C0274; // 0x007C0274

int gnThumbScale_007C0278; // 0x007C0278

int gnThumbRange_007C027C; // 0x007C027C

static __forceinline int sub_KEYCFG_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_KEYCFG_Rows()
{
    return ((sub_KEYCFG_ListTop() + 0x16C) - (sub_KEYCFG_ListTop() + 0x28)) / 0x12;
}

static __forceinline int sub_KEYCFG_VisibleLines()
{
    return sub_KEYCFG_Rows() - 3;
}

static __forceinline int sub_KEYCFG_TrackCels()
{
    return (sub_KEYCFG_Rows() * 0x12 - 0x4E) / 0x0C + 1;
}

// 0x004A43E0
void __cdecl sub_004A43E0()
{
    if (sub_0044DCC0())
    {
        gpListEntries_00724264 = gaEntries_00724468;
        gnEntryCount_007C0274 = 62;
        gnThumbScale_007C0278 = sub_KEYCFG_TrackCels() * sub_KEYCFG_VisibleLines() / gnEntryCount_007C0274;
        gnThumbRange_007C027C = gnEntryCount_007C0274 - sub_KEYCFG_VisibleLines();
    }
    else
    {
        gpListEntries_00724264 = gaEntries_00724268;
        gnEntryCount_007C0274 = 51;
        gnThumbScale_007C0278 = sub_KEYCFG_TrackCels() * sub_KEYCFG_VisibleLines() / gnEntryCount_007C0274;
        gnThumbRange_007C027C = gnEntryCount_007C0274 - sub_KEYCFG_VisibleLines();
    }
}

#include "gen/data/Source/D2Client/Unknown_004A3E40.inc"

// 0x004A6630
int __fastcall sub_004A6630_IsInRightPanelButton(int nMode, int nX, int nY)
{
    switch (nMode)
    {
    case 1:
        if (nX > (gnGlobal_0071146C - gnGlobal_0071146C / 2) - 73 && nX < (gnGlobal_0071146C - gnGlobal_0071146C / 2) - 40 && nY > gnGlobal_00711470 - 138 && nY < gnGlobal_00711470 - 102)
            return 1;
        return 0;
    default:
        if (nX > gnGlobal_0071146C - 73 && nX < gnGlobal_0071146C - 40 && nY > gnGlobal_00711470 - 138 && nY < gnGlobal_00711470 - 102)
            return 1;
        return 0;
    }
}

// 0x004A70C0
static int sub_004A70C0_GetWieldedTypeStatMax(D2UnitStrc* pUnit)
{
    int i;
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightItem = 0;
    D2UnitStrc* pLeftItem = 0;
    if (pInventory)
    {
        pRightItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        pLeftItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    }

    D2StatStrc aStats[0x20];
    const int nCount = STATLIST_CopyStats(pUnit, 0x15C, aStats, 0x20);
    int nBest = 0;
    for (i = 0; i < nCount; ++i)
    {
        const int nItemType = aStats[i].nLayer;
        const int nValue = aStats[i].nValue;
        if (nItemType <= 0)
        {
            nBest = nValue;
        }
        else if (pLeftItem && ITEMS_CheckItemTypeId(pLeftItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
        else if (pRightItem && ITEMS_CheckItemTypeId(pRightItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
    }

    return nBest;
}

int __fastcall sub_004A70C0_Emit(int nArg, D2UnitStrc* pUnit)
{
    int nValue = sub_004A70C0_GetWieldedTypeStatMax(pUnit);
    return nValue > 0 ? nValue : nArg;
}

__forceinline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static __forceinline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

static int sub_004A7300_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord_Inl(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            nAttackRate += pCharStatsTxtRecord->dwToHitFactor;
        }
    }

    return nAttackRate;
}

// 0x004A7340
int __stdcall sub_004A7340_GetPercentA(int nAttackRate)
{
    if (!nAttackRate)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = sub_00463DD0();
    int nPercent = 100;
    const int nDifficulty = sub_0044DCD0_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 398);

    const int nMonsterId = sub_00466DC0();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    D2_ASSERT(pMonStatsTxtRecord, 403);

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, sub_0044DCA0_GetGameType(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 2, &monStatsInit);
    int nDefense = monStatsInit.nAC;
    if (pMonStatsTxtRecord->nAlign != 1 && !sub_0044DCC0() && sub_0044DCD0_GetDifficulty())
    {
        nDefense = nDefense * 10 / 12;
    }

    int nToHit = sub_004A7300_AddToHitFactor(pPlayer, nAttackRate);
    if (nDefense < 0)
    {
        nToHit -= nDefense;
        nDefense = 0;
    }

    if (nToHit < 0)
    {
        nDefense -= nToHit;
        nToHit = 0;
    }

    if (nToHit || nDefense)
    {
        nDefense += nToHit;
        nToHit *= 100;
        nPercent = nToHit / nDefense;
    }

    const int nPlayerLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nChance = 2 * nPlayerLevel * nPercent / (pMonStatsTxtRecord->nLevel[nDifficulty] + nPlayerLevel);
    if (nChance < 5)
    {
        return 5;
    }
    if (nChance > 95)
    {
        return 95;
    }
    return nChance;
}
