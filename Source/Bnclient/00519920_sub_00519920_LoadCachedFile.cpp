struct D2CriticalSectionStrc { unsigned int fields[6]; };
struct D2FileTimeStrc { unsigned int low, high; };
struct D2SystemTimeStrc { unsigned short year,month,dayOfWeek,day,hour,minute,second,millisecond; };
struct D2CacheHeaderStrc { unsigned int magic,headerSize,fileSize,unk0C,hashOffset,blockOffset,nHashTableSize,nBlockTableSize,headerCrc,hashCrc,blockCrc; };
struct D2CacheHashEntryStrc { unsigned int nameA,nameB,locale,blockIndex; };
struct D2CacheBlockEntryStrc { unsigned int fileOffset,blockSize,dataSize,flags; };
struct D2CacheEntryStrc { unsigned int headerSize,unk04,unk08,headerCrc,dataCrc,unk14; D2FileTimeStrc current,fileTime,now,expiry,cacheExpiry; char name[260]; };
static D2CacheHeaderStrc* gpCacheHeader_00881880; // 0x00881880
static D2CacheBlockEntryStrc* gpCacheBlockTable_00881884; // 0x00881884
static unsigned int* gpCacheCryptTable_00881888; // 0x00881888
static D2CacheHashEntryStrc* gpCacheHashTable_0088188C; // 0x0088188C
extern int gnCacheOpen_00881890; // 0x00881890
extern D2CriticalSectionStrc gCacheLock_00881894; // 0x00881894
static void* ghCacheFile_0072FB78; // 0x0072FB78
extern unsigned int gdwCacheCrcTable_0072FB80[]; // 0x0072FB80
extern unsigned __int64 gqwCacheFileTime_008818AC; // 0x008818AC
extern unsigned long gdwCacheTimeTick_008818B4; // 0x008818B4
extern unsigned int gnCacheTimeSeconds_008818B8; // 0x008818B8
extern const char gszCacheFile_006DEE70[]; // 0x006DEE70
extern const char gszCorruptFile_006DEEC0[]; // 0x006DEEC0
extern const char gszCorruptCache_006DEF00[]; // 0x006DEF00
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int);
extern "C" int __cdecl toupper(int);
extern "C" int __cdecl _stricmp(const char*,const char*);
extern "C" void* __cdecl memset(void*,int,unsigned int);
void __stdcall sub_0041C340_SetLastError(unsigned long); // 0x0041C340
void* __stdcall sub_00413020_Alloc(unsigned int,const char*,int,unsigned int); // 0x00413020
int __stdcall SMemFree(void*,const char*,int,unsigned int); // 0x00412650
void __cdecl sub_00518D40_Log(const char*,...); // 0x00518D40
void __cdecl sub_005198C0_ResetCache(); // 0x005198C0
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*); // 0x006CC214
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*); // 0x006CC134
extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void*,long,long*,unsigned long); // 0x006CC1AC
extern "C" __declspec(dllimport) int __stdcall ReadFile(void*,void*,unsigned long,unsigned long*,void*); // 0x006CC1A4
extern "C" __declspec(dllimport) int __stdcall WriteFile(void*,const void*,unsigned long,unsigned long*,void*); // 0x006CC1A8
extern "C" __declspec(dllimport) long __stdcall CompareFileTime(const D2FileTimeStrc*,const D2FileTimeStrc*); // 0x006CC390
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall GetSystemTime(D2SystemTimeStrc*); // 0x006CC38C
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc*,void*); // 0x006CC26C

