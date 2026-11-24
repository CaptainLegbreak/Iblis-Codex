#include "Storm.h"
#include "stpl.h"
#include "D2BnCryptTypes.h"
#include "D2GameTypes.h"

struct D2BigPairStrc;
struct D2CriticalSectionStrc;
namespace Storm { namespace SFile { struct ARCHIVEREC; } }
using Storm::SFile::ARCHIVEREC;
struct REQUEST;
struct FILEREC;
struct EVENTREC;
struct AUDIOSTREAM;
struct HANDLER;
struct WNDREC;
struct BREAKCMD;

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void* section); // 0x006CC210
extern unsigned char gCriticalSection_00881860[]; // 0x00881860
void __cdecl sub_006CB420_DestroyLock(); // 0x006CB420
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824
extern unsigned char gCriticalSection_00881894[]; // 0x00881894
void __cdecl sub_006CB440_DestroyLock(); // 0x006CB440
void __cdecl sub_006CB450_StaticFiniNewsCache(); // 0x006CB450
extern unsigned char gCriticalSection_00881F64[24]; // 0x00881F64
void __cdecl sub_006CB470_DestroyLock(); // 0x006CB470

extern D2BigPairStrc gtBigPair; // 0x0088273C
void __cdecl sub_006CB480_DestroyBigPair(); // 0x006CB480
extern int gnDivisor_00731014; // 0x00731014
extern int gnQuotient_00883D60; // 0x00883D60
void __cdecl sub_006CB4E0_DestroyLock(); // 0x006CB4E0


extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection); // 0x006CC1FC

inline void* __cdecl operator new(unsigned int, void* location);

// 0x006CAEC0
void __cdecl sub_006CAEC0_RegisterCleanup()
{
    sub_00683824_RegisterExit(sub_006CB450_StaticFiniNewsCache);
}

inline void* __cdecl operator new(unsigned int, void* location) { return location; }

// 0x006CAEF0
void __cdecl sub_006CAEF0_InitializeBigPair()
{
    new (&gtBigPair) D2BigPairStrc;
    atexit(sub_006CB480_DestroyBigPair);
}

// 0x006CAF10
void __cdecl sub_006CAF10_SetPerSecond()
{
    gnQuotient_00883D60 = 1000 / gnDivisor_00731014;
}

#include "gen/data/Source/Storm/Unknown_006CAE80.inc"

