extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
#pragma intrinsic(memcpy)

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

struct D2GameStrc
{
    char unk0x00[0x1C];
    void* pMemoryPool;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

// 0x00572530
void __fastcall PLRINTRO_CopyNpcIntroFlagsToBuffer(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer)
{
    memcpy(pBuffer, pPlayerIntro->pNpcIntroFlags->pBuffer, 8);
}

// 0x00572540
void __fastcall PLRINTRO_CopyBufferToQuestIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer)
{
    memcpy(pPlayerIntro->pQuestIntroFlags->pBuffer, pBuffer, 8);
}

// 0x00572550
void __fastcall PLRINTRO_CopyBufferToNpcIntroFlags(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer)
{
    memcpy(pPlayerIntro->pNpcIntroFlags->pBuffer, pBuffer, 8);
}

// 0x00572620
void __fastcall PLRINTRO_Destroy(D2GameStrc* pGame, D2PlrIntroStrc* pPlayerIntro)
{
    if (pPlayerIntro->pQuestIntroFlags)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro->pQuestIntroFlags->pBuffer, ".\\PLAYER\\PlrIntro.cpp", 219, 0);
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro->pQuestIntroFlags, ".\\PLAYER\\PlrIntro.cpp", 220, 0);
        pPlayerIntro->pQuestIntroFlags = 0;
    }

    if (pPlayerIntro->pNpcIntroFlags)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro->pNpcIntroFlags->pBuffer, ".\\PLAYER\\PlrIntro.cpp", 225, 0);
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro->pNpcIntroFlags, ".\\PLAYER\\PlrIntro.cpp", 226, 0);
        pPlayerIntro->pNpcIntroFlags = 0;
    }

    FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerIntro, ".\\PLAYER\\PlrIntro.cpp", 229, 0);
}
