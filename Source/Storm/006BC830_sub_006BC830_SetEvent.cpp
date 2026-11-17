typedef void* HANDLE;
extern "C" __declspec(dllimport) int __stdcall SetEvent(HANDLE hEvent);

struct sub_006BC830_Object
{
    char unk_000[0x114];
    HANDLE hEvent;
};

// 0x006BC830
void __stdcall sub_006BC830_SetEvent(sub_006BC830_Object* pObject)
{
    if (pObject)
        SetEvent(pObject->hEvent);
}
