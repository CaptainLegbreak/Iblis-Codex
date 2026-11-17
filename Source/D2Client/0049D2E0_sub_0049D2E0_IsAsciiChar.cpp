struct D2MsgHandlerEntryStrc
{
    int nType;
    int nId;
    void* pfnHandler;
};

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

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
void __fastcall sub_00451E10_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10
void __fastcall sub_00451DB0_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

extern unsigned long gnGlobal_007BF1F6;                                                                     // 0x007BF1F6
extern int gbStarted_007BF27C;                                                                              // 0x007BF27C
unsigned long gnGlobal_007BF22C;                                                                            // 0x007BF22C
extern D2MsgHandlerEntryStrc gaTextMsgHandlers_00722600[];                                                  // 0x00722600

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

#include "gen/data/Source/D2Client/0049D2E0_sub_0049D2E0_IsAsciiChar.inc"
