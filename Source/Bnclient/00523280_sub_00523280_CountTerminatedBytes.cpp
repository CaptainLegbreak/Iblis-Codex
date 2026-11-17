static __declspec(noinline) unsigned int sub_00523280_CountTerminatedBytes(unsigned int maxLength, unsigned int length, const unsigned char* data);
// 0x00523280
static unsigned int sub_00523280_CountTerminatedBytes(unsigned int maxLength, unsigned int length, const unsigned char* data)
{
    unsigned int count = 0;
    if (length >= maxLength)
        length = maxLength;
    if (!length)
        return 0;
    do
    {
        --length;
        ++count;
        if (!(*data++))
            return count;
    } while (length);
    return 0;
}

unsigned int __fastcall CountTerminatedBytesContext(unsigned int length, const unsigned char* data, unsigned int maxLength)
{
    return sub_00523280_CountTerminatedBytes(maxLength, length, data);
}
