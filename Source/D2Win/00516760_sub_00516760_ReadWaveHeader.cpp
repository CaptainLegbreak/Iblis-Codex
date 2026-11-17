struct D2WaveFormatStrc
{
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned int nSamplesPerSec;
    unsigned int nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};

// 0x005166D0
static const unsigned char* __stdcall sub_005166D0_FindRiffChunk(const unsigned char* pData, unsigned int* pnSize, unsigned int nChunkId, unsigned int* pnChunkSize)
{
    while (*pnSize >= 8)
    {
        *pnSize -= 8;
        const unsigned int nRemaining = *pnSize;
        const unsigned int* pHeader = (const unsigned int*)pData;
        pData += 8;
        const unsigned int nLength = pHeader[1];
        if (pHeader[0] == nChunkId)
        {
            *pnChunkSize = nLength;
            return pData;
        }

        if (nRemaining < nLength)
            return 0;

        *pnSize = nRemaining - nLength;
        pData += nLength;
    }

    return 0;
}

// 0x00516760
const unsigned char* __fastcall sub_00516760_ReadWaveHeader(const unsigned int* pRiff, unsigned int* pnSize, D2WaveFormatStrc* pFormat)
{
    D2WaveFormatStrc* const pOut = pFormat;
    if (*pnSize < 0x20)
        return 0;

    *pnSize -= 12;
    if (pRiff[0] != 0x46464952 || pRiff[2] != 0x45564157)
        return 0;

    unsigned int nChunkSize = 0;
    const unsigned char* pChunk = sub_005166D0_FindRiffChunk((const unsigned char*)pRiff + 12, pnSize, 0x20746D66, &nChunkSize);
    if (!pChunk)
        return 0;

    if (nChunkSize < 0x10)
        return 0;

    if (*pnSize < nChunkSize)
        return 0;

    const D2WaveFormatStrc* pChunkFormat = (const D2WaveFormatStrc*)pChunk;
    *pnSize -= nChunkSize;
    pChunk += nChunkSize;
    pOut->wFormatTag = pChunkFormat->wFormatTag;
    pOut->nChannels = pChunkFormat->nChannels;
    pOut->nSamplesPerSec = pChunkFormat->nSamplesPerSec;
    pOut->nAvgBytesPerSec = pChunkFormat->nAvgBytesPerSec;
    pOut->nBlockAlign = pChunkFormat->nBlockAlign;
    pOut->wBitsPerSample = pChunkFormat->wBitsPerSample;
    pOut->cbSize = 0;

    pChunk = sub_005166D0_FindRiffChunk(pChunk, pnSize, 0x61746164, &nChunkSize);
    if (pChunk && *pnSize >= nChunkSize)
    {
        *pnSize = nChunkSize;
        return pChunk;
    }

    return 0;
}
