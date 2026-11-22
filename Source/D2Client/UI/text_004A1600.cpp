#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Primitives.h"
#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2DataTbls.h"
#include "D2Txt.h"

#pragma pack(push, 1)

struct D2TextBoxView
{
    char unk0x00[0x16];
    int dwState;
};

#pragma pack(pop)

typedef int(__fastcall* PANELCLOSEFN)(void* pArg, int a2, int a3);

extern D2TextBoxView* gpTextBox_007BF0A4; // 0x007BF0A4

extern int gnPanelOpen_007BF1BC; // 0x007BF1BC

extern int gnPending_007BF1C4; // 0x007BF1C4

extern void* gpHint_007BF202; // 0x007BF202

extern int gbHintActive_007BF20A; // 0x007BF20A

extern void* gpHint_007BF24B; // 0x007BF24B

extern PANELCLOSEFN gpfnClose_007BF258; // 0x007BF258

extern void* gpCloseArg_007BF25C; // 0x007BF25C

extern int gbHandlers_007BF27C; // 0x007BF27C

extern char gHandlerTable_00722600[]; // 0x00722600

int __cdecl sub_00514CC0(); // 0x00514CC0

static __declspec(noinline) int __cdecl sub_0049D5A0_UpdateTextBox(D2TextBoxView* pTextBox);

void __stdcall TEXT_FreeTextBox(D2TextBoxView* pTextBox); // 0x0049D410

void __fastcall sub_00467430_SetSelectionRect(void* pRect); // 0x00467430

void __cdecl TEXT_ResetTextBox(); // 0x0049F960

void __fastcall NPCMENU_CancelNpcAndFlag(void* pHint); // 0x004B3D10

void __cdecl UI_StartUIVarDelay(); // 0x00453AE0

void* __stdcall sub_004F59A0(); // 0x004F59A0

void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, void* pTable, int nCount); // 0x00451E10

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2MessageListStrc;

struct D2HoverTextPacketStrc;

struct Unicode;

struct D2QuestTextMsgStrc;

struct D2QuestTextsStrc;

struct D2QuestTableStrc;

struct D2QuestPageRangeStrc;

struct D2QuestPosStrc;

struct D2QuestLogStateStrc;

struct D2QuestPanelEntryStrc;

struct D2QuestSlotRectStrc;

#pragma pack(push, 1)

struct D2HoverTextPacketStrc
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned int dwUnitId;
    unsigned char nArg;
    unsigned char unk0x07;
    unsigned char nMode;
    unsigned char unk0x09;
    unsigned short wStringId;
};

#pragma pack(pop)

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound);

void __fastcall sub_004A1510_ShowTextBox(unsigned short nStringId);

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0

D2TextHeaderStrc* __stdcall TEXT_AllocTextHeader(void* pMemPool); // 0x00661240

void __stdcall TEXT_CreateTextHeaderFromMessageList(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMessageList); // 0x00661510

void __stdcall TEXT_SortTextNodeListByStringId(D2TextHeaderStrc* pTextHeader); // 0x006616E0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);

extern int gnGameFrame_007BF20E; // 0x007BF20E

extern "C" const char gszFormatD_006D57BC[]; // 0x006D57BC

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0

int __stdcall INV_GetTableByte(int nUnused, int nIndex); // 0x004B92E0

const unsigned short* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

unsigned short* __fastcall sub_00526700(unsigned short* pDest, const Unicode* pSource); // 0x00526700

unsigned short* __fastcall sub_00526790(unsigned short* pDest, const unsigned short* pSource, int nCount); // 0x00526790

unsigned short* __fastcall sub_005267E0(unsigned short* pDest, const unsigned short* pSource); // 0x005267E0

int __fastcall sub_00526800(const unsigned short* pString); // 0x00526800

void __cdecl sub_005269D0(int nBufferSize, unsigned short* pBuffer, const unsigned short* pFormat, ...); // 0x005269D0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

extern D2QuestTextsStrc gtQuestTexts_00723A64; // 0x00723A64

extern D2QuestTextsStrc gtQuestTexts_00723C64; // 0x00723C64

extern D2QuestTextsStrc gtQuestTexts_00723D24; // 0x00723D24

extern D2QuestPageRangeStrc gaQuestPageRanges_00723F08[]; // 0x00723F08

extern D2QuestTableStrc gaQuestTable_00723F30[]; // 0x00723F30

int ganPageSelection_007BF280[5]; // 0x007BF280

