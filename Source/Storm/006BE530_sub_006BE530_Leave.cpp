typedef struct _RTL_CRITICAL_SECTION* LPCRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

struct sub_006BE530_LockRef
{
    LPCRITICAL_SECTION pCriticalSection;
};

// 0x006BE530
void __fastcall sub_006BE530_Leave(sub_006BE530_LockRef* pLock)
{
    LeaveCriticalSection(pLock->pCriticalSection);
}
