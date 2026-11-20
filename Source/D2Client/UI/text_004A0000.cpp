#include "D2Client.h"

struct T00479230;

#pragma pack(push, 1)
struct D2TextNodeStrc
{
    char unk0x00[0x1E];
    int dwEndTick;
    D2TextNodeStrc* pNext;
};
#pragma pack(pop)

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short wCount;
};

int __fastcall sub_00455F20(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
extern T00479230* gpTextBox_007BF0A4;                                                                   // 0x007BF0A4
extern D2ClientDialogStrc* gpListDialog_007BF1B0;                                                           // 0x007BF1B0
extern D2TextListStrc gtTextList_007BF1E4;                                                                  // 0x007BF1E4

// 0x004A0000
int __cdecl sub_004A0000()
{
    return gpTextBox_007BF0A4 != 0;
}

// 0x004A01E0
void __cdecl sub_004A01E0_ClearListFlags()
{
    for (D2TextNodeStrc* pNode = gtTextList_007BF1E4.pFirst; pNode; pNode = pNode->pNext)
        pNode->dwEndTick = 0;
}

// 0x004A02F0
void __cdecl sub_004A02F0_ToggleListDialogUI()
{
    if (gpListDialog_007BF1B0)
    {
        sub_00455F20(0x18, 1, 0);
        sub_00455F20(0x18, 0, 0);
    }
}
