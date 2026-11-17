#pragma function(memset)

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

// 0x006197D0
void* __fastcall sub_006197D0_AllocCleared80(void* pMemPool)
{
    void* pBlock = FOG_AllocPool(pMemPool, 0x80, ".\\DUNGEON\\Dungeon.cpp", 0xF5, 0);
    memset(pBlock, 0, 0x80);
    return pBlock;
}
