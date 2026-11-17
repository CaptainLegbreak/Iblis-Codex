struct Unicode
{
    unsigned short ch;
};

#pragma pack(push, 2)
struct D2TextEntryStrc
{
    unsigned short wStringId;
    int nLength;
    int nX;
    int nY;
    int nWidth;
};
#pragma pack(pop)

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

extern D2TextEntryStrc gaTextEntries_00724824[15];                                                          // 0x00724824

// 0x004A7AA0
void __cdecl sub_004A7AA0_InitTextEntryLengths()
{
    for (unsigned int i = 0; i < sizeof(gaTextEntries_00724824) / sizeof(gaTextEntries_00724824[0]); ++i)
    {
        gaTextEntries_00724824[i].nLength = sub_00526800(D2LANG_GetStringFromTblIndex(gaTextEntries_00724824[i].wStringId));
    }
}

#include "gen/data/Source/D2Client/004A7AA0_sub_004A7AA0_InitTextEntryLengths.inc"
