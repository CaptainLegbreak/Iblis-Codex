#include "D2Client.h"
#include "D2Primitives.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2MsgHandlerEntryStrc;
struct Unicode;
struct D2RectStrc;
struct T00479230;
struct D2TextNodeStrc;
struct D2TextListStrc;
struct D2StringSoundStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void __cdecl GAME_ResetMouseState(); // 0x0044DA40
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
void __fastcall COMCALLBACK_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0
void __fastcall CUNIT_SetDialogState(int nState); // 0x004898D0
void __cdecl TEXT_InitKeyConfigEntries(); // 0x004A43E0
void __cdecl DIALOG_LoadDialogHotkeys(); // 0x004B7C60
int __cdecl WINDOW_GetWindow(); // 0x004F59A0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool); // 0x0065C430
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern D2MsgHandlerEntryStrc gaDialogWheelHandlers[]; // 0x007273E4
extern D2MsgHandlerEntryStrc gaDialogHandlers[]; // 0x007273F0
extern const char* gaszDialogCels[]; // 0x007274AC
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern void* gpWaypointBackgroundCel; // 0x007BF071
extern void* gpWaypointActTabsCel; // 0x007BF075
extern void* gpWaypointIconCel; // 0x007BF079
extern void* gpTextPanelFrameCel; // 0x007BF274
extern int gnGlobal_007C02AC; // 0x007C02AC
extern int gnKeyConfigSelected; // 0x007C02B0
extern void* gpKeyConfigSliderCel; // 0x007C02BC
extern void* gpGlobal_007C0D43; // 0x007C0D43
extern int gbWaitSoundPlayed; // 0x007C0DBC
extern int gbWaitSoundScheduled; // 0x007C0DC0
extern void* gpBuySellCel; // 0x007C0DC8
extern void* gpGoldBtnCel; // 0x007C0DCC
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

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest);
extern "C" __declspec(dllimport) int __stdcall IntersectRect(D2RectStrc* pDest, const D2RectStrc* pSrc1, const D2RectStrc* pSrc2);
extern "C" int __cdecl atoi(const char* szString);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __cdecl sub_0045AE90();
void __fastcall TEXT_DrawTextList(T00479230* pTextBox, int nX, int nY); // 0x0049D8E0
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
T0044CB60* __fastcall sub_00502970_SplitText(const Unicode* pText, int* pLineCount, int nWidth);
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __cdecl sub_00525150();
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);
void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0
unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x006611D0
unsigned char __stdcall CHAT_GetLangIdFromHoverMsg(D2HoverTextStrc* pHoverMsg);
// build: symbol ?gaHoverDirs@* 0x00722654
extern int gaHoverDirs[];
// build: symbol ?gnHoverDirCount@* 0x00722674
extern int gnHoverDirCount;
// build: symbol ?gaHoverRects@* 0x007BF0A8
extern D2RectStrc gaHoverRects[16];
extern int gnGameFrame; // 0x007BF20E
extern D2CoordStrc gtHoverOffset; // 0x007BF214
extern int gnHoverRectCount; // 0x007BF224

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

#pragma pack(pop)

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0
int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
extern D2TextListStrc gtOverheadTextList; // 0x007BF1EA

struct D2StringSoundStrc
{
    unsigned short wStringId;
    unsigned short wSoundId;
};

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" const char gszFormatD[]; // 0x006D57BC
extern "C" const char gszFormatSound[]; // 0x006DA194
extern D2StringSoundStrc* gapClassStringSounds[]; // 0x00722F1C
extern D2StringSoundStrc gaMonStringSounds[]; // 0x00723750

static void __stdcall TEXT_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos); // 0x004A0A00

char gabNpcMenuState[1]; // 0x007C0C68

static int gnDialogHandlerRegCount; // 0x007C0E4C

static D2ClientDialogStrc* gpDialogList; // 0x007C0E54

static int gbDialogHandlersRegistered; // 0x007C0E58

static int gnDialogCount; // 0x007C0E5C

