extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" const char gszEmptyAssertText; // 0x006CC837
int __stdcall sub_00600C90_GetDirectionIndex64(int nDirection, unsigned int nDirections); // 0x00600C90

struct Cell { int unk0; int width; int height; char pad[0x14]; unsigned char data[1]; };
struct CellTable { int type; unsigned char flags; char pad[0xB]; int nDirections; int stride; Cell* cells[1]; };

// 0x006015D0
int __stdcall sub_006015D0(CellTable* p, int nDirection, int nIndex, void* pDst)
{
    if (p->type != 6)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x4a0);
        exit(-1);
    }
    if ((p->flags & 4) == 0)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x4a1);
        exit(-1);
    }
    int idx = sub_00600C90_GetDirectionIndex64(nDirection, p->nDirections) * p->stride + nIndex;
    Cell* cell = p->cells[idx];
    int size = cell->height * cell->width;
    memcpy(pDst, cell->data, (unsigned int)size * 3);
    return 1;
}
