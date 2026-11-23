#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2MonsterIds.h"
#include "D2Primitives.h"

#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2ClientTabStrc;

struct D2TextListNodeStrc;

struct D2TextListStrc;

struct D2TextFieldA4Strc;

struct D2TextWidthStrc;

struct D2TextStateStrc;

struct D2TextBoxPosStrc;

struct D2TextPointStrc;

struct D2GSPacketSrv26;

struct D2CommonChatIgnoreListStrc;

struct T00479230;

class D2ListBoxViewStrc;

struct D2ClientTextDataStrc;

struct D2UnitStrc;

struct D2CommonIgnoreListStrc;

struct T0044CB60;

struct SMSGHANDLER_PARAMS;

struct ByteRecord;

struct PacketWords;

struct PacketShorts;

struct Digest;

struct HashState;

struct Member;

struct ClassRecord;

struct ClassTableView;

struct UnitView;

class ListBoxImplementation;

class UIWidget;

class ListBoxWrapper;

struct D2TextListNodeStrc
{
    const Unicode* wszText;
    D2TextListNodeStrc* pNext;
};

struct D2TextListStrc
{
    D2TextListNodeStrc* pFirst;
    unsigned int wCount;
    char unk0x08[0x08];
    unsigned short nWidth;
    unsigned short nHeight;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __stdcall INV_SelectItemPageTab(unsigned char nTab); // 0x00487A10

void __cdecl INV_SetupPanelButtons(); // 0x00487ED0

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

extern int gnScreenHeight; // 0x00711470

extern D2ClientTabStrc gaNpcTabStates[]; // 0x0072211A

extern int gnGlobal_007BCAF0; // 0x007BCAF0

extern int gbNpcTradeClicked; // 0x007BCBEC

extern int gnInvPanelMode; // 0x007BCBF0

extern int gdwNpcPanelDelayTick; // 0x007BCC08

extern int gnSelectedShopButton; // 0x007BCC40

extern int gbInvGoldButtonDown; // 0x007BCE30

extern int gnPetIconPopupState; // 0x007BEECC

struct D2TextFieldA4Strc
{
    char unk0x00[0xA4];
    int nFieldA4;
};

struct D2TextWidthStrc
{
    char unk0x00[0x0C];
    int nWidth;
    char unk0x10[0x04];
    unsigned short wWidth;
};

#pragma pack(push, 2)

struct D2TextStateStrc
{
    char unk0x00[0x16];
    int nState;
};

#pragma pack(pop)

struct D2TextBoxPosStrc
{
    char unk0x00[0x04];
    int nRows;
    char unk0x08[0x08];
    unsigned short wWidth;
};

struct D2TextPointStrc
{
    int nX;
    int nY;
};

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10

void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

extern int gbTextHandlersRegistered; // 0x007BF27C

extern D2MsgHandlerEntryStrc gaTextMsgHandlers[]; // 0x00722600

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest); // 0x006CC29C

extern "C" unsigned int __cdecl strlen(const char* szString);

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

Unicode* __fastcall SCMD_StripColorCodes(Unicode* pText); // 0x00452300

int __fastcall ROSTER_IsNotSquelched(int nUnitId); // 0x0047A170

void __fastcall INV_OpenRecipeScroll(const Unicode* wszName, int nUnused, int nArg); // 0x0048BBE0

void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern "C" Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0

char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit); // 0x00622150

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0

extern int gnGameFrame; // 0x007BF20E

static bool TEXT_IsLanguageCompatible(int nLangId);

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

#pragma pack(push, 2)

struct T00479230
{
    T0044CB60* pFirst;
    int nLines;
    int nTextTop;
    int nTextBottom;
    unsigned short nWidth;
    unsigned short nHeight;
    unsigned short f_14;
    int nScroll;
    int nField1A;
    int nField1E;
    int nField22;
    int nField26;
    unsigned short nField2A;
};

#pragma pack(pop)

class D2ListBoxViewStrc
{
public:
    virtual ~D2ListBoxViewStrc();
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __fastcall sub_00467430(void* pRect); // 0x00467430

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __stdcall TEXT_FreeTextList(void* pList); // 0x0049D4D0

void __cdecl TEXT_FreeTextPanelCels(); // 0x0049FE10

T0044CB60* __stdcall TEXT_BuildTextLines(const Unicode* wszText, int* pLineCount, unsigned short* pMaxLines); // 0x004A0320

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

T00479230* __stdcall CHAT_GetUsedFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661200

void __stdcall CHAT_SetUsedInHoverMsg(D2HoverTextStrc* pHoverMsg, int bUsed); // 0x00661210

void __stdcall sub_006612A0(int nHandle); // 0x006612A0

extern unsigned int gdwTextEndTick; // 0x007BF1AC

D2ClientDialogStrc* gpListDialog; // 0x007BF1B0

void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags); // 0x00413020

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
// build: symbol ?gszNew@* 0x006CC82C
        return SMemAlloc(nSize, gszNew, -1, 0);
    }

    virtual ~UIWidget();
    virtual void Slot01() = 0;
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int Slot11() = 0;

    int unk0x04;
};

