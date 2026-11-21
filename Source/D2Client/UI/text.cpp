#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"

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

struct UnicodeChar;

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

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __stdcall sub_00487A10_SelectItemPageTab(unsigned char nTab); // 0x00487A10

void __cdecl sub_00487ED0_SetupPanelButtons(); // 0x00487ED0

int __fastcall sub_004B3230_GetTickPair(int* pUnitId); // 0x004B3230

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

extern int gnGlobal_00711470; // 0x00711470

extern D2ClientTabStrc gaTabs_0072211A[]; // 0x0072211A

extern int gnGlobal_007BCAF0; // 0x007BCAF0

extern int gnGlobal_007BCBEC; // 0x007BCBEC

extern int gdwGlobal_007BCBF0; // 0x007BCBF0

extern int gnGlobal_007BCC08; // 0x007BCC08

extern int gnGlobal_007BCC40; // 0x007BCC40

extern int gnGlobal_007BCE30; // 0x007BCE30

extern int gnGlobal_007BEECC; // 0x007BEECC

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

int __cdecl sub_004F59A0(); // 0x004F59A0

void __fastcall sub_00451E10_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10

void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

extern int gbStarted_007BF27C; // 0x007BF27C

extern D2MsgHandlerEntryStrc gaTextMsgHandlers_00722600[]; // 0x00722600

struct UnicodeChar : Unicode
{
    UnicodeChar();                                                                                          // 0x0042F530
};

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

Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0

Unicode* __fastcall sub_00452300_StripStringAndNextChar(Unicode* pText); // 0x00452300

int __fastcall sub_0047A170_TestNotFlag4(int nUnitId); // 0x0047A170

void __fastcall sub_0048BBE0_SetNameText(const Unicode* wszName, int nUnused, int nArg); // 0x0048BBE0

void __fastcall sub_0049E3A0_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern "C" Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0

char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit); // 0x00622150

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0

extern int gnGameFrame_007BF20E; // 0x007BF20E

static __declspec(noinline) bool sub_0049E250_IsLanguageCompatible(int nLangId);

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

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __stdcall sub_0049D4D0_FreeTextList(void* pList); // 0x0049D4D0

void __cdecl sub_0049FE10(); // 0x0049FE10

T0044CB60* __stdcall sub_004A0320_BuildTextLines(const Unicode* wszText, int* pLineCount, unsigned short* pMaxLines); // 0x004A0320

void __fastcall sub_004B8020(void* pRes); // 0x004B8020

void __fastcall sub_004B9EF0_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

T00479230* __stdcall CHAT_GetUsedFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661200

void __stdcall CHAT_SetUsedInHoverMsg(D2HoverTextStrc* pHoverMsg, int bUsed); // 0x00661210

void __stdcall sub_006612A0(int nHandle); // 0x006612A0

extern unsigned int gdwTextEndTick_007BF1AC; // 0x007BF1AC

D2ClientDialogStrc* gpListDialog_007BF1B0; // 0x007BF1B0

void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags); // 0x00413020

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
        return SMemAlloc(nSize, gszNew_006CC82C, -1, 0);
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

extern ListBoxWrapper* gpListBox_007BF1B4; // 0x007BF1B4

extern int gnGlobal_007BF1C8; // 0x007BF1C8

extern char gtTextList_007BF1E4[]; // 0x007BF1E4

extern char gtTextList_007BF1EA[]; // 0x007BF1EA

extern char gtTextList_007BF1F0[]; // 0x007BF1F0

extern unsigned short gwTextStringId_007BF212; // 0x007BF212

extern int gnHintId_007BF260; // 0x007BF260

void __fastcall sub_00478A00(void* pCel); // 0x00478A00

extern int gnGlobal_0071146C; // 0x0071146C

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl sub_0044DA40(); // 0x0044DA40

void __cdecl sub_0049FA10_DrawPanelFrame(); // 0x0049FA10

void __stdcall sub_0049FBA0_OpenTextPanel(int bFlag); // 0x0049FBA0

extern D2ClientTextDataStrc* gpTextData_007BF228; // 0x007BF228

extern int gnGlobal_007BF254; // 0x007BF254

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

extern "C" ByteRecord* gRecords_007BC9A0;

extern "C" int gRecordCount_007BC9A4;

