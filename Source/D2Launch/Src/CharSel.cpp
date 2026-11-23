#include "D2Launch.h"
#include "D2StormTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2MultiTypes.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"

#pragma intrinsic(strlen)

struct D2UnitStrc;

struct D2ActiveRoomStrc;

struct D2InventoryStrc;

struct D2DynamicPathStrc;

struct D2StatListStrc;

struct SMSGHANDLER_PARAMS;

struct D2CharSelCacheStrc;

struct D2StatesTxt;

struct D2DataTablesStrc;

struct D2LaunchRequestStrc;

struct D2UnitDropItemsPacketStrc;

struct D2GridCellStrc;

struct D2CelFileStrc;

struct Unicode;

struct D2FuncTable_0077ABF0Strc;

struct D2LaunchCharInfoStrc;

struct D2FuncRecordStrc;

struct D2LaunchCharEntryStrc;

extern "C" char* __cdecl strstr(const char* szString, const char* szSubString); // 0x00686900

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern "C" int __stdcall CHARSEL_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel); // 0x0043A460

static int gnCharEntryCount; // 0x00779DC4

extern int gdwGlobal_0070CC08; // 0x0070CC08

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

void __fastcall CONTROL_SetVisible(D2WinControlStrc* pControl, int bSet); // 0x004F9740

int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0

void __fastcall CHARSEL_JoinSelectedWithDifficulty(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0

void __fastcall sub_004FC660_SetValue(D2WinControlStrc* pControl, int nValue); // 0x004FC660

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190

int __cdecl sub_0042F6D0(); // 0x0042F6D0

extern D2WinControlStrc* gpControl_007795E0; // 0x007795E0

extern D2WinControlStrc* gpControl_007795E4; // 0x007795E4

D2LaunchSlotStrc** gppSlots;                                                                       // 0x00779988

int gnSlotCount;                                                                                     // 0x0077998C

unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0

char* __fastcall CHARSEL_GetSlotName(int nIndex); // 0x00430B50

int __cdecl MAINMENUS_FreeSlots(); // 0x00430A20

D2CharSelCacheStrc* gpCharSelCache; // 0x00779DE8

static int gbFlag_00779C6C;             // 0x00779C6C

extern char gszBaseName_00779B68[]; // 0x00779B68

struct D2LaunchRequestStrc
{
    int nData[5];
    unsigned int dwFlags;
};

struct D2UnitDropItemsPacketStrc
{
    char nHeader;
    char bActive;
    char nUnitId[4];
    char nOtherUnitId[4];
};

struct D2GridCellStrc
{
    int nFlag;
    unsigned char nValue[4];
};

typedef void (__stdcall* D2RecordHandlerFn)(int nArg1, int nArg2, int nArg3);

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds); // 0x006CC258

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

void __cdecl sub_00444E70_FillGameList(); // 0x00444E70

void __fastcall WINMAIN_SendMcpGameListRequest(D2LaunchRequestStrc* pRequest, unsigned short wRequestId); // 0x0044A590

void __cdecl RECORD_WriteRecordFile(); // 0x00451620

extern "C" D2StatesTxt* __fastcall sub_00452040_GetStatesTxtRecord(int nStateId); // 0x00452040

void __cdecl AUTOMAP_SaveAutomapLayer(); // 0x004584C0

void __cdecl AUTOMAP_ResetAutomapCells(); // 0x00458680

void __cdecl AUTOMAP_LoadAutomapLayer(); // 0x00458750

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall UI_DrawLoadingScreen(int nArg); // 0x004565E0

unsigned char __stdcall AUTOMAP_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00462EE0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

void __fastcall GFX_DrawProgressiveStateOverlays(D2UnitStrc* pUnit, int nOverlay, int nX, int nY); // 0x0046E1B0

void __fastcall GFX_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280

void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70

void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0

D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90

void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648CE0

void __stdcall sub_00649190_SetPathMode(D2UnitStrc* pUnit, int nMode); // 0x00649190

int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern unsigned short gwRequestId; // 0x0070CD60

extern int gnGlobal_007111CC; // 0x007111CC

extern int gnGlobal_007111D0; // 0x007111D0

extern int gnGlobal_007111D4; // 0x007111D4

extern int gnScreenWidth; // 0x0071146C

extern int gnScreenHeight; // 0x00711470

extern unsigned short gwSavedRequestId; // 0x0077BBDC

extern void* gpGlobal_007A0634; // 0x007A0634

extern void* gpAutomapContext; // 0x007A5164

extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68

extern int gnProgress; // 0x007BB3B4

void __stdcall CHARSEL_AddToScrollValue(int nDelta); // 0x00439E60

int __stdcall CHARSEL_HandleListKey(SMSGHANDLER_PARAMS* pMsg); // 0x00439E90

static int gnTopRow; // 0x00779DC8

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430

void __fastcall CHARSEL_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __cdecl CHARSEL_DisconnectBattleNet(); // 0x0043B9A0

int gnBusy; // 0x00779DAC

extern "C" unsigned int __cdecl strlen(const char* sz);

int __stdcall sub_005041B0_Destroy(D2CelFileStrc* pCellFile, int nFlag); // 0x005041B0

D2LaunchCharEntryStrc* gpCharEntry_00779DC0;                                                                // 0x00779DC0

struct D2WinTextBoxStrc;

struct D2WinButtonStrc;

int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0

int __stdcall CHARSEL_OnScroll(SMSGHANDLER_PARAMS* pMsg);                                              // 0x00439DF0

int __cdecl CHARSEL_InitRealmScreen();                                                                 // 0x0043A2B0

void __fastcall CHARSEL_UseName(char* szName);                                                         // 0x0043ADB0

void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags);                     // 0x004F96F0

void __fastcall sub_004FB590(int nFont);                                                                    // 0x004FB590

int __fastcall D2Win_10191(D2WinTextBoxStrc* pTextBox, int nMaxSteps);                                      // 0x004FC5E0

int __fastcall D2Win_10194(D2WinTextBoxStrc* pTextBox, D2WinTextBoxStrc* pLinkedTextBox);                   // 0x004FC6A0

int __fastcall D2Win_10195(D2WinTextBoxStrc* pTextBox, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x004FC6E0

void __fastcall BUTTON_SetStringId(D2WinButtonStrc* pButton, int nStringId);                                // 0x00500BF0

D2WinControlStrc* gpControl_007799F8;                                                                       // 0x007799F8

extern void* gapRowControls[];                                                                     // 0x00779A20

extern char gszPreferredRealm[];                                                                               // 0x00779A40

void* gapRowControlsX[8];                                                                          // 0x00779B40

D2WinControlStrc* gpControl_00779C84;                                                                       // 0x00779C84

static int gnSelected;         // 0x0070CC00

static D2WinControlStrc* gpCharSelectText; // 0x00779DD4

static D2WinControlStrc* gpControl_00779DD0;        // 0x00779DD0

static int gnLastValue;        // 0x00779DCC

int __stdcall CHARSEL_OnCreateAccountTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B8E0

int __stdcall CHARSEL_OnChangePasswordTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B940

D2RecordHandlerFn gpfnPrevHandler; // 0x007A2764

int gbOverlaysEnabled; // 0x007A289C

int gnOverlayStep; // 0x007A3138

int gnCellOriginX; // 0x007B0A54

int gnCellOriginY; // 0x007B0A58

void __fastcall SCMD_DropUnitItems(D2UnitDropItemsPacketStrc* pPacket); // 0x00462F60

struct D2ListMsgStrc
{
    void* hWnd;
    unsigned int uMessage;
};

int __stdcall COMCALLBACK_OnCharSelectOk(D2ListMsgStrc* pMsg); // 0x00439840

struct D2CompositeUnitStrc;

struct D2LaunchCharEntryStrc
{
    char szName[0x100];                                     // 0x000
    Unicode wszName[0x100];                                 // 0x100
    unsigned char aFlags[16];                               // 0x300
    unsigned char aColors[16];                              // 0x310
    unsigned char nType;                                    // 0x320
    unsigned char unk0x321;                                 // 0x321
    union
    {
        unsigned short nLevel;                              // 0x322
        short nWord322;
    };
    union
    {
        struct
        {
            union
            {
                unsigned short wFlags;                      // 0x324
                short nWord324;
            };
            short nWord326;                                 // 0x326
        };
        int nFlags;                                         // 0x324
    };
    short nWord328;                                         // 0x328
    char szCode32A[4];                                      // 0x32A
    union
    {
        unsigned char nByte32E;                             // 0x32E
        char cByte32E;
    };
    union
    {
        unsigned char nByte32F;                             // 0x32F
        char cByte32F;
    };
    union
    {
        unsigned char nByte330;                             // 0x330
        char cByte330;
    };
    char unk0x331[3];                                       // 0x331
    int nState;                                             // 0x334
    union
    {
        D2CompositeUnitStrc* pCompositeUnit;                // 0x338
        D2CelFileStrc* pCellFile;
        void* pAnim;
    };
    int unk0x33C;                                           // 0x33C
    unsigned int nKeyLow;                                   // 0x340
    unsigned int nKeyHigh;                                  // 0x344
    union
    {
        unsigned int nExpireTime;                           // 0x348
        int nFlag348;
    };
    D2LaunchCharEntryStrc* pNext;                           // 0x34C
};

struct D2CharSaveIdStrc
{
    unsigned char f_0[0x10];
};

struct D2CharSaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    char unk0x0C[0x08];
    char szName[0x10];
    unsigned int dwFlags;
    unsigned char nClass;
    unsigned char nUnk0x29;
    unsigned char nUnk0x2A;
    unsigned char nUnk0x2B;
    long nCreateTime;
    long nSaveTime;
    char unk0x34[0x54];
    D2CharSaveIdStrc tId;
    int anUnk0x98[4];
    char unk0xA8[0xA7];
};

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId);                              // 0x0042F3A0

