#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define gnGlobal_007BCAA0 (gInvRect_007BCAA0.nLeft)
#define gnGlobal_007BCAA4 (gInvRect_007BCAA0.nRight)
#define gnGlobal_007BCAA8 (gInvRect_007BCAA0.nTop)
#define gnGlobal_007BCAAC (gInvRect_007BCAA0.nBottom)
struct D2MsgHandlerEntryStrc;
struct Unicode;
struct D2RectStrc;
struct T00479230;
struct D2WaypointMenuEntryStrc;
struct D2WaypointActRangeStrc;
struct D2AreaScanFindStrc;
struct D2SetItemsTxt;
struct D2SkillsTxt;
struct D2MonStatsTxt;
struct D2RequestStrc;
struct D2RosterPetStrc;
struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;
struct D2EscMenuUIStateStrc;
struct D2InvRectStrc;
class WardenModule;
struct D2ClientSlotObjStrc;
struct D2ClientSlotHolderStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


struct D2CelContextStrc
{
    int nFrame;
    int unk0x04[12];
    void* pCellFile;
    int unk0x38[2];
    int unk0x40;
    int unk0x44;
};

struct T00479230
{
    char unk0x00[0x16];
    char nScroll[4];
    char unk0x1A[0x12];
};

struct D2WaypointActRangeStrc
{
    char bInit;
    char nFirstLevelId[4];
    char nLastLevelId[4];
    unsigned char nMinWaypoint;
    unsigned char nMaxWaypoint;
};

struct D2AreaScanFindStrc
{
    int nFirst;
    int nBest;
    int nSecond;
    int nArgA;
    int nArgB;
    int nOut;
};

typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

struct D2SetItemsTxt
{
    char unk0x00[0x87];
    unsigned char nAddFunc;
};

struct D2SkillsTxt
{
    short nSkillId;
    char unk0x02[2];
    unsigned char nFlags[8];
    char unk0x0C[0xDE];
    short wCltMissileA;
    short wCltMissileB;
    short wCltMissileC;
    char unk0xF0[0x1A];
    short wTgtSound;
    char unk0x10C[0x130];
};

struct D2MonStatsTxt
{
    char unk0x00[0x1A8];
};

