#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"

struct D2CriticalSectionStrc;
struct D2SMemBlockInfoStrc;
struct D2SMemHeapInfoStrc;

enum D2SMemBlockFlags
{
    SMEM_BLOCK_SENTINEL = 0x01,
    SMEM_BLOCK_FREE = 0x02,
    SMEM_BLOCK_LARGE = 0x04,
    SMEM_BLOCK_INDIRECT = 0x08,
    SMEM_BLOCK_PREVFREE = 0x10,
    SMEM_BLOCK_NOREPORT = 0x40,
    SMEM_BLOCK_KEEP = 0x80,
};

struct D2SMemBlockInfoStrc
{
    unsigned int dwSize;
    void* pMemory;
    int bAllocated;
    int bValid;
    unsigned int nDataSize;
    unsigned int nHeaderSize;
    unsigned int unk_18;
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void __cdecl SMemInitialize(); // 0x00411CD0
extern "C" const char szSMemFindNextBlock_006CED04[]; // 0x006CED04
extern D2SMemHeapStrc* gapFreeBlocks_007768B8[0x100]; // 0x007768B8
extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0
extern int gnFlag1_007784C0; // 0x007784C0
extern int gbHeapInitialized_007788D0; // 0x007788D0
static void __stdcall sub_004117A0_SetAndShowError(const char* szFile, int nLine, unsigned int nError); // 0x004117A0
static int sub_00411910_CheckPtr(void* pMemory, int bReport, const char* szFile, int nLine); // 0x00411910
static void sub_00411B90_GetBlockSizes(D2SMemBlockStrc* pBlock, void* pMemory, unsigned int* pDataSize, unsigned int* pHeaderSize); // 0x00411B90

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
extern "C" const char szSMemFindNextHeap_006CED18[]; // 0x006CED18
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0
void __cdecl sub_00411A20_InitPageSize(); // 0x00411A20
void __fastcall sub_00411A80_ReleaseBlock(D2SMemHeapStrc** ppLink); // 0x00411A80
void __cdecl sub_00412000_ReleaseFreeBlocks(); // 0x00412000
extern "C" const char gszMemNeverReleased_006CECCC[]; // 0x006CECCC
extern "C" const char szSMemFree_006CED2C[]; // 0x006CED2C
extern "C" const char szSMemGetHeapByCaller_006CED38[]; // 0x006CED38
extern "C" const char szSMemGetHeapByPtr_006CED50[]; // 0x006CED50
extern "C" const char szSMemGetSize_006CED64[]; // 0x006CED64
extern "C" const char szSMemHeapCreate_006CED74[]; // 0x006CED74
extern "C" const char szSMemHeapFree_006CED9C[]; // 0x006CED9C
extern "C" const char szSMemHeapSize_006CEDAC[]; // 0x006CEDAC
extern "C" const char szSMemHeapAlloc_006CEDBC[]; // 0x006CEDBC
extern "C" const char szSMemAlloc_006CEDCC[]; // 0x006CEDCC
extern "C" const char szSMemHeapReAlloc_006CEE08[]; // 0x006CEE08
extern "C" const char szSMemReAlloc_006CEE1C[]; // 0x006CEE1C
extern int gbCallerFirst_00708340; // 0x00708340
extern unsigned int gnHeapId_00708344; // 0x00708344
extern unsigned int gdwCallerId_007768A8; // 0x007768A8
extern unsigned int gdwCallerWord_007768AC; // 0x007768AC
extern int gnCallerLine_007768B0; // 0x007768B0
extern const char* gszCallerFile_007768B4; // 0x007768B4
extern unsigned int gnPageSize_00776CB8; // 0x00776CB8
extern int gnFlag2_00776CBC; // 0x00776CBC
extern int gnFlag0_007784C4; // 0x007784C4
extern int gabFreeBlockDirty_007784C8[0x100]; // 0x007784C8
extern D2SMemHeapStrc* gpFreeBlockSweep_007788C8; // 0x007788C8
extern int gnFlag3_007788CC; // 0x007788CC
extern int gnFlag_00779098; // 0x00779098
static void sub_00411AA0_FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock);

unsigned int gnStringCopyCheck; // 0x007788D8

