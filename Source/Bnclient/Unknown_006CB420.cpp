#include "D2BnCryptTypes.h"
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* section); // 0x006CC1FC

extern unsigned char gCriticalSection_00881860[]; // 0x00881860

extern unsigned char gCriticalSection_00881894[]; // 0x00881894

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

extern void* gpNewsCacheItems; // 0x00881C38

extern const char gszTypeNewsTableItem_0072FF8C[]; // 0x0072FF8C

extern unsigned char gCriticalSection_00881F64[24]; // 0x00881F64


// build: symbol ??1D2BigPairStrc@@QAE@XZ 0x00528530

extern D2BigPairStrc data_0088273C; // 0x0088273C

// 0x006CB480
void __cdecl sub_006CB480_DestroyBigPair()
{
    data_0088273C.~D2BigPairStrc();
}
