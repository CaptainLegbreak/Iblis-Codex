#include "D2Client.h"
#include "D2Primitives.h"
#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2QuestTextsStrc;
struct D2UiEntry10Strc;
struct D2QuestPanelEntryStrc;
struct D2QuestSlotRectStrc;
struct Unicode;
struct D2ButtonLayoutStrc;
struct D2QuestTableStrc;
union D2SeedStrc;
extern D2UiEntry10Strc gaUiEntries_00723F38[41]; // 0x00723F38
extern int ganPageSelection_007BF280[5]; // 0x007BF280
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

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

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
void __stdcall sub_004A3220_LoadQuestPage(int nPage, int nArg); // 0x004A3220
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
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
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
extern int gnGlobal_007BF298; // 0x007BF298
extern int gnGlobal_007BF2A4; // 0x007BF2A4
extern int gnGlobal_007BF2AC; // 0x007BF2AC
extern int gnIndex_007BF2BD; // 0x007BF2BD
extern int gnIndex_007BF2C1; // 0x007BF2C1
extern int gnIndex_007BF2C5; // 0x007BF2C5
extern int gnIndex_007BF2C9; // 0x007BF2C9
extern int gnIndex_007BF2CD; // 0x007BF2CD
extern void* gapCelFiles_007BF2E1[27]; // 0x007BF2E1
extern volatile char gabQuestFlagsB_007BF380[]; // 0x007BF380

struct D2ButtonLayoutStrc
{
    int nTextX;
    int nRight;
    int nTop;
    int nBottom;
    int nTextY;
};

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0
int __cdecl sub_0045AE90(); // 0x0045AE90
int __cdecl sub_00463DF0(); // 0x00463DF0
int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840
int __stdcall sub_006018C0(D2CelStrc* pCel); // 0x006018C0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int nArg5); // 0x00502320
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
extern D2ButtonLayoutStrc gaButtonLayouts_007241C0[]; // 0x007241C0
extern void* gpGlobal_007C02DC; // 0x007C02DC
extern void* gpGlobal_007C02E0; // 0x007C02E0

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

extern D2QuestTableStrc gaQuestTable_00723F30[]; // 0x00723F30

typedef void (__stdcall* B27RecordHandler)(int, int, int);

typedef int (__cdecl* B27UIAction)();

extern "C" int __cdecl sub_004B1DD0_Action();
extern "C" int __cdecl sub_004B2020_Action();
extern "C" unsigned int gB27_00726CC1;
extern "C" unsigned short gB27_00726CCB;
extern "C" unsigned int gB27_00726CDB;
extern "C" unsigned int gB27_00726DF9;
extern "C" unsigned short gB27_00726E01;
extern "C" unsigned int gB27_00726E0F;
extern "C" unsigned int gB27_00726E47;
extern "C" unsigned short gB27_00726E4F;
extern "C" unsigned int gB27_00726E5D;
extern "C" unsigned int gB27_00726E95;
extern "C" unsigned short gB27_00726E9D;
extern "C" unsigned int gB27_00726EAB;
extern "C" unsigned int gB27_00726EBC;
extern "C" unsigned short gB27_00726EC2;
extern "C" B27UIAction gB27_00726ECE;
extern "C" unsigned int gB27_00726EE3;
extern "C" unsigned short gB27_00726EE9;
extern "C" B27UIAction gB27_00726EF5;
extern "C" unsigned int gB27_00726F0A;
extern "C" unsigned short gB27_00726F10;
extern "C" B27UIAction gB27_00726F1C;
extern "C" unsigned int gB27_00726F31;
extern "C" unsigned short gB27_00726F37;
extern "C" B27UIAction gB27_00726F43;
extern "C" unsigned int gB27_00726F7F;
extern "C" unsigned short gB27_00726F85;
extern "C" unsigned short gB27_00726F87;
extern "C" unsigned int gB27_00726F91;
extern "C" unsigned int gB27_00726F95;
extern "C" unsigned int gB27_00727216;
extern "C" unsigned short gB27_0072721C;
extern "C" B27UIAction gB27_00727228;
extern "C" unsigned int gB27_0072723D;
extern "C" unsigned short gB27_00727247;
extern "C" unsigned int gB27_00727257;
extern "C" unsigned int gB27_0072728B;
extern "C" unsigned short gB27_00727297;
extern "C" unsigned int gB27_007272A9;
extern "C" unsigned int gB27_007272D9;
extern "C" unsigned short gB27_007272E1;
extern "C" B27UIAction gB27_007272EB;
extern "C" unsigned int gB27_007272EF;
extern "C" int gB27_007BCBF0;
extern "C" int gB27_007BF298; // 0x007BF298
extern "C" unsigned char gB27_007C025F; // 0x007C025F
extern "C" unsigned int gB27_007C0265; // 0x007C0265
extern "C" B27RecordHandler gB27_00881834;
extern "C" unsigned int gB27_00883D70;
D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0
extern unsigned int gnQuestUnitId_007C0261; // 0x007C0261
D2UnitStrc* __fastcall sub_00466730_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730

