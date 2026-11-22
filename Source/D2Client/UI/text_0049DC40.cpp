#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2LevelTxt.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2CelContext.h"

struct D2ActiveRoomStrc;

struct D2StoredUnitRecordStrc;

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2TextNodeStrc;

struct D2TextListStrc;

struct D2NamePacketStrc;

struct ListBoxImplementation;

struct D2GSPacketSrv5A;

struct D2MonStatsTxt;

struct D2SuperUniquesTxt;

struct D2GSPacketSrv26;

struct D2CommonChatIgnoreListStrc;

struct D2RectStrc;

struct T00479230;

struct T0044CB60
{
    Unicode* pText;
    T0044CB60* pNext;
};

struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned char nLines[2];
    unsigned char nColor[4];
    unsigned char dwEndTick[4];
    unsigned char pNext[4];
};

struct D2NamePacketStrc
{
    unsigned char nHeader;
    char szName[16];
    unsigned char nValue[4];
};

struct ListBoxImplementation
{
    void* f_0;
    char unk0x000004[0x18070C];
    int nTextWidth;

    void sub_004BE410_DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor);
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __fastcall sub_004538D0(unsigned int nUIVar); // 0x004538D0

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall sub_0046EFD0_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410

int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730

int __fastcall sub_00501820(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void __fastcall sub_00502320(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

T0044CB60* __fastcall sub_00502970_SplitText(Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

int __fastcall sub_00502EF0(int nArg); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall sub_0065FEC0_ItemApplyProps(int nPass, int nArg1, D2UnitStrc* pItem, int nArg, int nArg2, int nArg5); // 0x0065FEC0

extern int gnGlobal_0071146C; // 0x0071146C

extern int gnGlobal_00711470; // 0x00711470

extern D2TextListStrc gtTextList_007BF1E4; // 0x007BF1E4

extern Unicode gwszName_007C0E84[]; // 0x007C0E84

#pragma pack(push, 1)

struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    int dwParam;
    unsigned char nParam;
    union
    {
        char szText[32];
        char szTextData[2][16];
    };
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" unsigned int __cdecl strlen(const char* sz);

extern "C" const char* __fastcall sub_004795C0_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

int __fastcall sub_0047A0C0_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __cdecl sub_004646A0_GetPlayerRoom(); // 0x004646A0

unsigned int __fastcall sub_004DC440(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall sub_0049E3A0_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0

void __fastcall sub_0049E5C0_PrintPartyText(const Unicode* wszText, char nColor); // 0x0049E5C0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId); // 0x006556E0

extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634

static int sub_0049E8F0_FormatPartyEvent(Unicode* pOut, D2GSPacketSrv5A* pPacket); // 0x0049E8F0

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

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

Unicode* __fastcall sub_004521C0_PrefixLevelText(Unicode* pText, int nDigit); // 0x004521C0

Unicode* __fastcall sub_00452300_StripStringAndNextChar(Unicode* pText); // 0x00452300

int __fastcall sub_0047A170_TestNotFlag4(int nUnitId); // 0x0047A170

void __fastcall sub_0048BBE0_SetNameText(const Unicode* wszName, int nUnused, int nArg); // 0x0048BBE0

void __fastcall sub_0049E3A0_ShowChatText(const Unicode* wszText, char nColor);

char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit); // 0x00622150

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0

extern int gnGameFrame_007BF20E; // 0x007BF20E

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

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);

void __fastcall sub_00451E10_UnregisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl sub_00453AE0(); // 0x00453AE0

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990

int __cdecl sub_00463DF0(); // 0x00463DF0

void __fastcall sub_00464950(UNITFN pfnCallback); // 0x00464950

void __fastcall sub_00464990(UNITFN pfnCallback); // 0x00464990

void __fastcall sub_004649D0(UNITFN pfnCallback); // 0x004649D0

void __fastcall sub_00467430(int nArg); // 0x00467430

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070

void __fastcall sub_004760C0_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY); // 0x004760C0

void __fastcall sub_004786A0_SendDwords2(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __fastcall sub_0049D8E0_DrawTextList(T00479230* pTextBox, int nX, int nY); // 0x0049D8E0

void __stdcall sub_0049D410_FreeTextBox(T00479230* pTextBox); // 0x0049D410

static __declspec(noinline) int __cdecl sub_0049D5A0_UpdateTextBox(T00479230* pTextBox);

void __cdecl sub_0049DC40_DrawTextList(); // 0x0049DC40

void __cdecl sub_0049DEE0_DrawOverheadTextList(); // 0x0049DEE0

void __cdecl sub_0049E300_FreeMainTextBox(); // 0x0049E300

void __cdecl sub_0049F960_ResetTextBox(); // 0x0049F960

void __cdecl sub_004A0880_CloseTextUnit(); // 0x004A0880

void __fastcall sub_004A0B30_DrawUnitHoverText(D2UnitStrc* pUnit); // 0x004A0B30

void __fastcall sub_004A0D20_DrawObjectHoverText(D2UnitStrc* pUnit); // 0x004A0D20

extern "C" void __fastcall sub_004B3830_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830

void __fastcall sub_004B8100_DrawDialog(D2ClientDialogStrc* pDialog); // 0x004B8100

int __cdecl sub_004F59A0(); // 0x004F59A0

int __cdecl sub_00514CC0(); // 0x00514CC0

extern D2MsgHandlerEntryStrc gaTextMsgHandlers_00722600[]; // 0x00722600

extern T00479230* gpTextBox_007BF0A4; // 0x007BF0A4

extern T00479230* gpTextBox_007BF1A8; // 0x007BF1A8

extern D2ClientDialogStrc* gpListDialog_007BF1B0; // 0x007BF1B0

extern int gnGlobal_007BF1C8; // 0x007BF1C8

extern D2RectStrc gtTextRect_007BF1D0; // 0x007BF1D0

extern D2TextCallback gpfnTextCallback_007BF258; // 0x007BF258

extern void* gpTextCallbackContext_007BF25C; // 0x007BF25C

extern int gnGlobal_007BF278; // 0x007BF278

static int __stdcall sub_004A0770(T00479230* pTextBox, int bIgnore); // 0x004A0770

static int sub_0049D9A0_DrawTextBoxAt(T00479230* pTextBox, D2RectStrc* pRect); // 0x0049D9A0

int gnGlobal_007C0E60; // 0x007C0E60

inline void* operator new(unsigned int, void* pWhere) { return pWhere; }

struct D2QuestTextBufferStrc
{
    D2QuestTextBufferStrc();
};

// build: symbol ??0D2QuestTextBufferStrc@@QAE@XZ 0x004A4260

extern D2QuestTextBufferStrc data_007BF298; // 0x007BF298

D2RectStrc gaHoverRects_007BF0A8[16]; // 0x007BF0A8

unsigned long gdwTextEndTick_007BF1AC; // 0x007BF1AC

int gnGlobal_007BF1BC; // 0x007BF1BC

int gnGlobal_007BF1C0; // 0x007BF1C0

D2RectStrc gtHoverOffset_007BF214; // 0x007BF214

int gnHoverRectCount_007BF224; // 0x007BF224

int gbStarted_007BF27C; // 0x007BF27C

#define gbUpPressed_007C028C (gaPressed_007C0288[1])

#define gbDownPressed_007C0290 (gaPressed_007C0288[2])

#define KEYCFG_X ((gnScreenWidth_0071146C - 620) / 2)

#define KEYCFG_Y ((gnScreenHeight_007A521C - 420) / 2)

struct D2SliderButtonStrc;

struct D2KeyConfigButtonStrc;

#pragma pack(push, 1)

struct D2SliderButtonStrc
{
    unsigned short wStringId;
    unsigned char unk_02[8];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

#pragma pack(pop)

int __fastcall sub_00501820_GetTextWidth(const wchar_t* wszText); // 0x00501820

const wchar_t* __fastcall sub_00524A30_GetString(unsigned short wStringId); // 0x00524A30

extern D2SliderButtonStrc gaSliderButtons_007246D8[3]; // 0x007246D8

int gnScreenHeight_007A521C; // 0x007A521C

extern int gnSliderRows_007C0274; // 0x007C0274

extern int gnSliderOffset_007C0278; // 0x007C0278

extern int gnSliderScale_007C02AC; // 0x007C02AC

extern int gnSliderPos_007C02CC; // 0x007C02CC

#pragma pack(push, 2)

struct D2ClientListEntryStrc
{
    int nKey;
    unsigned short nString;
    unsigned char unk0x06[4];
};

struct D2KeyConfigButtonStrc
{
    unsigned short nString;
    unsigned char unk0x02[4];
    int nColor;
    int nX;
    unsigned char unk0x0E[0x0C];
};

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void __fastcall sub_00452E50_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __fastcall sub_00469D90(int nA, int nB); // 0x00469D90

const Unicode* __fastcall sub_00469DE0_GetKeyText(int nKey, int nArg2); // 0x00469DE0

void __cdecl sub_004A43E0(); // 0x004A43E0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

extern D2KeyConfigButtonStrc gaButtons_007246D8[3]; // 0x007246D8

extern int gaPressed_007C0288[7]; // 0x007C0288

extern int gnGlobal_007C02B0; // 0x007C02B0

extern int gnGlobal_007C02B8; // 0x007C02B8

extern void* gpCelFile_007C02BC; // 0x007C02BC

extern unsigned int gdwMessageTick_007C02C8; // 0x007C02C8

int gbRedraw_007C0280; // 0x007C0280

int gnHoverButton_007C02B4; // 0x007C02B4

int gnMessage_007C02C4; // 0x007C02C4

unsigned int gnBlink_007C02D0; // 0x007C02D0

int gnLastMouseY_007C02D4; // 0x007C02D4

int gnLastMouseX_007C02D8; // 0x007C02D8

// 0x0049AAA0
int __fastcall sub_0049AAA0_GetCenteredStringX(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - sub_00501820(wszText) / 2;
}

// 0x0049DC40
void __cdecl sub_0049DC40_DrawTextList()
{
    int i;
    int nLine;
    D2TextNodeStrc* pNode;
    T0044CB60* pNextLine;
    int nBaseY;
    int bSplit;
    int nOldFont;
    int nLineCount;
    int nX;
    int nWidth;
    int nY;
    T0044CB60* pTextLine;

    if (!gtTextList_007BF1E4.wCount)
    {
        return;
    }

    nOldFont = sub_00502EF0(0xD);
    pNode = gtTextList_007BF1E4.pFirst;
    nBaseY = 0x14;
    if (sub_004538D0(0x13))
    {
        nBaseY = 0x5F;
    }

    nX = 0xF;
    nLine = 0;
    bSplit = 0;
    switch (sub_0045AE90())
    {
    case 1:
        bSplit = 1;
        break;

    case 2:
        nX = gnGlobal_0071146C / 2 + 0xF;
        bSplit = 1;
        break;
    }

    for (; pNode; pNode = *(D2TextNodeStrc**)pNode->pNext)
    {
        for (i = 0; i < 6; ++i)
        {
            if (!pNode->pLines[i])
            {
                continue;
            }

            if (bSplit)
            {
                Unicode wszText[0x190];
                sub_005267E0(wszText, pNode->pLines[i]);
                pTextLine = sub_00502970_SplitText(wszText, &nLineCount, 0x12C);
                if (pTextLine)
                {
                    nY = 15 * nLine + nBaseY;
                    do
                    {
                        pNextLine = pTextLine->pNext;
                        nWidth = D2Win_10123(pTextLine->pText, sub_00526800(pTextLine->pText));
                        if (nWidth)
                        {
                            sub_0046EFD0_DrawFramedBox(nX - 5, nY - 0xE, nWidth + 0xA, 0x10, 0, 1);
                            sub_00502320(pTextLine->pText, nX, nY, *(int*)pNode->nColor, 0);
                            ++nLine;
                            nY += 0xF;
                        }
                        FOG_Free(pTextLine->pText, ".\\UI\\text.cpp", 0xA47, 0);
                        FOG_Free(pTextLine, ".\\UI\\text.cpp", 0xA48, 0);
                        pTextLine = pNextLine;
                    }
                    while (pTextLine);
                }
            }
            else
            {
                nWidth = D2Win_10123(pNode->pLines[i], sub_00526800(pNode->pLines[i]));
                if (nWidth)
                {
                    sub_0046EFD0_DrawFramedBox(nX - 4, 15 * nLine + nBaseY - 0xE, nWidth + 8, 0x10, 0, 1);
                    sub_00502320(pNode->pLines[i], nX, 15 * nLine + nBaseY, *(int*)pNode->nColor, 0);
                    ++nLine;
                }
            }
        }
    }

    pNode = gtTextList_007BF1E4.pFirst;
    D2TextNodeStrc* pPrevious = 0;
    const unsigned long dwTick = GetTickCount();
    while (pNode)
    {
        if (*(unsigned long*)pNode->dwEndTick < dwTick)
        {
            --gtTextList_007BF1E4.wCount;
            D2TextNodeStrc* pNext = *(D2TextNodeStrc**)pNode->pNext;
            if (gtTextList_007BF1E4.pFirst == pNode)
            {
                gtTextList_007BF1E4.pFirst = pNext;
            }
            for (int j = 0; j < 6; ++j)
            {
                if (pNode->pLines[j])
                {
                    FOG_Free(pNode->pLines[j], ".\\UI\\text.cpp", 0x6B3, 0);
                }
            }
            FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
            if (pPrevious)
            {
                *(D2TextNodeStrc**)pPrevious->pNext = pNext;
            }
            pNode = pNext;
        }
        else
        {
            pPrevious = pNode;
            pNode = *(D2TextNodeStrc**)pNode->pNext;
        }
    }

    sub_00502EF0(nOldFont);
}

// 0x0049E8F0
static int sub_0049E8F0_FormatPartyEvent(Unicode* pOut, D2GSPacketSrv5A* pPacket)
{
    D2StoredUnitRecordStrc* pRecord = sub_00479BB0_FindRecord(pPacket->dwParam);
    Unicode wszName[16];
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    char szName[16];
    if (pRecord)
        strcpy(szName, sub_004795C0_GetEntryName(pRecord));
    else
        szName[0] = 0;
    sub_00526F20_ToUnicode(wszName, szName, 16);
    switch (pPacket->nParam)
    {
    case 1:
        sub_005269D0(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277A), wszName);
        break;
    case 2:
        sub_005269D0(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277B), wszName);
        break;
    case 3:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBA));
        sub_004B9A00(16, 0, 0, 0, 0);
        return 1;
    case 4:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBB));
        return 1;
    case 5:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBC));
        break;
    case 6:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBD));
        break;
    case 7:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBE));
        break;
    case 8:
        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0xFBF));
        sub_00526700(pOut, wszName);
        break;
    case 9:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFC0));
        break;
    case 10:
        sub_005269D0(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277C), wszName);
        break;
    case 11:
        sub_005269D0(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277D), wszName);
        break;
    }
    if (pPlayer)
    {
        const int nPlayerId = pPlayer->dwUnitId;
        if (sub_004DC440(nPlayerId, sub_0047A0C0_GetRecordUnitId(pRecord), 4))
            return 0;
    }
    return 1;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0049EB10
