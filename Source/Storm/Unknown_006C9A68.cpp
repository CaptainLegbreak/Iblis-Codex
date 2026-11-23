#include "Storm.h"

struct D2Block006CAB30Strc;
struct D2Block006CAB90Strc;
char* __fastcall sub_006C9AFF(char* p, char c); // 0x006C9AFF
extern "C" __declspec(dllimport) char* __stdcall CharNextA(const char*); // 0x006CC450
extern unsigned long gdwThreadId_00992B1C; // 0x00992B1C
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_0075E838[]; // 0x0075E838
void __cdecl sub_006CB070_DeleteCriticalSection(); // 0x006CB070
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824
extern unsigned char gCriticalSection_0075E850[]; // 0x0075E850
void __cdecl sub_006CB080_DeleteCriticalSection(); // 0x006CB080
extern unsigned int gnListTerminator_00708358; // 0x00708358
extern void* gpListHead_0070835C; // 0x0070835C
void __cdecl sub_006CB0C0_DestroyList(); // 0x006CB0C0
extern unsigned int gnListTerminator_00708364; // 0x00708364
extern void* gpListHead_00708368; // 0x00708368
void __cdecl sub_006CB120_DestroyList(); // 0x006CB120
extern unsigned char gCriticalSection_00779068[]; // 0x00779068
void __cdecl sub_006CB0A0_DeleteCriticalSection(); // 0x006CB0A0
extern unsigned int gnListTerminator_00708370; // 0x00708370
extern void* gpListHead_00708374; // 0x00708374
void __cdecl sub_006CB180_DestroyList(); // 0x006CB180
extern unsigned int gnListTerminator_0070837C; // 0x0070837C
extern void* gpListHead_00708380; // 0x00708380
void __cdecl sub_006CB1E0_DestroyList(); // 0x006CB1E0
extern unsigned int gnListTerminator_00708388; // 0x00708388
extern void* gpListHead_0070838C; // 0x0070838C
void __cdecl sub_006CB240_DestroyList(); // 0x006CB240
extern unsigned char gCriticalSection_00779080[]; // 0x00779080
void __cdecl sub_006CB0B0_DeleteCriticalSection(); // 0x006CB0B0
extern unsigned int gnListTerminator_00708424; // 0x00708424
extern void* gpListHead_00708428; // 0x00708428
void __cdecl sub_006CB2A0_DestroyList(); // 0x006CB2A0
void __cdecl sub_006CB300_DeleteCriticalSection(); // 0x006CB300
extern unsigned int gnListTerminator_00708864; // 0x00708864
extern void* gpListHead_00708868; // 0x00708868
void __cdecl sub_006CB310_DestroyList(); // 0x006CB310
extern unsigned int gnListTerminator_007088EC; // 0x007088EC
extern void* gpListHead_007088F0; // 0x007088F0
void __cdecl sub_006CB380_DestroyList(); // 0x006CB380
extern unsigned char gCriticalSection_0077930C[]; // 0x0077930C
void __cdecl sub_006CB370_DeleteCriticalSection(); // 0x006CB370
extern unsigned short gwszRealmNames_00779DF0[7 * 0x100]; // 0x00779DF0
unsigned int __stdcall SStrHash(const char* text, unsigned int flags, unsigned int hashSeed); // 0x00413CE0
extern const char* gpszDefaultCaption_0070EE50; // 0x0070EE50
extern const char* gpszHelpCaption; // 0x007A0454
extern unsigned short gwszText_007A2C80[80]; // 0x007A2C80
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

// 0x006C9A68
int __fastcall sub_006C9A68_GetDigitClass(signed char character)
{
    return gCharacterClass_0074C5C8[character] & 2;
}

#include "gen/data/Source/Storm/Unknown_006C9A68.inc"

// 0x006C9AB9
int __fastcall sub_006C9AB9_GetSpaceClass(signed char character)
{
    return gCharacterClass_0074C5C8[character] & 1;
}

