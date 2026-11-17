extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2CelStrc;

struct D2CelContextStrc
{
    int unk0x00[15];
    D2CelStrc* pCel;
    int unk0x40;
    int unk0x44;
};

struct D2UnitStrc
{
    int dwUnitType;
};

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem);                                                        // 0x0062B400
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __fastcall sub_004DBB50_GetItemCelContext(D2CelContextStrc* pContext, D2UnitStrc* pItem, int nArg3, int nArg4, int nArg5, int* pOut, int nArg7, int nArg8); // 0x004DBB50
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0
int __stdcall sub_006018F0(D2CelStrc* pCel);                                                                // 0x006018F0
int __stdcall sub_006018C0(D2CelStrc* pCel);                                                                 // 0x006018C0
int __fastcall sub_004DAB40_CheckCel(D2CelStrc* pCel, int nX, int nY, int nArg4);                           // 0x004DAB40
int __stdcall sub_0062C100(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned char* pShift, int nArg);  // 0x0062C100
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __stdcall sub_0046E300(D2UnitStrc* pItem, int nArg2, int nArg3, int nX, int nY, int nArg6);            // 0x0046E300

// 0x0046EE80
int __fastcall sub_0046EE80_DrawItemCel(D2UnitStrc* pItem, int nX, int nY)
{
    const int nType = pItem ? pItem->dwUnitType : 6;
    if (nType != 4)
    {
        return 0;
    }
    int nSize = 0;
    if (ITEMS_GetItemType(pItem) == 4)
    {
        unsigned int nGold = STATLIST_UnitGetStatValue(pItem, 0x0E, 0);
        if (nGold >= 0x64)
        {
            if (nGold < 0x1F4)
            {
                nSize = 1;
            }
            else
            {
                nSize = nGold < 0x1388 ? 2 : 3;
            }
        }
    }
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nOut;
    const int bReady = sub_004DBB50_GetItemCelContext(&tContext, pItem, 0, nSize, 0, &nOut, 1, -1)
        && sub_006001F0(&tContext, 0, 1)
        && sub_004DAB40_CheckCel(tContext.pCel, nX, nY + sub_006018F0(tContext.pCel), 0);
    if (!bReady)
    {
        return 0;
    }
    unsigned char nShift;
    const int nPalette = sub_0062C100(0, pItem, &nShift, 1);
    int nDrawMode = 5;
    if (ITEMS_CheckItemFlag(pItem, 0x400000, 0xAC2, ".\\ENGINE\\Gfx.cpp"))
    {
        nDrawMode = 1;
    }
    sub_004F6480(&tContext, nX, nY + sub_006018F0(tContext.pCel), -1, nDrawMode, nPalette);
    sub_0046E300(pItem, 0xFF, 0, nX + ((unsigned int)sub_006018C0(tContext.pCel) >> 1), nY + ((unsigned int)sub_006018F0(tContext.pCel) >> 1), 0);
    return 1;
}
