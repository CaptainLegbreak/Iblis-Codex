extern const int gaADPCMStepTable_006CFD38[];                                                               // 0x006CFD38
extern const int gaADPCMIndexTable_006CFCB8[];                                                              // 0x006CFCB8

static int __stdcall sub_0041DCE0_DecompressADPCM(short* pOut, int nInLength, unsigned int nOutSize, unsigned char* pIn, unsigned int nChannels)
{
    int aPredicted[2];
    int aStep[2];
    aStep[0] = 0x2C;
    aStep[1] = 0x2C;
    unsigned char* pHeader = pIn;
    unsigned char* pInEnd = pIn + nInLength;
    short* pOutStart = pOut;
    pIn += 2;
    for (unsigned int i = 0; i < nChannels; i++)
    {
        const int nSample = *(short*)pIn;
        pIn += 2;
        aPredicted[i] = nSample;
        if (nOutSize < 2)
        {
            return (char*)pOut - (char*)pOutStart;
        }
        nOutSize -= 2;
        *pOut = nSample;
        pOut++;
    }
    int nChannel = nChannels - 1;
    while (pIn < pInEnd)
    {
        if (nChannels == 2)
        {
            nChannel = (nChannel == 0);
        }
        const unsigned char nByte = *pIn++;
        if (nByte & 0x80)
        {
            switch (nByte & 0x7F)
            {
            case 0:
                if (aStep[nChannel])
                {
                    aStep[nChannel]--;
                }
                if (nOutSize < 2)
                {
                    return (char*)pOut - (char*)pOutStart;
                }
                *pOut = aPredicted[nChannel];
                pOut++;
                nOutSize -= 2;
                continue;
            case 1:
                aStep[nChannel] += 8;
                if (aStep[nChannel] > 0x58)
                {
                    aStep[nChannel] = 0x58;
                }
                break;
            case 2:
                aStep[nChannel] -= 8;
                if (aStep[nChannel] < 0)
                {
                    aStep[nChannel] = 0;
                }
                break;
            default:
                continue;
            }
            if (nChannels == 2)
            {
                nChannel = (nChannel == 0);
            }
        }
        else
        {
            const unsigned int nStep = gaADPCMStepTable_006CFD38[aStep[nChannel]];
            unsigned int nDiff = nStep >> pHeader[1];
            if (nByte & 1)
                nDiff += nStep;
            if (nByte & 2)
                nDiff += nStep >> 1;
            if (nByte & 4)
                nDiff += nStep >> 2;
            if (nByte & 8)
                nDiff += nStep >> 3;
            if (nByte & 0x10)
                nDiff += nStep >> 4;
            if (nByte & 0x20)
                nDiff += nStep >> 5;
            int nValue = aPredicted[nChannel];
            if (nByte & 0x40)
            {
                nValue -= nDiff;
                if (nValue <= -0x8000)
                {
                    nValue = -0x8000;
                }
            }
            else
            {
                nValue += nDiff;
                if (nValue >= 0x7FFF)
                {
                    nValue = 0x7FFF;
                }
            }
            aPredicted[nChannel] = nValue;
            if (nOutSize < 2)
            {
                return (char*)pOut - (char*)pOutStart;
            }
            nOutSize -= 2;
            *pOut = aPredicted[nChannel];
            pOut++;
            aStep[nChannel] += gaADPCMIndexTable_006CFCB8[nByte & 0x1F];
            if (aStep[nChannel] < 0)
            {
                aStep[nChannel] = 0;
            }
            else if (aStep[nChannel] > 0x58)
            {
                aStep[nChannel] = 0x58;
            }
        }
    }
    return (char*)pOut - (char*)pOutStart;
}

// 0x0041E3A0
void __fastcall sub_0041E3A0_SCompADPCMDecompressMono(short* pOut, unsigned int* pOutSize, unsigned char* pIn, int nInLength, int nUnused)
{
    *pOutSize = sub_0041DCE0_DecompressADPCM(pOut, nInLength, *pOutSize, pIn, 1);
}

// 0x0041E400
void __fastcall sub_0041E400_SCompADPCMDecompressStereo(short* pOut, unsigned int* pOutSize, unsigned char* pIn, int nInLength, int nUnused)
{
    *pOutSize = sub_0041DCE0_DecompressADPCM(pOut, nInLength, *pOutSize, pIn, 2);
}

#include "gen/data/Source/Storm/0041E3A0_sub_0041E3A0_SCompADPCMDecompressMono.inc"
