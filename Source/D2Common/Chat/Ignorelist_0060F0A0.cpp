#include "D2StormLink.h"
struct D2FileStrc;
struct D2Cache00610840Strc;
struct D2Cache00610CA0Strc;
struct D2StormLinkStrc;
struct D2StormSlotListStrc;
struct D2IgnoreKeyNodeStrc;
struct D2StormHashTableStrc;
struct D2IgnoreListStrc;
struct D2CacheLink00610840Strc;
struct D2CacheList00610840Strc;
struct D2CacheLink00610CA0Strc;
struct D2CacheList00610CA0Strc;


struct D2StormSlotListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
};

struct D2IgnoreKeyNodeStrc
{
    unsigned char unk_00[0x14];
    const char* m_key;
};

struct D2StormHashTableStrc
{
    void* pVtable;
    D2StormSlotListStrc m_fulllist;
    unsigned char unk_10[0x18];

    char* Head()
    {
        char* pHead = m_fulllist.m_terminator.Next();
        return pHead;
    }
    char* Next(char* pNode)
    {
        pNode += m_fulllist.m_linkoffset;
        D2StormLinkStrc* pLink = (D2StormLinkStrc*)pNode;
        return pLink->Next();
    }
};

struct D2IgnoreListStrc
{
    void* pVtable;
    D2StormHashTableStrc m_table;
    D2StormHashTableStrc m_table2;
    unsigned char unk_54[0x2C];
    char szFileName[0x104];
};


extern "C" D2FileStrc* __cdecl fopen(const char*, const char*); // 0x0068239A
extern "C" int __cdecl fclose(D2FileStrc*); // 0x00681FDC
extern "C" int __cdecl fprintf(D2FileStrc*, const char*, ...); // 0x00684C94
extern const char gszFileMode_006FF97C[]; // 0x006FF97C
extern const char gszFirstFormat_006CD90C[]; // 0x006CD90C
extern const char gszSecondFormat_006E62A8[]; // 0x006E62A8

struct D2CacheLink00610840Strc
{
	char* pPrev;
	char* pNext;

	__forceinline char* Next()
	{
		char* const pResult = (int)pNext <= 0 ? 0 : pNext;
		return pResult;
	}
};

struct D2CacheList00610840Strc
{
	int nLinkOffset;
	D2CacheLink00610840Strc tTerminator;
};

struct D2Cache00610840Strc
{
	char unk_00[0x10];
	unsigned int nCounter;
	char unk_14[0x08];
	D2CacheList00610840Strc* pLists;
	int unk_20;
	unsigned int nCount;

	int sub_00610840_Touch(int nIndex);
};


void __fastcall sub_006101B0_GrowListArray(D2Cache00610840Strc* pCache); // 0x006101B0

struct D2CacheLink00610CA0Strc
{
	char* pPrev;
	char* pNext;

	__forceinline char* Next()
	{
		char* const pResult = (int)pNext <= 0 ? 0 : pNext;
		return pResult;
	}
};

struct D2CacheList00610CA0Strc
{
	int nLinkOffset;
	D2CacheLink00610CA0Strc tTerminator;
};

struct D2Cache00610CA0Strc
{
	char unk_00[0x10];
	unsigned int nCounter;
	char unk_14[0x08];
	D2CacheList00610CA0Strc* pLists;
	int unk_20;
	unsigned int nCount;

	int sub_00610CA0_Touch(int nIndex);
};


void __fastcall sub_006108D0_GrowListArray(D2Cache00610CA0Strc* pCache); // 0x006108D0

// 0x0060F0A0
int __fastcall sub_0060F0A0_WriteLists(D2IgnoreListStrc* pList)
{
    D2FileStrc* pFile = fopen(pList->szFileName, gszFileMode_006FF97C);
    if (!pFile)
        return 0;
    for (char* pNode = pList->m_table.Head(); (int)pNode > 0; pNode = pList->m_table.Next(pNode))
        fprintf(pFile, gszFirstFormat_006CD90C, ((D2IgnoreKeyNodeStrc*)pNode)->m_key);
    for (char* pNode = pList->m_table2.Head(); (int)pNode > 0; pNode = pList->m_table2.Next(pNode))
        fprintf(pFile, gszSecondFormat_006E62A8, ((D2IgnoreKeyNodeStrc*)pNode)->m_key);
    fclose(pFile);
    return 1;
}

#include "gen/data/Source/D2Common/Chat/Ignorelist_0060F0A0.inc"

// 0x00610840
int D2Cache00610840Strc::sub_00610840_Touch(int nIndex)
{
	D2CacheList00610840Strc* const& pListArray = pLists;
	if (nCount >= 0x3FF)
	{
		return 0;
	}

	if (nCounter > 3)
	{
		nCounter -= 3;
	}
	else
	{
		nCounter = 0;
	}

	for (char* pEntry = pListArray[nIndex].tTerminator.Next(); (int)pEntry > 0; )
	{
		++nCounter;
		if (nCounter > 13)
		{
			nCounter = 0;
			sub_006101B0_GrowListArray(this);
			return 1;
		}

		D2CacheList00610840Strc* pList = &pListArray[nIndex];
		D2CacheLink00610840Strc* pLink = pEntry ? (D2CacheLink00610840Strc*)(pEntry + pList->nLinkOffset) : &pList->tTerminator;
		pEntry = pLink->pNext;
	}

	return 0;
}

// 0x00610CA0
int D2Cache00610CA0Strc::sub_00610CA0_Touch(int nIndex)
{
	D2CacheList00610CA0Strc* const& pListArray = pLists;
	if (nCount >= 0x3FF)
	{
		return 0;
	}

	if (nCounter > 3)
	{
		nCounter -= 3;
	}
	else
	{
		nCounter = 0;
	}

	for (char* pEntry = pListArray[nIndex].tTerminator.Next(); (int)pEntry > 0; )
	{
		++nCounter;
		if (nCounter > 13)
		{
			nCounter = 0;
			sub_006108D0_GrowListArray(this);
			return 1;
		}

		D2CacheList00610CA0Strc* pList = &pListArray[nIndex];
		D2CacheLink00610CA0Strc* pLink = pEntry ? (D2CacheLink00610CA0Strc*)(pEntry + pList->nLinkOffset) : &pList->tTerminator;
		pEntry = pLink->pNext;
	}

	return 0;
}
