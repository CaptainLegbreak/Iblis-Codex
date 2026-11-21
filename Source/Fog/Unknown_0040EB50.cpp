#include "D2GameTypes.h"

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

class CCritSect
{
public:
    CCritSect();
    ~CCritSect();

    D2CriticalSectionStrc tLock;
};

// 0x0040EB50
CCritSect::CCritSect()
{
    InitializeCriticalSection(&tLock);
}

// 0x0040EB60
CCritSect::~CCritSect()
{
    DeleteCriticalSection(&tLock);
}
