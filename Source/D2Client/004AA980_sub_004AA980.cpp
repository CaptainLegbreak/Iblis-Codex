#pragma pack(push, 1)
struct D2UiCelFileStrc
{
    void* pCelFile;
    char szPath[0x1E];
};

struct D2NpcEntryStrc
{
    int nId;
    char unk0x04[0x12];
};
#pragma pack(pop)

struct D2WeatherLayerStateStrc
{
    void* apCelFiles[4];
};

void __fastcall sub_00478A00(void* pCel);                                                                   // 0x00478A00
void __stdcall sub_004B1680(D2NpcEntryStrc* pEntry);                                                        // 0x004B1680
extern unsigned char gbGlobal_007A0522;                                                                     // 0x007A0522
extern D2UiCelFileStrc gaPanelCels_00724BF0[7];                                                             // 0x00724BF0
extern D2WeatherLayerStateStrc gtWeatherLayer_007A89B0;                                                     // 0x007A89B0
extern D2WeatherLayerStateStrc gtWeatherLayer_007A893C;                                                     // 0x007A893C
extern int gnNpcEntryCount_0072554C;                                                                        // 0x0072554C
extern D2NpcEntryStrc gaNpcEntries_00726850[];                                                              // 0x00726850
unsigned char gbGlobal_007C0C6A;                                                                            // 0x007C0C6A
extern int gdwGlobal_007C0D2D;                                                                              // 0x007C0D2D

// 0x004AA980
void __cdecl sub_004AA980()
{
    if (gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile)
    {
        sub_00478A00(gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile);
        gaPanelCels_00724BF0[gbGlobal_007A0522].pCelFile = 0;
    }
}

// 0x00472BD0
void __cdecl sub_00472BD0()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gtWeatherLayer_007A89B0.apCelFiles[i])
        {
            sub_00478A00(gtWeatherLayer_007A89B0.apCelFiles[i]);
            gtWeatherLayer_007A89B0.apCelFiles[i] = 0;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (gtWeatherLayer_007A893C.apCelFiles[i])
        {
            sub_00478A00(gtWeatherLayer_007A893C.apCelFiles[i]);
            gtWeatherLayer_007A893C.apCelFiles[i] = 0;
        }
    }
}

// 0x004B17A0
void __cdecl sub_004B17A0()
{
    for (int i = 0; i < gnNpcEntryCount_0072554C; ++i)
        sub_004B1680(&gaNpcEntries_00726850[i]);
    gbGlobal_007C0C6A = 1;
}

// 0x004B1D70
int __cdecl sub_004B1D70_FindNpcEntry()
{
    int i = 0;
    int bFound = 0;
    while (i < gnNpcEntryCount_0072554C && !bFound)
    {
        if (gaNpcEntries_00726850[i].nId == gdwGlobal_007C0D2D)
            bFound = 1;
        else
            ++i;
    }

    if (bFound == 1)
        return i;
    return 0;
}

#include "gen/data/Source/D2Client/004AA980_sub_004AA980.inc"
