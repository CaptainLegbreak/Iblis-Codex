typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection);

struct sub_006BE510_Guard
{
    CRITICAL_SECTION* pCriticalSection;

    sub_006BE510_Guard* sub_006BE510_Enter(CRITICAL_SECTION* pCs);
};

// 0x006BE510
sub_006BE510_Guard* sub_006BE510_Guard::sub_006BE510_Enter(CRITICAL_SECTION* pCs)
{
    pCriticalSection = pCs;
    EnterCriticalSection(pCs);
    return this;
}