class ListBoxWrapper : public UIWidget
{
public:
    ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18, int nArg1C,
        int nArg20);                                                                                        // 0x004BF8F0
    virtual ~ListBoxWrapper();
    virtual void Slot01();
    virtual int MsgSlot02(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot03(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot04(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot06(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot09(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot10(SMSGHANDLER_PARAMS* pMsg);
    virtual int Slot11();
    virtual void sub_004BBFB0();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();

    ListBoxImplementation* pImpl;
};

extern ListBoxWrapper* gpListBox; // 0x007BF1B4

extern int gbTextBoxShown; // 0x007BF1C8

extern char gtMessageTextList[]; // 0x007BF1E4

extern char gtOverheadTextList[]; // 0x007BF1EA

extern char gtTextHistory[]; // 0x007BF1F0

extern unsigned short gwTextStringId; // 0x007BF212

extern int gnHintId; // 0x007BF260

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

extern int gnScreenWidth; // 0x0071146C

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __cdecl TEXT_DrawPanelFrame(); // 0x0049FA10

void __stdcall TEXT_OpenTextPanel(int bFlag); // 0x0049FBA0

extern D2ClientTextDataStrc* gpTextData; // 0x007BF228

extern int gbTextDataOpen; // 0x007BF254

struct ByteRecord
{
    char gap00[0x3E];
    unsigned char value;
    char tail[0x4F];
};

#pragma pack(push, 1)

struct PacketWords
{
    char prefix[1];
    unsigned short kind;
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

struct PacketShorts
{
    char prefix[1];
    unsigned short kind;
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

#pragma pack(pop)

struct Digest
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
};

struct HashState
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int lowCount;
    unsigned int highCount;
    char block[0x40];
};

struct Member
{
    short value;
};

struct ClassRecord
{
    char gap00[2];
    short relation;
    short next;
    char gapToMembers[0x16A];
    Member members[8];
    char tail[0x28];
};

struct ClassTableView
{
    char gap00[0xA78];
    ClassRecord* records;
    char gapAfterRecords[4];
    int count;
};

struct UnitView
{
    unsigned int type;
    int classId;
};

typedef char ByteRecord_value[OFFSET(ByteRecord,value)==0x3E?1:-1];

typedef char PacketWords_kind[OFFSET(PacketWords,kind)==0x1?1:-1];

typedef char PacketWords_a[OFFSET(PacketWords,a)==0x3?1:-1];

typedef char PacketWords_b[OFFSET(PacketWords,b)==0x7?1:-1];

typedef char PacketWords_c[OFFSET(PacketWords,c)==0xB?1:-1];

typedef char PacketShorts_kind[OFFSET(PacketShorts,kind)==0x1?1:-1];

typedef char PacketShorts_a[OFFSET(PacketShorts,a)==0x3?1:-1];

typedef char PacketShorts_b[OFFSET(PacketShorts,b)==0x5?1:-1];

typedef char PacketShorts_c[OFFSET(PacketShorts,c)==0x7?1:-1];

typedef char ClassRecord_relation[OFFSET(ClassRecord,relation)==0x2?1:-1];

typedef char ClassRecord_next[OFFSET(ClassRecord,next)==0x4?1:-1];

typedef char ClassRecord_members[OFFSET(ClassRecord,members)==0x170?1:-1];

typedef char ClassTableView_records[OFFSET(ClassTableView,records)==0xA78?1:-1];

typedef char ClassTableView_count[OFFSET(ClassTableView,count)==0xA80?1:-1];

typedef char UnitView_type[OFFSET(UnitView,type)==0x0?1:-1];

typedef char UnitView_classId[OFFSET(UnitView,classId)==0x4?1:-1];

typedef char Digest_a[OFFSET(Digest,a)==0x0?1:-1];

typedef char Digest_b[OFFSET(Digest,b)==0x4?1:-1];

typedef char Digest_c[OFFSET(Digest,c)==0x8?1:-1];

typedef char Digest_d[OFFSET(Digest,d)==0xC?1:-1];

typedef char Digest_e[OFFSET(Digest,e)==0x10?1:-1];

typedef char HashState_a[OFFSET(HashState,a)==0x0?1:-1];

typedef char HashState_b[OFFSET(HashState,b)==0x4?1:-1];

typedef char HashState_c[OFFSET(HashState,c)==0x8?1:-1];

typedef char HashState_d[OFFSET(HashState,d)==0xC?1:-1];

typedef char HashState_e[OFFSET(HashState,e)==0x10?1:-1];

typedef char HashState_lowCount[OFFSET(HashState,lowCount)==0x14?1:-1];

typedef char HashState_highCount[OFFSET(HashState,highCount)==0x18?1:-1];

typedef char ByteRecord_size[sizeof(ByteRecord)==0x8E?1:-1];

typedef char PacketWords_size[sizeof(PacketWords)==0xF?1:-1];

typedef char PacketShorts_size[sizeof(PacketShorts)==0x9?1:-1];

typedef char Digest_size[sizeof(Digest)==0x14?1:-1];

typedef char HashState_size[sizeof(HashState)==0x5C?1:-1];

typedef char Member_size[sizeof(Member)==0x2?1:-1];

typedef char ClassRecord_size[sizeof(ClassRecord)==0x1A8?1:-1];

// build: symbol _sgptSoundHeaderTable 0x007BC9A0
extern "C" ByteRecord* sgptSoundHeaderTable;

extern "C" int gRecordCount_007BC9A4;

extern "C" unsigned int gValue_007BF254; // 0x007BF254

extern "C" unsigned int gValue_007BF2A4; // 0x007BF2A4

extern "C" unsigned int gValue_007BF2AC; // 0x007BF2AC

extern "C" HashState gStates_00882760[];

extern "C" ClassTableView* gClassTable_00744304;

static bool TEXT_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText); // 0x0049E280

static void __stdcall TEXT_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit); // 0x0049F410

int __cdecl TEXT_CloseMessageLogCallback(); // 0x004A0030

void __fastcall DIALOG_AddWidget(D2ClientDialogStrc* pDialog, void* pWidget, int nArg8, int nArgC); // 0x004B7C00

// build: symbol ?DIALOG_CreateDialog@* 0x004B7EB0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int nArg8, int nArgC, int nArg10, int nArg14,
    int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0

void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0

void __fastcall sub_004B8370_SetField5C(D2ClientDialogStrc* pDialog, int nValue); // 0x004B8370

void __fastcall sub_004B85F0_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nArg8, int nArgC,
    int nArg10, int nArg14, int (__cdecl* pfnCallback)(), int nArg1C); // 0x004B85F0

unsigned char gnSelectedTab; // 0x007BCC04

unsigned char gbOpenMercInvPending; // 0x007BEEE4

struct D2ClientServiceStrc
{
    char unk0x00[0xD0];
    int (__fastcall* pfnCall)(int nArg1, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

struct D2ClientStringListStrc
{
    Unicode* pStrings[6];
    unsigned short nCount;
    unsigned char f_1A[4];
    unsigned char unk0x1E[8];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

unsigned long gnStartTick; // 0x007BF22C

unsigned char gbTextHoverSet; // 0x007BF23A

T00479230* gpTextBox; // 0x007BF0A4

T00479230* gpMainTextBox; // 0x007BF1A8

int gnTextBoxX; // 0x007BF1D0

int gnTextBoxY; // 0x007BF1D4

int gbTextSound; // 0x007BF230

void* gpScroin3Cel; // 0x007BF26C

void* gpScroin2Cel; // 0x007BF270

void* gpTextPanelFrameCel; // 0x007BF274

// 0x00491940
void __cdecl TEXT_ResetNpcPanel()
{
    gbInvGoldButtonDown = 0;
    gnSelectedShopButton = -1;
    gnSelectedTab = 0;
    gnGlobal_007BCAF0 = 0;
// build: symbol ?gnNpcTabCount@* 0x00722158
    for (int i = 0; i < gnNpcTabCount; ++i)
    {
        *(int*)gaNpcTabStates[i].bSelected = 0;
        *(int*)gaNpcTabStates[i].bEnabled = 0;
    }
    gbNpcTradeClicked = 0;
    gnInvPanelMode = 1;
    INV_SetupPanelButtons();

    int nNpcId;
    if (NPCMENU_GetInteractNpcId(&nNpcId))
    {
        D2UnitStrc* pNpc = CUNIT_FindClientUnit(nNpcId, 1);
        int bMatched = 0;
        if (pNpc)
        {
            switch ((unsigned int)pNpc->dwClassId)
            {
            case 0x9A:
            case 0x1FF:
                gnSelectedTab = 1;
                bMatched = 1;
                break;
            case 0x94:
            case 0xB1:
            case 0xB2:
            case 0xCA:
            case 0xFC:
            case 0xFD:
            case 0xFF:
            case 0x101:
            case 0x195:
            case 0x201:
                gnSelectedTab = 3;
                bMatched = 1;
                break;
            case 0x93:
            case 0x200:
                gnSelectedTab = 0;
                bMatched = 1;
                break;
            }
        }
        INV_SelectItemPageTab(gnSelectedTab);
        if (bMatched)
        {
            gdwNpcPanelDelayTick = GetTickCount() + 500;
        }
    }
}

// 0x004939B0
void __cdecl TEXT_LoadPopupHireling()
{
    gnPetIconPopupState = 0;
    UI_SetUIVar(0x23, 0, 0);
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "PopupHireling", 0, &dwValue);
    if (!dwValue)
    {
        gbOpenMercInvPending = 1;
    }
}

int __cdecl sub_0047F210_IsMouseInSlots();                                                                  // 0x0047F210

void __cdecl sub_0049C6C0_SendWaypointClose();                                                              // 0x0049C6C0

extern D2WaypointRowRectStrc gaWaypointRowRects[9];                                                // 0x007224F8

extern D2WaypointMenuEntryStrc gaWaypointEntries[9];                                               // 0x007BF03C

static bool gbWaypointClosePressed;                                                                        // 0x007BF06C

static int gnWaypointSelected;                                                                       // 0x007BF06D

extern char gbSent;                                                                              // 0x007BF085

extern int gnPanelOffsetX;                                                                               // 0x007A2858

extern int gnPanelOffsetY;                                                                               // 0x007A285C

static int sub_0049C510_GetWaypointRowAtPoint(int nX, int nY)
{
    for (int i = 0; i < 9; ++i)
    {
        if (gaWaypointEntries[i].bEnabled && nX > gaWaypointRowRects[i].nX && nX < gaWaypointRowRects[i].nX + 0x118
            && nY > gaWaypointRowRects[i].nY && nY < gaWaypointRowRects[i].nY + 0x1E)
            return i;
    }
    return -1;
}

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

// 0x0049D010
void __stdcall sub_0049D010_WaypointMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX <= gnScreenWidth && nY <= gnScreenHeight - 0x31)
    {
        nX -= gnPanelOffsetX;
        nY += gnPanelOffsetY;
        if (gbWaypointClosePressed)
        {
            if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
            {
                UI_SetUIVar(0x14, 1, 0);
                sub_0049C6C0_SendWaypointClose();
            }
        }
        else if (gnWaypointSelected != -1 && gnWaypointSelected == sub_0049C510_GetWaypointRowAtPoint(nX, nY))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            MSG_SendTwoDwords(0x49, gnWaypointId, *(int*)gaWaypointEntries[gnWaypointSelected].nLevelId);
            gbSent = 1;
            sub_0049C6C0_SendWaypointClose();
            gbWaypointClosePressed = false;
            gnWaypointSelected = -1;
            UI_SetUIVar(0x14, 1, 0);
            sub_004B9A00(0x8B7, 0, 0, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        gbWaypointClosePressed = false;
        gnWaypointSelected = -1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        gbWaypointClosePressed = false;
        gnWaypointSelected = -1;
    }
}

// 0x0049D2E0
int __fastcall TEXT_IsAsciiChar(const unsigned short* pChar)
{
    return *pChar < 0x80;
}

// 0x0049D2F0
void __fastcall sub_0049D2F0_SetFieldA4(D2TextFieldA4Strc* pRecord, int nValue)
{
    if (pRecord)
        pRecord->nFieldA4 = nValue;
}

// 0x0049D300
int __fastcall sub_0049D300_GetFieldA4(D2TextFieldA4Strc* pRecord)
{
    if (!pRecord)
        return 0;
    return pRecord->nFieldA4;
}

// 0x0049D3B0
static inline void TEXT_SetWidthFromWord(D2TextWidthStrc* pRecord)
{
    pRecord->nWidth = pRecord->wWidth;
}

void __fastcall sub_M111_Emit_0049D3B0(D2TextWidthStrc* pRecord, int* pDone)
{
    TEXT_SetWidthFromWord(pRecord);
    *pDone = 1;
}

// 0x0049D570
void __fastcall TEXT_SaveTextDisplaySetting(unsigned long nValue)
{
// build: symbol ?gnTextDisplaySetting@* 0x007BF1F6
    gnTextDisplaySetting = nValue;
    SRegSaveValue("Diablo II", "Text Display Beta", 0, nValue);
}

// 0x0049D590
unsigned int __fastcall TEXT_CalcTextOffset(unsigned int nValue)
{
    return 0x70 - (nValue >> 10);
}

// 0x0049D8E0
void __fastcall TEXT_DrawTextList(D2TextListStrc* pList, int nX, int nY)
{
    int nLines = pList->wCount > 10 ? 10 : pList->wCount;

    D2TextListNodeStrc* pNode = pList->pFirst;
    if (!nLines || !pNode || nY < 0)
    {
        return;
    }

    const int nHeight = pList->nHeight;
    if (nHeight + nY >= gnScreenHeight)
    {
        return;
    }

    AUTOMAP_DrawFramedBox(nX, nY + 4, pList->nWidth, nHeight - 5, 0, 1);
    int i = 0;
    const int nOldFont = D2Win_10127_SetFont(13);
    for (; i < nLines && pNode; ++i)
    {
        D2Win_10117_DrawText(pNode->wszText, nX + 10, nY + 18 + 15 * (i - nLines + pList->wCount), 0, 0);
        pNode = pNode->pNext;
    }
    D2Win_10127_SetFont(nOldFont);
}

// 0x0049DA30
void __fastcall TEXT_SetHoverUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
// build: symbol ?gnTextHoverUnitId@* 0x007BF23B
        gnTextHoverUnitId = pUnit->dwUnitId;
        gbTextHoverSet = 1;
    }
    else
    {
        gbTextHoverSet = 0;
    }
}

