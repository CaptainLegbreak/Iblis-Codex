struct D2ObjectRegionStrc
{
    unsigned char nAct;
    unsigned char pad0x01[3];
    int field_4;
    int nPopulatedRooms;
    int unk0x0C;
    int nHealingShrines;
    int nShrines;
    int nWells;
};

struct D2ObjectControlStrc
{
    char unk0x00[0x48];
    D2ObjectRegionStrc* pObjectRegion[1024];
};

struct D2GameStrc
{
    char unk0x0000[0x10F0];
    D2ObjectControlStrc* pObjectControl;
};

// 0x00547300
bool __fastcall OBJRGN_CanNotSpawnMoreWells(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nWells == 4 || pObjectRegion->nWells > pObjectRegion->nPopulatedRooms / 8)
    {
        return true;
    }
    return false;
}

// 0x00547330
bool __fastcall OBJRGN_ShouldSpawnHealingShrineOrWell(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nPopulatedRooms > 0 && (pObjectRegion->field_4 << 7) / pObjectRegion->nPopulatedRooms > 96 && !pObjectRegion->nHealingShrines)
    {
        return true;
    }
    return false;
}

// 0x00547360
bool __fastcall OBJRGN_CanNotSpawnMoreShrines(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nShrines == 10 || pObjectRegion->nShrines > pObjectRegion->nPopulatedRooms / 8)
    {
        return true;
    }
    return false;
}
