#ifdef MOVED_TEST
#define ROSTER_GAP 0x29
#else
#define ROSTER_GAP 0x25
#endif
struct D2RosterSlotStrc
{
    int bFlag;
    int nX;
    int nY;
    int unk0x0C;
    int nCount;
    int nType;
    int nState;
    int bActive;
};
#pragma pack(push,1)
struct D2RosterUnitStrc
{
    D2RosterSlotStrc aSlots[5];
    char unk0xA0[ROSTER_GAP];
    int nId;
    char unk0xC9[4];
    D2RosterUnitStrc* pNext;
};
#pragma pack(pop)
extern D2RosterUnitStrc* gpRosterUnits_007BF014;  // 0x007BF014
// 0x00499DE0
D2RosterUnitStrc* __fastcall sub_00499DE0_FindRoster(int nId) {
 D2RosterUnitStrc* pFound=gpRosterUnits_007BF014;
 while(pFound) {
  if(pFound->nId == nId) return pFound;
  pFound=pFound->pNext;
 }
 return 0;
}