void __fastcall sub_0049EB10_HandleEventMessage(D2GSPacketSrv5A* pPacket)
{
    Unicode wszBuffer[0x132];
    Unicode wszName[16];
    Unicode wszName2[16];
    if (strlen(pPacket->szTextData[0]) >= 15)
        pPacket->szTextData[0][15] = 0;
    switch (pPacket->nType)
    {
    case 10:
        if (pPacket->szTextData[0][0])
        {
            sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
            sub_005267E0(wszBuffer, wszName);
            sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0x1026));
            break;
        }
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0x1027));
        break;
    case 16:
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0x2A38));
        break;
    case 9:
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xFCF));
        break;
    case 8:
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xFCC));
        break;
    case 0:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE37)) < 0x104, 0x114C);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE37));
        break;
    case 1:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE38)) < 0x104, 0x1152);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE38));
        break;
    case 2:
        if (sub_00463DD0_GetPlayerUnit() && !strcmp(pPacket->szTextData[0], sub_0047A210(sub_00463DD0_GetPlayerUnit())))
            break;
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE39)) < 0x104, 0x115C);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        if (strlen(pPacket->szTextData[1]))
        {
            Unicode wszAccount[16];
            sub_00526F20_ToUnicode(wszAccount, pPacket->szTextData[1], 16);
            sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3B), wszName, wszAccount);
            break;
        }
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE39), wszName);
        break;
    case 3:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3A)) < 0x104, 0x116A);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        if (strlen(pPacket->szTextData[1]))
        {
            Unicode wszAccount[16];
            sub_00526F20_ToUnicode(wszAccount, pPacket->szTextData[1], 16);
            sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3C), wszName, wszAccount);
            break;
        }
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3A), wszName);
        break;
    case 4:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3D)) < 0x104, 0x1178);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE3D));
        break;
    case 13:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE44)) < 0x104, 0x117E);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE44));
        break;
    case 5:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3E)) < 0x104, 0x1184);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE3E));
        break;
    case 6:
    {
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        const Unicode* pKiller;
        int nStringId;
        int bFound = 0;
        switch (pPacket->nParam)
        {
        case 0:
            if (strlen(pPacket->szTextData[1]))
            {
                sub_00526F20_ToUnicode(wszName2, pPacket->szTextData[1], 16);
                nStringId = 0xE40;
                pKiller = wszName2;
                bFound = 1;
            }
            break;
        case 1:
            if (!pPacket->szTextData[1][0])
            {
                D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pPacket->dwParam);
                if (pMonStatsTxtRecord)
                {
                    nStringId = 0xE3F;
                    pKiller = D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr);
                    bFound = 1;
                }
            }
            else
            {
                unsigned short wSuperUnique = *(unsigned short*)pPacket->szTextData[1];
                nStringId = 0xE40;
                D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(wSuperUnique);
                if (pSuperUniquesTxtRecord)
                {
                    pKiller = D2LANG_GetStringFromTblIndex(pSuperUniquesTxtRecord->wNameStr);
                    bFound = 1;
                }
            }
            break;
        case 2:
        {
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pPacket->dwParam);
            if (pObjectsTxtRecord)
            {
                nStringId = 0xE3F;
                if (pPacket->dwParam == 11)
                    pKiller = D2LANG_GetStringFromTblIndex(0xC98);
                else
                    pKiller = (const Unicode*)pObjectsTxtRecord->wszName;
                bFound = 1;
            }
            break;
        }
        }
        if (!bFound)
        {
            sub_005267E0(wszBuffer, wszName);
            sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE41));
            break;
        }
        if (sub_00526800(D2LANG_GetStringFromTblIndex(nStringId)) + sub_00526800(pKiller) + 16 >= 0x132)
            return;
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(nStringId));
        sub_00526700(wszBuffer, pKiller);
        break;
    }
    case 7:
        if (sub_0049E8F0_FormatPartyEvent(wszBuffer, pPacket))
            sub_0049E5C0_PrintPartyText(wszBuffer, pPacket->nColor);
        return;
    case 11:
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x69B), wszName);
        break;
    case 15:
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE43), pPacket->dwParam);
        break;
    case 17:
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x2AFC), pPacket->dwParam);
        break;
    case 18:
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x2AFD));
        if (gpGlobal_007A0634)
            ENVIRONMENT_InitializeEnvironment(gpGlobal_007A0634, sub_004646A0_GetPlayerRoom(), 5, 0, 1);
        sub_00476A80_StartTiming(6, 0xFA0, 0x2710, 0xFA0);
        sub_004B9A00(0x1220, 0, 0, 0, 0);
        break;
    default:
        return;
    }
    sub_0049E3A0_PrintChatLine(wszBuffer, pPacket->nColor);
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
static bool sub_0049E280_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        Unicode::win2Unicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    const int nCurrentLangId = STRTABLE_GetLanguage();
    if (nCurrentLangId == nLangId)
        return true;
    if (nCurrentLangId == 7)
    {
        if (nLangId == 0xC)
            return true;
    }
    else if (nCurrentLangId == 0xC && nLangId == 7)
    {
        return true;
    }

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