extern "C" unsigned int gValue_007BF254; // 0x007BF254

extern "C" unsigned int gValue_007BF2A4; // 0x007BF2A4

extern "C" unsigned int gValue_007BF2AC; // 0x007BF2AC

extern "C" HashState gStates_00882760[];

extern "C" ClassTableView* gClassTable_00744304;

static bool sub_0049E280_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText);

static void __stdcall sub_0049F410_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit);

int __cdecl sub_004A0030_DialogCallback(); // 0x004A0030

void __fastcall sub_004B7C00_AddWidget(D2ClientDialogStrc* pDialog, void* pWidget, int nArg8, int nArgC); // 0x004B7C00

D2ClientDialogStrc* __fastcall sub_004B7EB0_CreateDialog(int nArg1, int nArg2, int nArg8, int nArgC, int nArg10, int nArg14,
    int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0

void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0

void __fastcall sub_004B8370_SetField5C(D2ClientDialogStrc* pDialog, int nValue); // 0x004B8370

void __fastcall sub_004B85F0_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nArg8, int nArgC,
    int nArg10, int nArg14, int (__cdecl* pfnCallback)(), int nArg1C); // 0x004B85F0

unsigned char gnSelectedTab_007BCC04; // 0x007BCC04

unsigned char gbGlobal_007BEEE4; // 0x007BEEE4

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

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

#pragma pack(push, 2)

struct D2ListBoxLineStrc
{
    __forceinline D2ListBoxLineStrc()
    {
    }

    Unicode wszText0[0x400];
    Unicode f_800[0x400];
    Unicode f_1000[0x400];
    Unicode f_1800[0x400];
    Unicode f_2000[0x400];
    Unicode wszText5[0x400];
    short nFlags;
    int unk0x3002;
    int nData;
    int unk0x300A;
};

#pragma pack(pop)


#pragma pack(push, 2)

class ListBoxImplementation : public UIWidget
{
public:
    ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18,
        int nCallback, bool bLargeFont);
    virtual void Slot01();

    D2ListBoxLineStrc aLines[0x80];
    int f_180708;
    int f_18070C;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int f_18071C;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int f_180730;
    int nCallbackRow;
    int nSelectedIndex;
    int unk0x18073C;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    int pfnCallback;
    int f_18074E;
    int unk0x180752;
    int unk0x180756;
    int nX;
    int nY;
    int f_180762;
    int nScrollStep;
    int nArg10;
    int nRepeatTicks;
    int nState;
};

#pragma pack(pop)

unsigned long gnGlobal_007BF22C; // 0x007BF22C

unsigned char gnGlobal_007BF23A; // 0x007BF23A

T00479230* gpTextBox_007BF0A4; // 0x007BF0A4

T00479230* gpTextBox_007BF1A8; // 0x007BF1A8

int gnTextBoxX_007BF1D0; // 0x007BF1D0

int gnTextBoxY_007BF1D4; // 0x007BF1D4

int gbTextSound_007BF230; // 0x007BF230

void* gpCelFile_007BF26C; // 0x007BF26C

void* gpCelFile_007BF270; // 0x007BF270

void* gpCelFile_007BF274; // 0x007BF274

// 0x00491940
void __cdecl sub_00491940_ResetNpcPanel()
{
    gnGlobal_007BCE30 = 0;
    gnGlobal_007BCC40 = -1;
    gnSelectedTab_007BCC04 = 0;
    gnGlobal_007BCAF0 = 0;
    for (int i = 0; i < gnGlobal_00722158; ++i)
    {
        *(int*)gaTabs_0072211A[i].bSelected = 0;
        *(int*)gaTabs_0072211A[i].bEnabled = 0;
    }
    gnGlobal_007BCBEC = 0;
    gdwGlobal_007BCBF0 = 1;
    sub_00487ED0_SetupPanelButtons();

    int nNpcId;
    if (sub_004B3230_GetTickPair(&nNpcId))
    {
        D2UnitStrc* pNpc = sub_00463990(nNpcId, 1);
        int bMatched = 0;
        if (pNpc)
        {
            switch ((unsigned int)pNpc->dwClassId)
            {
            case 0x9A:
            case 0x1FF:
                gnSelectedTab_007BCC04 = 1;
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
                gnSelectedTab_007BCC04 = 3;
                bMatched = 1;
                break;
            case 0x93:
            case 0x200:
                gnSelectedTab_007BCC04 = 0;
                bMatched = 1;
                break;
            }
        }
        sub_00487A10_SelectItemPageTab(gnSelectedTab_007BCC04);
        if (bMatched)
        {
            gnGlobal_007BCC08 = GetTickCount() + 500;
        }
    }
}