// 0x0049C580
void __cdecl TEXT_LoadWaypointPanelCels()
{
    char szPath[0x104];
    if (!gpWaypointBackgroundCel)
    {
// build: symbol ?gszDataGlobal@* 0x006D4118
        sprintf(szPath, "%s\\ui\\menu\\waygatebackground", gszDataGlobal);
        gpWaypointBackgroundCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gpWaypointActTabsCel)
    {
// build: symbol ?FOG_IsExpansion@* 0x00408F20
        if (FOG_IsExpansion() && GAME_IsExpansion())
        {
            sprintf(szPath, "%s\\ui\\menu\\expwaygatetabs", gszDataGlobal);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\waygatetabs", gszDataGlobal);
        }
        gpWaypointActTabsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    if (!gpWaypointIconCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\waygateicons", gszDataGlobal);
        gpWaypointIconCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

struct Archive;

extern "C" void __fastcall sub_00478A00_CloseArchive(Archive* archive);

extern "C" Archive* gArchiveA; // 0x007BF071

extern "C" Archive* gArchiveB; // 0x007BF075

extern "C" Archive* gArchiveC; // 0x007BF079

D2WaypointDataStrc* __stdcall WAYPOINTS_AllocWaypointData(void* pMemPool); // 0x00660F30

extern char gbSent; // 0x007BF085

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __stdcall WAYPOINTS_FreeWaypointData(void* pMemPool, D2WaypointDataStrc* pData); // 0x00660FD0

extern "C" void __cdecl sub_0049C650_CloseArchives(); // 0x0049C650

char gbSent; // 0x007BF085

// 0x0049C650
extern "C" void __cdecl sub_0049C650_CloseArchives()
{
    if(gArchiveA) {
        sub_00478A00_CloseArchive(gArchiveA);
        gArchiveA=(Archive*)0;
    }
    if(gArchiveB) {
        sub_00478A00_CloseArchive(gArchiveB);
        gArchiveB=(Archive*)0;
    }
    if(gArchiveC) {
        sub_00478A00_CloseArchive(gArchiveC);
        gArchiveC=(Archive*)0;
    }
}

// 0x0049C6A0
void __cdecl sub_0049C6A0()
{
// build: symbol ?gpWaypointData@* 0x007BF081
    gpWaypointData = WAYPOINTS_AllocWaypointData(0);
    gbSent = 0;
}

// 0x0049C6C0
void __cdecl sub_0049C6C0_SendWaypointClose()
{
    if (!gbSent && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
    {
// build: symbol ?gnWaypointId@* 0x007BF07D
        MSG_SendTwoDwords(0x49, gnWaypointId, 0);
        gbSent = 1;
    }
}

// 0x0049C700
void __cdecl sub_0049C700_CloseWaypointPanel()
{
    sub_0049C6C0_SendWaypointClose();
    if (gpWaypointData)
        WAYPOINTS_FreeWaypointData(0, gpWaypointData);
    gpWaypointData = 0;
    sub_0049C650_CloseArchives();
}

// 0x0049CF50
void __cdecl sub_0049CF50_SendWaypointClose()
{
    if (!gbSent && sub_00463DD0_GetPlayerUnit() && UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))
    {
        MSG_SendTwoDwords(0x49, gnWaypointId, 0);
        gbSent = 1;
    }
}

// 0x0049FA10
void __cdecl TEXT_DrawPanelFrame()
{
    char szPath[0x104];
    D2CelContextStrc tContext;

    D2GFX_DrawBox(gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, gnScreenWidth / 2, gnScreenHeight - 0x30, 0, 5);

    void* pCelFile = gpTextPanelFrameCel;
    if (!pCelFile)
    {
        wsprintfA(szPath, "%s\\UI\\MENU\\scroin", gszDataGlobal);
        pCelFile = ARCHIVE_LoadClientCellFile(szPath, 0);
        gpTextPanelFrameCel = pCelFile;
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCelFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x6D, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x6D, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x31, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x31, -1, 5, 0);
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = 10;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x115, gnScreenHeight + gnPanelOffsetY - 0x3D, -1, 5, 0);
}

// 0x004A23D0
void __cdecl TEXT_LoadQuestPanelCels()
{
    char szPath[0x104];
    if (sub_00483350())
    {
        return;
    }
// build: symbol ?gpQuestBackgroundCel@* 0x007BF2D5
    if (!gpQuestBackgroundCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questbackground", gszDataGlobal);
        gpQuestBackgroundCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestTabsCel@* 0x007BF2D9
    if (!gpQuestTabsCel)
    {
        if (FOG_IsExpansion() && GAME_IsExpansion())
        {
            sprintf(szPath, "%s\\ui\\menu\\expquesttabs", gszDataGlobal);
        }
        else
        {
            sprintf(szPath, "%s\\ui\\menu\\questtabs", gszDataGlobal);
        }
        gpQuestTabsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestSocketsCel@* 0x007BF2D1
    if (!gpQuestSocketsCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questsockets", gszDataGlobal);
        gpQuestSocketsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestDoneCel@* 0x007BF2DD
    if (!gpQuestDoneCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questdone", gszDataGlobal);
        gpQuestDoneCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpInvPsCel@* 0x007BF351
    if (!gpInvPsCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\invps", gszDataGlobal);
        gpInvPsCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
// build: symbol ?gpQuestLastCel@* 0x007BF34D
    if (!gpQuestLastCel)
    {
        sprintf(szPath, "%s\\ui\\menu\\questlast", gszDataGlobal);
        gpQuestLastCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
}

// 0x004A5190
void __cdecl TEXT_InitTextSlider()
{
    char szPath[0x104];
    TEXT_InitKeyConfigEntries();
    sprintf(szPath, "%s\\UI\\Menu\\TextSlid", gszDataGlobal);
    gpKeyConfigSliderCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    sub_004A5060();
    gnGlobal_007C02AC = 0;
    gnKeyConfigSelected = 0;
}

// 0x004B23E0
void __cdecl TEXT_InitNpcMenu()
{
    char szPath[0x104];
    gbWaitSoundScheduled = 0;
    gbWaitSoundPlayed = 0;
    GetTickCount();
    memset(gabNpcMenuState, 0, 0x160);
    gpGlobal_007C0D43 = QUESTRECORD_AllocRecord(0);
    gpGlobal_007C0D47 = QUESTRECORD_AllocRecord(0);
// build: symbol ?gnNpcMenuState@* 0x007C0C6B
    gnNpcMenuState = 0;
    sprintf(szPath, "%s\\ui\\panel\\buysell", gszDataGlobal);
    gpBuySellCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    sprintf(szPath, "%s\\ui\\menu\\goldbtn", gszDataGlobal);
    gpGoldBtnCel = ARCHIVE_LoadClientCellFile(szPath, 0);
// build: symbol ?gnTradeRequestFailCount@* 0x007C0DED
    gnTradeRequestFailCount = 0;
// build: symbol ?gbTradeClickPending@* 0x007C0DE0
    gbTradeClickPending = 0;
// build: symbol ?gdwLastTradeSendTick@* 0x007C0DF1
    gdwLastTradeSendTick = 0;
// build: symbol ?gdwTradeRequestTick@* 0x007C0DE9
    gdwTradeRequestTick = 0;
}

#include "gen/data/Source/D2Client/UI/text_0049C580.inc"
struct D2BitBufferStrc;
struct D2CelFileStrc;

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0049D370
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

// 0x0049D3C0
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

// 0x0049D410
void __stdcall TEXT_FreeTextBox(T00479230* pTextBox)
{
    if (pTextBox)
    {
        TEXT_FreeTextLines(pTextBox->pFirst);
        FOG_Free(pTextBox, ".\\UI\\text.cpp", 0x68E, 0);
    }
}

// 0x0049D9A0
static int TEXT_DrawTextBoxAt(T00479230* pTextBox, D2RectStrc* pRect)
{
    if (!pTextBox->nScroll)
        pTextBox->nScroll = 1;
    else if (pTextBox->nScroll == 3)
        return 1;

    switch (sub_0045AE90())
    {
    case 1:
        if (pRect->nLeft > gnScreenWidth / 2 - 10)
            return 1;
        break;
    case 2:
        if (pRect->nLeft < gnScreenWidth / 2 + 10)
            return 1;
        break;
    case 3:
        return 1;
    }
    TEXT_DrawTextList(pTextBox, pRect->nLeft, pRect->nTop);
    return 1;
}

// build: symbol ?TEXT_PlaceHoverRect@* 0x0049E070
static bool __stdcall TEXT_PlaceHoverRect(int nCount, D2RectStrc* pRect)
{
    if (nCount >= 0x10)
        return false;

    if (!nCount)
    {
        gaHoverRects[0] = *pRect;
        return true;
    }

    for (int i = 0; i < nCount; ++i)
    {
        D2RectStrc tOverlap;
        if (IntersectRect(&tOverlap, &gaHoverRects[i], pRect))
        {
            for (int nDX = 0x32; nDX < 0x190; nDX += 0x32)
            {
                for (int nDY = 0x23; nDY < 0x118; nDY += 0x23)
                {
                    for (int nDir = 0; nDir < gnHoverDirCount; ++nDir)
                    {
                        D2RectStrc tRect = *pRect;
                        tRect.nLeft += gaHoverDirs[nDir] * nDX;
                        tRect.nTop += gaHoverDirs[nDir] * nDY;
                        tRect.nRight = tRect.nLeft + 0x190;
                        tRect.nBottom = tRect.nTop + 0x118;
                        if (tRect.nLeft < 0 || tRect.nRight > gnScreenWidth || tRect.nTop < 0 || tRect.nBottom > gnScreenHeight)
                            continue;

                        bool bOverlap = false;
                        for (int j = 0; j < nCount; ++j)
                        {
                            if (IntersectRect(&tOverlap, &gaHoverRects[j], &tRect))
                                bOverlap = true;
                        }
                        if (!bOverlap)
                        {
                            gaHoverRects[nCount] = tRect;
                            *pRect = tRect;
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    }

    gaHoverRects[nCount] = *pRect;
    return true;
}

// build: symbol ?TEXT_ConvertHoverText@* 0x0049E280
static bool TEXT_ConvertHoverText(Unicode* wszText, const char* szText, int nLangId)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        sub_00526F20_ToUnicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    const int nCurrentLangId = sub_00525150();
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

    for (const Unicode* pChar = wszText; pChar->wChar; ++pChar)
    {
        if (pChar->wChar >= 0x80)
            return false;
    }
    return true;
}

void __fastcall TEXT_DrawUnitHoverText(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
        return;

    D2CoordStrc tPos;
    UNITS_GetClientCoords(pUnit, &tPos);
    tPos.nX -= gtHoverOffset.nX;
    tPos.nY += -0x1E - gtHoverOffset.nY;
    switch (sub_0045AE90())
    {
    case 1:
        tPos.nX -= gnScreenWidth / 4;
        break;
    case 2:
        tPos.nX += gnScreenWidth / 4;
        break;
    case 3:
        return;
    }

    if (tPos.nY <= 0 || tPos.nY >= gnScreenHeight)
        return;
    if (tPos.nX <= -0x64 || tPos.nX >= gnScreenWidth + 0x64)
        return;

    char szText[0x100];
    CHAT_CopyHoverMsgToBuffer(pHoverText, szText);
    if (szText[0] == -1 && szText[1] == -1)
    {
        const int nStringId = atoi(&szText[2]);
        if ((nStringId >= 0x42D && nStringId <= 0x50F) || (nStringId >= 0x5587 && nStringId <= 0x5615)
            || nStringId == 0x2AA4 || nStringId == 0x5586)
        {
            const Unicode* wszString = D2LANG_GetStringFromTblIndex(nStringId);
            if (wszString)
            {
                Unicode wszBuffer[0xC8];
                memset(wszBuffer, 0, sizeof(wszBuffer));
                int nLength = sub_00526800(wszString);
                if (nLength >= 0xC8)
                    nLength = 0xC7;
                sub_00526790(wszBuffer, wszString, nLength);
                TEXT_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
                return;
            }
        }
    }

    Unicode wszHover[0x100];
    if (!TEXT_ConvertHoverText(wszHover, szText, CHAT_GetLangIdFromHoverMsg(pHoverText)))
        return;
    wszHover[0xFF].wChar = 0;
    TEXT_ShowHoverText(wszHover, pUnit, pHoverText, &tPos);
}

// 0x004A0D20
void __fastcall TEXT_DrawObjectHoverText(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
        return;

    D2CoordStrc tPos;
    UNITS_GetClientCoords(pUnit, &tPos);
    tPos.nY += -0x0A - gtHoverOffset.nY;
    tPos.nX -= gtHoverOffset.nX;
    switch (sub_0045AE90())
    {
    case 1:
        tPos.nX -= gnScreenWidth / 4;
        break;
    case 2:
        tPos.nX += gnScreenWidth / 4;
        break;
    case 3:
        return;
    }

    if (tPos.nY <= 0 || tPos.nY >= gnScreenHeight)
        return;
    if (tPos.nX <= -0x64 || tPos.nX >= gnScreenWidth + 0x64)
        return;

    char szText[0x100];
    CHAT_CopyHoverMsgToBuffer(pHoverText, szText);
    const int nStringId = atoi(szText);
    if (nStringId < 1 || nStringId > 0xFFFE)
        return;

    const Unicode* wszString = D2LANG_GetStringFromTblIndex(nStringId);
    if (!wszString)
        return;

    Unicode wszBuffer[0xC8];
    memset(wszBuffer, 0, sizeof(wszBuffer));
    int nLength = sub_00526800(wszString);
    if (nLength >= 0xC8)
        nLength = 0xC7;
    sub_00526790(wszBuffer, wszString, nLength);
    TEXT_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
}

// 0x0049DEE0
void __cdecl TEXT_DrawOverheadTextList()
{
    if (!gtOverheadTextList.wCount)
    {
        return;
    }

    int nOldFont = D2Win_10127_SetFont(13);
    D2TextNodeStrc* pNode = gtOverheadTextList.pFirst;
    int nX = 15;
    if (GAME_GetUIVarState(6) || GAME_GetUIVarState(0x11))
    {
        nX = 100;
    }

    if (pNode)
    {
        int nBoxRow = 0;
        int nTextRow = 0;
        do
        {
            for (int i = 0; i < 6; ++i)
            {
                if (pNode->pLines[i])
                {
                    AUTOMAP_DrawFramedBox(nX - 5, gnScreenHeight - 25 * nBoxRow - i * 25 / 2 - 0x81,
                                               D2Win_10123(pNode->pLines[i], sub_00526800(pNode->pLines[i])) + 10, 0x10, 0, 1);
                    D2Win_10117_DrawText(pNode->pLines[i], nX, gnScreenHeight + 25 * nTextRow - i * 25 / 2 - 0x73, pNode->nColor, 0);
                }
            }
            pNode = pNode->pNext;
            ++nBoxRow;
            --nTextRow;
        }
        while (pNode);
    }

    pNode = gtOverheadTextList.pFirst;
    D2TextNodeStrc* pPrev = 0;
    unsigned int dwNow = GetTickCount();
    while (pNode)
    {
        if (pNode->dwEndTick < dwNow)
        {
            --gtOverheadTextList.wCount;
            D2TextNodeStrc* pNext = pNode->pNext;
            if (gtOverheadTextList.pFirst == pNode)
            {
                gtOverheadTextList.pFirst = pNext;
            }

            for (int j = 0; j < 6; ++j)
            {
                if (pNode->pLines[j])
                {
                    FOG_Free(pNode->pLines[j], ".\\UI\\text.cpp", 0x6B3, 0);
                }
            }
            FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);

            if (pPrev)
            {
                pPrev->pNext = pNext;
            }
            pNode = pNext;
        }
        else
        {
            pPrev = pNode;
            pNode = pNode->pNext;
        }
    }

    D2Win_10127_SetFont(nOldFont);
}

// 0x0049F410
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

// 0x004A0200
void __fastcall TEXT_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId)
{
    char szText[12];

    if (!pUnit)
        return;

    const int nLangId = sub_00525150();
    if (nLangId < 6)
        return;
    if (nLangId > 7 && nLangId != 9)
        return;
    if (nStringId < 0xB76 || nStringId > 0x1230)
        return;

    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == 0)
    {
        const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
        D2StringSoundStrc* pTable = gapClassStringSounds[nClassId];
        for (unsigned int i = 0; i < 0x4A; ++i)
        {
            if (pTable[i].wStringId == nStringId)
            {
                sprintf(szText, gszFormatSound, -1, -1, pTable[i].wSoundId);
                TEXT_SetHoverText(sub_00525150(), szText, pUnit);
                return;
            }
        }
    }
    else if (nUnitType == 1)
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            if (gaMonStringSounds[i].wStringId == nStringId)
            {
                sprintf(szText, gszFormatD, gaMonStringSounds[i].wSoundId);
                TEXT_SetHoverText(sub_00525150(), szText, pUnit);
                return;
            }
        }
    }
}

// 0x004A0A00
static void __stdcall TEXT_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos)
{
    if (gnGameFrame > CHAT_GetTimeoutFromHoverMsg(pHoverText))
    {
        CHAT_FreeHoverMsg(0, pHoverText);
        if (pUnit)
            pUnit->pHoverText = 0;
    }

    const int nOldFont = D2Win_10127_SetFont(0x0D);
    T00479230* pTextBox = (T00479230*)FOG_Alloc(sizeof(T00479230), ".\\UI\\text.cpp", 0x65D, 0);
    pTextBox->pFirst = sub_00502970_SplitText(wszText, &pTextBox->nLines, 0xB4);
    TEXT_MeasureTextBox(pTextBox);

    pPos->nX -= pTextBox->nWidth >> 1;
    pPos->nY -= 0x32;
    pPos->nY = pPos->nY - pTextBox->nLines * 0x0F - 3;

    D2RectStrc tRect;
    tRect.nTop = pPos->nY;
    tRect.nLeft = pPos->nX;
    tRect.nBottom = pTextBox->nHeight + pPos->nY;
    tRect.nRight = pTextBox->nWidth + pPos->nX;
    if (gnHoverRectCount < 0x10 && !TEXT_PlaceHoverRect(gnHoverRectCount, &tRect))
    {
        TEXT_FreeTextBox(pTextBox);
        return;
    }

    ++gnHoverRectCount;
    TEXT_DrawTextBoxAt(pTextBox, &tRect);
    TEXT_FreeTextBox(pTextBox);
    D2Win_10127_SetFont(nOldFont);
}
