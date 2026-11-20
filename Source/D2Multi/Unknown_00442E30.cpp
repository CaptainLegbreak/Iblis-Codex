#include "D2Multi.h"
#include "D2Unicode.h"
struct D2WinEditBoxStrc;

struct Unicode;
struct SMSGHANDLER_PARAMS;
struct D2LaunchGameRecStrc;
struct D2GameDetailsStrc;

struct SMSGHANDLER_PARAMS
{
    void* hWnd;
    unsigned int uMessage;
    unsigned int wParam;
    unsigned int lParam;
    unsigned int dwCommandSource;
};

struct D2LaunchGameRecStrc
{
    char nUnk0x00;
    char szName[0x30];
    char wValue0x31[2];
    char wValue0x33[2];
    char f_35[2];
    char nAddress0x37[4];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" unsigned int __cdecl strlen(const char* szString);
int __stdcall sub_004F91C0(D2WinEditBoxStrc* pEditBox); // 0x004F91C0
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl); // 0x004FBB30
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
int __stdcall sub_004439F0_JoinByName(int nArg); // 0x004439F0
void __fastcall sub_00442DD0_SetPendingText(const char* szText, unsigned short wRequestId); // 0x00442DD0
extern D2LaunchGameRecStrc gaNewGames_0077BDC8[]; // 0x0077BDC8
extern D2WinControlStrc* gpJoinName_00798BD4; // 0x00798BD4
extern unsigned long gdwLastClickTick_00798CEC; // 0x00798CEC

struct D2GameDetailsStrc
{
    char unk0x00[0x0C];
    unsigned int dwElapsed;
    unsigned char nLevel;
    unsigned char nLevelDiff;
    unsigned char nMaxPlayers;
    char unk0x13;
    int nPlayers;
    char unk0x18[0x14];
    char szDescription[0x20];
    unsigned short wClass[16];
    unsigned short wLevel[16];
    char szNames[16][16];
};

extern "C" const char gszEmptyString_006CC837[]; // 0x006CC837

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

int __stdcall sub_004450D0_OnGameListEvent(SMSGHANDLER_PARAMS* pMsg)
{
    const int nSelection = sub_004FB990_GetSelection(gpGameList_00798BC0);
    sub_004FB6A0_ClearText(gpGameText_00798BC4);
    if (nSelection != -1)
    {
        if (pMsg->uMessage == 0x201)
        {
            const unsigned long dwTick = GetTickCount();
            if (nSelection == gnLastSelection_0070EBDC && dwTick - gdwLastClickTick_00798CEC <= 500)
            {
                sub_004439F0_JoinByName(0);
                return 0;
            }
            gnLastSelection_0070EBDC = nSelection;
            gdwLastClickTick_00798CEC = dwTick;
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

D2WinControlStrc* gpGameInfoText_00798BC4; // 0x00798BC4

// 0x00442EB0
void __fastcall sub_00442EB0_ShowGameDetails(D2GameDetailsStrc* pDetails)
{
    char szLine[0x100];

    if (!gpGameInfoText_00798BC4)
        return;

    sub_004FB6A0_ClearText(gpGameInfoText_00798BC4);
    if (strlen(pDetails->szDescription))
    {
        sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, pDetails->szDescription);
        sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, gszEmptyString_006CC837);
    }

    unsigned int nSecondsPerHour = 3600;
    unsigned int nSecondsPerMinute = 60;
    unsigned int dwElapsed = pDetails->dwElapsed;
    unsigned int nHours = dwElapsed / nSecondsPerHour;
    unsigned int nRest = dwElapsed % nSecondsPerHour;
    sprintf(szLine, "Elapsed Time: %d:%02d:%02d", nHours, nRest / 60, dwElapsed % nSecondsPerMinute);
    sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, szLine);

    unsigned char nLevelDiff = pDetails->nLevelDiff;
    if (nLevelDiff < 100)
    {
        if (nLevelDiff)
        {
            int nDiff = nLevelDiff;
            int nLevel = pDetails->nLevel;
            int nMin = nLevel - nDiff;
            if (nMin <= 1)
                nMin = 1;
            int nMax = nDiff + nLevel;
            if (nMax >= 99)
                nMax = 99;
            sprintf(szLine, "Level %d to %d", nMin, nMax);
        }
        else
        {
            sprintf(szLine, "Level %d", pDetails->nLevel);
        }
        sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, szLine);
    }

    if (pDetails->nMaxPlayers > 0 && pDetails->nMaxPlayers < 8)
    {
        sprintf(szLine, "Up to %d Players", pDetails->nMaxPlayers);
        sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, szLine);
    }

    sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, gszEmptyString_006CC837);

    for (int i = 0; i < pDetails->nPlayers; ++i)
    {
        if (pDetails->szNames[i][0])
        {
            sub_004FCF80_SetTextA(gpGameInfoText_00798BC4, pDetails->szNames[i]);
            switch (pDetails->wClass[i])
            {
            case 0:
                sprintf(szLine, "Level %d Amazon", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 1:
                sprintf(szLine, "Level %d Sorceress", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 2:
                sprintf(szLine, "Level %d Necromancer", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 3:
                sprintf(szLine, "Level %d Paladin", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 4:
                sprintf(szLine, "Level %d Barbarian", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 5:
                sprintf(szLine, "Level %d Druid", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            case 6:
                sprintf(szLine, "Level %d Assassin", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            default:
                sprintf(szLine, "Level %d", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText_00798BC4, szLine, 5);
                break;
            }
        }
    }

    D2Win_10053(gpGameInfoText_00798BC4, 0);
}
