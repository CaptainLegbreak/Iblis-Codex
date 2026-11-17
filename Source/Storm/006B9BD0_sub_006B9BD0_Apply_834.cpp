struct D2ComObject006B9BD0Strc;
struct D2ComObjectVtbl006B9BD0Strc
{
    void* unk_00[5];
    long (__stdcall* Set)(D2ComObject006B9BD0Strc* pThis, void* pValue);
};
struct D2ComObject006B9BD0Strc
{
    D2ComObjectVtbl006B9BD0Strc* lpVtbl;
};
extern void* gpBuffer_009897D4; // 0x009897D4
extern void* gpBuffer_009897D8; // 0x009897D8
extern void* gpValue_009897DC; // 0x009897DC
extern void* gpValue_009897E0; // 0x009897E0
extern void* gpTarget_009897E4; // 0x009897E4
extern void* gpTarget_009897E8; // 0x009897E8
extern D2ComObject006B9BD0Strc* gpObject_009897EC; // 0x009897EC
extern D2ComObject006B9BD0Strc* gpObject_009897F0; // 0x009897F0
extern const unsigned int gnRenderFlag_006CE290; // 0x006CE290
extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8
void __fastcall sub_006B38A0_Copy(void* pTarget, void* pBuffer, int nSize); // 0x006B38A0

// 0x006B9BD0
void __cdecl sub_006B9BD0_Apply()
{
    if (gpBuffer_009897D4)
    {
        if (gnRenderFlags_0096F3A8 & gnRenderFlag_006CE290)
        {
            sub_006B38A0_Copy(gpTarget_009897E4, gpBuffer_009897D4, 0x40);
            sub_006B38A0_Copy(gpTarget_009897E8, gpBuffer_009897D8, 0x40);
        }
        else
        {
            gpObject_009897EC->lpVtbl->Set(gpObject_009897EC, gpValue_009897DC);
            gpObject_009897F0->lpVtbl->Set(gpObject_009897F0, gpValue_009897E0);
        }
    }
}
