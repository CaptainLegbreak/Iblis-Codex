struct D2StormLinkStrc;

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* process, unsigned int exitCode); // 0x006CC274

struct D2StormLinkStrc
{
    D2StormLinkStrc* pPrevLink;
    int pNext;
    int sub_005174AA_Next(); // 0x005174AA
    int sub_005174B4_RawNext(); // 0x005174B4
};


// 0x005173DF
void __cdecl sub_005173DF_TerminateCurrentProcess()
{
    TerminateProcess(GetCurrentProcess(), (unsigned int)-1);
}

// 0x005174AA
int D2StormLinkStrc::sub_005174AA_Next()
{
    int nNext = pNext;
    if (nNext <= 0)
    {
        nNext = 0;
    }
    return nNext;
}

// 0x005174B4
int D2StormLinkStrc::sub_005174B4_RawNext()
{
    return pNext;
}
