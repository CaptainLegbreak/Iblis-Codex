#include <D2UnitData.h>
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Primitives.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Win32Types.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct D2CelFileStrc;
struct Unicode;
struct D2MonsterDataStrc;
struct D2ClientNotifyStrc;
struct D2ClientNodeStrc;
struct D2RosterSubStrc;
struct D2RosterEntryStrc;
struct D2RC4Strc;
struct D2ClientSlotObjStrc;
struct D2ClientSlotHolderStrc;
struct D2ClientRecordStrc;
struct D2ClientStringListStrc;
struct D2ItemStatCostTxt;
struct D2NpcButtonStrc;
struct D2StaticPathStrc;
struct D2InventoryGridInfoStrc;
struct D2PanelButtonStrc;
struct RangeNode;
struct LookupNode;
struct ColorView;
union PackedWord;
struct D2BodyLocRectStrc;
struct SMSGHANDLER_PARAMS;
struct D2UnitStrc;
struct D2ClientServiceStrc;
struct D2DataTablesStrc;
struct D2ItemsTxt;
struct D2AuxLevelEntryStrc;
struct D2GfxDataStrc;
struct D2HirelingIconRecordStrc;
struct D2PanelLabelStrc;

extern void* ghDbgHelp_0098A680; // 0x0098A680
extern int gdwGlobal_007A0670; // 0x007A0670
extern int gnGlobal_007A5254; // 0x007A5254

extern D2UnitStrc* gdwGlobal_007BCBF4; // 0x007BCBF4

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned short nWParamLo;
    short nWParamHi;
    union
    {
        struct
        {
            unsigned int lParam;
        };
        struct
        {
            unsigned short nXpos;
            unsigned short nYpos;
        };
    };
    unsigned int dwCommandSource;
    unsigned int dwArg;
    int bReturn;
    int lResult;
};

struct Unicode
{
    unsigned short wChar;
    static Unicode* __fastcall strncpy(Unicode* dest, const Unicode* src, int count);                       // 0x00526790
};

struct D2ClientNotifyStrc
{
    char unk0x00[0x90];
    void (__cdecl* pfnNotify)();
};

struct D2ClientNodeStrc
{
    char unk0x00[0x08];
    int nId;
    char unk0x0C[0x08];
    int nValueA;
    int nValueB;
    char unk0x1C[0x14];
    D2ClientNodeStrc* pNext;
};

struct D2RosterSubStrc
{
    int nUnk0x00;
    D2RosterSubStrc* pNext;
};

struct D2RosterEntryStrc
{
    char unk0x00[0x34];
    void* pResource;
    D2RosterSubStrc* pSubList;
    char unk0x3C[0x44];
    D2RosterEntryStrc* pNext;
};

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_0047F8C0_Crypt(unsigned char* pData, unsigned int nSize);
};

