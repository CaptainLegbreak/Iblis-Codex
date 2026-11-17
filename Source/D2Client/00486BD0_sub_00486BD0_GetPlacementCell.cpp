extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;

struct D2InventoryGridInfoStrc
{
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned short pad0x02;
    int nGridLeft;
    int nGridRight;
    int nGridTop;
    int nGridBottom;
    unsigned char nGridBoxWidth;
    unsigned char nGridBoxHeight;
};

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

static __declspec(noinline) void __stdcall sub_00486BD0_GetPlacementCell(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY);

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

// 0x00486BD0
static void __stdcall sub_00486BD0_GetPlacementCell(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY)
{
    D2_ASSERT(pItem, 0x14E8);

    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);

    unsigned int nCelWidth;
    unsigned int nCelHeight;
    sub_004DBEA0(pItem, 0, 0, &nCelWidth, &nCelHeight);

    if (!(nWidth % 2))
    {
        nCellX = (nCelWidth / 4 - pGrid->nGridLeft + nX) / pGrid->nGridBoxWidth;
    }

    if (nWidth == pGrid->nGridX)
    {
        nCellX = pGrid->nGridX >> 1;
    }

    if (!(nHeight % 2))
    {
        nCellY = (nCelHeight / 4 - pGrid->nGridTop + nY) / pGrid->nGridBoxHeight;
    }

    if (nHeight == pGrid->nGridY)
    {
        nCellY = pGrid->nGridY >> 1;
    }

    *pCellX = nCellX;
    *pCellY = nCellY;

    if (nWidth > 1)
    {
        nWidth >>= 1;
        *pCellX = D2_MAX(0, *pCellX - nWidth);
    }

    if (nHeight > 1)
    {
        nHeight >>= 1;
        *pCellY = D2_MAX(0, *pCellY - nHeight);
    }
}

void __stdcall sub_00486BD0_Emit(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, unsigned int nX, unsigned int nY, int* pCellX, int* pCellY)
{
    sub_00486BD0_GetPlacementCell(pItem, pGrid, nX, nY, pCellX, pCellY);
}