// 0x006C9B45
char* __fastcall sub_006C9B45(char* s)
{
    char* r = sub_006C9AFF(s, 0x5C);
    if (!r)
        return s;
    if (*CharNextA(r) != 0)
        return s;
    *r = 0;
    return s;
}

// 0x006CA6F0
void __cdecl sub_006CA6F0_RecordThreadId()
{
    gdwThreadId_00992B1C = GetCurrentThreadId();
}

// 0x006CA700
void __cdecl sub_006CA700_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0075E838);
    sub_00683824_RegisterExit(sub_006CB070_DeleteCriticalSection);
}

// 0x006CA720
void __cdecl sub_006CA720_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0075E850);
    sub_00683824_RegisterExit(sub_006CB080_DeleteCriticalSection);
}

// 0x006CA7B0
void __cdecl sub_006CA7B0_InitializeList()
{
    gpListHead_0070835C = (void*)~(unsigned int)&gnListTerminator_00708358;
    atexit(sub_006CB0C0_DestroyList);
}

// 0x006CA7D0
void __cdecl sub_006CA7D0_InitializeList()
{
    gpListHead_00708368 = (void*)~(unsigned int)&gnListTerminator_00708364;
    atexit(sub_006CB120_DestroyList);
}

// 0x006CA7F0
void __cdecl sub_006CA7F0_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00779068);
    sub_00683824_RegisterExit(sub_006CB0A0_DeleteCriticalSection);
}

// 0x006CA810
void __cdecl sub_006CA810_InitializeList()
{
    gpListHead_00708374 = (void*)~(unsigned int)&gnListTerminator_00708370;
    atexit(sub_006CB180_DestroyList);
}

// 0x006CA830
void __cdecl sub_006CA830_InitializeList()
{
    gpListHead_00708380 = (void*)~(unsigned int)&gnListTerminator_0070837C;
    atexit(sub_006CB1E0_DestroyList);
}

// 0x006CA850
void __cdecl sub_006CA850_InitializeList()
{
    gpListHead_0070838C = (void*)~(unsigned int)&gnListTerminator_00708388;
    atexit(sub_006CB240_DestroyList);
}

// 0x006CA870
void __cdecl sub_006CA870_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00779080);
    sub_00683824_RegisterExit(sub_006CB0B0_DeleteCriticalSection);
}

// 0x006CA8A0
void __cdecl sub_006CA8A0_InitializeList()
{
    gpListHead_00708428 = (void*)~(unsigned int)&gnListTerminator_00708424;
    atexit(sub_006CB2A0_DestroyList);
}

unsigned char gCriticalSection_00779214[24]; // 0x00779214

// 0x006CA8C0
void __cdecl sub_006CA8C0_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_00779214);
    sub_00683824_RegisterExit(sub_006CB300_DeleteCriticalSection);
}

// 0x006CA8E0
void __cdecl sub_006CA8E0_InitializeList()
{
    gpListHead_00708868 = (void*)~(unsigned int)&gnListTerminator_00708864;
    atexit(sub_006CB310_DestroyList);
}

// 0x006CA900
void __cdecl sub_006CA900_InitializeList()
{
    gpListHead_007088F0 = (void*)~(unsigned int)&gnListTerminator_007088EC;
    atexit(sub_006CB380_DestroyList);
}

// 0x006CA920
void __cdecl sub_006CA920_InitializeLock()
{
    InitializeCriticalSection(gCriticalSection_0077930C);
    sub_00683824_RegisterExit(sub_006CB370_DeleteCriticalSection);
}

