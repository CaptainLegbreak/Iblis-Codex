struct Unicode
{
    unsigned short wChar;
};

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

unsigned char gbFlag_007BCC06;                                                                              // 0x007BCC06
extern int gdwGlobal_007BCBF0;                                                                              // 0x007BCBF0

// 0x00486640
static __forceinline void sub_00486640_AppendStrings(Unicode* pText)
{
    const Unicode* pFirst = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pSecond = D2LANG_GetStringFromTblIndex(0x4FD6);
    sub_00526700(pText, pSecond);
    sub_00526700(pText, pFirst);
}

void __fastcall sub_M112_Emit_00486640(Unicode* pText)
{
    sub_00486640_AppendStrings(pText);
}

// 0x00486AD0
void __cdecl sub_00486AD0_ToggleFlag()
{
    gbFlag_007BCC06 = gbFlag_007BCC06 == 0;
}

// 0x00486D70
int __cdecl sub_00486D70_IsNotState11()
{
    return gdwGlobal_007BCBF0 != 0xB;
}

// 0x00486D80
int __cdecl sub_00486D80_IsState1Or2()
{
    if (gdwGlobal_007BCBF0 == 1 || gdwGlobal_007BCBF0 == 2)
    {
        return 1;
    }
    return 0;
}
