struct sub_006BC7E0_Object;
struct sub_006BC830_Object;

typedef void* HANDLE;


extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(HANDLE hHandle, unsigned long dwMilliseconds);

struct sub_006BC7E0_Object
{
    char unk_000[0x114];
    HANDLE hEvent;
};


extern "C" __declspec(dllimport) int __stdcall SetEvent(HANDLE hEvent);

struct sub_006BC830_Object
{
    char unk_000[0x114];
    HANDLE hEvent;
};


// 0x006BC7E0
unsigned long __stdcall sub_006BC7E0_Wait(sub_006BC7E0_Object* pObject, unsigned long dwMilliseconds)
{
    if (!pObject)
        return 0;
    return WaitForSingleObject(pObject->hEvent, dwMilliseconds);
}

// 0x006BC830
void __stdcall sub_006BC830_SetEvent(sub_006BC830_Object* pObject)
{
    if (pObject)
        SetEvent(pObject->hEvent);
}
