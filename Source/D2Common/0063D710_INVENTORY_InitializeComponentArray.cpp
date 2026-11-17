struct D2ItemsTxt
{
    char unk0x000[0x80];
    int dwCode;
    char unk0x084[0x0C];
    int dwAlternateGfx;
    char unk0x094[0x8A];
    short wType[2];
    char unk0x122[0x86];
};

struct D2ItemDataTbl
{
    int nItemsTxtRecordCount;
    D2ItemsTxt* pItemsTxt;
};

struct D2InventoryComponentItemTypeStrc
{
    int dwCode;
    int nItemType;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables();                                                      // 0x00633590
int __stdcall ITEMS_CheckType(int nItemType1, int nItemType2);                                              // 0x00629B50

extern D2InventoryComponentItemTypeStrc gComponentItemTypeMap_00744CA8[283]; // 0x00744CA8
static D2InventoryComponentItemTypeStrc gTxtComponentItemTypeMap_0096CC68[255];                            // 0x0096CC68
static int gnComponentArrayRecordCount_0096D460;                                                            // 0x0096D460
static int gbComponentArrayInitialized_0096D464;                                                            // 0x0096D464

// 0x0063D710
void __fastcall INVENTORY_InitializeComponentArray()
{
    if (!gbComponentArrayInitialized_0096D464)
    {
        gbComponentArrayInitialized_0096D464 = 1;

        memset(gTxtComponentItemTypeMap_0096CC68, 0, sizeof(gTxtComponentItemTypeMap_0096CC68));

        D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();

        gTxtComponentItemTypeMap_0096CC68[1].dwCode = 0x2074696C;
        gTxtComponentItemTypeMap_0096CC68[1].nItemType = 3;
        gTxtComponentItemTypeMap_0096CC68[2].dwCode = 0x2064656D;
        gTxtComponentItemTypeMap_0096CC68[2].nItemType = 3;
        gTxtComponentItemTypeMap_0096CC68[3].dwCode = 0x20797668;
        gTxtComponentItemTypeMap_0096CC68[3].nItemType = 3;

        int nCurrentTableEntries = 4;

        for (int i = 0; i < pItemDataTbl->nItemsTxtRecordCount; ++i)
        {
            D2ItemsTxt* pItemsTxtRecord = &pItemDataTbl->pItemsTxt[i];

            int dwCode = 0;
            if (pItemsTxtRecord->dwAlternateGfx)
            {
                dwCode = pItemsTxtRecord->dwAlternateGfx;
            }
            else
            {
                dwCode = pItemsTxtRecord->dwCode;
            }

            int bNeedsToBeAdded = 1;
            if (!(ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x2D)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], 3)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x33)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x25))
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x4B))
            {
                bNeedsToBeAdded = 0;
            }

            int bFound = 0;
            for (int nCounter = 0; nCounter < nCurrentTableEntries; ++nCounter)
            {
                if (gTxtComponentItemTypeMap_0096CC68[nCounter].dwCode == dwCode)
                {
                    bFound = 1;
                    break;
                }
            }

            if (!bFound && bNeedsToBeAdded == 1)
            {
                int nIndex = nCurrentTableEntries;

                while (ITEMS_CheckType(gComponentItemTypeMap_00744CA8[nIndex].nItemType, 0x2D) && ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x2D)
                       || ITEMS_CheckType(gComponentItemTypeMap_00744CA8[nIndex].nItemType, 0x32) && ITEMS_CheckType(pItemsTxtRecord->wType[0], 0x32)
                       || gTxtComponentItemTypeMap_0096CC68[nIndex].dwCode)
                {
                    ++nIndex;
                }

                if (nIndex >= 255)
                {
                    nIndex = nCurrentTableEntries;
                }

                gTxtComponentItemTypeMap_0096CC68[nIndex].dwCode = dwCode;
                gTxtComponentItemTypeMap_0096CC68[nIndex].nItemType = pItemsTxtRecord->wType[0];

                if (nCurrentTableEntries == nIndex)
                {
                    ++nCurrentTableEntries;
                }
            }
        }

        gnComponentArrayRecordCount_0096D460 = 255;
    }
}

#include "gen/data/Source/D2Common/0063D710_INVENTORY_InitializeComponentArray.inc"