// 0x004A1760
int __cdecl sub_004A1760_Forward()
{
    return sub_004A08C0();
}

// 0x004A18E0
static inline void sub_004A18E0_SetIndex(int nIndex)
{
    gnIndex_007BF2B9 = nIndex;
}

// 0x004A1930
static inline int sub_004A1930_FindEntryIndex(int nId)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaUiEntries_00723F38[i].nId == nId)
            return i;
    }
    return -1;
}

int __fastcall sub_M115_Emit_004A18E0(int nIndex, int nId)
{
    sub_004A18E0_SetIndex(nIndex);
    return sub_004A1930_FindEntryIndex(nId);
}

// 0x004A18F0
void __cdecl sub_004A3050()
{
    ganPageSelection_007BF280[0] = -1;
    ganPageSelection_007BF280[1] = -1;
    ganPageSelection_007BF280[2] = -1;
    ganPageSelection_007BF280[3] = -1;
    ganPageSelection_007BF280[4] = -1;
}

// 0x004A1910
static inline int sub_004A1910_FindQuestIndex(int nKey)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaUiEntries_00723F38[i].nKey == nKey)
            return i;
    }
    return -1;
}

int __fastcall sub_M224_Emit_004A1910(int nIndex, int nKey)
{
    gnIndex_007BF2B9 = nIndex;
    return sub_004A1910_FindQuestIndex(nKey);
}

static void sub_004A2220_SetQuestPage(int nPage)
{
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
    gnGlobal_007C0255 = nPage;
    for (int i = 0; i < 6; ++i)
    {
        ganGlobal_007C0225[i] = 0;
        ganGlobal_007C023D[i] = 0;
    }
    gnIndex_007BF2B9 = -1;
    gnIndex_007BF2B5 = -1;
}

// 0x004A2300
void __cdecl sub_004A2300_UpdateQuestPage()
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
                sub_004A2220_SetQuestPage(DRLG_GetActNoFromLevelId(nLevelId));
                return;
            }
        }
    }
    sub_004A2220_SetQuestPage(0);
}

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

