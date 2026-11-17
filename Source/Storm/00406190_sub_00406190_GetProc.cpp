extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);     // 0x006CC148

// 0x00406190
static int __stdcall sub_00406190_GetProc(void* hModule, const char* szName, void** ppProc)
{
    void* pProc = GetProcAddress(hModule, szName);
    if (!pProc)
    {
        return 0;
    }
    *ppProc = pProc;
    return 1;
}

int __stdcall sub_K01_Emit_00406190(void* hModule, const char* szName, void** ppProc)
{
    return sub_00406190_GetProc(hModule, szName, ppProc);
}
