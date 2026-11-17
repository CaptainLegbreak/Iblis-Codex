typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct D2InventoryStrc;
struct D2UnitStrc;
struct D2Block1;

struct D2InventoryGridStrc
{
    D2UnitStrc* pItem;
    D2UnitStrc* pLastItem;
    unsigned char nGridWidth;
    unsigned char nGridHeight;
    unsigned short unk0x0A;
    D2UnitStrc** ppItems;
};

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short unk0x02;
    int nGridRect[5];
};

struct D2InventoryStrc
{
    unsigned int dwSignature;
    void* pMemPool;
    D2UnitStrc* pOwner;
    D2UnitStrc* pFirstItem;
    D2UnitStrc* pLastItem;
    D2InventoryGridStrc* pGrids;
    int nGridCount;
    int dwLeftItemGUID;
    D2UnitStrc* pCursorItem;
    int dwOwnerGuid;
    int dwItemCount;
    char unk0x2C[0x14];
};

extern "C" const char gszInventorySourceFile_006EA918[];                                                    // 0x006EA918
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nInvPage, int bLoD);                        // 0x00621050
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850
void __stdcall sub_0065C1F0(int nInventoryRecordId, int nUnused, D2Block1* pInventoryGridInfo); // 0x0065C1F0

// build: symbol ?INVENTORY_GetGrid@@YGPAUD2InventoryGridStrc@@PAUD2InventoryStrc@@HPAUD2InventoryGridInfoStrc@@@Z 0x0063ADD0
static __declspec(noinline) D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo)
{
    D2InventoryGridStrc* pInventoryGrid;
    if (nInventoryGrid < pInventory->nGridCount)
    {
        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        if (!pInventoryGridInfo)
        {
            if (!pInventoryGrid->ppItems)
            {
                return 0;
            }

            return pInventoryGrid;
        }

        if (!pInventoryGrid->ppItems)
        {
            pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
            pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
            pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, 721, 0);
            memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
        }

        if (pInventoryGrid->nGridWidth != pInventoryGridInfo->nGridX || pInventoryGrid->nGridHeight != pInventoryGridInfo->nGridY)
        {
            return 0;
        }

        return pInventoryGrid;
    }

    if (!pInventoryGridInfo)
    {
        return 0;
    }

    pInventory->pGrids = (D2InventoryGridStrc*)sub_0040B4B0(pInventory->pMemPool, pInventory->pGrids, sizeof(D2InventoryGridStrc) * (nInventoryGrid + 1), gszInventorySourceFile_006EA918, 740, 0);
    memset(&pInventory->pGrids[pInventory->nGridCount], 0, sizeof(D2InventoryGridStrc) * (nInventoryGrid - pInventory->nGridCount + 1));
    pInventory->nGridCount = nInventoryGrid + 1;

    pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
    pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
    pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
    pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(pInventory->pMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight, gszInventorySourceFile_006EA918, 747, 0);
    memset(pInventoryGrid->ppItems, 0, sizeof(D2UnitStrc*) * pInventoryGrid->nGridWidth * pInventoryGrid->nGridHeight);
    return pInventoryGrid;
}

static __forceinline BOOL INVENTORY_TryPlaceInFreePosition(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, D2UnitStrc* pItem, int nInventoryRecordId, unsigned char* pHeight)
{
    int nX;
    int nY;
    unsigned char nWidth;
    if (pInventoryGrid && INVENTORY_GetFreePosition(pInventory, pItem, nInventoryRecordId, &nX, &nY, 0))
    {
        ITEMS_GetDimensions(pItem, &nWidth, pHeight, gszInventorySourceFile_006EA918, 0x16D5);

        if (nWidth && *pHeight)
        {
            const int nPosX = nX;
            if (nPosX >= 0 && nPosX + nWidth <= pInventoryGrid->nGridWidth && nY >= 0 && nY + *pHeight <= pInventoryGrid->nGridHeight)
            {
                for (int y = nY; y < nY + *pHeight; ++y)
                {
                    for (int x = nPosX; x < nPosX + nWidth; ++x)
                    {
                        pInventoryGrid->ppItems[x + y * pInventoryGrid->nGridWidth] = (D2UnitStrc*)-1;
                    }
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063E1C0
static __declspec(noinline) BOOL __stdcall INVENTORY_CanItemBePlacedInInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory)
{
    unsigned char nHeight;
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != 0x1020304)
    {
        return FALSE;
    }

    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pPlayer, 0, TRUE);
    D2InventoryGridInfoStrc tInventoryGridInfo;
    sub_0065C1F0(nInventoryRecordId, 0, (D2Block1*)&tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, 2, &tInventoryGridInfo);
    return INVENTORY_TryPlaceInFreePosition(pInventory, pInventoryGrid, pItem, nInventoryRecordId, &nHeight);
}

int __stdcall sub_M421_Emit_0063E1C0(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    return INVENTORY_CanItemBePlacedInInventory(pPlayer, pItem, pInventory) + 0x2B;
}