void __stdcall sub_004A3E40_OnLeftButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = D2_LOWORD(pMsg->lParam);
    int nY = D2_HIWORD(pMsg->lParam);
    int nIndex;
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
    if (!gbGlobal_007BF2B3)
    {
        nIndex = sub_004A26F0_GetTabAtPoint(nY, nX);
        if (nIndex != -1)
        {
            if (nIndex < 5 && nIndex != gnGlobal_007C0255 && ((sub_00408F20_HasExpansionMpq() && sub_0044DCC0()) || nIndex != 4))
            {
                sub_004A2760(gnGlobal_007C0255);
                sub_004A2220_SetQuestPage(nIndex);
                sub_004A3220_LoadQuestPage(gnGlobal_007C0255, 1);
                sub_004A2390_ResetQuestSelection();
            }
        }
        else
        {
            nIndex = sub_004A2630_GetSlotAtPoint(nX, nY);
            if (nIndex != -1 && nIndex < gnQuestCount_007BF2A0)
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

#include "gen/data/Source/D2Client/UI/text_004A1760.inc"

int gnQuestCount_007BF2A0; // 0x007BF2A0

char gabQuestFlagsA_007BF356[42]; // 0x007BF356

// 0x004A2550
void __cdecl sub_004A2550_FreeQuestCels()
{
    if (gpCelFile_007BF2D5)
    {
        sub_00478A00(gpCelFile_007BF2D5);
        gpCelFile_007BF2D5 = 0;
    }
    if (gpCelFile_007BF2D9)
    {
        sub_00478A00(gpCelFile_007BF2D9);
        gpCelFile_007BF2D9 = 0;
    }
    if (gpCelFile_007BF34D)
    {
        sub_00478A00(gpCelFile_007BF34D);
        gpCelFile_007BF34D = 0;
    }
    if (gpCelFile_007BF2D1)
    {
        sub_00478A00(gpCelFile_007BF2D1);
        gpCelFile_007BF2D1 = 0;
    }
    if (gpCelFile_007BF2DD)
    {
        sub_00478A00(gpCelFile_007BF2DD);
        gpCelFile_007BF2DD = 0;
    }
    if (gpCelFile_007BF351)
    {
        sub_00478A00(gpCelFile_007BF351);
        gpCelFile_007BF351 = 0;
    }
    for (int i = 0; i < 27; ++i)
    {
        if (gapCelFiles_007BF2E1[i])
        {
            sub_00478A00(gapCelFiles_007BF2E1[i]);
            gapCelFiles_007BF2E1[i] = 0;
        }
    }
}

// 0x004A2600
void __cdecl sub_004A2600_FreeQuestPanel()
{
    sub_004A2550_FreeQuestCels();
}

// 0x004A2760
void __cdecl sub_004A2760_SendQuestUpdates()
{
    for (int i = 0; i < gnQuestCount_007BF2A0; ++i)
    {
        if (!gaQuestEntries_007BF3AA[i].bDone)
        {
            D2BitBufferStrc* pQuestInfo = sub_004B32D0();
            QUESTRECORD_SetQuestState(pQuestInfo, gaQuestEntries_007BF3AA[i].nQuestId, 0xC);
            sub_004785B0_SendPacket3(0x58, (unsigned short)gaQuestEntries_007BF3AA[i].nQuestId);
        }
    }
}

// 0x004A3020
void __cdecl sub_004A3020_ClearQuestFlags()
{
    for (int i = 0; i < 41; ++i)
    {
        gabQuestFlagsA_007BF356[i] = 0;
        gabQuestFlagsB_007BF380[i] = 0;
    }
}

// 0x004A3410
void __cdecl sub_004A3410_ResetQuestPanel()
{
    SRegSaveValue("Diablo II", "GAMEOVER", 0, 0);
    gnGlobal_007BF298 = 0;
    gpCelFile_007BF2D5 = 0;
    gpCelFile_007BF2D9 = 0;
    gpCelFile_007BF2D1 = 0;
    gpCelFile_007BF2DD = 0;
    gpCelFile_007BF351 = 0;
    gpCelFile_007BF34D = 0;
    memset(gapCelFiles_007BF2E1, 0, sizeof(gapCelFiles_007BF2E1));
    gnGlobal_007BF2A4 = 0;
    gnGlobal_007BF2AC = 0;
    gnGlobal_007C0259 = 0;
    for (int i = 0; i < 41; ++i)
    {
        gabQuestFlagsA_007BF356[i] = 0;
        gabQuestFlagsB_007BF380[i] = 0;
    }
    gbGlobal_007BF2B1 = 0;
    gbGlobal_007BF2B2 = 0;
    gbGlobal_007BF2B0 = 0;
    gbGlobal_007BF2B4 = 0;
    gbGlobal_007C025D = 0;
    gbGlobal_007C025E = 0;
    gbGlobal_007C025F = 0;
    gbGlobal_007C0260 = 0;
    gbGlobal_007BF2B3 = 0;
    gnIndex_007BF2B5 = -1;
    gnIndex_007BF2BD = -1;
    gnIndex_007BF2C1 = -1;
    gnIndex_007BF2C5 = -1;
    gnIndex_007BF2C9 = -1;
    gnIndex_007BF2CD = -1;
}

// 0x004A27B0
int __fastcall sub_004A27B0_CloseQuestText(void* pContext, int nArg, int nValue)
{
    gbGlobal_007BF2B3 = 0;
    sub_0049E7E0_SetTextCallback(0, pContext);
    return 0;
}

// 0x004A2C70
void __fastcall sub_004A2C70_ClearUnitFlag92(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x92)
        pUnit->dwFlags &= ~2u;
}

// 0x004A2C90
void __fastcall sub_004A2C90_ClearUnitFlag20F(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId == 0x20F)
        pUnit->dwFlags &= ~2u;
}

// 0x004A2900
static int sub_004A2900_GetButtonLayout(int nMode)
{
    if (sub_004538D0(6) && !sub_004538D0(2))
    {
        const int nResolution = D2GFX_GetResolutionMode();
        if (nMode == 2)
            return nResolution == 2 ? 1 : 3;
        return nResolution == 2 ? 0 : 2;
    }

    const int nResolution = D2GFX_GetResolutionMode();
    if (nMode == 2)
    {
        if (nResolution == 2 || sub_004538D0(2))
            return 1;
        return 3;
    }
    return nResolution == 2 ? 0 : 2;
}

