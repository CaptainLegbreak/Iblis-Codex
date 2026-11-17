struct D2DifficultyLevelsTxt
{
    char unk0x00[0x1C];
    int dwAiCurseDiv;
    char unk0x20[0x38];
};

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30
unsigned char __cdecl sub_0044DCD0_GetDifficulty();                                                         // 0x0044DCD0

// 0x004E6E80
static __declspec(noinline) int sub_004E6E80_ApplyAiCurseDivisor(int nValue)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxt = DATATBLS_GetDifficultyLevelsTxtRecord(sub_0044DCD0_GetDifficulty());
    const int nDivisor = pDifficultyLevelsTxt->dwAiCurseDiv;
    if (nDivisor > 0)
        nValue /= nDivisor;
    return nValue;
}

int __stdcall sub_M125_Emit_004E6E80(int nUnused1, int nUnused2, int nUnused3, int nValue)
{
    return sub_004E6E80_ApplyAiCurseDivisor(nValue);
}
