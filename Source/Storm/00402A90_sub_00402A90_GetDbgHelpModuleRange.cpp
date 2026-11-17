struct D2ModuleInfoStrc
{
    void* lpBaseOfDll;
    unsigned long SizeOfImage;
    void* EntryPoint;
};

extern void* ghDbgHelp_0098A680;                                                                            // 0x0098A680
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();                                       // 0x006CC13C
extern "C" int __stdcall GetModuleInformation(void* hProcess, void* hModule, D2ModuleInfoStrc* pInfo, unsigned long cb); // 0x006B13C8

// 0x00402A90
bool __stdcall sub_00402A90_GetDbgHelpModuleRange(void** ppBase, unsigned long* pSize)
{
    D2ModuleInfoStrc tInfo;
    if (!ghDbgHelp_0098A680)
        return false;
    if (!GetModuleInformation(GetCurrentProcess(), ghDbgHelp_0098A680, &tInfo, sizeof(tInfo)))
        return false;
    *ppBase = *(void* volatile*)&tInfo.lpBaseOfDll;
    const unsigned long nSize = *(volatile unsigned long*)&tInfo.SizeOfImage;
    *pSize = nSize;
    return true;
}
