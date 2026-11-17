struct D2DrlgRoomStrc;

struct D2PresetUnitStrc
{
    int nMode;
    int nIndex;
    int nXpos;
    D2PresetUnitStrc* pNext;
    int unk0x10;
    int nUnitType;
};

D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom);                            // 0x0066BFA0

// 0x0066B010
D2PresetUnitStrc* __fastcall sub_0066B010_FindPresetTile(D2DrlgRoomStrc* pDrlgRoom)
{
    D2PresetUnitStrc* pPreset = DRLGROOM_GetPresetUnits(pDrlgRoom);
    for (; pPreset; pPreset = pPreset->pNext)
    {
        if (pPreset->nUnitType == 5)
        {
            break;
        }
    }

    return pPreset;
}

// 0x0066B7F0
void __cdecl sub_0066B7F0_Nop()
{
}
