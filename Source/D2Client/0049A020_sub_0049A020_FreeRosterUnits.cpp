#pragma pack(push, 1)
struct D2RosterUnitStrc
{
    char unk0x00[0xCD];
    D2RosterUnitStrc* pNext;
};
#pragma pack(pop)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
D2RosterUnitStrc* gpRosterUnits_007BF014;                                                                   // 0x007BF014

// 0x0049A020
void __cdecl sub_0049A020_FreeRosterUnits()
{
    D2RosterUnitStrc* pUnit = gpRosterUnits_007BF014;
    while (pUnit)
    {
        D2RosterUnitStrc* pNext = pUnit->pNext;
        FOG_Free(pUnit, ".\\UI\\Party.cpp", 0x108, 0);
        pUnit = pNext;
    }
    gpRosterUnits_007BF014 = 0;
}
