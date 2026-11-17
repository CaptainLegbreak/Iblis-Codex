struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[16];
    D2DrlgWarpStrc* pNext;
};

struct D2DrlgStrc
{
    char unk0x00[0x90];
    D2DrlgWarpStrc* pWarp;
};

struct D2DrlgLevelStrc
{
    char unk0x000[0x1D0];
    int nLevelId;
};

struct D2ActiveRoomStrc;

struct D2DrlgRoomStrc
{
    char unk0x00[0x28];
    unsigned int dwFlags;
    int nRoomsNear;
    D2ActiveRoomStrc* pRoom;
    char unk0x34[0x14];
    int nType;
    char unk0x4C[0xC];
    D2DrlgLevelStrc* pLevel;
};

struct D2LevelDefBin
{
    char unk0x00[0x48];
    int dwVis[8];
};

struct D2LvlWarpTxt;

extern "C" const char gszEmptyAssertText;                                                     // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                        // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);     // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                 // 0x00681E09
D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                             // 0x0061E470
D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom);                               // 0x0061AAE0
const char* __fastcall DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom);                             // 0x00667010
D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord);   // 0x0066AB00
unsigned int __fastcall sub_0067D7A0(D2DrlgRoomStrc* pDrlgRoom);                                // 0x0067D7A0

// 0x0066B980
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    if (nX < pDrlgCoord->nPosX)
    {
        return 0;
    }

    if (nY < pDrlgCoord->nPosY)
    {
        return 0;
    }

    if (nX >= pDrlgCoord->nWidth + pDrlgCoord->nPosX)
    {
        return 0;
    }

    return nY < pDrlgCoord->nHeight + pDrlgCoord->nPosY;
}

// 0x0066B9D0
int __fastcall DRLGROOM_AreXYInsideCoordinatesOrOnBorder(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    if (nX < pDrlgCoord->nPosX)
    {
        return 0;
    }

    if (nY < pDrlgCoord->nPosY)
    {
        return 0;
    }

    if (nX > pDrlgCoord->nWidth + pDrlgCoord->nPosX)
    {
        return 0;
    }

    return nY <= pDrlgCoord->nHeight + pDrlgCoord->nPosY;
}

// 0x0066BA20
int __fastcall sub_0066BA20(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    int nLeft = 5 * pDrlgCoord->nPosX;
    if (nX < nLeft)
    {
        return 0;
    }

    if (nX >= nLeft + 5 * pDrlgCoord->nWidth)
    {
        return 0;
    }

    int nTop = 5 * pDrlgCoord->nPosY;
    if (nY < nTop)
    {
        return 0;
    }

    return nY < nTop + 5 * pDrlgCoord->nHeight;
}

// 0x0066BA90
unsigned int __fastcall sub_0066BA90(D2DrlgRoomStrc* pDrlgRoom)
{
    switch (pDrlgRoom->nType)
    {
    case 1:
        return sub_0067D7A0(pDrlgRoom);
    }

    return 0;
}

// 0x0066BAA0
unsigned int __fastcall DRLGROOM_CheckWaypointFlags(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->dwFlags & 0x30000;
}

// 0x0066BAC0
int __fastcall DRLGROOM_GetWarpDestinationLevel(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel)
{
    int nDestinationLevel;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
    D2ActiveRoomStrc* pRoom = DRLGWARP_GetDestinationRoom(pDrlgRoom, nSourceLevel, &nDestinationLevel, &pLvlWarpTxtRecord);
    if (!pRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 604);
        exit(-1);
    }

    pDrlgRoom = DUNGEON_GetRoomExFromRoom(pRoom);
    if (!pDrlgRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 606);
        exit(-1);
    }

    if (!pDrlgRoom->pLevel)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 607);
        exit(-1);
    }

    return pDrlgRoom->pLevel->nLevelId;
}

// 0x0066BB20
int __fastcall DRLGROOM_GetLevelIdFromPopulatedRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 619);
        exit(-1);
    }

    if (pDrlgRoom->dwFlags & 0x800000)
    {
        return 0;
    }

    return pDrlgRoom->pLevel->nLevelId;
}

// 0x0066BB60
int __fastcall DRLGROOM_HasWaypoint(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 630);
        exit(-1);
    }

    return DRLGROOM_CheckWaypointFlags(pDrlgRoom) != 0;
}

// 0x0066BBA0
const char* __fastcall DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->nType == 2)
    {
        return DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(pDrlgRoom);
    }

    return "None";
}

// 0x0066BCF0
int __fastcall sub_0066BCF0(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->nRoomsNear;
}

// 0x0066BFC0
void __fastcall DRLGROOM_SetRoom(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc* pRoom)
{
    pDrlgRoom->pRoom = pRoom;
}

// 0x0066C040
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* pDrlgWarp = pDrlg->pWarp; pDrlgWarp; pDrlgWarp = pDrlgWarp->pNext)
    {
        if (!pDrlgWarp->nLevel)
        {
            sub_00408A60(&gszEmptyAssertText, sub_00408090(), 1040);
            exit(-1);
        }

        if (nLevelId == pDrlgWarp->nLevel)
        {
            return pDrlgWarp->nVis;
        }
    }

    return DATATBLS_GetLevelDefRecord(nLevelId)->dwVis;
}
