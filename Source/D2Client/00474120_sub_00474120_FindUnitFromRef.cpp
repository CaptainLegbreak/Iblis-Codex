struct D2UnitStrc;

struct D2UnitRefStrc
{
    int nType;
    unsigned int nUnitId;
    unsigned char f_8;
};

struct D2LightCellStrc
{
    unsigned char f_0;
    char unk0x01[7];
};

D2UnitStrc* __fastcall sub_004639B0_FindServerSideUnit(unsigned int nUnitId, int nUnitType);              // 0x004639B0
D2UnitStrc* __fastcall sub_00463990(unsigned int nUnitId, int nUnitType);                    // 0x00463990
extern int gbFlag_00712B8C;                                                                                 // 0x00712B8C
extern int gnCellOriginX_007B0A54;                                                                          // 0x007B0A54
extern int gnCellOriginY_007B0A58;                                                                          // 0x007B0A58
D2LightCellStrc gaCells_007B0E68[0x30][0x30];                                                               // 0x007B0E68

// 0x00474120
static __forceinline D2UnitStrc* sub_00474120_FindUnitFromRef(D2UnitRefStrc* pRef)
{
    if (pRef->nType == 6)
    {
        return 0;
    }
    if (pRef->f_8)
    {
        return sub_004639B0_FindServerSideUnit(pRef->nUnitId, pRef->nType);
    }
    return sub_00463990(pRef->nUnitId, pRef->nType);
}

// 0x00474140
void __cdecl sub_00474140_ToggleFlag()
{
    gbFlag_00712B8C = !gbFlag_00712B8C;
}

// 0x00474A30
static __forceinline unsigned char sub_00474A30_IsCellBlocked(int nX, int nY)
{
    nX = (nX >> 3) - gnCellOriginX_007B0A54;
    if (nX < 0)
    {
        return 1;
    }
    if (nX >= 0x30)
    {
        return 1;
    }
    nY = (nY >> 3) - gnCellOriginY_007B0A58;
    if (nY < 0)
    {
        return 1;
    }
    if (nY >= 0x30)
    {
        return 1;
    }
    return gaCells_007B0E68[nY][nX].f_0;
}

int __fastcall sub_M119_Emit_00474120(D2UnitRefStrc* pRef, int nX, int nY)
{
    int n = (int)sub_00474120_FindUnitFromRef(pRef);
    n += sub_00474A30_IsCellBlocked(nX, nY);
    return n;
}

#include "gen/data/Source/D2Client/00474120_sub_00474120_FindUnitFromRef.inc"
