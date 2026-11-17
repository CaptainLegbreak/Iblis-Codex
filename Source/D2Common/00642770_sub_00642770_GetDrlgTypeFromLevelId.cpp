struct D2DrlgLevelStrc
{
    char unk0x000[0x1AC];
    D2DrlgLevelStrc* pNextLevel;
};

struct D2DrlgStrc
{
    char unk0x000[0x47C];
    D2DrlgLevelStrc* pLevel;
};

struct D2LevelDefBin
{
    char unk0x00[0x30];
    unsigned int dwDrlgType;
};

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470

// 0x00642770
int __fastcall sub_00642770_GetDrlgTypeFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwDrlgType;
}

// 0x00642780
static __forceinline D2DrlgLevelStrc* sub_00642780_WalkLevels(D2DrlgStrc* pDrlg)
{
    D2DrlgLevelStrc* pLevel = pDrlg->pLevel;
    while (pLevel)
    {
        pLevel = pLevel->pNextLevel;
    }
    return pLevel;
}

D2DrlgLevelStrc* __stdcall sub_M121_Emit_00642780(D2DrlgStrc* pDrlg) { return sub_00642780_WalkLevels(pDrlg); }

// 0x006429D0
void __cdecl sub_006429D0_Nop()
{
}