// 0x004939B0
void __cdecl sub_004939B0_LoadPopupHireling()
{
    gnGlobal_007BEECC = 0;
    sub_00455F20(0x23, 0, 0);
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "PopupHireling", 0, &dwValue);
    if (!dwValue)
    {
        gbGlobal_007BEEE4 = 1;
    }
}

// 0x0049D2E0
int __fastcall sub_0049D2E0_IsAsciiChar(const unsigned short* pChar)
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
static __forceinline void sub_0049D3B0_SetWidthFromWord(D2TextWidthStrc* pRecord)
{
    pRecord->nWidth = pRecord->wWidth;
}

void __fastcall sub_M111_Emit_0049D3B0(D2TextWidthStrc* pRecord, int* pDone)
{
    sub_0049D3B0_SetWidthFromWord(pRecord);
    *pDone = 1;
}

// 0x0049D570
void __fastcall sub_0049D570_SaveTextDisplaySetting(unsigned long nValue)
{
    gnGlobal_007BF1F6 = nValue;
    SRegSaveValue("Diablo II", "Text Display Beta", 0, nValue);
}

// 0x0049D590
unsigned int __fastcall sub_0049D590_CalcTextOffset(unsigned int nValue)
{
    return 0x70 - (nValue >> 10);
}

// 0x0049D8E0
void __fastcall sub_0049D8E0_DrawTextList(D2TextListStrc* pList, int nX, int nY)
{
    int nLines = pList->wCount > 10 ? 10 : pList->wCount;

    D2TextListNodeStrc* pNode = pList->pFirst;
    if (!nLines || !pNode || nY < 0)
    {
        return;
    }

    const int nHeight = pList->nHeight;
    if (nHeight + nY >= gnGlobal_00711470)
    {
        return;
    }

    sub_0046EFD0_DrawFramedBox(nX, nY + 4, pList->nWidth, nHeight - 5, 0, 1);
    int i = 0;
    const int nOldFont = sub_00502EF0(13);
    for (; i < nLines && pNode; ++i)
    {
        sub_00502320(pNode->wszText, nX + 10, nY + 18 + 15 * (i - nLines + pList->wCount), 0, 0);
        pNode = pNode->pNext;
    }
    sub_00502EF0(nOldFont);
}

// 0x0049DA30
void __fastcall sub_0049DA30(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        gdwGlobal_007BF23B = pUnit->dwUnitId;
        gnGlobal_007BF23A = 1;
    }
    else
    {
        gnGlobal_007BF23A = 0;
    }
}

