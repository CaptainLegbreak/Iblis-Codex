#include "D2Game.h"
#include "D2Structs.h"
#include "D2Txt.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int (__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C


struct D2ObjGroupTxt
{
    unsigned int dwId[8];
    unsigned char nDensity[8];
    unsigned char nProbability[8];
    unsigned char nShrines;
    unsigned char nWells;
    unsigned short pad0x32;
};


typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);
D2SeedStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);         // 0x00546FA0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

extern OBJECTPOPULATEFN gpfObjectPopulateTable_00731D00[10];                                                // 0x00731D00

// 0x005528E0
void __fastcall sub_005528E0_PopulateObjectGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nObjGroup)
{
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
    {
        return;
    }

    D2ObjGroupTxt* pObjGroupTxtRecord = DATATBLS_GetObjGroupTxtRecord(nObjGroup);
    D2SeedStrc* pSeed = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    if (!pObjGroupTxtRecord)
    {
        return;
    }

    const unsigned __int64 nValue = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(nValue >> 32);
    pSeed->nLowSeed = (unsigned int)nValue;
    const int nProbability = (int)((unsigned int)nValue % 100);

    int nAccumulatedProbability = 0;
    for (int i = 0; i < 8; ++i)
    {
        const int nObjectId = pObjGroupTxtRecord->dwId[i];
        if (!nObjectId)
        {
            return;
        }

        nAccumulatedProbability += pObjGroupTxtRecord->nProbability[i];
        if (nProbability < nAccumulatedProbability)
        {
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
            D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xCA8);
            if (!gpfObjectPopulateTable_00731D00[pObjectsTxtRecord->nPopulateFn])
            {
                return;
            }
            D2_ASSERT(!IsBadCodePtr((FARPROC)gpfObjectPopulateTable_00731D00[pObjectsTxtRecord->nPopulateFn]), 0xCAB);
            D2_ASSERT(pObjGroupTxtRecord->nDensity[i] < 0x80, 0xCAC);
            gpfObjectPopulateTable_00731D00[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, pObjGroupTxtRecord->nDensity[i], nObjectId, 100);
            return;
        }
    }
}
