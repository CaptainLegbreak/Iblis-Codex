struct D2UnitStrc;

struct D2RosterPetNodeStrc
{
    int nValue;
    int nType;
    int nKey;
    int nArg;
    int unk0x10[3];
    int nInit;
    int nClear;
    int unk0x24[3];
    D2RosterPetNodeStrc* pNext;
};

struct D2Packet81ArgsStrc
{
    int nArg0C;
    int nArg10;
    int nZero;
};

struct D2HirelingInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int nSeed;
    int unk0x08[2];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit);                                       // 0x004647D0
void __fastcall sub_00478AB0_RemoveType7(int nUnused, int nKey);                                            // 0x00478AB0
void __fastcall sub_00478B10_SetRosterEntry(int nKey, int nArg, int nType, int nValue);                     // 0x00478B10
void __fastcall sub_004AE210_SetMonsterLight(D2UnitStrc* pUnit);                                            // 0x004AE210
void __fastcall sub_004B1090_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo);                    // 0x004B1090
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690
extern D2RosterPetNodeStrc* gpRosterPets_007BB5BC;                                                          // 0x007BB5BC

// 0x00478BB0
void __fastcall sub_00478BB0(int nKey, int nArg, int nType, int nValue, D2Packet81ArgsStrc* pArgs)
{
    if (nType == 7)
        sub_00478AB0_RemoveType7(nKey, nKey);

    D2RosterPetNodeStrc* pNode;
    for (pNode = gpRosterPets_007BB5BC; pNode && pNode->nKey != nKey; pNode = pNode->pNext)
        ;

    sub_00478B10_SetRosterEntry(nKey, nArg, nType, nValue);

    for (pNode = gpRosterPets_007BB5BC; pNode && pNode->nKey != nKey; pNode = pNode->pNext)
        ;
    D2_ASSERT(pNode, 0x95);

    pNode->nKey = nKey;
    pNode->nArg = nArg;
    pNode->nType = nType;
    pNode->unk0x24[0] = pArgs->nArg0C;
    pNode->unk0x24[1] = pArgs->nArg10;
    pNode->unk0x24[2] = pArgs->nZero;

    if (nType == 7)
    {
        D2HirelingInfoStrc tInfo;
        tInfo.nSeed = pArgs->nArg0C;
        tInfo.f_0 = (unsigned short)pArgs->nArg10;
        D2UnitStrc* pUnit = sub_00463990(nKey, 1);
        if (pUnit)
        {
            sub_004B1090_InitHireling(pUnit, &tInfo);
            sub_004647D0_UpdateAttackableFlag(pUnit);
            sub_004AE210_SetMonsterLight(pUnit);
            UNITS_ChangeAnimMode(pUnit, 1);
        }
    }
}
