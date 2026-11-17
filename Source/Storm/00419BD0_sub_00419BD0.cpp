extern "C" int __stdcall SMemFree(void*, const char*, int, unsigned int);  // 0x00412650
struct D2StormAudioStreamStrc {
    char prefix[0x4C];
    int nRefCount;
    ~D2StormAudioStreamStrc();  // 0x004199A0
    static void operator delete(void* memory) {
        if (memory) SMemFree(memory, "delete", -1, 0);
    }
};
// 0x00419BD0
static __forceinline void sub_00419BD0(D2StormAudioStreamStrc* stream)
{
    if (stream && --stream->nRefCount == 0)
        delete stream;
}

void __stdcall emit_release_00419BD0(D2StormAudioStreamStrc* stream) { sub_00419BD0(stream); }
