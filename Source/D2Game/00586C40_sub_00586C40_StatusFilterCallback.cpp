struct D2QuestDataStrc;
struct D2UnitStrc;
struct D2BitBufferStrc;

// 0x00586C40
bool __fastcall sub_00586C40_StatusFilterCallback(D2QuestDataStrc* quest, D2UnitStrc* player, D2BitBufferStrc* globalFlags, D2BitBufferStrc* flags, unsigned char* status)
{
    *status = 0;
    return false;
}