void __cdecl MAINMENUS_DestroyControls();                                                                // 0x0042F3F0

void __cdecl MAINMENUS_Reset();                                                                          // 0x0042F480

void __cdecl MAINMENUS_ShowConnectingPopup();                                                                                // 0x0042F6E0

extern "C" void __cdecl MAINMENUS_ConfigureLanguageLayout(); // 0x00432EF0

int __stdcall MAINMENUS_PollCharDelete(int nArg);                                                                       // 0x00433020

int __stdcall MAINMENUS_PollCharUpgrade(int nArg);                                                                       // 0x00433060

void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg);           // 0x00433380

void __cdecl CHARSEL_UpdateButtons();                                                                                // 0x0043A730

void __stdcall sub_00449E50_SetValue(int nValue);                                                                    // 0x00449E50

void __fastcall WINMAIN_SendMcpCharDelete(const char* szName, unsigned short nArg);                                      // 0x0044A7A0

void __fastcall WINMAIN_SendMcpCharUpgrade(const char* szName);                                                           // 0x0044A810

void __cdecl VIEW_SendMcpCancelGameCreate();                                                                                // 0x0044AA80

int __stdcall CONTROL_SetFocusedEditBox(void* pEditBox);                                                                  // 0x004F91C0

int __stdcall CONTROL_SetCellFile(D2WinControlStrc* pControl, D2CelFileStrc* pCellFile);                          // 0x004F91A0

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590

void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB);                                      // 0x004FB740

int __fastcall sub_004FB990_GetSelection(D2WinControlStrc* pControl);                                       // 0x004FB990

void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText);                      // 0x004FCF80

int __stdcall sub_004FD0B0_SetColor(D2WinControlStrc* pControl, int nColor, int nValue);                    // 0x004FD0B0

int __stdcall sub_00500810(D2WinControlStrc* pControl, int nArg);                                           // 0x00500810

int __stdcall D2Win_10125();                                                                                // 0x00501A40

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

int __stdcall sub_00518150(D2FuncRecordStrc* pRecord, int nIndex);                                          // 0x00518150

D2FuncTable_0077ABF0Strc* __cdecl sub_00518C00();                                                           // 0x00518C00

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern "C" const char* const gapszSkyPalette[2];                                                   // 0x006D3A08

extern int gnSelectionA;                                                                           // 0x0070CC04

extern D2WinControlStrc* gpGatewayList;                                                                // 0x00779590

extern D2LaunchRecordStrc* gpLaunchRecord;                                                         // 0x007795D4

D2WinControlStrc* gpList_0077995C;                                                                          // 0x0077995C

D2WinControlStrc* gpList_00779960;                                                                          // 0x00779960

D2WinControlStrc* gpList_00779964;                                                                          // 0x00779964

extern int gnListPos;                                                                              // 0x0077996C

extern D2WinControlStrc* gpControl_007799EC;                                                                // 0x007799EC

extern D2WinControlStrc* gpCharDescriptionText;                                                                // 0x007799F0

D2WinControlStrc* gpControl_007799F4;                                                                       // 0x007799F4

extern int ganRowValues_007799FC[];                                                                         // 0x007799FC

extern D2WinControlStrc* gpScrollUpButton;                                                                // 0x00779A1C

D2WinControlStrc* gpCharNameText;                                                                       // 0x00779B60

extern D2WinControlStrc* gpScrollDownButton;                                                                // 0x00779B64

D2WinControlStrc* gpControl_00779C68;                                                                       // 0x00779C68

extern D2WinControlStrc* gpControl_00779C70;                                                                // 0x00779C70

extern D2WinControlStrc* gpControl_00779C74;                                                                // 0x00779C74

extern D2WinControlStrc* gpControl_00779C78;                                                                // 0x00779C78

extern D2WinControlStrc* gpControl_00779C7C;                                                                // 0x00779C7C

D2WinControlStrc* gpControl_00779C80;                                                                       // 0x00779C80

extern char gszEnteredName[];                                                                             // 0x00779C88

extern D2WinControlStrc* gpControl_00779D88;                                                                // 0x00779D88

D2WinControlStrc* gpControl_00779D90;                                                                       // 0x00779D90

D2WinControlStrc* gpControl_00779D94;                                                                       // 0x00779D94

extern D2WinControlStrc* gpControl_00779D9C;                                                                // 0x00779D9C

unsigned long gdwStartTick;                                                                        // 0x00779DB4

extern D2LaunchCharEntryStrc* gpCharList;                                                          // 0x00779DBC

extern D2CharSaveHeaderStrc gtCharSaveHeader;                                                      // 0x0077AC10

#define gdwFlags_0077AC34 (gtCharSaveHeader.dwFlags)

extern D2WinControlStrc* gapControls[];                                                             // 0x0077ADA8

extern D2CriticalSectionStrc gtChatLock;                                                           // 0x0077AE28

extern D2WinControlStrc* gapControls_0077B050[2];                                                           // 0x0077B050

extern D2WinControlStrc* gpQuitButton;                                                                // 0x0077B080

extern char gaszHistory[10][0x100];                                                                // 0x0077B1D8

extern int gnControlCount;                                                                         // 0x0077BBE8

extern unsigned long gdwConnectTime;                                                               // 0x0077BBF0

extern D2WinControlStrc* gpControl_0077BC40;                                                                // 0x0077BC40

extern D2CelFileStrc* gpRadioButtonGreyCelFile;                                                                 // 0x0077BC6C

extern D2WinControlStrc* gpCreateJoinBckgImage;                                                                // 0x0077BCDC

extern D2WinControlStrc* gpChannelScreenTitle;                                                                // 0x0077BCE0

extern D2WinControlStrc* gpControl_0077BCE4;                                                                // 0x0077BCE4

extern D2WinControlStrc* gpControl_0077BCE8;                                                                // 0x0077BCE8

extern D2WinControlStrc* gpChannelOkButton;                                                                 // 0x0077BCEC

extern D2WinControlStrc* gpControl_0077BCF0;                                                                // 0x0077BCF0

extern D2WinControlStrc* gpChannelListBox;                                                                // 0x0077BCFC

