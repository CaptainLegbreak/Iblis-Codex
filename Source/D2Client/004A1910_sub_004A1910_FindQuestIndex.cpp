struct D2UiEntry10Strc
{
    int nKey;
    int nId;
    int unk0x08;
    int unk0x0C;
};

extern int gnIndex_007BF2B9;                                                                                // 0x007BF2B9
extern D2UiEntry10Strc gaUiEntries_00723F38[41];                                                            // 0x00723F38

// 0x004A1910
static __forceinline int sub_004A1910_FindQuestIndex(int nKey)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaUiEntries_00723F38[i].nKey == nKey)
            return i;
    }
    return -1;
}

int __fastcall sub_M224_Emit_004A1910(int nIndex, int nKey)
{
    gnIndex_007BF2B9 = nIndex;
    return sub_004A1910_FindQuestIndex(nKey);
}
