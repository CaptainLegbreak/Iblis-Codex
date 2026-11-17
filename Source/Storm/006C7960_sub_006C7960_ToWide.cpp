static __declspec(noinline) int __stdcall sub_006C78C0_ConvertToWide(unsigned short*,const unsigned char*,unsigned int,const unsigned short*); // 0x006C78C0
static __declspec(noinline) int __stdcall sub_006C78C0_ConvertToWide(unsigned short* destination,const unsigned char* source,unsigned int count,const unsigned short* table) {
    if (!count) return 0;
    unsigned short* out=destination;
    while (*source && count) {
        *out++=table[*source++];
        --count;
    }
    if (count) *out++=0;
    return out-destination;
}
extern const unsigned short gWideTable_006FCDC0[]; // 0x006FCDC0
// 0x006C7960
int __stdcall sub_006C7960_ToWide(unsigned short* destination,const unsigned char* source,unsigned int count) {
    return sub_006C78C0_ConvertToWide(destination,source,count,gWideTable_006FCDC0);
}
