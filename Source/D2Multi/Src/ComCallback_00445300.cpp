#include "D2Multi.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"
#include "D2Unicode.h"
#include "D2ClientTypes.h"

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

void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed);                             // 0x005009A0

unsigned int __stdcall sub_00505330_GetCompositeFlags(D2CompositeStrc* pComposite); // 0x00505330

const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nRank, int bSoftCore); // 0x00505640

void __cdecl sub_004451C0_UpdateLevelControls(); // 0x004451C0

void __stdcall sub_004493E0_RemoveChannelUser(const char* szName); // 0x004493E0

int __stdcall SErrGetErrorStr(unsigned long error, char* buffer, unsigned long size); // 0x0041C430

void __cdecl sub_00451400_AddRecordChunk(); // 0x00451400

int __cdecl sub_0044DA90(); // 0x0044DA90

int __cdecl UI_IsReplayActive(); // 0x00451990

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

static int sub_00446D30_GetUserRank(D2MultiChannelUserStrc* pUser);

void __cdecl sub_0043D990_ActivateEdit(); // 0x0043D990

extern const unsigned char gnCdKeyMap_006D59F0[256]; // 0x006D59F0

void* __stdcall sub_00449050_AddEntry(const char* szText, int nLength, int nA); // 0x00449050

D2WinButtonStrc* gpButton_00798C40; // 0x00798C40

void __cdecl sub_00445DF0_CreateJoinScreen();                                                               // 0x00445DF0

void __cdecl sub_00445FF0_BuildCreateScreen();                                                              // 0x00445FF0

extern int gnLaunchMode_0077BBE4;                                                                           // 0x0077BBE4

extern D2WinControlStrc* gpControlA_0077B070;                                                               // 0x0077B070

D2WinControlStrc* gpChatControl_0077B074;                                                                   // 0x0077B074

extern D2WinControlStrc* gpControlB_0077B078;                                                               // 0x0077B078

D2WinControlStrc* gpControlC_0077B07C;                                                                      // 0x0077B07C

extern "C" char* __cdecl strchr(const char* szString, int nChar);                                           // 0x00687740

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

#pragma intrinsic(strcmp)

struct D2CompositeUnitStrc;

struct D2NamedValueStrc;

struct Unicode;

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

struct D2NamedValueStrc
{
    char szName[0x32];
    char szValue[0x12];
    D2NamedValueStrc* pNext;
};


const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* pCompositeUnit); // 0x00505330

extern D2WinControlStrc* gpChatEdit_0077BD94; // 0x0077BD94

static D2NamedValueStrc* s_pNamedValues_00798F38; // 0x00798F38

static int s_nNamedValues_00798F3C; // 0x00798F3C

struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };


extern D2WinControlStrc* gapChatButtons_0077AD78[11]; // 0x0077AD78

extern D2LaunchCharInfoStrc* gpCharInfo_0077BBD8; // 0x0077BBD8


extern int gnChannelUserCount_00798F40; // 0x00798F40

extern int gnChannelUserOffset_00798F44; // 0x00798F44

extern unsigned int gdwSelectionTick_00798F4C; // 0x00798F4C

extern "C" __declspec(dllimport) unsigned int __stdcall GetTickCount();

void __cdecl sub_00443E10(); // 0x00443E10

void __fastcall sub_00445A80_ShowProfileDialog(const char*,int,int); // 0x00445A80

void __fastcall sub_00445C70_ShowUserInfoDialog(const char*,const char*,int,int); // 0x00445C70

void __cdecl sub_00448050_ClearSelectedUser(); // 0x00448050

void __cdecl sub_004477A0_Refresh(); // 0x004477A0

void __stdcall D2Win_10156(D2CompositeUnitStrc*,int); // 0x00505360


char gszTempFile_00798E30[260]; // 0x00798E30

char gszText_00798CF8[56]; // 0x00798CF8

D2WinControlStrc* gpChatControl_0077B058; // 0x0077B058

D2WinControlStrc* gpChatControl_0077B05C; // 0x0077B05C

D2WinControlStrc* gpChatControl_0077B064; // 0x0077B064

D2WinControlStrc* gpChatControl_0077B068; // 0x0077B068

