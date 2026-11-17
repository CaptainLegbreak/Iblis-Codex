struct D2GameStrc;
struct D2InventoryStrc;

struct D2UnitStrc
{
    int dwUnitType;
    unsigned int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x50];
    D2InventoryStrc* pInventory;
    char unk0x64[0x60];
    unsigned int dwFlags;
    unsigned int dwFlagEx;
};

void __fastcall D2GAME_NPC_HealPlayer_6FCCB080(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc);       // 0x00578D30
int gnNpcGUID_0088CAC4;                                                                                      // 0x0088CAC4

// 0x00578E70
void __fastcall D2GAME_NPC_Heal_6FCCB220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc)
{
    const int nGUID = !pNpc ? -1 : pNpc->dwUnitId;

    gnNpcGUID_0088CAC4 = nGUID;
    if (pNpc)
    {
        const int nClass = pNpc->dwClassId;
        if (nClass == 148 || nClass == 513 || nClass == 176 || nClass == 178 || nClass == 405 || nClass == 255)
        {
            D2GAME_NPC_HealPlayer_6FCCB080(pGame, pUnit, pNpc);
        }
    }
}