struct D2DataTablesStrc
{
    char unk0x000[0xA78];
    D2MonStatsTxt* pMonStatsTxt;
    int unk0xA7C;
    int nMonStatsTxtRecordCount;
    char unk0xA84[0xE8];
    int nMissilesTxtRecordCount;
    char unk0xB70[0x28];
    D2SkillsTxt* pSkillsTxt;
    int unk0xB9C;
    int nSkillsTxtRecordCount;
};

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    int unk0x08[2];
    int nArg0;
    int nArg1;
    int nArg2;
    int unk0x1C[4];
    int nArg3;
    int nArg4;
    int unk0x34[10];
};

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    union
    {
        struct
        {
            unsigned short nWParamLo;
            short nWParamHi;
        };
        unsigned int wParam;
    };
    union
    {
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
        unsigned int lParam;
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct D2RosterPetStrc
{
    int nClassId;
    int nType;
    int dwUnitId;
    int dwOwnerId;
    char unk0x10[0x20];
    D2RosterPetStrc* pNext;
};

struct D2OptionHeaderStrc
{
    int nCount;
};

struct D2OptionEntryStrc
{
    int nKind;
    char unk0x004[0x10C];
    int (__cdecl* pfnEnabled)();
    void (__fastcall* pfnChanged)(D2OptionEntryStrc* pEntry, int nArg);
    int unk0x118[2];
    unsigned int nValues;
    unsigned int nValue;
    char unk0x128[0x428];
};

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_0047A560(); // 0x0047A560
int __cdecl sub_004B8A10(); // 0x004B8A10
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __cdecl sub_0044DA40(); // 0x0044DA40
int __cdecl sub_0045AE90(); // 0x0045AE90
extern "C" int __cdecl sub_0045AFC0(); // 0x0045AFC0
extern "C" int __cdecl sub_0045AFD0_GetMouseYOffset(); // 0x0045AFD0
int __cdecl sub_0044DCC0(); // 0x0044DCC0
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall sub_004639D0_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
void* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode); // 0x0046E570
void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046E5A0
void* __fastcall sub_0046FA80_LoadGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80
int __fastcall sub_004709A0_IsOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2); // 0x004709A0
D2UnitStrc* __fastcall sub_004648F0_GetTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540
void __fastcall sub_004CEFE0_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nArg1, int nArg2, int nArg3); // 0x004CEFE0
int __fastcall sub_004DB0D0_UpdateGfxEntry(void* pEntry, int nArg); // 0x004DB0D0
int __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pItem, int nArg1, int nArg2, int nArg3, int nProp, int nArg5, int nArg6, int nArg7); // 0x004E60A0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70
unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370
D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062A490
int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem); // 0x0062B3A0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nState); // 0x0063A7B0
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int a5); // 0x0064F380
void __cdecl sub_00466FE0(); // 0x00466FE0
void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430
T00479230* __fastcall sub_004A05E0_CreateTextBox(const Unicode* wszText, int nMode); // 0x004A05E0
int __fastcall sub_004C5C40_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40
int __fastcall sub_004C5E70_FindCallback(void* pArg, D2UnitStrc* pUnit); // 0x004C5E70
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0
int __fastcall sub_004E0650_GetStringSound(unsigned short nStringId); // 0x004E0650
int __cdecl sub_004F59A0(); // 0x004F59A0
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0
void __stdcall sub_004912A0_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg); // 0x004912A0
int __stdcall sub_004934D0_CheckBoxAction(int nArg); // 0x004934D0
int __fastcall sub_004A8C80_GetSkillValue(D2SkillsTxt* pSkillsTxt); // 0x004A8C80
int __fastcall sub_004A8D30_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004A8D30
void __fastcall sub_004A9690_DrawSkillInfoBase(int nValue, D2SkillsTxt* pSkillsTxt, int nOwnerGUID, int nCharges, int nState, int nX, int nY, int nArg); // 0x004A9690
void __fastcall sub_004A8D50_UpdateButton(short* pId, int nState, int nA, int nB, int nX, int nY); // 0x004A8D50
void __fastcall sub_004AA1F0_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY); // 0x004AA1F0
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
int __stdcall WAYPOINTS_GetLevelIdFromWaypointNo(unsigned short wWaypointNo, int* pLevelId); // 0x00660D90
int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo); // 0x00660E00
int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660E50
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2SkillsTxt* __fastcall sub_00644140_GetSkillsTxtFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
int __fastcall sub_00463E50_GetUnitFlagA(D2UnitStrc* pUnit); // 0x00463E50
int __fastcall sub_00463EB0_GetUnitFlagB(D2UnitStrc* pUnit); // 0x00463EB0
int __fastcall sub_004791B0_IsOwnedByPlayer(D2UnitStrc* pUnit); // 0x004791B0
void __cdecl sub_0047B9C0_LoadChatHistoryLine(); // 0x0047B9C0
void __stdcall sub_0047BA80_StepChatIndex(int nDelta); // 0x0047BA80
extern const int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern int gaSetPartialCounts_006DBD90[]; // 0x006DBD90
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern D2OptionHeaderStrc gOptionHeader_00713044; // 0x00713044
extern D2EscMenuUIStateStrc gaEscMenuUIState_00713058[38]; // 0x00713058
extern D2OptionEntryStrc gaOptionEntries_00713220[]; // 0x00713220
extern D2OptionHeaderStrc gOptionHeader_00714210; // 0x00714210
extern D2OptionHeaderStrc gOptionHeader_00714224; // 0x00714224
extern D2OptionEntryStrc gaOptionEntries_00714238[]; // 0x00714238
extern D2OptionEntryStrc gaOptionEntries_00715CC8[]; // 0x00715CC8
extern D2OptionHeaderStrc gOptionHeader_00718748; // 0x00718748
extern D2OptionHeaderStrc gOptionHeader_0071875C; // 0x0071875C
extern D2OptionEntryStrc gaOptionEntries_00718770[]; // 0x00718770
extern D2OptionEntryStrc gaOptionEntries_0071ACA0[]; // 0x0071ACA0
extern D2MsgHandlerEntryStrc gaTextMsgHandlers_00722600[]; // 0x00722600
extern D2WaypointActRangeStrc gaWaypointActRanges_007224AC[]; // 0x007224AC
extern D2OptionHeaderStrc gOptionHeader_0071D720; // 0x0071D720
extern D2OptionHeaderStrc gOptionHeader_0071D734; // 0x0071D734
extern D2OptionEntryStrc gaOptionEntries_0071D748[]; // 0x0071D748
extern D2OptionEntryStrc gaOptionEntries_0071F728[]; // 0x0071F728
extern D2RosterPetStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