// 0x0049F490
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

        if (IGNORELIST_GetOrCreateIgnoreList()->IGNORELIST_IsListed(szName))
            return;
        if (IGNORELIST_GetOrCreateIgnoreList()->sub_0060FC40_IsTextFiltered(pPacket->szMessage))
            return;
    }

    Unicode wszText[0x100];
    if (!sub_0049E280_ConvertHoverText(pPacket->nLang, wszText, pPacket->szMessage))
        return;
    wszText[0xFF].wChar = 0;

    if (pPacket->nMessageType == 4)
    {
        sub_0049E3A0_ShowChatText(wszText, pPacket->nMessageColor);
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
        sub_00452300_StripStringAndNextChar(wszA);
        sub_0049E3A0_ShowChatText(wszA, 2);
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
            sub_0049E3A0_ShowChatText(wszA, 2);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        sub_0049E3A0_ShowChatText(wszA, 2);
    }
    else if (pPacket->nMessageType == 1)
    {
        if (pPacket->nUnitType == 0 || pPacket->nUnitType == 1)
        {
            sub_0049E3A0_ShowChatText(wszText, pPacket->nMessageColor);
            return;
        }
        const int nNameLen = strlen(pPacket->szName);
        const int nTextLen = strlen(pPacket->szMessage);
        if (nNameLen >= 1 && nNameLen <= 15)
        {
            Unicode wszD[0x10];
            Unicode::win2Unicode(wszD, pPacket->szName, 0x10);
            sub_005267E0(wszA, wszD);
            sub_004521C0_PrefixLevelText(wszA, 4);
            sub_005267E0(wszB, D2LANG_GetStringFromTblIndex(0xFD0));
            Unicode::strcat(wszB, wszText);
            sub_004521C0_PrefixLevelText(wszB, 0);
            Unicode::strcat(wszA, wszB);
            sub_0049E3A0_ShowChatText(wszA, pPacket->nMessageColor);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        sub_0049E3A0_ShowChatText(wszA, pPacket->nMessageColor);
    }
    else if (pPacket->nMessageType == 5)
    {
        if (pUnit)
            sub_0049F410_SetHoverText(pPacket->nLang, pPacket->szMessage, pUnit);
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
        sub_0048BBE0_SetNameText(wszE, nLang, pPacket->nMessageColor);
    }
}

