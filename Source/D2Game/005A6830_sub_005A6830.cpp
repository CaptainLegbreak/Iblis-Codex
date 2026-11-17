struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2MonStatsTxt;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0xC4 - 0x08];
    unsigned int dwFlags;
};

struct D2ModeChangeStrc
{
    int nMode;
    D2UnitStrc* pUnit;
    D2UnitStrc* pTargetUnit;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                    // 0x00451F80
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
void __stdcall sub_6FC631B0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFlag, D2ModeChangeStrc* pModeChange); // 0x005A6600

#define MONSTER_BONEWALL 344
#define UNITFLAG_NOTC 0x00020000

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005A6830
void __fastcall sub_005A6830(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    D2_ASSERT(pUnit, 493);

    if (UNIT_HasFlag(pUnit, UNITFLAG_NOTC))
    {
        return;
    }

    D2_ASSERT(pUnit->dwClassId != MONSTER_BONEWALL, 504);

    if (!COLLISION_CheckMask(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0x801))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pRoom, 511);

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        D2_ASSERT(pMonStatsTxtRecord, 516);

        sub_6FC631B0(pGame, pUnit, 0, pModeChange);
    }
}