// 0x0049DA60
void __fastcall sub_0049DA60_ToggleTextHandlers(int nMode)
{
    if (nMode == 0)
    {
        if (gbStarted_007BF27C == 1)
        {
            gbStarted_007BF27C = 0;
            sub_00451E10_UnregisterHandlerTable((void*)sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
        }
    }
    else if (nMode == 1 && gbStarted_007BF27C == 0)
    {
        gbStarted_007BF27C = 1;
        gnGlobal_007BF22C = GetTickCount();
        sub_00451DB0_RegisterMsgHandlers(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
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
void __fastcall sub_0049DAE0_AdjustTextPos(D2TextBoxPosStrc* pBox, D2TextPointStrc* pPoint)
{
    pPoint->nX -= pBox->wWidth / 2;
    pPoint->nY -= 50;
    pPoint->nY -= pBox->nRows * 15 + 3;
}

// 0x0049DB10
D2ClientStringListStrc* __fastcall sub_0049DB10_CloneStringList(D2ClientStringListStrc* pSource)
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
static bool sub_0049E250_IsLanguageCompatible(int nLangId)
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

// build: context sub_0049F490_HandleHoverTextPacket
void __fastcall sub_0049F490_HandleHoverTextPacket(D2GSPacketSrv26* pPacket)
{
    if (pPacket->nUnitType == 0 && !sub_0047A170_TestNotFlag4(pPacket->dwUnitGUID))
        return;

    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitGUID, pPacket->nUnitType);
    char szName[0x11] = { 0 };
    if ((pUnit && pUnit->dwUnitType == UNIT_PLAYER) || pPacket->szName[0])
    {
        if (pUnit)
            SStrCopy(szName, UNITS_GetPlayerName(pUnit), 0x11);
        else
            SStrCopy(szName, pPacket->szName, 0x11);

        if (sub_00611560_GetOrCreateIgnoreList()->sub_00610380_IsListed(szName))
            return;
        if (sub_00611560_GetOrCreateIgnoreList()->sub_0060FC40_IsTextFiltered(pPacket->szMessage))
            return;
    }

    Unicode wszText[0x100];
    if (!sub_0049E280_ConvertHoverText(pPacket->nLang, wszText, pPacket->szMessage))
        return;
    wszText[0xFF].wChar = 0;

    if (pPacket->nMessageType == 4)
    {
        sub_0049E3A0_PrintChatLine(wszText, pPacket->nMessageColor);
        return;
    }

    UnicodeChar wszA[0x264];
    UnicodeChar wszB[0x264];
    UnicodeChar wszC[0x10];
    if (pPacket->nMessageType == 6)
    {
        Unicode::win2Unicode(wszB, pPacket->szMessage, 0x100);
        Unicode::win2Unicode(wszC, pPacket->szName, 0x10);
        sub_005269D0(0x264, wszA, D2LANG_GetStringFromTblIndex(0xE4A), wszC, wszB);
        sub_00452300_StripStringAndNextChar(wszA);
        sub_0049E3A0_PrintChatLine(wszA, 2);
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
            sub_0049E3A0_PrintChatLine(wszA, 2);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        sub_0049E3A0_PrintChatLine(wszA, 2);
    }
    else if (pPacket->nMessageType == 1)
    {
        if (pPacket->nUnitType == 0 || pPacket->nUnitType == 1)
        {
            sub_0049E3A0_PrintChatLine(wszText, pPacket->nMessageColor);
            return;
        }
        const int nNameLen = strlen(pPacket->szName);
        const int nTextLen = strlen(pPacket->szMessage);
        if (nNameLen >= 1 && nNameLen <= 15)
        {
            UnicodeChar wszD[0x10];
            Unicode::win2Unicode(wszD, pPacket->szName, 0x10);
            sub_005267E0(wszA, wszD);
            sub_004521C0_PrefixLevelText(wszA, 4);
            sub_005267E0(wszB, D2LANG_GetStringFromTblIndex(0xFD0));
            Unicode::strcat(wszB, wszText);
            sub_004521C0_PrefixLevelText(wszB, 0);
            Unicode::strcat(wszA, wszB);
            sub_0049E3A0_PrintChatLine(wszA, pPacket->nMessageColor);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        sub_0049E3A0_PrintChatLine(wszA, pPacket->nMessageColor);
    }
    else if (pPacket->nMessageType == 5)
    {
        if (pUnit)
            sub_0049F410_SetHoverText(pPacket->nLang, pPacket->szMessage, pUnit);
    }
    else if (pPacket->nMessageType == 7)
    {
        UnicodeChar wszE[0x100];
        MultiByteToWideChar(0, 1, pPacket->szMessage, 0x100, wszE, 0x100);
        const int nLang = pPacket->nLang;
        if (nLang != STRTABLE_GetLanguage())
        {
            for (Unicode* p = wszE; p->wChar; ++p)
                ;
        }
        sub_0048BBE0_SetNameText(wszE, nLang, pPacket->nMessageColor);
    }
}

static void sub_0049D370_FreeTextLines(T0044CB60* pLine)
{
    while (pLine)
    {
        T0044CB60* pNext = pLine->pNext;
        FOG_Free(pLine->pText, ".\\UI\\text.cpp", 0x60F, 0);
        FOG_Free(pLine, ".\\UI\\text.cpp", 0x610, 0);
        pLine = pNext;
    }
}

static void sub_0049D3C0_MeasureTextBox(T00479230* pBox)
{
    int nMaxWidth = 0;
    pBox->nTextTop = 0;
    pBox->nTextBottom = pBox->f_14;
    for (T0044CB60* pLine = pBox->pFirst; pLine; pLine = pLine->pNext)
    {
        nMaxWidth = nMaxWidth > sub_00501820(pLine->pText) ? nMaxWidth : sub_00501820(pLine->pText);
    }
    pBox->nWidth = nMaxWidth + 0x14;
    pBox->nHeight = pBox->nLines * 0x0F + 6;
}

void __stdcall sub_0049D410_FreeTextBox(T00479230* pTextBox)
{
    if (pTextBox)
    {
        sub_0049D370_FreeTextLines(pTextBox->pFirst);
        FOG_Free(pTextBox, ".\\UI\\text.cpp", 0x68E, 0);
    }
}

// 0x0049E300
void __cdecl sub_0049E300_FreeMainTextBox()
{
    if (gpTextBox_007BF1A8)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF1A8);
        gpTextBox_007BF1A8 = 0;
    }
}

// 0x0049E390
unsigned long __cdecl sub_0049E390_GetTimeoutTick()
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
void __cdecl sub_0049E860_ClearHint()
{
    if (gnHintId_007BF260)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId_007BF260);
        if (nHint)
            sub_004B9EF0_ArmHint(nHint, 0, 0, 4);
        gnHintId_007BF260 = 0;
    }
    gnHintSound_007BF24B = 0;
}