// build: context sub_0049D5A0_UpdateTextBox
// calling-convention shim (not game code)
static int __cdecl sub_0049D5A0_UpdateTextBox(T00479230* pTextBox)
{
    int nA = sub_004F59A0();
    int nB = sub_004F59A0();
    sub_00467430(nA);
    sub_00467430(nB);
    sub_00467430(nA);
    sub_00467430(nB);
    pTextBox->nScroll = 1;
    return *(char*)pTextBox;
}

static int __stdcall sub_004A0770(T00479230* pTextBox, int bIgnore)
{
    if (bIgnore)
    {
        pTextBox->nScroll = 2;
        return 0;
    }

    const int bBusy = sub_00514CC0();
    if (!gnHintSound_007BF24B || sub_004B95C0_IsHintPlaying((void*)gnHintSound_007BF24B) || !bBusy)
    {
        gnHintSound_007BF24B = 0;
        if (sub_0049D5A0_UpdateTextBox(pTextBox))
        {
            gnGlobal_007BF1BC = 1;
            if (!gdwGlobal_007BF20A && gpTextBox_007BF0A4)
            {
                sub_0049D410_FreeTextBox(gpTextBox_007BF0A4);
                gpTextBox_007BF0A4 = 0;
                sub_00467430(0);
            }

            sub_0049F960_ResetTextBox();
            if (gpfnTextCallback_007BF258)
            {
                return gpfnTextCallback_007BF258(gpTextCallbackContext_007BF25C, 0, 0);
            }

            if (gnGlobal_007BF1C4 == 1)
            {
                gnGlobal_007BF1C4 = 0;
            }
            else if (gdwGlobal_007BF20A)
            {
                sub_004B3D10_ReleaseTextUnit(gdwGlobal_007BF202);
            }

            sub_00453AE0();
            gdwGlobal_007BF20A = 0;
            sub_00467430(0);
            if (gbStarted_007BF27C == 1)
            {
                gbStarted_007BF27C = 0;
                sub_00451E10_UnregisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
            }

            return 0;
        }
    }

    return 1;
}