extern int gdwGlobal_0077BD50;                                                                              // 0x0077BD50

extern D2ChatMessageStrc* gpChatQueueHead;                                                         // 0x0077BDAC

D2ChatMessageStrc* gpChatQueueTail;                                                                // 0x0077BDB0

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6

void __fastcall sub_A15_UseText(const Unicode* pText);

void __cdecl sub_00439CC0_CreateControls(); // 0x00439CC0

void __cdecl CHARSEL_UpdateStatus(); // 0x0043A270

#pragma intrinsic(memset)

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength);               // 0x005263E0

extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0

D2CompositeUnitStrc* __stdcall sub_005066C0_CreateComposite(int nSel, int nMode, unsigned char* pFlags, unsigned char* pColors);

void __stdcall D2Win_10149(D2CompositeUnitStrc* pCompositeUnit, unsigned char nValue);                     // 0x005051A0

void __stdcall D2Win_10151(D2CompositeUnitStrc* pCompositeUnit, int nFrame);                               // 0x00505260

int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode);                                // 0x005042F0

void __cdecl sub_00438560_Refresh();

char* gpszName; // 0x00779DB0

unsigned long gdwLastClick; // 0x00779DEC

extern "C" int __cdecl tolower(int nChar);

// build: symbol ?gacCDKeyMap@* 0x006DF238
extern const char gacCDKeyMap[];

// 0x0042E5B0
char* __cdecl CHARSEL_StrStr(char* szString, const char* szSubString)
{
    return strstr(szString, szSubString);
}

// 0x0042FDE0
int __stdcall CHARSEL_IsRestrictedChar(void* pControl, int nUnused, const char* pChar)
{
    char c = *pChar;
    switch (c)
    {
    case '"':
    case '#':
    case '%':
    case '*':
    case ',':
    case '/':
    case '<':
    case '>':
    case '?':
    case '\\':
        return 0;
    }
    if (c <= 0x20)
        return 0;
    return c < 0x7F;
}

// 0x0042FE70
int __stdcall CHARSEL_FilterLoginChar(void* pControl, int nUnused, const char* pChar)
{
    char c = *pChar;
    switch (c)
    {
    case '"':
    case '#':
    case '%':
    case '*':
    case ',':
    case '/':
    case '<':
    case '>':
    case '?':
    case '\\':
        return 0;
    }
    if (c <= 0x20)
        return 0;
    return c < 0x7F;
}

// 0x00430120
int __stdcall sub_00430120_OnToggle(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam)
        CONTROL_SetVisible(gpControl_007795E0, 1);
    else
        CONTROL_SetVisible(gpControl_007795E0, 0);
    return 1;
}

// 0x00430160
int __stdcall sub_00430160_OnToggle(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam)
        CONTROL_SetVisible(gpControl_007795E4, 1);
    else
        CONTROL_SetVisible(gpControl_007795E4, 0);
    return 1;
}

// 0x004303E0
bool __stdcall CHARSEL_IsLineBreak(Unicode wc)
{
    if (wc.wChar == 13 || wc.wChar == 10)
        return true;
    return false;
}

// 0x00430520
void __cdecl sub_00430520()
{
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xCD);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xCE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xCF);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14B7), 0, 0, 0);
}

// 0x004306C0
void __cdecl CHARSEL_UpdateLoginOk()
{
// build: symbol ?gpAccountEdit@* 0x0077958C
    const Unicode* pName = sub_004FDD90_GetEditText(gpAccountEdit);
// build: symbol ?gpPasswordEdit@* 0x00779334
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpPasswordEdit);
    int bOk = 0;
    if (pName && pPassword)
    {
        int nNameLength = sub_00526800(pName);
        int nPasswordLength = sub_00526800(pPassword);
        if (nNameLength >= 1 && nNameLength <= 50 && nPasswordLength >= 1 && nPasswordLength <= 13)
            bOk = 1;
    }
    if (gpControl_00779594)
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpControl_00779594, bOk);
}

// 0x00430840
int __stdcall CHARSEL_OnHoverSorceress(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 1, 0xFAA, 0x140B);
    return 1;
}

// 0x00430870
int __stdcall CHARSEL_OnHoverAmazon(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 0, 0xFAB, 0x1408);
    return 1;
}

// 0x00430920
int __stdcall CHARSEL_OnHoverNecromancer(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 2, 0xFA9, 0x1409);
    return 1;
}

// 0x00430950
int __stdcall CHARSEL_OnHoverBarbarian(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 4, 0xFA7, 0x140A);
    return 1;
}

// 0x00430980
int __stdcall CHARSEL_OnHoverPaladin(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 3, 0xFA8, 0x140C);
    return 1;
}

// 0x004309C0
int __stdcall CHARSEL_AddToSlots(void* pEntry)
{
    D2_ASSERT(gppSlots, 4383);
    for (int i = 0; i < gnSlotCount; i++)
    {
        if (!gppSlots[i])
        {
            gppSlots[i] = (D2LaunchSlotStrc*)pEntry;
            return 1;
        }
    }
    return 0;
}

// 0x00430B00
int __cdecl CHARSEL_CompareNames(const void* pEntry1, const void* pEntry2)
{
    return strcmp(**(const char* const* const*)pEntry1, **(const char* const* const*)pEntry2);
}

// 0x00430B50
char* __fastcall CHARSEL_GetSlotName(int nIndex)
{
    D2LaunchSlotStrc* pSlot = gppSlots[nIndex];
    D2_ASSERT(pSlot, 0x115C);
    return pSlot->szName;
}

// 0x00430C80
void __cdecl CHARSEL_FillCreditsList()
{
    for (int i = 0; i < 50; i++)
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
    D2Win_10045(gpList_00779964, "The End");
    gnListPos = sub_004FB950_GetFirstVisible(gpList_00779964);
}

// 0x00430EF0
void __cdecl CHARSEL_SyncCreditsLists()
{
    int nFirst = sub_004FB950_GetFirstVisible(gpList_00779964);
    int nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
    int nThird = sub_004FB950_GetFirstVisible(gpList_00779960);
    while (nSecond > nThird)
    {
        D2Win_10045(gpList_00779960, &gszEmptyAssertText);
        nThird = sub_004FB950_GetFirstVisible(gpList_00779960);
    }
    while (nSecond < nThird)
    {
        D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
        nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
    }
    while (nFirst > nSecond)
    {
        D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
        nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
        D2Win_10045(gpList_00779960, &gszEmptyAssertText);
    }
    while (nFirst < nSecond)
    {
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
        nFirst = sub_004FB950_GetFirstVisible(gpList_00779964);
    }
    D2Win_10045(gpList_00779964, &gszEmptyAssertText);
    D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
    D2Win_10045(gpList_00779960, &gszEmptyAssertText);
}

// 0x00431570
void __fastcall CHARSEL_CreateExpansionDiscPopup(int bFlag)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0x3C);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    if (bFlag)
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x5578), 0, 0, 0);
    else
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1431), 0, 0, 0);
}

// 0x004325B0
void __cdecl sub_004325B0_CreateScreen()
{
    MAINMENUS_Reset();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(6);
    sub_00500810(pControl, 0);
    pControl = MAINMENUS_CreateControl(7);
    sub_00500810(pControl, 0);
    MAINMENUS_CreateControl(8);
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    MAINMENUS_CreateFromTemplate(0x4D);
    MAINMENUS_CreateFromTemplate(0x63);
    MAINMENUS_CreateFromTemplate(0x64);
    pControl = MAINMENUS_CreateFromTemplate(0x5F);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x146B), 0, 0, 0);
    D2WinControlStrc* pList = MAINMENUS_CreateFromTemplate(0x60);
    int nOld = D2Win_10127_SetFont(5);
    int nValue = D2Win_10125();
    D2Win_10127_SetFont(nOld);
    sub_004FC9B0_SetText(pList, D2LANG_GetStringFromTblIndex(0x146C), 0, 0, 0);
    sub_004FB740(pList, nValue / -10, 0);
    pControl = MAINMENUS_CreateFromTemplate(0x61);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x146D), 0, 0, 0);
    sub_004FB740(pControl, nValue / -10, 0);
    pControl = MAINMENUS_CreateFromTemplate(0x62);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B77), 0, 0, 0);
}