// 0x0049DA60
void __fastcall TEXT_ToggleTextHandlers(int nMode)
{
    if (nMode == 0)
    {
        if (gbTextHandlersRegistered == 1)
        {
            gbTextHandlersRegistered = 0;
            AUTOMAP_UnregisterHandlerTable((void*)WINDOW_GetWindow(), gaTextMsgHandlers, 7);
        }
    }
    else if (nMode == 1 && gbTextHandlersRegistered == 0)
    {
        gbTextHandlersRegistered = 1;
        gnStartTick = GetTickCount();
        COMCALLBACK_RegisterMsgHandlers(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
    }
}

// 0x0049DAC0
int __fastcall sub_0049DAC0_IsStateZeroOrOne(D2TextStateStrc* pRecord)
{
    if (!pRecord)
        return 0;
    int nState = pRecord->nState;
    if (nState == 1 || nState == 0)
        return 1;
    return 0;
}

// 0x0049DAE0
void __fastcall TEXT_AdjustTextPos(D2TextBoxPosStrc* pBox, D2TextPointStrc* pPoint)
{
    pPoint->nX -= pBox->wWidth / 2;
    pPoint->nY -= 50;
    pPoint->nY -= pBox->nRows * 15 + 3;
}

// 0x0049DB10
D2ClientStringListStrc* __fastcall TEXT_CloneStringList(D2ClientStringListStrc* pSource)
{
    D2ClientStringListStrc* pCopy = (D2ClientStringListStrc*)FOG_Alloc(0x26, ".\\UI\\text.cpp", 0x9D0, 0);
    memset(pCopy, 0, 0x26);
    for (int i = 0; i < pSource->nCount; ++i)
    {
        pCopy->pStrings[i] = (Unicode*)FOG_Alloc((sub_00526800(pSource->pStrings[i]) + 1) * sizeof(Unicode), ".\\UI\\text.cpp", 0x9D4, 0);
        sub_005267E0(pCopy->pStrings[i], pSource->pStrings[i]);
    }
    pCopy->nCount = pSource->nCount;
    *(int*)pCopy->f_1A = *(int*)pSource->f_1A;
    return pCopy;
}

// 0x0049E250
static bool TEXT_IsLanguageCompatible(int nLangId)
{
    const int nCurrentLangId = STRTABLE_GetLanguage();
    if (!(nCurrentLangId == nLangId))
    {
        if (nCurrentLangId == 7)
        {
            if (nLangId == 0xC)
                return true;
        }
        else if (nCurrentLangId == 0xC)
        {
            if (nLangId == 7)
                return true;
        }
        return false;
    }
    return true;
}

// build: context TEXT_HandleChatPacket
void __fastcall TEXT_HandleChatPacket(D2GSPacketSrv26* pPacket)
{
    if (pPacket->nUnitType == 0 && !ROSTER_IsNotSquelched(pPacket->dwUnitGUID))
        return;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitGUID, pPacket->nUnitType);
    char szName[0x11] = { 0 };
    if ((pUnit && pUnit->dwUnitType == UNIT_PLAYER) || pPacket->szName[0])
    {
        if (pUnit)
            SStrCopy(szName, UNITS_GetPlayerName(pUnit), 0x11);
        else
            SStrCopy(szName, pPacket->szName, 0x11);

        if (IGNORELIST_GetOrCreateIgnoreList()->IGNORELIST_IsListed(szName))
            return;
        if (IGNORELIST_GetOrCreateIgnoreList()->sub_0060FC40_IsTextFiltered(pPacket->szMessage))
            return;
    }

    Unicode wszText[0x100];
    if (!TEXT_ConvertHoverText(pPacket->nLang, wszText, pPacket->szMessage))
        return;
    wszText[0xFF].wChar = 0;

    if (pPacket->nMessageType == 4)
    {
        TEXT_PrintChatLine(wszText, pPacket->nMessageColor);
        return;
    }

    Unicode wszA[0x264];
    Unicode wszB[0x264];
    Unicode wszC[0x10];
    if (pPacket->nMessageType == 6)
    {
        Unicode::win2Unicode(wszB, pPacket->szMessage, 0x100);
        Unicode::win2Unicode(wszC, pPacket->szName, 0x10);
        sub_005269D0(0x264, wszA, D2LANG_GetStringFromTblIndex(0xE4A), wszC, wszB);
        SCMD_StripColorCodes(wszA);
        TEXT_PrintChatLine(wszA, 2);
    }
    else if (pPacket->nMessageType == 2)
    {
        const int nNameLen = strlen(pPacket->szName);
        const int nTextLen = strlen(pPacket->szMessage);
        if (nNameLen >= 1 && nNameLen <= 15)
        {
            Unicode::win2Unicode(wszC, pPacket->szName, 0x10);
            sub_005267E0(wszA, wszC);
            Unicode::strcat(wszA, D2LANG_GetStringFromTblIndex(0xE46));
            sub_005267E0(wszB, wszText);
            Unicode::strcat(wszA, wszB);
            TEXT_PrintChatLine(wszA, 2);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        TEXT_PrintChatLine(wszA, 2);
    }
    else if (pPacket->nMessageType == 1)
    {
        if (pPacket->nUnitType == 0 || pPacket->nUnitType == 1)
        {
            TEXT_PrintChatLine(wszText, pPacket->nMessageColor);
            return;
        }
        const int nNameLen = strlen(pPacket->szName);
        const int nTextLen = strlen(pPacket->szMessage);
        if (nNameLen >= 1 && nNameLen <= 15)
        {
            Unicode wszD[0x10];
            Unicode::win2Unicode(wszD, pPacket->szName, 0x10);
            sub_005267E0(wszA, wszD);
            INV_PrefixColorCode(wszA, 4);
            sub_005267E0(wszB, D2LANG_GetStringFromTblIndex(0xFD0));
            Unicode::strcat(wszB, wszText);
            INV_PrefixColorCode(wszB, 0);
            Unicode::strcat(wszA, wszB);
            TEXT_PrintChatLine(wszA, pPacket->nMessageColor);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        TEXT_PrintChatLine(wszA, pPacket->nMessageColor);
    }
    else if (pPacket->nMessageType == 5)
    {
        if (pUnit)
            TEXT_SetHoverText(pPacket->nLang, pPacket->szMessage, pUnit);
    }
    else if (pPacket->nMessageType == 7)
    {
        Unicode wszE[0x100];
        MultiByteToWideChar(0, 1, pPacket->szMessage, 0x100, wszE, 0x100);
        const int nLang = pPacket->nLang;
        if (nLang != STRTABLE_GetLanguage())
        {
            for (Unicode* p = wszE; p->wChar; ++p)
                ;
        }
        INV_OpenRecipeScroll(wszE, nLang, pPacket->nMessageColor);
    }
}

// build: symbol ?TEXT_FreeTextLines@* 0x0049D370
static void TEXT_FreeTextLines(T0044CB60* pLine)
{
    while (pLine)
    {
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine->pText, ".\\UI\\text.cpp", 0x60F, 0);
        FOG_Free(pLine, ".\\UI\\text.cpp", 0x610, 0);
        pLine = pNext;
    }
}

// build: symbol ?TEXT_MeasureTextBox@* 0x0049D3C0
static void TEXT_MeasureTextBox(T00479230* pBox)
{
    int nMaxWidth = 0;
    pBox->nTextTop = 0;
    pBox->nTextBottom = pBox->f_14;
    for (T0044CB60* pLine = pBox->pFirst; pLine; pLine = pLine->pNext)
    {
        nMaxWidth = nMaxWidth > D2Win_10121_GetTextWidth(pLine->pText) ? nMaxWidth : D2Win_10121_GetTextWidth(pLine->pText);
    }
    pBox->nWidth = nMaxWidth + 0x14;
    pBox->nHeight = pBox->nLines * 0x0F + 6;
}

void __stdcall TEXT_FreeTextBox(T00479230* pTextBox)
{
    if (pTextBox)
    {
        TEXT_FreeTextLines(pTextBox->pFirst);
        FOG_Free(pTextBox, ".\\UI\\text.cpp", 0x68E, 0);
    }
}

// 0x004A0680
void __cdecl TEXT_FreeTextResources()
{
    if (gdwGlobal_007BF250)
    {
        sub_006612A0(gdwGlobal_007BF250);
        gdwGlobal_007BF250 = 0;
    }
    if (gpTextBox)
    {
        TEXT_FreeTextBox(gpTextBox);
        gpTextBox = 0;
    }
    if (gpMainTextBox)
    {
        TEXT_FreeTextBox(gpMainTextBox);
        FOG_Free(gpMainTextBox, ".\\UI\\text.cpp", 0x6E4, 0);
        gpMainTextBox = 0;
    }
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
    TEXT_FreeTextPanelCels();
    sub_00467430(0);
    TEXT_FreeTextList(gtMessageTextList);
    TEXT_FreeTextList(gtOverheadTextList);
    TEXT_FreeTextList(gtTextHistory);
// build: symbol ?ghHintSound@* 0x007BF24B
    ghHintSound = 0;
}

// 0x0049E300
void __cdecl TEXT_FreeMainTextBox()
{
    if (gpMainTextBox)
    {
        TEXT_FreeTextBox(gpMainTextBox);
        gpMainTextBox = 0;
    }
}

// 0x0049E390
unsigned long __cdecl TEXT_GetTimeoutTick()
{
    return GetTickCount() + 10000;
}

// 0x0049E7F0
void __stdcall sub_0049E7F0_Nop()
{
}

// 0x0049E800
void __stdcall sub_0049E800_Nop()
{
}

// 0x0049E860
void __cdecl TEXT_ClearHint()
{
    if (gnHintId)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId);
        if (nHint)
            sub_004B9EF0_ArmHint(nHint, 0, 0, 4);
        gnHintId = 0;
    }
    ghHintSound = 0;
}

