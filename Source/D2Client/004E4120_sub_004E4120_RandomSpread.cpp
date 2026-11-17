typedef char check_int_width[sizeof(int)==4?1:-1];
typedef char check_uint_width[sizeof(unsigned int)==4?1:-1];
extern "C" int __fastcall sub_004E40A0(int nRange); // 0x004E40A0

// 0x004E4120
extern "C" int __fastcall sub_004E4120_RandomSpread(int nRange)
{
    const unsigned int uRange = (unsigned int)nRange;
    const unsigned int uWidth = 2u * uRange + 1u;
    const unsigned int uRoll = (unsigned int)sub_004E40A0((int)uWidth);
    return (int)(uRoll - uRange);
}
