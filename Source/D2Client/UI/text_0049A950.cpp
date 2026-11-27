#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
#include "D2Primitives.h"
#include "D2Structs.h"
#include "D2Unicode.h"
#include "D2ClientQuestLog.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
#include "D2GfxApi.h"
#include "D2CMPApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;

struct D2RectStrc;

struct D2TextListStrc;

struct D2MsgHandlerEntryStrc;

class ListBoxWrapper;

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0





void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10





void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430








bool __stdcall sub_004A2970(int nX, int nY); // 0x004A2970




int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00


int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320



extern D2MsgHandlerEntryStrc gaKeyCaptureMButtonHandlers[]; // 0x0072472C

extern D2MsgHandlerEntryStrc gaKeyCaptureHandlers[]; // 0x00724738

extern D2MsgHandlerEntryStrc gaKeyCaptureXButtonHandlers[]; // 0x00724780

extern D2MsgHandlerEntryStrc gaKeyCaptureWheelHandlers[]; // 0x0072478C





extern char gData_007BF1B0[]; // 0x007BF1B0





class ListBoxWrapper
{
public:
    virtual ~ListBoxWrapper();
};



char gbQuestButtonDown; // 0x007BF2B0

char gbQuestDescriptionOpen; // 0x007BF2B3

#define SOUND_ID 4


ListBoxWrapper* gpListBox; // 0x007BF1B4

#define FIELD_OFFSET(T, F) ((unsigned long)&(((T*)0)->F))

#pragma pack(push, 2)

struct PackedNode
{
    char unused0[0x1e];
    int value;
    PackedNode* next;
};

#pragma pack(pop)

typedef char PackedNode_value_offset[(FIELD_OFFSET(PackedNode,value)==0x1e)?1:-1];

typedef char PackedNode_next_offset[(FIELD_OFFSET(PackedNode,next)==0x22)?1:-1];

typedef char PackedNode_size[(sizeof(PackedNode)==0x26)?1:-1];

extern "C" PackedNode* gtMessageTextList;

extern "C" { unsigned char gByte_007BF2B1; } // 0x007BF2B1

extern "C" unsigned char gByte_007BF2B2; // 0x007BF2B2

extern "C" unsigned char gByte_007BF2B0; // 0x007BF2B0

extern "C" int gnQuestPressedSlot; // 0x007BF2B5

extern "C" unsigned char gByte_007BF2B4; // 0x007BF2B4

extern "C" unsigned char gByte_007C025D; // 0x007C025D

extern "C" unsigned char gByte_007C025E; // 0x007C025E

extern "C" unsigned char gByte_007C025F; // 0x007C025F

extern "C" unsigned char gByte_007C0260; // 0x007C0260

struct SearchRecord
{
    char unused0[2];
    unsigned char value;
    unsigned char destination;
    char unused4[4];
    int key;
    char unusedC[0x4];
};

typedef char SearchRecord_size[(sizeof(SearchRecord)==0x10)?1:-1];

typedef char SearchRecord_key_offset[(FIELD_OFFSET(SearchRecord,key)==8)?1:-1];

typedef char SearchRecord_value_offset[(FIELD_OFFSET(SearchRecord,value)==2)?1:-1];

typedef char SearchRecord_destination_offset[(FIELD_OFFSET(SearchRecord,destination)==3)?1:-1];

extern "C" SearchRecord gSearch_00723F30[41];


struct OutputRecord
{
    char opaque[0x120];
};

struct InputRecord
{
    char unused0[0x12c];
    short value;
    char unusedAfterValue[0x66];
    short outputIndex;
    char unusedTail[0xa6];
};

struct TablesView
{
    char unused0[0xb8c];
    OutputRecord* outputs;
    int unusedBetweenOutputs;
    int outputCount;
    InputRecord* inputs;
    int unusedBetweenInputs;
    int inputCount;
};

typedef char OutputRecord_size[(sizeof(OutputRecord)==0x120)?1:-1];

typedef char InputRecord_size[(sizeof(InputRecord)==0x23c)?1:-1];

typedef char InputRecord_value_offset[(FIELD_OFFSET(InputRecord,value)==0x12c)?1:-1];

