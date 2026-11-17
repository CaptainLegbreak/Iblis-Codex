struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2GameStrc { unsigned char padding[0x6D]; unsigned char difficulty; };
struct D2PlayerDataStrc { unsigned char padding[0x10]; D2BitBufferStrc* questFlags[3]; };
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* unit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* flags, int quest, int state); // 0x0065C310
void __fastcall SUNIT_AttachSound(D2UnitStrc* unit, int updateType, D2UnitStrc* updateUnit); // 0x00553380

// 0x0058B730
int __fastcall sub_0058B730_AttachCompletionSound(D2GameStrc* game, D2UnitStrc* player, void* unused)
{
    D2BitBufferStrc* flags = UNITS_GetPlayerData(player)->questFlags[game->difficulty];
    if (QUESTRECORD_GetQuestState(flags, 38, 13))
        SUNIT_AttachSound(player, 82, player);
    return 0;
}
