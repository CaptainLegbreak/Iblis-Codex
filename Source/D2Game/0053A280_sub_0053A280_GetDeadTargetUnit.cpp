extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GameStrc;
struct D2UnitStrc;

struct D2ClientStrc
{
    char unk0x000[0x198];
    int nDeadTargetType;
    int nDeadTargetGUID;
    char unk0x1A0[0x3D4 - 0x1A0];
    unsigned int dwFlags;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient);                             // 0x005387F0

// 0x0053A280
D2UnitStrc* __fastcall sub_0053A280_GetDeadTargetUnit(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x7B9);

    if (!(pClient->dwFlags & 2))
    {
        return 0;
    }

    D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, pClient->nDeadTargetType, pClient->nDeadTargetGUID);
    if (pUnit)
    {
        if (CLIENTS_IsInUnitsRoom(pUnit, pClient))
        {
            return pUnit;
        }
        pUnit = 0;
    }
    pClient->dwFlags &= ~2;
    return pUnit;
}
