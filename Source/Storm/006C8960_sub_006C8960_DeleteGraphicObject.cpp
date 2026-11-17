extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object); // 0x006CC0D4
extern void* gpGraphicObject_0098A170; // 0x0098A170

// 0x006C8960
void __cdecl sub_006C8960_DeleteGraphicObject()
{
    DeleteObject(gpGraphicObject_0098A170);
}