struct D2ClientServiceStrc
{
    char unk0x00[0xD0];
    int (__fastcall* pfnCall)(int nArg1, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

struct D2ClientSlotObjStrc
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
};

struct D2ClientSlotHolderStrc
{
    char unk0x00[0x0C];
    D2ClientSlotObjStrc* pObj;
};

struct D2ClientRecordStrc
{
    unsigned char nId;
    unsigned char nType;
    unsigned char nFlag;
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_5;
    unsigned char nValue3;
    unsigned char nUnk0x07;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    int nUnk0x20;
    int nUnk0x24;
};

struct D2ClientStringListStrc
{
    Unicode* pStrings[6];
    unsigned short nCount;
    unsigned char f_1A[4];
    unsigned char unk0x1E[8];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
D2ClientNotifyStrc* __cdecl sub_0044B7B0_GetNotify(); // 0x0044B7B0
void __cdecl sub_0044DA70(); // 0x0044DA70
int __cdecl sub_0044DCC0(); // 0x0044DCC0
int __fastcall sub_004538D0(int nUIVar); // 0x004538D0
int __fastcall sub_00453A90_GetUIVarUnchecked(int nUIVar); // 0x00453A90
int __fastcall sub_00455F20(int nUIVar, int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00467A10(); // 0x00467A10
void __fastcall sub_00468070_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
void __cdecl sub_00468F00(); // 0x00468F00
void __fastcall sub_00478600_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __cdecl sub_00480230(); // 0x00480230
void __cdecl sub_0048A050(); // 0x0048A050
void __cdecl sub_0048A730(); // 0x0048A730
void __cdecl sub_00494FC0(); // 0x00494FC0
void __fastcall sub_0049EB10_PostRecord(D2ClientRecordStrc* pRecord); // 0x0049EB10
void __stdcall sub_004A1770(SMSGHANDLER_PARAMS* pMsg); // 0x004A1770
void __cdecl sub_004B8CB0(); // 0x004B8CB0
void __fastcall sub_004DC2B0(void* pResource); // 0x004DC2B0
int __cdecl D2GFX_GetResolutionMode(); // 0x004F5160
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
extern int gnGlobal_0071146C; // 0x0071146C
extern int gnGlobal_00711470; // 0x00711470
extern int gnGlobal_00721E3C; // 0x00721E3C
extern int gnGlobal_00721E40; // 0x00721E40
extern int gnGlobal_00721E44; // 0x00721E44
extern int gnGlobal_00721E48; // 0x00721E48
extern int gnGlobal_00721E4C; // 0x00721E4C
extern int gnGlobal_00721E50; // 0x00721E50
extern int gdwGlobal_007A0618; // 0x007A0618
extern int gdwGlobal_007A061C; // 0x007A061C
extern int gdwGlobal_007A0620; // 0x007A0620
extern int gnGlobal_007A2858; // 0x007A2858
extern int gnGlobal_007A285C; // 0x007A285C
extern D2ClientNodeStrc* gpNodeList_007BB5BC; // 0x007BB5BC
extern D2RosterEntryStrc* gpRosterListA_007BB5C0; // 0x007BB5C0
extern int gdwGlobal_007BB5DC; // 0x007BB5DC
extern unsigned char gnGlobal_007BB5E0; // 0x007BB5E0
extern D2ClientSlotHolderStrc* gpSlotHolder_007BC990; // 0x007BC990
extern int gdwGlobal_007BCBE4; // 0x007BCBE4
extern int gdwGlobal_007BCBF0; // 0x007BCBF0
extern int gdwGlobal_007BCEA4; // 0x007BCEA4
extern Unicode gwszName_007BCEA8[]; // 0x007BCEA8
extern unsigned char gnGlobal_007BF23A; // 0x007BF23A
extern int gdwGlobal_007BF23F; // 0x007BF23F
extern int gnHotkeySkill_007C06C8[16]; // 0x007C06C8
extern int gnHotkeyOwner_007C0768[16]; // 0x007C0768
extern int gbHotkeyLeft_007C07B8[16]; // 0x007C07B8
extern unsigned char gaTable_007C0EA4[]; // 0x007C0EA4
extern int gdwTableInit_007C0ECC; // 0x007C0ECC
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

struct D2ItemStatCostTxt
{
    char unk0x00[0x144];
};

struct D2DataTablesStrc
{
    char unk0x00[0xBCC];
    D2ItemStatCostTxt* pItemStatCostTxt;
    char unk0xBD0[0xBD4 - 0xBD0];
    int nItemStatCostTxtRecordCount;
    unsigned char unk_BD8[0x18];
    int nPetTypeTxtRecordCount;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360
void __stdcall sub_Z12_EmitUse(int nMin, int nMax, int bModified);
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

struct D2NpcButtonStrc
{
    int nId;
    int bActive;
    char unk0x08[0x0C];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __cdecl sub_0044DB30(); // 0x0044DB30
void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath); // 0x004520C0
int __cdecl sub_00468830(); // 0x00468830
void __fastcall sub_00478590(char nValue); // 0x00478590
void __fastcall sub_00478A00(void* pCel); // 0x00478A00
void __fastcall sub_00480930(int nType, int nUnitId); // 0x00480930
void __cdecl sub_004B90B0(); // 0x004B90B0
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __fastcall sub_004C21F0(D2UnitStrc* pItem); // 0x004C21F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
extern int gnGlobal_00721E54; // 0x00721E54
extern int gnButtonCount_00722160; // 0x00722160
extern int gnGlobal_007BCA4C; // 0x007BCA4C
extern int gnGlobal_007BCAF0; // 0x007BCAF0
extern int gnGlobal_007BCBD8; // 0x007BCBD8
extern int gdwGlobal_007BCBE8; // 0x007BCBE8
extern int gdwGlobal_007BCBF8; // 0x007BCBF8
extern unsigned char gnSelectedTab_007BCC04; // 0x007BCC04
extern int gnQuestTimerValue_007BCC14; // 0x007BCC14
extern unsigned long gdwQuestTimerTicks_007BCC18; // 0x007BCC18
extern D2CelFileStrc* gpCellFile_007BCC24; // 0x007BCC24
extern D2CelFileStrc* gpCellFile_007BCC28; // 0x007BCC28
extern D2CelFileStrc* gpCellFile_007BCC38; // 0x007BCC38
extern int gbWeaponSwitch_007BCC4C; // 0x007BCC4C
extern int gnGlobal_007BCD34; // 0x007BCD34
extern int gnGlobal_007BCE14; // 0x007BCE14
extern "C" int gnFlag_007BCE28; // 0x007BCE28
extern int gnGlobal_007BCE30; // 0x007BCE30
extern void* gpCel_007BCE8C; // 0x007BCE8C
extern int gnGlobal_007BCE9C; // 0x007BCE9C

struct D2ItemsTxt
{
    char unk0x00[0x80];
    int dwCode;
};

extern D2InventoryGridInfoStrc gGrid_007BCA78; // 0x007BCA78
extern D2InventoryGridInfoStrc gGrid_007BCB40; // 0x007BCB40
extern D2InventoryGridInfoStrc gGrid_007BCB88; // 0x007BCB88
extern int gnGlobal_007BCC50; // 0x007BCC50
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg); // 0x00478680
void __fastcall sub_004786D0_SendPacket(char nHeader, int nArg1, int nArg2, int nArg3); // 0x004786D0
int __cdecl sub_00486D10_CheckTick(); // 0x00486D10
void __fastcall sub_0049FF90_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt); // 0x0049FF90
int __fastcall sub_004C1E20(D2UnitStrc* pItem); // 0x004C1E20
int __fastcall sub_004C2240(D2UnitStrc* pItem); // 0x004C2240
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050
int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590
int __stdcall sub_00628C20(D2UnitStrc* pItem); // 0x00628C20
int __stdcall sub_00628C70(D2UnitStrc* pItem); // 0x00628C70
int __stdcall sub_0062A0A0(D2UnitStrc* pItem); // 0x0062A0A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall sub_0063BD10(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall sub_004B3870(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x004B3870
void __cdecl sub_K04_EmitUse(int nValue);

#pragma pack(push, 2)
struct D2PanelButtonStrc
{
    int bActive;
    int nValue;
    unsigned short nString;
    int nCel;
    unsigned short nFrame;
    int nType;
};

#pragma pack(pop)

extern D2PanelButtonStrc gaPanelButtons_007BC9E0[]; // 0x007BC9E0
int __cdecl sub_004B3500(); // 0x004B3500
int __fastcall sub_004B3230_GetSelectedUnitId(int* pUnitId); // 0x004B3230
extern unsigned char gnMaxTab_007BCC05; // 0x007BCC05

struct RangeNode
{
    char gap00[0x204];
    unsigned int start;
    unsigned int size;
    RangeNode* next;
};

struct LookupNode
{
    char gap00[0x8];
    unsigned int key;
    char gapAfterKey[0x10];
    unsigned int value;
    char gapAfterValue[0x10];
    LookupNode* next;
};

struct ColorView
{
    char gap00[0x10];
    unsigned int color;
};

union PackedWord
{
    unsigned int word;
    struct Bytes
    {
        unsigned char low;
        unsigned char high;
        unsigned char third;
        unsigned char fourth;
    } bytes;
};

typedef char packed_word_size[sizeof(PackedWord)==4?1:-1];

typedef char packed_high_lane[OFFSET(PackedWord::Bytes,high)==1?1:-1];

typedef char RangeNode_start[OFFSET(RangeNode,start)==0x204?1:-1];

typedef char RangeNode_size[OFFSET(RangeNode,size)==0x208?1:-1];

typedef char RangeNode_next[OFFSET(RangeNode,next)==0x20C?1:-1];

typedef char LookupNode_key[OFFSET(LookupNode,key)==0x8?1:-1];

typedef char LookupNode_value[OFFSET(LookupNode,value)==0x1C?1:-1];

typedef char LookupNode_next[OFFSET(LookupNode,next)==0x30?1:-1];

typedef char ColorView_color[OFFSET(ColorView,color)==0x10?1:-1];

extern "C" LookupNode* gLookupHead_007BB5BC;
extern "C" unsigned int gValue_007A065C;
extern "C" unsigned int gValue_007A0660;
extern "C" unsigned int gValue_007A0664;
extern "C" unsigned int gValue_007A6ABC;
extern "C" unsigned int gValue_007A6ADC;
extern "C" unsigned int gValue_007A6AE0;
extern "C" unsigned int gValue_007A6AF0;
extern "C" unsigned int gValue_00712F44;
extern "C" unsigned int gValue_00712F48;
extern "C" unsigned int gValue_007BB5D8;
extern "C" unsigned int gValue_007BB5E8;
extern "C" unsigned int gValue_007BCBF0; // 0x007BCBF0
extern "C" unsigned int gValue_007BCE2C; // 0x007BCE2C
extern "C" unsigned short gValue_007BB5E4;
extern "C" const unsigned char gColorTable_00971740[];
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

extern U8 gColor;
extern int gScreenHeight;
extern int gScreenWidth;
extern U32 gUiState; // 0x007BCBF0
extern void* gResourceA;
extern void* gResourceB;
void __cdecl InitializePalette();
void __fastcall sub_004F6300(int x, int y, int width, int height, int color, int mode);
int __stdcall ReleaseResource(void* resource);
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __fastcall sub_00479120_GetHirelingClassId(int nUnitId); // 0x00479120
unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0
int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0
void __stdcall sub_Z12_EmitUse2(int nValue1, int nValue2);

struct D2BodyLocRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned char unk0x12[2];
};

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc); // 0x0062ED50
void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
extern D2BodyLocRectStrc gaBodyLocRects_007BCD38[11]; // 0x007BCD38
extern int gnAutomapWidth_007A5220; // 0x007A5220
extern int gnAutomapHeight_007A521C; // 0x007A521C
int __fastcall sub_00478F20_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
extern unsigned char gbGlobal_007BCAD8; // 0x007BCAD8
extern unsigned char gbGlobal_007BCAD9; // 0x007BCAD9
void __stdcall sub_00467FA0(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0
int __fastcall sub_004C1D60(D2UnitStrc* pItem); // 0x004C1D60
void __fastcall sub_004785B0_SendPacket3(unsigned char nCmd, unsigned short nArg); // 0x004785B0
extern int gnGlobal_007BCEA0; // 0x007BCEA0
extern "C" int gnModeValue_00712CCC; // 0x00712CCC
extern "C" int gnValue_007C0C3C; // 0x007C0C3C
extern "C" unsigned char gbFlag_007BC9D4; // 0x007BC9D4
extern "C" unsigned char gbFlag_007BC9D8; // 0x007BC9D8
extern "C" int gnScreenHeight_00711470; // 0x00711470
void __cdecl sub_0044DA40(); // 0x0044DA40
extern int gnGlobal_007BCC54; // 0x007BCC54
void __fastcall sub_0046EE80_DrawCursorItem(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80
void __stdcall sub_00483E40(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40
void __fastcall sub_0048B3F0_DrawMercEquipHighlights(D2UnitStrc* pUnit); // 0x0048B3F0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

typedef void (__fastcall *UnitCallback)(Unit*);

extern U32 gSelectionState; // 0x007BCC50
extern U8 gPaletteA;
extern U8 gPaletteB;
extern U8 gPaletteC;
extern U8 gPaletteD;
void __fastcall sub_004649D0(UnitCallback callback); // 0x004649D0
void __fastcall sub_00489DA0(Unit* unit); // 0x00489DA0
U32 __stdcall PaletteColor(U32 red, U32 green, U32 blue);
void __fastcall sub_00478600(U8 command, U16 value, U32 word2, U32 word3); // 0x00478600
static void sub_0048B540_DrawEquippedItems(D2UnitStrc* pUnit);

struct D2AuxLevelEntryStrc
{
    int nType;
    int unk0x04[2];
};

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
D2CelFileStrc* __fastcall sub_004788B0(const char* szFile, int nType); // 0x004788B0
D2BitBufferStrc* __cdecl sub_004B32D0(); // 0x004B32D0
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C360
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern D2AuxLevelEntryStrc gaAuxLevelEntries_00721D98[]; // 0x00721D98
extern int gbQuestTimerActive_007BCC10; // 0x007BCC10
extern D2CelFileStrc* gpHoradricCel_007BCC1C; // 0x007BCC1C
static void __stdcall sub_00485240_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified);
Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20
void __fastcall sub_004521C0_SetTextColor(Unicode* pText, int nColor); // 0x004521C0
int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625560
int __stdcall ITEMS_GetMissileType(D2UnitStrc* pItem); // 0x006288A0
int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0062A1E0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
int __stdcall MISSILE_GetMinDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AF20
int __stdcall MISSILE_GetMaxDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064AFF0
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0
int __stdcall sub_0064B2A0(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B2A0

struct D2GfxDataStrc
{
    int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCellFile;
    char unk0x38[0x08];
    int nDirection;
    char unk0x44[0x04];
};

void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall sub_00502EF0(int nArg); // 0x00502EF0
extern D2CelFileStrc* gpGoldButtonCel_007BCC34; // 0x007BCC34
extern int gbGoldButtonDown_007BCE30; // 0x007BCE30
extern int gbGoldButtonDown_007BCE34; // 0x007BCE34
extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC
static int __stdcall sub_00486820_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight); // 0x00486820

struct D2HirelingIconRecordStrc
{
    int unk0x00[5];
};

#pragma pack(push, 2)
struct D2PanelLabelStrc
{
    int nX;
    int nX2;
    int nY;
    unsigned short nString;
};

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0
extern "C" size_t __cdecl strlen(const char* szString);
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __cdecl sub_00525150(); // 0x00525150
void __fastcall sub_0045AEA0_SetPanelSlide(int nMode); // 0x0045AEA0
Unicode* __fastcall sub_00526940_UnicodeStrStr(const Unicode* pString, const Unicode* pPattern); // 0x00526940
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
void __fastcall sub_004A7080(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
const Unicode* __fastcall sub_00464A60_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
int __fastcall sub_004A7660_SplitAtNewLine(Unicode* wszText, Unicode** ppSecond); // 0x004A7660
unsigned short __fastcall sub_00469AA0(int nA, int nB); // 0x00469AA0
const Unicode* __fastcall sub_0046A530_GetKeyName(int nA, int nB); // 0x0046A530
extern int gnGlobal_007BCA48; // 0x007BCA48
extern D2CelFileStrc* gpCellFile_007BCC2C; // 0x007BCC2C
extern D2CelFileStrc* gpCellFile_007BCC3C; // 0x007BCC3C
extern D2CelFileStrc* gpCellFile_007BCC30; // 0x007BCC30
extern D2CelFileStrc* gpCellFile_007BCB04; // 0x007BCB04
extern D2PanelLabelStrc gaPanelLabels_006D9AE8[12]; // 0x006D9AE8
extern void* gpCellFile_007BEF7C; // 0x007BEF7C
extern void* gpCellFile_007BEF78; // 0x007BEF78
extern void* gpCellFile_007BEF10; // 0x007BEF10
extern void* gpCellFile_007BEF2C; // 0x007BEF2C
extern void* gpCellFile_007BEF20; // 0x007BEF20
extern D2HirelingIconRecordStrc* gpHirelingRecords_007BEEAC; // 0x007BEEAC

int gdwGlobal_007BC974; // 0x007BC974

// 0x00402A80
int __cdecl sub_00402A80_IsDbgHelpLoaded()
{
    return ghDbgHelp_0098A680 != 0;
}

// 0x0044BFF0
int __cdecl sub_0044BFF0_IsSet()
{
    return gdwGlobal_007A0670 != 0;
}

void __cdecl sub_004972B0_InitializePalette(); // 0x004972B0

int gnQuestTimerValue_007BCC14; // 0x007BCC14

unsigned long gdwQuestTimerTicks_007BCC18; // 0x007BCC18

// 0x004521C0
Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit)
{
    if (pText->wChar)
    {
        Unicode wszBuffer[0x400];
        wszBuffer[0].wChar = 0;
        for (int i = 1; i < 0x400; i++)
        {
            wszBuffer[i].wChar = 0;
        }
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
        Unicode wszDigit[3];
        wszDigit[0].wChar = 0;
        wszDigit[1].wChar = 0;
        wszDigit[2].wChar = 0;
        char szDigit[4];
        wsprintfA(szDigit, "%c", (char)(nDigit + '0'));
        sub_00526F20_ToUnicode(wszDigit, szDigit, 2);
        sub_00526700(wszBuffer, wszDigit);
        sub_00526700(wszBuffer, pText);
        sub_005267E0(pText, wszBuffer);
    }
    return pText;
}

// 0x00454970
extern "C" int __cdecl sub_00454970_GetScreenHeightMinus49()
{
    return gnScreenHeight_00711470 - 49;
}

// 0x0045FDD0
int __cdecl sub_0045FDD0_IsSet()
{
    return gnGlobal_007A5254 != 0;
}

extern "C" { int gnFlag_007BCE28; } // 0x007BCE28

extern "C" { int gnFlag_007C02EC; } // 0x007C02EC

// 0x004776F0
extern "C" void __cdecl sub_004776F0_SetModeValue4()
{
    gnModeValue_00712CCC = 4;
}

// 0x00477700
extern "C" void __cdecl sub_00477700_SetModeValue5()
{
    gnModeValue_00712CCC = 5;
}

// 0x00477710
extern "C" void __cdecl sub_00477710_SetModeValue6()
{
    gnModeValue_00712CCC = 6;
}

// 0x00477720
extern "C" void __cdecl sub_00477720_SetModeValue7()
{
    gnModeValue_00712CCC = 7;
}

int gnSentBytes_007A6AF8; // 0x007A6AF8

int gnSentPackets_007A6B00; // 0x007A6B00


int gdwGlobal_007BB5EC; // 0x007BB5EC

D2ClientServiceStrc* gpService_007BC998; // 0x007BC998

int gdwGlobal_007BCBE8; // 0x007BCBE8

int gdwGlobal_007BCBF8; // 0x007BCBF8

int gdwGlobal_007BEEFC; // 0x007BEEFC

// 0x00477EE0
void __cdecl sub_00477EE0_SendPacket69()
{
    unsigned char nHeader = 0x69;
    sub_0052AE50_SendPacket(1, 0, &nHeader);
    gnSentBytes_007A6AF8 += 1;
    gnSentPackets_007A6B00 += 1;
    if (gdwGlobal_007A0610 != 0 && gdwGlobal_007A0610 != 1 && gdwGlobal_007A0610 != 6 && gdwGlobal_007A0610 != 7
        && gdwGlobal_007A0610 != 8 && gdwGlobal_007A0610 != 9)
    {
        gdwGlobal_007A0620 = 1;
        gdwGlobal_007A061C = 0;
        gdwGlobal_007A0618 = 0;
    }
    if (gdwGlobal_007A0610 == 6 || gdwGlobal_007A0610 == 7)
    {
        D2ClientNotifyStrc* pNotify = sub_0044B7B0_GetNotify();
        if (pNotify)
            pNotify->pfnNotify();
    }
}

// 0x00478010
void __cdecl sub_00478010()
{
    unsigned char nHeader = 0x6A;
    sub_0052AE50_SendPacket(1, 0, &nHeader);
    gnSentBytes_007A6AF8 += 1;
    gnSentPackets_007A6B00 += 1;
}

// 0x004790B0
void __fastcall sub_004790B0_FindNodeValues(int nId, int* pValueA, int* pValueB)
{
    for (D2ClientNodeStrc* pNode = gpNodeList_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
        {
            *pValueA = pNode->nValueA;
            *pValueB = pNode->nValueB;
            return;
        }
    }
    *pValueA = 0;
    *pValueB = 0;
}

// 0x0047AD10
void __stdcall sub_0047AD10_ResetSelectionMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gwGlobal_007BC850 = 0;
    gwGlobal_007BB5F8 = 0;
    gdwGlobal_007BB5EC = -2;
    if (gdwGlobal_007BB5DC == 6)
        gnGlobal_007BB5E0 = 0;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0047B070
void __stdcall sub_0047B070_SetHandled(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x0047BC70
void __stdcall sub_0047BC70_LowClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->nYpos > gnGlobal_00711470 - 0x31)
        sub_00455F20(5, 1, 0);
}

// 0x0047EC40
int __cdecl sub_0047EC40_IsSet()
{
    return gdwGlobal_007BC974 != 0;
}

// 0x0047F8C0
void D2RC4Strc::sub_0047F8C0_Crypt(unsigned char* pData, unsigned int nSize)
{
    for (unsigned int n = 0; n < nSize; ++n)
    {
        ++i;
        j += S[i];
        unsigned char* pA = &S[i];
        unsigned char* pB = &S[j];
        unsigned char t = *pA;
        *pA = *pB;
        *pB = t;
        pData[n] ^= S[(unsigned char)(S[j] + S[i])];
    }
}

// 0x0047FFB0
int __stdcall sub_0047FFB0_CallServiceWithTime(int nArg1, int nArg2, int nArg3)
{
    if (!gpService_007BC998)
        return 0;
    _FILETIME tTime;
    GetSystemTimeAsFileTime(&tTime);
    return gpService_007BC998->pfnCall(nArg1, nArg2, nArg3, &tTime, -1, -1);
}

// 0x004802E0
void __fastcall sub_004802E0_CallHolderSlot2(int nArg1, int nArg2)
{
    if (gpSlotHolder_007BC990)
    {
        int nOut = 0;
        gpSlotHolder_007BC990->pObj->Slot2(nArg1, nArg2, &nOut);
        sub_00480230();
    }
}

// 0x00482CA0
void __fastcall sub_00482CA0_RaiseAuxLevel(int nIndex)
{
    const int nType = gaAuxLevelEntries_00721D98[nIndex].nType;
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d = 0x22;
    unsigned char nLevel;
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        sscanf(szAddress, "%d.%d.%d.%d", &a, &b, &c, &d);
        const unsigned char nLow = d;
        if (nLow & 1)
            nLevel = 7;
        else if (nLow & 0x80)
            nLevel = 6;
        else if (nLow & 0x10)
            nLevel = 5;
        else if (nLow & 0x08)
            nLevel = 4;
        else if (nLow & 0x40)
            nLevel = 3;
        else
            nLevel = (nLow & 4) ? 2 : 1;
    }
    else
    {
        nLevel = 0x22;
    }

    unsigned char nNeeded;
    switch (nType)
    {
    case 2:
        nNeeded = 2;
        break;
    case 3:
        nNeeded = 3;
        break;
    case 4:
        nNeeded = 4;
        break;
    case 5:
    case 6:
        nNeeded = 5;
        break;
    case 7:
        nNeeded = 7;
        break;
    default:
        nNeeded = 1;
        break;
    }

    if (nNeeded > nLevel)
    {
        int nValue;
        switch (nNeeded)
        {
        case 7:
            nValue = 0x23;
            break;
        case 5:
            nValue = 0xB2;
            break;
        case 4:
            nValue = 0x2A;
            break;
        case 3:
            nValue = 0x62;
            break;
        case 2:
            nValue = 0x26;
            break;
        default:
            nValue = 0x22;
            break;
        }
        d = nValue;
        sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, d);
        SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    }
}

