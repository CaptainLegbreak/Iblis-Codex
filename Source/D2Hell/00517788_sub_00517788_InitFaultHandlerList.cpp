struct D2CriticalSectionStrc { int unk[6]; };

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824

void sub_0051775A_FreeFaultHandlerList(); // 0x0051775A

extern D2CriticalSectionStrc gErrorHandlerLock_00881818; // 0x00881818
int gbFaultHandlerListInitialized_00881830;        // 0x00881830

// 0x00517788
void sub_00517788_InitFaultHandlerList()
{
    if (!gbFaultHandlerListInitialized_00881830) {
        InitializeCriticalSection(&gErrorHandlerLock_00881818);
        atexit(sub_0051775A_FreeFaultHandlerList);
        gbFaultHandlerListInitialized_00881830 = 1;
    }
}
