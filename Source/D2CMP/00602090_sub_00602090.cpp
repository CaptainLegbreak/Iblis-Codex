struct CriticalSection { unsigned data[6]; };
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection*);  // 0x006CC214
struct LockedObject { char pad[0x50]; CriticalSection lock; void sub_00602090(int acquired); };
enum { NOT_ACQUIRED = 0 };
// 0x00602090
void LockedObject::sub_00602090(int acquired)
{
    if(acquired!=NOT_ACQUIRED) LeaveCriticalSection(&lock);
}
