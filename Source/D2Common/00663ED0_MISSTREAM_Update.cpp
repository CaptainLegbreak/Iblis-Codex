struct D2DynamicPathStrc;
struct D2UnitStrc {
    unsigned int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    char unk_0c[0x20];
    D2DynamicPathStrc* pDynamicPath;
};
struct D2PathPointStrc { unsigned short X, Y; };
struct D2MissileStreamStrc { int* pEntries; int nCapacity; };
typedef int (__fastcall* D2StreamCreate)(D2UnitStrc*, int, int, int, int, int, char);
typedef void (__fastcall* D2StreamFree)(int);
void __stdcall PATH_SetType(D2DynamicPathStrc*, int); // 0x00648CF0
int __stdcall D2Common_10142(D2DynamicPathStrc*, D2UnitStrc*, int); // 0x00649970
int __stdcall sub_006487D0(D2DynamicPathStrc*, D2PathPointStrc**); // 0x006487D0
D2MissileStreamStrc* __fastcall sub_0064A6F0_GetMissileStream(D2UnitStrc*); // 0x0064A6F0
int __stdcall PATH_ComputeDirection(int, int, int, int); // 0x0064FDC0
const char* __cdecl sub_00408090(); // 0x00408090
void __cdecl sub_00408A60(const char*, const char*, int); // 0x00408A60
extern const char gszAssertExpression_006CC837[]; // 0x006CC837
extern const char gszMisStream_006EE540[]; // 0x006EE540
void* __fastcall FOG_AllocPool(void*, int, const char*, int, int); // 0x0040B430
void* __fastcall FOG_ReallocPool(void*, void*, int, const char*, int, int); // 0x0040B4B0
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" __declspec(noreturn) void __cdecl exit(int);
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*);

// 0x00663ED0
void __stdcall MISSTREAM_Update(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nAmount, int nStep, D2StreamCreate pfCreate, D2StreamFree pfFree)
{
    D2PathPointStrc* pPathPoints;
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    PATH_SetType(pPath, 16);
    D2Common_10142(pPath, pMissile, 0);
    int nPathPoints = sub_006487D0(pPath, &pPathPoints);
    if (nPathPoints != 0 && nPathPoints != 1) {
        D2MissileStreamStrc* pStream = sub_0064A6F0_GetMissileStream(pMissile);
        if (!pStream) { sub_00408A60(gszAssertExpression_006CC837, sub_00408090(), 138); exit(-1); }
        int nRatio = nAmount / nStep;
        int bCreate = 0;
        int nTemp = nPathPoints - 1;
        int nPoints = nTemp;
        if (nTemp < nRatio) { nPoints = nRatio; bCreate = 1; }
        if (!pStream->nCapacity) {
            unsigned int nSize = sizeof(int) * nPoints;
            pStream->nCapacity = nPoints;
            void* const pPool = pMissile->pMemoryPool;
            pStream->pEntries = (int*)FOG_AllocPool(pPool, nSize, gszMisStream_006EE540, 151, 0);
            memset(pStream->pEntries, 0, nSize);
        } else if (pStream->nCapacity < nPoints) {
            void* const pPool = pMissile->pMemoryPool;
            pStream->pEntries = (int*)FOG_ReallocPool(pPool, pStream->pEntries, sizeof(int) * nPoints, gszMisStream_006EE540, 154, 0);
        }
        int nMax = nTemp / nRatio;
        int nExtra = 0;
        if (bCreate) nExtra = 4 * (nRatio - nTemp) / nTemp;
        int nCurrent = nAmount;
        int nCycle = 4;
        if (IsBadCodePtr((void*)pfCreate)) { sub_00408A60(gszAssertExpression_006CC837, sub_00408090(), 169); exit(-1); }
        int nCounter = 0;
        int nIndex = 0;
        while (nIndex < nTemp) {
            int nX = pPathPoints[nIndex].X;
            int nY = pPathPoints[nIndex].Y;
            char nDirection = (char)PATH_ComputeDirection(pPathPoints[nIndex + 1].X, pPathPoints[nIndex + 1].Y, nX, nY);
            if (nCounter >= nMax && nAmount) {
                nCounter = 1;
                pStream->pEntries[nIndex] = pfCreate(pMissile, pStream->pEntries[nIndex], nX, nY, nCurrent, 1, nDirection);
                nCurrent -= nStep;
                if (bCreate) {
                    int nRepeat = nExtra / 4;
                    if (nCycle < nExtra % 4) ++nRepeat;
                    --nCycle;
                    if (nCycle <= 0) nCycle = 4;
                    for (int i = 0; i < nRepeat; ++i) {
                        pStream->pEntries[nIndex] = pfCreate(pUnit, pStream->pEntries[nIndex], nX, nY, nCurrent, 2, nDirection);
                        nCurrent -= nStep;
                    }
                }
            } else {
                ++nCounter;
                pStream->pEntries[nIndex] = pfCreate(pUnit, pStream->pEntries[nIndex], nX, nY, nCurrent, 0, nDirection);
            }
            ++nIndex;
        }
        while (nIndex < pStream->nCapacity) {
            pfFree(pStream->pEntries[nIndex]);
            pStream->pEntries[nIndex] = 0;
            ++nIndex;
        }
    }
}