D2WinControlStrc* gpChatControl_0077B06C; // 0x0077B06C

D2MultiChannelUserStrc* gpSelectedChannelUser_00798F48; // 0x00798F48

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
        BUTTON_SetIsPressed((D2WinControlStrc*)gpButton_00798C40, 0);
        sub_004451C0_UpdateLevelControls();
        return;
    }
    SStrPrintf(szText, 4, gszFormatInt_006D57BC, nValue);
    D2Win_10076(gpEditBox_00798C3C, szText);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpButton_00798C40, 1);
    sub_004451C0_UpdateLevelControls();
}

// 0x00446780
int __stdcall sub_00446780_OpenJoinScreen(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    gnLaunchMode_0077BBE4 = 3;
    sub_00445DF0_CreateJoinScreen();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlA_0077B070, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    return 1;
}

// 0x004467D0
int __stdcall sub_004467D0_OpenCreateScreen(int nArg)
{
    sub_0043F8C0_ResetLaunchState();
    sub_00445FF0_BuildCreateScreen();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpControlB_0077B078, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    return 1;
}

// 0x00446950
int __stdcall sub_00446950_Refresh(int nArg)
{
    sub_00444020();
    sub_0043D990();
    return 1;
}

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
static inline int sub_00446D00_SetText(const char* szText)
{
    SStrCopy(gszText_00798CF8, szText, 0x32);
    return 1;
}

