#include "D2Multi.h"

struct D2CompositeUnitStrc;
struct D2NamedValueStrc;
struct Unicode;
struct T0043E860;

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

struct D2NamedValueStrc
{
    char szName[0x32];
    char szValue[0x12];
    D2NamedValueStrc* pNext;
};

const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

struct Unicode
{
    unsigned short wChar;
};

struct T0043E860
{
    int nUnk0x00;
    char szName[0x32];
    char szText[0x50];
    unsigned char nClass;
    char unk0x87[0x15];
    D2CompositeUnitStrc* f_9C;
    int nValue0xA0;
    int unk0xA4;
    int nValue0xA8;
    int unk0xAC;
    T0043E860* pNext;
};

const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* pCompositeUnit); // 0x00505330
extern D2WinControlStrc* gpChatEdit_0077BD94; // 0x0077BD94

static D2NamedValueStrc* s_pNamedValues_00798F38; // 0x00798F38

static int s_nNamedValues_00798F3C; // 0x00798F3C

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

D2WinControlStrc* gpChatControl_0077B058; // 0x0077B058

D2WinControlStrc* gpChatControl_0077B05C; // 0x0077B05C

D2WinControlStrc* gpChatControl_0077B064; // 0x0077B064

D2WinControlStrc* gpChatControl_0077B068; // 0x0077B068

D2WinControlStrc* gpChatControl_0077B06C; // 0x0077B06C

T0043E860* gpSelectedChannelUser_00798F48; // 0x00798F48

// 0x004477A0
void __cdecl sub_004477A0_Refresh()
{
    const Unicode* pText = sub_004FDD90_GetEditText(gpChatEdit_0077BD94);
    int bHasText = 0;
    if (pText && sub_00526800(pText))
        bHasText = 1;

    sub_004F96F0_ControlClearState(gpChatControl_0077B06C, bHasText);
    sub_004F96F0_ControlClearState(gpChatControl_0077B058, bHasText);
    sub_004F96F0_ControlClearState(gpChatControl_0077B05C, gpSelectedChannelUser_00798F48 && bHasText);

    unsigned int nFlags = 0;
    if (gpSelectedChannelUser_00798F48 && gpSelectedChannelUser_00798F48->f_9C)
    {
        const unsigned int nComposite = D2Win_10155(gpSelectedChannelUser_00798F48->f_9C);
        nFlags = gdwBitMasks[9] & nComposite;
    }

    sub_004F96F0_ControlClearState(gpChatControl_0077B064, gpSelectedChannelUser_00798F48 && !nFlags);
    sub_004F96F0_ControlClearState(gpChatControl_0077B068, gpSelectedChannelUser_00798F48 && nFlags);
}
