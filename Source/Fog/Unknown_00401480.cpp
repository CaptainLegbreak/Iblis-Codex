#include "Fog.h"

struct D2MemoryBasicInfoStrc
{
    void* BaseAddress;
    void* AllocationBase;
    unsigned long AllocationProtect;
    unsigned long RegionSize;
    unsigned long State;
    unsigned long Protect;
    unsigned long Type;
};

struct D2FloatSaveStrc
{
    unsigned long ControlWord;
    unsigned long StatusWord;
    unsigned long TagWord;
    unsigned long ErrorOffset;
    unsigned long ErrorSelector;
    unsigned long DataOffset;
    unsigned long DataSelector;
    unsigned char RegisterArea[80];
    unsigned long Cr0NpxState;
};

struct D2StackFrameStrc
{
    unsigned long dwPc;
    unsigned long dwFrame;
    unsigned long dwStack;
    unsigned long dwReturn;
    unsigned char bHasArgs;
    void* apArgs[4];
};

struct D2ThreadContextStrc
{
    unsigned long ContextFlags;
    unsigned long Dr0;
    unsigned long Dr1;
    unsigned long Dr2;
    unsigned long Dr3;
    unsigned long Dr6;
    unsigned long Dr7;
    D2FloatSaveStrc FloatSave;
    unsigned long SegGs;
    unsigned long SegFs;
    unsigned long SegEs;
    unsigned long SegDs;
    unsigned long Edi;
    unsigned long Esi;
    unsigned long Ebx;
    unsigned long Edx;
    unsigned long Ecx;
    unsigned long Eax;
    unsigned long Ebp;
    unsigned long Eip;
    unsigned long SegCs;
    unsigned long EFlags;
    unsigned long Esp;
    unsigned long SegSs;
    unsigned char ExtendedRegisters[512];

    int sub_00405060_CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames);
};
extern "C" __declspec(dllimport) void __stdcall RtlCaptureContext(D2ThreadContextStrc* pContext);             // 0x006CC290
extern "C" __declspec(dllimport) void* __stdcall OpenThread(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwThreadId); // 0x006CC27C
extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void* hThread);                         // 0x006CC288
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread);                          // 0x006CC28C
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

// 0x00401480
static unsigned char __stdcall sub_00401480_GetStackRange(void** ppBase, unsigned long* pEnd, const void* pAddress)
{
    D2MemoryBasicInfoStrc tInfo;
    if (!VirtualQuery(pAddress, &tInfo, sizeof(tInfo)))
        return 0;
    if (tInfo.State != 0x1000)
        return 0;
    if (tInfo.Type != 0x20000)
        return 0;
    if (tInfo.Protect != 4)
        return 0;
    *pEnd = (unsigned long)tInfo.BaseAddress + tInfo.RegionSize;
    if (*pEnd <= (unsigned long)pAddress)
        return 0;
    *ppBase = tInfo.AllocationBase;
    if (!VirtualQuery(tInfo.AllocationBase, &tInfo, sizeof(tInfo)))
        return 0;
    if (tInfo.Type != 0x20000)
        return 0;
    if (tInfo.BaseAddress != *ppBase)
        return 0;
    unsigned long dwEnd = (unsigned long)*ppBase + tInfo.RegionSize;
    if (tInfo.State == 0x1000)
    {
        if (dwEnd != *pEnd)
            return 0;
        *ppBase = tInfo.AllocationBase;
        return 1;
    }
    if (tInfo.State == 0x2000)
    {
        if (dwEnd >= *pEnd)
            return 0;
        *ppBase = tInfo.AllocationBase;
        return 1;
    }
    return 0;
}

// 0x00401540
static unsigned char __stdcall sub_00401540_GetThreadStack(unsigned long* pStackSize, unsigned long dwThreadId, unsigned long* pStackTop, unsigned long* pStackPointer)
{
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    tContext.ContextFlags = 0x10001;
    if (GetCurrentThreadId() == dwThreadId)
    {
        RtlCaptureContext(&tContext);
    }
    else
    {
        hThread = OpenThread(0x4A, 0, dwThreadId);
        if (!hThread)
            return 0;
        if (SuspendThread(hThread) == -1)
            return 0;
        if (!GetThreadContext(hThread, &tContext))
        {
            ResumeThread(hThread);
            CloseHandle(hThread);
            return 0;
        }
    }
    *pStackPointer = tContext.Esp;
    void* pBase;
    unsigned long dwEnd;
    unsigned char bResult = sub_00401480_GetStackRange(&pBase, &dwEnd, (const void*)tContext.Esp);
    if (bResult)
    {
        *pStackTop = dwEnd;
        *pStackSize = dwEnd - (unsigned long)pBase;
    }
    if (hThread)
    {
        ResumeThread(hThread);
        CloseHandle(hThread);
    }
    return bResult;
}

int D2ThreadContextStrc::sub_00405060_CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames)
{
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    if (this)
    {
        tContext = *this;
    }
    else
    {
        tContext.ContextFlags = 0x10001;
        if (GetCurrentThreadId() == dwThreadId)
        {
            RtlCaptureContext(&tContext);
        }
        else
        {
            hThread = OpenThread(0x4A, 0, dwThreadId);
            if (!hThread)
                return 0;
            if (SuspendThread(hThread) == -1)
                return 0;
            if (!GetThreadContext(hThread, &tContext))
            {
                ResumeThread(hThread);
                CloseHandle(hThread);
                return 0;
            }
        }
    }
    unsigned int nCount = 0;
    unsigned long dwPc = tContext.Eip;
    unsigned long dwFrame = tContext.Ebp;
    unsigned long dwStack = tContext.Esp;
    unsigned long dwStackTop;
    unsigned long dwStackSize;
    unsigned long dwStackPointer;
    if (!sub_00401540_GetThreadStack(&dwStackSize, dwThreadId, &dwStackTop, &dwStackPointer))
    {
        if (hThread)
        {
            ResumeThread(hThread);
            CloseHandle(hThread);
        }
        return 0;
    }
    __try
    {
        for (unsigned int i = 0; i < 0x80; i++)
        {
            if (i >= (unsigned int)nSkipFrames)
            {
                pFrames[nCount].dwPc = dwPc;
                pFrames[nCount].dwStack = dwStack;
                pFrames[nCount].dwFrame = dwFrame;
                nCount++;
                if (nCount >= 0x80)
                    break;
            }
            if (dwFrame <= dwStack)
                break;
            if (dwFrame + 8 > dwStackTop)
                break;
            unsigned long dwNext = *(unsigned long*)dwFrame;
            if (dwNext & 3)
                break;
            if (dwNext <= dwFrame)
                break;
            dwStack = dwFrame + 4;
            dwPc = *(unsigned long*)dwStack;
            dwFrame = dwNext;
        }
    }
    __except (1)
    {
    }
    if (hThread)
    {
        ResumeThread(hThread);
        CloseHandle(hThread);
    }
    return nCount;
}
