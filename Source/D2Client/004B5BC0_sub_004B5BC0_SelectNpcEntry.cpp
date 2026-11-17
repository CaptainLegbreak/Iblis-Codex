#pragma pack(push, 2)
struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x0D];
    char bSelected;
    char bFlag;
    char unk0x13[0x02];
    char bRefreshed;
};
#pragma pack(pop)

typedef char check_size_npcentry[(sizeof(D2NpcEntryStrc) == 0x16) ? 1 : -1];

int __cdecl sub_004B1D70_FindNpcEntry();                                                                    // 0x004B1D70
void __stdcall sub_004B5890_OpenNpcPanel(int nStringIndex, int nEntryIndex);                               // 0x004B5890

extern int gnGlobal_007C0C6B;                                                                               // 0x007C0C6B
extern D2NpcEntryStrc* gpNpcEntry_007C0C7D;                                                                 // 0x007C0C7D
extern D2NpcEntryStrc gaNpcEntries_00726850[];                                                              // 0x00726850

// 0x004B5BC0
int __cdecl sub_004B5BC0_SelectNpcEntry()
{
    gnGlobal_007C0C6B = 1;
    int nIndex = sub_004B1D70_FindNpcEntry();
    gpNpcEntry_007C0C7D = &gaNpcEntries_00726850[nIndex];
    sub_004B5890_OpenNpcPanel(0xD35, nIndex);
    return 1;
}