// build: context TEXT_ConvertHoverText
static bool TEXT_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        Unicode::win2Unicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    if (TEXT_IsLanguageCompatible(nLangId))
        return true;

    for (; wszText->wChar; ++wszText)
    {
        if (wszText->wChar >= 0x80)
            return false;
    }
    return true;
}

static void __stdcall TEXT_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (!strlen(szText))
    {
        if (pUnit->pHoverText)
            CHAT_FreeHoverMsg(0, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        return;
    }

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame);
    CHAT_SetLangIdInHoverMsg(pHoverText, nLangId);
    if (pUnit->pHoverText)
        CHAT_FreeHoverMsg(0, pUnit->pHoverText);
    pUnit->pHoverText = pHoverText;
}

// 0x004A05E0
T00479230* __fastcall TEXT_CreateTextBox(const Unicode* wszText, int nMode)
{
    T00479230* pTextBox = (T00479230*)FOG_Alloc(sizeof(T00479230), ".\\UI\\text.cpp", 0x65D, 0);
    if (nMode == 3)
    {
        pTextBox->pFirst = sub_00502970_SplitText(wszText, &pTextBox->nLines, 0xB4);
        TEXT_MeasureTextBox(pTextBox);
        return pTextBox;
    }

    const int nOldFont = D2Win_10127_SetFont(8);
    pTextBox->pFirst = TEXT_BuildTextLines(wszText, &pTextBox->nLines, &pTextBox->f_14);
    pTextBox->nWidth = 0x145;
    pTextBox->nHeight = 0x70;
    pTextBox->nField1A = 0;
    pTextBox->nField1E = 0;
    pTextBox->nField22 = 0;
    pTextBox->nField26 = 0;
    pTextBox->nField2A = 0;
    D2Win_10127_SetFont(nOldFont);
    TEXT_MeasureTextBox(pTextBox);
    return pTextBox;
}