// 0x00483300
extern "C" void __cdecl sub_00483300_SetByteFlag7BC9D4()
{
    gbFlag_007BC9D4 = 1;
}

// 0x00483340
extern "C" void __cdecl sub_00483340_SetByteFlag7BC9D8()
{
    gbFlag_007BC9D8 = 1;
}

// 0x00484A70
static const Unicode* sub_00484A70_GetClassNameText(unsigned int nClass)
{
    if (nClass < 7)
    {
        switch (nClass)
        {
        case 0:
            return D2LANG_GetStringFromTblIndex(0xFAB);
        case 1:
            return D2LANG_GetStringFromTblIndex(0xFAA);
        case 2:
            return D2LANG_GetStringFromTblIndex(0xFA9);
        case 3:
            return D2LANG_GetStringFromTblIndex(0xFA8);
        case 4:
            return D2LANG_GetStringFromTblIndex(0xFA7);
        case 5:
            return D2LANG_GetStringFromTblIndex(0x2771);
        case 6:
            return D2LANG_GetStringFromTblIndex(0x2772);
        }

        return 0;
    }

    sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x69C);
    exit(-1);
}

const Unicode* __fastcall sub_A15_Emit_00484A70(const unsigned char* pClass)
{
    return sub_00484A70_GetClassNameText(*pClass);
}

// 0x00485240
static void __stdcall sub_00485240_GetItemDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit, int nStatMin, int nStatMax, int* pnMin, int* pnMax, int* pbModified)
{
    *pnMin = 1;
    *pnMax = 2;
    if (!pUnit || !pItem)
        return;
    int nStatNotDynamic = 0;
    D2UnitStrc* pOwner = STATLIST_GetOwner(gpOwnerSource_007BCBF4, &nStatNotDynamic);
    const int bOwner = pOwner != 0;
    if (pOwner && pOwner != pUnit)
        pUnit = pOwner;
    STATLIST_MergeStatLists(pUnit, pItem, 1);
    const int nMin = STATLIST_UnitGetStatValue(pItem, nStatMin, 0);
    int nMax = STATLIST_UnitGetStatValue(pItem, nStatMax, 0);
    if (!bOwner)
        STATLIST_ExpireUnitStatlist(pUnit, pItem);
    else
        STATLIST_MergeStatLists(pUnit, pItem, nStatNotDynamic);
    const int nBaseMin = STATLIST_GetUnitBaseStat(pItem, nStatMin, 0);
    const int nBaseMax = STATLIST_GetUnitBaseStat(pItem, nStatMax, 0);
    if (nBaseMin < nMin || nBaseMax < nMax)
        *pbModified = 1;
    if (nMax <= nMin)
        nMax = nMin;
    const int nByTimeMax = STATLIST_UnitGetStatValue(pItem, STAT_ITEM_MAXDAMAGE_BYTIME, 0);
    if (nByTimeMax && sgptDataTables->nItemStatCostTxtRecordCount > 0x110 && &sgptDataTables->pItemStatCostTxt[0x110] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nAdd = ITEMMODS_GetByTimeAdjustment(nByTimeMax, nPeriod, nBaseTime, 0, 0, 0);
        nMax += nAdd;
        if (nAdd)
            *pbModified = 1;
    }
    const int nByTimePct = STATLIST_UnitGetStatValue(pItem, STAT_ITEM_MAXDAMAGE_PERCENT_BYTIME, 0);
    if (nByTimePct && sgptDataTables->nItemStatCostTxtRecordCount > 0x111 && &sgptDataTables->pItemStatCostTxt[0x111] && pUnit->pDrlgAct)
    {
        int nBaseTime = 0;
        const int nPeriod = ENVIRONMENT_GetPeriodOfDayFromAct(pUnit->pDrlgAct, &nBaseTime);
        const int nPct = ITEMMODS_GetByTimeAdjustment(nByTimePct, nPeriod, nBaseTime, 0, 0, 0);
        nMax += DATATBLS_ApplyRatio(nMax, nPct, 100);
        if (nPct)
            *pbModified = 1;
    }
    *pnMin = nMin;
    *pnMax = nMax;
}

// 0x00485410
void __stdcall sub_00485410_BuildItemDamageText(D2UnitStrc* pItem, Unicode* pBuffer)
{
    Unicode wszValue[256];
    char szValue[256];
    int bModified;
    int nMax;
    int nMin;

    for (int i = 0; i < sizeof(wszValue) / sizeof(wszValue[0]); ++i)
        wszValue[i].wChar = 0;
    const Unicode* wszSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* wszNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
    D2UnitStrc* pPlayer = sub_00463DD0();

    if (ITEMSIsA(pItem, 0x26))
    {
        int nElemMin;
        nMin = ITEMS_GetMissileType(pItem);
        Unicode wszText[256];
        for (int i = 0; i < sizeof(wszText) / sizeof(wszText[0]); ++i)
            wszText[i].wChar = 0;
        int nColor = 0;
        nElemMin = MISSILE_GetMinElemDamage(0, pPlayer, nMin, 1);
        nMax = MISSILE_GetMaxElemDamage(0, pPlayer, nMin, 1);
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xD8B));
        sub_004521C0_SetTextColor(wszText, 0);

        switch (MISSILE_GetElemTypeFromMissileId(nMin))
        {
        case 5:
        {
            nColor = 2;
            int nLength = sub_0064B2A0(0, pPlayer, nMin, 1) / 25;
            if (nLength <= 0)
                nLength = 1;
            nElemMin /= nLength;
            nMax /= nLength;
            break;
        }
        case 4:
            nColor = 3;
            break;
        case 1:
            nColor = 1;
            break;
        case 2:
            nColor = 4;
            break;
        }

        nElemMin += MISSILE_GetMinDamage(0, pPlayer, nMin, 1);
        int nElemMax = nMax + MISSILE_GetMaxDamage(0, pPlayer, nMin, 1);
        nElemMin >>= 8;
        nElemMax >>= 8;
        if (nElemMax <= nElemMin)
            nElemMax = nElemMin;

        SStrPrintf(szValue, sizeof(szValue), "%i", nElemMin);
        sub_00526F20(wszValue, szValue, 9);
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        if (nElemMin != nElemMax)
        {
            sub_00526700(wszText, wszSpace);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xD88));
            SStrPrintf(szValue, sizeof(szValue), "%i", nElemMax);
            sub_00526F20(wszValue, szValue, 9);
            sub_004521C0_SetTextColor(wszValue, nColor);
            sub_00526700(wszText, wszSpace);
            sub_00526700(wszText, wszValue);
        }
        sub_00526700(wszText, wszNewLine);
        sub_005267E0(pBuffer, wszText);
        return;
    }

    bModified = 0;
    if (ITEMS_Is1Or2Handed(pPlayer, pItem))
    {
        Unicode wszTwoHand[128];
        Unicode wszOneHand[128];

        sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x17, 0x18, &nMin, &nMax, &bModified);
        for (int i = 0; i < sizeof(wszTwoHand) / sizeof(wszTwoHand[0]); ++i)
            wszTwoHand[i].wChar = 0;
        sub_005267E0(wszTwoHand, D2LANG_GetStringFromTblIndex(0xD8A));
        sub_00526700(wszTwoHand, wszSpace);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 5);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(wszTwoHand, wszValue);
        sub_00526700(wszTwoHand, wszSpace);
        sub_00526700(wszTwoHand, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 5);
        sub_00526700(wszTwoHand, wszSpace);
        sub_00526700(wszTwoHand, wszValue);
        sub_00526700(wszTwoHand, wszNewLine);

        sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x15, 0x16, &nMin, &nMax, &bModified);
        for (int i = 0; i < sizeof(wszOneHand) / sizeof(wszOneHand[0]); ++i)
            wszOneHand[i].wChar = 0;
        sub_005267E0(wszOneHand, D2LANG_GetStringFromTblIndex(0xD89));
        sub_00526700(wszOneHand, wszSpace);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 5);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(wszOneHand, wszValue);
        sub_00526700(wszOneHand, wszSpace);
        sub_00526700(wszOneHand, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 5);
        sub_00526700(wszOneHand, wszSpace);
        sub_00526700(wszOneHand, wszValue);
        sub_00526700(wszOneHand, wszNewLine);

        sub_004521C0_SetTextColor(wszTwoHand, 0);
        sub_004521C0_SetTextColor(wszOneHand, 0);
        sub_005267E0(pBuffer, wszTwoHand);
        sub_00526700(pBuffer, wszOneHand);
    }
    else
    {
        unsigned short nString;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x17, 0x18, &nMin, &nMax, &bModified);
            nString = 0xD8A;
        }
        else
        {
            sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x15, 0x16, &nMin, &nMax, &bModified);
            nString = 0xD89;
        }
        if (nMax <= nMin + 1)
            nMax = nMin + 1;

        sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(nString));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 9);
        sub_00526700(pBuffer, wszSpace);
        if (bModified)
            sub_004521C0_SetTextColor(wszValue, 3);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, wszSpace);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 9);
        sub_00526700(pBuffer, wszSpace);
        sub_00526700(pBuffer, wszValue);
        sub_00526700(pBuffer, wszNewLine);
    }

    bModified = 0;
    if (STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MINDAMAGE_PERCENT, 0) || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_MAXDAMAGE_PERCENT, 0)
        || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_THROW_MINDAMAGE, 0) || STATLIST_GetUnitStatBonus(pItem, STAT_ITEM_THROW_MAXDAMAGE, 0))
        bModified = 1;

    if (ITEMS_CheckIfThrowable(pItem))
    {
        Unicode wszText[256];
        for (int i = 0; i < sizeof(wszText) / sizeof(wszText[0]); ++i)
            wszText[i].wChar = 0;
        sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0xD8B));
        sub_004521C0_SetTextColor(wszText, 0);
        sub_00485240_GetItemDamageRange(pItem, pPlayer, 0x9F, 0xA0, &nMin, &nMax, &bModified);
        SStrPrintf(szValue, sizeof(szValue), "%i", nMin);
        sub_00526F20(wszValue, szValue, 9);
        const int nColor = bModified ? 3 : 0;
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xD88));
        SStrPrintf(szValue, sizeof(szValue), "%i", nMax);
        sub_00526F20(wszValue, szValue, 9);
        sub_004521C0_SetTextColor(wszValue, nColor);
        sub_00526700(wszText, wszSpace);
        sub_00526700(wszText, wszValue);
        sub_00526700(wszText, wszNewLine);
        sub_00526700(pBuffer, wszText);
    }
}

