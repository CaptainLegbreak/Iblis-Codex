extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC
extern unsigned char gCriticalSection_00881860[]; // 0x00881860
extern unsigned char gCriticalSection_00881894[]; // 0x00881894
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
extern void* gpNewsCacheItems_00881C38; // 0x00881C38
extern const char gszTypeNewsTableItem_0072FF8C[]; // 0x0072FF8C
extern unsigned char gCriticalSection_00881F64[24]; // 0x00881F64
extern unsigned char gCriticalSection_0088CAA8[]; // 0x0088CAA8

// 0x006CB420
void __cdecl sub_006CB420_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_00881860);
}

// 0x006CB440
void __cdecl sub_006CB440_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_00881894);
}

// 0x006CB450
void __cdecl sub_006CB450_StaticFiniNewsCache()
{
    if (gpNewsCacheItems_00881C38)
    {
        SMemFree(gpNewsCacheItems_00881C38, gszTypeNewsTableItem_0072FF8C, -2, 0);
    }
}

// 0x006CB470
void __cdecl sub_006CB470_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_00881F64);
}

// 0x006CB490
void __cdecl sub_006CB490_DestroyLock()
{
    DeleteCriticalSection(gCriticalSection_0088CAA8);
}
