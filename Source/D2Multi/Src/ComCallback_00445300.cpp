#include "D2Multi.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinEditBoxStrc;
struct D2WinButtonStrc;
struct SMSGHANDLER_PARAMS;
struct D2ChannelEntryStrc;
struct D2MultiChannelUserStrc;
struct D2MsgRecordStrc;
struct D2MsgRecordChunkStrc;
struct D2MsgHandlerEntryStrc;

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

struct D2MsgRecordStrc
{
    unsigned int dwTick;
    unsigned int uMessage;
    unsigned int wParam;
    int lParam;
};

struct D2MsgRecordChunkStrc
{
    D2MsgRecordStrc tRecords[500];
    int nCount;
    int nUnk0x1F44;
    D2MsgRecordChunkStrc* pNext;
};

struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    SMSGHANDLER pfnHandler;
};
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam); // 0x006CC488
extern "C" int __cdecl SStrPrintf(char* szBuffer, unsigned int nSize, const char* szFormat, ...); // 0x00413A40
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam, int* pUseResult, int* pResult); // 0x00420B00
int __fastcall D2Win_10076(D2WinEditBoxStrc* pEditBox, const char* szText); // 0x004FFE10
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinButtonStrc* ptBtnData, int bIsPressed); // 0x005009A0
unsigned int __stdcall sub_00505330_GetCompositeFlags(D2CompositeStrc* pComposite); // 0x00505330
const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nRank, int bSoftCore); // 0x00505640
void __cdecl sub_004451C0_UpdateLevelControls(); // 0x004451C0
void __stdcall sub_004493E0_RemoveChannelUser(const char* szName); // 0x004493E0
int __stdcall sub_0041C430_FormatError(unsigned long error, char* buffer, unsigned long size); // 0x0041C430
void __cdecl sub_00451400_AddRecordChunk(); // 0x00451400
int __cdecl sub_0044DA90(); // 0x0044DA90
int __cdecl sub_00451990(); // 0x00451990
void __fastcall sub_004514B0_FilterMessage(unsigned int uMessage, unsigned int wParam, int lParam); // 0x004514B0
void __fastcall sub_00451C70_RegisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler); // 0x00451C70
extern const char gszFormatInt_006D57BC[]; // 0x006D57BC
extern const unsigned int gdwTitleMaskA_006CE280; // 0x006CE280
extern const unsigned int gdwTitleMaskB_006CE284; // 0x006CE284
extern D2WinEditBoxStrc* gpEditBox_00798C3C; // 0x00798C3C
extern D2MultiChannelUserStrc* gpChannelUsers_00798F34; // 0x00798F34
extern D2ChannelEntryStrc* gpChannelEntries_00798F38; // 0x00798F38
extern int gbStringsLoaded_007A070C; // 0x007A070C
extern D2MsgRecordChunkStrc* gpMsgRecordChunk_0070F7A0; // 0x0070F7A0
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
extern D2WinControlStrc* gpControl_0077B098; // 0x0077B098
static __declspec(noinline) int sub_00446D30_GetUserRank(D2MultiChannelUserStrc* pUser);

void __cdecl sub_0043D990_ActivateEdit(); // 0x0043D990
extern const unsigned char gnCdKeyMap_006D59F0[256]; // 0x006D59F0
void* __stdcall sub_00449050_AddEntry(const char* szText, int nLength, int nA); // 0x00449050

D2WinButtonStrc* gpButton_00798C40; // 0x00798C40

char* gpMcpPacket_007992F4; // 0x007992F4

// 0x00445300
void __cdecl sub_00445300_LoadLvlRest()
{
    unsigned long nValue = 4;
    if (!SRegLoadValue("Diablo II", "LVL_REST", 0, &nValue))
    {
        SRegSaveValue("Diablo II", "LVL_REST", 0, nValue);
        return;
    }
    char szText[4] = "4";
    if (nValue == 666)
    {
        BUTTON_SetIsPressed(gpButton_00798C40, 0);
        sub_004451C0_UpdateLevelControls();
        return;
    }
    SStrPrintf(szText, 4, gszFormatInt_006D57BC, nValue);
    D2Win_10076(gpEditBox_00798C3C, szText);
    BUTTON_SetIsPressed(gpButton_00798C40, 1);
    sub_004451C0_UpdateLevelControls();
}

