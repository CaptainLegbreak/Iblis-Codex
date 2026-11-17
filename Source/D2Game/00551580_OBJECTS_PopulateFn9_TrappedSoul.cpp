struct D2GameStrc;
struct D2UnitStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2ActiveRoomStrc
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

struct D2DrlgCoordsStrc
{
    int nSubtileX;
    int nSubtileY;
    int nSubtileWidth;
    int nSubtileHeight;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
};

struct D2ObjectsTxt
{
    char unk0x00[0xC4];
    unsigned char nSelectable[8];
    char unk0xCC[0x04];
    unsigned int dwSizeX;
    unsigned int dwSizeY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    char unk0x08[0x08];
    int dwAnimMode;
    char unk0x14[0xB0];
    unsigned int dwFlags;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);              // 0x00619730
D2UnitStrc* __stdcall OBJECTS_CreateObject(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom); // 0x00550380

#define UNITFLAG_TARGETABLE 0x00000002

static __forceinline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)nSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    return (unsigned int)nSeed;
}

// 0x00551580
D2UnitStrc* __fastcall OBJECTS_PopulateFn9_TrappedSoul(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2_ASSERT(nDensity <= 128, 0x893);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    int nSizeY;
    int nSizeX;
    nSizeX = pObjectsTxtRecord->dwSizeX;
    nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    D2SeedStrc* pSeed;
    if (pRoom)
    {
        pSeed = &pRoom->pSeed;
    }
    else
    {
        pSeed = 0;
    }
    if (OBJECTS_RollSeed_Inline(pSeed) % 100 > nProbability)
    {
        return 0;
    }
    const int nMax = nDensity * (drlgCoords.nSubtileWidth * drlgCoords.nSubtileHeight >> 7) >> 8;
    for (int i = nMax; i > 0; --i)
    {
        D2UnitStrc* pObject = OBJECTS_CreateObject(pGame, nObjectId, nSizeX, nSizeY, pRoom);
        if (pObject)
        {
            if (pObjectsTxtRecord->nSelectable[pObject->dwAnimMode])
            {
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            }
            else
            {
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            }
            return pObject;
        }
    }
    return 0;
}
