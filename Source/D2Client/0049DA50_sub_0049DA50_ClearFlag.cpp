struct D2HoverTextStrc;
struct D2ClientTextBoxStrc;
struct D2MsgHandlerEntryStrc;

struct Unicode
{
    unsigned short wChar;
};

struct D2UnitStrc
{
    char unk0x00[0x0C];
    int dwUnitId;
    char unk0x10[0xA4 - 0x10];
    D2HoverTextStrc* pHoverText;
};

#pragma pack(push, 2)
struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst;
    unsigned short nCount;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2HoverClearPacketStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
};
#pragma pack(pop)

struct D2TextIdEntryStrc
{
    unsigned short wId;
    unsigned short wStringId;
};

struct D2ClientTextDataStrc
{
    char unk0x00[0x80];
    int dwTag;
};

class ListBoxWrapper
{
public:
    virtual void Slot00(); virtual void Slot04(); virtual void Slot08(); virtual void Slot0C();
    virtual void Slot10(); virtual void Slot14(); virtual void Slot18(); virtual void Slot1C();
    virtual void Slot20(); virtual void Slot24(); virtual void Slot28(); virtual void Slot2C();
    virtual void AddTextLine(Unicode* pLine0, Unicode* pLine1, Unicode* pLine2, Unicode* pLine3, Unicode* pLine4,
                             Unicode* pLine5, int nArg6, int nColor, int nArg8, int nArg9);
};

typedef int (__fastcall* D2TextCallback)(void* pContext, int nArg, int nValue);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
void __cdecl sub_0044DA40();                                                                                // 0x0044DA40
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __cdecl sub_00453AE0();                                                                                // 0x00453AE0
void __fastcall sub_00455F20(int nUIVar, int nState, int nArg);                                        // 0x00455F20
D2UnitStrc* __fastcall sub_00463990(int nUnitId, int nUnitType);                             // 0x00463990
void __fastcall sub_00478680_SendPacket5(char nHeader, int nArg);                                           // 0x00478680
void __stdcall sub_0049D410_FreeTextBox(D2ClientTextBoxStrc* pTextBox);                                     // 0x0049D410
void __stdcall sub_0049D4D0_FreeTextList(D2TextListStrc* pList);                                            // 0x0049D4D0
void __cdecl sub_0049F960_ResetTextBox();                                                                   // 0x0049F960
void __fastcall sub_004B3D10_ReleaseTextUnit(int nUnitId);                                                  // 0x004B3D10
int __cdecl sub_004F59A0();                                                                                // 0x004F59A0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText);                           // 0x006611A0

extern D2MsgHandlerEntryStrc gaTextMsgHandlers_00722600[];                                                  // 0x00722600
extern D2TextIdEntryStrc gaTextIds_00722678[];                                                              // 0x00722678
extern int gnTextIdCount_00722EB4;                                                                          // 0x00722EB4
extern D2ClientTextBoxStrc* gpTextBox_007BF1A8;                                                             // 0x007BF1A8
extern ListBoxWrapper* gpListBox_007BF1B4;                                                                  // 0x007BF1B4
extern int gnGlobal_007BF1BC;                                                                               // 0x007BF1BC
extern int gnGlobal_007BF1C0;                                                                               // 0x007BF1C0
extern int gnGlobal_007BF1C4;                                                                               // 0x007BF1C4
int gnGlobal_007BF1C8;                                                                                      // 0x007BF1C8
int gnGlobal_007BF1E0;                                                                                      // 0x007BF1E0
extern D2TextListStrc gtTextList_007BF1E4;                                                                  // 0x007BF1E4
extern D2TextListStrc gtTextList_007BF1F0;                                                                  // 0x007BF1F0
extern int gdwGlobal_007BF202;                                                                              // 0x007BF202
extern int gdwGlobal_007BF206;                                                                              // 0x007BF206
extern int gdwGlobal_007BF20A;                                                                              // 0x007BF20A
D2ClientTextDataStrc* gpTextData_007BF228;                                                                  // 0x007BF228
extern unsigned char gnGlobal_007BF23A;                                                                     // 0x007BF23A
extern int gnGlobal_007BF23F;                                                                               // 0x007BF23F
int gnGlobal_007BF254;                                                                                      // 0x007BF254
D2TextCallback gpfnTextCallback_007BF258;                                                                   // 0x007BF258
void* gpTextCallbackContext_007BF25C;                                                                       // 0x007BF25C
extern int gbStarted_007BF27C;                                                                              // 0x007BF27C

// 0x0049DA50
void __cdecl sub_0049DA50_ClearFlag()
{
    gnGlobal_007BF23A = 0;
}

// 0x0049E340
void __cdecl sub_0049E340_FillListBox()
{
    for (D2TextNodeStrc* pNode = gtTextList_007BF1F0.pFirst; pNode; pNode = pNode->pNext)
        gpListBox_007BF1B4->AddTextLine(pNode->pLines[0], pNode->pLines[1], pNode->pLines[2], pNode->pLines[3],
                                        pNode->pLines[4], pNode->pLines[5], 0, pNode->nColor, 0, 0xD);
}

