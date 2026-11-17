struct D2WinControlStrc;
typedef unsigned short Unicode;

struct D2ListMessage00441320Strc
{
    void* hWnd;
    unsigned int uMessage;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
int __fastcall sub_004FB990_GetSelection(D2WinControlStrc* pControl); // 0x004FB990
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl); // 0x004FBB30
void __fastcall sub_004FF5A0_SetEditText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0
int __stdcall sub_004F91C0(D2WinControlStrc* pEditBox); // 0x004F91C0
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
void __fastcall sub_004411E0_Use(const char* szText); // 0x004411E0

extern D2WinControlStrc* gpControl_0077BCFC; // 0x0077BCFC
extern D2WinControlStrc* gpEdit_0077BCF4; // 0x0077BCF4
extern int gnLastSelection_0070EB90; // 0x0070EB90
extern unsigned long gdwLastClickTick_0077BDA8; // 0x0077BDA8

static __forceinline int DoubleClick()
{
    int aText[0x40];
    const Unicode* pEditText = sub_004FDD90_GetEditText(gpEdit_0077BCF4);
    if (!pEditText)
    {
        return 0;
    }
    sub_00526F70((char*)aText, pEditText, 0x100);
    sub_004411E0_Use((const char*)aText);
    return 0;
}

// 0x00441320
int __stdcall sub_00441320_ListClick(D2ListMessage00441320Strc* pMsg)
{
    const int nSelection = sub_004FB990_GetSelection(gpControl_0077BCFC);
    if (nSelection == -1)
    {
        return 0;
    }

    switch (pMsg->uMessage)
    {
    case 0x201:
        {
            const unsigned long dwTick = GetTickCount();
            const int bDoubleClick = nSelection == gnLastSelection_0070EB90 && dwTick - gdwLastClickTick_0077BDA8 <= 500;
            if (!bDoubleClick)
            {
                gnLastSelection_0070EB90 = nSelection;
                gdwLastClickTick_0077BDA8 = dwTick;
            }
            if (bDoubleClick)
            {
                return DoubleClick();
            }
        }
        break;
    }

    const Unicode* pText = sub_004FBB30_GetText(gpControl_0077BCFC);
    if (!pText)
    {
        return 0;
    }
    sub_004FF5A0_SetEditText(gpEdit_0077BCF4, pText);
    sub_004F91C0(0);
    return 0;
}

#include "gen/data/Source/D2Client/00441320_sub_00441320_ListClick.inc"