void __stdcall sub_Z12_EmitDamageRange(D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    int nMin, nMax, bModified;
    sub_00485240_GetItemDamageRange(pItem, pUnit, 0x1F, 0x20, &nMin, &nMax, &bModified);
    sub_Z12_EmitUse(nMin, nMax, bModified);
}

unsigned char gbFlag_007BCC06; // 0x007BCC06

// 0x00486640
static __forceinline void sub_00486640_AppendStrings(Unicode* pText)
{
    const Unicode* pFirst = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pSecond = D2LANG_GetStringFromTblIndex(0x4FD6);
    sub_00526700(pText, pSecond);
    sub_00526700(pText, pFirst);
}

// 0x00486820
static int __stdcall sub_00486820_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

D2NpcButtonStrc gaNpcButtons_007BC9E0[4]; // 0x007BC9E0

int gnGlobal_007BCA48; // 0x007BCA48

D2CelFileStrc* gpCellFile_007BCB04; // 0x007BCB04

int gdwGlobal_007BCBF0; // 0x007BCBF0

int gbQuestTimerActive_007BCC10; // 0x007BCC10

D2CelFileStrc* gpHoradricCel_007BCC1C; // 0x007BCC1C

void* gpCelGoldCoinBtn_007BCC34; // 0x007BCC34

int gnGlobal_007BCC40; // 0x007BCC40

int gnGlobal_007BCC50; // 0x007BCC50

int gnGlobal_007BCC54; // 0x007BCC54

void* gpCelInvArmor_007BCE68; // 0x007BCE68

void* gpCelInvBelt_007BCE6C; // 0x007BCE6C

void* gpCelInvBoots_007BCE70; // 0x007BCE70

void* gpCelInvHelmGlove_007BCE74; // 0x007BCE74

void* gpCelInvRingAmulet_007BCE78; // 0x007BCE78

void* gpCelInvWeapons_007BCE7C; // 0x007BCE7C

void* gpCelTradeBtn_007BCE80; // 0x007BCE80

void* gpCelInvChar6Tab_007BCE84; // 0x007BCE84

void* gpCelNpcInv_007BCE88; // 0x007BCE88

static int gbGlobal_007BCE90; // 0x007BCE90

// 0x004868B0
void __cdecl sub_004868B0_LoadNpcPanelCels()
{
    gpCelInvArmor_007BCE68 = sub_004520C0_LoadUiCelFile("Panel\\inv_armor");
    gpCelInvBelt_007BCE6C = sub_004520C0_LoadUiCelFile("Panel\\inv_belt");
    gpCelInvBoots_007BCE70 = sub_004520C0_LoadUiCelFile("Panel\\inv_boots");
    gpCelInvHelmGlove_007BCE74 = sub_004520C0_LoadUiCelFile("Panel\\inv_helm_glove");
    gpCelInvRingAmulet_007BCE78 = sub_004520C0_LoadUiCelFile("Panel\\inv_ring_amulet");
    gpCelInvWeapons_007BCE7C = sub_004520C0_LoadUiCelFile("Panel\\inv_weapons");
    gpCelTradeBtn_007BCE80 = sub_004520C0_LoadUiCelFile("Panel\\tradebtn");
    gpCelGoldCoinBtn_007BCC34 = sub_004520C0_LoadUiCelFile("Panel\\goldcoinbtn");
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        gpCelInvChar6Tab_007BCE84 = sub_004520C0_LoadUiCelFile("Panel\\invchar6Tab");
        gbWeaponSwitch_007BCC4C = 0;
        gpCelNpcInv_007BCE88 = sub_004520C0_LoadUiCelFile("Panel\\NPCInv");
    }
    else
    {
        gpCelInvChar6Tab_007BCE84 = 0;
        gbWeaponSwitch_007BCC4C = 0;
        gpCelNpcInv_007BCE88 = 0;
    }
}

// 0x00486980
void __cdecl sub_00486980_FreeNpcPanelCels()
{
    if (gpHoradricCel_007BCC1C)
    {
        sub_00478A00(gpHoradricCel_007BCC1C);
        gpHoradricCel_007BCC1C = 0;
    }
    if (gpCelInvArmor_007BCE68)
    {
        sub_00478A00(gpCelInvArmor_007BCE68);
        gpCelInvArmor_007BCE68 = 0;
    }
    if (gpCelInvBelt_007BCE6C)
    {
        sub_00478A00(gpCelInvBelt_007BCE6C);
        gpCelInvBelt_007BCE6C = 0;
    }
    if (gpCelInvBoots_007BCE70)
    {
        sub_00478A00(gpCelInvBoots_007BCE70);
        gpCelInvBoots_007BCE70 = 0;
    }
    if (gpCelInvHelmGlove_007BCE74)
    {
        sub_00478A00(gpCelInvHelmGlove_007BCE74);
        gpCelInvHelmGlove_007BCE74 = 0;
    }
    if (gpCelInvRingAmulet_007BCE78)
    {
        sub_00478A00(gpCelInvRingAmulet_007BCE78);
        gpCelInvRingAmulet_007BCE78 = 0;
    }
    if (gpCelInvWeapons_007BCE7C)
    {
        sub_00478A00(gpCelInvWeapons_007BCE7C);
        gpCelInvWeapons_007BCE7C = 0;
    }
    if (gpCelTradeBtn_007BCE80)
    {
        sub_00478A00(gpCelTradeBtn_007BCE80);
        gpCelTradeBtn_007BCE80 = 0;
    }
    if (gpCelGoldCoinBtn_007BCC34)
    {
        sub_00478A00(gpCelGoldCoinBtn_007BCC34);
        gpCelGoldCoinBtn_007BCC34 = 0;
    }
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0() && gpCelInvChar6Tab_007BCE84)
    {
        sub_00478A00(gpCelInvChar6Tab_007BCE84);
        gpCelInvChar6Tab_007BCE84 = 0;
    }
    if (gpCelNpcInv_007BCE88)
    {
        sub_00478A00(gpCelNpcInv_007BCE88);
        gpCelNpcInv_007BCE88 = 0;
    }
    if (gpCel_007BCE8C)
    {
        sub_00478A00(gpCel_007BCE8C);
        gpCel_007BCE8C = 0;
    }
    gpCelInvArmor_007BCE68 = 0;
    gpCelInvBelt_007BCE6C = 0;
    gpCelInvBoots_007BCE70 = 0;
    gpCelInvHelmGlove_007BCE74 = 0;
    gpCelInvRingAmulet_007BCE78 = 0;
    gpCelInvWeapons_007BCE7C = 0;
    gpCelTradeBtn_007BCE80 = 0;
    gpCelGoldCoinBtn_007BCC34 = 0;
}

void __fastcall sub_M112_Emit_00486640(Unicode* pText)
{
    sub_00486640_AppendStrings(pText);
}

// 0x00486AD0
void __cdecl sub_00486AD0_ToggleFlag()
{
    gbFlag_007BCC06 = gbFlag_007BCC06 == 0;
}

// 0x00486AE0
int __cdecl sub_00486AE0_GetPanelX()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_007A2858 + 0x113;
    }
    return gnGlobal_007A2858 + 0x110;
}

// 0x00486B00
int __cdecl sub_00486B00_GetPanelY()
{
    if (!sub_0044DCC0())
    {
        return gnGlobal_00711470 + gnGlobal_007A285C - 0x41;
    }
    return gnGlobal_00711470 + gnGlobal_007A285C - 0x40;
}

// 0x00486B30
int __cdecl sub_00486B30_IsNpcStateA()
{
    switch (gdwGlobal_007BCBF0)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
        return 0;
    }
    return 0;
}

// 0x00486B80
int __cdecl sub_00486B80_IsNpcStateB()
{
    switch (gdwGlobal_007BCBF0)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0xF:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
    case 0x11:
        return 0;
    }
    return 0;
}

// 0x00486D10
int __cdecl sub_00486D10_CheckTick()
{
    if (!sub_0044DB30() || sub_0044DB30() == 1)
    {
        return 1;
    }
    if (sub_004B9180())
    {
        sub_004B90B0();
        return 0;
    }
    if (GetTickCount() - gnGlobal_007BCA48 > 0xFA)
    {
        gnGlobal_007BCA48 = GetTickCount();
        return 1;
    }
    return 0;
}

// 0x00486D70
int __cdecl sub_00486D70_IsNotState11()
{
    return gdwGlobal_007BCBF0 != 0xB;
}

// 0x00486D80
int __cdecl sub_00486D80_IsState1Or2()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2)
    {
        return 1;
    }
    return 0;
}

// 0x00486E10
int __fastcall sub_00486E10_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnGlobal_0071146C - gnGlobal_007A2858 - 0x12E || nX > gnGlobal_0071146C - gnGlobal_007A2858 - 0x10E)
    {
        return 0;
    }
    if (nY < gnGlobal_00711470 + gnGlobal_007A285C - 0x60 || nY > gnGlobal_00711470 + gnGlobal_007A285C - 0x40)
    {
        return 0;
    }
    return 1;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00487740
static int __stdcall sub_00487740_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
{
    int nOutX;
    int nOutY;
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, sub_0044DCC0());
    unsigned int nGridX;
    unsigned int nGridY;
    if (!nPage)
    {
        nGridX = (nX - gGrid_007BCB88.nGridLeft) / gGrid_007BCB88.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCB88.nGridTop) / gGrid_007BCB88.nGridBoxHeight;
    }
    else if (sub_0044DCC0())
    {
        nGridX = (nX - gGrid_007BCA78.nGridLeft) / gGrid_007BCA78.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCA78.nGridTop) / gGrid_007BCA78.nGridBoxHeight;
    }
    else
    {
        nGridX = (nX - gGrid_007BCB40.nGridLeft) / gGrid_007BCB40.nGridBoxWidth;
        nGridY = (nY - gGrid_007BCB40.nGridTop) / gGrid_007BCB40.nGridBoxHeight;
    }

    D2UnitStrc* pItem = sub_0063BD10(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        if (!INVENTORY_GetCursorItem(pInventory) && sub_0062A0A0(pItem))
        {
            if (!sub_004C2240(pItem))
            {
                sub_00478680_SendPacket5(0x4C, pItem->dwUnitId);
                sub_004C21F0(pItem);
                return 1;
            }
        }
        else if (sub_00628C20(pItem))
        {
            const int nUnitX = UNITS_GetXPositionInline(pPlayer);
            const int nUnitY = UNITS_GetYPositionInline(pPlayer);
            if (!sub_004C2240(pItem) && sub_00486D10_CheckTick())
            {
                if (sub_004538D0(0x19) && ITEMS_GetBaseCode(pItem) == 0x20786F62)
                {
                    gnGlobal_007BCC50 = 1;
                }

                sub_004786D0_SendPacket(0x20, pItem->dwUnitId, nUnitX, nUnitY);
                sub_004C21F0(pItem);
                sub_004B9A00(sub_004C1E20(pItem), 0, 0, 0, 0);
                gdwGlobal_007BCBE4 = 0;
                return 1;
            }
        }
        else if (sub_00628C70(pItem))
        {
            D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            const int nCode = pTxt->dwCode;
            if (nCode == 0x20737274 || nCode == 0x20736B62 || nCode == 0x20646B62)
            {
                sub_0049FF90_OpenTextData(pItem, pTxt);
            }
            return 1;
        }
    }

    return 0;
}

