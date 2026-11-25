#include "Storm.h"

struct D2Block006CAB30Strc;
struct D2Block006CAB90Strc;
char* __fastcall sub_006C9AFF(char* p, char c); // 0x006C9AFF
extern "C" __declspec(dllimport) char* __stdcall CharNextA(const char*); // 0x006CC450
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824
extern unsigned short gwszRealmNames[7 * 0x100]; // 0x00779DF0
unsigned int __stdcall SStrHash(const char* text, unsigned int flags, unsigned int hashSeed); // 0x00413CE0
extern const char* gpszDefaultCaption_0070EE50; // 0x0070EE50
extern const char* gpszHelpCaption; // 0x007A0454
extern int gnScreenWidth; // 0x0071146C
extern int gnAutomapWidth; // 0x007A5220
extern int gnScreenHeight; // 0x00711470
extern int gnDivisor_007121DC; // 0x007121DC

struct D2Block006CAB30Strc
{
    int n00;
    int n04;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int n2C;
    int n30;
    int n34;
    int n38;
    int n3C;
};

extern D2Block006CAB30Strc gBlock_007BC850; // 0x007BC850

struct D2Block006CAB90Strc
{
    int n00;
    int n04;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int n2C;
    int n30;
    int n34;
    int n38;
    int n3C;
};

extern D2Block006CAB90Strc gBlock_007BB5F8; // 0x007BB5F8
extern int gnTextLeft; // 0x007BF278

#include "gen/data/Source/Storm/Unknown_006C9A68.inc"

// 0x006CA940
void __cdecl sub_006CA940_ClearRealmNames()
{
    for (int n = 0; n < 7 * 0x100; ++n)
    {
        gwszRealmNames[n] = 0;
    }
}

unsigned int gdwHeaderHash_0077AD64; // 0x0077AD64

// 0x006CA960
void __cdecl sub_006CA960_InitializeHeaderHash()
{
    gdwHeaderHash_0077AD64 = SStrHash("Header", 0, 0);
}

unsigned int gdwGameTimeHash_0077AD60; // 0x0077AD60

// 0x006CA980
void __cdecl sub_006CA980_InitializeGameTimeHash()
{
    gdwGameTimeHash_0077AD60 = SStrHash("Game Time", 0, 0);
}

const char* gpszCaption_007A0450; // 0x007A0450

int gnQuotient_007A6B0C; // 0x007A6B0C

// 0x006CAAB0
void __cdecl sub_006CAAB0_SetPerSecond()
{
    gnQuotient_007A6B0C = 1000 / gnDivisor_007121DC;
}

// 0x006CAC10
void __cdecl sub_006CAC10_InitializeHorizontalPosition()
{
    gnTextLeft = (gnScreenWidth_0071146C - 325) / 2;
}