extern void* gapCelFiles_007BF2E1[]; // 0x007BF2E1

extern unsigned char gabQuestFlagsA_007BF356[]; // 0x007BF356

void __stdcall TEXT_LoadQuestPage(int nPage, int bReset); // 0x004A3220

static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg); // 0x004A1950

struct T0044CB60
{
    unsigned short* pText;
    T0044CB60* pNext;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __cdecl sub_00463DF0(); // 0x00463DF0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0

void __cdecl sub_004A23D0_LoadPanelCels(); // 0x004A23D0

int __stdcall sub_004A26B0_OpenPanel(int nArg); // 0x004A26B0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10121_GetTextWidth(const unsigned short* wszText); // 0x00501820

void __fastcall sub_00502280_SetPopUpText(const unsigned short* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void __fastcall D2Win_10117_DrawText(const unsigned short* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

T0044CB60* __fastcall sub_00502970_SplitText(unsigned short* pText, unsigned int* pLineCount, int nWidth); // 0x00502970

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

extern D2QuestPosStrc gaQuestPos_00723EA8[]; // 0x00723EA8

extern int gnGlobal_007A2858; // 0x007A2858

extern int gnGlobal_007A285C; // 0x007A285C

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

extern D2QuestLogStateStrc gtQuestLog_007BF298; // 0x007BF298

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

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __fastcall TEXT_ToggleQuestLog(int nMode); // 0x004A3FE0

void __cdecl sub_0044DA70(); // 0x0044DA70

void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

int __fastcall TEXT_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

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

int gnGlobal_007BF2A4; // 0x007BF2A4

int gnGlobal_007BF2AC; // 0x007BF2AC

unsigned char gabQuestFlagsB_007BF380[41]; // 0x007BF380

unsigned short gwTextPanelClassId_007BF234; // 0x007BF234

D2TextHeaderStrc* gpTextHeader_007BF250; // 0x007BF250

#define UNIT_PLAYER 0

#define STAT_LEVEL 12

struct D2CharStatsTxt;

struct D2MonStatsTxt;

#pragma pack(push, 1)

#pragma pack(pop)

#pragma pack(push, 1)

#pragma pack(pop)

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

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

static int sub_004A70C0_GetWieldedTypeStatMax(D2UnitStrc* pUnit);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __cdecl sub_00466DC0(); // 0x00466DC0

int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

static int sub_004A7300_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate);

static void sub_004A2220_SetQuestPage(int nPageArg);

int __fastcall TEXT_TestQuestCondition(int nCondition);

void __stdcall TEXT_QuestLButtonDownMsg(SMSGHANDLER_PARAMS* pMsg);

int gnEntryCount_007C0274; // 0x007C0274

int gnThumbScale_007C0278; // 0x007C0278

int gnThumbRange_007C027C; // 0x007C027C

// build: context sub_0049D5A0_UpdateTextBox
// calling-convention shim (not game code)
static int __cdecl sub_0049D5A0_UpdateTextBox(D2TextBoxView* pTextBox)
{
    void* pA = sub_004F59A0();
    void* pB = sub_004F59A0();
    sub_00467430_SetSelectionRect(pA);
    sub_00467430_SetSelectionRect(pB);
    sub_00467430_SetSelectionRect(pA);
    sub_00467430_SetSelectionRect(pB);
    pTextBox->dwState = 1;
    return pTextBox->unk0x00[0];
}

// 0x004A0770
static int __stdcall TEXT_AdvanceTextBox(int bIgnore, D2TextBoxView* pTextBox)
{
    if (bIgnore)
    {
        pTextBox->dwState = 2;
        return 0;
    }

    const int bBusy = sub_00514CC0();
    if (!gpHint_007BF24B || sub_004B95C0_IsHintPlaying(gpHint_007BF24B) || !bBusy)
    {
        gpHint_007BF24B = 0;
        if (sub_0049D5A0_UpdateTextBox(pTextBox))
        {
            gnPanelOpen_007BF1BC = 1;
            if (!gbHintActive_007BF20A && gpTextBox_007BF0A4)
            {
                TEXT_FreeTextBox(gpTextBox_007BF0A4);
                gpTextBox_007BF0A4 = 0;
                sub_00467430_SetSelectionRect(0);
            }

            TEXT_ResetTextBox();
            if (gpfnClose_007BF258)
            {
                return gpfnClose_007BF258(gpCloseArg_007BF25C, 0, 0);
            }

            if (gnPending_007BF1C4 == 1)
            {
                gnPending_007BF1C4 = 0;
            }
            else if (gbHintActive_007BF20A)
            {
                NPCMENU_CancelNpcAndFlag(gpHint_007BF202);
            }

            UI_StartUIVarDelay();
            gbHintActive_007BF20A = 0;
            sub_00467430_SetSelectionRect(0);
            if (gbHandlers_007BF27C == 1)
            {
                gbHandlers_007BF27C = 0;
                AUTOMAP_UnregisterHandlerTable(sub_004F59A0(), gHandlerTable_00722600, 7);
            }

            return 0;
        }
    }

    return 1;
}

// build: context sub_004A0770_Shim
// calling-convention shim (not game code)
int __stdcall sub_004A0770_Shim()
{
    D2TextBoxView* pTextBox = gpTextBox_007BF0A4;
    if (pTextBox && (pTextBox->dwState == 1 || pTextBox->dwState == 0))
    {
        return TEXT_AdvanceTextBox(gnPanelOpen_007BF1BC, pTextBox);
    }

    return 0;
}

// build: context sub_00623C60
static inline int sub_00623C60(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x004A1600
void __fastcall TEXT_HandleNpcTextPacket(D2HoverTextPacketStrc* pPacket)
{
    if (pPacket->nType == 1)
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, 1);
        if (pUnit && pPacket->nArg == 1 && pPacket->nMode == 3)
        {
            if (pUnit->pHoverText)
            {
                CHAT_FreeHoverMsg(0, pUnit->pHoverText);
            }

            char szText[20];
            sprintf(szText, gszFormatD_006D57BC, pPacket->wStringId);
            pUnit->pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame_007BF20E);
            return;
        }

        if (gpTextHeader_007BF250)
        {
            TEXT_FreeTextHeader(gpTextHeader_007BF250);
        }

        gpTextHeader_007BF250 = TEXT_AllocTextHeader(0);
        TEXT_CreateTextHeaderFromMessageList(gpTextHeader_007BF250, (D2MessageListStrc*)&pPacket->nArg);
        TEXT_SortTextNodeListByStringId(gpTextHeader_007BF250);
    }
    else if (pPacket->nType == 2)
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, 2);
        if (pPacket->nMode == 3)
        {
            sub_004A1510_ShowTextBox(pPacket->wStringId);
            return;
        }

        gwTextPanelClassId_007BF234 = 0;
        gdwGlobal_007BF206 = pPacket->dwUnitId;
        if (pUnit)
        {
            gwTextPanelClassId_007BF234 = sub_00623C60(pUnit);
        }
        sub_004A1320_OpenTextPanel(pPacket->wStringId, 0, 1);
    }
    else
    {
        TEXT_FreeTextHeader(gpTextHeader_007BF250);
        gpTextHeader_007BF250 = 0;
    }
}

