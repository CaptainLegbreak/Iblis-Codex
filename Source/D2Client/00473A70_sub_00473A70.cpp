struct D2CelFileStrc;

struct D2GfxDataStrc
{
    int nFrame;
    char unk0x04[0x30];
    D2CelFileStrc* pCellFile;
    char unk0x38[0x08];
    int nDirection;
    char unk0x44[0x04];
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

struct D2WeatherLayerStateStrc
{
    D2CelFileStrc* pCelFiles[4];
};

int __stdcall D2GFX_CheckPerspective();                                                                     // 0x004F51D0
int __cdecl sub_0045AE90();                                                                         // 0x0045AE90
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
int __stdcall SCALE_CheckPerspectivePosition(int nXPos, int nYPos);                                         // 0x004F66E0
void __stdcall SCALE_AdjustPerspectivePosition(int nXPos, int nYPos, int nBias, int* pXAdjust, int* pYAdjust); // 0x004F6760
void __fastcall sub_006BCCD0_FreeDataArraySlot(D2WeatherStrc* pArray, int nSlot);                           // 0x006BCCD0

typedef int (__stdcall* D2CelDrawRetFn)(D2GfxDataStrc*, int, int, unsigned int, int, unsigned char*);

extern int gnGlobal_0071146C;                                                                               // 0x0071146C
extern int gnGlobal_00711470;                                                                               // 0x00711470

// 0x00473A70
void __fastcall sub_00473A70(D2WeatherStrc* pWeather, D2WeatherLayerStateStrc* pState)
{
    const int bPerspective = D2GFX_CheckPerspective();
    int nOffset = 0;
    int nLeft = 0;
    int nRight = gnGlobal_0071146C;
    int nBottom = gnGlobal_00711470 - 47;
    switch (sub_0045AE90())
    {
    case 1:
    {
        const int nQuarter = gnGlobal_0071146C / 4;
        nOffset = -nQuarter;
        nRight -= nQuarter * 2;
        break;
    }
    case 2:
        nOffset = gnGlobal_0071146C / 4;
        nLeft = gnGlobal_0071146C / 4 * 2;
        break;
    }

    D2GfxDataStrc tGfxData = {};
    D2WeatherSplashStrc* pRecord = pWeather->pRecords;
    for (int i = 0; i <= pWeather->nLastParticle; ++i, ++pRecord)
    {
        if (!pRecord->bActive)
        {
            continue;
        }

        if (bPerspective)
        {
            if (SCALE_CheckPerspectivePosition(pRecord->nX, pRecord->nY))
            {
                int nX;
                int nY;
                SCALE_AdjustPerspectivePosition(pRecord->nX, pRecord->nY, 0, &nX, &nY);
                nX += nOffset;
                if (nX >= nLeft && nX < nRight && nY >= 0 && nY < nBottom)
                {
                    tGfxData.pCellFile = pState->pCelFiles[pRecord->nType];
                    tGfxData.nFrame = pRecord->nFrame;
                    if (((D2CelDrawRetFn)&TEXTURE_CelDraw)(&tGfxData, nX, nY, -1, 3, 0))
                    {
                        continue;
                    }
                }
            }
            sub_006BCCD0_FreeDataArraySlot(pWeather, i << 16);
        }
        else
        {
            const int nX = pRecord->nX + nOffset;
            const int nY = pRecord->nY;
            if (nX >= nLeft && nX < nRight && nY >= 0 && nY < nBottom)
            {
                tGfxData.pCellFile = pState->pCelFiles[pRecord->nType];
                tGfxData.nFrame = pRecord->nFrame;
                TEXTURE_CelDraw(&tGfxData, nX, nY, -1, 3, 0);
            }
        }
    }
}
