extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2UnitStrc;

struct D2InventoryGridStrc
{
    D2UnitStrc* pItem;
    D2UnitStrc* pLastItem;
    unsigned char nCellsX;
    unsigned char nCellsY;
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
    char unk0x0C[0x8];
    D2InventoryGridStrc* pGrids;
    int nGridCount;
};

extern "C" const char gszInventorySourceFile_006EA918[]; // 0x006EA918
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void* __fastcall sub_0040B4B0(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

#define LINE_GRID_ALLOC1 721
#define LINE_GRID_REALLOC 740
#define LINE_GRID_ALLOC2 747

__declspec(noinline) static D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc*, int, D2InventoryGridInfoStrc*);

// 0x0063ADD0
D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo)
{
    void** const pInventoryMemPool = &pInventory->pMemPool;
    D2InventoryGridStrc* pInventoryGrid;
    if (pInventory->nGridCount > nInventoryGrid)
    {
        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        if (!pInventoryGridInfo)
        {
            if (!pInventoryGrid->ppItems)
            {
                return 0;
            }
        }
        else
        {
            if (!pInventoryGrid->ppItems)
            {
                pInventoryGrid->nCellsX = pInventoryGridInfo->nGridX;
                pInventoryGrid->nCellsY = pInventoryGridInfo->nGridY;
                pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(*pInventoryMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nCellsY * pInventoryGrid->nCellsX, gszInventorySourceFile_006EA918, LINE_GRID_ALLOC1, 0);
                unsigned int nSize = pInventoryGrid->nCellsX;
                nSize *= pInventoryGrid->nCellsY;
                nSize *= sizeof(D2UnitStrc*);
                memset(pInventoryGrid->ppItems, 0, nSize);
            }

            if (pInventoryGrid->nCellsX != pInventoryGridInfo->nGridX || pInventoryGrid->nCellsY != pInventoryGridInfo->nGridY)
            {
                return 0;
            }
        }
    }
    else
    {
        if (!pInventoryGridInfo)
        {
            return 0;
        }

        pInventory->pGrids = (D2InventoryGridStrc*)sub_0040B4B0(*pInventoryMemPool, pInventory->pGrids, sizeof(D2InventoryGridStrc) * (nInventoryGrid + 1), gszInventorySourceFile_006EA918, LINE_GRID_REALLOC, 0);
        memset(&pInventory->pGrids[pInventory->nGridCount], 0, sizeof(D2InventoryGridStrc) * (nInventoryGrid - pInventory->nGridCount + 1));
        pInventory->nGridCount = nInventoryGrid + 1;

        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        pInventoryGrid->nCellsX = pInventoryGridInfo->nGridX;
        pInventoryGrid->nCellsY = pInventoryGridInfo->nGridY;
        pInventoryGrid->ppItems = (D2UnitStrc**)sub_0040B430(*pInventoryMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nCellsY * pInventoryGrid->nCellsX, gszInventorySourceFile_006EA918, LINE_GRID_ALLOC2, 0);
        unsigned int nSize = pInventoryGrid->nCellsX;
                nSize *= pInventoryGrid->nCellsY;
                nSize *= sizeof(D2UnitStrc*);
                memset(pInventoryGrid->ppItems, 0, nSize);
    }

    return pInventoryGrid;
}

#define INVENTORY_SIGNATURE 0x1020304
#define INVGRID_INVENTORY 2
void __stdcall DATATBLS_GetInventoryGridInfo(int, int, D2InventoryGridInfoStrc*); // 0x0065C1F0
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

// 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nGridX, int nGridY, int* pX, int* pY, int nInventoryRecordId, unsigned char nPage)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nPage + INVGRID_INVENTORY, &tInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    if (nGridX >= 0 && nGridX <= pInventoryGrid->nCellsX && nGridY >= 0 && nGridY <= pInventoryGrid->nCellsY)
    {
        D2UnitStrc* pItem = pInventoryGrid->ppItems[nGridX + nGridY * pInventoryGrid->nCellsX];
        if (pItem)
        {
            *pX = CLIENTS_GetUnitX(pItem);
            *pY = CLIENTS_GetUnitY(pItem);
            return pItem;
        }
    }

    return 0;
}

extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo; // 0x0074479C
struct D2ItemExtraDataStrc { char unknown[0x14]; D2UnitStrc* nextGridItem; };
struct D2ItemDataStrc { char unknown[0x5c]; D2ItemExtraDataStrc extra; };
struct D2PathRecordStrc { char unknown[12]; unsigned int x; };
struct D2UnitStrc { int type; char unknown[16]; D2ItemDataStrc* itemData; char unknown18[20]; D2PathRecordStrc* path; };
int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70
int __stdcall ITEMS_GetFileIndex(D2UnitStrc*); // 0x00629DA0
unsigned int __stdcall PATH_GetXPosition(D2PathRecordStrc*); // 0x006488C0
// 0x0063D0F0
int __stdcall INVENTORY_GetSetItemEquipCountByFileIndex(D2InventoryStrc* inventory,int fileIndex)
{
 if (!inventory) return 0;
 if (inventory->dwSignature != 0x1020304) return 0;
 D2InventoryGridStrc* grid=INVENTORY_GetGrid(inventory,0,&gBodyLocInventoryGridInfo);
 if (!grid) return 0;
 int count=0;
 for (D2UnitStrc* item=grid->pItem;item;) {
  if (ITEMS_GetItemQuality(item)==5 && ITEMS_GetFileIndex(item)==fileIndex) {
   unsigned int x;
   if (item->type==2 || (item->type>3 && item->type<=5)) x=item->path->x;
   else x=item->path ? PATH_GetXPosition(item->path):0;
   if (x<11) ++count;
  }
  if (item->type!=4) return count;
  D2ItemDataStrc* data=item->itemData;
  if (!data) return count;
  D2ItemExtraDataStrc* extra=&data->extra;
  if (!extra) return count;
  item=extra->nextGridItem;
 }
 return count;
}