// 0x00487990
void __cdecl sub_00487990_ResetHover()
{
    gnGlobal_00721E3C = -1;
    gnGlobal_00721E40 = -1;
    gnGlobal_00721E44 = -1;
    gnGlobal_00721E48 = -1;
    gnGlobal_00721E4C = -1;
    gnGlobal_00721E50 = -1;
    gdwGlobal_007BCBE4 = 0;
    gdwGlobal_007BCBE8 = 0;
    gdwGlobal_007BCBF4 = 0;
    gdwGlobal_007BCBF8 = 0;
}

// 0x00487B30
void __cdecl sub_00487B30_ResetNpcState()
{
    gdwGlobal_007BCBF0 = 0;
    gnSelectedTab_007BCC04 = 0;
    gnGlobal_007BCE30 = 0;
    gnGlobal_007BCA4C = 0;
    gnGlobal_007BCBD8 = 0;
    if (gpCellFile_007BCB04)
    {
        sub_00478A00(gpCellFile_007BCB04);
        gpCellFile_007BCB04 = 0;
    }
    gnGlobal_007BCA48 = 0;
}

extern "C" { int gRequest; } // 0x007BCC0C

// 0x00487B70
void __cdecl sub_00487B70()
{
    gRequest = 1;
}

// 0x00487B80
void __cdecl sub_00487B80_SetNpcStateTrade()
{
    gnSelectedTab_007BCC04 = 0;
    gdwGlobal_007BCBF0 = 0x13;
}

int __stdcall sub_H19_Emit_00487740(D2UnitStrc* pPlayer, int nX, int nY)
{
    return sub_00487740_ClickGridItem(pPlayer, pPlayer->pInventory, nX, nY, 4);
}

// 0x00487BA0
static void __stdcall sub_00487BA0_Forward(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!sub_004B3870(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gdwGlobal_007BCBF0 = 5;
    sub_00468070_SetCursorItemState(0);
}

// 0x00487BE0
int __cdecl sub_00487BE0_ResetButtons()
{
    gaNpcButtons_007BC9E0[0].bActive = 0;
    gaNpcButtons_007BC9E0[1].bActive = 0;
    gaNpcButtons_007BC9E0[2].bActive = 0;
    gaNpcButtons_007BC9E0[3].bActive = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    return 1;
}

// 0x00487C20
void __cdecl sub_00487C20_ResetButtonsFromState5()
{
    if (gdwGlobal_007BCBF0 == 5)
    {
        gaNpcButtons_007BC9E0[0].bActive = 0;
        gaNpcButtons_007BC9E0[1].bActive = 0;
        gaNpcButtons_007BC9E0[2].bActive = 0;
        gaNpcButtons_007BC9E0[3].bActive = 0;
        gdwGlobal_007BCBF0 = 1;
        sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    }
}

// 0x00487C60
void __cdecl sub_00487C60_SetNpcState6()
{
    D2_ASSERT(gdwGlobal_007BCBF0 == 5, 0x1EA1);
    gdwGlobal_007BCBF0 = 6;
}

// 0x00487CC0
void __cdecl sub_00487CC0_SelectFirstButton()
{
    gnGlobal_007BCC40 = -1;
    for (int i = 0; i < gnButtonCount_00722160; ++i)
    {
        if (gaNpcButtons_007BC9E0[i].bActive)
        {
            gnGlobal_007BCC40 = i;
            break;
        }
    }
    gaNpcButtons_007BC9E0[0].bActive = 0;
    gaNpcButtons_007BC9E0[1].bActive = 0;
    gaNpcButtons_007BC9E0[2].bActive = 0;
    gaNpcButtons_007BC9E0[3].bActive = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
}

// 0x00487D30
void __cdecl sub_00487D30_SetNpcState7()
{
    gdwGlobal_007BCBF0 = 7;
}

// 0x00487D40
void __cdecl sub_00487D40_ResetButtonsFromState7()
{
    D2_ASSERT(gdwGlobal_007BCBF0 == 7, 0x1ED3);
    gaNpcButtons_007BC9E0[0].bActive = 0;
    gaNpcButtons_007BC9E0[1].bActive = 0;
    gaNpcButtons_007BC9E0[2].bActive = 0;
    gaNpcButtons_007BC9E0[3].bActive = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
}

void __cdecl sub_K04_EmitForward(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    sub_00487BA0_Forward(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7);
    sub_K04_EmitUse(nArg7);
}

// 0x00487DA0
static void sub_00487DA0_SetButtonD(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0x276F;
    gaPanelButtons_007BC9E0[nButton].nCel = 1;
    gaPanelButtons_007BC9E0[nButton].nType = 8;
    gaPanelButtons_007BC9E0[nButton].nFrame = 0x12;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

// 0x00487DE0
static void sub_00487DE0_SetButtonC(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD0A;
    gaPanelButtons_007BC9E0[nButton].nCel = 4;
    gaPanelButtons_007BC9E0[nButton].nType = 1;
    gaPanelButtons_007BC9E0[nButton].nFrame = 6;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

void __cdecl sub_M214_Emit_00487ED0()
{
    sub_00487DE0_SetButtonC(2);
    sub_00487DA0_SetButtonD(3);
}

// 0x00487E20
static void sub_00487E20_SetButtonA(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD07;
    gaPanelButtons_007BC9E0[nButton].nCel = 2;
    gaPanelButtons_007BC9E0[nButton].nType = 3;
    gaPanelButtons_007BC9E0[nButton].nFrame = 2;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

// 0x00487E60
static void sub_00487E60_SetButtonB(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0xD08;
    gaPanelButtons_007BC9E0[nButton].nCel = 3;
    gaPanelButtons_007BC9E0[nButton].nType = 4;
    gaPanelButtons_007BC9E0[nButton].nFrame = 4;
    gaPanelButtons_007BC9E0[nButton].bActive = 1;
}

// 0x00487EA0
static void sub_00487EA0_ClearButton(int nButton)
{
    gaPanelButtons_007BC9E0[nButton].nString = 0;
    gaPanelButtons_007BC9E0[nButton].nCel = 1;
    gaPanelButtons_007BC9E0[nButton].nType = 1;
    gaPanelButtons_007BC9E0[nButton].nFrame = 0;
    gaPanelButtons_007BC9E0[nButton].bActive = 0;
}

void __cdecl sub_00487ED0_SetupPanelButtons()
{
    const int bValue = sub_004B3500();
    int nUnitId;
    if (!sub_004B3230_GetSelectedUnitId(&nUnitId))
        return;

    D2UnitStrc* pUnit = sub_00463990(nUnitId, 1);
    if (!pUnit)
        return;

    if (!bValue)
    {
        gnMaxTab_007BCC05 = 1;
        sub_00487E20_SetButtonA(0);
        sub_00487E60_SetButtonB(1);
        gaPanelButtons_007BC9E0[2].nString = 0;
        gaPanelButtons_007BC9E0[2].nCel = 1;
        gaPanelButtons_007BC9E0[2].nType = 1;
        gaPanelButtons_007BC9E0[2].nFrame = 0;
        gaPanelButtons_007BC9E0[2].bActive = 0;
    }
    else
    {
        switch (pUnit->dwClassId)
        {
        case 0x93:
        case 0x94:
        case 0xB1:
        case 0xC7:
        case 0xCA:
        case 0xFC:
        case 0xFE:
        case 0xFF:
        case 0x195:
        case 0x200:
        case 0x201:
            gnMaxTab_007BCC05 = 3;
            sub_00487E20_SetButtonA(0);
            sub_00487E60_SetButtonB(1);
            sub_00487EA0_ClearButton(2);
            break;

        case 0x9A:
        case 0xB2:
        case 0xFD:
        case 0x101:
        case 0x1FF:
            gnMaxTab_007BCC05 = 3;
            sub_00487E20_SetButtonA(0);
            sub_00487E60_SetButtonB(1);
            gaPanelButtons_007BC9E0[2].nString = 0xD0A;
            gaPanelButtons_007BC9E0[2].nCel = 4;
            gaPanelButtons_007BC9E0[2].nType = 1;
            gaPanelButtons_007BC9E0[2].nFrame = 6;
            gaPanelButtons_007BC9E0[2].bActive = 1;
            gaPanelButtons_007BC9E0[3].nString = 0x276F;
            gaPanelButtons_007BC9E0[3].nCel = 1;
            gaPanelButtons_007BC9E0[3].nType = 8;
            gaPanelButtons_007BC9E0[3].nFrame = 0x12;
            gnButtonCount_00722160 = 4;
            gaPanelButtons_007BC9E0[3].bActive = 1;
            gnButtonRow_0072215C = 3;
            gaPanelButtons_007BC9E0[0].nValue = 0;
            gaPanelButtons_007BC9E0[1].nValue = 0;
            gaPanelButtons_007BC9E0[2].nValue = 0;
            gaPanelButtons_007BC9E0[3].nValue = 0;
            return;

        default:
            gnButtonCount_00722160 = 0;
            return;
        }
    }

    gaPanelButtons_007BC9E0[3].nString = 0x1030;
    gaPanelButtons_007BC9E0[3].nCel = 9;
    gaPanelButtons_007BC9E0[3].nFrame = 0xA;
    gnButtonCount_00722160 = 4;
    gaPanelButtons_007BC9E0[3].bActive = 1;
    gnButtonRow_0072215C = 3;
    gaPanelButtons_007BC9E0[0].nValue = 0;
    gaPanelButtons_007BC9E0[1].nValue = 0;
    gaPanelButtons_007BC9E0[2].nValue = 0;
    gaPanelButtons_007BC9E0[3].nValue = 0;
}

// 0x004880F0
void __cdecl sub_004880F0_ClearClickPos()
{
    gnGlobal_007BCA4C = 0;
    gnGlobal_007BCBD8 = 0;
}

// 0x00488100
void __fastcall sub_00488100_DrawGold(int nType)
{
    int nOldFont = sub_00502EF0(1);
    D2GfxDataStrc tData = {};
    tData.nDirection = 0;

    int nGold;
    int nTextX;
    int nTextY;
    int nIconX;
    int nIconY;
    int nFrame;
    switch (nType)
    {
    case 0:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLDBANK, 0);
        nTextX = gnGlobal_007A2858 + 0xA5;
        if (sub_0044DCC0())
        {
            nTextY = gnGlobal_00711470 + gnGlobal_007A285C - 0x1B8;
            nIconY = gnGlobal_00711470 + gnGlobal_007A285C - 0x1B6;
        }
        else
        {
            nTextY = gnGlobal_00711470 + gnGlobal_007A285C - 0xF4;
            nIconY = gnGlobal_00711470 + gnGlobal_007A285C - 0xF2;
        }
        nIconX = gnGlobal_007A2858 + 0x49;
        nFrame = gbGoldButtonDown_007BCE34 != 0;
        if (sub_0044DCC0())
        {
            if (sub_00486820_IsMouseInBox(gnGlobal_007A2858 + 0x49, gnGlobal_00711470 + gnGlobal_007A285C - 0x1B6, 0x14, 0x12))
            {
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x101C), gnGlobal_007A2858 + 0x35, gnGlobal_00711470 + gnGlobal_007A285C - 0x1CA, 0, 0);
            }
        }
        else
        {
            if (sub_00486820_IsMouseInBox(gnGlobal_007A2858 + 0x49, gnGlobal_00711470 + gnGlobal_007A285C - 0xF2, 0x14, 0x12))
            {
                sub_00502280_SetPopUpText(D2LANG_GetStringFromTblIndex(0x101C), gnGlobal_007A2858 + 0x35, gnGlobal_00711470 + gnGlobal_007A285C - 0x106, 0, 0);
            }
        }
        break;

    case 1:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLD, 0);
        nTextX = gnGlobal_0071146C - gnGlobal_007A2858 - 0xD4;
        nTextY = gnGlobal_00711470 + gnGlobal_007A285C - 0x48;
        nIconY = gnGlobal_00711470 + gnGlobal_007A285C - 0x45;
        nIconX = gnGlobal_0071146C - gnGlobal_007A2858 - 0xED;
        nFrame = gbGoldButtonDown_007BCE30 != 0;
        break;

    default:
        nGold = STATLIST_UnitGetStatValue(sub_00463DD0(), STAT_GOLDBANK, 0);
        nTextX = sub_00501820(D2LANG_GetStringFromTblIndex(0xCF3)) + gnGlobal_007A2858 + 0x15;
        nTextY = gnGlobal_00711470 + gnGlobal_007A285C - 0x6A;
        nIconX = 0;
        nIconY = 0;
        nFrame = 0;
        break;
    }

    if (nType != 3)
    {
        Unicode wszGold[20] = {};
        char szGold[20];
        SStrPrintf(szGold, 20, szFmtD_006D57BC, nGold);
        sub_00526F20(wszGold, szGold, 19);
        if (nType == 2)
        {
            nTextX = gnGlobal_007A2858 - sub_00501820(wszGold) + 0xC6;
        }
        sub_00502320(wszGold, nTextX, nTextY, 0, 0);
    }

    switch (nType)
    {
    case 0:
        if (gbGoldButtonDown_007BCE34)
        {
            ++nIconY;
        }
        nIconX += 2;
        nIconY -= 2;
        tData.pCellFile = gpGoldButtonCel_007BCC34;
        tData.nFrame = nFrame;
        TEXTURE_CelDraw(&tData, nIconX, nIconY, -1, 5, 0);
        break;

    case 1:
        if (gbGoldButtonDown_007BCE30)
        {
            ++nIconY;
        }
        nIconX += 1;
        nIconY -= 2;
        tData.pCellFile = gpGoldButtonCel_007BCC34;
        tData.nFrame = nFrame;
        TEXTURE_CelDraw(&tData, nIconX, nIconY, -1, 5, 0);
        break;

    default:
        sub_00502320(D2LANG_GetStringFromTblIndex(0xCF3), gnGlobal_007A2858 + 0x15, nTextY, 0, 0);
        break;
    }

    sub_00502EF0(nOldFont);
}

