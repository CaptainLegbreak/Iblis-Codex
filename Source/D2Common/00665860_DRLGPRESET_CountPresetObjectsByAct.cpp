extern int gnPresetObjectIndices[5][150];                                                                   // 0x00748AD8

// 0x006658E0
int __stdcall DRLGPRESET_GetObjectIndexFromObjPreset(unsigned char nAct, int nUnitId)
{
    return gnPresetObjectIndices[nAct][nUnitId];
}

// 0x00665860
int __stdcall DRLGPRESET_CountPresetObjectsByAct(unsigned char nAct)
{
    int nCount = 0;
    for (int i = 0; i < 150; ++i)
    {
        if (!DRLGPRESET_GetObjectIndexFromObjPreset(nAct, i))
        {
            break;
        }

        ++nCount;
    }

    return nCount;
}

#include "gen/data/Source/D2Common/00665860_DRLGPRESET_CountPresetObjectsByAct.inc"
