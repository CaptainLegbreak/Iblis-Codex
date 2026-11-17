struct D2SurfaceStrc;
struct D2SurfaceDescStrc
{
    unsigned int nSize;
    unsigned int f_4[3];
    int nPitch;
    unsigned int unk_14[4];
    void* pPixels;
    unsigned int unk_28[21];
};
struct D2SurfaceVtableStrc
{
    void* unk_00[25];
    int (__stdcall* Lock)(D2SurfaceStrc*, void*, D2SurfaceDescStrc*, unsigned int, void*);
    void* unk_68[6];
    int (__stdcall* Unlock)(D2SurfaceStrc*, void*);
};
struct D2SurfaceStrc
{
    D2SurfaceVtableStrc* f_0;
};
extern D2SurfaceStrc* gpPrimarySurface_00970E68; // 0x00970E68
extern D2SurfaceStrc* gpRenderSurface_00970E6C; // 0x00970E6C
extern int gnRenderHeight_007C913C; // 0x007C913C
extern "C" void* __cdecl memset(void*, int, unsigned int);
void __fastcall sub_006B20E0_ReportError(const char*, int); // 0x006B20E0

// 0x006B3800
void __cdecl sub_006B3800_Flush()
{
    D2SurfaceStrc* pSurface = gpRenderSurface_00970E6C ? gpRenderSurface_00970E6C : gpPrimarySurface_00970E68;
    D2SurfaceDescStrc desc;
    desc.nSize = sizeof(desc);
    memset((char*)&desc + sizeof(desc.nSize), 0, sizeof(desc) - sizeof(desc.nSize));
    int nResult = pSurface->f_0->Lock(pSurface, 0, &desc, 0x21, 0);
    if (nResult)
    {
        sub_006B20E0_ReportError("Failed to lock render surface for clear", nResult);
        return;
    }
    int nHeight = gnRenderHeight_007C913C;
    int nPitch = desc.nPitch;
    char* pPixels = (char*)desc.pPixels;
    while (nHeight)
    {
        --nHeight;
        memset(pPixels, 0, nPitch);
        pPixels += nPitch;
    }
    pSurface->f_0->Unlock(pSurface, 0);
}
