#include "Storm.h"
extern "C" __declspec(dllimport) void* __stdcall HeapAlloc(void* hHeap, unsigned long dwFlags, unsigned long dwBytes); // 0x006CC318

unsigned char gnStormByteFlag_0077905E;                                                                     // 0x0077905E
int (__stdcall* gpfnStormNotify_007790B8)(int nArg);                                                        // 0x007790B8
extern void* gpStormOwnerA_007790C0;                                                                        // 0x007790C0
void* gpStormOwnerB_007790C4;                                                                               // 0x007790C4
unsigned long gdwStormOwnerThread_007790C8;                                                                 // 0x007790C8
D2StormMsgSourceStrc* gpStormMsgSources_007790E8;                                                           // 0x007790E8

int __cdecl sub_00418B50();                                                                         // 0x00418B50
int __stdcall sub_00418390_FileQuery(void* hArchive, const char* szFileName, int nFlags);                  // 0x00418390
void* __cdecl sub_0041BEF0_GetExeModule();                                                                  // 0x0041BEF0
void __cdecl sub_0041C1A0_LockErrorState();                                                                 // 0x0041C1A0
void __cdecl sub_0041C1E0_UnlockErrorState();                                                               // 0x0041C1E0
void __stdcall sub_0041C360_SetSuppress(int bSuppress);                                                     // 0x0041C360
void __cdecl sub_0041FFF0_FlushAll();                                                                       // 0x0041FFF0

// 0x00416700
void __stdcall SFileSetPlatform(unsigned char nValue)
{
    gnStormByteFlag_0077905E = nValue;
}

// 0x00418B80
int __stdcall sub_00418B80_FileQueryDirect(const char* szFileName)
{
    return sub_00418390_FileQuery(0, szFileName, sub_00418B50());
}

// 0x0041BEB0
int __stdcall sub_0041BEB0_FlushAndNotify(int nArg)
{
    sub_0041C360_SetSuppress(1);
    sub_0041FFF0_FlushAll();
    if (gpfnStormNotify_007790B8)
        gpfnStormNotify_007790B8(nArg);
    return 0;
}

// 0x0041C0D0
char* __cdecl sub_0041C0D0_StrPbrk(const char* szString, const char* szCharSet)
{
    return strpbrk(szString, szCharSet);
}

// 0x0041C0F0
void __stdcall sub_0041C0F0_AppendExeMsgSource(unsigned short wFacility)
{
    D2StormMsgSourceStrc** ppSource = &gpStormMsgSources_007790E8;
    while (*ppSource)
        ppSource = &(*ppSource)->pNext;
    *ppSource = (D2StormMsgSourceStrc*)HeapAlloc(GetProcessHeap(), 4, sizeof(D2StormMsgSourceStrc));
    (*ppSource)->wFacility = wFacility;
    (*ppSource)->hModule = sub_0041BEF0_GetExeModule();
    (*ppSource)->pNext = 0;
}

// 0x0041C2C0
void __stdcall sub_0041C2C0_SetOwner(void* pOwnerA, void* pOwnerB)
{
    sub_0041C1A0_LockErrorState();
    gpStormOwnerA_007790C0 = pOwnerA;
    gpStormOwnerB_007790C4 = pOwnerB;
    gdwStormOwnerThread_007790C8 = GetCurrentThreadId();
    sub_0041C1E0_UnlockErrorState();
}

// 0x0041C2F0
int __stdcall sub_0041C2F0_RegisterMsgSource(unsigned short wFacility, void* hModule, void* pReserved)
{
    sub_0041C1A0_LockErrorState();
    D2StormMsgSourceStrc* pSource = (D2StormMsgSourceStrc*)HeapAlloc(GetProcessHeap(), 4, sizeof(D2StormMsgSourceStrc));
    pSource->wFacility = wFacility;
    pSource->hModule = hModule;
    pSource->pNext = gpStormMsgSources_007790E8;
    gpStormMsgSources_007790E8 = pSource;
    sub_0041C1E0_UnlockErrorState();
    return 1;
}
