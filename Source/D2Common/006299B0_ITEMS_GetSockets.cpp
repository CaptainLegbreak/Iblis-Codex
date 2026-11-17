extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc
{
    int dwUnitType;
};

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;
};

struct D2ItemSaveStrc
{
    int nClassId;
    unsigned short nX;
    unsigned short nY;
    unsigned char nAnimMode;
    unsigned char pad0x09[3];
    unsigned int dwFlags;
    unsigned char nStorePage;
    unsigned char nBodyloc;
    unsigned char pad0x12[2];
    int nItemFileIndex;
};

#define UNIT_ITEM 4
#define STAT_ITEM_NUMSOCKETS 194
#define IMODE_ONGROUND 3
#define IMODE_DROPPING 5
#define IFLAG_ISEAR 0x00010000
#define IFLAG_COMPACTSAVE_LOWQUALITY 0x02200000

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                       // 0x00625480
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);         // 0x00410E40
unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits);                      // 0x00411020
int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits);                                     // 0x00411030
int __stdcall DATATBLS_GetItemIdFromItemCode(unsigned int dwCode);                                          // 0x00633680
int __fastcall sub_0062EFB0_GetRepairCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode); // 0x0062EFB0

// 0x006299B0
int __stdcall ITEMS_GetSockets(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0xEA6);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 0xEA7);
    return STATLIST_UnitGetStatValue(pItem, STAT_ITEM_NUMSOCKETS, 0);
}

// 0x0062AE20
int __stdcall ITEMS_GetCompactItemDataFromBitstream(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, int dwVersion)
{
    D2BitBufferStrc pBuffer;
    BITMANIP_Initialize(&pBuffer, pBitstream, nSize);

    if (bCheckForHeader && BITMANIP_ReadSigned(&pBuffer, 16) != 'MJ')
        return 0;

    unsigned int dwFlags = sub_00411020_ReadBits(&pBuffer, 32);
    pItemSave->dwFlags = dwFlags;
    sub_00411020_ReadBits(&pBuffer, 10);
    pItemSave->nAnimMode = (unsigned char)sub_00411020_ReadBits(&pBuffer, 3);
    if (pItemSave->nAnimMode == IMODE_ONGROUND || pItemSave->nAnimMode == IMODE_DROPPING)
    {
        pItemSave->nX = (unsigned short)sub_00411020_ReadBits(&pBuffer, 16);
        pItemSave->nY = (unsigned short)sub_00411020_ReadBits(&pBuffer, 16);
    }
    else
    {
        pItemSave->nBodyloc = (unsigned char)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nX = (unsigned short)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nY = (unsigned short)sub_00411020_ReadBits(&pBuffer, 4);
        pItemSave->nStorePage = (unsigned char)sub_00411020_ReadBits(&pBuffer, 3) - 1;
    }

    if (dwFlags & IFLAG_ISEAR)
    {
        pItemSave->nClassId = DATATBLS_GetItemIdFromItemCode(' rae');
    }
    else
    {
        unsigned int dwCode = sub_00411020_ReadBits(&pBuffer, 32);
        if (dwVersion <= 0x5C && dwCode == ' cen')
            dwCode = ' gen';
        pItemSave->nClassId = DATATBLS_GetItemIdFromItemCode(dwCode);
    }

    int nItemFileIndex = 0;
    if (!(dwFlags & IFLAG_COMPACTSAVE_LOWQUALITY))
        nItemFileIndex = sub_00411020_ReadBits(&pBuffer, 3);
    pItemSave->nItemFileIndex = nItemFileIndex;

    return 1;
}

// 0x0062FDC0
int __stdcall sub_0062FDC0_GetRepairCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode)
{
    return sub_0062EFB0_GetRepairCost(pUnit, pItem, nDifficulty, pQuestFlags, nNpcId, nMode);
}