// 0x00519300
void __cdecl sub_00519300_FreeCache()
{
    EnterCriticalSection(&gCacheLock_00881894);
    gnCacheOpen_00881890 = 0;
    if (gpCacheBlockTable_00881884)
    {
        SMemFree(gpCacheBlockTable_00881884, ".\\CACHE.CPP", 0x155, 0);
        gpCacheBlockTable_00881884 = 0;
    }
    if (gpCacheHashTable_0088188C)
    {
        SMemFree(gpCacheHashTable_0088188C, ".\\CACHE.CPP", 0x159, 0);
        gpCacheHashTable_0088188C = 0;
    }
    if (gpCacheHeader_00881880)
    {
        SMemFree(gpCacheHeader_00881880, ".\\CACHE.CPP", 0x15D, 0);
        gpCacheHeader_00881880 = 0;
    }
    if (ghCacheFile_0072FB78 != (void*)-1)
    {
        CloseHandle(ghCacheFile_0072FB78);
        ghCacheFile_0072FB78 = (void*)-1;
    }
    if (gpCacheCryptTable_00881888)
    {
        SMemFree(gpCacheCryptTable_00881888, ".\\CACHE.CPP", 0x165, 0);
        gpCacheCryptTable_00881888 = 0;
    }
    LeaveCriticalSection(&gCacheLock_00881894);
}
#define CACHE_CRC32(crc,bytes,count) crc=0xFFFFFFFF; for (;count;--count,++bytes) crc=(crc>>8)^gdwCacheCrcTable_0072FB80[(*bytes^crc)&0xFF]; crc=~crc
static unsigned int sub_00518DE0_Crc32(const void*,unsigned int); // 0x00518DE0
// 0x00518DE0
static unsigned int sub_00518DE0_Crc32(const void* data,unsigned int size) {
 int valid=-1; valid&=(data||!size)?-1:0;
 if(!data&&size) { sub_00408A60(&gszEmptyAssertText,sub_00408090(),0x91);exit(-1); }
 if(!valid) {sub_0041C340_SetLastError(0x57);return 0;}
 const unsigned char* bytes=(const unsigned char*)data; unsigned int crc; CACHE_CRC32(crc,bytes,size);return crc;
}
static __declspec(noinline) unsigned __int64* sub_00518F30_GetCacheFileTime(unsigned int);
static unsigned __int64* sub_00518F30_GetCacheFileTime(unsigned int); // 0x00518F30
// 0x00518F30
static unsigned __int64* sub_00518F30_GetCacheFileTime(unsigned int seconds) {
 if(seconds!=gnCacheTimeSeconds_008818B8||GetTickCount()!=gdwCacheTimeTick_008818B4) {
 D2SystemTimeStrc time; GetSystemTime(&time);SystemTimeToFileTime(&time,&gqwCacheFileTime_008818AC);
 gqwCacheFileTime_008818AC+=(unsigned __int64)seconds*10000000;
 gnCacheTimeSeconds_008818B8=seconds;gdwCacheTimeTick_008818B4=GetTickCount();
 } return &gqwCacheFileTime_008818AC;
}
static unsigned int __stdcall sub_00518FA0_HashString(unsigned int,const char*); // 0x00518FA0
// 0x00518FA0
static unsigned int __stdcall sub_00518FA0_HashString(unsigned int type,const char* text) {
 unsigned int seed1=0x7FED7FED,seed2=0xEEEEEEEE;
 while(text&&*text) {char ch=(char)toupper(*text++);seed1=gpCacheCryptTable_00881888[(type<<8)+ch]^(seed1+seed2);seed2=ch+seed1+seed2+(seed2<<5)+3;}
 return seed1;
}
static __declspec(noinline) int __stdcall sub_00519110_FindHashEntry(const char*,unsigned int);
static int __stdcall sub_00519110_FindHashEntry(const char*,unsigned int); // 0x00519110
// 0x00519110
static int __stdcall sub_00519110_FindHashEntry(const char* text,unsigned int locale) {
 unsigned int hash=sub_00518FA0_HashString(0,text),a=sub_00518FA0_HashString(1,text),b=sub_00518FA0_HashString(2,text);
 unsigned int size=gpCacheHeader_00881880->nHashTableSize,index=hash&(size-1);
 D2CacheHashEntryStrc* table=gpCacheHashTable_0088188C; unsigned int start=index; int fallback=-1; unsigned int block;
 while((block=table[index].blockIndex)!=(unsigned int)-1) {
 if(table[index].nameA==a&&table[index].nameB==b&&block!=(unsigned int)-2) {if(table[index].locale==locale)return index;if(!table[index].locale)fallback=index;}
 index=(index+1)&(size-1);if(index==start)break;
 }return fallback;
}
// build: context sub_H08_ClearBlockEntry
static void sub_H08_ClearBlockEntry(D2CacheBlockEntryStrc* pBlockTable, unsigned int nBlock)
{
    pBlockTable[nBlock].dataSize = 0;
    pBlockTable[nBlock].flags = 0;
}
static void sub_005191D0_DeleteHashEntries(const char*); // 0x005191D0

// 0x005191D0
static void sub_005191D0_DeleteHashEntries(const char* szName)
{
    int nIndex;
    while ((nIndex = sub_00519110_FindHashEntry(szName, 0)) != -1)
    {
        unsigned int* pBlock = &gpCacheHashTable_0088188C[nIndex].blockIndex;
        if (*pBlock < gpCacheHeader_00881880->nBlockTableSize)
        {
            sub_H08_ClearBlockEntry(gpCacheBlockTable_00881884, *pBlock);
        }
        *pBlock = (unsigned int)-2;
    }
}

