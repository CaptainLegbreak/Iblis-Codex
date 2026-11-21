#include "D2Multi.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
extern "C" unsigned int __cdecl strlen(const char* szString);
int __stdcall sub_004F91C0(void* pEditBox);                                                                  // 0x004F91C0
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl);                                 // 0x004FBB30
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount);                     // 0x00526F70
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText);                 // 0x004FF5A0
int __stdcall sub_004439F0_JoinByName(int nArg);                                                            // 0x004439F0
void __fastcall sub_00442DD0_SetPendingText(const char* szText, unsigned short wRequestId);                 // 0x00442DD0

extern D2LaunchGameRecStrc gaNewGames_0077BDC8[];                                                           // 0x0077BDC8
extern D2WinControlStrc* gpJoinName_00798BD4;                                                               // 0x00798BD4
unsigned long gdwLastClickTick_00798CEC;                                                                    // 0x00798CEC

// 0x00442E30
static void sub_00442E30_ShowGameInfo(int nIndex)
{
    if (!gpGameText_00798BC4)
        return;

    D2LaunchGameRecStrc* pGame = &gaNewGames_0077BDC8[nIndex];
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    if (strlen(&pGame->szName[0x10]))
    {
        sub_004FCF80_SetTextA(gpGameText_00798BC4, &pGame->szName[0x10]);
        sub_004FCF80_SetTextA(gpGameText_00798BC4, &gszEmptyAssertText);
    }
    D2Win_10053(gpGameText_00798BC4, 0);
    if (pGame->szName)
    {
        sub_004FFE10_SetTextA(gpJoinName_00798BD4, pGame->szName);
        sub_004F91C0(0);
    }
}

static __forceinline int sub_004450D0_IsDoubleClick(int nSelection)
{
    const unsigned long dwTick = GetTickCount();
    if (nSelection == gnLastSelection_0070EBDC && dwTick - gdwLastClickTick_00798CEC <= 500)
        return 1;

    gnLastSelection_0070EBDC = nSelection;
    gdwLastClickTick_00798CEC = dwTick;
    return 0;
}

// 0x004450D0
int __stdcall sub_004450D0_OnGameListEvent(SMSGHANDLER_PARAMS* pMsg)
{
    const int nSelection = sub_004FB990_GetSelection(gpGameList_00798BC0);
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    if (nSelection != -1)
    {
        if (pMsg->uMessage == 0x201 && sub_004450D0_IsDoubleClick(nSelection))
        {
            sub_004439F0_JoinByName(0);
            return 0;
        }

        if (sub_00449B30_QueryAddress())
        {
            const Unicode* pText = sub_004FBB30_GetText(gpGameList_00798BC0);
            if (pText)
            {
                char szText[0x100];
                sub_00526F70(szText, pText, 0x100);
                while (++gwRequestId_0070CD60 == 0)
                {
                }
                sub_00442DD0_SetPendingText(szText, gwRequestId_0070CD60);
                sub_004FF5A0_SetEditText(gpJoinName_00798BD4, pText);
                sub_004F91C0(0);
            }
        }
        else
        {
            sub_00442E30_ShowGameInfo(nSelection);
        }
    }
    return 0;
}

#include "gen/data/Source/D2Multi/Unknown_004450D0.inc"
