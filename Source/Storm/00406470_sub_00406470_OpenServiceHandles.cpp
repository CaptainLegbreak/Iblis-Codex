extern "C" __declspec(dllimport) unsigned long __stdcall GetVersion();                                      // 0x006CC138
extern "C" __declspec(dllimport) void* __stdcall OpenSCManagerA(const char* szMachineName, const char* szDatabaseName, unsigned long dwDesiredAccess); // 0x006CC028
extern "C" __declspec(dllimport) void* __stdcall OpenServiceA(void* hSCManager, const char* szServiceName, unsigned long dwDesiredAccess); // 0x006CC04C
extern char gszServiceName_007065DC[];                                                                      // 0x007065DC

// 0x00406470
static __declspec(noinline) int sub_00406470_OpenServiceHandles(void** phService, void** phManager)
{
    *phService = 0;
    *phManager = 0;
    if (GetVersion() & 0x80000000)
    {
        return 0;
    }
    void* hManager = OpenSCManagerA(0, 0, 0xF003F);
    *phManager = hManager;
    if (!hManager)
    {
        return 0;
    }
    *phService = OpenServiceA(hManager, gszServiceName_007065DC, 0xF01FF);
    return 1;
}

int sub_M371_Emit_00406470(int nAdd)
{
    void* hService;
    void* hManager;
    return sub_00406470_OpenServiceHandles(&hService, &hManager) + nAdd;
}
