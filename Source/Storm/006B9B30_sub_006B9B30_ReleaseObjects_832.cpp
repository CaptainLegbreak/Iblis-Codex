struct D2ComObject006B9B30Strc;
struct D2ComObjectVtbl006B9B30Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006B9B30Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObject006B9B30Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006B9B30Strc* pThis);
};
struct D2ComObject006B9B30Strc
{
    D2ComObjectVtbl006B9B30Strc* lpVtbl;
};
extern D2ComObject006B9B30Strc* gapObjectsD4_009897D4[2]; // 0x009897D4
extern D2ComObject006B9B30Strc* gapObjectsDC_009897DC[2]; // 0x009897DC
extern D2ComObject006B9B30Strc* gapObjectsE4_009897E4[2]; // 0x009897E4
extern D2ComObject006B9B30Strc* gapObjectsEC_009897EC[2]; // 0x009897EC

#define RELEASE(p) if (p) { p->lpVtbl->Release(p); p = 0; }

// 0x006B9B30
void __cdecl sub_006B9B30_ReleaseObjects()
{
    for (int i = 0; i < 2; ++i)
    {
        RELEASE(gapObjectsDC_009897DC[i]);
        RELEASE(gapObjectsD4_009897D4[i]);
        RELEASE(gapObjectsEC_009897EC[i]);
        RELEASE(gapObjectsE4_009897E4[i]);
    }
}