typedef char InputRecord_index_offset[(FIELD_OFFSET(InputRecord,outputIndex)==0x194)?1:-1];

typedef char TablesView_size[(sizeof(TablesView)==0xba4)?1:-1];

typedef char TablesView_outputs_offset[(FIELD_OFFSET(TablesView,outputs)==0xb8c)?1:-1];

typedef char TablesView_outputCount_offset[(FIELD_OFFSET(TablesView,outputCount)==0xb94)?1:-1];

typedef char TablesView_inputs_offset[(FIELD_OFFSET(TablesView,inputs)==0xb98)?1:-1];

typedef char TablesView_inputCount_offset[(FIELD_OFFSET(TablesView,inputCount)==0xba0)?1:-1];

extern "C" TablesView* gTables_00744304;

struct PayloadView
{
    char unused0[0x16];
    unsigned short flags;
    char unusedAfterFlags[4];
    unsigned char modifiers[10];
    short value26;
};

struct UnitView
{
    int type;
    char unused4[0x10];
    PayloadView* payload;
};

typedef char PayloadView_size[(sizeof(PayloadView)==0x28)?1:-1];

typedef char PayloadView_flags_offset[(FIELD_OFFSET(PayloadView,flags)==0x16)?1:-1];

typedef char PayloadView_modifiers_offset[(FIELD_OFFSET(PayloadView,modifiers)==0x1c)?1:-1];

typedef char PayloadView_value_offset[(FIELD_OFFSET(PayloadView,value26)==0x26)?1:-1];

typedef char UnitView_size[(sizeof(UnitView)==0x18)?1:-1];

typedef char UnitView_payload_offset[(FIELD_OFFSET(UnitView,payload)==0x14)?1:-1];

struct D2QuestTextsStrc;

struct D2UiEntry10Strc;

struct D2QuestPanelEntryStrc;

struct D2QuestSlotRectStrc;

struct D2ButtonLayoutStrc;

struct D2QuestTableStrc;

union D2SeedStrc;

extern D2UiEntry10Strc gaQuestLookup[41]; // 0x00723F38

extern int gaQuestPageDefault[5]; // 0x007BF280


D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0








void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0


extern D2QuestSlotRectStrc gaQuestSlots[]; // 0x00723EB0

int gnQuestCount; // 0x007BF2A0



extern D2QuestPanelEntryStrc gaQuestEntries[]; // 0x007BF3AA

char gbDurielCofsLoaded; // 0x007C025D

char gbAncientsCofsLoaded; // 0x007C025E

char gbHasQuestPacketValue; // 0x007C025F

char gbQuestUnitsSpawned; // 0x007C0260


void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00





extern int gnIndex_007BF2BD; // 0x007BF2BD

extern int gnIndex_007BF2C1; // 0x007BF2C1

extern int gnIndex_007BF2C5; // 0x007BF2C5

extern int gnIndex_007BF2C9; // 0x007BF2C9

extern int gnIndex_007BF2CD; // 0x007BF2CD

extern void* gapQuestIconCels[27]; // 0x007BF2E1

extern volatile char gabQuestFlagsB[]; // 0x007BF380






extern D2ButtonLayoutStrc gaButtonLayouts[]; // 0x007241C0




extern D2QuestTableStrc gaQuestTable[]; // 0x00723F30

typedef void (__stdcall* B27RecordHandler)(int, int, int);

typedef int (__cdecl* B27UIAction)();

extern "C" int __cdecl NPCMENU_ResurrectMercWait(); // 0x004B1DD0

extern "C" int __cdecl NPCMENU_IdentifyItemsWait(); // 0x004B2020

extern "C" unsigned int gnImbueMenuState;

extern "C" unsigned short gB27_00726CCB;

extern "C" unsigned int gB27_00726CDB;

extern "C" unsigned int gnHireMenuState;

extern "C" unsigned short gB27_00726E01;

extern "C" unsigned int gB27_00726E0F;

extern "C" unsigned int gnTravelLutGholeinState;

extern "C" unsigned short gB27_00726E4F;

extern "C" unsigned int gB27_00726E5D;

extern "C" unsigned int gnTravelKurastDocksState;

