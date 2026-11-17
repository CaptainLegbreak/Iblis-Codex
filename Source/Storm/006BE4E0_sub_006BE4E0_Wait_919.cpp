extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

struct D2Object006BE4E0Strc
{
    int nClosed00;
    unsigned char unk_004[0xBD0];
    void* hEventBD4;
};

// 0x006BE4E0
unsigned long __stdcall sub_006BE4E0_Wait(D2Object006BE4E0Strc* pObject, unsigned long dwMilliseconds)
{
    if (pObject->nClosed00)
        return 0;
    return WaitForSingleObject(pObject->hEventBD4, dwMilliseconds);
}
