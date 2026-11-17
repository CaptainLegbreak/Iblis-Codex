struct D2CriticalSectionStrc { int unk[6]; };

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

struct TMESSAGESOURCE
{
    int unk[4];

    void Clear(); // 0x005176F8
};

extern TMESSAGESOURCE gFaultHandlerList_0072FA14; // 0x0072FA14
extern D2CriticalSectionStrc gErrorHandlerLock_00881818; // 0x00881818
extern int gbFaultHandlerListInitialized_00881830; // 0x00881830

// 0x0051775A
void sub_0051775A_FreeFaultHandlerList()
{
    EnterCriticalSection(&gErrorHandlerLock_00881818);
    gFaultHandlerList_0072FA14.Clear();
    LeaveCriticalSection(&gErrorHandlerLock_00881818);
    DeleteCriticalSection(&gErrorHandlerLock_00881818);
    gbFaultHandlerListInitialized_00881830 = 0;
}