static int sub_0049D9A0_DrawTextBoxAt(T00479230* pTextBox, D2RectStrc* pRect)
{
    if (!pTextBox->nScroll)
        pTextBox->nScroll = 1;
    else if (pTextBox->nScroll == 3)
        return 1;

    switch (sub_0045AE90())
    {
    case 1:
        if (pRect->nLeft > gnGlobal_0071146C / 2 - 10)
            return 1;
        break;
    case 2:
        if (pRect->nLeft < gnGlobal_0071146C / 2 + 10)
            return 1;
        break;
    case 3:
        return 1;
    }
    sub_0049D8E0_DrawTextList(pTextBox, pRect->nLeft, pRect->nTop);
    return 1;
}

// 0x004A0E70
void __fastcall sub_004A0E70_UpdateTexts(D2ViewStrc* pView)
{
    D2RectStrc tViewRect;
    D2CoordStrc tViewPos;

    ++gnGameFrame_007BF20E;
    int nResult = 0;
    sub_00476070_GetViewRect(pView, &tViewRect.nLeft, &tViewRect.nTop, &tViewRect.nRight, &tViewRect.nBottom);
    sub_004760C0_GetViewOffset(pView, &tViewPos.nX, &tViewPos.nY);
    SetRect(&gtHoverOffset_007BF214, tViewPos.nX, tViewPos.nY, tViewPos.nX + tViewRect.nRight - tViewRect.nLeft, tViewPos.nY + tViewRect.nBottom - tViewRect.nTop);

    if (gnGlobal_007BF1C0 == 1)
    {
        gaHoverRects_007BF0A8[0].nLeft = gnGlobal_007BF278;
        gaHoverRects_007BF0A8[0].nRight = gnGlobal_007BF278 + 0x145;
        gaHoverRects_007BF0A8[0].nTop = gnGlobal_007225FC;
        gnHoverRectCount_007BF224 = 1;
        gaHoverRects_007BF0A8[0].nBottom = gnGlobal_007225FC + 0x70;
    }
    else
    {
        gnHoverRectCount_007BF224 = 0;
    }

    sub_00464950(sub_004A0B30_DrawUnitHoverText);
    sub_00464990(sub_004A0D20_DrawObjectHoverText);
    sub_004649D0(sub_004A0D20_DrawObjectHoverText);

    if (gnGlobal_007BF1C0 == 1 && gpTextBox_007BF0A4 && (gpTextBox_007BF0A4->nScroll == 1 || !gpTextBox_007BF0A4->nScroll))
    {
        nResult = sub_004A0770(gpTextBox_007BF0A4, gnGlobal_007BF1BC);

        D2UnitStrc* pUnit = 0;
        if (gdwGlobal_007BF20A)
        {
            pUnit = sub_00463990(gdwGlobal_007BF202, 1);
        }

        if (sub_00463DF0() || (gdwGlobal_007BF20A && pUnit && pUnit->dwAnimMode == 0x0C))
        {
            if (gdwGlobal_007BF20A)
            {
                sub_004786A0_SendDwords2(0x30, 1, gdwGlobal_007BF202);
                sub_004B3830_ClearNpcInventoryAndSound(gdwGlobal_007BF202);
            }

            sub_004A0880_CloseTextUnit();
            if (gbStarted_007BF27C == 1)
            {
                gbStarted_007BF27C = 0;
                sub_00451E10_UnregisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
            }
        }
    }

    if (gnGlobal_007BF1C4)
    {
        gnGlobal_007BF1C8 ? (void)0 : (sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xD02), exit(-1));
        int nDrawn = 1;
        (gdwTextEndTick_007BF1AC < GetTickCount()) ? (void)(nDrawn = 0) : (void)sub_0049D9A0_DrawTextBoxAt(gpTextBox_007BF1A8, &gtTextRect_007BF1D0);
        if (!nDrawn)
        {
            sub_0049E300_FreeMainTextBox();
            gnGlobal_007BF1C4 = 0;
            gdwGlobal_007BF20A = 0;
        }
        nResult += nDrawn;
    }

    if (!nResult && gnGlobal_007BF1C0 == 1)
    {
        gnGlobal_007BF1FA = 0;
        gdwGlobal_007BF20A = 0;
        gnGlobal_007BF1BC = 1;
        gnGlobal_007BF1C0 = 0;
        if (gbStarted_007BF27C == 1)
        {
            gbStarted_007BF27C = 0;
            sub_00451E10_UnregisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
        }
    }

    gnGlobal_007BF1BC = 0;
    if (!sub_004538D0(0x18))
    {
        sub_0049DC40_DrawTextList();
        sub_0049DEE0_DrawOverheadTextList();
    }

    if (gpListDialog_007BF1B0)
    {
        sub_004B8100_DrawDialog(gpListDialog_007BF1B0);
    }
}