struct D2InvRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

extern D2InvRectStrc gInvRect_007BCAA0; // 0x007BCAA0
extern D2OptionHeaderStrc* gpOptionHeader_007BC93C; // 0x007BC93C
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern char gbGlobal_007BF085; // 0x007BF085
extern int gnWaypointCount_007BF08A; // 0x007BF08A
extern int gnWaypointEnabled_007BF08E; // 0x007BF08E
extern T00479230* gpTextBox_007BF0A4; // 0x007BF0A4
extern int gnGlobal_007BF1BC; // 0x007BF1BC
extern int gnGlobal_007BF1C0; // 0x007BF1C0
extern unsigned long gnGlobal_007BF22C; // 0x007BF22C
extern int gbTextSound_007BF230; // 0x007BF230
extern int gbTextSide_007BF236; // 0x007BF236
extern int gnGlobal_007BEEE8; // 0x007BEEE8

// build: symbol ??1WardenModule@@QAE@XZ 0x004E06A0
// build: symbol ??_GWardenModule@@QAEPAXI@Z 0x0047FC40
// 0x0047FC40
class WardenModule
{
public:
    ~WardenModule();
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }

    void* pImage;
    int unk0x04;
    int nImports;
};

struct D2ClientSlotObjStrc
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
    virtual void Slot3(int nArg);
};

struct D2ClientSlotHolderStrc
{
    char unk0x00[0x0C];
    D2ClientSlotObjStrc* pObj;
};

void __cdecl sub_00480230(); // 0x00480230
extern D2ClientSlotHolderStrc* gpSlotHolder_007BC990; // 0x007BC990

int gnOptionSelected_007BC938; // 0x007BC938

D2OptionEntryStrc* gpOptionEntries_007BC940; // 0x007BC940

static int gnGlobal_007BCA4C; // 0x007BCA4C

static int gnGlobal_007BCBD8; // 0x007BCBD8

static int gnGlobal_007BEECC; // 0x007BEECC

D2WaypointMenuEntryStrc gaWaypointEntries_007BF03C[9]; // 0x007BF03C

unsigned short gwTextStringId_007BF212; // 0x007BF212

int gnHintId_007BF260; // 0x007BF260

int gnGlobal_007BF278; // 0x007BF278

static int gbStarted_007BF27C; // 0x007BF27C

int gnGlobal_007BEED4; // 0x007BEED4

void* gpWardenBuffer_007BC988; // 0x007BC988

unsigned int gnWardenBufferSize_007BC98C; // 0x007BC98C

// 0x00479230
void __fastcall sub_00479230_UpdateOwnerPetFlags(int nOwnerId)
{
    for (D2RosterPetStrc* pPet = gpRosterPets_007BB5BC; pPet; pPet = pPet->pNext)
    {
        if (pPet->dwOwnerId == nOwnerId)
        {
            switch (pPet->nClassId)
            {
            case 0x16B:
            case 0x16C:
            {
                D2UnitStrc* pUnit = sub_00463990(pPet->dwUnitId, UNIT_MONSTER);
                if (pUnit)
                {
                    int nFlagB = sub_00463EB0_GetUnitFlagB(pUnit);
                    int bSet = !sub_004791B0_IsOwnedByPlayer(pUnit);
                    if (nFlagB == sub_00463E50_GetUnitFlagA(pUnit))
                    {
                        sub_00463E80_SetUnitFlagB(pUnit, bSet);
                    }
                    sub_00463E20_SetUnitFlagA(pUnit, bSet);
                }
                break;
            }
            }
        }
    }
}

// 0x0047BCA0
void __stdcall sub_0047BCA0_ChatKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
    if (pMsg->lParam & 0x40000000)
    {
        return;
    }
    int nKey = pMsg->wParam;
    switch (nKey)
    {
    case 0x26:
        sub_0047B9C0_LoadChatHistoryLine();
        sub_0047BA80_StepChatIndex(1);
        break;
    case 0x28:
        sub_0047BA80_StepChatIndex(-1);
        sub_0047B9C0_LoadChatHistoryLine();
        break;
    }
}

