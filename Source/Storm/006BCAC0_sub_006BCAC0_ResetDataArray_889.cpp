struct T006BCA10 {
    char name[256];
    int count;
    int stride;
    int initialized;
    int used;
    int freeHead;
    int cursor;
    unsigned short nextId;
    unsigned short reserved;
    unsigned char* data;
};
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl sub_00408A60(const char* text, const char* file, int line); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int code); // 0x00681E09
// 0x006BCAC0
void __fastcall sub_006BCAC0_ResetDataArray(T006BCA10* array)
{
    if (!array->initialized) {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 0x68);
        exit(-1);
    }
    array->freeHead = -1;
    array->cursor = 0;
    array->used = 0;
    array->nextId = 0x8000;
    for (int i = 0; i < array->count; ++i)
        *(unsigned short*)(array->data + i * array->stride) = 0;
}