static inline int sub_F08_ListTop()
{
    return (gnScreenHeight_007A521C - 0x1A4) / 2;
}

static inline int sub_F08_PanelLeft()
{
    return (gnScreenWidth_0071146C - 0x26C) / 2;
}

static inline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnScreenWidth_0071146C - sub_F08_PanelLeft() * 2);
}

static inline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static inline int sub_F08_ThumbHeight()
{
    return gnSliderOffset_007C0278 * 12;
}

static inline int sub_KEYCFG_Rows()
{
    return ((sub_F08_ListTop() + 0x16C) - (sub_F08_ListTop() + 0x28)) / 0x12;
}

static inline int sub_F08_VisibleLines()
{
    return sub_KEYCFG_Rows() - 3;
}

static inline int sub_F08_TrackSpan()
{
    return sub_KEYCFG_Rows() * 0x12 - sub_F08_ThumbHeight() - 0x4E;
}

static inline int sub_004A44C0_GetMaxFirstEntry()
{
    int nCount = gnSliderRows_007C0274;
    for (int i = 0; i < sub_F08_VisibleLines(); ++i)
    {
        if (--nCount <= 0)
            return 0;
    }
    return nCount;
}

// 0x004A5060
void __cdecl sub_004A5060_LayoutSlider()
{
    const int nOldFont = sub_00502EF0_SetFont(13);
    for (unsigned int i = 0; i < 3; ++i)
    {
        const int nWidth = sub_00501820_GetTextWidth(sub_00524A30_GetString(gaSliderButtons_007246D8[i].wStringId));
        const int nThird = (sub_F08_PanelRight() - sub_F08_PanelLeft()) / (sizeof(gaSliderButtons_007246D8) / sizeof(gaSliderButtons_007246D8[0]));
        gaSliderButtons_007246D8[i].nLeft = nThird * i + sub_F08_PanelLeft() + nThird / 2 - nWidth / 2 - 10;
        gaSliderButtons_007246D8[i].nRight = nThird * i + sub_F08_PanelLeft() + nThird / 2 + nWidth / 2 + 10;
        gaSliderButtons_007246D8[i].nTop = sub_F08_ListTop() + 0x149;
        gaSliderButtons_007246D8[i].nBottom = sub_F08_ListTop() + 0x16F;
    }
    sub_00502EF0_SetFont(nOldFont);

    gnSliderPos_007C02CC = sub_F08_TrackSpan() * gnSliderScale_007C02AC / sub_004A44C0_GetMaxFirstEntry() + sub_F08_TrackTop();
}