// 0x00446D20
int __stdcall sub_00446D20_AlwaysOne(int nArg1, int nArg2)
{
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

// 0x00446D60
static int sub_00446D60_Classify(int code) {
 switch(code) {
 case 0:
 case 1:
 case 6:
 case 9:
  return 0;
 default:
  return 1;
 }
}

int __fastcall EmitClassify(int code) { return sub_00446D60_Classify(code); }

// 0x00447390
static int sub_00447390_CompareNames(const char* szNameA, const char* szNameB)
{
    const char* szA = strchr(szNameA, '*');
    if (!szA)
        szA = szNameA;
    else
        szA += 1;
    const char* szB = strchr(szNameB, '*');
    if (!szB)
        szB = szNameB;
    else
        szB += 1;
    return strcmp(szA, szB);
}

int __cdecl sub_M133_Emit_00447390(const char* szNameA, const char* szNameB)
{
    return sub_00447390_CompareNames(szNameA, szNameB);
}

static inline const char* sub_SkipStarPrefix(const char* szName)
{
    const char* pFound = SStrChr(szName, '*');
    if (pFound && *++pFound)
        return pFound;
    return szName;
}

// 0x00447400
void __fastcall sub_00447400_SetNamedValue(const char* szName, const char* szValue)
{
    D2NamedValueStrc* pNode = s_pNamedValues_00798F38;
    D2NamedValueStrc* pPrevious = 0;
    const char* szKey = sub_SkipStarPrefix(szName);
    for (; pNode; pNode = pNode->pNext)
    {
        if (!strcmp(sub_SkipStarPrefix(pNode->szName), szKey))
            break;
        pPrevious = pNode;
    }
    if (pNode)
    {
        strcpy(pNode->szValue, szValue);
        return;
    }
    if (s_nNamedValues_00798F3C >= 0x400)
    {
        pNode = s_pNamedValues_00798F38;
        s_pNamedValues_00798F38 = s_pNamedValues_00798F38->pNext;
        FOG_Free(pNode, ".\\Src\\ComCallback.cpp", 0x936, 0);
        --s_nNamedValues_00798F3C;
    }
    D2NamedValueStrc* pNew = (D2NamedValueStrc*)FOG_Alloc(sizeof(D2NamedValueStrc), ".\\Src\\ComCallback.cpp", 0x93A, 0);
    strcpy(pNew->szName, szName);
    strcpy(pNew->szValue, szValue);
    pNew->pNext = 0;
    if (pPrevious)
        pPrevious->pNext = pNew;
    else
        s_pNamedValues_00798F38 = pNew;
    ++s_nNamedValues_00798F3C;
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

// 0x004477A0
void __cdecl sub_004477A0_Refresh()
{
    const Unicode* pText = sub_004FDD90_GetEditText(gpChatEdit_0077BD94);
    int bHasText = 0;
    if (pText && sub_00526800(pText))
        bHasText = 1;

// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
    CONTROL_SetEnabled(gpChatControl_0077B06C, bHasText);
    CONTROL_SetEnabled(gpChatControl_0077B058, bHasText);
    CONTROL_SetEnabled(gpChatControl_0077B05C, gpSelectedChannelUser_00798F48 && bHasText);

    unsigned int nFlags = 0;
    if (gpSelectedChannelUser_00798F48 && gpSelectedChannelUser_00798F48->pComposite)
    {
        const unsigned int nComposite = D2Win_10155((D2CompositeUnitStrc*)gpSelectedChannelUser_00798F48->pComposite);
        nFlags = gdwBitMasks[9] & nComposite;
    }

    CONTROL_SetEnabled(gpChatControl_0077B064, gpSelectedChannelUser_00798F48 && !nFlags);
    CONTROL_SetEnabled(gpChatControl_0077B068, gpSelectedChannelUser_00798F48 && nFlags);
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

// 0x00448C70
int __stdcall sub_00448C70_ButtonCallback(D2ChatMessageStrc* pMsg)
{
    int nButton;
    nButton = 0;
    for (;;)
    {
        if (!(nButton < 11))
            break;
        if (pMsg->pControl == gapChatButtons_0077AD78[nButton])
            goto found;
        ++nButton;
    }
    return 0;
found:
    const int nLine = gnChannelUserOffset_00798F44 + nButton;
    if (pMsg->nMessage == 0x205)
    {
        D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
        for (int n = 0; pUser; ++n, pUser = pUser->pNext)
        {
            if (n == nLine)
            {
                sub_00443E10();
                const char* szName = pUser->szName;
                const char* szCompare = SStrChr(szName, '*');
                if (szCompare && szCompare[1])
                    ++szCompare;
                else
                    szCompare = szName;
                if (!strcmp(szCompare, gpCharInfo_0077BBD8->szText0x8D))
                {
                    sub_00445A80_ShowProfileDialog(pUser->szText, pUser->bFlagA0, pUser->bFlagA8);
                    return 1;
                }
                sub_00445C70_ShowUserInfoDialog(szName, pUser->szText, pUser->bFlagA0, pUser->bFlagA8);
                return 1;
            }
        }
        return 1;
    }
    const unsigned int nTick = GetTickCount();
    if (nLine == gnSelectedLine_0070EC1C)
    {
        sub_00448050_ClearSelectedUser();
        return 1;
    }
    if (nLine < gnChannelUserCount_00798F40)
    {
        sub_00448050_ClearSelectedUser();
        D2MultiChannelUserStrc* pUser = gpChannelUsers_00798F34;
        for (int n = 0; pUser; ++n, pUser = pUser->pNext)
        {
            if (n == nLine)
            {
                D2_ASSERT(pUser->pComposite,0x135);
                const unsigned int nFlags = D2Win_10155((D2CompositeUnitStrc*)pUser->pComposite);
                D2Win_10156((D2CompositeUnitStrc*)pUser->pComposite, gdwBitMasks[10] | nFlags);
                gpSelectedChannelUser_00798F48 = pUser;
                gnSelectedLine_0070EC1C = nLine;
                gdwSelectionTick_00798F4C = nTick;
                sub_004477A0_Refresh();
            }
        }
    }
    return 1;
}

// 0x00449320
static inline void* sub_00449320_AddEntry(const char* szText, int nLength, int nA)
{
    return sub_00449050_AddEntry(szText, nLength, nA);
}

// 0x00449690
int __fastcall sub_00449690_OnMessage(int nA, int nB, const char* szText, int nLength)
{
    sub_004493E0_RemoveChannelUser(szText);
    return 1;
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
    if (!SErrGetErrorStr(nId, szBuffer, nSize))
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
    if (!UI_IsReplayActive() || uMessage == 0x10)
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
        sub_00451C70_RegisterMsgHandler(hWnd, pTable[i].nType, pTable[i].nId, (SMSGHANDLER)pTable[i].pfnHandler);
    }
}

#include "gen/data/Source/D2Multi/Src/ComCallback_00445300.inc"
