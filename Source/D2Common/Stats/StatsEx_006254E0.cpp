#include "D2Common.h"

struct D2StatsArrayStrc
{
    void* pStat;
    unsigned short nStatCount;
    unsigned short nBitSize;
};

struct D2StatListStrc
{
    void* pMemPool;
    D2UnitStrc* pUnit;
    unsigned int dwOwnerType;
    unsigned int dwOwnerId;
    unsigned int dwFlags;
    unsigned int dwStateNo;
    int dwExpireFrame;
    unsigned int dwSkillNo;
    unsigned int dwSLvl;
    D2StatsArrayStrc Stats;
    D2StatListStrc* pPrevLink;
    D2StatListStrc* pNextLink;
    D2StatListStrc* pParent;
    void* fpStatRemove;
};

struct D2StatListExStrc : D2StatListStrc
{
    D2StatListStrc* pMyLastList;
    D2StatListStrc* pMyStats;
    D2UnitStrc* pOwner;
    D2StatsArrayStrc FullStats;
    D2StatsArrayStrc ModStats;
    unsigned int* StatFlags;
};

struct D2SkillsTxt
{
    char unk0x000[0x194];
    short wSkillDesc;
    char unk0x196[0x23C - 0x196];
};

struct D2DataTablesStrc
{
    char unk0x000[0xB94];
    int nSkillDescTxtRecordCount;
    D2SkillsTxt* pSkillsTxt;
    char unk0xB9C[4];
    int nSkillsTxtRecordCount;
};

#define STATLIST_NEWLENGTH 0x80000000

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480
int __stdcall sub_00625350(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625350
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList);                                 // 0x006269F0

__forceinline D2SkillsTxt* __fastcall DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x006254E0
int __stdcall sub_006254E0_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    return sub_00625350(pStatList, nStatId, nLayer);
}

// 0x00626C00
void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList)
{
    D2Common_ExpireStatList_6FDB6E30(pStatList);

    if (pStatList->Stats.pStat)
        FOG_FreePool(pStatList->pMemPool, pStatList->Stats.pStat, ".\\Stats\\StatsEx.cpp", 0x4D8, 0);

    if (pStatList->dwFlags & STATLIST_NEWLENGTH)
    {
        D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
        D2StatListStrc* pPrevious;
        for (D2StatListStrc* pCurrent = pStatListEx->pMyLastList; pCurrent; pCurrent = pPrevious)
        {
            pPrevious = pCurrent->pPrevLink;
            pCurrent->pParent = 0;
            pCurrent->pUnit = 0;
            if (pCurrent->dwFlags & STATLIST_NEWLENGTH)
                continue;

            if (pStatListEx->pMyLastList == pCurrent)
                pStatListEx->pMyLastList = pPrevious;

            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);

            pPrevious = pStatListEx->pMyLastList;
        }

        if (pStatListEx->FullStats.pStat)
            FOG_FreePool(pStatListEx->pMemPool, pStatListEx->FullStats.pStat, ".\\Stats\\StatsEx.cpp", 0x4F3, 0);

        if (pStatListEx->ModStats.pStat)
            FOG_FreePool(pStatListEx->pMemPool, pStatListEx->ModStats.pStat, ".\\Stats\\StatsEx.cpp", 0x4F7, 0);

        FOG_FreePool(pStatListEx->pMemPool, pStatListEx->StatFlags, ".\\Stats\\StatsEx.cpp", 0x4FA, 0);
    }

    FOG_FreePool(pStatList->pMemPool, pStatList, ".\\Stats\\StatsEx.cpp", 0x502, 0);
}

// 0x00627AF0
int __fastcall sub_00627AF0_HasSkillDesc(int nSkillId)
{
    if (D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId))
    {
        int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
            return 1;
    }
    return 0;
}
