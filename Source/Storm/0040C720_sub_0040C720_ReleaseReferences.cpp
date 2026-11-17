struct D2CriticalSectionStrc { unsigned int opaque[6]; };
extern D2CriticalSectionStrc gCriticalSection_0075CFBC; // 0x0075CFBC
extern int gnReferenceCount_0075CFD4; // 0x0075CFD4
extern int (__stdcall *gpCleanup_0075CFDC)(void*); // 0x0075CFDC
extern int gnInitialized_0075D014; // 0x0075D014
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess();
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc*);
// 0x0040C720
int __fastcall sub_0040C720_ReleaseReferences(int all)
{
    int result = 0;
    if (!gnInitialized_0075D014)
    {
        return 0;
    }
    EnterCriticalSection(&gCriticalSection_0075CFBC);
    int nCount = gnReferenceCount_0075CFD4;
    do
    {
        if (!nCount)
        {
            break;
        }
        gnReferenceCount_0075CFD4 = --nCount;
        if (nCount)
        {
            result = 1;
            break;
        }
        gpCleanup_0075CFDC(GetCurrentProcess());
        if (!all)
        {
            break;
        }
        nCount = gnReferenceCount_0075CFD4;
    } while (nCount);
    LeaveCriticalSection(&gCriticalSection_0075CFBC);
    return result;
}
