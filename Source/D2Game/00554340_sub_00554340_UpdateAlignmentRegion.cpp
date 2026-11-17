extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2StatListStrc;
struct D2ActiveRoomStrc;
struct D2MonsterRegionStrc;

struct D2GameStrc
{
    char unk0x00[0xF0];
    D2MonsterRegionStrc* pMonReg[1024];
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    char unk0x10[0x70];
    D2GameStrc* pGame;
};

#define UNIT_MONSTER 1
#define UNIT_ALIGNMENT_EVIL 0
#define UNIT_ALIGNMENT_GOOD 2
#define UNIT_NUM_ALIGNMENT 3
#define UNIT_ALIGNMENT_UNASSIGNED 4
#define MONSTER_HYDRA1 351
#define MONSTER_HYDRA2 352
#define MONSTER_HYDRA3 353
#define STATE_ALIGNMENT 105
#define STAT_ALIGNMENT 172

void __fastcall sub_00547DD0(D2MonsterRegionStrc** pMonReg, D2UnitStrc* pUnit, int nAlignment, int nAlignNew); // 0x00547DD0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall sub_00619EE0(D2ActiveRoomStrc* pRoom);                                                       // 0x00619EE0
void __stdcall sub_00619F20(D2ActiveRoomStrc* pRoom);                                                       // 0x00619F20
int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40
void __stdcall D2Common_10214(D2UnitStrc* pUnit);                                                           // 0x00649CA0
int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag);                                     // 0x00451F30
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState);                                    // 0x006252D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer);            // 0x00627150
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet);                          // 0x00639E30

// 0x00554340
static void __stdcall sub_00554340_UpdateAlignmentRegion(D2UnitStrc* pUnit, int nAlignment, int nAlignNew, int bUpdate)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pGame)
    {
        return;
    }
    if (bUpdate)
    {
        sub_00547DD0(pUnit->pGame->pMonReg, pUnit, nAlignment, nAlignNew);
    }
    if (nAlignment == nAlignNew)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }
    if (nAlignNew == UNIT_ALIGNMENT_GOOD)
    {
        sub_00619EE0(pRoom);
    }
    else if (nAlignment == UNIT_ALIGNMENT_GOOD)
    {
        sub_00619F20(pRoom);
    }
    if (!MONSTERS_IsDead(pUnit))
    {
        D2Common_10214(pUnit);
    }
}

// 0x005543B0
void __fastcall sub_005543B0_AssignAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int bUpdate)
{
    const int nNew = nAlignNew;
    int nAlignment = UNIT_ALIGNMENT_UNASSIGNED;
    if (!pUnit)
    {
        return;
    }
    D2_ASSERT(nNew < UNIT_NUM_ALIGNMENT, 2994);
    const int nClassId = pUnit->dwClassId;
    if (nClassId != MONSTER_HYDRA1 && nClassId != MONSTER_HYDRA2 && nClassId != MONSTER_HYDRA3 && nNew == UNIT_ALIGNMENT_EVIL && sub_00451F30_TestUnitFlag(pUnit, 0x80000000))
    {
        return;
    }
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_ALIGNMENT);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(pUnit->pMemoryPool, 0, 0, pUnit->dwUnitType, pUnit->dwUnitId);
        D2_ASSERT(pStatList, 3012);
        STATLIST_SetState(pStatList, STATE_ALIGNMENT);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, STATE_ALIGNMENT, 1);
    }
    else
    {
        nAlignment = STATLIST_GetStatValue(pStatList, STAT_ALIGNMENT, 0);
    }
    STATLIST_SetStat(pStatList, STAT_ALIGNMENT, nNew, 0);
    STATES_ToggleGfxStateFlag(pUnit, STATE_ALIGNMENT, 1);
    sub_00554340_UpdateAlignmentRegion(pUnit, nAlignment, nNew, bUpdate);
}