// 0x00488890
int __cdecl sub_00488890_IsNpcStateMenu()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 4
        || gdwGlobal_007BCBF0 == 9)
    {
        return 1;
    }

    return 0;
}

// 0x004888C0
int __cdecl sub_004888C0_CanUseCursor()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 4 || gdwGlobal_007BCBF0 == 3)
    {
        if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
        {
            return 0;
        }
        const int nMode = sub_00468830();
        if (nMode == 7 || nMode == 1 || nMode == 4)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00488DF0
void __stdcall sub_00488DF0_HandledMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00488EC0
void __stdcall sub_00488EC0_KeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if ((gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2 || gdwGlobal_007BCBF0 == 3 || gdwGlobal_007BCBF0 == 4
        || gdwGlobal_007BCBF0 == 9) && !(pMsg->lParam & 0x40000000))
        sub_00468F00();
    pMsg->bReturn = 1;
    pMsg->lResult = 1;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00489190
int __fastcall sub_00489190_ClickNpcPanel(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (sub_00486E10_IsInNpcPanelRect(nX, nY))
    {
        gbGlobal_007BCE90 = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

int gnGlobal_007BCAF0; // 0x007BCAF0

int gnGlobal_007BCD34; // 0x007BCD34

int gnGlobal_007BCE14; // 0x007BCE14

int gnGlobal_007BCE18; // 0x007BCE18

int gnGlobal_007BCE1C; // 0x007BCE1C

int gnGlobal_007BCE20; // 0x007BCE20

int gnGlobal_007BCE24; // 0x007BCE24

D2CelFileStrc* gpCellFile_007BCC24; // 0x007BCC24

D2CelFileStrc* gpCellFile_007BCC28; // 0x007BCC28

D2CelFileStrc* gpCellFile_007BCC38; // 0x007BCC38

void* gapHirelingIcons_007BEEB0[7]; // 0x007BEEB0

// 0x00489220
void __cdecl sub_00489220_LoadShopPanelCels()
{
    char szPath[0x104];
    if (!gpCellFile_007BCC24)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\buyselltabs", szDataGlobal_006D4118);
        gpCellFile_007BCC24 = sub_004788B0(szPath, 0);
    }
    if (!gpCellFile_007BCC28)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\miniconvert", szDataGlobal_006D4118);
        gpCellFile_007BCC28 = sub_004788B0(szPath, 0);
    }
    if (!gpCellFile_007BCC38 && sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\invchar6tab", szDataGlobal_006D4118);
        gpCellFile_007BCC38 = sub_004788B0(szPath, 0);
    }
}

// 0x004892F0
void __cdecl sub_004892F0_FreeNpcCels()
{
    if (gpCellFile_007BCB04)
    {
        sub_00478A00(gpCellFile_007BCB04);
        gpCellFile_007BCB04 = 0;
    }
    if (gpCellFile_007BCC24)
    {
        sub_00478A00(gpCellFile_007BCC24);
        gpCellFile_007BCC24 = 0;
    }
    if (gpCellFile_007BCC28)
    {
        sub_00478A00(gpCellFile_007BCC28);
        gpCellFile_007BCC28 = 0;
    }
    if (sub_0044DCC0() && gpCellFile_007BCC38)
    {
        sub_00478A00(gpCellFile_007BCC38);
        gpCellFile_007BCC38 = 0;
    }
}

// 0x00489360
void __fastcall sub_00489360_SetTradePanelOpen(int bOpen)
{
    char szPath[0x104];
    if (gnGlobal_007BCD34 || gnGlobal_007BCE14)
    {
        sub_004B9A00(3, 0, 0, 0, 0);
    }
    gnGlobal_007BCD34 = 0;
    gnGlobal_007BCE14 = 0;
    gnGlobal_007BCE30 = 0;
    if (bOpen)
    {
        gnGlobal_007BCA48 = 0;
        gdwGlobal_007BCBF0 = 0xB;
        sub_0045AEA0_SetPanelSlide(3);
        if (!gpCellFile_007BCB04)
        {
            SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\trade", szDataGlobal_006D4118);
            gpCellFile_007BCB04 = sub_004788B0(szPath, 0);
        }
    }
    else
    {
        gdwGlobal_007BCBF0 = 0xA;
        sub_0045AEA0_SetPanelSlide(0);
    }
    gnGlobal_007BCE9C = 0;
    gnGlobal_007BCE18 = 0;
    gnGlobal_007BCE1C = 0;
    gnGlobal_007BCE20 = 0;
    gnGlobal_007BCE24 = 0;
}

// 0x00489770
void __stdcall sub_00489770_HandledIfState11(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xB)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x004897A0
void __stdcall sub_004897A0_HandledIfState11Ex(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xB)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!sub_00453A90_GetUIVarUnchecked(5))
            sub_004B8CB0();
    }
}

// 0x004897E0
void __fastcall sub_004897E0_UpdateSound(int bFirst, int bSecond)
{
    if ((gnGlobal_007BCD34 || gnGlobal_007BCE14) && (!bFirst || !bSecond))
    {
        sub_004B9A00(3, 0, 0, 0, 0);
    }
    else if ((!gnGlobal_007BCD34 && bFirst) || (bSecond && !gnGlobal_007BCE14))
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    gnGlobal_007BCD34 = bFirst;
    gnGlobal_007BCE14 = bSecond;
}

// 0x00489860
int __cdecl sub_00489860_IsNpcState4()
{
    return gdwGlobal_007BCBF0 == 4;
}

extern "C" RangeNode* __fastcall sub_0040BCB0_FindRange(unsigned int address, RangeNode* node)
{
    while (node)
    {
        unsigned int start = node->start;
        if (address >= start && address < start + node->size)
            return node;
        node = node->next;
    }
    return 0;
}

extern "C" void __fastcall sub_00468040_SetMode(unsigned int value, unsigned int alternate)
{
    unsigned int result = alternate != 0;
    gValue_007A6ABC = 0;
    gValue_007A6ADC = 0x6;
    gValue_007A6AE0 = value;
    gValue_007A6AF0 = result + 0x7;
}

extern "C" unsigned int __fastcall sub_00479080_FindListValue(unsigned int key)
{
    LookupNode* node = gLookupHead_007BB5BC;
    while (node)
    {
        if (node->key == key)
            return node->value;
        node = node->next;
    }
    return 0;
}

extern "C" void __cdecl sub_0047BD30_ResetGlobals()
{
    gValue_00712F44 = 0x7;
    gValue_00712F48 = 0x7;
    gValue_007BB5D8 = 0;
    gValue_007BB5E4 = 0;
    gValue_007BB5E8 = 0;
}

// 0x00489880
extern "C" void __cdecl sub_00489880_ClearAndTransition()
{
    bool transition = gValue_007BCBF0 == 0xD;
    gValue_007BCE2C = 0;
    if (transition)
        gValue_007BCBF0 = 0xC;
}

// 0x00489A10
void __cdecl sub_00489A10_OpenUIVar25()
{
    sub_00455F20(0x19, 1, 0);
    sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
}

// 0x00489CE0
void __stdcall sub_00489CE0_HandledIfState12(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xC)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!sub_00453A90_GetUIVarUnchecked(5))
        {
            sub_00455F20(0x19, 1, 0);
            sub_00478600_SendShorts(0x4F, 0x12, 0, 0);
            gnGlobal_00721E3C = -1;
            gnGlobal_00721E40 = -1;
            gnGlobal_00721E44 = -1;
            gnGlobal_00721E48 = -1;
            gnGlobal_00721E4C = -1;
            gnGlobal_00721E50 = -1;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
    }
}

// 0x00489D70
void __stdcall sub_00489D70_KeyNoRepeatMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!(pMsg->lParam & 0x40000000))
        sub_00468F00();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x00489DA0
void __fastcall sub_00489DA0_SelectUnit(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwClassId : -1) != 267)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(sub_00463DD0());
    if (!pPlayerRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pPlayerRoom)) == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)))
    {
        gnGlobal_00721E54 = pUnit->dwUnitId;
    }
}

void __cdecl sub_J08_Emit_0048B540(D2UnitStrc* pUnit)
{
    sub_0048B0A0(pUnit);
    sub_0048B540_DrawEquippedItems(pUnit);
    sub_0048B3F0_DrawMercEquipHighlights(pUnit);
}

U32 gButtonA; // 0x007BCE30

U32 gButtonB; // 0x007BCE34

U32 gPressedFrame; // 0x007BCE38

U32 gButtonLatch; // 0x007BCE3C

void* gArchiveA; // 0x007BCC2C

void* gArchiveB; // 0x007BCC3C

// 0x00489E00
void __cdecl sub_00489E00_OpenUi()
{
    if (sub_00455F20(25, 0, 0))
    {
        gSelectionState = 0;
        sub_004649D0(sub_00489DA0);
        gUiState = 12;
        sub_0044DA40();
        gButtonA = 0;
        gButtonB = 0;
        gPressedFrame = 0;
        gButtonLatch = 0;
    }
}

// 0x00489E50
void __cdecl sub_00489E50_LoadStashPanelCels()
{
    char szPath[0x104];
    gnGlobal_007BCAF0 = 0;
    if (!gpCellFile_007BCC2C)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\bank", szDataGlobal_006D4118);
        gpCellFile_007BCC2C = sub_004788B0(szPath, 0);
        if (sub_00408F20_HasExpansionMpq())
        {
            SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\TradeStash", szDataGlobal_006D4118);
            gpCellFile_007BCC3C = sub_004788B0(szPath, 0);
        }
    }
}

// 0x00489EE0
void __cdecl sub_00489EE0_CloseUiAndSend()
{
    if (gUiState == 12 || gUiState == 13)
    {
        gUiState = 0;
        sub_00455F20(25, 1, 0);
        sub_00478600(79, 18, 0, 0);
    }
    if (gArchiveA)
    {
        sub_00478A00(gArchiveA);
        gArchiveA = 0;
    }
    if (gArchiveB)
    {
        sub_00478A00(gArchiveB);
        gArchiveB = 0;
    }
}

// 0x00489F50
void __cdecl sub_00489F50_CloseUiArchives()
{
    if (gUiState == 12 || gUiState == 13)
    {
        gUiState = 0;
        sub_00455F20(25, 1, 0);
    }
    if (gArchiveA)
    {
        sub_00478A00(gArchiveA);
        gArchiveA = 0;
    }
    if (gArchiveB)
    {
        sub_00478A00(gArchiveB);
        gArchiveB = 0;
    }
}

// 0x0048A050
void __cdecl sub_0048A050_CloseQuestPanel()
{
    gbQuestTimerActive_007BCC10 = 0;
    sub_00455F20(0x1A, 1, 0);
    if (!gnGlobal_007BCC54)
    {
        sub_00478600_SendShorts(0x4F, 0x17, 0, 0);
        gnGlobal_007BCC54 = 1;
    }
    if (gnGlobal_007BCC50)
    {
        if (sub_00463990(gnGlobal_00721E54, 2))
        {
            sub_00480930(2, gnGlobal_00721E54);
        }
        gnGlobal_007BCC50 = 0;
    }
}

int gnGlobal_007BCE40; // 0x007BCE40

