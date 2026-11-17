struct D2ClientStrc;
struct D2DynamicPathStrc;
struct D2GameStrc;

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    void* pRoom;
    int dwClientCoordX;
    int dwClientCoordY;
    D2CoordStrc tGameCoords;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x18];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0x30];
    void* pInventory;
    char unk0x64[0x4C];
    unsigned int dwLastHitClass;
};

typedef void (__fastcall* PlrMsgFunc)(D2GameStrc*, D2UnitStrc*, D2ClientStrc*, int);

struct D2UnkPlrMsgStrc
{
    PlrMsgFunc field_0;
    int field_4;
    int field_8;
};

extern D2UnkPlrMsgStrc stru_6FD30708[20];                                                                   // 0x007319E8

void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

#define UNIT_OBJECT 2
#define UNIT_MISSILE 3
#define UNIT_TILE 5

// 0x00547F70
void __fastcall sub_6FC81C00(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const char nHitType = pUnit->dwLastHitClass;
    const unsigned char nLife = UNITS_GetCurrentLifePercentage(pUnit);
    int nY;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nY = pUnit->pStaticPath->tGameCoords.nY;
    else
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    int nX;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nX = pUnit->pStaticPath->tGameCoords.nX;
    else
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
    D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 0x0D, 0, nUnitId, 19, nX, nY, nHitType, nLife);
}

// 0x00548400
void __fastcall sub_6FC821C0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    if (pUnit != CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        const unsigned char nLife = UNITS_GetCurrentLifePercentage(pUnit);
        const int nHitClass = stru_6FD30708[nAnimMode].field_4;
        int nY;
        if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
            nY = pUnit->pStaticPath->tGameCoords.nY;
        else
            nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        int nX;
        if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
            nX = pUnit->pStaticPath->tGameCoords.nX;
        else
            nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
        D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 0x0D, 0, nUnitId, nHitClass, nX, nY, 0, nLife);
    }
}