extern "C" unsigned short gB27_00726E9D;

extern "C" unsigned int gB27_00726EAB;

extern "C" unsigned int gnIdentifyMenu1State;

extern "C" unsigned short gwIdentifyMenu1StringId;

extern "C" B27UIAction gpfnIdentifyMenu1Handler;

extern "C" unsigned int gnIdentifyMenu2State;

extern "C" unsigned short gwIdentifyMenu2StringId;

extern "C" B27UIAction gpfnIdentifyMenu2Handler;

extern "C" unsigned int gnIdentifyMenu3State;

extern "C" unsigned short gwIdentifyMenu3StringId;

extern "C" B27UIAction gpfnIdentifyMenu3Handler;

extern "C" unsigned int gnIdentifyMenu4State;

extern "C" unsigned short gwIdentifyMenu4StringId;

extern "C" B27UIAction gpfnIdentifyMenu4Handler;

extern "C" unsigned int gnTravelHarrogathState;

extern "C" unsigned short gwTravelHarrogathStringId;

extern "C" unsigned short gB27_00726F87;

extern "C" unsigned int gpfnTravelHarrogathHandler;

extern "C" unsigned int gB27_00726F95;

extern "C" unsigned int gnIdentifyMenu5State;

extern "C" unsigned short gwIdentifyMenu5StringId;

extern "C" B27UIAction gpfnIdentifyMenu5Handler;

extern "C" unsigned int gnSocketMenuState;

extern "C" unsigned short gB27_00727247;

extern "C" unsigned int gB27_00727257;

extern "C" unsigned int gnPersonalizeMenuState;

extern "C" unsigned short gB27_00727297;

extern "C" unsigned int gB27_007272A9;

extern "C" unsigned int gnResurrectMenuState;

extern "C" unsigned short gB27_007272E1;

extern "C" B27UIAction gpfnResurrectMenuHandler;

extern "C" unsigned int gB27_007272EF;

extern "C" int gB27_007BCBF0;

extern "C" int gB27_007BF298; // 0x007BF298

extern "C" unsigned char gB27_007C025F; // 0x007C025F

extern "C" unsigned int gbQuestPacketValue; // 0x007C0265

// build: symbol _gpfnRecordHandler 0x00881834
extern "C" B27RecordHandler gpfnRecordHandler;

extern "C" unsigned int gnVirtualPlayerCount;


extern unsigned int gnQuestUnitId; // 0x007C0261


char gabQuestFlagsA[42]; // 0x007BF356

extern "C" B27RecordHandler __fastcall sub_005173D3_ExchangeRecordHandler(B27RecordHandler handler); // 0x005173D3

static inline int TEXT_FindEntryIndex(int nId);



D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10


void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __stdcall sub_004A1770(SMSGHANDLER_PARAMS* pMsg); // 0x004A1770

extern int gdwGlobal_007BF23F; // 0x007BF23F


// 0x004A01A0
void __cdecl TEXT_CloseMessageLogDialog()
{
    if (gpListDialog)
    {
        DIALOG_DestroyDialog(gpListDialog);
        gpListDialog = 0;
    }

    if (gpListBox)
    {
        delete gpListBox;
        gpListBox = 0;
    }
}

// 0x004A1760
int __cdecl TEXT_Forward()
{
// build: symbol ?TEXT_CloseText@* 0x004A08C0
    return TEXT_CloseText();
}

// 0x004A1770
void __stdcall TEXT_KeyUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?gbTextPanelOpen@* 0x007BF1FA
    gbTextPanelOpen = 0;
    if (GetTickCount() - gnStartTick < 100)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
// build: symbol ?gbTextCallbackAccepted@* 0x007BF23F
        gbTextCallbackAccepted = 0;
        return;
    }

    if (TEXT_CloseText())
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x004A17D0
void __stdcall sub_004A17D0_FilterNpcClick(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_007BF23F = 1;
    if (SELECT_GetSelectedUnit())
    {
// build: symbol ?gnTextNpcId@* 0x007BF202
// build: symbol ?gbTextFromObject@* 0x007BF20A
        if (gbTextFromObject && CUNIT_FindClientUnit(gnTextNpcId, 1) == SELECT_GetSelectedUnit())
            return;
    }
    else if (!SELECT_GetSelectedUnit() && gbTextHoverSet)
    {
// build: symbol ?gnTextHoverUnitId@* 0x007BF23B
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnTextHoverUnitId, 1);
        if (pUnit && pUnit == CUNIT_FindClientUnit(gnTextNpcId, 1))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
        }
        return;
    }
    sub_004A1770(pMsg);
}