int gnGlobal_007BCE44; // 0x007BCE44

int gnGlobal_007BCE48; // 0x007BCE48

int gnGlobal_007BCE4C; // 0x007BCE4C

// 0x0048A0D0
void __cdecl sub_0048A0D0_SendPanelClosed()
{
    sub_00478600_SendShorts(0x4F, 0x18, 0, 0);
}

// 0x0048A3B0
void __stdcall sub_0048A3B0_HandledIfState14(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xE)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x0048A3E0
void __stdcall sub_0048A3E0_HandledIfState14Ex(SMSGHANDLER_PARAMS* pMsg)
{
    if (gdwGlobal_007BCBF0 == 0xE)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
        if (!sub_004538D0(1))
        {
            gnGlobal_00721E3C = -1;
            gnGlobal_00721E40 = -1;
            gnGlobal_00721E44 = -1;
            gnGlobal_00721E48 = -1;
            gnGlobal_00721E4C = -1;
            gnGlobal_00721E50 = -1;
            gdwGlobal_007BCBE4 = 0;
            gdwGlobal_007BCBE8 = 0;
            gdwGlobal_007BCBF4 = 0;
            gdwGlobal_007BCBF8 = 0;
        }
        if (!sub_00453A90_GetUIVarUnchecked(5))
            sub_0048A050();
    }
}

// 0x0048A460
void __cdecl sub_0048A460_CloseCubePanel()
{
    if (sub_00455F20(0x1A, 0, 0))
    {
        gnGlobal_007BCC54 = 0;
        gdwGlobal_007BCBF0 = 0xE;
        sub_0044DA40();
        gnGlobal_007BCE30 = 0;
        gnGlobal_007BCE40 = 0;
        gnGlobal_007BCE44 = 0;
        gnGlobal_007BCE48 = 0;
        gnGlobal_007BCE4C = 0;
    }
}

// 0x0048A4B0
void __cdecl sub_0048A4B0_LoadCubePanelCel()
{
    char szPath[0x104];
    gnGlobal_007BCAF0 = 0;
    if (!gpCellFile_007BCC30)
    {
        SStrPrintf(szPath, sizeof(szPath), "%s\\ui\\panel\\supertransmogrifier", szDataGlobal_006D4118);
        gpCellFile_007BCC30 = sub_004788B0(szPath, 0);
    }
}

void* gUiArchive; // 0x007BCC30

void __cdecl sub_00494EB0_DrawUiRectangle()
{
    InitializePalette();
    sub_004F6300(0, 0, gScreenWidth, gScreenHeight - 49, gColor, 1);
}

// 0x0048A500
void __cdecl sub_0048A500_CloseUiArchive()
{
    if (gUiState == 14)
    {
        gUiState = 0;
        sub_0048A050();
    }
    if (gUiArchive)
    {
        sub_00478A00(gUiArchive);
        gUiArchive = 0;
    }
}

// 0x0048A540
void __fastcall sub_0048A540_QuestCodeUpdate(int nCode)
{
    char szPath[0x104];
    D2BitBufferStrc* pQuestInfo = sub_004B32D0();
    if (nCode == 0x20747368)
    {
        if (!pQuestInfo)
        {
            return;
        }
        if (QUESTRECORD_GetQuestState(pQuestInfo, 10, 11))
        {
            return;
        }
        QUESTRECORD_SetQuestState(pQuestInfo, 10, 11);
    }
    else if (nCode == 0x20326671)
    {
        if (!pQuestInfo)
        {
            return;
        }
        if (QUESTRECORD_GetQuestState(pQuestInfo, 18, 11))
        {
            return;
        }
        QUESTRECORD_SetQuestState(pQuestInfo, 18, 11);
    }
    gbQuestTimerActive_007BCC10 = 1;
    gnQuestTimerValue_007BCC14 = 0;
    gdwQuestTimerTicks_007BCC18 = GetTickCount();
    if (!gpHoradricCel_007BCC1C)
    {
        SStrPrintf(szPath, 0x104, "%s\\ui\\menu\\horadric", szDataGlobal_006D4118);
        gpHoradricCel_007BCC1C = sub_004788B0(szPath, 0);
    }
}

// 0x0048A600
void __cdecl sub_0048A600_FreeHoradricCel()
{
    if (gpHoradricCel_007BCC1C)
    {
        sub_00478A00(gpHoradricCel_007BCC1C);
        gpHoradricCel_007BCC1C = 0;
    }
    gbQuestTimerActive_007BCC10 = 0;
    gnQuestTimerValue_007BCC14 = 0;
    gdwQuestTimerTicks_007BCC18 = 0;
}

// 0x0048A630
void __cdecl sub_0048A630_EnterState1()
{
    gdwGlobal_007BCBF0 = 1;
    sub_00468070_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0()->pInventory));
    D2ClientRecordStrc tRecord;
    tRecord.nId = 0x5A;
    tRecord.nFlag = 1;
    *(int*)&tRecord.nValue0 = 0;
    tRecord.nType = 0x0E;
    sub_0049EB10_PostRecord(&tRecord);
}

// 0x0048A680
void __cdecl sub_0048A680_Clear()
{
    gnGlobal_007BCAF0 = 0;
}

// 0x0048A690
int __cdecl sub_0048A690_HasHoverItem()
{
    return gdwGlobal_007BCBF4 != 0;
}

// 0x0048A6A0
void __cdecl sub_0048A6A0_ResetNpcCursor()
{
    gnGlobal_007BCE9C = 0;
    gdwGlobal_007BCBF0 = 0;
    gnGlobal_007BCA4C = 0;
    gnGlobal_007BCBD8 = 0;
    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!pPlayer || !INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        sub_00468070_SetCursorItemState(0);
    }
}

// 0x0048A6E0
extern "C" void __cdecl sub_0048A6E0_SetFlag7BCE28()
{
    gnFlag_007BCE28 = 1;
}

// 0x0048A6F0
void __cdecl sub_0048A6F0_Clear()
{
    gnFlag_007BCE28 = 0;
}

void __cdecl sub_005239C0_ReleaseResources()
{
    if (gResourceA)
    {
        ReleaseResource(gResourceA);
        gResourceA = 0;
    }
    if (gResourceB)
    {
        ReleaseResource(gResourceB);
        gResourceB = 0;
    }
}

// 0x0048A700
void __cdecl sub_0048A700_ToggleExpansionTab()
{
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        gbWeaponSwitch_007BCC4C = !gbWeaponSwitch_007BCC4C;
    }
}

// 0x0048A730
void __cdecl sub_0048A730_ResetEquipSounds()
{
    if (!sub_00408F20_HasExpansionMpq() || !sub_0044DCC0())
    {
        return;
    }
    sub_004B9A00(1, 0, 0, 0, 0);
    sub_00478590(0x60);
    D2InventoryStrc* pInventory = sub_00463DD0()->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (pItem)
    {
        sub_004C21F0(pItem);
    }
    pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (pItem)
    {
        sub_004C21F0(pItem);
    }
}

// 0x0048A790
int __stdcall sub_0048A790_IsCursorInRect(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

// 0x0048A7D0
void __stdcall sub_0048A7D0_DrawUnitName(D2UnitStrc* pUnit)
{
    Unicode wszName[32];
    for (int i = 0; i < 32; ++i)
    {
        wszName[i].wChar = 0;
    }
    const int nOldFont = sub_00502EF0(6);
    Unicode::strncpy(wszName, sub_00464A60_GetUnitName(pUnit), 32);
    wszName[31].wChar = 0;
    Unicode* pEnd = &wszName[31];
    while (sub_00501820(wszName) > 0xA0)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    sub_00502320(wszName, gnGlobal_007A2858 + 0xF, 0xD6 - gnGlobal_007A285C, 0, 0);
    sub_00502EF0(nOldFont);
}

// 0x0048A890
void __cdecl sub_0048A890_DrawPanelLabels()
{
    const int nOldFont = sub_00502EF0(6);
    for (int i = 0; i < sizeof(gaPanelLabels_006D9AE8) / sizeof(gaPanelLabels_006D9AE8[0]); ++i)
    {
        Unicode wszText[100];
        for (int j = 0; j < 100; ++j)
        {
            wszText[j].wChar = 0;
        }
        Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(gaPanelLabels_006D9AE8[i].nString), 99);
        wszText[99].wChar = 0;
        const int nLeft = gaPanelLabels_006D9AE8[i].nX + gnGlobal_007A2858;
        const int nRight = gaPanelLabels_006D9AE8[i].nX2 + gnGlobal_007A2858;
        const int nY = gaPanelLabels_006D9AE8[i].nY - gnGlobal_007A285C;
        Unicode* pSecond;
        if (sub_004A7660_SplitAtNewLine(wszText, &pSecond))
        {
            sub_004A7080(nLeft, nY - 4, nRight, wszText, 0);
            sub_004A7080(nLeft, nY + 4, nRight, pSecond, 0);
        }
        else if (nRight)
        {
            sub_004A7080(nLeft, nY, nRight, wszText, 0);
        }
        else
        {
            sub_00502320(wszText, nLeft, nY, 0, 0);
        }
    }
    sub_00502EF0(nOldFont);
}

// 0x0048B290
static int __stdcall sub_0048B290(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pbSlotMatch)
{
    *pbSlotMatch = 0;
    if (!sub_0044DCC0())
        return 0;
    int bResult = 0;
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x302C, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x302F, ".\\UI\\inv.cpp"))
        return 0;
    if (ITEMSIsA(pItem, 3) || ITEMSIsA(pItem, 0x25))
    {
        bResult = 1;
        *pbSlotMatch = bResult;
    }
    switch (sub_00479120_GetHirelingClassId(!pUnit ? -1 : pUnit->dwUnitId))
    {
    case 0x10F:
        if (ITEMSIsA(pItem, 0x1B))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x152:
        if (ITEMSIsA(pItem, 0x21) || ITEMSIsA(pItem, 0x22))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x167:
        if (ITEMSIsA(pItem, 2))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x230:
        if (ITEMSIsA(pItem, 0x1C) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    case 0x231:
        if (ITEMSIsA(pItem, 0x1E))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bResult = 1;
            *pbSlotMatch = bResult;
        }
        break;
    }
    if (bResult && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
        bResult = 0;
    return bResult;
}

void __fastcall sub_Z12_EmitCanHirelingEquipItem(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int bMatch;
    const int bCan = sub_0048B290(pUnit, pItem, &bMatch);
    sub_Z12_EmitUse2(bCan, bMatch);
}

unsigned char gbGlobal_007BCAD8; // 0x007BCAD8

unsigned char gbGlobal_007BCAD9; // 0x007BCAD9

static __forceinline int IsCursorInRectInline(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

static __forceinline void DrawBodyLocRectInline(D2BodyLocRectStrc* pRect, int nColor)
{
    const int nX = pRect->nLeft;
    const int nY = pRect->nTop;
    if (nX >= 0 && nX < gnAutomapWidth_007A5220 && nY >= 0 && nY < gnAutomapHeight_007A521C)
        sub_0046EFD0_DrawFramedBox(nX, nY, pRect->nWidth, pRect->nHeight, nColor, 0);
}

// 0x0048B3F0
void __fastcall sub_0048B3F0_DrawMercEquipHighlights(D2UnitStrc* pUnit)
{
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0()->pInventory);
    if (!pCursorItem)
        return;
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects_007BCD38[i].nLeft > 0 && IsCursorInRectInline(gaBodyLocRects_007BCD38[i].nLeft, gaBodyLocRects_007BCD38[i].nTop, gaBodyLocRects_007BCD38[i].nRight, gaBodyLocRects_007BCD38[i].nBottom))
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            int bMatch;
            if (ITEMS_CheckBodyLocation(pCursorItem, i) && sub_0048B290(pUnit, pCursorItem, &bMatch) && ITEMS_CheckRequirements(pCursorItem, pUnit, 0, 0, 0, 0))
                DrawBodyLocRectInline(&gaBodyLocRects_007BCD38[i], gbGlobal_007BCAD9);
            else
                DrawBodyLocRectInline(&gaBodyLocRects_007BCD38[i], gbGlobal_007BCAD8);
        }
    }
}

D2InventoryGridInfoStrc gInventoryGrid_007BCBC0; // 0x007BCBC0

