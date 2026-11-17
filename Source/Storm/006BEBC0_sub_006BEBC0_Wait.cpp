extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds);

struct D2Object006BE4E0Strc
{
    int nClosed00;
    unsigned char unk_004[0xBD0];
    void* hEventBD4;
};
int __fastcall sub_006C30D0_Wait(D2Object006BE4E0Strc* pObject, unsigned long dwMilliseconds); // 0x006C30D0

static inline int sub_006BEBC0_WaitHandle(D2Object006BE4E0Strc* pObject, unsigned long dwMilliseconds)
{
    if (!pObject->nClosed00)
        return WaitForSingleObject(pObject->hEventBD4, dwMilliseconds);
    return 0;
}

// 0x006BEBC0
int __stdcall sub_006BEBC0_Wait(D2Object006BE4E0Strc* pObject, unsigned long dwMilliseconds)
{
    if (pObject->nClosed00)
        return sub_006C30D0_Wait(pObject, dwMilliseconds);
    return !sub_006BEBC0_WaitHandle(pObject, dwMilliseconds);
}
