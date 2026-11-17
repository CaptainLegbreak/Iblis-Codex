struct D2UnitStrc;

struct D2WaypointDataStrc
{
    unsigned short nFlag0;
    unsigned short unk0x02;
    int unk0x04[3];
};

struct D2PlayerDataStrc
{
    char unk0x00[0x1C];
    D2WaypointDataStrc* pWaypointData[3];
};

struct D2GameStrc
{
    char unk0x00[0x70];
    int bExpansion;
};

#pragma pack(push, 1)
struct D2WaypointSaveFlagStrc
{
    D2WaypointDataStrc flags;
    unsigned int unk0x10;
    unsigned int unk0x14;
};

struct D2WaypointSaveDataStrc
{
    unsigned short nHeader;
    int unk0x02;
    unsigned short nRecordSize;
    D2WaypointSaveFlagStrc waypoints[3];
};
#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0
void __stdcall WAYPOINTS_ValidateAndCopyWaypointData(D2WaypointDataStrc* pSource, D2WaypointDataStrc* pDestination); // 0x006610B0
void __stdcall WAYPOINTS_CopyAndValidateWaypointData(D2WaypointDataStrc* pDest, const D2WaypointDataStrc* pSource); // 0x00661030
D2UnitStrc* __fastcall sub_6FC7E8B0(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4);          // 0x00574EC0
int __fastcall sub_00531BB0_WriteItemList(void* pArg1, void* pArg2, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x00531BB0

#define PLRSAVE2_WAYPOINT_HEADER 0x5357
#define PLRSAVE2ERROR_BAD_WAYPOINT 0x10

// 0x005693E0
int __fastcall PLRSAVE2_WriteWaypointData(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pNext = pSection + sizeof(D2WaypointSaveDataStrc);
    if (pNext > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2WaypointSaveDataStrc waypointSaveData = {};
    waypointSaveData.nHeader = PLRSAVE2_WAYPOINT_HEADER;
    waypointSaveData.unk0x02 = 1;
    waypointSaveData.nRecordSize = sizeof(D2WaypointSaveDataStrc);

    for (int i = 0; i < 3; ++i)
    {
        WAYPOINTS_ValidateAndCopyWaypointData(pPlayerData->pWaypointData[i], &waypointSaveData.waypoints[i].flags);
    }

    memcpy(pSection, &waypointSaveData, sizeof(D2WaypointSaveDataStrc));
    *ppSection = pNext;
    return 0;
}

// 0x005699A0
int __fastcall sub_005699A0_WriteMercSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int a7, int bSizing)
{
    unsigned char* pData = *ppSection;
    if (pGame->bExpansion)
    {
        *(unsigned short*)pData = 0x666A;
        pData += 2;

        D2UnitStrc* pPet = sub_6FC7E8B0(pGame, pPlayer, 7, 1);
        if (pPet)
        {
            const int nLength = sub_00531BB0_WriteItemList(pGame, pPet, pData, pEnd - pData, 0, a7, bSizing);
            if (nLength >= 0)
            {
                pData += nLength;
            }
            else
            {
                return 5;
            }
        }

        *ppSection = pData;
    }

    return 0;
}

// 0x0056A3E0
int __fastcall PLRSAVE2_ReadWaypointData(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pNext = pSection + sizeof(D2WaypointSaveDataStrc);
    if (pNext > pEnd)
    {
        return PLRSAVE2ERROR_BAD_WAYPOINT;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2WaypointSaveDataStrc* pWaypointSaveData = (D2WaypointSaveDataStrc*)pSection;
    if (pWaypointSaveData->nHeader != PLRSAVE2_WAYPOINT_HEADER)
    {
        return PLRSAVE2ERROR_BAD_WAYPOINT;
    }

    for (int i = 0; i < 3; ++i)
    {
        D2WaypointDataStrc* pSavedData = &pWaypointSaveData->waypoints[i].flags;
        if (pSavedData->nFlag0 != 0x102 && pSavedData->nFlag0 != 0x101 && pSavedData->nFlag0)
        {
            return PLRSAVE2ERROR_BAD_WAYPOINT;
        }

        WAYPOINTS_CopyAndValidateWaypointData(pPlayerData->pWaypointData[i], pSavedData);
    }

    *ppSection = pNext;
    return 0;
}