// 0x004A28D0
void __cdecl sub_004A28D0_ResetButton()
{
    if (gnGlobal_007C0255 < 5)
        sub_004A2760(gnGlobal_007C0255);
    gbGlobal_007BF2B0 = 0;
    gnGlobal_007BF298 = 0;
    gbGlobal_007BF2B3 = 0;
    sub_004A2550();
}

// build: symbol ?sub_E10_GetButtonLayoutCopy@@YAHH@Z 0x004A2900
static int sub_E10_GetButtonLayoutCopy(int nMode)
{
    if (sub_004538D0(6) && !sub_004538D0(2))
    {
        const int nResolution = D2GFX_GetResolutionMode();
        if (nMode == 2)
            return nResolution == 2 ? 1 : 3;
        return nResolution == 2 ? 0 : 2;
    }

    const int nResolution = D2GFX_GetResolutionMode();
    if (nMode == 2)
    {
        if (nResolution == 2 || sub_004538D0(2))
            return 1;
        return 3;
    }
    return nResolution == 2 ? 0 : 2;
}

// 0x004A2970
int __stdcall sub_004A2970_IsMouseOnButton(int nX, int nY)
{
    const int nMode = sub_0045AE90();
    const int nIndex = sub_E10_GetButtonLayoutCopy(nMode);
    const int nLeft = gaButtonLayouts_007241C0[nIndex].nTextX + (nMode == 2 ? (gnGlobal_0071146C - 0x280) / 2 : 0);
    const int nTop = gaButtonLayouts_007241C0[nIndex].nTop + gnGlobal_00711470 - 0x1E0;
    const int nRight = gaButtonLayouts_007241C0[nIndex].nRight + (nMode == 2 ? (gnGlobal_0071146C - 0x280) / 2 : 0);
    if (nX > nLeft && nX < nRight && nY > nTop && nY < gaButtonLayouts_007241C0[nIndex].nBottom + gnGlobal_00711470 - 0x1E0)
        return 1;
    return 0;
}

// 0x004A2A80
void __cdecl sub_004A2A80_DrawButton()
{
    if (sub_00463DF0())
    {
        sub_00455F20(0x11, 1, 0);
        if (gnGlobal_007BF298 == 1)
        {
            gbGlobal_007BF2B0 = 0;
            gnGlobal_007BF298 = 0;
        }
        return;
    }

    const int nMode = sub_0045AE90();
    if (nMode == 3)
        return;
    if (sub_004538D0(0x0F))
        return;

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.nDirection = 0;
    tCel.pCellFile = gpGlobal_007C02E0;
    tCel.nFrame = 0;
    const int nIndex = sub_E10_GetButtonLayoutCopy(nMode);
    const int nCelWidth = sub_006018C0(CelGetHandle(&tCel));
    const int nTextWidth = sub_00501820(D2LANG_GetStringFromTblIndex(0xF58));
    int nTextX = nCelWidth / 2 - nTextWidth / 2 + gaButtonLayouts_007241C0[nIndex].nTextX + 1;
    const int nTextY = gaButtonLayouts_007241C0[nIndex].nTextY + gnGlobal_00711470 - 0x1E0;
    if (sub_0045AE90() == 2)
        nTextX += (gnGlobal_0071146C - 0x280) / 2;
    sub_00502320(D2LANG_GetStringFromTblIndex(0xF58), nTextX, nTextY, 0, 0);

    int nCelX = gaButtonLayouts_007241C0[nIndex].nTextX;
    const int nCelY = gaButtonLayouts_007241C0[nIndex].nBottom + gnGlobal_00711470 - 0x1E0;
    if (sub_0045AE90() == 2)
        nCelX += (gnGlobal_0071146C - 0x280) / 2;
    sub_004F6480(&tCel, nCelX, nCelY, -1, 5, 0);

    tCel.pCellFile = gpGlobal_007C02DC;
    tCel.nFrame = gbGlobal_007BF2B0 && (unsigned char)sub_004A2970_IsMouseOnButton(sub_00468730(), sub_00468740());
    sub_004F6480(&tCel, nCelX + 3, nCelY - 4, -1, 5, 0);
}

// 0x004A2C30
void __fastcall sub_004A2C30_SelectQuestPage(int nCondition)
{
    int nIndex = -1;
    for (int i = 0; i < 41; ++i)
    {
        if (gaQuestTable_00723F30[i].nCondition == nCondition)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex != -1)
        ganPageSelection_007BF280[gaQuestTable_00723F30[nIndex].nPage] = gaQuestTable_00723F30[nIndex].nCelId2;
}