// 0x00433450
void __fastcall CHARSEL_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_ShowMessage(pText, pfnDone, 1);
}

// 0x00434700
int __stdcall CHARSEL_OnRealmSelected(SMSGHANDLER_PARAMS* pMsg)
{
    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
    int nSelection = sub_004FB990_GetSelection(gpGatewayList);
    if (nSelection != -1)
    {
        nSelection += 1;
        sub_00518150(pRecord, nSelection);
        SRegSaveString("Diablo II", "Preferred Realm", 0, sub_005180E0(pRecord, nSelection));
    }
    MAINMENUS_Reset();
    sub_004336C0();
    return 1;
}

// 0x00434960
int __fastcall CHARSEL_DeleteCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName)
{
    if (!sub_00449B30_QueryAddress())
    {
        int nResult = MAINMENUS_ConnectToRealm(szName, 0);
        if (nResult >= 1 && nResult <= 2)
        {
            D2MCPClientCloseMCP();
            return 0;
        }
    }
    MAINMENUS_ShowConnectingPopup();
    WINMAIN_SendMcpCharDelete(pEntry->szName, 0);
    sub_004FA590_RunLoop(MAINMENUS_PollCharDelete);
    return 1;
}

// 0x004349B0
int __fastcall CHARSEL_UpgradeCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName)
{
    if (!sub_00449B30_QueryAddress())
    {
// build: symbol ?MAINMENUS_ConnectToRealm@* 0x00432480
        int nResult = MAINMENUS_ConnectToRealm(szName, 0);
        if (nResult >= 1 && nResult <= 2)
        {
            D2MCPClientCloseMCP();
            return 0;
        }
    }
    MAINMENUS_ShowConnectingPopup();
    WINMAIN_SendMcpCharUpgrade(pEntry->szName);
    sub_004FA590_RunLoop(MAINMENUS_PollCharUpgrade);
// build: symbol ?GAME_GetConnectError@* 0x00449C00
    return GAME_GetConnectError() == 0;
}

// 0x00435E00
int __stdcall CHARSEL_Back(int nArg)
{
    sub_00435580();
    return 1;
}

// 0x004379C0
// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

// 0x004379D0
int __fastcall CHARSEL_IsExpansionFlag(int nValue)
{
    return nValue & 0x20;
}

// 0x004379E0
unsigned int __fastcall CHARSEL_GetProgression(unsigned int nValue)
{
    return (nValue >> 8) & 0x1F;
}

// 0x004379F0
void __cdecl CHARSEL_RefreshRealmList()
{
    sub_00434060();
}

// 0x00437A60
int __cdecl CHARSEL_FreeSlots()
{
    return MAINMENUS_FreeSlots();
}

// 0x00437A70
void* __fastcall CHARSEL_CacheFind(const char* szKey)
{
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    const int nTick = GetTickCount();
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash && nTick <= (int)pEntry->dwExpireTick)
            return pEntry->pData;
    }
    return 0;
}

// 0x00437AB0
void __fastcall CHARSEL_CacheStore(const char* szKey, const void* pData, unsigned int nSize)
{
    const unsigned int dwHash = SStrHash(szKey, 0, 0);
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash)
        {
            SMemFree(pEntry->pData, ".\\Src\\CharSel.cpp", 0xF1, 0);
            pEntry->pData = SMemAlloc(nSize, ".\\Src\\CharSel.cpp", 0xF2, 0);
            memcpy(pEntry->pData, pData, nSize);
            pEntry->dwExpireTick = GetTickCount() + 300000;
            return;
        }
    }
    D2CharSelCacheStrc* pEntry = (D2CharSelCacheStrc*)SMemAlloc(sizeof(D2CharSelCacheStrc), ".\\Src\\CharSel.cpp", 0xFA, 0);
    pEntry->dwHash = dwHash;
    pEntry->pData = SMemAlloc(nSize, ".\\Src\\CharSel.cpp", 0xFC, 0);
    memcpy(pEntry->pData, pData, nSize);
    pEntry->dwExpireTick = GetTickCount() + 300000;
    pEntry->pNext = gpCharSelCache;
    gpCharSelCache = pEntry;
}

// 0x00437BF0
void __cdecl CHARSEL_CreateCharInfoControls()
{
    gpControl_007799EC = MAINMENUS_CreateFromTemplate(0x6D);
    D2Win_10033(gpControl_007799EC, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_007799EC, 1);
    gpControl_00779C7C = MAINMENUS_CreateFromTemplate(0x6E);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C7C, 1);
    gpControl_00779D9C = MAINMENUS_CreateFromTemplate(0x6F);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D9C, 1);
// build: symbol ?gpNameControl@* 0x007799E8
    gpNameControl = MAINMENUS_CreateFromTemplate(0x70);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpNameControl, 1);
    gpControl_00779D88 = MAINMENUS_CreateFromTemplate(0x71);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779D88, 1);
    gpControl_00779C74 = MAINMENUS_CreateFromTemplate(0x72);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpControl_00779C74, 1);
}

// 0x00437C90
void __cdecl CHARSEL_ScrollNameControl()
{
    if (gbFlag_00779C6C)
// build: symbol ?gpNameControl@* 0x007799E8
        D2Win_10188(gpNameControl, -1, 4);
}

// 0x00437F30
void __fastcall CHARSEL_CopyBaseName(const char* szName)
{
    char* pDest = gszBaseName_00779B68;
    while (*szName && *szName != '.')
        *pDest++ = *szName++;
    *pDest = 0;
}

// 0x00437F60
static Unicode* CHARSEL_GetClassName(Unicode* pBuffer, int nClass)
{
    switch (nClass)
    {
    case 0:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAB));
    case 1:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFAA));
    case 2:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA9));
    case 3:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA8));
    case 4:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0xFA7));
    case 5:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2771));
    case 6:
        return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x2772));
    }

    return sub_005267E0(pBuffer, D2LANG_GetStringFromTblIndex(0x1507));
}

// 0x00438030
static int sub_00438030_IsNotListedCode(int nValue)
{
    switch (nValue)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    }

    return 1;
}

// 0x00438060
void __cdecl CHARSEL_FreeCharEntry()
{
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->nState)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
}

// 0x004380B0
static unsigned int CHARSEL_GetDaysLeft(unsigned int nExpireTime)
{
    long nNow;
    const unsigned int nTime = _time32(&nNow);
    if (nExpireTime <= nTime)
    {
        return 0;
    }

    return (nExpireTime - nTime) / 86400;
}

// 0x00438EA0
void __cdecl CHARSEL_FreeCharList()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList;
    while (pEntry)
    {
        D2LaunchCharEntryStrc* pNext = pEntry->pNext;
        sub_005041B0_Destroy(pEntry->pCellFile, 1);
        sub_0040B3C0(pEntry, ".\\Src\\CharSel.cpp", 0x518, 0);
        pEntry = pNext;
    }
    gpCharList = 0;
    gnCharEntryCount = 0;
    gnTopRow = 0;
    gbFlag_00779DD8 = 0;
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->nState)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
}

// 0x00438F40
int __fastcall CHARSEL_IsValidCharName(const char* szName)
{
    const int nLen = strlen(szName);
    if (nLen < 2 || nLen > 15 || szName[nLen - 1] == '-' || szName[0] == '_')
        return 0;
    return 1;
}

