struct D2Block006BD040Strc
{
    int n00;
    int n04;
    int n08;
    int n0C;
};
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

// 0x006BD040
D2Block006BD040Strc* __stdcall sub_006BD040_AllocBlock(const char* szFile, int nLine)
{
    D2Block006BD040Strc* pBlock = (D2Block006BD040Strc*)FOG_AllocPool(0, 0x10, szFile, nLine, 0);
    memset(pBlock, 0, sizeof(D2Block006BD040Strc));
    return pBlock;
}
