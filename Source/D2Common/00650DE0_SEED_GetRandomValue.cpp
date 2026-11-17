extern "C" long __cdecl _time32(long* pTime);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

static __forceinline void SEED_Step(unsigned int* pSeed)
{
    *pSeed = *pSeed * 0x19660D + 0x3C6EF35F;
}

// 0x00650DE0
int __fastcall SEED_GetRandomValue(int nValue)
{
    unsigned int nSeed = _time32(0);
    nSeed += GetTickCount();
    nSeed += nValue;
    SEED_Step(&nSeed);
    SEED_Step(&nSeed);
    SEED_Step(&nSeed);
    return nSeed & 0x7FFFFFFF;
}
