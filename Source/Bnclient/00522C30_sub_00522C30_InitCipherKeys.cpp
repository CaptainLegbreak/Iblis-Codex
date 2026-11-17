struct D2IdeaUserKeyStrc
{
    unsigned int aKey[4];
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { sub_00408A60(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void __cdecl srand(unsigned int nSeed);                                                          // 0x00687454
extern "C" int __cdecl rand();                                                                              // 0x00687461
extern "C" long __cdecl _time32(long* pTime);                                                               // 0x006850E6

void __fastcall sub_00524280_InitHashContext(int nIndex);                                                   // 0x00524280
void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest);              // 0x00524200
void __cdecl sub_005241A0_ClearHashContexts();                                                              // 0x005241A0
void __fastcall sub_00524780_SetKey(int nIndex, int bEncrypt, const D2IdeaUserKeyStrc* pUserKey);           // 0x00524780

// 0x00522C30
void __fastcall sub_00522C30_InitCipherKeys(const char* szKey, int nUnused, volatile int bEncrypt)
{
    unsigned char abRandom[0x70];
    unsigned char abBlock[0x40];
    unsigned char abDigest[20];

    D2_ASSERT(szKey, 0x4E);

    srand(0x4FA7);
    unsigned char* pRandom = abRandom;
    int nCount = 0x70;
    while (nCount--)
    {
        *pRandom++ = (unsigned char)rand();
    }
    srand(_time32(0));

    int j = 0;
    for (int i = 0; i < 0x40; ++i)
    {
        if (!szKey[j])
        {
            j = 0;
        }
        abBlock[i] = szKey[j];
        ++j;
    }

    sub_00524280_InitHashContext(0);
    sub_00524200_HashBlock(0, abBlock, (unsigned int*)abDigest);
    sub_005241A0_ClearHashContexts();

    for (unsigned int i = 0; i < 0x70; ++i)
    {
        abRandom[i] ^= abDigest[i % 20];
    }

    for (int i = 0; i < 3; ++i)
    {
        sub_00524780_SetKey(i, bEncrypt, (const D2IdeaUserKeyStrc*)&abRandom[i * 16]);
        sub_00524280_InitHashContext(i);
        sub_00524200_HashBlock(i, &abRandom[0x30], 0);
    }
}