// 0x00447560
void __fastcall sub_00447560_SplitName(const char* szName, char* szTitle, char* szOut)
{
    *szOut = 0;
    *szTitle = 0;
    if (*szName == '*')
    {
        SStrCopy(szOut, szName, 0x7FFFFFFF);
        return;
    }
    char* pAt = SStrChr(szName, '@');
    char* pStar = SStrChr(szName, '*');
    if (pAt && pStar && pAt < pStar)
    {
        SStrCopy(szOut, szName, 0x7FFFFFFF);
        *SStrChr(szOut, '*') = 0;
        return;
    }
    D2ChannelEntryStrc* pEntry = gpChannelEntries_00798F38;
    while (pEntry)
    {
        if (!_stricmp(pEntry->szName, szName))
            break;
        pEntry = pEntry->pNext;
    }
    if (pEntry)
    {
        D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
        while (pUser)
        {
            if (!_stricmp(pUser->szName, szName))
                break;
            pUser = pUser->pNext;
        }
        if (pUser)
        {
            const unsigned int nFlags = sub_00505330_GetCompositeFlags(pUser->pComposite);
            if ((nFlags & gdwTitleMaskA_006CE280) || (nFlags & gdwTitleMaskB_006CE284))
            {
                SStrCopy(szTitle, D2Win_10160_GetPlayerTitle(pUser->nClass, 3 * ((nFlags >> 5) & 1) + 2 * ((nFlags >> 7) & 1) + ((nFlags >> 6) & 1), (nFlags >> 12) & 1), 0x7FFFFFFF);
            }
        }
        SStrCopy(szOut, pEntry->szAccount, 0x7FFFFFFF);
    }
    if (*szName != '*')
    {
        char* pEnd = SStrChr(szName, '*');
        if (pEnd)
        {
            memcpy(szOut, szName, pEnd - szName);
            szOut[pEnd - szName] = 0;
            return;
        }
    }
    SStrCopy(szOut, szName, 0x7FFFFFFF);
}

// 0x00449690
int __fastcall sub_00449690_OnMessage(int nA, int nB, const char* szText, int nLength)
{
    sub_004493E0_RemoveChannelUser(szText);
    return 1;
}

// 0x00449E70
void __stdcall sub_00449E70_SetMcpPacket(const char* pData, int nSize)
{
    if (gpMcpPacket_007992F4)
    {
        FOG_Free(gpMcpPacket_007992F4, ".\\Src\\McpConnect.cpp", 0x21E, 0);
        gpMcpPacket_007992F4 = 0;
    }
    if (!nSize)
        return;
    gpMcpPacket_007992F4 = (char*)FOG_Alloc(nSize, ".\\Src\\McpConnect.cpp", 0x227, 0);
    memcpy(gpMcpPacket_007992F4, pData, nSize);
    if (*pData == 0x17)
    {
        D2_ASSERT(*(unsigned short*)(gpMcpPacket_007992F4 + 1) < 0x100, 0x233);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket_007992F4 + 3) < 0x100, 0x234);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket_007992F4 + 5) < 0x100, 0x235);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket_007992F4 + 7) < 0x100, 0x236);
    }
    else if (*pData == 0x19)
    {
        D2_ASSERT(*(unsigned short*)(gpMcpPacket_007992F4 + 1) < 0x100, 0x242);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket_007992F4 + 3) < 0x100, 0x243);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket_007992F4 + 5) < 0x100, 0x244);
        const unsigned short nCount = *(unsigned short*)(gpMcpPacket_007992F4 + 7);
        D2_ASSERT(nCount < 0x100, 0x245);
        const char* p = gpMcpPacket_007992F4 + 9;
        for (int i = 0; i < nCount; i++)
        {
            p += 4;
            while (*p++);
            while (*p++);
        }
    }
    else
    {
        D2_ASSERT(0, 0x254);
    }
}

// 0x0044CCA0
int __fastcall sub_0044CCA0_CountLevels(int nValue, int nUnused, int nLimit)
{
    int nCount = 0;
    if (nLimit < 7)
        nCount = 1;
    if (nValue > 1)
        nCount++;
    if (nValue > 9)
        nCount++;
    if (nValue > 0x13)
        nCount++;
    if (nValue > 0x1D)
        nCount++;
    return nCount;
}

// 0x004512C0
int __stdcall sub_004512C0_LoadString(int nId, char* szBuffer, unsigned int nSize)
{
    D2_ASSERT(gbStringsLoaded_007A070C, 0x81);
    if (!sub_0041C430_FormatError(nId, szBuffer, nSize))
    {
        SStrCopy(szBuffer, "Stupid Lng.cpp error.", nSize);
        return 0;
    }
    return 1;
}