static int sub_004A4FA0_GetEntryState(int nIndex, int nFlag)
{
    if (nIndex == gnGlobal_007C02B0 && (gnGlobal_007C02B8 || nFlag == gnGlobal_007246D4))
    {
        return 3;
    }

    if (!sub_00469D90(gpListEntries_00724264[nIndex].nKey, 1) && !sub_00469D90(gpListEntries_00724264[nIndex].nKey, 0))
    {
        return 1;
    }

    return sub_00469D90(gpListEntries_00724264[nIndex].nKey, nFlag) ? 4 : 5;
}

static inline int sub_KEYCFG_VisibleLines()
{
    return ((KEYCFG_Y + 0x136) - (KEYCFG_Y + 0x28)) / 0x12;
}

static inline int sub_KEYCFG_ListTop()
{
    return (gnScreenHeight_007A521C - 0x1A4) / 2;
}

static inline int sub_KEYCFG_PanelRight()
{
    return KEYCFG_X + (gnScreenWidth_0071146C - KEYCFG_X * 2);
}

static inline int sub_KEYCFG_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_KEYCFG_PanelRight() - 0x1F && nX <= sub_KEYCFG_PanelRight() - 0x12)
    {
        const int nTop = sub_KEYCFG_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

static inline int sub_KEYCFG_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_KEYCFG_PanelRight() - 0x1F && nX <= sub_KEYCFG_PanelRight() - 0x12)
    {
        const int nTop = sub_KEYCFG_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}

static inline int sub_KEYCFG_TrackCels()
{
    return ((KEYCFG_Y + 0x131) - (KEYCFG_Y + 0x2F)) / 0x0C;
}

// 0x004A5270
void __cdecl sub_004A5270()
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    sub_004A43E0();
    if (gnLastMouseX_007C02D8 != nMouseX || gnLastMouseY_007C02D4 != nMouseY || gbRedraw_007C0280)
    {
        gnLastMouseX_007C02D8 = nMouseX;
        gnLastMouseY_007C02D4 = nMouseY;
        sub_004A4AD0_Press(nMouseX, nMouseY);
    }

    const int nOldFont = sub_00502EF0_SetFont(13);
    sub_0046EFD0_DrawFramedBox(KEYCFG_X, KEYCFG_Y, gnScreenWidth_0071146C - 2 * KEYCFG_X, (KEYCFG_Y + 0x171) - KEYCFG_Y, 0, 1);

    D2RectStrc tRect;
    tRect.nLeft = KEYCFG_X;
    tRect.nTop = KEYCFG_Y + 3;
    tRect.nRight = gnScreenWidth_0071146C - KEYCFG_X - 3;
    tRect.nBottom = KEYCFG_Y + 0x170;
    sub_00452E50_DrawRectangleBorder(&tRect);
    tRect.nTop = KEYCFG_Y + 0x143;
    sub_00452E50_DrawRectangleBorder(&tRect);

    sub_00502320(D2LANG_GetStringFromTblIndex(0xF51), KEYCFG_X + 0x12, KEYCFG_Y + 0x1E, 4, 0);
    sub_00502320(D2LANG_GetStringFromTblIndex(0xF52), KEYCFG_X + 0x12 + (gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3, KEYCFG_Y + 0x1E, 4, 0);
    sub_00502320(D2LANG_GetStringFromTblIndex(0xF53), KEYCFG_X + 0x12 + 2 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), KEYCFG_Y + 0x1E, 4, 0);

    int i = 0;
    while (i < sub_KEYCFG_VisibleLines() && i < gnSliderRows_007C0274)
    {
        int nY = i * 0x12 + KEYCFG_Y + 0x22;
        int nIndex = gnSliderScale_007C02AC + i;
        int bVisible;
        if (gnGlobal_007C02B8 && nIndex == gnGlobal_007C02B0 && (gnBlink_007C02D0 & 0xF) <= 4)
            bVisible = 0;
        else
            bVisible = 1;

        ++i;

        if (gpListEntries_00724264[nIndex].nKey == 0x39)
            continue;

        if (nIndex == gnGlobal_007C02B0)
        {
            sub_0046EFD0_DrawFramedBox(KEYCFG_X + 0x12, nY + 1, 3 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), 0x12, 0, 1);
            sub_00502320(D2LANG_GetStringFromTblIndex(gpListEntries_00724264[nIndex].nString), KEYCFG_X + 0x1E, nY + 0x12, gnGlobal_007C02B8 ? 3 : 0, 0);
        }
        else
        {
            sub_00502320(D2LANG_GetStringFromTblIndex(gpListEntries_00724264[nIndex].nString), KEYCFG_X + 0x1E, nY + 0x12, 0, 0);
        }

        if (bVisible || !gnGlobal_007246D4)
        {
            sub_00502320(sub_00469DE0_GetKeyText(gpListEntries_00724264[nIndex].nKey, 1), KEYCFG_X + 0x1E + (gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3, nY + 0x12, sub_004A4FA0_GetEntryState(nIndex, 1), 0);
        }

        if (bVisible || gnGlobal_007246D4)
        {
            sub_00502320(sub_00469DE0_GetKeyText(gpListEntries_00724264[nIndex].nKey, 0), KEYCFG_X + 0x1E + 2 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), nY + 0x12, sub_004A4FA0_GetEntryState(nIndex, 0), 0);
        }
    }

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = gpCelFile_007C02BC;
    tCel.nFrame = 13;
    for (int j = 0; j < sub_KEYCFG_TrackCels(); ++j)
        sub_004F6480(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + 0x3B + j * 0x0C, -1, 5, 0);

    tCel.nFrame = 14;
    for (int k = 0; k < gnSliderOffset_007C0278; ++k)
        sub_004F6480(&tCel, sub_KEYCFG_PanelRight() - 0x20, gnSliderPos_007C02CC + 0x0C + k * 0x0C, -1, 5, 0);

    if (gbUpPressed_007C028C && sub_KEYCFG_IsOnUpArrow(nMouseX, nMouseY))
        tCel.nFrame = 9;
    else
        tCel.nFrame = 11;
    sub_004F6480(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + 0x2F, -1, 5, 0);

    if (gbDownPressed_007C0290 && sub_KEYCFG_IsOnDownArrow(nMouseX, nMouseY))
        tCel.nFrame = 8;
    else
        tCel.nFrame = 10;
    sub_004F6480(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) - 0x40, -1, 5, 0);

    for (unsigned int m = 0; m < 3; ++m)
    {
        int nColor;
        if (m == gnHoverButton_007C02B4)
            nColor = gaButtons_007246D8[m].nColor;
        else
            nColor = 4;
        sub_00502320(D2LANG_GetStringFromTblIndex(gaButtons_007246D8[m].nString), gaButtons_007246D8[m].nX + 10, KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) - 0x12, nColor, 0);
    }

    if (GetTickCount() < gdwMessageTick_007C02C8 + 2000)
    {
        const int nCenterX = gnScreenWidth_0071146C / 2;
        const int nTextY = KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) + 0x1E;
        const int nTextX = nCenterX - sub_00501820(D2LANG_GetStringFromTblIndex(gnMessage_007C02C4)) / 2;
        sub_00502320(D2LANG_GetStringFromTblIndex(gnMessage_007C02C4), nTextX, nTextY, 1, 1);
    }

    sub_00502EF0_SetFont(nOldFont);
    ++gnBlink_007C02D0;
}