// 0x0047E090
void __fastcall sub_0047E090(int bSaveState, int nMenu)
{
    if (bSaveState)
    {
        for (unsigned int i = 0; i < 38; ++i)
        {
            gaEscMenuUIState_00713058[i].nSaved = 0;
            if (gaEscMenuUIState_00713058[i].bCheck)
            {
                if (gaEscMenuUIState_00713058[i].bSave)
                {
                    gaEscMenuUIState_00713058[i].nSaved = sub_004538D0(i);
                }
                if (sub_004538D0(i))
                {
                    sub_00455F20(i, 1, 0);
                }
            }
        }
    }
    sub_00455F20(9, 0, 0);
    switch (nMenu)
    {
    case 0:
        gpOptionHeader_007BC93C = &gOptionHeader_00713044;
        gpOptionEntries_007BC940 = gaOptionEntries_00713220;
        break;
    case 1:
        gpOptionHeader_007BC93C = &gOptionHeader_00714210;
        gpOptionEntries_007BC940 = gaOptionEntries_00714238;
        break;
    case 2:
        gpOptionHeader_007BC93C = &gOptionHeader_00714224;
        gpOptionEntries_007BC940 = gaOptionEntries_00715CC8;
        break;
    case 3:
        if (sub_00408F20_HasExpansionMpq())
        {
            gpOptionHeader_007BC93C = &gOptionHeader_0071875C;
            gpOptionEntries_007BC940 = gaOptionEntries_0071ACA0;
        }
        else
        {
            gpOptionHeader_007BC93C = &gOptionHeader_00718748;
            gpOptionEntries_007BC940 = gaOptionEntries_00718770;
        }
        break;
    case 4:
        if (sub_00408F20_HasExpansionMpq())
        {
            gpOptionHeader_007BC93C = &gOptionHeader_0071D734;
            gpOptionEntries_007BC940 = gaOptionEntries_0071F728;
        }
        else
        {
            gpOptionHeader_007BC93C = &gOptionHeader_0071D720;
            gpOptionEntries_007BC940 = gaOptionEntries_0071D748;
        }
        break;
    }
    gnOptionSelected_007BC938 = gpOptionHeader_007BC93C->nCount - 1;
    if (nMenu == 5)
    {
        gnOptionSelected_007BC938 = 1;
    }
}

// 0x00480150
bool __stdcall sub_00480150_TakeWardenBuffer(void* pDst, unsigned int* pSize)
{
    void* pBuffer = gpWardenBuffer_007BC988;
    if (!pBuffer)
    {
        return false;
    }
    unsigned int nSize = *pSize < gnWardenBufferSize_007BC98C ? *pSize : gnWardenBufferSize_007BC98C;
    *pSize = nSize;
    sub_0041D2A0_MemCopy(pDst, pBuffer, nSize);
    SMemFree(gpWardenBuffer_007BC988, ".\\WARDEN\\WardenClient.cpp", 0x292, 0);
    gpWardenBuffer_007BC988 = 0;
    gnWardenBufferSize_007BC98C = 0;
    return true;
}

// 0x004922A0
int __stdcall sub_004922A0_ClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gnGlobal_007BCA4C = nX;
    gnGlobal_007BCBD8 = nY;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
    if (nX >= gnGlobal_007BCAA0 && nX < gnGlobal_007BCAA4 && nY >= gnGlobal_007BCAA8 && nY <= gnGlobal_007BCAAC)
    {
        sub_004912A0_HandlePanelClick(pMsg);
        return 1;
    }
    return 0;
}

static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}

