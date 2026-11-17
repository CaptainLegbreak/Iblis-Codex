struct D2DrlgCoordStrc
{
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
};

struct D2DrlgLevelLinkDataStrc
{
    char unk0x00[0x08];
    D2DrlgCoordStrc pLevelCoord[15];
};

struct D2DrlgLinkStrc
{
    void* pfLinker;
    int nLevel;
    int nLevelLink;
    int nLevelLinkEx;
};

extern D2DrlgLinkStrc gAct1MonasteryDrlgLink[];                                                             // 0x006F0840
extern D2DrlgLinkStrc gAct2OutdoorDrlgLink[];                                                               // 0x006F0930
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance); // 0x0066B860

// 0x00676EB0
int __fastcall sub_6FD82130(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    const int nLevelLink = gAct1MonasteryDrlgLink[nIteration].nLevelLink;
    int nCounter = 0;

    while (nCounter < nIteration)
    {
        if (nCounter != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[nCounter], 0))
        {
            return 0;
        }

        ++nCounter;
    }

    int bResult = 1;
    if (nIteration)
    {
        pLevelLinkData->pLevelCoord[0].nHeight += 200;
        pLevelLinkData->pLevelCoord[0].nPosY -= 200;

        bResult = DRLG_CheckNotOverlappingUsingManhattanDistance(pLevelLinkData->pLevelCoord, &pLevelLinkData->pLevelCoord[nCounter], 0);

        pLevelLinkData->pLevelCoord[0].nHeight -= 200;
        pLevelLinkData->pLevelCoord[0].nPosY += 200;
    }

    return bResult;
}

// 0x00676F50
int __fastcall DRLGOUTPLACE_LinkAct2Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nCounter = 0;
    const int nLevelLink = gAct2OutdoorDrlgLink[nIteration].nLevelLink;

    while (nCounter < nIteration)
    {
        if (nCounter != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[nCounter], 0))
        {
            return 0;
        }

        ++nCounter;
    }

    return 1;
}