// 0x0049F3D0
void __fastcall sub_0049F3D0_FreeHoverText(D2HoverTextStrc* pHoverText)
{
    T00479230* pTextBox = CHAT_GetUsedFromHoverMsg(pHoverText);
    if (pTextBox)
    {
        sub_0049D410_FreeTextBox(pTextBox);
        CHAT_SetUsedInHoverMsg(pHoverText, 0);
    }
    CHAT_FreeHoverMsg(0, pHoverText);
}

// build: context sub_0049E280_ConvertHoverText
static bool sub_0049E280_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        Unicode::win2Unicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    if (sub_0049E250_IsLanguageCompatible(nLangId))
        return true;

    for (; wszText->wChar; ++wszText)
    {
        if (wszText->wChar >= 0x80)
            return false;
    }
    return true;
}

static void __stdcall sub_0049F410_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit)
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

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame_007BF20E);
    CHAT_SetLangIdInHoverMsg(pHoverText, nLangId);
    if (pUnit->pHoverText)
        CHAT_FreeHoverMsg(0, pUnit->pHoverText);
    pUnit->pHoverText = pHoverText;
}

// 0x0049F960
void __cdecl sub_0049F960_ResetTextBox()
{
    sub_00467430(0);
    if (gpTextBox_007BF0A4)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF0A4);
        gpTextBox_007BF0A4 = 0;
    }
    if (gnHintId_007BF260)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId_007BF260);
        if (nHint)
            sub_004B9EF0_ArmHint(nHint, 0, 0, 4);
        gnHintId_007BF260 = 0;
    }
    gnHintSound_007BF24B = 0;
    if (gbStarted_007BF27C == 1)
    {
        gbStarted_007BF27C = 0;
        sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
    }
    if (gbTextSound_007BF230)
    {
        sub_004786A0_SendDwords2(0x31, -1, gwTextStringId_007BF212);
        gbTextSound_007BF230 = 0;
    }
}

// 0x0049FE10
void __cdecl sub_0049FE10()
{
    if (gpCelFile_007BF270)
    {
        sub_00478A00(gpCelFile_007BF270);
        gpCelFile_007BF270 = 0;
    }
    if (gpCelFile_007BF26C)
    {
        sub_00478A00(gpCelFile_007BF26C);
        gpCelFile_007BF26C = 0;
    }
    if (gpCelFile_007BF274)
    {
        sub_00478A00(gpCelFile_007BF274);
        gpCelFile_007BF274 = 0;
    }
}

// 0x0049FEA0
void __stdcall sub_0049FEA0_PanelClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (nY < gnGlobal_00711470 - 0x30 && nX < gnGlobal_0071146C / 2)
    {
        sub_00455F20(0x10, 2, 0);
        sub_0049FE10();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        sub_0044DA40();
    }
}