// 0x004936E0
void __stdcall sub_004936E0_ClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_0044DCC0())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    const int bHit = gnGlobal_007BEECC != 2 && InBox(nX, nY, gnGlobal_007BEED4, gnGlobal_007BEED4 + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gnGlobal_007BEEE8 = 0;
        return;
    }
    if (sub_004934D0_CheckBoxAction(1))
    {
        sub_004785B0_SendPacket3(0x61, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x00496B10
void __cdecl sub_00496B10()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int bPanel = 0;
    int nYOffset = 0;
    if (!sub_0047A560())
    {
        return;
    }
    if (sub_004538D0(0x19) || sub_004538D0(0x0C) || sub_004538D0(0x18) || sub_004538D0(1) || sub_004538D0(4))
    {
        bPanel = 1;
    }
    if (sub_004538D0(0x17) && !sub_004B8A10())
    {
        return;
    }
    if (bPanel)
    {
        return;
    }
    tContext.pCellFile = gpCellFile_007BEF28;
    tContext.unk0x40 = 0;
    tContext.nFrame = 0;
    if (sub_004538D0(0x0A))
    {
        nYOffset = 0x46;
    }
    sub_004F6480(&tContext, gnGlobal_0071146C - 0x3A, nYOffset + 0x2D, -1, 1, 0);
}

// 0x00496BE0
void __fastcall sub_00496BE0_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg)
{
    if (!pUnit || !pSkill)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = sub_00644140_GetSkillsTxtFromSkill(pSkill);
    if (!pSkillsTxt)
    {
        return;
    }

    const int nValue = sub_004A8C80_GetSkillValue(pSkillsTxt);
    int nState = sub_004A8D30_GetSkillState(pUnit, pSkill);
    if (!(pSkillsTxt->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            nState = 1;
        }
    }

    int nOwnerGUID = -1;
    int nSkillLevel = 0;
    int nCharges = 0;
    const int bItemSkill = SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, 0, &nSkillLevel, &nCharges);
    if (!bItemSkill)
    {
        nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    }

    int nQuantity = 0;
    if (!bItemSkill)
    {
        nQuantity = SKILLS_GetQuantity(pSkill);
    }

    sub_004A9690_DrawSkillInfoBase(nValue, pSkillsTxt, nOwnerGUID, nCharges, nState, nX, nY, nArg);
    if (nQuantity)
    {
        sub_004AA1F0_DrawSkillQuantity(&pSkillsTxt->nSkillId, nState, nQuantity, nX, nY);
    }
    else
    {
        sub_004A8D50_UpdateButton(&pSkillsTxt->nSkillId, nState, nSkillLevel, nCharges, nX, nY);
    }
}

// 0x0049C7F0
void __cdecl sub_0049C7F0_BuildWaypointList()
{
    gnWaypointCount_007BF08A = 0;
    gnWaypointEnabled_007BF08E = 0;
    const int nCurrentLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0()));

    for (int i = 0; i < 9; ++i)
    {
        *(int*)gaWaypointEntries_007BF03C[i].nLevelId = 0;
        gaWaypointEntries_007BF03C[i].bEnabled = 0;
    }

    if ((unsigned int)gnWaypointAct_007BF086 > 5)
    {
        gbGlobal_007BF085 = 0;
        return;
    }

    if (!gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].bInit)
    {
        gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].bInit = 1;
        for (int nLevelId = *(int*)gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nFirstLevelId;
            nLevelId <= *(int*)gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nLastLevelId; ++nLevelId)
        {
            unsigned short wWaypoint;
            if (WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &wWaypoint))
            {
                const unsigned char nIndex = (unsigned char)wWaypoint;
                if (gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMinWaypoint == 0xFF)
                {
                    gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMinWaypoint = nIndex;
                }

                gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMaxWaypoint = nIndex > gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMaxWaypoint ? nIndex : gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMaxWaypoint;
            }
        }
    }

    for (int i = gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMinWaypoint; i <= gaWaypointActRanges_007224AC[gnWaypointAct_007BF086].nMaxWaypoint; ++i)
    {
        const unsigned short wWaypoint = (unsigned short)i;
        if (WAYPOINTS_IsActivated(gpWaypointData_007BF081, wWaypoint))
        {
            int nLevelId;
            if (WAYPOINTS_GetLevelIdFromWaypointNo(wWaypoint, &nLevelId))
            {
                *(int*)gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].nLevelId = nLevelId;
                if (nCurrentLevelId == nLevelId)
                {
                    gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].bEnabled = 0;
                }
                else
                {
                    ++gnWaypointEnabled_007BF08E;
                    gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].bEnabled = 1;
                }
                ++gnWaypointCount_007BF08A;
            }
        }
        else
        {
            int nLevelId;
            if (WAYPOINTS_GetLevelIdFromWaypointNo(wWaypoint, &nLevelId))
            {
                *(int*)gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].nLevelId = nLevelId;
                gaWaypointEntries_007BF03C[gnWaypointCount_007BF08A].bEnabled = 0;
                ++gnWaypointCount_007BF08A;
            }
        }
    }
}

