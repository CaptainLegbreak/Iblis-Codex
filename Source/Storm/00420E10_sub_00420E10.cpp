struct Entry { unsigned char data[20]; };
enum { KEEP_EXISTING = 0 };
struct SlotArray {
    Entry slots[16];
    int count;
    Entry* sub_00420E10(Entry* existing,int mode);
};
// 0x00420E10
Entry* SlotArray::sub_00420E10(Entry* existing,int mode)
{
    if(mode != KEEP_EXISTING) return &slots[count++];
    return existing;
}