// 0x004A1510
void __fastcall TEXT_ShowTextBox(unsigned short nStringId)
{
    if (gpMainTextBox)
    {
        TEXT_FreeTextBox(gpMainTextBox);
        gpMainTextBox = 0;
    }

    const Unicode* wszText = D2LANG_GetStringFromTblIndex(nStringId);
    const int nOldFont = D2Win_10127_SetFont(0x0D);
    gpMainTextBox = TEXT_CreateTextBox(wszText, 3);
    D2Win_10127_SetFont(nOldFont);
    if (gpMainTextBox)
    {
        gpMainTextBox->nScroll = 1;
        gdwTextEndTick = GetTickCount() + (sub_00526800(wszText) + 0x19) * 0xC8;
        gbTextBoxShown = 1;
// build: symbol ?gbTextBoxPending@* 0x007BF1C4
        gbTextBoxPending = 1;
        gnTextBoxY = 0x64 - (gpMainTextBox->nHeight >> 2);
        gnTextBoxX = 0x140 - (gpMainTextBox->nWidth >> 1);
    }
}

// 0x0049F3D0
void __fastcall TEXT_FreeHoverText(D2HoverTextStrc* pHoverText)
{
    T00479230* pTextBox = CHAT_GetUsedFromHoverMsg(pHoverText);
    if (pTextBox)
    {
        TEXT_FreeTextBox(pTextBox);
        CHAT_SetUsedInHoverMsg(pHoverText, 0);
    }
    CHAT_FreeHoverMsg(0, pHoverText);
}

