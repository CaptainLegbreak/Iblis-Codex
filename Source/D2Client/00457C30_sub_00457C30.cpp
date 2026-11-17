struct D2AutomapCellStrc { int fields[5]; };
struct D2AutomapCellBlockStrc { D2AutomapCellStrc cells[512]; D2AutomapCellBlockStrc* next; };
D2AutomapCellBlockStrc* gpCellBlocks_007A5158;        // 0x007A5158
int gnCellCount_007A515C;        // 0x007A515C
void* __fastcall FOG_Alloc(int size, const char* file, int line, int flags); // 0x0040B380
extern "C" void* __cdecl memset(void* memory, int value, unsigned int size); // 0x00681EF0

// 0x00457C30
D2AutomapCellStrc* __cdecl sub_00457C30()
{
    D2AutomapCellBlockStrc* current = gpCellBlocks_007A5158;
    D2AutomapCellBlockStrc* previous = 0;
    int blockIndex = gnCellCount_007A515C / 512;
    int cellIndex = gnCellCount_007A515C % 512;
    int i = 0;
    ++gnCellCount_007A515C;
    if (gpCellBlocks_007A5158)
    {
        for (; current && i < blockIndex; ++i)
        {
            previous = current;
            current = current->next;
        }
    }
    else
    {
        current = 0;
    }
    if (!current)
    {
        current = (D2AutomapCellBlockStrc*)FOG_Alloc(sizeof(D2AutomapCellBlockStrc), ".\\UI\\automap.cpp", 0x35D, 0);
        memset(current, 0, sizeof(D2AutomapCellBlockStrc));
        if (previous)
            previous->next = current;
        else
            gpCellBlocks_007A5158 = current;
    }
    D2AutomapCellStrc* cell = &current->cells[cellIndex];
    memset(cell, 0, sizeof(D2AutomapCellStrc));
    return cell;
}
