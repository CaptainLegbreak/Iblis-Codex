extern "C" int __cdecl abs(int);

extern const int gaADPCMStepTable_006CFD38[];                                                               // 0x006CFD38
extern const int gaADPCMIndexTable_006CFCB8[];                                                              // 0x006CFCB8

struct D2AdpcmHeaderStrc
{
    unsigned char nZero;
    unsigned char f_1;
};

// 0x0041DA30
static __declspec(noinline) void sub_0041DA30_GetCompressionLevel(unsigned int nCmpLevel, unsigned char* pnLevel, int* pCmpType)
{
    switch (nCmpLevel)
    {
    case 1:
    case 2:
        *pnLevel = 4;
        *pCmpType = 6;
        break;
    case 3:
        *pnLevel = 6;
        *pCmpType = 8;
        break;
    default:
        *pnLevel = 5;
        *pCmpType = 7;
        break;
    }
}

// 0x0041DA60
static int __stdcall sub_0041DA60_CompressADPCM(int nOutSize, const short* pIn, int nInSize, unsigned int nChannels, unsigned char nLevel, unsigned char* pOut)
{
    unsigned char* pOutStart = pOut;
    if ((unsigned int)nOutSize < 2)
    {
        return 2;
    }
    D2AdpcmHeaderStrc tHeader;
    tHeader.nZero = 0;
    tHeader.f_1 = nLevel - 1;
    *(D2AdpcmHeaderStrc*)pOut = tHeader;
    pOut += 2;
    if (pOut + nChannels * 2 - pOutStart > nOutSize)
    {
        return pOut + nChannels * 2 - pOutStart;
    }
    int aSample[2];
    int aPredicted[2];
    int aStepIndex[2];
    aStepIndex[0] = 0x2C;
    aStepIndex[1] = 0x2C;
    unsigned int i;
    for (i = 0; i < nChannels; i++)
    {
        aPredicted[i] = *pIn++;
        *(short*)pOut = (short)aPredicted[i];
        pOut += 2;
    }
    int nGrowLeft = (nInSize / 2 - (pOut - pOutStart) < 0) ? 0 : nInSize / 2 - (pOut - pOutStart);
    int nChannel = nChannels - 1;
    const unsigned int nWords = nInSize / sizeof(short);
    for (i = nChannels; i < nWords; i++)
    {
        if (pOut + 2 - pOutStart > nOutSize)
        {
            return pOut + 2 - pOutStart;
        }
        if (nChannels == 2)
        {
            nChannel = nChannel == 0;
        }
        aSample[nChannel] = *pIn++;
        const unsigned int nAbs = abs(aSample[nChannel] - aPredicted[nChannel]);
        const int nSignBit = aSample[nChannel] >= aPredicted[nChannel] ? 0 : 0x40;
        unsigned int nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
        if (nAbs < (nStepSize >> nLevel))
        {
            if (aStepIndex[nChannel])
            {
                aStepIndex[nChannel]--;
            }
            *pOut++ = 0x80;
            continue;
        }
        while (nAbs > nStepSize * 2 && aStepIndex[nChannel] < 0x58 && nGrowLeft)
        {
            aStepIndex[nChannel] += 8;
            if (aStepIndex[nChannel] > 0x58)
            {
                aStepIndex[nChannel] = 0x58;
            }
            nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
            *pOut++ = 0x81;
            nGrowLeft--;
        }
        unsigned int nMask = 0;
        unsigned int nTotal = 0;
        const unsigned int nStepRest = nStepSize >> tHeader.f_1;
        unsigned int nBit = 1;
        const unsigned int nMaxBit = ((unsigned int)(1 << (nLevel - 2)) > 0x20) ? 0x20 : (1 << (nLevel - 2));
        for (;;)
        {
            if (nTotal + nStepSize <= nAbs)
            {
                nMask |= nBit;
                nTotal += nStepSize;
            }
            if (nBit == nMaxBit)
            {
                break;
            }
            nStepSize >>= 1;
            nBit <<= 1;
        }
        nTotal += nStepRest;
        int nPredicted = aPredicted[nChannel];
        if (nSignBit)
        {
            nPredicted -= nTotal;
            if (nPredicted < -0x8000)
            {
                nPredicted = -0x8000;
            }
        }
        else
        {
            nPredicted += nTotal;
            if (nPredicted > 0x7FFF)
            {
                nPredicted = 0x7FFF;
            }
        }
        aPredicted[nChannel] = nPredicted;
        *pOut++ = (unsigned char)(nSignBit | nMask);
        aStepIndex[nChannel] += gaADPCMIndexTable_006CFCB8[nMask & 0x1F];
        if (aStepIndex[nChannel] < 0)
        {
            aStepIndex[nChannel] = 0;
        }
        else if (aStepIndex[nChannel] > 0x58)
        {
            aStepIndex[nChannel] = 0x58;
        }
    }
    return pOut - pOutStart;
}

// 0x0041E360
void __fastcall sub_0041E360_SCompADPCMCompressMono(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = sub_0041DA60_CompressADPCM(*pcbOutBuffer, pvInBuffer, cbInBuffer, 1, nLevel, pvOutBuffer);
}

// 0x0041E3C0
void __fastcall sub_0041E3C0_SCompADPCMCompressStereo(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = sub_0041DA60_CompressADPCM(*pcbOutBuffer, pvInBuffer, cbInBuffer, 2, nLevel, pvOutBuffer);
}