extern "C" { unsigned int gawScrollSlots; } // 0x007BF098

extern "C" { unsigned int gValue_007BF09C; } // 0x007BF09C

extern "C" { unsigned int gValue_007BF0A0; } // 0x007BF0A0

extern "C" { unsigned int gValue_007BF2A8; } // 0x007BF2A8

// 0x004A28A0
extern "C" void __fastcall TEXT_AcceptShortPacket(const PacketShorts* packet)
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

// 0x0049F960
void __cdecl TEXT_ResetTextBox()
{
    sub_00467430(0);
    if (gpTextBox)
    {
        TEXT_FreeTextBox(gpTextBox);
        gpTextBox = 0;
    }
    if (gnHintId)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId);
        if (nHint)
            sub_004B9EF0_ArmHint(nHint, 0, 0, 4);
        gnHintId = 0;
    }
    ghHintSound = 0;
    if (gbTextHandlersRegistered == 1)
    {
        gbTextHandlersRegistered = 0;
        sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
    }
    if (gbTextSound)
    {
        MSG_SendTwoDwords(0x31, -1, gwTextStringId);
        gbTextSound = 0;
    }
}

extern "C" void __fastcall sub_00524280_InitializeDigest(unsigned int index)
{
    HashState* state = &gStates_00882760[index];
    state->a = 0x67452301u;
    state->b = 0xEFCDAB89u;
    state->c = 0x98BADCFEu;
    state->d = 0x10325476u;
    state->e = 0xC3D2E1F0u;
    state->lowCount = 0;
    state->highCount = 0;
}

