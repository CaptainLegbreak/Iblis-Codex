struct T00410B70 { unsigned char bytes[1]; };
extern const unsigned int gdwBitMasks[32];  // 0x006CE268
enum { BIT_MASK = 7 };
// 0x00410B70
void __stdcall sub_00410B70(T00410B70* buffer,int bit)
{
    buffer->bytes[bit >> 3] ^= (unsigned char)gdwBitMasks[bit & BIT_MASK];
}
