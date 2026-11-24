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
extern unsigned int gnListTerminator_0074C490; // 0x0074C490
extern void* gpListHead_0074C494; // 0x0074C494
void __cdecl sub_006CB4F0_DestroyList(); // 0x006CB4F0
extern unsigned int gnListTerminator_0074C49C; // 0x0074C49C
extern void* gpListHead_0074C4A0; // 0x0074C4A0
void __cdecl sub_006CB550_DestroyList(); // 0x006CB550


extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* lpCriticalSection); // 0x006CC1FC

// build: symbol ?UnlinkAll@?$TSList@UARCHIVEREC@SFile@Storm@@U?$TSGetLink@UARCHIVEREC@SFile@Storm@@@@@@QAEXXZ 0x00418900
// build: symbol ?UnlinkAll@?$TSList@UREQUEST@@U?$TSGetLink@UREQUEST@@@@@@QAEXXZ 0x00418940
// build: symbol ?UnlinkAll@?$TSList@UFILEREC@@U?$TSGetLink@UFILEREC@@@@@@QAEXXZ 0x00418980
// build: symbol ?UnlinkAll@?$TSList@UEVENTREC@@U?$TSGetLink@UEVENTREC@@@@@@QAEXXZ 0x004189C0
// build: symbol ?UnlinkAll@?$TSList@UAUDIOSTREAM@@U?$TSGetLink@UAUDIOSTREAM@@@@@@QAEXXZ 0x00418A00
// build: symbol ?UnlinkAll@?$TSList@UHANDLER@@U?$TSGetLink@UHANDLER@@@@@@QAEXXZ 0x0041C770
// build: symbol ?UnlinkAll@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEXXZ 0x00420750
// build: symbol ?UnlinkAll@?$TSList@UBREAKCMD@@U?$TSGetLink@UBREAKCMD@@@@@@QAEXXZ 0x00426CF0
extern TSList<ARCHIVEREC> gArchiveList_00708354; // 0x00708354

extern TSList<REQUEST> gRequestList_00708360; // 0x00708360

extern TSList<FILEREC> gList_0070836C; // 0x0070836C

extern TSList<EVENTREC> gList_00708378; // 0x00708378

extern TSList<AUDIOSTREAM> gList_00708384; // 0x00708384

extern TSList<HANDLER> gList_00708420; // 0x00708420

extern TSList<WNDREC> gList_00708860; // 0x00708860

extern TSList<BREAKCMD> gList_007088E8; // 0x007088E8

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

// 0x006CB030
void __cdecl sub_006CB030_InitializeList()
{
    gpListHead_0074C494 = (void*)~(unsigned int)&gnListTerminator_0074C490;
    atexit(sub_006CB4F0_DestroyList);
}

// 0x006CB050
void __cdecl sub_006CB050_InitializeList()
{
    gpListHead_0074C4A0 = (void*)~(unsigned int)&gnListTerminator_0074C49C;
    atexit(sub_006CB550_DestroyList);
}

// 0x006CB0C0
void __cdecl sub_006CB0C0_DestroyList()
{
    gArchiveList_00708354.~TSList();
}

// 0x006CB120
void __cdecl sub_006CB120_DestroyList()
{
    gRequestList_00708360.~TSList();
}

// 0x006CB180
void __cdecl sub_006CB180_DestroyList()
{
    gList_0070836C.~TSList();
}

// 0x006CB1E0
void __cdecl sub_006CB1E0_DestroyList()
{
    gList_00708378.~TSList();
}

// 0x006CB240
void __cdecl sub_006CB240_DestroyList()
{
    gList_00708384.~TSList();
}

// 0x006CB2A0
void __cdecl sub_006CB2A0_DestroyList()
{
    gList_00708420.~TSList();
}

// 0x006CB310
void __cdecl sub_006CB310_DestroyList()
{
    gList_00708860.~TSList();
}

// 0x006CB380
void __cdecl sub_006CB380_DestroyList()
{
    gList_007088E8.~TSList();
}
