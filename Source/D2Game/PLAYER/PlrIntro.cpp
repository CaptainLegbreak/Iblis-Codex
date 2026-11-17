#include "D2Game.h"

struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    char unk0x04[0x10];
};

struct D2PlrIntroStrc
{
    D2BitBufferStrc* pQuestIntroFlags;
    D2BitBufferStrc* pNpcIntroFlags;
};

struct D2NpcIndexMapStrc
{
    int nNpcClassId;
    int nIndex;
};

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern D2NpcIndexMapStrc gaPlrIntroNpcIndexMap[];                                                           // 0x00732738
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __stdcall BITMANIP_SetBitState(unsigned char* pBitBuffer, int nBit);                                   // 0x00410B10
int __stdcall BITMANIP_GetBitState(unsigned char* pBitBuffer, int nBit);                                    // 0x00410B30
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize);         // 0x00410E40

static int PLRINTRO_GetNpcIndex(int nNpcId)
{
    for (int i = 0; i < gnPlrIntroNpcIndexMapCount; ++i)
    {
        if (gaPlrIntroNpcIndexMap[i].nNpcClassId == nNpcId)
        {
            return gaPlrIntroNpcIndexMap[i].nIndex;
        }
    }

    return 0;
}

// 0x00572420
void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId)
{
    BITMANIP_SetBitState(pPlayerIntro->pNpcIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x00572470
int __fastcall PLRINTRO_GetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId)
{
    return BITMANIP_GetBitState(pPlayerIntro->pNpcIntroFlags->pBuffer, PLRINTRO_GetNpcIndex(nNpcId));
}

// 0x00572560
D2PlrIntroStrc* __fastcall PLRINTRO_Create(D2GameStrc* pGame)
{
    D2PlrIntroStrc* pPlayerIntro = (D2PlrIntroStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2PlrIntroStrc), ".\\PLAYER\\PlrIntro.cpp", 196, 0);
    D2BitBufferStrc* pBitBuffer1 = (D2BitBufferStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2BitBufferStrc), ".\\PLAYER\\PlrIntro.cpp", 197, 0);
    unsigned char* pBuffer1 = (unsigned char*)sub_0040B430(pGame->pMemoryPool, 8, ".\\PLAYER\\PlrIntro.cpp", 198, 0);
    memset(pBuffer1, 0, 8);

    BITMANIP_Initialize(pBitBuffer1, pBuffer1, 8);
    pPlayerIntro->pQuestIntroFlags = pBitBuffer1;

    D2BitBufferStrc* pBitBuffer2 = (D2BitBufferStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2BitBufferStrc), ".\\PLAYER\\PlrIntro.cpp", 203, 0);
    unsigned char* pBuffer2 = (unsigned char*)sub_0040B430(pGame->pMemoryPool, 8, ".\\PLAYER\\PlrIntro.cpp", 204, 0);
    memset(pBuffer2, 0, 8);

    BITMANIP_Initialize(pBitBuffer2, pBuffer2, 8);
    pPlayerIntro->pNpcIntroFlags = pBitBuffer2;

    return pPlayerIntro;
}
