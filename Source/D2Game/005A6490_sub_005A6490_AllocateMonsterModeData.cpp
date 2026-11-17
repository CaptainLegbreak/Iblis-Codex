struct D2GameStrc { char unk_00[0x1C]; void* pMemoryPool; };
struct D2MonsterModeDataStrc { int unk_00; int unk_04; int unk_08; int unk_0C; int unk_10; int unk_14; int unk_18; int unk_1C; int unk_20; };
void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int nZero); // 0x0040B430

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);

// 0x005A6490
D2MonsterModeDataStrc* __fastcall sub_005A6490_AllocateMonsterModeData(D2GameStrc* pGame)
{
    D2MonsterModeDataStrc* pData = (D2MonsterModeDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2MonsterModeDataStrc), ".\\MONSTER\\MonsterMode.cpp", 319, 0);
    memset(pData, 0, sizeof(D2MonsterModeDataStrc));
    return pData;
}
