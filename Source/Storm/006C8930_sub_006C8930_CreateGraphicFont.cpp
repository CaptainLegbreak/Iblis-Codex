extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int height, int width, int escapement, int orientation, int weight, unsigned long italic, unsigned long underline, unsigned long strikeout, unsigned long charset, unsigned long outPrecision, unsigned long clipPrecision, unsigned long quality, unsigned long pitchAndFamily, const char* face); // 0x006CC0E0
extern const char gszCourier_006DD52C[]; // 0x006DD52C
void* gpGraphicObject_0098A170;        // 0x0098A170

// 0x006C8930
void __cdecl sub_006C8930_CreateGraphicFont()
{
    gpGraphicObject_0098A170 = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier_006DD52C);
}
