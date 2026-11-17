extern const int gaADPCMStepTable_006CFD38[];                                                               // 0x006CFD38
extern const int gaADPCMIndexTable_006CFCB8[];                                                              // 0x006CFCB8

struct D2AdpcmHeaderStrc
{
    unsigned char nZero;
    unsigned char f_1;
};

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

static int __stdcall sub_0041DA60_CompressADPCM(int nOutSize, const short* pIn, int nInSize, unsigned int nChannels, unsigned char nLevel, unsigned char* pOut)
{
    unsigned char* pOutStart = pOut;
    if ((unsigned int)nOutSize < 2)
    {
        return 2;
    }
    D2AdpcmHeaderStrc tHeader;
    tHeader.f_1 = nLevel - 1;
    tHeader.nZero = 0;
    *(D2AdpcmHeaderStrc*)pOut = tHeader;
    pOut += 2;
    const int nHeader = nChannels * 2 + (pOut - pOutStart);
    if (nHeader > nOutSize)
    {
        return nHeader;
    }
    int aPredicted[2];
    int aStepIndex[2];
    aStepIndex[0] = 0x2C;
    aStepIndex[1] = 0x2C;
    for (unsigned int i = 0; i < nChannels; i++)
    {
        const int nSample = *pIn++;
        aPredicted[i] = nSample;
        *(short*)pOut = nSample;
        pOut += 2;
    }
    int nGrowLeft = nInSize / 2 - (pOut - pOutStart);
    nGrowLeft = nGrowLeft < 0 ? 0 : nGrowLeft;
    unsigned int nIndex = nChannels;
    const unsigned int nWords = (unsigned int)nInSize >> 1;
    int nChannel = nChannels - 1;
    if (nIndex >= nWords)
    {
        return pOut - pOutStart;
    }
    do
    {
        if ((pOut - pOutStart) + 2 > nOutSize)
        {
            return (pOut - pOutStart) + 2;
        }
        if (nChannels == 2)
        {
            nChannel = nChannel == 0;
        }
        const int nSample = *pIn++;
        int nDifference = nSample - aPredicted[nChannel];
        const unsigned int nAbs = nDifference < 0 ? -nDifference : nDifference;
        const unsigned char nSignBit = nSample >= aPredicted[nChannel] ? 0 : 0x40;
        unsigned int nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
        if (nAbs < (nStepSize >> nLevel))
        {
            if (aStepIndex[nChannel])
            {
                aStepIndex[nChannel]--;
            }
            *pOut++ = 0x80;
        }
        else
        {
            while (nAbs > nStepSize * 2 && aStepIndex[nChannel] < 0x58 && nGrowLeft)
            {
                aStepIndex[nChannel] += 8;
                if (aStepIndex[nChannel] > 0x58)
                {
                    aStepIndex[nChannel] = 0x58;
                }
                nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
                nGrowLeft--;
                *pOut++ = 0x81;
            }
            const unsigned int nStepRest = nStepSize >> tHeader.f_1;
            const unsigned int nMaxBit = 1 << (nLevel - 2);
            unsigned int nTotal = 0;
            unsigned int nMask = 0;
            unsigned int nLimit = 0x20;
            nInSize = 1;
            if (nMaxBit <= 0x20)
            {
                nLimit = nMaxBit;
            }
            for (;;)
            {
                if (nTotal + nStepSize <= nAbs)
                {
                    nTotal += nStepSize;
                    nMask |= nInSize;
                }
                if (nInSize == nLimit)
                {
                    break;
                }
                nStepSize >>= 1;
                nInSize <<= 1;
            }
            const int nDelta = nTotal + nStepRest;
            int nPredicted = aPredicted[nChannel];
            if (nSignBit)
            {
                nPredicted -= nDelta;
                if (nPredicted < -0x8000)
                {
                    nPredicted = -0x8000;
                }
            }
            else
            {
                nPredicted += nDelta;
                if (nPredicted > 0x7FFF)
                {
                    nPredicted = 0x7FFF;
                }
            }
            *pOut++ = nSignBit | (unsigned char)nMask;
            aStepIndex[nChannel] += gaADPCMIndexTable_006CFCB8[nMask & 0x1F];
            aPredicted[nChannel] = nPredicted;
            if (aStepIndex[nChannel] < 0)
            {
                aStepIndex[nChannel] = 0;
            }
            else if (aStepIndex[nChannel] > 0x58)
            {
                aStepIndex[nChannel] = 0x58;
            }
        }
        nIndex++;
    } while (nIndex < nWords);
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
