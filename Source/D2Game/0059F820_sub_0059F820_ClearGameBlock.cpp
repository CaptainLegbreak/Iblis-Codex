struct D2GameStrc
{
    char unk0x0000[0x1920];
    char unk0x1920[0x7A00];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

// 0x0059F820
void __fastcall sub_0059F820_ClearGameBlock(D2GameStrc* pGame)
{
    memset(pGame->unk0x1920, 0, sizeof(pGame->unk0x1920));
}

// 0x0059FFF0
unsigned short __fastcall sub_0059FFF0_ToWord(unsigned short nValue)
{
    return nValue;
}
