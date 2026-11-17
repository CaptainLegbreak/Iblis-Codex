struct D2ActiveRoomStrc;
struct D2FieldStrc;
struct D2CoordStrc
{
    int nX;
    int nY;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define COLLISION_ABS(a) ((a) < 0 ? -(a) : (a))

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
D2FieldStrc* __stdcall DATATBLS_AllocField(); // 0x0066A4B0
void __stdcall DATATBLS_FreeField(D2FieldStrc* pField); // 0x0066A500
void __stdcall DATATBLS_SetFieldCoordinates(D2FieldStrc* pField, int nX, int nY); // 0x0066A540
int __stdcall D2Common_11099(D2FieldStrc* pField, D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short fMask); // 0x0066A670

// 0x0064DEA0
D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesImpl(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms, int nMaxDistance, int nPosIncrementValue)
{
    D2_ASSERT(pSpawnPoint, 0x726);

    const D2CoordStrc tSpawn = *pSpawnPoint;
    D2FieldStrc* pField = 0;

    if (pFieldCoord)
    {
        pField = DATATBLS_AllocField();
        D2_ASSERT(pField, 0x730);

        DATATBLS_SetFieldCoordinates(pField, pFieldCoord->nX, pFieldCoord->nY);
    }

    pRoom = COLLISION_GetRoomBySubTileCoordinates(pRoom, pSpawnPoint->nX, pSpawnPoint->nY);

    if (pRoom && !COLLISION_CheckMaskWithSize(pRoom, pSpawnPoint->nX, pSpawnPoint->nY, nUnitSize, nMask))
    {
        if (!pFieldCoord || !D2Common_11099(pField, pRoom, pSpawnPoint->nX, pSpawnPoint->nY, nFieldMask))
        {
            if (pField)
            {
                DATATBLS_FreeField(pField);
            }

            return pRoom;
        }
    }

    int nBestDistance = -1;
    for (int nRing = 1; nRing < nMaxDistance; nRing += nPosIncrementValue)
    {
        nBestDistance = -1;

        for (int nY = tSpawn.nY - nRing; nY <= tSpawn.nY + nRing; nY += nPosIncrementValue)
        {
            for (int nX = tSpawn.nX - nRing; nX <= tSpawn.nX + nRing; nX += 2 * nRing)
            {
                D2ActiveRoomStrc* pTemp = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
                if (pTemp)
                {
                    pRoom = pTemp;

                    if (!COLLISION_CheckMaskWithSize(pTemp, nX, nY, nUnitSize, nMask) && (!pFieldCoord || !D2Common_11099(pField, pTemp, nX, nY, nFieldMask)))
                    {
                        const int nAbsX = COLLISION_ABS(nX - tSpawn.nX);
                        int nDY = nY - tSpawn.nY;
                        if (nDY < 0)
                        {
                            nDY = -nDY;
                        }
                        const int nDistance = nAbsX + nDY;
                        if (nBestDistance == -1 || nDistance < nBestDistance)
                        {
                            pSpawnPoint->nX = nX;
                            pSpawnPoint->nY = nY;
                            nBestDistance = nDistance;
                        }
                    }
                }
            }
        }

        for (int nX = tSpawn.nX - nRing + 1; nX <= tSpawn.nX + nRing - 1; nX += nPosIncrementValue)
        {
            for (int nY = tSpawn.nY - nRing; nY <= tSpawn.nY + nRing; nY += 2 * nRing)
            {
                D2ActiveRoomStrc* pTemp = COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY);
                if (pTemp)
                {
                    pRoom = pTemp;

                    if (!COLLISION_CheckMaskWithSize(pTemp, nX, nY, nUnitSize, nMask) && (!pFieldCoord || !D2Common_11099(pField, pTemp, nX, nY, nFieldMask)))
                    {
                        int nDX = nX - tSpawn.nX;
                        if (nDX < 0)
                        {
                            nDX = -nDX;
                        }
                        const int nDistance = nDX + COLLISION_ABS(nY - tSpawn.nY);
                        if (nBestDistance == -1 || nDistance < nBestDistance)
                        {
                            pSpawnPoint->nX = nX;
                            pSpawnPoint->nY = nY;
                            nBestDistance = nDistance;
                        }
                    }
                }
            }
        }

        if (nBestDistance != -1)
        {
            break;
        }
    }

    if (pField)
    {
        DATATBLS_FreeField(pField);
    }

    if (nBestDistance != -1)
    {
        return COLLISION_GetRoomBySubTileCoordinates(pRoom, pSpawnPoint->nX, pSpawnPoint->nY);
    }

    if (bAllowNeighborRooms)
    {
        return COLLISION_GetRoomBySubTileCoordinates(pRoom, pSpawnPoint->nX, pSpawnPoint->nY);
    }

    return 0;
}
