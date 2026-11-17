extern "C" int gnTable_00727A28[5];                                                                         // 0x00727A28
extern "C" unsigned int gnTableCount_00727A3C;                                                              // 0x00727A3C

// 0x004C2150
int __fastcall sub_004C2150_FindInTable(int nValue)
{
    for (unsigned int i = 0; i < gnTableCount_00727A3C; ++i)
    {
        if (nValue == gnTable_00727A28[i])
            return 4;
    }
    return 3;
}

#include "gen/data/Source/D2Client/004C2150_sub_004C2150_FindInTable.inc"
