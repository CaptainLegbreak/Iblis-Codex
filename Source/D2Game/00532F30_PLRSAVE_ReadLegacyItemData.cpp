#pragma function(memset)
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

#pragma pack(push, 1)
struct D2SavedItemStrc
{
    unsigned char nBodyLoc;
    unsigned char nSocketedItems;
    int nItemLevel;
    int nItemId;
    unsigned char nSpawnType;
    unsigned char nItemQuality;
    int nQuantity;
    int nMinDurability;
    int nMaxDurability;
    int nX;
    int nY;
    int nItemIndex;
    unsigned int nItemFlags;
    unsigned int nSeed;
    unsigned int nItemSeed;
    unsigned char nInvPage;
    unsigned char nEarLevel;
    char szName[16];
    unsigned short nItemFormat;
    unsigned int nItemCode;
};
#pragma pack(pop)

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
};

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);         // 0x00410E40
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits);                                     // 0x00411030
extern "C" int __stdcall sub_00410E90(D2BitBufferStrc* pBuffer);                                          // 0x00410E90
extern "C" unsigned int __stdcall sub_006287A0(unsigned int dwA, unsigned int dwB);                       // 0x006287A0
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode);                                          // 0x00633680
int __stdcall DATATBLS_MapOldItemIndexToCurrent(int nItemId);                                               // 0x006335A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

// 0x00532F30
int __fastcall PLRSAVE_ReadLegacyItemData(D2SavedItemStrc* pSavedItem, unsigned char* pData)
{
    memset(pSavedItem, 0, sizeof(D2SavedItemStrc));

    D2BitBufferStrc tBitBuffer;
    BITMANIP_Initialize(&tBitBuffer, pData, 0x40);

    pSavedItem->nItemFlags = sub_00411020_ReadBits(&tBitBuffer, 32);

    if (sub_006287A0(pSavedItem->nItemFlags, 0x100000))
    {
        if (sub_006287A0(pSavedItem->nItemFlags, 0x200000))
        {
            pSavedItem->nItemFormat = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 10);
            pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nItemLevel = 1;
            pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);

            if (sub_006287A0(pSavedItem->nItemFlags, 0x10000))
            {
                pSavedItem->nItemCode = 0x20726165;
                pSavedItem->nItemIndex = sub_00411020_ReadBits(&tBitBuffer, 3);
                pSavedItem->nEarLevel = sub_00411020_ReadBits(&tBitBuffer, 8);

                for (unsigned int i = 0; i < 16; ++i)
                {
                    pSavedItem->szName[i] = sub_00411020_ReadBits(&tBitBuffer, 7);
                }
            }
            else
            {
                pSavedItem->nItemCode = sub_00411020_ReadBits(&tBitBuffer, 32);
            }
        }
        else
        {
            pSavedItem->nItemFormat = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 10);
            pSavedItem->nItemCode = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nSocketedItems = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemLevel = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 12);
            pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemQuality = sub_00411020_ReadBits(&tBitBuffer, 4);
            pSavedItem->nQuantity = BITMANIP_ReadSigned(&tBitBuffer, 20);
            pSavedItem->nMinDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
            pSavedItem->nMaxDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
            pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
            pSavedItem->nSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nItemSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);
        }

        pSavedItem->nItemId = DATATBLS_GetItemIdFromItemCode(pSavedItem->nItemCode);
        return sub_00410E90(&tBitBuffer);
    }

    pSavedItem->nItemFormat = 0;

    if (sub_006287A0(pSavedItem->nItemFlags, 0x10000))
    {
        pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
        pSavedItem->nItemLevel = 1;
        BITMANIP_ReadSigned(&tBitBuffer, 10);
        pSavedItem->nItemId = DATATBLS_GetItemIdFromItemCode(0x20726165);
        pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
        pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
        pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
        pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
        pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);
        pSavedItem->nEarLevel = sub_00411020_ReadBits(&tBitBuffer, 8);

        for (unsigned int i = 0; i < 16; ++i)
        {
            pSavedItem->szName[i] = sub_00411020_ReadBits(&tBitBuffer, 7);
            if (!pSavedItem->szName[i])
            {
                break;
            }
        }

        pSavedItem->nItemCode = 0x20726165;
        return 25;
    }

    pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
    pSavedItem->nSocketedItems = sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemLevel = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 12);
    const int nItemId = BITMANIP_ReadSigned(&tBitBuffer, 10);
    pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemQuality = sub_00411020_ReadBits(&tBitBuffer, 4);
    pSavedItem->nQuantity = BITMANIP_ReadSigned(&tBitBuffer, 20);
    pSavedItem->nMinDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
    pSavedItem->nMaxDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
    pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
    pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
    pSavedItem->nSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
    pSavedItem->nItemSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
    pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);

    if (nItemId >= 0)
    {
        pSavedItem->nItemId = DATATBLS_MapOldItemIndexToCurrent(nItemId);

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pSavedItem->nItemId);
        if (pItemsTxtRecord)
        {
            pSavedItem->nItemCode = pItemsTxtRecord->dwCode;
            return 25;
        }
    }

    pSavedItem->nItemCode = 0;
    pSavedItem->nItemId = -1;
    return 25;
}
