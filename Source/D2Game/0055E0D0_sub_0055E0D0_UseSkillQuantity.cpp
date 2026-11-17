extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SkillStrc;
struct D2ClientStrc;

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

void __fastcall sub_0053C520_SendToClient(D2ClientStrc* pClient, char nUnitType);                           // 0x0053C520
D2ClientStrc* __fastcall sub_005531C0_MakeQuantityPacket(D2UnitStrc* pUnit, const char* szFile, int nLine, int nUnitId, int nSkillId, int nQuantity); // 0x005531C0
void __fastcall sub_005701B0_ResetRightSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID, int nArg);   // 0x005701B0
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit);                                              // 0x006201D0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);               // 0x006439B0
int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill);                                                      // 0x006450F0
void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity);                                      // 0x00645120

static __forceinline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static __forceinline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static void __stdcall sub_0055E0D0_UseSkillQuantity(D2UnitStrc* pUnit, int nSkillId);
static void __declspec(noinline) __stdcall sub_0055E0D0_UseSkillQuantity(D2UnitStrc* pUnit, int nSkillId);

// 0x0055E0D0
static void __stdcall sub_0055E0D0_UseSkillQuantity(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        int nQuantity = SKILLS_GetQuantity(pSkill) - 1;
        if (nQuantity <= 0)
        {
            if (UNITS_GetRightSkill(pUnit) == pSkill)
            {
                sub_005701B0_ResetRightSkill(pUnit, 0, 0, -1);
            }
            nQuantity = 0;
        }

        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitId = UNITS_GetUnitId(pUnit);
        const int nUnitType = sub_0044BE50(pUnit);
        sub_0053C520_SendToClient(sub_005531C0_MakeQuantityPacket(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xFC2, nUnitId, nSkillId, nQuantity), nUnitType);
    }
    else
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0xFC4);
        exit(-1);
    }
}

void __fastcall sub_BF69_Emit_0055E0D0(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit && nSkillId)
    {
        sub_0055E0D0_UseSkillQuantity(pUnit, nSkillId);
        sub_0055E0D0_UseSkillQuantity(pUnit, nSkillId + 1);
    }
}
