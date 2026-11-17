extern int gnSource_00731DCC; // 0x00731DCC
extern int gnSource_00731DF8; // 0x00731DF8
extern int gnSource_00731E24; // 0x00731E24
extern int gnSource_00731E60; // 0x00731E60
extern int gnCopy_00731EB8; // 0x00731EB8
extern int gnCopy_00731EC0; // 0x00731EC0
extern int gnCopy_00731EC8; // 0x00731EC8
extern int gnCopy_00731ED0; // 0x00731ED0

// 0x006CAF30
void __cdecl sub_006CAF30_SnapshotCounters()
{
    gnCopy_00731EB8 = gnSource_00731DCC;
    gnCopy_00731EC0 = gnSource_00731DF8;
    gnCopy_00731EC8 = gnSource_00731E24;
    gnCopy_00731ED0 = gnSource_00731E60;
}

#include "gen/data/Source/Storm/006CAF30_sub_006CAF30_SnapshotCounters.inc"
