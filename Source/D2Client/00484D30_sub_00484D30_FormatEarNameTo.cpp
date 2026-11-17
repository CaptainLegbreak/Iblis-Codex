struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}

    static Unicode* __fastcall strcpy(Unicode* dest, const Unicode* src);                                   // 0x005267E0
    static Unicode* __fastcall win2Unicode(Unicode* dest, const char* src, int count);                      // 0x00526F20
};

struct D2UnitStrc;

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70
char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem);                                                        // 0x00628340
int __cdecl sub_00525150();                                                                         // 0x00525150
void __fastcall sub_005272B0_FormatText(Unicode* pDst, const Unicode* pText, const Unicode* pFormat, int nMaxLength, int nLanguage); // 0x005272B0

// 0x00484C90
static __declspec(noinline) int sub_00484C90_FormatEarName(Unicode* pText, D2UnitStrc* pItem)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x6EA, ".\\UI\\inv.cpp"))
    {
        const int nQuality = ITEMS_GetItemQuality(pItem);
        if (nQuality >= 5 && nQuality <= 9)
        {
            return 0;
        }

        Unicode wszName[0x200];
        Unicode wszFormatted[0x200];
        Unicode::win2Unicode(wszName, ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(wszFormatted, wszName, pText, 0x200, sub_00525150());
        Unicode::strcpy(pText, wszFormatted);
        return 1;
    }

    return 0;
}

// 0x00484D30
static __declspec(noinline) int __stdcall sub_00484D30_FormatEarNameTo(Unicode* pOut, const Unicode* pFormat, D2UnitStrc* pItem)
{
    if (ITEMS_CheckItemFlag(pItem, 0x1000000, 0x70B, ".\\UI\\inv.cpp"))
    {
        Unicode wszName[0x200];
        Unicode::win2Unicode(wszName, ITEMS_GetEarName(pItem), 0x20);
        sub_005272B0_FormatText(pOut, wszName, pFormat, 0x200, sub_00525150());
        return 1;
    }

    return 0;
}

int __fastcall sub_A15_Emit_00484C90(Unicode* pText, D2UnitStrc* pItem)
{
    return sub_00484C90_FormatEarName(pText, pItem);
}

int __fastcall sub_A15_Emit_00484D30(Unicode* pOut, const Unicode* pFormat, D2UnitStrc* pItem)
{
    return sub_00484D30_FormatEarNameTo(pOut, pFormat, pItem);
}
