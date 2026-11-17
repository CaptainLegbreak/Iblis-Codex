#include "D2Sound.h"

struct T00516950;
struct D2SoundNode00516980Strc;
struct Node005169D0;
struct D2SoundNode00516A10Strc;
struct D2SoundNodeStrc;
struct D2FixedFileInfoStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char szD2SoundUtilFile_006DEB68[]; // 0x006DEB68

struct T00516950
{
    void* pData;
    T00516950* pNext;
};

struct D2SoundNode00516980Strc
{
    int nId;
    D2SoundNode00516980Strc* pNext;
};

struct Node005169D0 { int nId; Node005169D0* pNext; };

struct D2SoundNode00516A10Strc
{
    int nKey;
    D2SoundNode00516A10Strc* pNext;
};

struct D2SoundNodeStrc
{
    int nKey;
    D2SoundNodeStrc* pNext;
};

struct D2FixedFileInfoStrc
{
    unsigned int dwSignature;
    unsigned int dwStrucVersion;
    unsigned short wFileVersionMSLow;
    unsigned short wFileVersionMSHigh;
    unsigned short wFileVersionLSLow;
};

int __fastcall sub_00516AC0_ReadVxdVersionResource(const char* szFileName, unsigned long* pSize, void* pBuffer); // 0x00516AC0
extern "C" int __stdcall VerQueryValueA(const void* pBlock, const char* szSubBlock, void** ppBuffer, unsigned int* puLen); // 0x006B01A4

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

// 0x00516980
void __fastcall sub_00516980_RemoveNode(D2SoundNode00516980Strc** ppList, int nId)
{
    D2SoundNode00516980Strc* pPrev = 0;
    for (D2SoundNode00516980Strc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (pNode && pNode->nId == nId)
        {
            if (*ppList == pNode)
            {
                *ppList = pNode->pNext;
            }
            if (pPrev)
            {
                pPrev->pNext = pNode->pNext;
            }
            FOG_Free(pNode, ".\\Src\\D2SoundUtil.cpp", 0xF1, 0);
            return;
        }
        pPrev = pNode;
    }
}

// 0x005169D0
extern "C" __declspec(dllexport) int __fastcall sub_005169D0(Node005169D0* pNode, int nId) {
    for (; pNode; pNode = pNode->pNext) {
        if (pNode->nId == nId) {
            return 1;
        }
    }
    return 0;
}

// 0x005169F0
int __fastcall sub_005169F0_CountEntries(T00516950* pNode)
{
    int nCount = 0;
    while (pNode)
    {
        pNode = pNode->pNext;
        ++nCount;
    }

    return nCount;
}

static __forceinline void RemoveNode(D2SoundNode00516A10Strc** ppList, int nKey)
{
    D2SoundNode00516A10Strc* pPrev = 0;
    for (D2SoundNode00516A10Strc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (pNode && pNode->nKey == nKey)
        {
            if (*ppList == pNode)
            {
                *ppList = pNode->pNext;
            }
            if (pPrev)
            {
                pPrev->pNext = pNode->pNext;
            }
            FOG_Free(pNode, ".\\Src\\D2SoundUtil.cpp", 0xF1, 0);
            return;
        }
        pPrev = pNode;
    }
}

// 0x00516A10
void __fastcall sub_00516A10_FreeList(D2SoundNode00516A10Strc** ppList)
{
    while (*ppList)
    {
        RemoveNode(ppList, (*ppList)->nKey);
    }
}

// 0x00516A70
void __fastcall sub_00516A70_AppendNode(D2SoundNodeStrc** ppList, int nKey)
{
    D2SoundNodeStrc* pNew = (D2SoundNodeStrc*)FOG_Alloc(sizeof(D2SoundNodeStrc), ".\\Src\\D2SoundUtil.cpp", 0x120, 0);
    memset(pNew, 0, sizeof(D2SoundNodeStrc));
    pNew->nKey = nKey;

    for (D2SoundNodeStrc* pNode = *ppList; pNode; pNode = pNode->pNext)
    {
        if (!pNode->pNext)
        {
            pNode->pNext = pNew;
            return;
        }
    }

    *ppList = pNew;
}

// 0x00516C40
unsigned long __fastcall sub_00516C40_GetVersionInfoSize(const char* szPath)
{
    unsigned long nSize = 0;
    if (!sub_00516AC0_ReadVxdVersionResource(szPath, &nSize, 0) && GetLastError() == 0x7A)
    {
        SetLastError(0);
        return nSize;
    }
    return 0;
}

// 0x00516C80
int __fastcall sub_00516C80_GetVersionInfo(const char* szPath, unsigned long nSize, void* pBuffer)
{
    return sub_00516AC0_ReadVxdVersionResource(szPath, &nSize, pBuffer);
}

// 0x00516CA0
int __fastcall sub_00516CA0_GetFileVersion(const char* szPath, unsigned int* pMajor, unsigned int* pMinor, unsigned int* pBuild)
{
    unsigned long nSize = sub_00516C40_GetVersionInfoSize(szPath);
    if (!nSize)
        return 0;

    void* pBuffer = FOG_Alloc(nSize, szD2SoundUtilFile_006DEB68, 0x21C, 0);
    if (!sub_00516C80_GetVersionInfo(szPath, nSize, pBuffer))
    {
        FOG_Free(pBuffer, szD2SoundUtilFile_006DEB68, 0x221, 0);
        return 0;
    }

    D2FixedFileInfoStrc* pInfo;
    unsigned int nInfoLen;
    if (!VerQueryValueA(pBuffer, "\\", (void**)&pInfo, &nInfoLen))
    {
        FOG_Free(pBuffer, szD2SoundUtilFile_006DEB68, 0x229, 0);
        return 0;
    }

    *pMajor = pInfo->wFileVersionMSHigh;
    *pMinor = pInfo->wFileVersionMSLow;
    *pBuild = pInfo->wFileVersionLSLow;
    return 1;
}