// 0x004A1320
void __fastcall sub_004A1320_OpenTextPanel(unsigned short nStringId, int bSide, int bSound)
{
    if (!bSide)
    {
        gbTextSide_007BF236 = 0;
        gnGlobal_007225FC = 0x0C;
        gnGlobal_007BF278 = (gnGlobal_0071146C - 0x145) / 2;
    }
    else
    {
        gbTextSide_007BF236 = 1;
        gnGlobal_007225FC = 0x105 - gnGlobal_007A285C;
        gnGlobal_007BF278 = gnGlobal_007A2858;
    }

    sub_0044DA40();

    if (gnHintId_007BF260)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId_007BF260);
        if (nHint)
        {
            sub_004B9EF0_ArmHint(nHint, 0, 0, 4);
        }
        gnHintId_007BF260 = 0;
    }

    gnHintSound_007BF24B = 0;
    gdwGlobal_007BF20A = 0;

    D2RectStrc tRect;
    const int nScreenBottom = gnGlobal_00711470 - 0x35;
    tRect.nTop = gnGlobal_007225FC;
    tRect.nBottom = gnGlobal_007225FC + 0xB6;
    if (tRect.nBottom >= nScreenBottom)
    {
        tRect.nBottom = nScreenBottom;
    }
    tRect.nLeft = gnGlobal_007BF278 - 10;
    tRect.nRight = gnGlobal_007BF278 + 0x14F;
    sub_00467430(&tRect);
    sub_00466FE0();

    gwTextStringId_007BF212 = nStringId;
    if (gpTextBox_007BF0A4)
    {
        return;
    }

    gnGlobal_007BF1BC = 0;
    const int nOldFont = sub_00502EF0(8);
    gpTextBox_007BF0A4 = sub_004A05E0_CreateTextBox(D2LANG_GetStringFromTblIndex(nStringId), 2);
    D2_ASSERT(gpTextBox_007BF0A4, 0x1063);
    sub_00502EF0(nOldFont);

    *(int*)gpTextBox_007BF0A4->nScroll = 0;
    gnGlobal_007BF1C0 = 1;
    gnGlobal_007BF1FA = 1;
    if (!gbStarted_007BF27C)
    {
        gbStarted_007BF27C = 1;
        gnGlobal_007BF22C = GetTickCount();
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
    }

    const int nSoundId = sub_004E0650_GetStringSound(nStringId);
    if (nSoundId)
    {
        gnHintSound_007BF24B = sub_004B9A00(nSoundId, sub_00463DD0(), 5, 0, 0);
        gnHintId_007BF260 = nSoundId;
    }

    if ((nStringId == 0x7F || nStringId == 0x4E22 || nStringId == 0x4EC9 || nStringId == 0x4EA3 || nStringId == 0x18C) && bSound)
    {
        gbTextSound_007BF230 = 1;
    }
}

// 0x004C5EB0
int __fastcall sub_004C5EB0_ScanFind(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, int nArg, int* pOut)
{
    D2AreaScanFindStrc tFind = { 0, -1, 0, nArg, nArg, 0 };

    if (!nFlags)
    {
        nFlags = 0x583;
    }

    sub_004C5C40_ScanArea(pUnit, nX, nY, nRange, nFlags | 0xA280, sub_004C5E70_FindCallback, &tFind, 0);

    int nResult = tFind.nFirst;
    if (!nResult)
    {
        nResult = tFind.nSecond;
    }

    if (pOut)
    {
        *pOut = tFind.nOut;
    }

    return nResult;
}

// 0x004DB670
int __fastcall sub_004DB670_UpdateUnitGfx(D2UnitStrc* pUnit, int nArg)
{
    int nX = 0;
    int nY = 0;
    if (sub_004F51D0_IsPerspective())
    {
        sub_004F6760_PrecisionToScreen(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), 0, &nX, &nY);
        switch (sub_0045AE90())
        {
        case 1:
            nX -= gnGlobal_0071146C / 4;
            break;

        case 2:
            nX += gnGlobal_0071146C / 4;
            break;
        }
    }
    else
    {
        nX = UNITS_GetClientCoordX(pUnit) - sub_0045AFC0();
        nY = UNITS_GetClientCoordY(pUnit) - sub_0045AFD0_GetMouseYOffset();
    }

    if (!sub_004709A0_IsOnScreen(pUnit, nX, nY, 0, 0))
    {
        return 0;
    }

    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    int bShapeshifted = pUnit ? (pUnit->dwFlagEx >> 3) & 1 : 0;
    if (bShapeshifted && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = sub_004639D0_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    int nWeaponClassId[2];
    const int nId = COMPOSIT_GetWeaponClassId(pUnit, pInventory, nWeaponClassId, -1, 1);
    if (!sub_0046E5A0_FindGfxNode(pUnit, nId, -1) && !sub_0046FA80_LoadGfxNode(pUnit, nId, -1))
    {
        return 0;
    }

    void* pEntry = sub_0046E570_GetGfxEntry(pUnit, sub_0046DA60_GetUnitMode(pUnit));
    if (!pEntry)
    {
        return 0;
    }

    return sub_004DB0D0_UpdateGfxEntry(pEntry, nArg);
}

