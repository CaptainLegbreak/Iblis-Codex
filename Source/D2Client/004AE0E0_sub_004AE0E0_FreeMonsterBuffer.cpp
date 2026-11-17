#define UNIT_MONSTER 1

struct D2MonsterDataStrc
{
    char unk0x00[0x2C];
    void* pBuffer0x2C;
};

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x10];
    D2MonsterDataStrc* pMonsterData;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0
extern "C" const char gszMonsterSourceFile_006DA5C8[];                                                       // 0x006DA5C8

// 0x004AE0E0
void __fastcall sub_004AE0E0_FreeMonsterBuffer(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData && pMonsterData->pBuffer0x2C)
        {
            FOG_Free(pMonsterData->pBuffer0x2C, gszMonsterSourceFile_006DA5C8, 0x66, 0);
            pMonsterData->pBuffer0x2C = 0;
        }
    }
}
