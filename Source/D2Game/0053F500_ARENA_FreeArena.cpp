struct D2ArenaStrc;

struct D2GameStrc
{
    char unk0x0000[0x1C];
    void* pMemoryPool;
    char unk0x0020[0x1D08];
    D2ArenaStrc* pArenaCtrl;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x0053F500
void __fastcall ARENA_FreeArena(D2GameStrc* pGame)
{
    if (pGame->pArenaCtrl)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pGame->pArenaCtrl, ".\\GAME\\Arena.cpp", 0x40, 0);
        pGame->pArenaCtrl = 0;
    }
}
