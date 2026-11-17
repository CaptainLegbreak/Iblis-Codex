extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* hObject);

struct D2RendererCallbacksStrc
{
    void (__fastcall* pfnCallback00)(int a, int b, int c, int d);
};

extern void* ghObject_0098A164; // 0x0098A164
extern int gnValue_007C9154; // 0x007C9154
extern D2RendererCallbacksStrc* gpCallbacks_007C914C; // 0x007C914C

// 0x006C7C90
void __cdecl sub_006C7C90_Release()
{
    DeleteObject(ghObject_0098A164);
    gnValue_007C9154 = 0;
    gpCallbacks_007C914C->pfnCallback00(0, 0, 0, 0);
}