// 0x004390A0
int __cdecl CHARSEL_UpdateSelection()
{
    D2LaunchCharEntryStrc* pEntry = gpCharList;
    int n = 0;
    if (!gnCharEntryCount)
// build: symbol ?gnSelected@* 0x0070CC00
        gnSelected = 0;
    int nRow = gnSelected - gnTopRow;
    int bShow;
// build: symbol ?gnVisibleRows@* 0x0070CC0C
    if (nRow >= 0 && nRow < gnVisibleRows)
    {
        sub_004FD0B0_SetColor(gpControl_00779D94, (nRow % 2) ? 0x135 : 0x25, ganRowValues_007799FC[nRow]);
        bShow = 1;
    }
    else
    {
        bShow = 0;
    }
    sub_004F9740_ControlSetState(gpControl_00779D94, bShow);
    for (; pEntry && gnSelected != n; n++)
        pEntry = pEntry->pNext;
    CONTROL_SetEnabled(gpControl_007799F4, 1);
    CONTROL_SetEnabled(gpControl_00779C68, 1);
    if (!pEntry)
    {
        CONTROL_SetEnabled(gpControl_00779C80, 0);
        CONTROL_SetEnabled(gpControl_007799F4, 0);
        CONTROL_SetEnabled(gpControl_00779C68, 0);
        sub_004F9740_ControlSetState(gpControl_00779D94, 0);
        return 1;
    }
    CONTROL_SetEnabled(gpControl_00779C80, 1);
    if (pEntry->nFlags & 0x20)
        CONTROL_SetEnabled(gpControl_00779C80, 0);
    CONTROL_SetEnabled(gpControl_00779D90, gdwGlobal_00779DB8 == 0);
// build: symbol ?gnLaunchMode@* 0x007795EC
    if (gnLaunchMode == 1 && gbFlag_00779DD8)
        CONTROL_SetEnabled(gpControl_00779D90, 0);
    sub_004FB6A0_ClearText(gpCharNameText);
    sub_004FCFF0_SetTextA(gpCharNameText, pEntry->szName, 0);
    return 1;
}

// 0x00439780
void __fastcall CHARSEL_PickClass(int nClass, int bExpansion)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xAC);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xAB);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2723), 7, 0, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xA8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xA9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xAA);
    CONTROL_SetEnabled(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    if ((!bExpansion && nClass >= 8) || nClass >= 10)
        CONTROL_SetEnabled(pControl, 1);
    MAINMENUS_CreateFromTemplate(0xAD);
}

// 0x00439B80
int __stdcall CHARSEL_OnNormalDifficulty(SMSGHANDLER_PARAMS* pMsg)
{
    CHARSEL_JoinSelectedWithDifficulty(pMsg, 0);
    return 1;
}

// 0x00439BA0
int __stdcall CHARSEL_OnNightmareDifficulty(SMSGHANDLER_PARAMS* pMsg)
{
    CHARSEL_JoinSelectedWithDifficulty(pMsg, 1);
    return 1;
}

// 0x00439BC0
int __stdcall CHARSEL_OnHellDifficulty(SMSGHANDLER_PARAMS* pMsg)
{
    CHARSEL_JoinSelectedWithDifficulty(pMsg, 2);
    return 1;
}

void __fastcall sub_A15_Emit_00437F60(const unsigned char* pClass)
{
    Unicode wszText[0x40];
    CHARSEL_GetClassName(wszText, *pClass);
    sub_A15_UseText(wszText);
}

int __fastcall sub_A15_Emit_00438030(const unsigned char* pClass)
{
    return sub_00438030_IsNotListedCode(*pClass);
}

unsigned int __fastcall sub_A15_Emit_004380B0(const unsigned int* pExpire)
{
    return CHARSEL_GetDaysLeft(*pExpire);
}

// 0x00439BE0
int __stdcall CHARSEL_CreateExpansionControls(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        MAINMENUS_DestroyControls();
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDA);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xDB);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
        D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xDC);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
        pControl = MAINMENUS_CreateFromTemplate(0xDD);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CE), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58CF), 0, 0, 0);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x58D0), 0, 0, 0);
    }
    return 1;
}

// 0x00439CA0
int __stdcall CHARSEL_DestroyIfExpansion(SMSGHANDLER_PARAMS* pMsg)
{
    if (FOG_IsExpansion())
        MAINMENUS_DestroyControls();
    return 1;
}

// 0x00439CC0
void __cdecl sub_00439CC0_CreateControls()
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xD6);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xD7);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xD8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x142B), 0, 0, 0);
}

// 0x00439D40
int __stdcall CHARSEL_OnClosePopup(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_DestroyControls();
    return 1;
}

// 0x00439D50
int __stdcall sub_00439D50_CreateControls(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00439CC0_CreateControls();
    return 1;
}

// 0x00439D60
int __stdcall CHARSEL_ScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow > 0)
        gnTopRow -= 1;
    if (gnSelected > 0)
        gnSelected -= 1;
    sub_00438560_Refresh();
// build: symbol ?CHARSEL_Redraw@* 0x00439210
    CHARSEL_Redraw();
    return 1;
}

// 0x00439DA0
int __stdcall CHARSEL_ScrollDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnTopRow + gnVisibleRows < gnCharEntryCount)
    {
        if (gnSelected < gnCharEntryCount - 1)
            gnSelected += 1;
        gnTopRow += 1;
        sub_00438560_Refresh();
        CHARSEL_Redraw();
    }
    return 1;
}

// 0x00439DF0
int __stdcall CHARSEL_OnScroll(SMSGHANDLER_PARAMS* pMsg)
{
    const int nValue = sub_004FC620_GetValue(gpControl_00779C84);
    if (gnLastValue == nValue)
        return 0;
    gnTopRow += 2 * (nValue - gnLastValue);
    if (gnTopRow < 0)
        gnTopRow = 0;
    if (gnTopRow >= gnCharEntryCount)
        gnTopRow = gnCharEntryCount - 1;
    gnLastValue = nValue;
    sub_00438560_Refresh();
    CHARSEL_Redraw();
    return 1;
}

// 0x00439E60
void __stdcall CHARSEL_AddToScrollValue(int nDelta)
{
    sub_004FC660_SetValue(gpControl_00779C84, sub_004FC620_GetValue(gpControl_00779C84) + nDelta);
}

// 0x00439E90
int __stdcall CHARSEL_HandleListKey(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->uMessage != 0x102)
    {
    switch (pMsg->wParam)
    {
    case 0x28:
        if (gnSelected < gnCharEntryCount - 1)
        {
            gnSelected += 2;
            if (gnSelected > gnCharEntryCount - 1)
            {
                gnSelected -= 2;
            }
            else if (gnSelected < gnTopRow)
            {
                gnTopRow = gnSelected;
            }
// build: symbol ?gnVisibleRows@* 0x0070CC0C
            else if (gnSelected > gnTopRow + gnVisibleRows - 1)
            {
                if (gnSelected % 2 == 0)
                {
                    gnTopRow = gnSelected - gnVisibleRows + 2;
                }
                else
                {
                    gnTopRow = gnSelected - gnVisibleRows + 1;
                }
                CHARSEL_AddToScrollValue(1);
            }
        }
        break;

    case 0x26:
        if (gnSelected > 0)
        {
            gnSelected -= 2;
            if (gnSelected < 0)
            {
                gnSelected += 2;
            }
            else if (gnSelected < gnTopRow)
            {
                if (gnSelected % 2 != 0)
                {
                    gnTopRow = gnSelected - 1;
                }
                else
                {
                    gnTopRow = gnSelected;
                }
                CHARSEL_AddToScrollValue(-1);
            }
            else if (gnSelected > gnTopRow + gnVisibleRows - 1)
            {
                gnTopRow = gnSelected - gnVisibleRows + 2;
            }
        }
        break;

    case 0x27:
        if (gnSelected < gnCharEntryCount - 1 && gnSelected % 2 == 0)
        {
            gnSelected += 1;
            if (gnSelected < gnTopRow)
            {
                gnTopRow = gnSelected;
            }
            else if (gnSelected > gnTopRow + gnVisibleRows - 1)
            {
                gnTopRow = gnSelected - gnVisibleRows + 1;
            }
        }
        break;

    case 0x25:
        if (gnSelected > 0 && gnSelected % 2 != 0)
        {
            gnSelected -= 1;
            if (gnSelected < gnTopRow)
            {
                gnTopRow = gnSelected;
            }
            else if (gnSelected > gnTopRow + gnVisibleRows - 1)
            {
                gnTopRow = gnSelected - gnVisibleRows + 1;
            }
        }
        break;

    case 0x24:
        gnTopRow = 0;
        gnSelected = 0;
        break;

    case 0x23:
        if (gnCharEntryCount > gnVisibleRows)
        {
            gnTopRow = gnCharEntryCount - gnVisibleRows;
        }
        gnSelected = gnCharEntryCount - 1;
        break;
    }

    sub_00438560_Refresh();
// build: symbol ?CHARSEL_Redraw@* 0x00439210
    CHARSEL_Redraw();
    return 1;
    }

    return 0;
}

