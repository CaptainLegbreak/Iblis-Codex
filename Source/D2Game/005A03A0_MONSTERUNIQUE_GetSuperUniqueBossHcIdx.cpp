struct D2GameStrc;

struct D2MonsterDataStrc
{
    char unk0x00[0x16];
    unsigned short nTypeFlag;
    char unk0x18[0x0E];
    short wBossHcIdx;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

#define UNIT_MONSTER 1
#define MONTYPEFLAG_SUPERUNIQUE 2

struct Data005A01E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned short wUnknown24;
    short sValue26;
};

struct Unit005A01E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data005A01E0* pData;
};

extern "C" __declspec(dllexport) short __fastcall sub_005A01E0(Unit005A01E0* pUnit) {
    Data005A01E0* pData = (pUnit && pUnit->nType == 1) ? pUnit->pData : 0;
    if (!pData) {
        return -1;
    }
    return pData->sValue26;
}

// 0x005A03A0
int __fastcall MONSTERUNIQUE_GetSuperUniqueBossHcIdx(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : 6;
    D2MonsterDataStrc* pMonsterData = (nType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData || !(pMonsterData->nTypeFlag & MONTYPEFLAG_SUPERUNIQUE))
    {
        return -1;
    }

    return sub_005A01E0((Unit005A01E0*)pUnit);
}
