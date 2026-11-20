typedef int (__stdcall* D2CmdCallback)(const char*);
extern "C" __declspec(dllimport) char* __stdcall GetCommandLineA(); // 0x006CC3AC
int __stdcall SCmdProcess(const char*, int, D2CmdCallback, D2CmdCallback); // 0x006C4FB0
// 0x006C50B0
int __stdcall SCmdProcessCommandLine(D2CmdCallback extra, D2CmdCallback error)
{
    return SCmdProcess(GetCommandLineA(), 1, extra, error);
}
