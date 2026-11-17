struct D2HotspotStrc
{
    char unk0x00[0x10];
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    char unk0x20[0x04];
    char bFlag0x24;
    char bFlag0x25;
    char unk0x26[0x02];
};

void* __fastcall sub_004520C0_LoadUiCelFile(const char* szPath);                                            // 0x004520C0
void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __cdecl sub_004C0090();                                                                                // 0x004C0090

extern int gnGlobal_007278FC;                                                                               // 0x007278FC
extern D2HotspotStrc gaHotspots_00727902[];                                                                 // 0x00727902
extern int gnGlobal_007C5474;                                                                               // 0x007C5474
extern int gnGlobal_007C5478;                                                                               // 0x007C5478
extern int gnGlobal_007C547C;                                                                               // 0x007C547C
extern unsigned long gdwTick_007C5488;                                                                      // 0x007C5488
void* gpCelFile_007C5494;                                                                                   // 0x007C5494
void* gpCelFile_007C5498;                                                                                   // 0x007C5498

// 0x004BF9D0
void __cdecl sub_004BF9D0()
{
    gnGlobal_007C5474 = 0;
    gnGlobal_007C547C = 0;
    gnGlobal_007C5478 = 0;
    gdwTick_007C5488 = 0;
    gpCelFile_007C5494 = sub_004520C0_LoadUiCelFile("menu\\upgrade");
    gpCelFile_007C5498 = sub_004520C0_LoadUiCelFile("menu\\horadricback");
    for (int i = 0; i < gnGlobal_007278FC; i++)
    {
        gaHotspots_00727902[i].bFlag0x25 = 0;
        gaHotspots_00727902[i].bFlag0x24 = 0;
    }
}

// 0x004C0100
void __cdecl sub_004C0100()
{
    if (gnGlobal_007C5474)
    {
        sub_004C0090();
    }

    if (gpCelFile_007C5494)
    {
        sub_00478A00(gpCelFile_007C5494);
        gpCelFile_007C5494 = 0;
    }

    if (gpCelFile_007C5498)
    {
        sub_00478A00(gpCelFile_007C5498);
        gpCelFile_007C5498 = 0;
    }
}
