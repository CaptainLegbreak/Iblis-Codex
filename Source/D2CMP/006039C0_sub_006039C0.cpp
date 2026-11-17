struct D2CriticalSectionStrc
{
    int nOpaque[6];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2StormNodeStrc
{
    D2StormLinkStrc f_0;
};

struct D2CelEntryStrc : D2StormNodeStrc
{
    int nArg8;
    unsigned int nHeight;
    unsigned int nWidth;
    unsigned int nSize;
    int nArg6;
    int nArg7;
    void* pData;
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_00602BF0_DeleteAll();                                                                          // 0x00602BF0
};

struct D2StormEntry38Strc
{
    char unk0x00[0x18];
    unsigned int dwFlags;
    int nType;
    int nData;
    unsigned int nCount;
    unsigned int nDirections;
    D2StormNodeListStrc tList;
};

struct D2CelFileStrc
{
    int nVersion;
    int dwFlags;
    int nFormat;
    int nTermination;
    int nDirections;
    int nCelsPerDirection;
    void* pCells[1];
};

typedef void (__fastcall* CelFileBuildFn)(D2StormEntry38Strc* pList, D2CelFileStrc* pCelFile);
extern CelFileBuildFn gpfnCelFileBuilders_006E3680[];                                                       // 0x006E3680
void __fastcall sub_0060D190_BuildCelFileWithData(D2StormEntry38Strc* pList, D2CelFileStrc* pCelFile);     // 0x0060D190

struct D2GameDataTableStrc
{
    virtual void InternalDelete(D2StormEntry38Strc* pNode);
    char unk0x04[0x40];
    int f_44;
    char unk0x48[0x08];
    D2CriticalSectionStrc m_sync;

    D2StormEntry38Strc* sub_006030E0_InternalFind(unsigned int nHashVal, const int& tKey);                 // 0x006030E0
    void sub_006021E0_UnlinkNode(D2StormEntry38Strc* pNode);                                                // 0x006021E0
    void SyncEnterLock(int* pLockHandle, int bForWriting)
    {
        EnterCriticalSection(&m_sync);
        *pLockHandle = bForWriting ? 1 : -1;
    }
    void SyncLeaveLock(int nLockHandle)
    {
        if (nLockHandle)
            LeaveCriticalSection(&m_sync);
    }
    D2StormEntry38Strc* Ptr(unsigned int hHandle)
    {
        return sub_006030E0_InternalFind(hHandle, f_44);
    }
    D2StormEntry38Strc* Lock(unsigned int hHandle, int* pLockHandle, int bForWriting)
    {
        SyncEnterLock(pLockHandle, bForWriting);
        D2StormEntry38Strc* pList = Ptr(hHandle);
        if (!pList)
        {
            SyncLeaveLock(*pLockHandle);
            *pLockHandle = 0;
        }
        return pList;
    }
    void sub_0052E590(D2StormEntry38Strc* pNode)
    {
        sub_006021E0_UnlinkNode(pNode);
        InternalDelete(pNode);
    }
};

extern D2GameDataTableStrc gCelListTable;                                                                   // 0x008E8CC0

// 0x006039C0
void __stdcall sub_006039C0(unsigned int hCelList)
{
    int hLock;
    D2StormEntry38Strc* pList = gCelListTable.Lock(hCelList, &hLock, 0);
    for (D2CelEntryStrc* pEntry = (D2CelEntryStrc*)((((int)pList->tList.m_terminator.m_next <= 0) - 1) & (int)pList->tList.m_terminator.m_next); (int)pEntry > 0; pEntry = (D2CelEntryStrc*)pEntry->f_0.m_next)
    {
        FOG_Free(pEntry->pData, ".\\SRC\\CelCmp.cpp", 588, 0);
    }
    pList->tList.sub_00602BF0_DeleteAll();
    gCelListTable.sub_0052E590(pList);
    gCelListTable.SyncLeaveLock(hLock);
}

// 0x00603A70
unsigned int __stdcall sub_00603A70(unsigned int hCelList, D2CelFileStrc** ppCelFile)
{
    int hLock;
    D2StormEntry38Strc* pList = gCelListTable.Lock(hCelList, &hLock, 0);
    *ppCelFile = 0;

    if (!pList->nCount)
    {
        return 0x85200001;
    }

    if (pList->nCount % pList->nDirections)
    {
        return 0x85200002;
    }

    D2CelFileStrc* pCelFile = (D2CelFileStrc*)FOG_Alloc(pList->nCount * sizeof(void*) + 0x18, ".\\SRC\\CelCmp.cpp", 615, 0);
    pCelFile->nVersion = 6;
    pCelFile->dwFlags = pList->dwFlags;
    pCelFile->nFormat = pList->nType;
    pCelFile->nDirections = pList->nDirections;
    pCelFile->nCelsPerDirection = pList->nCount / pList->nDirections;
    if (pList->dwFlags & 4)
    {
        sub_0060D190_BuildCelFileWithData(pList, pCelFile);
        pCelFile->nTermination = pList->nData;
    }
    else
    {
        gpfnCelFileBuilders_006E3680[pList->nType](pList, pCelFile);
    }

    gCelListTable.SyncLeaveLock(hLock);
    *ppCelFile = pCelFile;
    return 0;
}

#include "gen/data/Source/D2CMP/006039C0_sub_006039C0.inc"
