struct D2GameStrc;

struct D2UnitStrc
{
    char unk0x00[0xC8];
    unsigned int dwFlagEx;
};

extern unsigned int gdwItemFlags_00738C4C[8];                                                               // 0x00738C4C
extern unsigned int gnItemFlagCount_00738C6C;                                                               // 0x00738C6C
extern unsigned int gdwItemCmdFlags_00738C70[21];                                                           // 0x00738C70
extern unsigned int gnItemCmdFlagCount_00738CC4;                                                            // 0x00738CC4
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0
void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet);                                // 0x00628170

// 0x005979B0
void __fastcall D2GAME_ResetSomeItemFlags_6FC415F0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (pItem)
    {
        pItem->dwFlagEx &= ~0x14;
    }

    for (unsigned int i = 0; i < gnItemCmdFlagCount_00738CC4; ++i)
    {
        ITEMS_SetItemCMDFlag(pItem, gdwItemCmdFlags_00738C70[i], 0);
    }

    for (unsigned int i = 0; i < gnItemFlagCount_00738C6C; ++i)
    {
        ITEMS_SetItemFlag(pItem, gdwItemFlags_00738C4C[i], 0);
    }
}

#include "gen/data/Source/D2Game/005979B0_D2GAME_ResetSomeItemFlags_6FC415F0.inc"