// 0x0049FF10
void __cdecl sub_0049FF10_DispatchTextData()
{
    if (!gpTextData_007BF228)
        return;

    const int nTag = gpTextData_007BF228->dwTag;
    if (nTag == 0x20736B62)
    {
        sub_0049FBA0_OpenTextPanel(0);
        return;
    }
    if (nTag == 0x20646B62)
    {
        if (!gnGlobal_007BF254)
        {
            sub_0049FBA0_OpenTextPanel(1);
            return;
        }
    }
    else if (nTag != 0x20317274)
    {
        return;
    }
    sub_0049FA10_DrawPanelFrame();
}

extern "C" { unsigned int gValue_007BF098; } // 0x007BF098

extern "C" { unsigned int gValue_007BF09C; } // 0x007BF09C

extern "C" { unsigned int gValue_007BF0A0; } // 0x007BF0A0

extern "C" { unsigned int gValue_007BF2A8; } // 0x007BF2A8

// 0x0049FF60
extern "C" void __fastcall sub_0049FF60_AcceptWordPacket(const PacketWords* packet)
{
    if (packet->kind == 4)
    {
        gValue_007BF098 = packet->a;
        gValue_007BF09C = packet->b;
        gValue_007BF0A0 = packet->c;
        gValue_007BF254 = 0;
    }
}

// 0x004A0030
int __cdecl sub_004A0030_DialogCallback()
{
    sub_00455F20(0x18, 1, 0);
    return 1;
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
// 0x004A0050
void sub_004A0050_OpenListBoxDialog()
{
    if (gpListDialog_007BF1B0)
    {
        return;
    }
    gpListDialog_007BF1B0 = sub_004B7EB0_CreateDialog(5, 0x1E, (int)sub_004A0030_DialogCallback, 0, 0, 0, 0,
        gnGlobal_0071146C - 0x14, gnGlobal_00711470 - 0x82, 0, 0);
    sub_004B8370_SetField5C(gpListDialog_007BF1B0, 1);
    sub_004B85F0_AddTextLine(gpListDialog_007BF1B0, D2LANG_GetStringFromTblIndex(0xFC3), 0x15, 0, 4, 1, 0, 0);
    sub_004B85F0_AddTextLine(gpListDialog_007BF1B0, D2LANG_GetStringFromTblIndex(0x1030), gnGlobal_00711470 - 0xA5, 0,
        0, 1, sub_004A0030_DialogCallback, 1);
    gpListBox_007BF1B4 = new ListBoxWrapper(5, 0x41, gnGlobal_0071146C - 0x14, gnGlobal_00711470 - 0xC8, 2, 0, 0xD, 0,
        1);
    if (gpListBox_007BF1B4)
    {
        sub_004B7C00_AddWidget(gpListDialog_007BF1B0, gpListBox_007BF1B4, 0x19, 0x1E);
        sub_0049E340();
        sub_004B82F0_Select(gpListDialog_007BF1B0, -1);
    }
}

// 0x004A05E0
T00479230* __fastcall sub_004A05E0_CreateTextBox(const Unicode* wszText, int nMode)
{
    T00479230* pTextBox = (T00479230*)FOG_Alloc(sizeof(T00479230), ".\\UI\\text.cpp", 0x65D, 0);
    if (nMode == 3)
    {
        pTextBox->pFirst = sub_00502970_SplitText(wszText, &pTextBox->nLines, 0xB4);
        sub_0049D3C0_MeasureTextBox(pTextBox);
        return pTextBox;
    }

    const int nOldFont = sub_00502EF0(8);
    pTextBox->pFirst = sub_004A0320_BuildTextLines(wszText, &pTextBox->nLines, &pTextBox->f_14);
    pTextBox->nWidth = 0x145;
    pTextBox->nHeight = 0x70;
    pTextBox->nField1A = 0;
    pTextBox->nField1E = 0;
    pTextBox->nField22 = 0;
    pTextBox->nField26 = 0;
    pTextBox->nField2A = 0;
    sub_00502EF0(nOldFont);
    sub_0049D3C0_MeasureTextBox(pTextBox);
    return pTextBox;
}

// 0x004A0680
void __cdecl sub_004A0680_FreeTextResources()
{
    if (gdwGlobal_007BF250)
    {
        sub_006612A0(gdwGlobal_007BF250);
        gdwGlobal_007BF250 = 0;
    }
    if (gpTextBox_007BF0A4)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF0A4);
        gpTextBox_007BF0A4 = 0;
    }
    if (gpTextBox_007BF1A8)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF1A8);
        FOG_Free(gpTextBox_007BF1A8, ".\\UI\\text.cpp", 0x6E4, 0);
        gpTextBox_007BF1A8 = 0;
    }
    if (gpListDialog_007BF1B0)
    {
        sub_004B8020(gpListDialog_007BF1B0);
        gpListDialog_007BF1B0 = 0;
    }
    if (gpListBox_007BF1B4)
    {
        delete gpListBox_007BF1B4;
        gpListBox_007BF1B4 = 0;
    }
    sub_0049FE10();
    sub_00467430(0);
    sub_0049D4D0_FreeTextList(gtTextList_007BF1E4);
    sub_0049D4D0_FreeTextList(gtTextList_007BF1EA);
    sub_0049D4D0_FreeTextList(gtTextList_007BF1F0);
    gnHintSound_007BF24B = 0;
}