// build: symbol ??0ListBoxWrapper@@QAE@HHHHHHHHH@Z 0x004BF8F0
// 0x0049FE10
void __cdecl TEXT_FreeTextPanelCels()
{
    if (gpScroin2Cel)
    {
        ARCHIVE_FreeClientCellFile(gpScroin2Cel);
        gpScroin2Cel = 0;
    }
    if (gpScroin3Cel)
    {
        ARCHIVE_FreeClientCellFile(gpScroin3Cel);
        gpScroin3Cel = 0;
    }
    if (gpTextPanelFrameCel)
    {
        ARCHIVE_FreeClientCellFile(gpTextPanelFrameCel);
        gpTextPanelFrameCel = 0;
    }
}

// 0x0049FEA0
void __stdcall TEXT_PanelClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (nY < gnScreenHeight - 0x30 && nX < gnScreenWidth / 2)
    {
        UI_SetUIVar(0x10, 2, 0);
        TEXT_FreeTextPanelCels();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        GAME_ResetMouseState();
    }
}

// 0x0049FF10
void __cdecl TEXT_DispatchTextData()
{
    if (!gpTextData)
        return;

    const int nTag = gpTextData->dwTag;
    if (nTag == 0x20736B62)
    {
        TEXT_OpenTextPanel(0);
        return;
    }
    if (nTag == 0x20646B62)
    {
        if (!gbTextDataOpen)
        {
            TEXT_OpenTextPanel(1);
            return;
        }
    }
    else if (nTag != 0x20317274)
    {
        return;
    }
    TEXT_DrawPanelFrame();
}

// 0x0049FF60
extern "C" void __fastcall TEXT_AcceptWordPacket(const PacketWords* packet)
{
    if (packet->kind == 4)
    {
        gawScrollSlots = packet->a;
        gValue_007BF09C = packet->b;
        gValue_007BF0A0 = packet->c;
        gValue_007BF254 = 0;
    }
}

// 0x004A0030
int __cdecl TEXT_CloseMessageLogCallback()
{
    UI_SetUIVar(0x18, 1, 0);
    return 1;
}

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// 0x004A0050
void TEXT_OpenMessageLogDialog()
{
    if (gpListDialog)
    {
        return;
    }
    gpListDialog = DIALOG_CreateDialog(5, 0x1E, (int)TEXT_CloseMessageLogCallback, 0, 0, 0, 0,
        gnScreenWidth - 0x14, gnScreenHeight - 0x82, 0, 0);
    sub_004B8370_SetField5C(gpListDialog, 1);
    sub_004B85F0_AddTextLine(gpListDialog, D2LANG_GetStringFromTblIndex(0xFC3), 0x15, 0, 4, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpListDialog, D2LANG_GetStringFromTblIndex(0x1030), gnScreenHeight - 0xA5, 0,
        0, 1, TEXT_CloseMessageLogCallback, 1);
    gpListBox = new ListBoxWrapper(5, 0x41, gnScreenWidth - 0x14, gnScreenHeight - 0xC8, 2, 0, 0xD, 0,
        1);
    if (gpListBox)
    {
        DIALOG_AddWidget(gpListDialog, gpListBox, 0x19, 0x1E);
        sub_0049E340();
        sub_004B82F0_Select(gpListDialog, -1);
    }
}
struct D2PacketRecord6Strc;

struct D2QuestTableStrc;

struct D2UiEntry10Strc;

struct D2QuestUiFlagsStrc;

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char nId;
    unsigned char nFlags;
    unsigned char nValue;
    short nParam;
};

struct D2QuestTableStrc
{
    unsigned char bEnabled;
    unsigned char nCelId;
    unsigned char nCelId2;
    unsigned char nPage;
    void* pTexts;
    int nCondition;
    int nQuestId;
};

extern int gnQuestAct; // 0x007BF2A4

extern int gnQuestParam; // 0x007BF2AC

extern D2QuestTableStrc gaQuestTable[]; // 0x00723F30

extern D2UiEntry10Strc gaQuestLookup[41]; // 0x00723F38

struct D2QuestUiFlagsStrc
{
    char bLocked;
    unsigned char unk0x01[0xA2];
    unsigned char abFlags[41];
};

extern D2QuestUiFlagsStrc gtQuestUiFlags_007BF2B3; // 0x007BF2B3

extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820

void __cdecl GAME_RequestExit(); // 0x0044D520

void __fastcall GAME_SetPlayCinematic(int nValue); // 0x0044D530

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __cdecl GAME_SetDifficultyFlags(); // 0x0044EC80

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback); // 0x00464990

void __fastcall sub_0046BFD0_StartTimer(int nDelay); // 0x0046BFD0

void __fastcall sub_0046F870_LoadMonsterCofs(int nMonsterId, int bLoadNow); // 0x0046F870

void __cdecl INV_StopCinematic(); // 0x00483300

