struct D2RecordArrayStrc {
    char name[256];
    int count, stride, initialized, used, freeHead, cursor;
    unsigned short nextId, reserved;
    unsigned char* data;
};
void* __fastcall FOG_Alloc(unsigned int, const char*, int, int); // 0x0040B380
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int); // 0x00687330
// 0x006BCA10
D2RecordArrayStrc* __fastcall sub_006BCA10_CreateDataArray(const char* name, int count, int stride)
{
    D2RecordArrayStrc* array = (D2RecordArrayStrc*)FOG_Alloc(sizeof(D2RecordArrayStrc) + count * stride, ".\\Src\\DataArrays.cpp", 0x34, 0);
    if (array) {
        memset(array, 0, sizeof(D2RecordArrayStrc));
        strncpy(array->name, name, 256);
        array->stride = stride;
        array->count = count;
        array->data = (unsigned char*)(array + 1);
        array->initialized = 0;
    }
    return array;
}
