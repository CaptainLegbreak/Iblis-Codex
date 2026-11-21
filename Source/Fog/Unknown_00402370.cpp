#include "Fog.h"

int gdwGlobal_00992B1C;           // 0x00992B1C
int __stdcall sub_004198D0(void* pArg);    // 0x004198D0
int gdwGlobal_0074C82C;           // 0x0074C82C
extern "C" int __stdcall closesocket(unsigned int s);    // 0x006B012C
extern "C" int __stdcall WSACleanup(void);    // 0x006B0138
struct PairStrc_0040F570
{
    int nFirst;
    int nSecond;
};


// 0x00402370
int __stdcall sub_00402370(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x00405EF0
int __cdecl sub_00405EF0()
{
    return 1;
}

// 0x004068F0
int __fastcall sub_004068F0(void* pArg)
{
    return sub_004198D0(pArg);
}

// 0x00406D20
int __cdecl sub_00406D20()
{
    return gdwGlobal_0074C82C;
}

// 0x00407FF0
int __cdecl sub_00407FF0()
{
    return gdwGlobal_0074F0C8;
}

// 0x004080A0
void __stdcall sub_004080A0(int nUnused1, int nUnused2)
{
}

// 0x0040A070
int __cdecl sub_0040A070()
{
    return 0;
}

// 0x0040ABE0
int __cdecl sub_0040ABE0()
{
    return 0;
}

// 0x0040D880
int __fastcall sub_0040D880(unsigned int s)
{
    return closesocket(s);
}

// 0x0040D8D0
int __cdecl sub_0040D8D0()
{
    return WSACleanup();
}

// 0x0040EB10
int __cdecl sub_0040EB10()
{
    return 0;
}

// 0x0040F570
void __fastcall sub_0040F570(PairStrc_0040F570* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}
