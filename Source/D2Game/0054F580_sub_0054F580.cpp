struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2TimerArg2Strc
{
    int unk0x00;
    D2TimerArg2Strc* pNext;
};

struct D2TimerArgStrc
{
    D2TimerArg2Strc* unk0x00;
};

void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480

// 0x0054F580
void __fastcall sub_0054F580(D2GameStrc* pGame, D2TimerArgStrc* pTimerArg)
{
    D2TimerArg2Strc* pArg = pTimerArg->unk0x00;
    while (pArg)
    {
        D2TimerArg2Strc* pNext = pArg->pNext;
        FOG_FreePool(pGame->pMemoryPool, pArg, ".\\OBJECTS\\Objects.cpp", 462, 0);
        pArg = pNext;
    }

    FOG_FreePool(pGame->pMemoryPool, pTimerArg, ".\\OBJECTS\\Objects.cpp", 465, 0);
}