// 0x0048B540
static void sub_0048B540_DrawEquippedItems(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    for (int i = 0; i < 11; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (pItem)
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
            const int nX = gaBodyLocRects_007BCD38[i].nLeft
                + (gaBodyLocRects_007BCD38[i].nWidth - nWidth * gInventoryGrid_007BCBC0.nGridBoxWidth) / 2;
            const int nY = gaBodyLocRects_007BCD38[i].nTop
                + (gaBodyLocRects_007BCD38[i].nHeight - nHeight * gInventoryGrid_007BCBC0.nGridBoxWidth) / 2;
            sub_0046EE80_DrawCursorItem(pItem, nX, nY);
            if (gdwGlobal_007BCBF4 == pItem && ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0
                && ITEMS_CheckItemFlag(pItem, 0x800, 0x30C8, ".\\UI\\inv.cpp"))
            {
                sub_00483E40(pItem, &gInventoryGrid_007BCBC0, nX, nY);
            }
        }
    }
}

// 0x0048B640
D2UnitStrc* __cdecl sub_0048B640_GetMercUnit()
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0);
    if (nPetId != -1)
    {
        D2UnitStrc* pMerc = sub_00463990(nPetId, 1);
        if (pMerc)
        {
            return pMerc;
        }
    }
    sub_00455F20(0x24, 2, 0);
    return 0;
}

static __forceinline int INV_GetUnitIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x0048B7C0
void __stdcall sub_0048B7C0_HandleMercInvClick(SMSGHANDLER_PARAMS* pMsg)
{
    const int nPetId = sub_00478F20_FindPetIdByOwner(sub_00463DD0(), 7, 0);
    if (nPetId == -1)
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pPet = sub_00463990(nPetId, 1);
    if (!pPet)
    {
        sub_00455F20(0x24, 2, 0);
        return;
    }

    pMsg->bReturn = 0;
    sub_00467FA0(pMsg);
    gnGlobal_007BCEA0 = 0;
    if (!IsCursorInRectInline(0, 0, gnGlobal_0071146C / 2, gnGlobal_00711470 - 0x31))
    {
        return;
    }

    if (IsCursorInRectInline(gnGlobal_007A2858 + 0x110, gnGlobal_007A285C + gnGlobal_00711470 - 0x5F, gnGlobal_007A2858 + 0x130, gnGlobal_007A285C + gnGlobal_00711470 - 0x3F))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00455F20(0x24, 2, 0);
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(sub_00463DD0()->pInventory);
    for (int i = 0; i < 11; ++i)
    {
        if (gaBodyLocRects_007BCD38[i].nLeft > 0 && IsCursorInRectInline(gaBodyLocRects_007BCD38[i].nLeft, gaBodyLocRects_007BCD38[i].nTop, gaBodyLocRects_007BCD38[i].nRight, gaBodyLocRects_007BCD38[i].nBottom))
        {
            if (pCursorItem)
            {
                int bSlotMatch = 0;
                if (ITEMS_CheckBodyLocation(pCursorItem, i) && ITEMS_CheckRequirements(pCursorItem, pPet, 0, 0, 0, 0) && sub_0048B290(pPet, pCursorItem, &bSlotMatch))
                {
                    sub_004C21F0(pCursorItem);
                    sub_004B9A00(sub_004C1D60(pCursorItem), 0, 0, 0, 0);
                    sub_004785B0_SendPacket3(0x61, 0);
                }
                else if (ITEMS_CheckBodyLocation(pCursorItem, i) && sub_0048B290(pPet, pCursorItem, &bSlotMatch) && bSlotMatch)
                {
                    sub_004CBDE0_PetCommand(INV_GetUnitIdInline(pPet), 1, 0x56);
                }
                else
                {
                    sub_004CBDE0_PetCommand(INV_GetUnitIdInline(pPet), 1, 0x55);
                }

                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }

            if (pPet->pInventory)
            {
                D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPet->pInventory, i);
                if (pItem)
                {
                    sub_004C21F0(pItem);
                    sub_004785B0_SendPacket3(0x61, i);
                    gdwGlobal_007BCBE4 = 0;
                    gdwGlobal_007BCBE8 = 0;
                    gdwGlobal_007BCBF4 = 0;
                }
            }
        }
    }

    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x0048BBE0
void __fastcall sub_0048BBE0_SetNameText(const Unicode* wszName, int nUnused, int nArg)
{
    sub_005267E0(gwszName_007BCEA8, wszName);
    gdwGlobal_007BCEA4 = nArg;
    sub_00455F20(0x25, 0, 0);
}

// 0x0048BE00
void __fastcall sub_0048BE00_CutBracketToken(Unicode* pString, const Unicode* pToken)
{
    Unicode wszOpen[2] = { '[', 0 };
    Unicode wszText[100];
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    Unicode* pFound = sub_00526940_UnicodeStrStr(pString, pToken);
    if (pFound)
    {
        pFound += 4;
        const int nLength = sub_00526800(pFound);
        Unicode::strncpy(wszText, pFound, nLength - sub_00526800(sub_00526940_UnicodeStrStr(pFound, wszOpen)));
        sub_005267E0(pString, wszText);
    }
}

// 0x00492770
void __stdcall sub_00492770_KeyIfReadyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_0044DCC0())
    {
        if (!(pMsg->lParam & 0x40000000) && !sub_00453A90_GetUIVarUnchecked(5))
            sub_0048A730();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_HandleMsg(pMsg);
    }
}

// 0x00493100
void __stdcall sub_00493100_DrawNumber(int nValue, int nX)
{
    Unicode wszConverted[32];
    for (int i = 0; i < 32; ++i)
    {
        wszConverted[i].wChar = 0;
    }
    Unicode wszText[32];
    for (int i = 0; i < 32; ++i)
    {
        wszText[i].wChar = 0;
    }
    char szNumber[0x20];
    sprintf(szNumber, szIntFormat_006D57BC, nValue);
    memset(wszText, 0, sizeof(wszText));
    sub_00526320_ToUnicode(wszConverted, szNumber, 32);
    Unicode::strncpy(wszText, wszConverted, 32);
    wszText[31].wChar = 0;
    Unicode* pEnd = &wszText[sub_00526800(wszText)];
    while (sub_00501820(wszText) > 0x2E)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    const int nOldFont = sub_00502EF0(6);
    sub_00502320(wszText, nX + 8, 0x37, 0, 0);
    sub_00502EF0(nOldFont);
}

// 0x004953C0
int __fastcall sub_004953C0_GetCenteredX(unsigned short nString, int nX)
{
    Unicode wszText[100];
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    return nX - sub_00501820(wszText) / 2;
}

// 0x00496720
void __stdcall sub_00496720_ButtonReleaseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (gdwGlobal_007BEEFC)
    {
        if (D2GFX_GetResolutionMode() == 2)
        {
            if (nX >= 0x2AD && nX <= 0x2CD && nY >= 0x18 && nY <= 0x38)
            {
                sub_00455F20(0x21, 2, 0);
                sub_00494FC0();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
        else
        {
            if (nX >= 0x20D && nX <= 0x22D && nY >= 0x18 && nY <= 0x38)
            {
                sub_00455F20(0x21, 2, 0);
                sub_00494FC0();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
    }
    gdwGlobal_007BEEFC = 0;
    sub_0044DA70();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x004967F0
void __cdecl sub_004967F0_LoadPanelCels()
{
    char szPath[0x104];
    gpCellFile_007BEF7C = sub_004520C0_LoadUiCelFile("Panel\\btn");
    const int nLanguage = sub_00525150();
    int bExpansion = 0;
    if (sub_00408F20_HasExpansionMpq() && sub_0044DCC0())
    {
        bExpansion = 1;
    }
    if (nLanguage >= 6 && nLanguage <= 9)
    {
        if (bExpansion)
        {
            sprintf(szPath, "%s\\UI\\InvChar6", szDataLocal_006D41A8);
        }
        else
        {
            sprintf(szPath, "%s\\UI\\InvChar", szDataLocal_006D41A8);
        }
        gpCellFile_007BEF64 = sub_004788B0(szPath, 0);
    }
    else
    {
        gpCellFile_007BEF64 = sub_004520C0_LoadUiCelFile(bExpansion ? "Panel\\InvChar6" : "Panel\\InvChar");
    }
    gpCellFile_007BEF78 = sub_004520C0_LoadUiCelFile("Panel\\Arrow");
    gpCellFile_007BEF24 = sub_004520C0_LoadUiCelFile("Panel\\Invwarn");
    gpCellFile_007BEF60 = sub_004520C0_LoadUiCelFile("Panel\\DuroIcon");
    gpCellFile_007BEF14 = sub_004520C0_LoadUiCelFile("Panel\\GemSocket");
    gpCellFile_007BEF10 = sub_004520C0_LoadUiCelFile("Panel\\ctrlpnl_popbelt");
    gpCellFile_007BEF68 = sub_004520C0_LoadUiCelFile("Panel\\Hlthmana");
    gpCellFile_007BEF80 = sub_004520C0_LoadUiCelFile("Panel\\overlap");
    gpStateButtonCel_007BEF70 = sub_004520C0_LoadUiCelFile("Panel\\menubutton");
    gpCellFile_007BEF2C = sub_004520C0_LoadUiCelFile("Panel\\menupanel");
    gpCellFile_007BEF20 = sub_004520C0_LoadUiCelFile("Panel\\skillpoints");
    gpGlobal_007BEF0C = sub_004520C0_LoadUiCelFile("Panel\\runbutton");
    gpCellFile_007BEF28 = sub_004520C0_LoadUiCelFile("Panel\\hostilepic");
    memset(gabGlobal_007BEF30, 0, sizeof(gabGlobal_007BEF30));
    SRegLoadValue("Diablo II", "Show HP Text", 0, &gdwShowHpText_007BEFDC);
    SRegLoadValue("Diablo II", "Show MP Text", 0, &gdwShowMpText_007BEFE0);
}

// 0x00497300
void __cdecl sub_00497300_DrawKeyBindingPopup()
{
    Unicode wszText[200];
    for (int i = 0; i < 200; ++i)
    {
        wszText[i].wChar = 0;
    }
    Unicode wszKey[30];
    for (int i = 0; i < 30; ++i)
    {
        wszKey[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x1053));
    if (sub_00469AA0(0x23, 1) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), sub_0046A530_GetKeyName(0x23, 1));
        sub_00526700(wszText, wszKey);
    }
    if (sub_00469AA0(0x23, 0) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), sub_0046A530_GetKeyName(0x23, 0));
        sub_00526700(wszText, wszKey);
    }
    sub_00502280_SetPopUpText(wszText, gnGlobal_0071146C / 2 - 0x91, gnGlobal_00711470 - 0x17, 0, 1);
}

// 0x004A17D0
void __stdcall sub_004A17D0(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_007BF23F = 1;
    if (sub_00467A10())
    {
        if (gdwGlobal_007BF20A && sub_00463990(gdwGlobal_007BF202, 1) == sub_00467A10())
            return;
    }
    else if (!sub_00467A10() && gnGlobal_007BF23A)
    {
        D2UnitStrc* pUnit = sub_00463990(gdwGlobal_007BF23B, 1);
        if (pUnit && pUnit == sub_00463990(gdwGlobal_007BF202, 1))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
        }
        return;
    }
    sub_004A1770(pMsg);
}

// 0x004A7A80
extern "C" void __cdecl sub_004A7A80_ClearFlag7C02EC()
{
    gnFlag_007C02EC = 0;
}

// 0x004AA0C0
void __fastcall sub_004AA0C0_SetSlot(int nSlot, int nValueA, int nValueB, int nValueC)
{
    gnHotkeySkill_007C06C8[nSlot] = nValueA;
    gbHotkeyLeft_007C07B8[nSlot] = nValueB;
    gnHotkeyOwner_007C0768[nSlot] = nValueC;
}

// 0x004AA8F0
extern "C" void __cdecl sub_004AA8F0_ClearValue7C0C3C()
{
    gnValue_007C0C3C = 0;
}

// 0x004B1050
int __fastcall sub_004B1050_GetMonsterValue(D2UnitStrc* pUnit, char* pNotFound, int* pValue)
{
    *pNotFound = 1;
    *pValue = -1;
    if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && pUnit->pMonsterData->nOwnerGUID != -1)
    {
        *pValue = pUnit->pMonsterData->nOwnerGUID;
        *pNotFound = 0;
        return 1;
    }
    return 0;
}

// 0x004B92E0
int __stdcall sub_004B92E0_GetTableByte(int nUnused, int nIndex)
{
    D2_ASSERT(gdwTableInit_007C0ECC, 0x60);
    D2_ASSERT(nIndex < 0x25, 0x65);
    return gaTable_007C0EA4[nIndex];
}

#include "gen/data/Source/D2Client/UI/inv.inc"
