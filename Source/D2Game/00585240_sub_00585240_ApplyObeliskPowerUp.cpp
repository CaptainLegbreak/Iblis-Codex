extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef int(__stdcall* FARPROC)();
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                 // 0x006CC34C

struct D2GameStrc;

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    int dwUnitType;
    int dwClassId;
    void* pMemoryPool;
    int dwUnitId;
    int dwAnimMode;
    char unk0x14[0x0C];
    D2SeedStrc pSeed;
};

struct D2ItemsTxt
{
    char unk0x00[0x80];
    unsigned int dwCode;
    char unk0x84[0x9E];
    unsigned char nSubType;
};

typedef int(__fastcall* ObeliskPowerUpFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue);

struct D2ObeliskPowerUpStrc
{
    ObeliskPowerUpFunction pPowerUpCallback;
    unsigned int nChance;
    int nValue;
};

extern D2ObeliskPowerUpStrc gaObeliskPowerUps_00732EB0[21];                                                 // 0x00732EB0
extern int gnObeliskPowerUps_00732FAC;                                                                      // 0x00732FAC

// 0x00585240
static __declspec(noinline) int __stdcall sub_00585240_ApplyObeliskPowerUp(D2GameStrc* pGame, unsigned char nSubType, D2UnitStrc* pPlayer)
{
    if (nSubType < gnObeliskPowerUps_00732FAC)
    {
        const unsigned __int64 lSeed = pPlayer->pSeed.nHighSeed + 0x6AC690C5i64 * pPlayer->pSeed.nLowSeed;
        pPlayer->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pPlayer->pSeed.nLowSeed = (unsigned int)lSeed;
        if ((unsigned int)lSeed % 100 < gaObeliskPowerUps_00732EB0[nSubType].nChance)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gaObeliskPowerUps_00732EB0[nSubType].pPowerUpCallback), 4341);
            return gaObeliskPowerUps_00732EB0[nSubType].pPowerUpCallback(pGame, pPlayer, gaObeliskPowerUps_00732EB0[nSubType].nValue);
        }
    }

    return 0;
}

int __fastcall sub_M98_Emit_00585240(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ItemsTxt* pItemsTxtRecord, int nExtra)
{
    return sub_00585240_ApplyObeliskPowerUp(pGame, pItemsTxtRecord->nSubType, pPlayer) + nExtra;
}

#include "gen/data/Source/D2Game/00585240_sub_00585240_ApplyObeliskPowerUp.inc"