// 0x004A1870
void __stdcall TEXT_HotkeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (CUNIT_HasHotkeyBinding(7, 1))
    {
        unsigned short nKey = CUNIT_GetHotkeyBinding(7, 1);
        if (nKey != 0xFFFF && nKey <= 0xDF && pMsg->wParam == nKey)
        {
            return;
        }
    }

    TEXT_KeyUpMsg(pMsg);
}

// 0x004A18C0
void __stdcall TEXT_KeyDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam != 0x73)
    {
        TEXT_HotkeyMsg(pMsg);
    }
}






// build: symbol _TEXT_ClearListFlags 0x004A01E0
extern "C" void __cdecl TEXT_ClearListFlags(void)
{
    for (PackedNode* p = gtMessageTextList; p; p = p->next)
        p->value = 0;
}













// build: symbol _CUNIT_IsInvPanelTradeMode 0x00489840
extern "C" int __cdecl INV_IsInvPanelTradeMode()
{
    int mode = gB27_007BCBF0;
    if (mode == 1 || mode == 2 || mode == 3)
        return 1;
    return 0;
}

// build: symbol _NPCMENU_ResetHandlers 0x004B2250
extern "C" void __cdecl NPCMENU_ResetHandlers()
{
    bool oldAction = (gpfnResurrectMenuHandler == NPCMENU_ResurrectMercWait);
    gnHireMenuState = 2;
    gB27_00726E01 = 0;
    gB27_00726E0F = 0;
    gnTravelLutGholeinState = 2;
    gB27_00726E4F = 0;
    gB27_00726E5D = 0;
    gnTravelKurastDocksState = 2;
    gB27_00726E9D = 0;
    gB27_00726EAB = 0;
    gnImbueMenuState = 3;
    gB27_00726CCB = 0;
    gB27_00726CDB = 0;
    gnResurrectMenuState = 2;
    gB27_007272E1 = 0;
    gB27_007272EF = 0;
    if (oldAction)
        gnResurrectMenuState = 3;
    gB27_00727247 = 0;
    gB27_00727257 = 0;
    gB27_00727297 = 0;
    gB27_007272A9 = 0;
    gnTravelHarrogathState = 2;
    gB27_00726F87 = 0;
    gB27_00726F95 = 0;
    gwTravelHarrogathStringId = 0;
    gpfnTravelHarrogathHandler = 0;
    gnSocketMenuState = 3;
    gnPersonalizeMenuState = 4;
    gwIdentifyMenu1StringId = 0xfb4;
    gpfnIdentifyMenu1Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu1State = 3;
    gwIdentifyMenu2StringId = 0xfb4;
    gpfnIdentifyMenu2Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu2State = 3;
    gwIdentifyMenu3StringId = 0xfb4;
    gpfnIdentifyMenu3Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu3State = 3;
    gwIdentifyMenu4StringId = 0xfb4;
    gpfnIdentifyMenu4Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu4State = 3;
    gwIdentifyMenu5StringId = 0xfb4;
    gpfnIdentifyMenu5Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu5State = 3;
}

// build: symbol @PLAYER_SetVirtualPlayerCount@* 0x00535780
extern "C" void __fastcall PLAYER_SetVirtualPlayerCount(unsigned int count)
{
    if (count <= 8)
        gnVirtualPlayerCount = count;
}
















// build: symbol @SPELLSEL_GetSkillMaxLevel@* 0x004AA8B0
extern "C" int __fastcall SPELLSEL_GetSkillMaxLevel(int index)
{
    if (index >= 0 && index < gTables_00744304->inputCount)
    {
        int value = gTables_00744304->inputs[index].value;
        if (value > 0)
            return value;
    }
    return 20;
}

#include "gen/data/Source/D2Client/UI/text_0049A950.inc"