// 0x0043A0D0
int __stdcall CHARSEL_OnListKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        return CHARSEL_HandleListKey(pMsg);

    if (pMsg->uMessage != 0x102)
    {
        switch (pMsg->wParam)
        {
        case 0x28:
            if (gnSelected < gnCharEntryCount - 1)
            {
                gnSelected += 1;
                if (gnSelected < gnTopRow)
                    gnTopRow = gnSelected;
                else if (gnSelected > gnTopRow + gnVisibleRows - 1)
                    gnTopRow = gnSelected - gnVisibleRows + 1;
            }
            break;

        case 0x26:
            if (gnSelected > 0)
            {
                gnSelected -= 1;
                if (gnSelected < gnTopRow)
                    gnTopRow = gnSelected;
                else if (gnSelected > gnTopRow + gnVisibleRows - 1)
                    gnTopRow = gnSelected - gnVisibleRows + 1;
            }
            break;

        case 0x24:
            gnTopRow = 0;
            gnSelected = 0;
            break;

        case 0x23:
            if (gnCharEntryCount > gnVisibleRows)
                gnTopRow = gnCharEntryCount - gnVisibleRows;
            gnSelected = gnCharEntryCount - 1;
            break;
        }

        sub_00438560_Refresh();
        CHARSEL_Redraw();
        return 1;
    }

    return 0;
}

// 0x0043A1F0
static void CHARSEL_ShowConnectError(int nError)
{
    int nStringId;
    switch (nError)
    {
    case 0x7E:
        nStringId = 0x2B99;
        break;
    case 0x7F:
        nStringId = 0x2B9A;
        break;
    default:
        nStringId = 0x2B3A;
        break;
    }

    gdwGlobal_00779DB8 = 1;
    gnBusy = 0;
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(nStringId), 4, 0, 0);
    CONTROL_SetEnabled(gpControl_00779D90, 0);
    if (gbFlag_00779C6C)
        D2Win_10188(gpNameControl, -1, 4);
}

// 0x0043A270
void __cdecl CHARSEL_UpdateStatus()
{
    sub_004FB6A0_ClearText(gpControl_00779DD0);
    if (GetTickCount() - gdwStartTick > 1000)
        sub_004FC9B0_SetText(gpControl_00779DD0, D2LANG_GetStringFromTblIndex(0x2B39), 4, 0, 0);
}

// 0x0043A460
extern "C" int __stdcall CHARSEL_CreateNotice(const Unicode* pTitle, const Unicode* pText, int nState, unsigned char nSel)
{
    D2LaunchCharEntryStrc* pEntry = (D2LaunchCharEntryStrc*)FOG_Alloc(sizeof(D2LaunchCharEntryStrc), ".\\Src\\CharSel.cpp", 0xBAF, 0);
    sub_005263E0(pEntry->szName, pTitle, 0x100);
    sub_005267E0(pEntry->wszName, pText);
    memset(pEntry->aFlags, 0, sizeof(pEntry->aFlags));
    memset(pEntry->aColors, 0, sizeof(pEntry->aColors));
    pEntry->nType = nSel;
    pEntry->nWord322 = 0;
    pEntry->nWord324 = 0;
    pEntry->nWord326 = 0;
    pEntry->nWord328 = 0;
    pEntry->nByte32E = 0;
    pEntry->nByte32F = 0;
    pEntry->nByte330 = 0;
    pEntry->pCompositeUnit = 0;
    pEntry->pNext = 0;
    for (int i = 0; i < 16; ++i)
    {
        pEntry->aFlags[i] = 0;
        pEntry->aColors[i] = 0xFF;
    }
    pEntry->aFlags[1] = 1;
    pEntry->pCompositeUnit = sub_005066C0_CreateComposite(pEntry->nType, 5, pEntry->aFlags, pEntry->aColors);
    pEntry->nState = nState;
    D2Win_10149(pEntry->pCompositeUnit, 0);
    D2Win_10151(pEntry->pCompositeUnit, 0);
    D2Win_10143(pEntry->pCompositeUnit, 5);
    if (!gpCharList)
    {
        gpCharList = pEntry;
    }
    else
    {
        D2LaunchCharEntryStrc* pLast = gpCharList;
        D2LaunchCharEntryStrc** ppNext = &gpCharList->pNext;
        while (pLast->pNext)
        {
            pLast = *ppNext;
            ppNext = &pLast->pNext;
        }
        pLast->pNext = pEntry;
    }
    ++gnCharEntryCount;
    sub_00438560_Refresh();
    return 1;
}

// 0x0043A5D0
void __cdecl CHARSEL_ShowMessage()
{
    const Unicode* pTitle = D2LANG_GetStringFromTblIndex(0x1419);
    const Unicode* pText;
    if (gnLaunchMode == 1)
        pText = D2LANG_GetStringFromTblIndex(0x141B);
    else
        pText = D2LANG_GetStringFromTblIndex(0x141A);
    gnSelectionA = gnCharEntryCount;
    CHARSEL_CreateNotice(pTitle, pText, 1, 0xC);
}

// 0x0043A610
void __cdecl sub_0043A610_ShowString()
{
    const Unicode* pTitle = D2LANG_GetStringFromTblIndex(0x2B3B);
    Unicode wEmpty;
    wEmpty.wChar = 0;
    gdwGlobal_0070CC08 = gnCharEntryCount;
    CHARSEL_CreateNotice(pTitle, &wEmpty, 2, 0x12);
}

// 0x0043A650
void __cdecl CHARSEL_RefreshCharEntry()
{
    if (gpCharEntry_00779DC0)
    {
        if (!gpCharEntry_00779DC0->nState)
            sub_005041B0_Destroy(gpCharEntry_00779DC0->pCellFile, 1);
        sub_0040B3C0(gpCharEntry_00779DC0, ".\\Src\\CharSel.cpp", 0x2A1, 0);
        gpCharEntry_00779DC0 = 0;
    }
    sub_004FB6A0_ClearText(gpCharNameText);
    sub_004FB6A0_ClearText(gpCharDescriptionText);
    sub_004FB6A0_ClearText(gpControl_00779C70);
    CONTROL_SetEnabled(gpControl_007799F4, 0);
    CONTROL_SetEnabled(gpControl_00779C68, 0);
    CONTROL_SetEnabled(gpControl_007799F8, 0);
    CONTROL_SetEnabled(gpScrollUpButton, 0);
    CONTROL_SetEnabled(gpScrollDownButton, 0);
    sub_004F9740_ControlSetState(gpControl_00779D94, 0);
    if (FOG_IsExpansion())
    {
        CONTROL_SetEnabled(gpControl_00779C80, 0);
        CONTROL_SetEnabled(gpControl_00779D90, 0);
    }
    else
    {
        sub_004F9740_ControlSetState(gpControl_00779C78, 0);
    }
}

// build: symbol ?CHARSEL_SelectNamedSlot@* 0x00437CB0
static void CHARSEL_SelectNamedSlot(const char* szName)
{
    if (!gbFlag_00779C6C)
        return;

    int i = 0;
next:
// build: symbol ?GAME_GetSlotNameCount@* 0x00430B40
    if (i >= GAME_GetSlotNameCount())
        return;
    char* szSlot = CHARSEL_GetSlotName(i);
    if (!szSlot)
        return;
    if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
        D2Win_10188(gpNameControl, i, 1);
    ++i;
    goto next;
}

