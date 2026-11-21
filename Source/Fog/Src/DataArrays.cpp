#include "Fog.h"

struct D2RecordArrayStrc;

struct D2RecordArrayStrc
{
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

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int); // 0x00687330
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" void __cdecl sub_00408A60(const char* text, const char* file, int line); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int code); // 0x00681E09

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

// 0x006BCA90
void __fastcall sub_006BCA90_ClearAndFree(void* pBlock)
{
    memset(pBlock, 0, 0x120);
    FOG_Free(pBlock, ".\\Src\\DataArrays.cpp", 0x4C, 0);
}

// 0x006BCAC0
void __fastcall sub_006BCAC0_ResetDataArray(D2RecordArrayStrc* array)
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

short* __fastcall sub_006BCC10_GetEntry(void* pDataArray, int nHandle); // 0x006BCC10

// 0x006BCC90
short* __fastcall sub_006BCC90_GetEntryOrHalt(void* pDataArray, int nHandle)
{
    short* pEntry = sub_006BCC10_GetEntry(pDataArray, nHandle);
    if (!pEntry)
    {
        sub_00408A60(&gszEmptyAssertText, sub_00408090(), 253);
        exit(-1);
    }
    return pEntry;
}
