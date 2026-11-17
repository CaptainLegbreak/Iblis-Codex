extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SeedStrc
{
    unsigned int nLowSeed;
    unsigned int nHighSeed;
};

struct D2UnitStrc
{
    char unk0x00[0x20];
    D2SeedStrc pSeed;
};

struct D2WeatherSplashStrc
{
    short bActive;
    short unk0x02;
    int nX;
    int nY;
    int nType;
    int nFrame;
    int f_14;
};

struct D2WeatherStrc
{
    char unk0x000[0x110];
    int nLastParticle;
    char unk0x114[0x08];
    D2WeatherSplashStrc* pRecords;
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();
int __stdcall D2GFX_CheckPerspective();                                                                     // 0x004F51D0
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange);                                 // 0x00472280
int __fastcall sub_006BCB40(D2WeatherStrc* pArray);

D2WeatherStrc* gpWeather_007A8A00;                                                                          // 0x007A8A00

// 0x00472EC0
void __fastcall sub_00472EC0_CreateBubble(int nX, int nY, int nFixX, int nFixY)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x2FC);

    D2SeedStrc* pSeed = &pPlayer->pSeed;
    const int nRecord = sub_006BCB40(gpWeather_007A8A00);
    if (nRecord == -1)
        return;

    D2WeatherSplashStrc* pBubble = &gpWeather_007A8A00->pRecords[(short)(nRecord >> 16)];
    int nNewY;
    if (D2GFX_CheckPerspective())
    {
        pBubble->nX = ((sub_00472280(pSeed, 0, 5) - 2) << 16) + nFixX;
        nNewY = ((sub_00472280(pSeed, 0, 5) - 2) << 16) + nFixY;
    }
    else
    {
        const int nRoll = sub_00472280(pSeed, 0, 0x50);
        int nDist = nRoll - 0x28;
        if (nDist < 0)
            nDist = -nDist;
        const int nSpread = 0x50 - (nDist << 1);
        pBubble->nX = sub_00472280(pSeed, -nSpread, 2 * nSpread) + nX;
        nNewY = nRoll + nY - 0x1E;
    }
    pBubble->nY = nNewY;

    pBubble->nType = 2;
    pBubble->nFrame = 0;
    pBubble->f_14 = 2;
}