// 0x006CA940
void __cdecl sub_006CA940_ClearRealmNames()
{
    for (int n = 0; n < 7 * 0x100; ++n)
    {
        gwszRealmNames_00779DF0[n] = 0;
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

// 0x006CA9A0
void __cdecl sub_006CA9A0_Initialize()
{
    gpszHelpCaption = gpszDefaultCaption_0070EE50;
}

const char* gpszCaption_007A0450; // 0x007A0450

// 0x006CA9B0
void __cdecl sub_006CA9B0_Initialize()
{
    gpszCaption_007A0450 = gpszDefaultCaption_0070EE50;
}

// 0x006CAA10
void __cdecl sub_006CAA10_ClearText()
{
    for (int i = 0; i < 80; ++i)
    {
        gwszText_007A2C80[i] = 0;
    }
}

// 0x006CAA90
void __cdecl sub_006CAA90_Initialize()
{
    gnAutomapWidth = gnScreenWidth;
}

// 0x006CAAA0
void __cdecl sub_006CAAA0_InitializeHeight()
{
    gnAutomapHeight_007A521C = gnScreenHeight - 40;
}

int gnQuotient_007A6B0C; // 0x007A6B0C

// 0x006CAAB0
void __cdecl sub_006CAAB0_SetPerSecond()
{
    gnQuotient_007A6B0C = 1000 / gnDivisor_007121DC;
}

unsigned short gwCharacterBuffer_007A741C; // 0x007A741C

unsigned short gwCharacterBuffer_007A741E; // 0x007A741E

unsigned short gwCharacterBuffer_007A7420; // 0x007A7420

unsigned short gwCharacterBuffer_007A7422; // 0x007A7422

// 0x006CAAD0
void __cdecl sub_006CAAD0_ClearCharacterBuffer()
{
    gwCharacterBuffer_007A741C = 0;
    gwCharacterBuffer_007A741E = 0;
    gwCharacterBuffer_007A7420 = 0;
    gwCharacterBuffer_007A7422 = 0;
}

unsigned short gwszBuffer_007BB638[257]; // 0x007BB638

// 0x006CAAF0
void __cdecl sub_006CAAF0_ClearBuffer()
{
    for (int i = 0; i < 257; ++i)
    {
        gwszBuffer_007BB638[i] = 0;
    }
}

// 0x006CAB30
void __cdecl sub_006CAB30_InitBlock()
{
    gBlock_007BC850.n00 = 0;
    gBlock_007BC850.n04 = 0;
    gBlock_007BC850.n08 = 0;
    gBlock_007BC850.n0C = 0;
    gBlock_007BC850.n10 = 0;
    gBlock_007BC850.n14 = 0;
    gBlock_007BC850.n18 = 0;
    gBlock_007BC850.n1C = 0;
    gBlock_007BC850.n20 = 0;
    gBlock_007BC850.n24 = 0;
    gBlock_007BC850.n28 = 0;
    gBlock_007BC850.n2C = 0;
    gBlock_007BC850.n30 = 0;
    gBlock_007BC850.n34 = 0;
    gBlock_007BC850.n38 = 0;
    gBlock_007BC850.n3C = 0;
}

// 0x006CAB90
void __cdecl sub_006CAB90_InitBlock()
{
    gBlock_007BB5F8.n00 = 0;
    gBlock_007BB5F8.n04 = 0;
    gBlock_007BB5F8.n08 = 0;
    gBlock_007BB5F8.n0C = 0;
    gBlock_007BB5F8.n10 = 0;
    gBlock_007BB5F8.n14 = 0;
    gBlock_007BB5F8.n18 = 0;
    gBlock_007BB5F8.n1C = 0;
    gBlock_007BB5F8.n20 = 0;
    gBlock_007BB5F8.n24 = 0;
    gBlock_007BB5F8.n28 = 0;
    gBlock_007BB5F8.n2C = 0;
    gBlock_007BB5F8.n30 = 0;
    gBlock_007BB5F8.n34 = 0;
    gBlock_007BB5F8.n38 = 0;
    gBlock_007BB5F8.n3C = 0;
}

// 0x006CAC10
void __cdecl sub_006CAC10_InitializeHorizontalPosition()
{
    gnTextLeft = (gnScreenWidth_0071146C - 325) / 2;
}
