struct D2UnitStrc;
struct D2BitBufferStrc;
struct D2QuestDataStrc { char unknown0[9]; unsigned char notIntro, active, lastState, state; };
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc*, int, int); // 0x0065C310
// 0x0058AF00
bool __fastcall sub_0058AF00_GetQuestStatus(D2QuestDataStrc* quest, D2UnitStrc* unit, D2BitBufferStrc* globalFlags, D2BitBufferStrc* flags, unsigned char* status)
{
    *status = 0;
    if (QUESTRECORD_GetQuestState(flags, 38, 0)) return true;
    if (QUESTRECORD_GetQuestState(flags, 38, 1) || QUESTRECORD_GetQuestState(flags, 38, 13)) {
        *status = QUESTRECORD_GetQuestState(flags, 38, 4) != 0 ? 5 : 4;
    } else if (quest->notIntro) {
        if (QUESTRECORD_GetQuestState(flags, 38, 14)) { *status = 12; return true; }
        if (quest->state < 4) { *status = quest->lastState; return true; }
    }
    return true;
}
