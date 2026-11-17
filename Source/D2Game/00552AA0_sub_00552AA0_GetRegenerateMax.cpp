struct D2ObjectsTxt
{
    char unk0x00[0xD8];
    unsigned int dwFrameCnt[8];
    char unk0xF8[0x10];
    unsigned char nCycleAnim[8];
    char unk0x110[0x2F];
    unsigned char nMode[8];
    char unk0x147[0x31];
    int dwParm[8];
    char unk0x198[0x1B];
    unsigned char nOperateFn;
};

// 0x00552AA0
unsigned char __fastcall sub_00552AA0_GetRegenerateMax(D2ObjectsTxt* pObjectsTxtRecord)
{
    return 2 * pObjectsTxtRecord->dwParm[2];
}
