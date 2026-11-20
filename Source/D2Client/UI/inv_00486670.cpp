#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"

struct Unicode
{
    unsigned short wChar;

    Unicode(unsigned short ch = 0) : wChar(ch) {}
};



const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId);                                                 // 0x006372C0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0
extern D2UnitStrc* gdwGlobal_007BCBF4;                                                                      // 0x007BCBF4

// 0x00486670
static __declspec(noinline) void __stdcall sub_00486670_AppendSocketedGemLetters(Unicode* pText, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return;
    }
    Unicode wszLetter[6];
    int bAny = 0;
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pGem = INVENTORY_UnitIsItem(pNode);
        if (!pGem)
        {
            break;
        }
        if (ITEMSIsA(pGem, 0x4A))
        {
            const int nClassId = pGem->dwClassId;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
            const int nGemOffset = pItemsTxtRecord->dwGemOffset;
            if (nGemOffset > 0)
            {
                D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(nGemOffset);
                if (pGemsTxtRecord)
                {
                    if (!bAny)
                    {
                        bAny = 1;
                        sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x501A));
                    }
                    sub_00526320_ToUnicode(wszLetter, pGemsTxtRecord->szLetter, 6);
                    sub_00526700(pText, wszLetter);
                }
            }
        }
    }
    if (bAny)
    {
        sub_00526320_ToUnicode(wszLetter, szQuote_006D9BF4, 5);
        sub_00526700(pText, wszLetter);
        sub_00526700(pText, pColorEnd);
    }
}

void __stdcall sub_P09_Emit_00486670(Unicode* pText)
{
    sub_00486670_AppendSocketedGemLetters(pText, gdwGlobal_007BCBF4);
}