extern "C" int __cdecl sub_00489840_ModeInGroup()
{
    int mode = gB27_007BCBF0;
    if (mode == 1 || mode == 2 || mode == 3)
        return 1;
    return 0;
}

// 0x004A3000
extern "C" void __cdecl sub_004A3000_ResetFlag()
{
    if (gB27_007BF298 == 1)
        gB27_007BF298 = 0;
}

// 0x004A3100
extern "C" void __fastcall sub_004A3100_SetPacketValue(unsigned int value)
{
    gB27_007C025F = 1;
    gB27_007C0265 = value;
}

extern "C" void __cdecl sub_004B2250_InitializeControls()
{
    bool oldAction = (gB27_007272EB == sub_004B1DD0_Action);
    gB27_00726DF9 = 2;
    gB27_00726E01 = 0;
    gB27_00726E0F = 0;
    gB27_00726E47 = 2;
    gB27_00726E4F = 0;
    gB27_00726E5D = 0;
    gB27_00726E95 = 2;
    gB27_00726E9D = 0;
    gB27_00726EAB = 0;
    gB27_00726CC1 = 3;
    gB27_00726CCB = 0;
    gB27_00726CDB = 0;
    gB27_007272D9 = 2;
    gB27_007272E1 = 0;
    gB27_007272EF = 0;
    if (oldAction)
        gB27_007272D9 = 3;
    gB27_00727247 = 0;
    gB27_00727257 = 0;
    gB27_00727297 = 0;
    gB27_007272A9 = 0;
    gB27_00726F7F = 2;
    gB27_00726F87 = 0;
    gB27_00726F95 = 0;
    gB27_00726F85 = 0;
    gB27_00726F91 = 0;
    gB27_0072723D = 3;
    gB27_0072728B = 4;
    gB27_00726EC2 = 0xfb4;
    gB27_00726ECE = sub_004B2020_Action;
    gB27_00726EBC = 3;
    gB27_00726EE9 = 0xfb4;
    gB27_00726EF5 = sub_004B2020_Action;
    gB27_00726EE3 = 3;
    gB27_00726F10 = 0xfb4;
    gB27_00726F1C = sub_004B2020_Action;
    gB27_00726F0A = 3;
    gB27_00726F37 = 0xfb4;
    gB27_00726F43 = sub_004B2020_Action;
    gB27_00726F31 = 3;
    gB27_0072721C = 0xfb4;
    gB27_00727228 = sub_004B2020_Action;
    gB27_00727216 = 3;
}

extern "C" B27RecordHandler __fastcall sub_005173D3_ExchangeRecordHandler(B27RecordHandler handler); // 0x005173D3

extern "C" void __fastcall sub_00535780_SetPlayers(unsigned int count)
{
    if (count <= 8)
        gB27_00883D70 = count;
}

char gbGlobal_007C025D; // 0x007C025D

char gbGlobal_007C025E; // 0x007C025E

// 0x004A30A0
void __cdecl sub_004A30A0_TriggerOnceD3()
{
    if (!gbGlobal_007C025D)
    {
        gbGlobal_007C025D = 1;
        sub_0046F870(0xD3, 1);
    }
}

// 0x004A30C0
void __cdecl sub_004A30C0_TriggerOnce219()
{
    if (!gbGlobal_007C025E)
    {
        gbGlobal_007C025E = 1;
        sub_0046F870(0x219, 0);
        sub_0046F870(0x21A, 0);
        sub_0046F870(0x21B, 0);
    }
}

// 0x004A3110
char __cdecl sub_004A3110_GetFlag025F()
{
    return gbGlobal_007C025F;
}

char gbGlobal_007C0260; // 0x007C0260

// 0x004A3120
char __cdecl sub_004A3120_IsQuestUnitPresent()
{
    if (gbGlobal_007C0260 && sub_004639B0_FindServerSideUnit(gnQuestUnitId_007C0261, 1))
    {
        return 1;
    }
    return 0;
}

char gbGlobal_007C025F; // 0x007C025F

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
void __fastcall sub_004A3150_SpawnQuestUnits(int nX, int nY)
{
    if (gbGlobal_007C025F)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nCount = SEED_RollLimitedRandomNumber(&pPlayer->pSeed, 3) + 2;
        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pUnit = sub_00466730_SpawnPresetUnit(0x95, nX + i % 2, nY + i % 2, 1, 1);
            gnQuestUnitId_007C0261 = UNITS_GetUnitId(pUnit);
            gbGlobal_007C0260 = 1;
        }
    }
}