// 0x004A1510
void __fastcall sub_004A1510_ShowTextBox(unsigned short nStringId)
{
    if (gpTextBox_007BF1A8)
    {
        sub_0049D410_FreeTextBox(gpTextBox_007BF1A8);
        gpTextBox_007BF1A8 = 0;
    }

    const Unicode* wszText = D2LANG_GetStringFromTblIndex(nStringId);
    const int nOldFont = sub_00502EF0(0x0D);
    gpTextBox_007BF1A8 = sub_004A05E0_CreateTextBox(wszText, 3);
    sub_00502EF0(nOldFont);
    if (gpTextBox_007BF1A8)
    {
        gpTextBox_007BF1A8->nScroll = 1;
        gdwTextEndTick_007BF1AC = GetTickCount() + (sub_00526800(wszText) + 0x19) * 0xC8;
        gnGlobal_007BF1C8 = 1;
        gnGlobal_007BF1C4 = 1;
        gnTextBoxY_007BF1D4 = 0x64 - (gpTextBox_007BF1A8->nHeight >> 2);
        gnTextBoxX_007BF1D0 = 0x140 - (gpTextBox_007BF1A8->nWidth >> 1);
    }
}

// 0x004A28A0
extern "C" void __fastcall sub_004A28A0_AcceptShortPacket(const PacketShorts* packet)
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

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7ListBoxImplementation@@6B@ 0x006DAAEC
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004BF650
ListBoxImplementation::ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14,
    int nArg18, int nCallback, bool bLargeFont)
{
    f_180708 = nX;
    f_18070C = nY;
    nRectWidth = nWidth;
    nRectHeight = nHeight;
    nCallbackRow = -1;
    nSelectedIndex = -1;
    this->nArg14 = nArg14;
    this->nArg18 = nArg18;
    f_18071C = 0;
    bRowsPressed = 0;
    bTopPressed = 0;
    bBottomPressed = 0;
    nState = 0;
    f_180730 = 0;
    nEntryCount = 0;
    for (int n = 0; n < 0x80; n++)
    {
        aLines[n].wszText0[0].wChar = 0;
        aLines[n].f_800[0].wChar = 0;
        aLines[n].f_1000[0].wChar = 0;
        aLines[n].f_1800[0].wChar = 0;
        aLines[n].f_2000[0].wChar = 0;
        aLines[n].wszText5[0].wChar = 0;
        aLines[n].nFlags = 0;
        aLines[n].nData = 0;
        aLines[n].unk0x300A = 1;
        aLines[n].unk0x3002 = 0;
    }
    pfnCallback = nCallback;
    this->nArg10 = nArg10;
    this->nX = f_180708 + nRectWidth - 0x12;
    this->nY = f_18070C + 0x10;
    nScrollStep = 0xE;
    if (nRectHeight < 0x20)
    {
        f_180762 = 1;
    }
    else
    {
        f_180762 = (nRectHeight - 0x10) / 12 - 1;
    }
    f_18074E = 1;
    if (D2GFX_GetResolutionMode() == 2)
    {
        nLineHeight = bLargeFont ? 0x1C : 0x12;
    }
    else
    {
        nLineHeight = 0x12;
    }
}

#include "gen/data/Source/D2Client/UI/text.inc"
