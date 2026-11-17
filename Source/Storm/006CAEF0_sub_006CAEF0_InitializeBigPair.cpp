struct D2BigPairStrc {
    void* pState;
    D2BigPairStrc(); // 0x00528500
};
extern D2BigPairStrc gtBigPair_0088273C; // 0x0088273C
void __cdecl sub_006CB480_DestroyBigPair(); // 0x006CB480
extern "C" int __cdecl atexit(void (__cdecl* callback)()); // 0x00683824
inline void* __cdecl operator new(unsigned int, void* location) { return location; }
// 0x006CAEF0
void __cdecl sub_006CAEF0_InitializeBigPair()
{
    new (&gtBigPair_0088273C) D2BigPairStrc;
    atexit(sub_006CB480_DestroyBigPair);
}
