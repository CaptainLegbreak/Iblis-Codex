struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2InteractInfoStrc
{
    char unk0x00[0x08];
    D2InteractInfoStrc* pNext;
};

struct D2MonsterInteractStrc
{
    D2InteractInfoStrc* pInteractInfo;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x00572BC0
void __fastcall MONSTERAI_FreeMonsterInteract(D2GameStrc* pGame, D2MonsterInteractStrc* pMonInteract)
{
    D2InteractInfoStrc* pInteractInfo = pMonInteract->pInteractInfo;
    while (pInteractInfo)
    {
        D2InteractInfoStrc* pNext = pInteractInfo->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pInteractInfo, ".\\MONSTER\\MonsterAI.cpp", 392, 0);
        pInteractInfo = pNext;
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pMonInteract, ".\\MONSTER\\MonsterAI.cpp", 395, 0);
}