static inline int sub_004A1950_GetActNumber(const D2QuestTextsStrc* pTexts)
{
    if (pTexts->awIds[0] == 0xE82)
    {
        return gnGlobal_007BF2A4;
    }
    return 0;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A1950
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
    D2BitBufferStrc* pQuestInfo = MONSTER_GetQuestFlags();
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
        pMsg->wDesc = wDesc;
        pMsg->nState = 3;
        pMsg->bValid = 1;
        pMsg->nStep = nStep;
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
        if (!pTexts)
        {
            pMsg->nState = 2;
            return;
        }

        const unsigned short* pIds = &pTexts->awIds[nNewStep * 2];
        if (pIds[1] == 0xE8D)
        {
            pMsg->nState = 2;
            return;
        }

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
            if (nStepIndex - 1 != 2 && nStepIndex - 1 != 3)
            {
                sub_00526790(pMsg->wszText, pString, 300);
                pMsg->wszText[300 - 1] = 0;
            }
            else if (pTexts->awIds[0] == 0xE82 && gnGlobal_007BF2A4 > 1)
            {
                Unicode wszNumber[10];
                char szNumber[6];
                sprintf(szNumber, gszFormatD_006D57BC, sub_004A1950_GetActNumber(pTexts));
                sub_00526320_ToUnicode(wszNumber, szNumber, 9);
                sub_005267E0(pMsg->wszText, pString);
                D2_ASSERT(sub_00526800(pString) < 0x118, 0x4FA);
                sub_00526700(pMsg->wszText, wszNumber);
            }
            else
            {
                pString = D2LANG_GetStringFromTblIndex(0xE9B);
                sub_00526790(pMsg->wszText, pString, 300);
                pMsg->wszText[300 - 1] = 0;
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
            if ((unsigned short)nString == 0xE8F && !gdwGlobal_007A0610)
            {
                nString = 0xE91;
            }
        }

        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
        if (pTexts->awIds[0] == 0x585E && (unsigned short)nString == 0x5860)
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
        const unsigned short wDesc = pTexts->awIds[nStep * 2 + 2];
        gabQuestFlagsB_007BF380[nIndex] = nStep;
        pMsg->wDesc = wDesc;
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
            goto lPrint;
        }

        if (!bState13 && !QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 1))
        {
            unsigned short nNoneString = 0xE92;
            if (!gdwGlobal_007A0610)
            {
                nNoneString = 0xE91;
            }
            sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nNoneString), 300);
            pMsg->wszText[300 - 1] = 0;
            pMsg->wDesc = 0xE8D;
            pMsg->bValid = 1;
            pMsg->nState = 3;
            return;
        }
    }
    else if (QUESTRECORD_GetQuestState(pQuestHistory, gaQuestTable_00723F30[nIndex].nQuestId, 0xF) && !bState13
        && !QUESTRECORD_GetQuestState(pQuestInfo, gaQuestTable_00723F30[nIndex].nQuestId, 1))
    {
        nString = 0xE92;
        if (!gdwGlobal_007A0610)
        {
            nString = 0xE91;
        }
lPrint:
        sub_00526790(pMsg->wszText, D2LANG_GetStringFromTblIndex(nString), 300);
        pMsg->wszText[300 - 1] = 0;
        pMsg->wDesc = 0xE8D;
        pMsg->bValid = 1;
        pMsg->nState = 3;
        return;
    }

    pMsg->nState = 2;
}