// 0x0043A950
int __stdcall CHARSEL_OnRealmChosen(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?gszPreferredRealm@* 0x00779A40
    SStrCopy(gszPreferredRealm, gszEnteredName, 0x7FFFFFFF);
    SRegSaveString("Diablo II", "Preferred Realm", 0, gszPreferredRealm);
    if (gnLaunchMode == 1)
    {
        MAINMENUS_DestroyControls();
        CHARSEL_UpdateButtons();
    }
    gbFlag_00779C6C = 0;
    return 1;
}

// 0x0043A9D0
int __stdcall CHARSEL_OnListClick(D2ListMsgStrc* pMsg)
{
    if (!gbFlag_00779C6C)
    {
        const int nPrevious = gnSelected;
        void* hWnd = pMsg->hWnd;
        int nRow;
        for (nRow = 0; nRow < gnVisibleRows; nRow += 1)
        {
            if (FOG_IsExpansion() && hWnd == gapRowControlsX[nRow])
                break;
            if (hWnd == gapRowControls[nRow])
                break;
        }
        const int nIndex = gnTopRow + nRow;
        if (gnCharEntryCount < nIndex)
            return 0;
        gnSelected = nIndex;
        if (gnCharEntryCount <= 0)
            gnSelected = -1;
        if (pMsg->uMessage == 0x201)
        {
            const unsigned long dwTick = GetTickCount();
            if (gnSelected != -1 && gnSelected == nPrevious && dwTick - gdwLastClick < 500)
                return COMCALLBACK_OnCharSelectOk(pMsg);
            gdwLastClick = dwTick;
        }
        return CHARSEL_Redraw();
    }
    return 1;
}

// 0x0043AC00
int __stdcall CHARSEL_PollConnect(int nUnused)
{
    switch (gnBusy)
    {
    case 1:
        if (gbFlag_00779C6C)
            D2Win_10188(gpNameControl, -1, 4);
        CHARSEL_SelectNamedSlot(gpszName);
        MAINMENUS_ConnectToRealm(gpszName, 1);
        gnBusy = 2;
        gdwStartTick = GetTickCount();
        break;

    case 2:
        CHARSEL_UpdateStatus();
        switch (sub_00432400_GetStatus())
        {
        case 0:
// build: symbol ?MCPCONNECT_SetPacket@* 0x00449E70
            MCPCONNECT_SetPacket(0, 0);
            gnBusy = 3;
// build: symbol ?VIEW_SendMcpCharListRequest@* 0x0044AAB0
            if (!VIEW_SendMcpCharListRequest())
                CHARSEL_ShowConnectError(GAME_GetConnectError());
            break;
        case 2:
            CHARSEL_ShowConnectError(GAME_GetConnectError());
            break;
        }
        break;

    case 3:
    {
        CHARSEL_UpdateStatus();
        sub_00449B70_Receive();
        int pPacket = sub_00449E60();
        if (pPacket)
        {
            gnBusy = 0;
            if (gbFlag_00779C6C)
                D2Win_10188(gpNameControl, -1, 4);
// build: symbol ?CHARSEL_HandleCharList@* 0x0043AAB0
            CHARSEL_HandleCharList(gpszName, pPacket, 1);
        }
        break;
    }
    }

    return 1;
}

// 0x0043AE30
void __cdecl CHARSEL_InitCharList()
{
// build: symbol ?MAINMENUS_Reset@* 0x0042F480
    MAINMENUS_Reset();
// build: symbol ?gapszSkyPalette@* 0x006D3A08
    MAINMENUS_ReadPaletteFiles(gapszSkyPalette[0], gapszSkyPalette[1]);
    gdwGlobal_00779DA4 = 1;
    gnCharEntryCount = 0;
    gnTopRow = 0;
    gnSelected = 0;
    gbFlag_00779C6C = 0;
    gpCharSelectText = 0;
    gpControl_00779DD0 = 0;
    gnLastValue = 0;
// build: symbol ?gpLaunchRecord@* 0x007795D4
    gpLaunchRecord->nByte210 = 0;
    MAINMENUS_CreateControl(0xA1);
    gpControl_00779C68 = MAINMENUS_CreateControl(0xA2);
    gpControl_007799F8 = MAINMENUS_CreateControl(0xA3);
    gpControl_00779D90 = MAINMENUS_CreateControl(0xA4);
    gpControl_00779C80 = MAINMENUS_CreateControl(0xA5);
    gpControl_007799F4 = MAINMENUS_CreateControl(0xA6);
// build: symbol ?gpCharNameText@* 0x00779B60
    gpCharNameText = MAINMENUS_CreateControl(0x9C);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_00779D90, 0x5524);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_00779C80, 0x58CA);
    BUTTON_SetStringId((D2WinButtonStrc*)gpControl_007799F4, 0x5524);
    gpControl_00779C84 = MAINMENUS_CreateControl(0xA7);
    D2Win_10194((D2WinTextBoxStrc*)gpControl_00779C84, 0);
    D2Win_10195((D2WinTextBoxStrc*)gpControl_00779C84, (void(__stdcall*)(SMSGHANDLER_PARAMS*))CHARSEL_OnScroll);
    memset(gapRowControls, 0, 8 * sizeof(void*));
    gnVisibleRows = 8;
    for (int i = 0; i < gnVisibleRows; ++i)
    {
        if (FOG_IsExpansion())
        {
            gapRowControlsX[i] = MAINMENUS_CreateControl(i + 0x8C);
// build: symbol ?gszSpace@* 0x006FFC44
            D2Win_10045((D2WinControlStrc*)gapRowControlsX[i], gszSpace);
        }
        sub_004FB590(1);
        gapRowControls[i] = MAINMENUS_CreateControl(i + 0x84);
        sub_004FB590(0);
        ganRowValues_007799FC[i] = i / 2 * 0x5D + 0xB2;
    }
    gpControl_00779D94 = MAINMENUS_CreateControl(0x96);
    if (CHARSEL_InitRealmScreen())
    {
        CONTROL_SetEnabled(gpControl_007799F8, 0);
        CHARSEL_UseName(gszPreferredRealm);
        const int nExtra = gnCharEntryCount - gnVisibleRows;
        if (nExtra > 0)
            D2Win_10191((D2WinTextBoxStrc*)gpControl_00779C84, nExtra / 2 + (nExtra % 2 != 0));
// build: symbol ?D2SOUND_GetOptionsMusicOption@* 0x00514D80
        if (D2SOUND_GetOptionsMusicOption())
// build: symbol ?D2SOUND_10034@* 0x005148F0
            D2SOUND_10034(1);
        CONTROL_SetEnabled(gpControl_007799F8, 1);
    }
}

// 0x0043B7A0
int __fastcall CHARSEL_InitFuncTable(D2LaunchRecordStrc* pRecord)
{
    if (!pRecord->pFuncTable)
    {
        gpFuncTable_0077ABF0 = sub_00518C00();
        D2_ASSERT(gpFuncTable_0077ABF0, 0x94);
        pRecord->pFuncTable = gpFuncTable_0077ABF0;
        gpFuncTable_0077ABF0->pfnInit(pRecord);
    }
    return 1;
}

// 0x0043B820
void __cdecl CHARSEL_ClearCancelled()
{
    gdwGlobal_0077AC04 = 0;
}

// 0x0043B9A0
void __cdecl CHARSEL_DisconnectBattleNet()
{
    if (gpFuncTable_0077ABF0)
    {
        gdwGlobal_00779DA4 = 1;
        gpLaunchRecord->nByte361 = 0;
        gpLaunchRecord->nByte381 = 0;
        OutputDebugStringA("Disconnect from BNET\n");
        D2MCPClientCloseMCP();
        gpFuncTable_0077ABF0->pfnSlot10();
    }
}

// 0x0043C4F0
void __cdecl CHARSEL_CreateBaseScreen()
{
    MAINMENUS_Reset();
    MAINMENUS_CreateControl(8);
    MAINMENUS_CreateControl(6);
    MAINMENUS_CreateControl(7);
    MAINMENUS_ReadPaletteFiles(gapszSkyPalette[0], gapszSkyPalette[1]);
    MAINMENUS_ConfigureLanguageLayout();
}

