struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

struct D2NpcVendorChainStrc
{
    int dwGUID;
    unsigned char field_4;
    unsigned char unk0x05[3];
    D2NpcVendorChainStrc* pNext;
};

struct D2NpcRecordStrc
{
    char unk0x00[0x18];
    D2NpcVendorChainStrc* pVendorChain;
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

// 0x00536CB0
D2NpcVendorChainStrc* __fastcall SUNITPROXY_GetVendorChain(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pPlayer)
{
    const int nNpcGUID = !pPlayer ? -1 : pPlayer->dwUnitId;

    for (D2NpcVendorChainStrc* pVendorChain = pNpcRecord->pVendorChain; pVendorChain; pVendorChain = pVendorChain->pNext)
    {
        if (pVendorChain->dwGUID == nNpcGUID)
        {
            return pVendorChain;
        }
    }

    D2NpcVendorChainStrc* pVendorChain = (D2NpcVendorChainStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2NpcVendorChainStrc), ".\\UNIT\\sunitproxy.cpp", 0x4ED, 0);
    pVendorChain->dwGUID = nNpcGUID;
    pVendorChain->pNext = pNpcRecord->pVendorChain;
    pNpcRecord->pVendorChain = pVendorChain;
    return pVendorChain;
}