void __cdecl sub_004A34F0_DrawQuestPage(); // 0x004A34F0

struct D2CelFileStrc;

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
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x1A, 0)) nPage = 3;
    case 3:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x17, 0)) nPage = 2;
    case 2:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0xF, 0)) nPage = 1;
    case 1:
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 7, 0)) nPage = 0;
    }
    gnIndex_007BF2B9 = -1;
    gnIndex_007BF2B5 = -1;
    for (int i = 0; i < 6; ++i)
    {
        ganGlobal_007C023D[i] = ganGlobal_007C0225[i] = 0;
    }
    gnGlobal_007C0255 = nPage;
}

void __cdecl sub_004A2300_UpdateQuestPage(); // 0x004A2300

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

static unsigned char sub_004A2610_HitTestButtonA(int nX, int nY)
{
    if (nX >= 0xE6 && nX <= 0xE6 + 0x1D && nY >= 0x187 && nY <= 0x187 + 0x20)
    {
        return 1;
    }
    return 0;
}

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

static unsigned char sub_004A2690_HitTestButtonB(int nX, int nY)
{
    if (nX >= 0x116 && nX <= 0x116 + 0x23 && nY >= 0x188 && nY <= 0x188 + 0x21)
    {
        return 1;
    }
    return 0;
}

static int __stdcall sub_004A26F0_GetTabAtPoint(int nY, int nX)
{
    if (nY < 0 || nY > 0x1B || nX < 0 || nX > 0x13F)
    {
        return -1;
    }
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion() && GAME_IsExpansion())
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
    TEXT_SetTextCallback(TEXT_CloseQuestText, 0);
    gbGlobal_007BF2B3 = 1;
}

