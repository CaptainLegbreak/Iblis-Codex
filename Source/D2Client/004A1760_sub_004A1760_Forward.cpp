struct D2UiEntry10Strc
{
    int nKey;
    int nId;
    int unk0x08;
    int unk0x0C;
};

int __cdecl sub_004A08C0();                                                                                 // 0x004A08C0
extern int gnIndex_007BF2B9;                                                                                // 0x007BF2B9
extern D2UiEntry10Strc gaUiEntries_00723F38[41];                                                            // 0x00723F38

// 0x004A1760
int __cdecl sub_004A1760_Forward()
{
    return sub_004A08C0();
}

// 0x004A18E0
static __forceinline void sub_004A18E0_SetIndex(int nIndex)
{
    gnIndex_007BF2B9 = nIndex;
}

// 0x004A1930
static __forceinline int sub_004A1930_FindEntryIndex(int nId)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaUiEntries_00723F38[i].nId == nId)
            return i;
    }
    return -1;
}

int __fastcall sub_M115_Emit_004A18E0(int nIndex, int nId)
{
    sub_004A18E0_SetIndex(nIndex);
    return sub_004A1930_FindEntryIndex(nId);
}
