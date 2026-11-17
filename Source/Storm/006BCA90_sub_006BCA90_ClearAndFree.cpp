extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

// 0x006BCA90
void __fastcall sub_006BCA90_ClearAndFree(void* pBlock)
{
    memset(pBlock, 0, 0x120);
    FOG_Free(pBlock, ".\\Src\\DataArrays.cpp", 0x4C, 0);
}