// 0x00451450
void __stdcall sub_00451450_RecordMessage(unsigned int uMessage, unsigned int wParam, int lParam)
{
    if (gpMsgRecordChunk_0070F7A0->nCount >= 500)
        sub_00451400_AddRecordChunk();
    D2MsgRecordStrc* pRecord = &gpMsgRecordChunk_0070F7A0->tRecords[gpMsgRecordChunk_0070F7A0->nCount++];
    pRecord->dwTick = sub_0044DA90();
    pRecord->uMessage = uMessage;
    pRecord->wParam = wParam;
    pRecord->lParam = lParam;
}

// 0x00451B30
int __stdcall sub_00451B30_WindowProc(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam)
{
    int bUseResult = 0;
    int lResult = 0;
    sub_004514B0_FilterMessage(uMessage, wParam, lParam);
    if (!sub_00451990() || uMessage == 0x10)
    {
        if (SMsgDispatchMessage(hWnd, uMessage, wParam, lParam, &bUseResult, &lResult) && bUseResult)
            return lResult;
    }
    return DefWindowProcA(hWnd, uMessage, wParam, lParam);
}

// 0x00451DB0
void __fastcall sub_00451DB0_RegisterMsgHandlers(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount)
{
    D2_ASSERT(hWnd, 0x153);
    for (unsigned int i = 0; i < nCount; i++)
    {
        sub_00451C70_RegisterMsgHandler(hWnd, pTable[i].nType, pTable[i].nId, pTable[i].pfnHandler);
    }
}

#include "gen/data/Source/D2Multi/Src/ComCallback_00445300.inc"

char gszTempFile_00798E30[260]; // 0x00798E30

char gszText_00798CF8[56]; // 0x00798CF8

// 0x00446CA0
int __cdecl sub_00446CA0_PlayTempSmack()
{
    if (gszTempFile_00798E30[0] && GetFileAttributesA(gszTempFile_00798E30) != (unsigned long)-1)
    {
        const char* pExt = strrchr(gszTempFile_00798E30, '.') + 1;
        SMACK_Decode((D2WinSmackStrc*)gpControl_0077B098, gszTempFile_00798E30, tolower(*pExt));
        return 1;
    }
    return 0;
}

// 0x00446D00
static __forceinline int sub_00446D00_SetText(const char* szText)
{
    SStrCopy(gszText_00798CF8, szText, 0x32);
    return 1;
}

int __stdcall sub_M121_Emit_00446D00(const char* szText) { return sub_00446D00_SetText(szText); }

// 0x00446D30
static int sub_00446D30_GetUserRank(D2MultiChannelUserStrc* pUser)
{
    const unsigned int dwFlags = pUser->dwFlags;
    if (dwFlags & 2)
        return 4;
    if (dwFlags & 8)
        return 3;
    if (dwFlags & 1)
        return 2;
    if (dwFlags & 4)
        return 1;
    return 0;
}

// build: context sub_00446D30_Shim
// calling-convention shim (not game code)
int __fastcall sub_00446D30_Shim(D2MultiChannelUserStrc* pLeft, D2MultiChannelUserStrc* pRight)
{
    return sub_00446D30_GetUserRank(pRight) - sub_00446D30_GetUserRank(pLeft);
}

// 0x00447A90
int __stdcall sub_00447A90_OnActivate(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00444020();
    sub_0043D990_ActivateEdit();
    return 1;
}

// 0x00449320
static __forceinline void* sub_00449320_AddEntry(const char* szText, int nLength, int nA)
{
    return sub_00449050_AddEntry(szText, nLength, nA);
}

// 0x004497C0
int __fastcall sub_004497C0_MapKeyChar(unsigned char cChar)
{
    return (char)gnCdKeyMap_006D59F0[cChar];
}

// 0x004497D0
int __fastcall sub_004497D0_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// 0x00449840
unsigned int __fastcall sub_00449840_NibbleToHex(unsigned int nValue)
{
    unsigned int nResult = nValue & 0xF;
    if (nResult >= 10)
        nResult += 0x37;
    else
        nResult += 0x30;
    return nResult;
}

// 0x00449860
int __fastcall sub_00449860_IsValidKeyText(const char* szKey)
{
    while (*szKey)
    {
        if (gnCdKeyMap_006D59F0[(unsigned char)*szKey++] > 0x17)
        {
            return 0;
        }
    }
    return 1;
}

void* __fastcall sub_M109_Emit_00449320(const char* szText, int nLength)
{
    return sub_00449320_AddEntry(szText, nLength, 7);
}
