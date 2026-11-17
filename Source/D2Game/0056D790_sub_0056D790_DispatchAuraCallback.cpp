struct D2GameStrc;
struct D2UnitStrc;
struct D2SkillsTxt { char unknown0[0x80]; short auraState; char unknown82[0x1ba]; };
struct D2StatesTxt { char unknown0[0x36]; short callback; };
struct D2DataTablesStrc {
    char unknown0[0xc4]; int stateCount;
    char unknownc8[0xad0]; D2SkillsTxt* skills;
    int unknownb9c; int skillCount;
};
typedef int (__fastcall *SkillCallback)(D2GameStrc*, D2UnitStrc*, int, int);
extern D2DataTablesStrc* gpDataTables_00744304; // 0x00744304
extern const SkillCallback gpSkillCallbacks_007322B0[]; // 0x007322B0
D2StatesTxt* __fastcall sub_00452040_GetStatesTxtRecord(int); // 0x00452040
static __forceinline SkillCallback GetSkillCallback(short nIndex)
{
    if (nIndex < 0)
        return 0;
    if (nIndex >= 191)
        return 0;
    return gpSkillCallbacks_007322B0[nIndex];
}

// 0x0056D790
void __fastcall sub_0056D790_DispatchAuraCallback(D2GameStrc* game, D2UnitStrc* unit, int skill, int level)
{
    if (skill <= 0)
        return;
    if (skill >= gpDataTables_00744304->skillCount)
        return;
    D2SkillsTxt* record = &gpDataTables_00744304->skills[skill];
    if (!record)
        return;
    const short state = record->auraState;
    if (state < 0)
        return;
    if (state >= gpDataTables_00744304->stateCount)
        return;
    D2StatesTxt* states = sub_00452040_GetStatesTxtRecord(state);
    if (!states)
        return;
    SkillCallback callback = GetSkillCallback(states->callback);
    if (!callback)
        return;
    callback(game, unit, skill, level);
}