void __cdecl INV_ChainCinematic(); // 0x00483340

void __fastcall TEXT_SelectQuestPage(int nCondition); // 0x004A2C30

void __fastcall TEXT_ClearCainFlag(D2UnitStrc* pUnit); // 0x004A2C70

void __fastcall TEXT_ClearNihlathakFlag(D2UnitStrc* pUnit); // 0x004A2C90

D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0


int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

static int TEXT_FindQuestIndex(int nKey);

extern int gaQuestPageDefault[5]; // 0x007BF280

// 0x004A1910
int TEXT_FindQuestIndex(int nKey)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaQuestLookup[i].nKey == nKey)
            return i;
    }
    return -1;
}

// 0x004A2CB0
void __fastcall TEXT_HandleQuestEvent(int nArg, D2PacketRecord6Strc* pPacket)
{
    if (pPacket)
    {
        unsigned char nFlags = pPacket->nFlags;
        if (nFlags & 1)
        {
            switch (pPacket->nId)
            {
            case 13:
                sub_0046F870_LoadMonsterCofs(MONSTER_DURIEL, 1);
                return;
            case 23:
                GAME_RequestExit();
                return;
            case 3:
                TEXT_PrintChatLine(D2LANG_GetStringFromTblIndex(3708), 0);
                return;
            case 4:
                CUNIT_ForEachMonster(TEXT_ClearCainFlag);
                return;
            case 15:
                TEXT_PrintChatLine(D2LANG_GetStringFromTblIndex(3710), 0);
                return;
            case 10:
                GAME_ConfigureEnvironmentOrDefer();
                return;
            case 33:
                sub_004B9A00(237, 0, 0, 0, 0);
                return;
            }
            return;
        }

        if (nFlags & 2)
        {
            switch (pPacket->nId)
            {
            case 23:
                if (GAME_IsExpansion())
                {
                    INV_ChainCinematic();
                    return;
                }
                GAME_SetDifficultyFlags();
                INV_StopCinematic();
                return;
            case 4:
                sub_004B9A00(241, 0, 0, 0, 0);
                return;
            case 32:
                sub_004B9A00(217, 0, 0, 0, 0);
                return;
            case 33:
                sub_004B9A00(243, 0, 0, 0, 0);
                return;
            case 8:
            case 15:
            case 18:
            case 22:
            case 35:
                sub_004B9A00(7, 0, 0, 0, 0);
                return;
            case 36:
                GAME_SetPlayCinematic(1);
                return;
            }
            return;
        }

        if (nFlags == 0x10)
        {
            unsigned char nId = pPacket->nId;
            if (nId == 10)
            {
                sub_004B9A00(2456, 0, 0, 0, 0);
                sub_004B9A00(2474, 0, 0, 0, 0);
            }
            else if (nId == 33)
            {
                sub_004B9A00(pPacket->nParam, 0, 0, 0, 0);
            }
            return;
        }

        if (nFlags & 0x20)
        {
            unsigned char nId = pPacket->nId;
            if (nId == 32)
            {
                gnQuestParam = pPacket->nParam;
            }
            else if (nId == 33)
            {
                CUNIT_ForEachMonster(TEXT_ClearNihlathakFlag);
                return;
            }
            else
            {
                D2BitBufferStrc* pQuestFlags = MONSTER_GetQuestFlags();
                if (pQuestFlags && QUESTRECORD_GetQuestState(pQuestFlags, 1, 0))
                {
                    return;
                }

                if (QUESTRECORD_GetQuestState(pQuestFlags, 1, 1))
                {
                    return;
                }

                gnQuestAct = pPacket->nParam;
                if (gnQuestAct > 5 || gnQuestAct < 0)
                {
                    gnQuestAct = 666;
                }

                if (gnQuestAct != 5)
                {
                    gtQuestUiFlags_007BF2B3.abFlags[TEXT_FindQuestIndex(1)] = pPacket->nValue;
                    return;
                }

                if (pPacket->nId == 23)
                {
                    short nDelay = pPacket->nParam;
                    sub_0046BFD0_StartTimer(nDelay < 1 ? 1 : nDelay);
                    return;
                }
            }
        }
    }

refresh:
    if (!gnState_007BF298)
    {
        if (UI_SetUIVar(17, 0, 0) == 1)
        {
            TEXT_SelectQuestPage(pPacket->nId);
            gnState_007BF298 = 1;
        }
        return;
    }

    if (GAME_GetUIVarState(15))
    {
        int nIndex = TEXT_FindQuestIndex(pPacket->nId);
        if (nIndex != -1)
        {
            gtQuestUiFlags_007BF2B3.abFlags[nIndex] = pPacket->nValue;
            if (!gtQuestUiFlags_007BF2B3.bLocked)
            {
                D2QuestTableStrc* pEntry = &gaQuestTable[nIndex];
// build: symbol ?gnPage@* 0x007C0255
                if (pEntry->nPage == gnPage)
                {
// build: symbol ?gnQuestSelectedSlot@* 0x007BF2B9
                    gnQuestSelectedSlot = pEntry->nCelId2;
                }
            }
        }
    }
}
// build: symbol ?SCMD_HandleQuestEvent@* 0x0045E540
void __fastcall SCMD_HandleQuestEvent(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    TEXT_HandleQuestEvent(1, &tPacket);
}

// 0x004A3050
void __cdecl sub_004A3050()
{
    gaQuestPageDefault[0] = -1;
    gaQuestPageDefault[1] = -1;
    gaQuestPageDefault[2] = -1;
    gaQuestPageDefault[3] = -1;
    gaQuestPageDefault[4] = -1;
}



#include "gen/data/Source/D2Client/UI/text.inc"