// 0x004B9010
void __fastcall sub_004B9010_SetNameFromPacket(D2NamePacketStrc* pPacket)
{
    char szName[16];
    memcpy(szName, pPacket->szName, 16);
    szName[15] = 0;
    sub_00526F20_ToUnicode(gwszName_007C0E84, szName, 16);
    gnGlobal_007C0E60 = *(int*)pPacket->nValue;
}

// 0x004BE410
void ListBoxImplementation::sub_004BE410_DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor)
{
    Unicode wszText[1024];
    sub_005267E0(wszText, wszSource);
    if (D2Win_10123(wszText, sub_00526800(wszText)) < nTextWidth - 0x32)
    {
        sub_00502320(wszText, nX, nY, nColor, 0);
        return;
    }

    while (D2Win_10123(wszText, sub_00526800(wszText)) > nTextWidth - 0x32)
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
    sub_00502320(wszText, nX, nY, nColor, 0);
}

// 0x004E48B0
void __fastcall sub_004E48B0_BuildText(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused)
{
    Unicode wszText[0x80];
    const Unicode* wszA = D2LANG_GetStringFromTblIndex(0xFA2);
    const Unicode* wszB = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* wszC = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* wszD = D2LANG_GetStringFromTblIndex(0xFA1);
    Unicode wszNumber[10];
    char szNumber[10];
    SStrPrintf(szNumber, 10, szIntFormat_006D6454, 0x32);
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszA);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszD);
    sub_00526700(wszText, wszC);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xDE2));
    sub_00526700(wszText, wszB);
    sub_00526700(wszOut, wszText);
}

// 0x004E6720
void __fastcall sub_004E6720_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4)
{
    sub_0065FEC0_ItemApplyProps(5, 0, pItem, nArg, nArg2, 0);
    Unicode wszBuffer[1024];
    wszBuffer[0].wChar = 0;
    sub_004E6410_BuildPropText(pItem, wszBuffer, nArg3, 1, nArg4);
    sub_00526700(wszText, wszBuffer);

    D2StatListStrc* pStatList = sub_00625790_UnitFindStatList(pItem, 0, 0x40);
    if (pStatList)
    {
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    if (wszText[sub_00526800(wszText) - 1].isNewline())
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
}

// 0x004ED3F0
void __stdcall sub_004ED3F0_DrawHintText(int nArg1, int nStringIndex)
{
    Unicode wszText[100];
    sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(0x1058), nArg1);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    D2Win_10129_DrawFramedText(wszText, gnGlobal_0071146C - 0x80, gnGlobal_00711470 - 0x34, 0, 1);
}

// 0x006CACD0
void __cdecl sub_006CACD0_InitQuestTextBuffer()
{
    new (&data_007BF298) D2QuestTextBufferStrc;
}

#include "gen/data/Source/D2Client/UI/text_0049DC40.inc"
