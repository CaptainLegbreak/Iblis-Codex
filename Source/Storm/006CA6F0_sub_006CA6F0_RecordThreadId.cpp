extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(); // 0x006CC20C
extern unsigned long gdwThreadId_00992B1C; // 0x00992B1C

// 0x006CA6F0
void __cdecl sub_006CA6F0_RecordThreadId()
{
    gdwThreadId_00992B1C = GetCurrentThreadId();
}
