extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
struct D2VideoBlitVertex
{
    float x, y, z, rhw;
    unsigned int color, specular;
    float u, v;
};
extern D2VideoBlitVertex gVideoVertices_00989750[4]; // 0x00989750
#define gnHandle_00989760 (gVideoVertices_00989750[0].color)
#define gnHandle_00989780 (gVideoVertices_00989750[1].color)
#define gnHandle_009897A0 (gVideoVertices_00989750[2].color)
#define gnHandle_009897C0 (gVideoVertices_00989750[3].color)
extern void* gpBuffer_009897D0; // 0x009897D0

// 0x006B9A10
void __cdecl sub_006B9A10_Init()
{
    gnHandle_00989760 = -1;
    gnHandle_00989780 = -1;
    gnHandle_009897A0 = -1;
    gnHandle_009897C0 = -1;
    gpBuffer_009897D0 = FOG_Alloc(0x10000, ".\\Src\\d3dSmack.cpp", 0x38, 0);
    memset(gpBuffer_009897D0, 0, 0x10000);
}
