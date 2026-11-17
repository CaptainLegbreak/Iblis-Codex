extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DynamicPathStrc;

struct D2StaticPathStrc
{
    int unk0x00[3];
    int nX;
    int nY;
};

struct D2UnitStrc
{
    int dwUnitType;
    int unk0x04[2];
    int dwUnitId;
    int unk0x10[7];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
    char unk0x30[0xB8];
    D2UnitStrc* pRoomNext;
};

#pragma pack(push, 1)
struct D2ClientUnitUpdateStrc
{
    unsigned char nUnitType;
    int nUnitGUID;
    unsigned short nX;
    unsigned short nY;
};
#pragma pack(pop)

struct D2ActiveRoomStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

struct D2ClientStrc
{
    char unk0x000[0x1B4];
    D2ActiveRoomStrc* pRoom;
    char unk0x1B8[0x14];
    D2ClientUnitUpdateStrc unitUpdate[55];
    char pad0x3BB;
    unsigned int nUnitUpdateIndex;
};

struct D2ClientUnitUpdateSortStrc
{
    D2UnitStrc* pUnit;
    unsigned int nDistance;
    int nNextIndex;
};

#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath);                 // 0x00537860
int __fastcall UNITS_GetXPosition(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

static int CLIENTS_GetUnitX_Inlined(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int CLIENTS_GetUnitY_Inlined(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static void __stdcall sub_00537D10_InsertUnitUpdate(D2UnitStrc* pRoomUnit, int nX, int nY, unsigned int* pMaxDistance, D2ClientStrc* pClient, unsigned int nUpdateSize, D2ClientUnitUpdateSortStrc* pSort)
{
    const int nType = pRoomUnit ? pRoomUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        return;
    }
    int nDeltaX = nX - CLIENTS_GetUnitX_Inlined(pRoomUnit);
    if (nDeltaX < 0)
    {
        nDeltaX = -nDeltaX;
    }
    int nDeltaY = nY - CLIENTS_GetUnitY_Inlined(pRoomUnit);
    if (nDeltaY < 0)
    {
        nDeltaY = -nDeltaY;
    }
    const unsigned int nDistance = nDeltaX + nDeltaY;
    if (pClient->nUnitUpdateIndex >= nUpdateSize && nDistance >= *pMaxDistance)
    {
        return;
    }
    int nPrevIndex = 0;
    int* pNextIndex = &pSort[0].nNextIndex;
    while (*pNextIndex)
    {
        const int nIndex = *pNextIndex;
        if (nDistance <= pSort[nIndex].nDistance)
        {
            break;
        }
        nPrevIndex = nIndex;
        pNextIndex = &pSort[nIndex].nNextIndex;
    }
    int nNewIndex;
    if (pClient->nUnitUpdateIndex == nUpdateSize)
    {
        int nLastIndex = 0;
        int* pIndex = &pSort[0].nNextIndex;
        if (pSort[*pIndex].nNextIndex)
        {
            do
            {
                nLastIndex = *pIndex;
                pIndex = &pSort[nLastIndex].nNextIndex;
            }
            while (pSort[*pIndex].nNextIndex);
        }
        D2ClientUnitUpdateSortStrc* pLast = &pSort[nLastIndex];
        nNewIndex = pLast->nNextIndex;
        if (pClient->nUnitUpdateIndex && nDistance >= pSort[nNewIndex].nDistance)
        {
            return;
        }
        if (pClient->nUnitUpdateIndex == 1)
        {
            *pMaxDistance = nDistance;
            pLast->nNextIndex = 0;
        }
        else
        {
            *pMaxDistance = pLast->nDistance;
            pLast->nNextIndex = 0;
        }
    }
    else
    {
        nNewIndex = pClient->nUnitUpdateIndex;
        pClient->nUnitUpdateIndex = nNewIndex + 1;
    }
    if (!nPrevIndex && nDistance < pSort[0].nDistance)
    {
        if (pClient->nUnitUpdateIndex != 1)
        {
            pSort[nNewIndex].nNextIndex = pSort[0].nNextIndex;
            pSort[nNewIndex].pUnit = pSort[0].pUnit;
            pSort[nNewIndex].nDistance = pSort[0].nDistance;
        }
        pSort[0].nNextIndex = nNewIndex;
        nNewIndex = 0;
    }
    else
    {
        pSort[nNewIndex].nNextIndex = pSort[nPrevIndex].nNextIndex;
        pSort[nPrevIndex].nNextIndex = nNewIndex;
    }
    pSort[nNewIndex].nDistance = nDistance;
    pSort[nNewIndex].pUnit = pRoomUnit;
    if (nDistance > *pMaxDistance)
    {
        *pMaxDistance = nDistance;
    }
}

// 0x00537EE0
static void __stdcall CLIENTS_SetUnitsUpdateList(D2ClientStrc* pClient, D2ClientUnitUpdateSortStrc* pSort)
{
    D2ClientUnitUpdateSortStrc* pCurrent = pSort;
    pClient->nUnitUpdateIndex = 0;
    do
    {
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nUnitType = !pCurrent->pUnit ? UNIT_INVALID : pCurrent->pUnit->dwUnitType;
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nUnitGUID = !pCurrent->pUnit ? -1 : pCurrent->pUnit->dwUnitId;
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nX = CLIENTS_GetUnitX_Inlined(pCurrent->pUnit);
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nY = CLIENTS_GetUnitY_Inlined(pCurrent->pUnit);
        ++pClient->nUnitUpdateIndex;
        pCurrent = &pSort[pCurrent->nNextIndex];
    }
    while (pCurrent->nNextIndex);
}

// 0x00537FD0
void __fastcall CLIENTS_RefreshUnitsUpdateList(D2ClientStrc* pClient, unsigned int nUpdateSize)
{
    D2_ASSERT(pClient->pRoom, 0x70B);
    D2ActiveRoomStrc** pAdjacentRoomsList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pClient->pRoom, &pAdjacentRoomsList, &nNumRooms);
    D2_ASSERT(pAdjacentRoomsList, 0x70D);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!pPlayer)
    {
        return;
    }
    const int nPlayerX = UNITS_GetXPosition(pPlayer);
    const int nPlayerY = CLIENTS_GetUnitY(pPlayer);
    unsigned int nCurrentMaxDistance = 0;
    D2ClientUnitUpdateSortStrc tUnitUpdatesSort[55];
    pClient->nUnitUpdateIndex = 0;
    tUnitUpdatesSort[0].nNextIndex = 0;
    tUnitUpdatesSort[0].nDistance = 0;
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pRoomUnit = pAdjacentRoomsList[i]->pUnitFirst; pRoomUnit; pRoomUnit = pRoomUnit->pRoomNext)
        {
            sub_00537D10_InsertUnitUpdate(pRoomUnit, nPlayerX, nPlayerY, &nCurrentMaxDistance, pClient, nUpdateSize, tUnitUpdatesSort);
        }
    }
    CLIENTS_SetUnitsUpdateList(pClient, tUnitUpdatesSort);
}
