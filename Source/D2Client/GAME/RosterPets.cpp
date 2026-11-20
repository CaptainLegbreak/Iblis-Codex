#include "D2Client.h"
#include "D2Structs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2RosterPetNodeStrc;
struct D2Packet81ArgsStrc;
struct D2HirelingInfoStrc;


int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
extern D2RosterPetNodeStrc* gpRosterPets_007BB5BC; // 0x007BB5BC

struct D2HirelingInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int nSeed;
    int unk0x08[2];
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType); // 0x00463990
void __fastcall sub_004647D0_UpdateAttackableFlag(D2UnitStrc* pUnit); // 0x004647D0
void __fastcall sub_00478AB0_RemoveType7(int nUnused, int nKey); // 0x00478AB0
void __fastcall sub_00478B10_SetRosterEntry(int nKey, int nArg, int nType, int nValue); // 0x00478B10
void __fastcall sub_004AE210_SetMonsterLight(D2UnitStrc* pUnit); // 0x004AE210
void __fastcall sub_004B1090_InitHireling(D2UnitStrc* pUnit, D2HirelingInfoStrc* pInfo); // 0x004B1090
int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

// 0x00478A90
D2RosterPetNodeStrc* __fastcall sub_00478A90_FindRosterPet(int nKey)
{
    for (D2RosterPetNodeStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            return pNode;
        }
    }
    return 0;
}

// 0x00478C90
void __fastcall sub_00478C90_DropPetEntry(int nKey)
{
    D2RosterPetNodeStrc* pPrev = 0;
    for (D2RosterPetNodeStrc* pNode = gpRosterPets_007BB5BC; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKey == nKey)
        {
            if (pNode->nType == 7)
            {
                D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
                if (pNode->nArg == (!pPlayer ? -1 : pPlayer->dwUnitId))
                {
                    pNode->nClear = 1;
                    return;
                }
            }
            if (pPrev)
                pPrev->pNext = pNode->pNext;
            else
                gpRosterPets_007BB5BC = pNode->pNext;
            FOG_Free(pNode, ".\\GAME\\RosterPets.cpp", 0xD1, 0);
            return;
        }
        pPrev = pNode;
    }
}

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