void __stdcall TEXT_QuestLButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam) - gnGlobal_007A2858;
    int nY = D2_HIWORD(pMsg->lParam) + gnGlobal_007A285C;
    if (gbGlobal_007BF2B2)
    {
        if (sub_004A2690_HitTestButtonB(nX, nY)) TEXT_ToggleQuestLog(0);
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
    sub_004A2390_ResetQuestSelection();
    if (D2_LOWORD(pMsg->lParam) > gnGlobal_0071146C / 2) return;
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (D2_HIWORD(pMsg->lParam) > gnGlobal_00711470 - 0x2F) return;
    }
    else
    {
        if (D2_HIWORD(pMsg->lParam) > gnGlobal_00711470 - 0x31) return;
    }
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A3220
void __stdcall TEXT_LoadQuestPage(int nPage, int bReset)
{
    int nFirst;
    int nCount = 0;
    int nFound = 0;
    nFirst = -1;
    char szPath[260];

    gnIndex_007BF2B9 = -1;
    if ((!FOG_IsExpansion() || !GAME_IsExpansion()) && nPage == 4)
    {
        return;
    }

    for (int i = gaQuestPageRanges_00723F08[nPage].nFirst; i <= gaQuestPageRanges_00723F08[nPage].nLast; ++i)
    {
        if (!gapCelFiles_007BF2E1[i])
        {
            sprintf(szPath, "%s\\ui\\menu\\%s", gszDataGlobal_006D4118, gaszQuestCelNames_006DA2C8[i]);
            gapCelFiles_007BF2E1[i] = ARCHIVE_LoadClientCellFile(szPath, 0);
        }
    }

    if (ganPageSelection_007BF280[nPage] != -1)
    {
        gnIndex_007BF2B9 = ganPageSelection_007BF280[nPage];
        if (bReset)
        {
            for (int j = 0; j < 5; ++j)
            {
                ganPageSelection_007BF280[j] = -1;
            }
        }
        return;
    }

    D2QuestTableStrc* pQuest = gaQuestTable_00723F30;
    for (;;)
    {
        if (pQuest->nPage == nPage && pQuest->bEnabled && pQuest->nCelId < 0x1B && gapCelFiles_007BF2E1[pQuest->nCelId])
        {
            D2QuestTextMsgStrc tMsg;
            for (int k = 0; k < 300; ++k)
            {
                tMsg.wszText[k] = 0;
            }
            tMsg.nQuestId = pQuest->nQuestId;
            TEXT_BuildQuestText(&tMsg);
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

        if (++nCount >= 41)
        {
            break;
        }
        ++pQuest;
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
        for (int j = 0; j < 5; ++j)
        {
            ganPageSelection_007BF280[j] = -1;
        }
    }
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
void __stdcall TEXT_QuestLButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
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
            if (nIndex < 5 && nIndex != gnGlobal_007C0255 && ((FOG_IsExpansion() && GAME_IsExpansion()) || nIndex != 4))
            {
                sub_004A2760(gnGlobal_007C0255);
                sub_004A2220_SetQuestPage(nIndex);
                TEXT_LoadQuestPage(gnGlobal_007C0255, 1);
                sub_004A2390_ResetQuestSelection();
            }
        }
        else
        {
            nIndex = sub_004A2630_GetSlotAtPoint(nX, nY);
            if (nIndex != -1 && nIndex < gnQuestCount_007BF2A0)
            {
                sub_004A3E40_ClickSlot_Inline(nIndex);
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_BreakHandlerChain(pMsg);
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
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A4180
int __fastcall TEXT_TestQuestCondition(int nCondition)
{
    if (!INV_GetTableByte(0, nCondition))
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

static inline int sub_KEYCFG_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static inline int sub_KEYCFG_Rows()
{
    return ((sub_KEYCFG_ListTop() + 0x16C) - (sub_KEYCFG_ListTop() + 0x28)) / 0x12;
}

static inline int sub_KEYCFG_VisibleLines()
{
    return sub_KEYCFG_Rows() - 3;
}

static inline int sub_KEYCFG_TrackCels()
{
    return (sub_KEYCFG_Rows() * 0x12 - 0x4E) / 0x0C + 1;
}

// 0x004A43E0
void __cdecl TEXT_InitKeyConfigEntries()
{
    if (GAME_IsExpansion())
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

// 0x004A6630
int __fastcall TEXT_IsInRightPanelButton(int nMode, int nX, int nY)
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
    const int nCount = STATLIST_CopyStats(pUnit, STAT_PASSIVE_WEAPONBLOCK, aStats, 0x20);
    int nBest = 0;
    for (i = 0; i < nCount; ++i)
    {
        const int nItemType = aStats[i].nLayer;
        const int nValue = aStats[i].nValue;
        if (nItemType <= 0)
        {
            nBest = nValue;
        }
        else if (pLeftItem && ITEMSIsA(pLeftItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
        else if (pRightItem && ITEMSIsA(pRightItem, nItemType))
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

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nClass)
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
int __stdcall TEXT_GetChanceToHit(int nAttackRate)
{
    if (!nAttackRate)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nPercent = 100;
    const int nDifficulty = GAME_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 398);

    const int nMonsterId = sub_00466DC0();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    D2_ASSERT(pMonStatsTxtRecord, 403);

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 2, &monStatsInit);
    int nDefense = monStatsInit.nAC;
    if (pMonStatsTxtRecord->nAlign != 1 && !GAME_IsExpansion() && GAME_GetDifficulty())
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

#include "gen/data/Source/D2Client/UI/text_004A1600.inc"