// 0x0049E7E0
void __fastcall sub_0049E7E0_SetTextCallback(D2TextCallback pfnCallback, void* pContext)
{
    gpfnTextCallback_007BF258 = pfnCallback;
    gpTextCallbackContext_007BF25C = pContext;
}

// 0x0049E8B0
D2UnitStrc* __cdecl sub_0049E8B0_GetTextUnit()
{
    if (gdwGlobal_007BF20A)
        return sub_00463990(gdwGlobal_007BF202, 1);
    if (gnGlobal_007BF1C0)
        return sub_00463990(gdwGlobal_007BF206, 2);
    return 0;
}

// 0x0049F8C0
void __fastcall sub_0049F8C0_ClearHoverText(D2HoverClearPacketStrc* pPacket)
{
    D2UnitStrc* pUnit = sub_00463990(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        if (pUnit->pHoverText)
            CHAT_FreeHoverMsg(0, pUnit->pHoverText);
        pUnit->pHoverText = 0;
    }
}

// 0x0049F910
const Unicode* __fastcall sub_0049F910_GetTextString(unsigned short nId)
{
    int nStart;
    int nEnd;
    if (gaTextIds_00722678[100].wId > nId)
    {
        nStart = 0;
        nEnd = 100;
    }
    else
    {
        nStart = 100;
        nEnd = gnTextIdCount_00722EB4;
    }
    for (int i = nStart; i < nEnd; ++i)
    {
        if (gaTextIds_00722678[i].wId == nId)
            return D2LANG_GetStringFromTblIndex(gaTextIds_00722678[i].wStringId);
    }
    return D2LANG_GetStringFromTblIndex(0xE8C);
}

// 0x0049FF00
void __cdecl sub_0049FF00()
{
}

// 0x0049FF90
void __fastcall sub_0049FF90_OpenTextData(D2UnitStrc* pUnit, D2ClientTextDataStrc* pTextData)
{
    gpTextData_007BF228 = pTextData;
    sub_00455F20(0x10, 2, 0);
    sub_0044DA40();
    if (gpTextData_007BF228->dwTag == 0x20646B62)
    {
        gnGlobal_007BF254 = 1;
        sub_00478680_SendPacket5(0x3E, !pUnit ? -1 : pUnit->dwUnitId);
        gnGlobal_007BF1E0 = 0;
    }
    else
    {
        gnGlobal_007BF254 = 0;
        gnGlobal_007BF1E0 = 1;
    }
}

// 0x004A0010
void __cdecl sub_004A0010_FreeTextLists()
{
    sub_0049D4D0_FreeTextList(&gtTextList_007BF1E4);
    sub_0049D4D0_FreeTextList(&gtTextList_007BF1F0);
}

// 0x004A0880
void __cdecl sub_004A0880_CloseTextUnit()
{
    if (gdwGlobal_007BF20A)
        sub_004B3D10_ReleaseTextUnit(gdwGlobal_007BF202);
    else
        sub_0049F960_ResetTextBox();
    sub_00453AE0();
    gdwGlobal_007BF20A = 0;
}

// 0x004A08C0
int __cdecl sub_004A08C0_CloseText()
{
    int bResult = 0;
    gnGlobal_007BF1BC = 1;
    if (!gdwGlobal_007BF20A && gnGlobal_007BF1C0 != 1)
    {
        if (gnGlobal_007BF1C4 == 1)
        {
            if (gnGlobal_007BF1C8 == 1)
            {
                gnGlobal_007BF23F = 0;
                return bResult;
            }
            D2_ASSERT(gpTextBox_007BF1A8, 0x947);
            sub_0049D410_FreeTextBox(gpTextBox_007BF1A8);
            FOG_Free(gpTextBox_007BF1A8, ".\\UI\\text.cpp", 0x949, 0);
            gpTextBox_007BF1A8 = 0;
            gnGlobal_007BF1C4 = 0;
            gnGlobal_007BF1C8 = 0;
            bResult = 1;
        }
    }
    else
    {
        if (gpfnTextCallback_007BF258)
        {
            sub_0049F960_ResetTextBox();
            sub_00453AE0();
            if (gpfnTextCallback_007BF258(gpTextCallbackContext_007BF25C, 1, gnGlobal_007BF23F))
            {
                gnGlobal_007BF23F = 0;
                return 1;
            }
            if (gdwGlobal_007BF20A)
                sub_004B3D10_ReleaseTextUnit(gdwGlobal_007BF202);
        }
        else
        {
            if (gdwGlobal_007BF20A)
                sub_004B3D10_ReleaseTextUnit(gdwGlobal_007BF202);
            else
                sub_0049F960_ResetTextBox();
            sub_00453AE0();
        }
        gdwGlobal_007BF20A = 0;
        if (gbStarted_007BF27C == 1)
        {
            gbStarted_007BF27C = 0;
            sub_00451E10_RegisterHandlerTable(sub_004F59A0(), gaTextMsgHandlers_00722600, 7);
        }
        bResult = 1;
    }
    gnGlobal_007BF23F = 0;
    return bResult;
}

#include "gen/data/Source/D2Client/0049DA50_sub_0049DA50_ClearFlag.inc"
