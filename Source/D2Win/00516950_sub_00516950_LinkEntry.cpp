extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

extern "C" const char szD2SoundUtilFile_006DEB68[];                                                         // 0x006DEB68

struct T00516950
{
    void* pData;
    T00516950* pNext;
};

// 0x00516950
void __fastcall sub_00516950_LinkEntry(T00516950** ppList, void* pData)
{
    T00516950* pNode = (T00516950*)FOG_Alloc(sizeof(T00516950), szD2SoundUtilFile_006DEB68, 0xD5, 0);
    memset(pNode, 0, sizeof(T00516950));
    T00516950* pHead = *ppList;
    pNode->pData = pData;
    pNode->pNext = pHead;
    *ppList = pNode;
}
