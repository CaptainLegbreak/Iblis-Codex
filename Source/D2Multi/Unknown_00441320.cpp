#include "D2Multi.h"

typedef unsigned short Unicode;

struct D2ListMessage00441320Strc
{
    void* hWnd;
    unsigned int uMessage;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl); // 0x004FBB30
void __fastcall EDITBOX_SetText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
void __fastcall CHATDLG_JoinChannel(const char* szText); // 0x004411E0

extern D2WinControlStrc* gpChannelListBox; // 0x0077BCFC
extern int gnChannelListLastSelection; // 0x0070EB90
extern unsigned long gdwChannelListLastClickTick; // 0x0077BDA8

static __forceinline int DoubleClick()
{
    int aText[0x40];
    const Unicode* pEditText = sub_004FDD90_GetEditText(gpEdit_0077BCF4);
    if (!pEditText)
    {
        return 0;
    }
    sub_00526F70((char*)aText, pEditText, 0x100);
    CHATDLG_JoinChannel((const char*)aText);
    return 0;
}

// 0x00441320
int __stdcall sub_00441320_ListClick(D2ListMessage00441320Strc* pMsg)
{
    const int nSelection = sub_004FB990_GetSelection(gpChannelListBox);
    if (nSelection == -1)
    {
        return 0;
    }

    switch (pMsg->uMessage)
    {
    case 0x201:
        {
            const unsigned long dwTick = GetTickCount();
            const int bDoubleClick = nSelection == gnChannelListLastSelection && dwTick - gdwChannelListLastClickTick <= 500;
            if (!bDoubleClick)
            {
                gnChannelListLastSelection = nSelection;
                gdwChannelListLastClickTick = dwTick;
            }
            if (bDoubleClick)
            {
                return DoubleClick();
            }
        }
        break;
    }

    const Unicode* pText = sub_004FBB30_GetText(gpChannelListBox);
    if (!pText)
    {
        return 0;
    }
    EDITBOX_SetText(gpEdit_0077BCF4, pText);
    CONTROL_SetFocusedEditBox(0);
    return 0;
}

#include "gen/data/Source/D2Multi/Unknown_00441320.inc"
