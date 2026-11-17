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
};

union D2WordArgStrc
{
    unsigned int dwValue;
    unsigned short wValue;
};

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C
extern "C" __declspec(dllimport) void __stdcall RtlCaptureContext(D2ThreadContextStrc* pContext);             // 0x006CC290
extern "C" __declspec(dllimport) void* __stdcall OpenThread(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwThreadId); // 0x006CC27C
extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void* hThread);                         // 0x006CC288
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) int __stdcall GetThreadContext(void* hThread, D2ThreadContextStrc* pContext); // 0x006CC234
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread);                          // 0x006CC28C
extern "C" int __cdecl _snprintf_s(char* szBuffer, unsigned int nSizeOfBuffer, unsigned int nCount, const char* szFormat, ...); // 0x006824CB

extern "C" const char gszNewLine_006FFCB0[];                                                               // 0x006FFCB0
extern "C" const char gszNewLine2_006FFCD8[];                                                              // 0x006FFCD8

// 0x00404660
static unsigned char sub_00404660_GetThreadContext(unsigned long dwThreadId, D2ThreadContextStrc* pContext)
{
    pContext->ContextFlags = 0x1003F;
    if (GetCurrentThreadId() == dwThreadId)
    {
        RtlCaptureContext(pContext);
        return 1;
    }
    void* hThread = OpenThread(0x4A, 0, dwThreadId);
    if (!hThread)
        return 0;
    if (SuspendThread(hThread) == -1)
    {
        CloseHandle(hThread);
        return 0;
    }
    int bResult = GetThreadContext(hThread, pContext);
    ResumeThread(hThread);
    CloseHandle(hThread);
    return bResult != 0;
}

void __fastcall sub_004032F0_DumpRegisters(unsigned long dwThreadId, D2CrashPrintFn pfnPrint, void* pContext)
{
    D2ThreadContextStrc tContext;
    char szText[0x400];
    if (!sub_00404660_GetThreadContext(dwThreadId, &tContext))
        return;
    if (tContext.ContextFlags & 0x10002)
    {
        int n = _snprintf_s(szText, 0x400, -1, "%6s:0x%08x", "EAX", tContext.Eax);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "EBX", tContext.Ebx);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "ECX", tContext.Ecx);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "EDX", tContext.Edx);
        n += _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine_006FFCB0);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "ESI", tContext.Esi);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "EDI", tContext.Edi);
        _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine2_006FFCD8);
        pfnPrint(pContext, szText);
    }
    if (tContext.ContextFlags & 0x10001)
    {
        int n = _snprintf_s(szText, 0x400, -1, "%6s:0x%08x", "EBP", tContext.Ebp);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "ESP", tContext.Esp);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "EIP", tContext.Eip);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "FLG", tContext.EFlags);
        n += _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine_006FFCB0);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "CS", tContext.SegCs);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "SS", tContext.SegSs);
        _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine2_006FFCD8);
        pfnPrint(pContext, szText);
    }
    if (tContext.ContextFlags & 0x10004)
    {
        int n = _snprintf_s(szText, 0x400, -1, "%6s:0x%08x", "DS", tContext.SegDs);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "ES", tContext.SegEs);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "FS", tContext.SegFs);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "GS", tContext.SegGs);
        _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine2_006FFCD8);
        pfnPrint(pContext, szText);
    }
    if (tContext.ContextFlags & 0x10008)
    {
        int n = _snprintf_s(szText, 0x400, -1, "%6s:0x%08x", "CTRL", tContext.FloatSave.ControlWord);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "STAT", tContext.FloatSave.StatusWord);
        _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine_006FFCB0);
        pfnPrint(pContext, szText);
        const unsigned int* pLow = (const unsigned int*)&tContext.FloatSave.RegisterArea[0];
        const unsigned int* pHigh = (const unsigned int*)&tContext.FloatSave.RegisterArea[4];
        const unsigned short* pExponent = (const unsigned short*)&tContext.FloatSave.RegisterArea[8];
        for (unsigned int i = 0; i < 8; i++)
        {
            D2WordArgStrc tExponent;
            tExponent.dwValue = 0;
            tExponent.wValue = *pExponent;
            int n = _snprintf_s(szText, 0x400, -1, "%5s%d:0x%08x 0x%08x 0x%08x", "ST", i, *pLow, *pHigh, tExponent.dwValue);
            pLow = (const unsigned int*)((const unsigned char*)pLow + 10);
            pHigh = (const unsigned int*)((const unsigned char*)pHigh + 10);
            pExponent = (const unsigned short*)((const unsigned char*)pExponent + 10);
            i++;
            tExponent.wValue = *pExponent;
            n += _snprintf_s(szText + n, 0x400 - n, -1, "%5s%d:0x%08x 0x%08x 0x%08x", "ST", i, *pLow, *pHigh, tExponent.dwValue);
            _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine_006FFCB0);
            pfnPrint(pContext, szText);
            pLow = (const unsigned int*)((const unsigned char*)pLow + 10);
            pHigh = (const unsigned int*)((const unsigned char*)pHigh + 10);
            pExponent = (const unsigned short*)((const unsigned char*)pExponent + 10);
        }
        _snprintf_s(szText, 0x400, -1, gszNewLine_006FFCB0);
        pfnPrint(pContext, szText);
    }
    if (tContext.ContextFlags & 0x10020)
    {
        const unsigned int* pWord0 = (const unsigned int*)&tContext.FloatSave.RegisterArea[0];
        const unsigned int* pWord1 = (const unsigned int*)&tContext.FloatSave.RegisterArea[4];
        const unsigned int* pWord2 = (const unsigned int*)&tContext.FloatSave.RegisterArea[8];
        const unsigned int* pWord3 = (const unsigned int*)&tContext.FloatSave.RegisterArea[12];
        for (unsigned int i = 0; i < 8; i++)
        {
            int n = _snprintf_s(szText, 0x400, -1, "%5s%d:0x%08x 0x%08x 0x%08x 0x%08x", "XMM", i, *pWord0, *pWord1, *pWord2, *pWord3);
            pWord0 = (const unsigned int*)((const unsigned char*)pWord0 + 16);
            pWord1 = (const unsigned int*)((const unsigned char*)pWord1 + 16);
            pWord2 = (const unsigned int*)((const unsigned char*)pWord2 + 16);
            pWord3 = (const unsigned int*)((const unsigned char*)pWord3 + 16);
            i++;
            n += _snprintf_s(szText + n, 0x400 - n, -1, "%5s%d:0x%08x 0x%08x 0x%08x 0x%08x", "XMM", i, *pWord0, *pWord1, *pWord2, *pWord3);
            _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine_006FFCB0);
            pfnPrint(pContext, szText);
            pWord0 = (const unsigned int*)((const unsigned char*)pWord0 + 16);
            pWord1 = (const unsigned int*)((const unsigned char*)pWord1 + 16);
            pWord2 = (const unsigned int*)((const unsigned char*)pWord2 + 16);
            pWord3 = (const unsigned int*)((const unsigned char*)pWord3 + 16);
        }
        _snprintf_s(szText, 0x400, -1, gszNewLine_006FFCB0);
        pfnPrint(pContext, szText);
    }
}
