int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

// 0x005193C0
int __fastcall sub_005193C0_FreeCachedFile(void* pData, unsigned int nSize)
{
    if (!pData)
        return 0;
    SMemFree(pData, ".\\CACHE.CPP", 0x16F, 0);
    return 1;
}
