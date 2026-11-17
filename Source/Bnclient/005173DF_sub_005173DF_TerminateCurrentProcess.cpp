extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* process, unsigned int exitCode); // 0x006CC274

// 0x005173DF
void __cdecl sub_005173DF_TerminateCurrentProcess()
{
    TerminateProcess(GetCurrentProcess(), (unsigned int)-1);
}
