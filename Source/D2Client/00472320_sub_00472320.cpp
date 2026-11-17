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

D2WeatherStrc* __fastcall sub_006BCA10_CreateDataArray(const char* szName, int nCount, int nRecordSize);    // 0x006BCA10
void __fastcall sub_006BCA90_FreeDataArray(D2WeatherStrc* pArray);                                          // 0x006BCA90
void __fastcall sub_006BCAC0_ResetDataArray(D2WeatherStrc* pArray);                                         // 0x006BCAC0
void __fastcall sub_006BCCC0(D2WeatherStrc* pArray);                                          // 0x006BCCC0
void __fastcall sub_006BCCD0_FreeDataArraySlot(D2WeatherStrc* pArray, int nSlot);                           // 0x006BCCD0
int __stdcall sub_004726F0(int nArg);                                                                       // 0x004726F0
int __cdecl sub_004F51D0_IsPerspective();                                                                   // 0x004F51D0

static D2WeatherStrc* gpWeather_007A8A04;                                                                   // 0x007A8A04
static D2WeatherStrc* gpWeather_007A89FC;                                                                   // 0x007A89FC
static D2WeatherStrc* gpWeather_007A8A00;                                                                   // 0x007A8A00

extern int gnPhaseLevel_007A89E0;                                                                           // 0x007A89E0
extern int gnGlobal_007A89D8;                                                                               // 0x007A89D8
int gnGlobal_007A89DC;                                                                                      // 0x007A89DC
extern int gnGlobal_007A8998;                                                                               // 0x007A8998
int gnGlobal_007A899C;                                                                                      // 0x007A899C
extern int gnGlobal_007A896C;                                                                               // 0x007A896C
int gnGlobal_007A8A08;                                                                                      // 0x007A8A08
extern int gnGlobal_007A8A0C;                                                                               // 0x007A8A0C
extern int gnGlobal_007A89E8;                                                                               // 0x007A89E8
extern int gnGlobal_00712B4C;                                                                               // 0x00712B4C
int gnViewDeltaX_007A0678;                                                                                  // 0x007A0678
int gnViewDeltaY_007A067C;                                                                                  // 0x007A067C
extern int gnSplashFrames_007A89C8[];                                                                       // 0x007A89C8
extern int gnBubbleFrames_007A892C[];                                                                       // 0x007A892C

// 0x00472320
void __cdecl sub_00472320()
{
    gpWeather_007A8A04 = sub_006BCA10_CreateDataArray("Environment Particles", 0x100, 0x28);
    sub_006BCCC0(gpWeather_007A8A04);
    gnPhaseLevel_007A89E0 = 0;
    gpWeather_007A89FC = sub_006BCA10_CreateDataArray("Environment Splashes", 0x200, 0x18);
    sub_006BCCC0(gpWeather_007A89FC);
    gpWeather_007A8A00 = sub_006BCA10_CreateDataArray("Environment Bubbles", 0x80, 0x18);
    sub_006BCCC0(gpWeather_007A8A00);
    gnGlobal_007A89DC = 0x2A;
    gnGlobal_007A89D8 = 0x2A;
    gnGlobal_007A896C = 0;
    gnGlobal_007A8A08 = 0;
    gnGlobal_007A8A0C = 0;
    gnGlobal_007A899C = 0xAA;
    gnGlobal_007A8998 = 0xAA;
}

// 0x004723C0
void __cdecl sub_004723C0()
{
    sub_006BCA90_FreeDataArray(gpWeather_007A8A04);
    sub_006BCA90_FreeDataArray(gpWeather_007A89FC);
    sub_006BCA90_FreeDataArray(gpWeather_007A8A00);
}

// 0x00472C20
void __fastcall sub_00472C20_PlayerMoved(int nArg)
{
    sub_006BCAC0_ResetDataArray(gpWeather_007A89FC);
    sub_006BCAC0_ResetDataArray(gpWeather_007A8A00);
    if (nArg)
        sub_004726F0(nArg);
}

// 0x00472C50
void __fastcall sub_00472C50(int nArg)
{
    if (!gnGlobal_007A8A08)
    {
        gnGlobal_007A8A08 = 1;
        gnGlobal_007A89E8 = 1;
        gnGlobal_007A896C = 0;
        gnGlobal_00712B4C = nArg;
    }
}

// 0x00472C80
void __fastcall sub_00472C80_StepSplashes(int nUnused)
{
    const int bPerspective = sub_004F51D0_IsPerspective();
    D2WeatherSplashStrc* pSplash = gpWeather_007A89FC->pRecords;
    for (int i = 0; i <= gpWeather_007A89FC->nLastParticle; i += 1, ++pSplash)
    {
        if (!pSplash->bActive)
            continue;

        if (!bPerspective)
        {
            pSplash->nX -= gnViewDeltaX_007A0678;
            pSplash->nY -= gnViewDeltaY_007A067C;
        }

        pSplash->f_14 -= 1;
        if (pSplash->f_14 <= 0)
        {
            pSplash->nFrame += 1;
            pSplash->f_14 = 2;
            if (pSplash->nFrame >= gnSplashFrames_007A89C8[pSplash->nType])
                sub_006BCCD0_FreeDataArraySlot(gpWeather_007A89FC, i << 16);
        }
    }
}

// 0x00472D10
void __fastcall sub_00472D10_StepBubbles(int nUnused)
{
    const int bPerspective = sub_004F51D0_IsPerspective();
    D2WeatherSplashStrc* pSplash = gpWeather_007A8A00->pRecords;
    for (int i = 0; i <= gpWeather_007A8A00->nLastParticle; i += 1, ++pSplash)
    {
        if (!pSplash->bActive)
            continue;

        if (!bPerspective)
        {
            pSplash->nX -= gnViewDeltaX_007A0678;
            pSplash->nY -= gnViewDeltaY_007A067C;
        }

        pSplash->f_14 -= 1;
        if (pSplash->f_14 <= 0)
        {
            pSplash->nFrame += 1;
            pSplash->f_14 = 2;
            if (pSplash->nFrame >= gnBubbleFrames_007A892C[pSplash->nType])
                sub_006BCCD0_FreeDataArraySlot(gpWeather_007A8A00, i << 16);
        }
    }
}