// 0x004135D0
unsigned int __stdcall SStrCopy(char* dest,const char* source,unsigned int limit)
{
 int valid=-1;
 valid&=dest?-1:0;
 valid&=source?-1:0;
 if(!valid) { sub_0041C340_SetLastError(87); return 0; }
 if(!limit) return 0;
 unsigned int end=(unsigned int)dest+limit-1;
 int offset=(unsigned int)dest-end;
 while((unsigned int)source&3) {
  if(!offset) break;
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 offset+=3;
 if(offset<0) {
  end-=3;
  unsigned int word=*(const unsigned int*)source;
  source+=4;
  unsigned int ones=0xFFFFFFFF;
  ones-=word;
  unsigned int check=(word+0x7EFEFEFF)^ones;
  ones|=word;
  check&=0x81010101;
  while(!check) {
   *(unsigned int*)(end+offset)=word;
   offset+=4;
   if(offset>=0) goto Tail;
   word=*(const unsigned int*)source;
   source+=4;
   ones-=word;
   check=(word+0x7EFEFEFF)^ones;
   ones|=word;
   check&=0x81010101;
  }
  for(;;) {
   if(!(unsigned char)word) {
    ((char*)end)[offset]=(char)word;
    goto Done;
   }
   if(!(unsigned char)(word>>8)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    offset+=1;
    goto Done;
   }
   if(!(word&0xFF0000)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    ((char*)end)[offset+2]=0;
    offset+=2;
    goto Done;
   }
   *(unsigned int*)(end+offset)=word;
   if(!(word&0xFF000000)) { offset+=3; goto Done; }
   offset+=4;
   gnStringCopyCheck=check;
   if(offset>=0) break;
   word=*(const unsigned int*)source;
   source+=4;
  }
Tail:
  end+=3;
 }
 offset-=3;
 while(offset) {
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 *(char*)end=0;
Done:
 return valid ? offset-(unsigned int)dest+end : 0;
}

// 0x00413800
unsigned int __stdcall SStrPack(char* dest, const char* source, unsigned int limit)
{
 int valid=(__int64)dest?-1:0;
 valid&=source?-1:0;
 if(!valid) { sub_0041C340_SetLastError(87); return 0; }
 if(!limit) return 0;
 unsigned int dwOnes = 0xFFFFFFFF;
 const char* p = dest;
 unsigned int end=(unsigned int)dest+limit-1;
 if(limit!=0x7FFFFFFF) *(char*)end=0;
 while ((unsigned int)p & 3)
 {
  if (!*p) goto scanned;
  ++p;
 }
 for (;;)
 {
  const unsigned int w = *(const unsigned int*)p;
  dwOnes -= w;
  unsigned int dwTest = (w + 0x7EFEFEFF) ^ dwOnes;
  p += 4;
  dwOnes |= w;
  dwTest &= 0x81010101;
  if (dwTest)
  {
   if (!(char)w) { p -= 4; break; }
   if (!(char)(w >> 8)) { p -= 3; break; }
   if (!(w & 0xFF0000)) { p -= 2; break; }
   if (!(w & 0xFF000000)) { p -= 1; break; }
   gdwSStrScanWord_007788D8 = dwTest;
  }
 }
scanned:
 int offset=(unsigned int)p-end;
 while((unsigned int)source&3) {
  if(!offset) break;
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 offset+=3;
 if(offset<0) {
  end-=3;
  unsigned int word=*(const unsigned int*)source;
  source+=4;
  dwOnes-=word;
  unsigned int check=(word+0x7EFEFEFF)^dwOnes;
  dwOnes|=word;
  check&=0x81010101;
  while(!check) {
   *(unsigned int*)(end+offset)=word;
   offset+=4;
   if(offset>=0) goto Tail;
   word=*(const unsigned int*)source;
   source+=4;
   dwOnes-=word;
   check=(word+0x7EFEFEFF)^dwOnes;
   dwOnes|=word;
   check&=0x81010101;
  }
  for(;;) {
   if(!(unsigned char)word) {
    ((char*)end)[offset]=(char)word;
    goto Done;
   }
   if(!(unsigned char)(word>>8)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    offset+=1;
    goto Done;
   }
   if(!(word&0xFF0000)) {
    *(unsigned short*)(end+offset)=(unsigned short)word;
    ((char*)end)[offset+2]=0;
    offset+=2;
    goto Done;
   }
   *(unsigned int*)(end+offset)=word;
   if(!(word&0xFF000000)) { offset+=3; goto Done; }
   offset+=4;
   gdwSStrScanWord_007788D8=check;
   if(offset>=0) break;
   word=*(const unsigned int*)source;
   source+=4;
  }
Tail:
  end+=3;
 }
 offset-=3;
 while(offset) {
  char ch=*source++;
  ((char*)end)[offset]=ch;
  if(!ch) goto Done;
  ++offset;
 }
 *(char*)end=0;
Done:
 return valid ? offset-(unsigned int)dest+end : 0;
}