// build: context sub_00519920_ReadEntry
static __forceinline int sub_00519920_ReadEntry(const char* name,D2FileTimeStrc* time,void** data,unsigned int* size,unsigned int block,int* pArchiveError,int* pFileError) {
 D2CacheEntryStrc header;
 unsigned long count; D2FileTimeStrc* now;
 memset(&header,0,sizeof(header));
 if(gpCacheBlockTable_00881884[block].flags&0xC0000000) {
 SetFilePointer(ghCacheFile_0072FB78,gpCacheBlockTable_00881884[block].fileOffset,0,0);
 ReadFile(ghCacheFile_0072FB78,&header,4,&count,0);
 if(count!=4){*pArchiveError=2;return 0;}
 if(header.headerSize!=sizeof(header)){*pArchiveError=3;return 0;}
 ReadFile(ghCacheFile_0072FB78,(char*)&header+4,sizeof(header)-4,&count,0);
 if(count!=sizeof(header)-4){*pArchiveError=4;return 0;}
 unsigned int stored=header.headerCrc;header.headerCrc=0;
 unsigned int crc=sub_00518DE0_Crc32(&header,sizeof(header));
 if(stored!=crc){*pFileError=1;return 0;}header.headerCrc=stored;
 }
 if(_stricmp(name,header.name)){*pFileError=2;return 0;}
 now=(D2FileTimeStrc*)sub_00518F30_GetCacheFileTime(0);
 if(CompareFileTime(now,&header.cacheExpiry)>0){*pFileError=3;return 0;}
 if(gpCacheBlockTable_00881884[block].dataSize>0x1000000){*pArchiveError=5;return 0;}
 if(time)*time=header.fileTime;
 header.current=*(D2FileTimeStrc*)sub_00518F30_GetCacheFileTime(0);
 SetFilePointer(ghCacheFile_0072FB78,gpCacheBlockTable_00881884[block].fileOffset,0,0);
 header.headerCrc=0;
 header.headerCrc=sub_00518DE0_Crc32(&header,sizeof(header));
 {unsigned int writeSize=header.headerSize;if(writeSize>sizeof(header))writeSize=sizeof(header);
 unsigned long written;
 WriteFile(ghCacheFile_0072FB78,&header,writeSize,&written,0);
 if(written!=writeSize){*pArchiveError=6;return 0;}}
 *data=sub_00413020_Alloc(gpCacheBlockTable_00881884[block].dataSize,gszCacheFile_006DEE70,0x2B5,0);
 SetFilePointer(ghCacheFile_0072FB78,gpCacheBlockTable_00881884[block].fileOffset+header.headerSize,0,0);
 ReadFile(ghCacheFile_0072FB78,*data,gpCacheBlockTable_00881884[block].dataSize,(unsigned long*)size,0);
 if(*size!=gpCacheBlockTable_00881884[block].dataSize){*pArchiveError=7;return 0;}
 if(header.dataCrc!=sub_00518DE0_Crc32(*data,*size)){*pFileError=4;return 0;}
 return 1;
}

// 0x00519920
int __fastcall sub_00519920_LoadCachedFile(const char* name,D2FileTimeStrc* time,void** data,unsigned int* size) {
 if(time){memset(time,0,sizeof(*time));} if(data)*data=0;if(size)*size=0;
 if(!name||!*name||!data||!size||!gnCacheOpen_00881890)return 0;
 int archiveError=0,fileError=0;
 EnterCriticalSection(&gCacheLock_00881894);
 int index=sub_00519110_FindHashEntry(name,0);
 if(index==-1){LeaveCriticalSection(&gCacheLock_00881894);return 0;}
 unsigned int block=gpCacheHashTable_0088188C[index].blockIndex;
 if(block>=gpCacheHeader_00881880->nBlockTableSize) archiveError=1;
 else if(sub_00519920_ReadEntry(name,time,data,size,block,&archiveError,&fileError)) goto unlock;
 if(archiveError){sub_00518D40_Log(gszCorruptCache_006DEF00,archiveError);sub_005198C0_ResetCache();}
 else {sub_00518D40_Log(gszCorruptFile_006DEEC0,name,fileError);sub_005191D0_DeleteHashEntries(name);}
 if(*data){SMemFree(*data,gszCacheFile_006DEE70,0x2DE,0);*data=0;}*size=0;
unlock: LeaveCriticalSection(&gCacheLock_00881894);return !fileError&&!archiveError;
}

#include "gen/data/Source/Bnclient/00519920_sub_00519920_LoadCachedFile.inc"
