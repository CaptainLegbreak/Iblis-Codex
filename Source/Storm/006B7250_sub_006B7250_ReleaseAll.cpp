struct D2Unknown006B7250Strc;
struct D2Unknown006B7250VtblStrc
{
    long (__stdcall* pfnQueryInterface)(D2Unknown006B7250Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* pfnAddRef)(D2Unknown006B7250Strc* pThis);
    unsigned long (__stdcall* pfnRelease)(D2Unknown006B7250Strc* pThis);
};
struct D2Unknown006B7250Strc
{
    D2Unknown006B7250VtblStrc* pVtbl;
};
D2Unknown006B7250Strc* gpSurfaces_009712D0[0x60];        // 0x009712D0
extern D2Unknown006B7250Strc* gpTextures_00971150[0x60]; // 0x00971150

// 0x006B7250
void __cdecl sub_006B7250_ReleaseAll()
{
    for (int i = 0; i < 0x60; ++i)
    {
        if (gpSurfaces_009712D0[i])
        {
            gpSurfaces_009712D0[i]->pVtbl->pfnRelease(gpSurfaces_009712D0[i]);
            gpSurfaces_009712D0[i] = 0;
        }
        if (gpTextures_00971150[i])
        {
            gpTextures_00971150[i]->pVtbl->pfnRelease(gpTextures_00971150[i]);
            gpTextures_00971150[i] = 0;
        }
    }
}