// 0x0043C6A0
void __fastcall sub_0043C6A0(int bSet)
{
    if (bSet)
        gdwFlags_0077AC34 |= 2;
}

// 0x0043D990
void __cdecl CHARSEL_ActivateChatEdit()
{
// build: symbol ?gpChatEdit@* 0x0077BD94
    if (gpChatEdit)
        CONTROL_SetFocusedEditBox(gpChatEdit);
}

// 0x0043DB20
void __cdecl CHARSEL_DestroyDialogControls()
{
    sub_004F95C0_ControlDestroy(&gpCreateJoinBckgImage);
    sub_004F95C0_ControlDestroy(&gpChannelScreenTitle);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCE4);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCE8);
    sub_004F95C0_ControlDestroy(&gpChannelOkButton);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCF0);
    sub_004F95C0_ControlDestroy(&gpEdit_0077BCF4);
    sub_004F95C0_ControlDestroy(&gpChannelListBox);
    sub_004FA450_SetActive(gpQuitButton);
    if (gpChatEdit)
        CONTROL_SetFocusedEditBox(gpChatEdit);
}

// 0x0043DC30
int __cdecl CHARSEL_GetConnectStatus()
{
// build: symbol ?gpCharInfo@* 0x0077BBD8
    if (gpCharInfo->nByte22D && !sub_00449B30_QueryAddress())
        return -1;
    return 0;
}

// 0x0043E130
void __cdecl CHARSEL_ResetChatControls()
{
    for (int i = 0; i <= 1; i++)
    {
        if (gapControls_0077B050[i])
        {
            sub_004F95C0_ControlDestroy(&gapControls_0077B050[i]);
            gapControls_0077B050[i] = 0;
        }
    }
    if (gpControl_0077BC40)
    {
        sub_004F95C0_ControlDestroy(&gpControl_0077BC40);
        gpControl_0077BC40 = 0;
    }
}

// 0x0043EA20
void __cdecl CHARSEL_DestroyPopupControls()
{
    for (int i = 0; i < gnControlCount; i++)
        sub_004F95C0_ControlDestroy(&gapControls[i]);
    gnControlCount = 0;
    sub_004FA450_SetActive(gpQuitButton);
    gdwConnectTime = 0;
}

// 0x0043F4D0
void __cdecl CHARSEL_ClearHistory()
{
    for (int i = 0; i < 10; i++)
        gaszHistory[i][0] = 0;
// build: symbol ?gnHistoryIndex@* 0x0070CD74
    gnHistoryIndex = -1;
    gdwGlobal_0077BD50 = 0;
}

// 0x0043F560
void __fastcall CHARSEL_DisableControl(D2WinControlStrc* pControl)
{
    CONTROL_SetCellFile(pControl, gpRadioButtonGreyCelFile);
    CONTROL_SetEnabled(pControl, 0);
}

// 0x0043F850
int __cdecl CHARSEL_CancelGameCreate()
{
    VIEW_SendMcpCancelGameCreate();
    sub_00449E50_SetValue(0);
    return 1;
}

// 0x00445020
void __cdecl CHARSEL_RequestGameList()
{
// build: symbol ?gnChatLaunchMode@* 0x0077BBE4
    gnChatLaunchMode = 3;
    gnValue_00798CCC = 0;
// build: symbol ?gpCharInfo@* 0x0077BBD8
    if (gpCharInfo->nType0x35E == 2)
    {
        D2LaunchRequestStrc tRequest;
        memset(&tRequest, 0, sizeof(tRequest));
        if (gpCharInfo->wFlags[0] & 4)
            tRequest.dwFlags |= 0x800;
        while (++gwRequestId == 0)
        {
        }
        WINMAIN_SendMcpGameListRequest(&tRequest, gwRequestId);
        gwSavedRequestId = gwRequestId;
    }
    else
    {
        sub_00444E70_FillGameList();
    }
}

// 0x00451920
void __stdcall CHARSEL_RecordHandler(int nArg1, int nArg2, int nArg3)
{
    RECORD_WriteRecordFile();
    if (gpfnPrevHandler)
        gpfnPrevHandler(nArg1, nArg2, nArg3);
}

// 0x00453470
void __cdecl CHARSEL_DrawProgressiveStates()
{
    if (!gpGlobal_007A0634)
        return;
    if (!sub_00463DE0_GetPlayerUnit())
        return;
    if (!UNITS_GetRoom(sub_00463DE0_GetPlayerUnit()))
        return;
    if (!gbOverlaysEnabled)
        return;
    int nY = gnScreenHeight - gnGlobal_007111D4;
    int nX = gnScreenWidth - gnGlobal_007111D0;
    if (D2GFX_GetResolutionMode() == 2)
        nY = gnScreenHeight - gnGlobal_007111CC;
    D2UnitStrc* pUnit = sub_00463DE0_GetPlayerUnit();
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        const int nState = sgptDataTables->pProgressiveStates[i];
        if (!STATES_CheckState(pUnit, nState))
            continue;
        if (!STATLIST_GetStatListFromUnitAndState(pUnit, nState))
            continue;
        D2StatesTxt* pStatesTxtRecord = sub_00452040_GetStatesTxtRecord(nState);
        if (!pStatesTxtRecord)
            continue;
        if (!(pStatesTxtRecord->nStateFlags[0] & gdwBitMasks[4]))
            continue;
        if (pStatesTxtRecord->wPrgOverlay <= 0 || pStatesTxtRecord->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount)
            continue;
        if (pStatesTxtRecord->wStat < 0 || pStatesTxtRecord->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
            continue;
        const int nCharges = STATLIST_UnitGetStatValue(pUnit, pStatesTxtRecord->wStat, 0);
        if (nCharges < 1 || nCharges > 3)
            continue;
        GFX_DrawProgressiveStateOverlays(pUnit, pStatesTxtRecord->wPrgOverlay + nCharges - 1, nX, nY);
        nX -= gnOverlayStep;
    }
}

// 0x00458CD0
void __stdcall CHARSEL_SetAutomapContext(void* pContext)
{
    AUTOMAP_SaveAutomapLayer();
    AUTOMAP_ResetAutomapCells();
    gpAutomapContext = pContext;
    AUTOMAP_LoadAutomapLayer();
}

// 0x004756D0
void __cdecl CHARSEL_ScanGridCollision()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
        return;
    for (int nY = 0; nY < 0x30; ++nY)
    {
        for (int nX = 0; nX < 0x30; ++nX)
        {
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, gnCellOriginX + nX, gnCellOriginY + nY);
            if (!pRoom)
                pRoom = UNITS_GetRoom(pPlayer);
            if (COLLISION_CheckMask(pRoom, gnCellOriginX + nX, gnCellOriginY + nY, 0x22))
                gtGridCells_007B0E68[nY * 0x30 + nX].nFlag = 1;
        }
    }
}

// 0x00478160
void __fastcall CHARSEL_ShowProgressSteps(int nDone, int nTotal)
{
    const int nDivisor = nTotal * 8;
    int nPosition = nDone * 8;
    for (int i = 0; i < 8; ++i)
    {
        if (nDivisor == 0)
            gnProgress = 0;
        else
            gnProgress = (nPosition * 0x100) / nDivisor;
        UI_DrawLoadingScreen(0);
        Sleep(250);
        ++nPosition;
    }
}

static unsigned int sub_0051DD10_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

static int sub_0051DD20_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

static int sub_0051DD40_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return sub_0051DD10_NibbleToHex(tolower(n)) + sub_0051DD10_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return sub_0051DD20_HexToNibble((char)tolower(n)) * 16 + sub_0051DD20_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return sub_0051DD40_MapKeyChar((unsigned char)tolower(n)) * 24 + sub_0051DD40_MapKeyChar((unsigned char)tolower(n + 1));
}

#include "gen/data/Source/D2Launch/Src/CharSel.inc"
