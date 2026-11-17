struct D2GlideTexCacheEntryStrc;
struct D2GlideCache00509AA0Strc
{
    int unk0x00;
    int nCount;
    int nUsed;
    D2GlideTexCacheEntryStrc* pHead;
    D2GlideTexCacheEntryStrc* pTail;
    D2GlideTexCacheEntryStrc* f_14;
    D2GlideTexCacheEntryStrc* f_18;
    D2GlideTexCacheEntryStrc* pEntries;
};

void __fastcall sub_0050F7C0(D2GlideCache00509AA0Strc* pCache, int bFree); // 0x0050F7C0
void __fastcall sub_0050F210(D2GlideCache00509AA0Strc* pCache, int bFree); // 0x0050F210
void __cdecl sub_0050E030(); // 0x0050E030
void __fastcall sub_0050ECB0(D2GlideCache00509AA0Strc* pCache, int bFree); // 0x0050ECB0
void __cdecl sub_0050A0C0(); // 0x0050A0C0
void __cdecl sub_0050BB70(); // 0x0050BB70

int gbGlideInit_0087EFC8;        // 0x0087EFC8
extern int gbGlideTexCaches_0087EFE8; // 0x0087EFE8
typedef void (__stdcall* D2GlideFinishFn)();
typedef int (__stdcall* D2GlideIdleFn)(int nHandle);
D2GlideFinishFn gpfnGlideFinish_0087EB14;        // 0x0087EB14
D2GlideIdleFn gpfnGlideIdle_0087EFA4;        // 0x0087EFA4
int gnGlideHandle_0087EB94;        // 0x0087EB94
extern D2GlideCache00509AA0Strc gTexCacheA_0087EB68; // 0x0087EB68
extern D2GlideCache00509AA0Strc gTexCacheB_0087EB48; // 0x0087EB48
extern D2GlideCache00509AA0Strc gaGlideTexCaches_0087F048[4]; // 0x0087F048
#define gCacheA_0087F068 (gaGlideTexCaches_0087F048[1])
#define gCacheB_0087F088 (gaGlideTexCaches_0087F048[2])
#define gCacheC_0087F0A8 (gaGlideTexCaches_0087F048[3])
extern int gnGlideState_007C9140; // 0x007C9140

// 0x00509AA0
int __cdecl sub_00509AA0_GlideShutdown()
{
    if (gbGlideInit_0087EFC8)
    {
        gbGlideInit_0087EFC8 = 0;
        gpfnGlideFinish_0087EB14();
        if (gbGlideTexCaches_0087EFE8)
        {
            sub_0050F7C0(&gTexCacheA_0087EB68, 1);
            sub_0050F210(&gTexCacheB_0087EB48, 1);
        }
        else
        {
            sub_0050E030();
        }
        sub_0050ECB0(&gCacheA_0087F068, 1);
        sub_0050ECB0(&gCacheB_0087F088, 1);
        sub_0050ECB0(&gCacheC_0087F0A8, 1);
        sub_0050A0C0();
        for (int i = 0; ; ++i)
        {
            int nIdle = i < 100 ? gpfnGlideIdle_0087EFA4(gnGlideHandle_0087EB94) : 1;
            if (nIdle == 1)
            {
                break;
            }
        }
        sub_0050BB70();
        gnGlideState_007C9140 = 0;
    }
    return 1;
}
