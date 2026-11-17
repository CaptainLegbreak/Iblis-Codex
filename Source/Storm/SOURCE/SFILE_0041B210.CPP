#include "Storm.h"

struct D2WaveChunkHeaderStrc
{
    unsigned int dwTag;
    unsigned int dwSize;
};

#define FILE_CURRENT 1
#define INVALID_SET_FILE_POINTER (-1)

int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped);       // 0x0041B050
void __stdcall sub_A02_EmitUse(unsigned int nValue);

// 0x0041B210
static int sub_0041B210_FindWaveChunk(void* hFile, unsigned int dwTag, unsigned int* pChunk)
{
    D2WaveChunkHeaderStrc tHeader;
    while (SFileReadFile(hFile, &tHeader, sizeof(tHeader), 0, 0))
    {
        if (tHeader.dwTag == dwTag)
        {
            pChunk[0] = tHeader.dwSize;
            const int nPosition = SFileSetFilePointer(hFile, 0, 0, FILE_CURRENT);
            pChunk[1] = nPosition;
            return nPosition != INVALID_SET_FILE_POINTER;
        }

        if (SFileSetFilePointer(hFile, tHeader.dwSize, 0, FILE_CURRENT) == INVALID_SET_FILE_POINTER)
        {
            break;
        }
    }

    return 0;
}

int __stdcall sub_A02_EmitFindChunk(void* hFile)
{
    unsigned int aChunk[2];
    aChunk[0] = 0;
    aChunk[1] = 0;
    if (!sub_0041B210_FindWaveChunk(hFile, 0x20746D66, aChunk))
    {
        return 0;
    }

    sub_A02_EmitUse(aChunk[0]);
    if (!sub_0041B210_FindWaveChunk(hFile, 0x61746164, aChunk))
    {
        return 0;
    }

    sub_A02_EmitUse(aChunk[1]);
    return 1;
}
