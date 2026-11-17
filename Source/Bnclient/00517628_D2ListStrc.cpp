extern "C" void* __cdecl memset(void*, int, unsigned int);
struct D2LinkStrc {
    D2LinkStrc* previous;
    unsigned int next;
    __forceinline D2LinkStrc() {
        memset(this, 0, sizeof(*this));
        previous = this;
    }
};
struct D2ListStrc {
    unsigned int linkOffset;
    D2LinkStrc head;
    D2ListStrc();
};
// 0x00517628
D2ListStrc::D2ListStrc() {
    linkOffset = 0;
    head.next = ~(unsigned int)&head;
}
