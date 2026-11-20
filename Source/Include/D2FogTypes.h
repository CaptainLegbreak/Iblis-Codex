#pragma once
// Fog: the memory pool system, and the thread context and stack frame records of the crash handler.

#include "D2Check.h"
#include "D2SysTypes.h"

struct D2MemPoolBlockStrc;
struct D2MemPoolRecStrc;
struct D2PoolRecordStrc;
struct D2PoolSystemStrc;
struct D2PoolDirectoryStrc;
struct D2FloatSaveStrc;
struct D2ThreadContextStrc;
struct D2StackFrameStrc;

struct D2MemPoolBlockStrc
{
    void* pMemory; // 0x00
    unsigned int* pUsedBits; // 0x04
    int nUsed; // 0x08
    D2MemPoolBlockStrc* pPrev; // 0x0C
    D2MemPoolBlockStrc* pNext; // 0x10
    D2MemPoolRecStrc* pPool; // 0x14
};

struct D2MemPoolRecStrc
{
    D2CriticalSectionStrc tLock; // 0x00
    int nBlockSize; // 0x18
    int nBlocksPerChunk; // 0x1C
    int nChunkSize; // 0x20
    int nBlocks; // 0x24
    D2MemPoolBlockStrc* pFirstBlock; // 0x28
    D2MemPoolBlockStrc* pLastBlock; // 0x2C
};

struct D2PoolRecordStrc
{
    D2MemPoolBlockStrc* pBlock; // 0x00
    void* pMemory; // 0x04
};

struct D2PoolSystemStrc
{
    int bFreePoolAlloc; // 0x00
    D2CriticalSectionStrc tLock; // 0x04
    int nPools; // 0x1C
    D2MemPoolRecStrc aPools[40]; // 0x20
    int nPoolBlocks; // 0x7A0
    int nMaxPoolBlocks; // 0x7A4
    D2PoolRecordStrc* pRecords; // 0x7A8
    int* apLargeBlocks[1023]; // 0x7AC
    int nCount; // 0x17A8
    char szName[32]; // 0x17AC
};

struct D2PoolDirectoryStrc
{
    int bInit; // 0x00
    D2CriticalSectionStrc tLock; // 0x04
    D2PoolSystemStrc aSystems[8]; // 0x1C
    int nUsed; // 0xBE7C
    unsigned int anFreeIndex[8]; // 0xBE80
    int nFreeCount; // 0xBEA0
};

struct D2FloatSaveStrc
{
    unsigned long ControlWord; // 0x00
    unsigned long StatusWord; // 0x04
    unsigned long TagWord; // 0x08
    unsigned long ErrorOffset; // 0x0C
    unsigned long ErrorSelector; // 0x10
    unsigned long DataOffset; // 0x14
    unsigned long DataSelector; // 0x18
    unsigned char RegisterArea[80]; // 0x1C
    unsigned long Cr0NpxState; // 0x6C
};

struct D2ThreadContextStrc
{
    unsigned long ContextFlags; // 0x00
    unsigned long Dr0; // 0x04
    unsigned long Dr1; // 0x08
    unsigned long Dr2; // 0x0C
    unsigned long Dr3; // 0x10
    unsigned long Dr6; // 0x14
    unsigned long Dr7; // 0x18
    D2FloatSaveStrc FloatSave; // 0x1C
    unsigned long SegGs; // 0x8C
    unsigned long SegFs; // 0x90
    unsigned long SegEs; // 0x94
    unsigned long SegDs; // 0x98
    unsigned long Edi; // 0x9C
    unsigned long Esi; // 0xA0
    unsigned long Ebx; // 0xA4
    unsigned long Edx; // 0xA8
    unsigned long Ecx; // 0xAC
    unsigned long Eax; // 0xB0
    unsigned long Ebp; // 0xB4
    unsigned long Eip; // 0xB8
    unsigned long SegCs; // 0xBC
    unsigned long EFlags; // 0xC0
    unsigned long Esp; // 0xC4
    unsigned long SegSs; // 0xC8
    unsigned char ExtendedRegisters[512]; // 0xCC

    int sub_00405060_CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames);
};

struct D2StackFrameStrc
{
    unsigned long dwPc; // 0x00
    unsigned long dwFrame; // 0x04
    unsigned long dwStack; // 0x08
    unsigned long dwReturn; // 0x0C
    unsigned char bHasArgs; // 0x10
    void* apArgs[4]; // 0x14
};

D2_CHECK_SIZE(D2MemPoolBlockStrc, 0x18);
D2_CHECK_SIZE(D2MemPoolRecStrc, 0x30);
D2_CHECK_SIZE(D2PoolRecordStrc, 0x8);
D2_CHECK_SIZE(D2PoolSystemStrc, 0x17CC);
D2_CHECK_SIZE(D2PoolDirectoryStrc, 0xBEA4);
D2_CHECK_SIZE(D2FloatSaveStrc, 0x70);
D2_CHECK_SIZE(D2ThreadContextStrc, 0x2CC);
D2_CHECK_SIZE(D2StackFrameStrc, 0x24);