// 0x004E6560
void __fastcall sub_004E6560_SetItemPropTexts(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nArg1, int nArg2)
{
    if (!pItem || pItem->dwUnitType != 4)
    {
        return;
    }

    if (ITEMS_GetItemQuality(pItem) != 5)
    {
        return;
    }

    D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordFromItem(pItem);
    if (!pSetItemsTxt)
    {
        return;
    }

    int nMember;
    unsigned int nMask;
    switch (pSetItemsTxt->nAddFunc)
    {
    case 1:
    {
        nMask = ITEMS_GetSetItemsMask(pPlayer, pItem, 0);
        nMember = ITEMS_GetNoOfSetItemsFromItem(pItem);
        for (int i = 0; i < 6; ++i)
        {
            int nIndex = i;
            if (i == nMember)
            {
                continue;
            }

            if (i > nMember)
            {
                nIndex = i - 1;
            }

            if (nMask & (1 << i))
            {
                sub_004E60A0_AddSetPropText(pItem, nArg1, nArg2, 0, gaSetPropIds_006DBD70[nIndex], 0, 0, 1);
            }
        }
        break;
    }
    case 2:
    {
        const unsigned int nWorn = ITEMS_GetSetItemsMask(pPlayer, pItem, 1);
        const int nCount = (nWorn >= 0x40 ? 0 : gaSetPartialCounts_006DBD90[nWorn]) - 1;
        for (int i = 0; i < nCount; ++i)
        {
            sub_004E60A0_AddSetPropText(pItem, nArg1, nArg2, 0, gaSetPropIds_006DBD70[i], 0, 0, 1);
        }
        break;
    }
    }
}

static D2MonStatsTxt* MONSTATS_GetTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F3CE0
int __fastcall sub_004F3CE0_CreateSkillMissiles(D2UnitStrc* pUnit, int nSkillId, int nArg4, int nX, int nY, int nMonsterId)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (!MONSTATS_GetTxtRecord(nMonsterId))
    {
        return 0;
    }

    if (!nX || !nY)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x2001;
    tRequest.pUnit = pUnit;
    tRequest.nArg1 = nX;
    tRequest.nArg2 = nY;
    tRequest.nArg3 = nSkillId;
    tRequest.nArg4 = nArg4;
    tRequest.nArg0 = nMissile;
    D2UnitStrc* pMissile = sub_004CD540_HandleRequest(&tRequest);

    const int nMissileC = pSkillsTxt->wCltMissileC;
    if (nMissileC > 0 && nMissileC < sgptDataTables->nMissilesTxtRecordCount)
    {
        tRequest.nArg4 = 2;
        tRequest.nArg0 = nMissileC;
        sub_004CD540_HandleRequest(&tRequest);
    }

    const int nMissileB = pSkillsTxt->wCltMissileB;
    if (pMissile)
    {
        if (nMissileB > 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
        {
            sub_004CEFE0_AddMissileEffect(pMissile, nMissileB, 0, 2, 0);
        }

        if (!sub_004648F0_GetTargetUnit(pUnit) && pSkillsTxt->wTgtSound > 0)
        {
            sub_004B9A00(pSkillsTxt->wTgtSound, pMissile, 0, 0, 0);
        }
    }

    return 1;
}

#include "gen/data/Source/D2Client/WARDEN/WardenClient.inc"

void WardenModule_EmitDelete(WardenModule* pModule)
{
    delete pModule;
}

// 0x00480320
void __fastcall sub_00480320_CallHolderSlot3(int nArg)
{
    if (gpSlotHolder_007BC990)
    {
        gpSlotHolder_007BC990->pObj->Slot3(nArg);
        sub_00480230();
    }
}
